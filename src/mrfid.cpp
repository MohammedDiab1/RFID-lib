/*
 * Example of C++ using mercurylib
 * 
 */

#include <iostream>
#include <mrfid/rfid.h>
#include<stdint.h>
#include <sstream>
#include <iomanip>
#include <cstring>
//#include <string>

//ADDED
#include <ros/ros.h>
#include "mercuryrfid/MemoryInfo.h"
#include "mercuryrfid/MemoryUpdate.h"
#include "mercuryrfid/epcUpdate.h"
#include "mercuryrfid/InfoTag.h"
#include "mercuryrfid/AccessReader.h"


using namespace std;

rfid* mydevice;

//string tohex(const string& s, bool upper=false)
//{
//    ostringstream ret;

//    unsigned int c;
//    for (string::size_type i = 0; i < s.length(); ++i)
//    {
//        c = (unsigned int)(unsigned char)s[i];
//        ret << hex << setfill('0') <<
//            setw(2) << (upper ? uppercase : nouppercase) << c;
//    }
//    return ret.str();
//}

//int main()
//{
//    string s0 = "a";
//    const char *buf = s0.c_str();
// //    size_t strlen (* buf );


//    string s(buf, 10);
//    cout << "hex: " << tohex(s) << endl;
//    cout << "HEX: " << tohex(s, true) << endl;
//    return 0;
//}
//ADDED for access the serial port .........

bool srvRFIDSetUp(mercuryrfid::AccessReader::Request &req, mercuryrfid::AccessReader::Response &res)
{
    int argcRFID = 2;
 char *addressRFID[2];
 addressRFID[0] = {"demo"} ;
  //   argvRFID[1] = req.addressRFID;
    char *add = new char[req.addressRFID.length() + 1];
    std::strcpy(add, req.addressRFID.c_str());
    addressRFID[1] = add;
    res.status = mydevice->RFID_Setup(argcRFID, addressRFID);
    delete[] add;
    //RFID_Setup(argcRFID, argvRFID);
}

//ADDED
bool srvMemoryInfo(mercuryrfid::MemoryInfo::Request &req, mercuryrfid::MemoryInfo::Response &res)
{

    char *epcTag = new char[req.epc.length() + 1];;
    std::strcpy(epcTag, req.epc.c_str());
    uint16_t words[100];
    //uint16_t Nwords[100];
    res.memInfo="";
    res.status = mydevice->read_Memory(req.bank, req.address, req.count, epcTag, words);

    if (res.status) cout<<"The memory info is : "<<std::endl;

    stringstream ss;
    //string target;
 //   ss << words;
 //   ss >> target;

  for (int i = 0 ; i < 6; i++) {
    std::cout<<std::hex<<words[i];
    ss << std::hex<<words[i];

}
  std::cout<<std::endl;
  std::cout<<"ROS START ! "<<ss.str()<<std::endl;


  int len = ss.str().length();
  std::string _newString;
  for(int i=0; i< len; i+=2)
  {
      string byte = ss.str().substr(i,2);
      char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
      _newString.push_back(chr);
  }

  std::cout<<"NEW STRING ! "<<_newString<<std::endl;
  res.memInfo = _newString;

//  for (int i = 0; i<6; i+5) {

//}
//    std::cout<<"ROS START !"<<std::endl;
//    for (int i = 0 ; i < 6; i++)
//    {
//        printf("%04X", words[i]);

//    }
    printf("\n");
//    std::cout<<"ROS END !"<<std::endl;

    delete[] epcTag;

    return true;
}

std::string tohex(const std::string& s, bool upper=false)
 {
     ostringstream ret;
     unsigned int c;
     for (std::string::size_type i = 0; i < s.length(); ++i)
     {
         c = (unsigned int)(unsigned char)s[i];
         ret << hex << setfill('0') << setw(2) << (upper ? uppercase : nouppercase) << c;
     }
     return ret.str();
 }

/*int HexString()
{

    return 0;
}*/

