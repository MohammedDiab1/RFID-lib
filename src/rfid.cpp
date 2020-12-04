// Program to illustrate the working of objects and class in C++ Programming
#include <mrfid/rfid.h>
extern "C"
{
#include <mwlib/mwlib.h>
}

rfid::rfid(){
   data1 = 0;
   float data2 = 0.0;
}

int rfid::RFID_Setup(int argcRFID, char *argvRFID[]) {
    int memRFID;
    //char *argvRFID[] = {"demo", "tmr:///dev/ttyACM3"} ;
    //addressRFID = argvRFID[1];
    memRFID = RFID(argcRFID, argvRFID);
    return memRFID;
}

void rfid::insertIntegerData(int d){
          data1 = d;
          std::cout << "Number: " << data1;
}

float rfid::insertFloatData()
{
           std::cout << "\nEnter data: ";
           std::cin >> data2;
           return data2;
}

//void rfid::readcmd(int argc, char *argv[])
//{
//   readcmd(argc,argv);
//}

//void rfid::readmemwordscmd(int argc, char *argv[])
//{
//   readmemwordscmd(argc, argv);
//}

int rfid::read_Memory(int bank, int address, int count, char* epc, uint16_t *words)
{
    int memInfo;
    memInfo = readMemory( bank,  address,  count,  epc, words);
    return memInfo;
}

int rfid::write_Memory(int bank, int address, char* Data, char* epc)
{
    int memUpdate;
    memUpdate = writeMemory( bank,  address,  Data,  epc);
    return memUpdate;
}

int rfid::change_Epc(char *epc, char *NewEPC)
{
    int epcUpdate;
    epcUpdate = changeEpc(epc, NewEPC);
    return epcUpdate;

}

int rfid::read_Tag(char *epc, int *rssi, int *Antenna, int *Frequency, int *Phase, int *Protocol)
{
    int TagInfo;
    TagInfo = readTag(epc, rssi, Antenna, Frequency, Phase, Protocol);
    return TagInfo;

}

//int rfid::RFID_Setup(int argcRFID, char* argvRFID)
//{
//int AccessReader;
//argcRFID =  2;
//argvRFID[] = serialPort[];
//AccessReader = RFID( (argcRFID, argvRFID);
//return AccessReader;
//}

rfid::~rfid(){}

//void rfid::writememwordscmd(int argc, char *argv[])
//{
//   writememwordscmd(argc, argv);
//}

