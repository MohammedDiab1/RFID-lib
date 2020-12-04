#ifndef MWLIB_H
#define MWLIB_H


#include "serial_reader_imp.h"
 enum LLRP_ResultCode;
#include <tm_config.h>
#include <serial_reader_imp.h>

static const char *hexChars = "0123456789abcdefABCDEF";
static const char *decimalChars = "0123456789";
static const char *regions[] = {"UNSPEC", "NA", "EU", "KR", "IN", "JP", "PRC",
                                "EU2", "EU3", "KR2", "PRC2", "AU", "NZ", "REDUCED_FCC"
                               };
static const char *powerModes[] = {"FULL", "MINSAVE", "MEDSAVE", "MAXSAVE", "SLEEP"};
static const char *userModes[] = {"NONE", "PRINTER", NULL, "PORTAL"};

static const char *tagEncodingNames[] = {"FM0", "M2", "M4", "M8"};
static const char *sessionNames[] = {"S0", "S1", "S2", "S3"};
static const char *targetNames[] = {"A", "B", "AB", "BA"};
static const char *gen2LinkFrequencyNames[] = {"250kHz", "300kHz", "320kHz", "40kHz", "640KHz"};
static const char *tariNames[] = {"25us", "12.5us", "6.25us"};

static const char *iso180006bLinkFrequencyNames[] = {"40kHz", "160kHz"};

static const char *iso180006bModulationDepthNames[] = {"99 percent", "11 percent"};

static const char *iso180006bDelimiterNames[] = {"", "Delimiter1", "", "", "Delimiter4"};
static const char *protocolNames[] = {NULL, NULL, NULL, "ISO180006B",
                                      NULL, "GEN2", "UCODE", "IPX64", "IPX256"
                                     };

static const char *bankNames[] = {"Reserved", "EPC", "TID", "User"};
static const char *selectOptionNames[] = {"EQ", "NE", "GT", "LT"};

static const char *tagopNames[] = {"Gen2.Read","Gen2.Write","Gen2.Lock",
                                   "Gen2.Kill"
                                  };



int RFID(int argc, char *argv[]);
void errx(int exitval, const char *fmt, ...);
void serialPrinter(bool tx, uint32_t dataLen, const uint8_t data[],
                   uint32_t timeout, void *cookie);
void stringPrinter(bool tx, uint32_t dataLen, const uint8_t data[],
                   uint32_t timeout, void *cookie);

void runcmd(int argc, char *argv[]);
int parseEpc(const char *arg, TMR_TagData *tag, int *nchars);
int parseFilter(const char *arg, TMR_TagFilter **filterp, int *nchars);
int parseTagop(const char *arg, TMR_TagOp **tagopp, int *nchars);
int parseU32List(const char *arg, TMR_uint32List *list, int *nchars);
int parseU8List(const char *arg, TMR_uint8List *list, int *nchars);
int parseWords(const char *arg, TMR_uint16List *list);
int parseBytes(const char *arg, TMR_uint8List *list);
int parseReadPlan(const char *arg, TMR_ReadPlan *plan, int *nchars);
//int parseLockAction(const char *arg, TMR_TagLockAction *action);
void printU8List(TMR_uint8List *list);
void printU32List(TMR_uint32List *list);
void printPortValueList(TMR_PortValueList *list);
void printReadPlan(TMR_ReadPlan *plan);
void printFilter(TMR_TagFilter *filter);
void printTagop(TMR_TagOp *tagop);
const char *listname(const char *list[], int listlen, unsigned int id);
int listid(const char *list[], int listlen, const char *name);

#ifdef TMR_ENABLE_READLINE
char *command_generator(const char *, int);
char **demo_completion(const char *, int, int);
char *getcommand_interactive();
char *getcommand_noninteractive();
#endif /* TMR_ENABLE_READLINE */


//void readcmd(int argc, char *argv[]);
//void writeepccmd(int argc, char *argv[]);
//void readmemwordscmd(int argc, char *argv[]);
void readmembytescmd(int argc, char *argv[]);
//void writememwordscmd(int argc, char *argv[]);
void writemembytescmd(int argc, char *argv[]);
void getcmd(int argc, char *argv[]);
void setcmd(int argc, char *argv[]);
void tagMetaData(int argc, char *argv[]);
void gpiodirection(int argc, char *argv[]);

//ADDED
int readMemory(int bank, int address, int count, char* epc, uint16_t *words);
int writeMemory(int bank, int address, char* Data, char* epc);
int changeEpc(char *epc, char *NewEPC);
int readTag(char *epc, int *rssi, int *Antenna, int *Frequency, int *Phase, int *Protocol);

//int RFID(int argc, char *argv[]);


#endif