bool srvMemoryUpdate(mercuryrfid::MemoryUpdate::Request &req, mercuryrfid::MemoryUpdate::Response &res)
{
    char *epcTag = new char[req.epc.length() + 1];
    std::strcpy(epcTag, req.epc.c_str());

    char *DataTag = new char[req.Data.length() + 1];
    std::strcpy(DataTag, req.Data.c_str());

    std::string Data = "a";
    const char *buf = Data.c_str();
    size_t strlen (* buf );

    std::string s(buf, 10);
    cout << "hex: " << tohex(Data) << endl;
    cout << "HEX: " << tohex(Data, true) << endl;
    res.memUpdate = mydevice->write_Memory(req.bank,  req.address, DataTag, epcTag);

    delete[] epcTag;
    delete[] DataTag;

    return true;
}


bool srvepcUpdate(mercuryrfid::epcUpdate::Request &req, mercuryrfid::epcUpdate::Response &res)
{

    char *epcTag = new char[req.epc.length() + 1];
    std::strcpy(epcTag, req.epc.c_str());

    char *newepcTag = new char[req.NewEPC.length() + 1];
    std::strcpy(newepcTag, req.NewEPC.c_str());

    res.epcUpdate = mydevice->change_Epc(epcTag, newepcTag);

    delete[] epcTag;
    delete[] newepcTag;

    return true;
}

bool srvInfoTag(mercuryrfid::InfoTag::Request &req, mercuryrfid::InfoTag::Response &res)
{
//    int argcRFID = 2;
//    char *argvRFID[] = {"demo", "tmr:///dev/ttyACM0"} ;
//    mydevice->RFID_Setup(argcRFID, argvRFID);


    char *epcTag = new char[req.epc.length() + 1];
    std::strcpy(epcTag, req.epc.c_str());

int _rssi;
int _Antenna;
int _Frequency;
int _Phase;
int _Protocol;

    res.status = mydevice->read_Tag( epcTag, &_rssi, &_Antenna, &_Frequency, &_Phase, &_Protocol);


    std::cout<<"The rssi value is: "<<_rssi<<std::endl;
    std::cout<<"The Antenna ID is: "<<_Antenna<<std::endl;
    std::cout<<"The Frequency is: "<<_Frequency<<std::endl;
    std::cout<<"The Phase is: "<<_Phase<<std::endl;
    std::cout<<"The Protocol is: "<<_Protocol<<std::endl;

   if(res.status) std::cout<<"RESPONSE is TRUE "<<std::endl;


res.rssi = _rssi;
res.Antenna = _Antenna;
res.Frequency = _Frequency;
res.Phase = _Phase;
res.Protocol = _Protocol;

    delete[] epcTag;


    return true;
}


int main(int argc, char *argv[])
{
   //Added
    mydevice = new rfid();
    //int argcRFID = 2;
    //char *argvRFID[] = {"demo", "tmr:///dev/ttyACM3"} ;

    //std::cout<<"The request is: "<<argvRFID[1]<<std::endl;
  //  mydevice->RFID_Setup(argcRFID, argvRFID);
   // cout<< "tmr:///dev/ttyS0"<<endl;
    ros::init(argc, argv, "RFIDServices");
    ros::NodeHandle n;

    ROS_INFO("Starting RFID Services");

   int d = 4;
   float f = 4.5;
   ros::ServiceServer service0 = n.advertiseService("RFID/RFIDSetUp", srvRFIDSetUp);
   ros::ServiceServer service1 = n.advertiseService("RFID/ReadMemory", srvMemoryInfo);
   ros::ServiceServer service2 = n.advertiseService("RFID/WriteMemory", srvMemoryUpdate);
   ros::ServiceServer service3 = n.advertiseService("RFID/ChangeEPC", srvepcUpdate);
   ros::ServiceServer service4 = n.advertiseService("RFID/ReadTag", srvInfoTag);

   ros::spin();

      
   return 0;
}
