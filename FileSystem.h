#ifndef HEADER_FILE
#define HEADER_FILE


#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_MAX 64
#define START_OF_FAT 0
#define START_OF_ROOT 8
#define START_OF_DATA 10
#define FAT_SIZE 2048
#define DIR_TABLE_SIZE 32
#define DATA_SIZE 1048576

struct FAT{
	uint16_t next; //2 bytes
};

struct Entry{
	char *name; //11 bytes
	uint16_t create_time; //2 bytes
	uint16_t last_access; //2 bytes
	uint16_t modified_time; //2 bytes
	uint16_t start_blocks; //2 bytes
	uint32_t size; //4 bytes
};


int fd, currentDIR;
struct FAT *fatMap;
struct Entry *dirTable;
char *dataMap;

void map(char *drive);
void unmap();
void setup(char *drive);
void createRoot();
char *getcurrentDate(int i);
char *getcurrentTime(int i);
void initEntry(int index);
int findfreeFAT();
int findFreeEntry();
int searchFile(char *filename);
void create(char *filename , int flag);
void fs_delete(char *filename);
void fs_read(char *filename);
void fs_write(char *filename , char *writeData);
int fs_open(char *filename);
void list();
void fs_exit();
void fs_close();
#endif

