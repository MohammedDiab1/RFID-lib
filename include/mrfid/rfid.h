#ifndef MRFID_H
#define MRFID_H


#include <iostream>
#include <stdint.h>

class rfid
{
private:
    int data1;
    float data2;

public:
    rfid(); 
    ~rfid();
    void insertIntegerData(int d);
    float insertFloatData();

    //ADDED
    int read_Memory(int bank, int address, int count, char* epc, uint16_t *words);
    int write_Memory(int bank, int address, char* Data, char* epc);
    int change_Epc(char *epc, char *NewEPC);
    int read_Tag(char *epc, int *rssi, int *Antenna, int *Frequency, int *Phase, int *Protocol);
    int RFID_Setup(int argcRFID, char *argvRFID[]);

    void readcmd(int argc, char *argv[]);
    void readmemwordscmd(int argc, char *argv[]);
    void writememwordscmd(int argc, char *argv[]);
};

#endif
