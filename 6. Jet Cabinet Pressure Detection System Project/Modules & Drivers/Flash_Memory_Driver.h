
#ifndef FLASH_MEMORY_DRIVER_H_
#define FLASH_MEMORY_DRIVER_H_
#define flashSpace 5

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "EclipseBugsCorrections.h"

typedef struct{

	uint32_t* Base;
	uint32_t* Head;
	uint32_t* Tail;
	uint32_t Count;
	uint32_t Length;

}fifo_flash;

typedef enum {

	Flash_No_error,
	Flash_Memory_Empty,
	Flash_Memory_Full

}Flash_Memory_Status;

extern void Storing_State(uint32_t);
extern void Waiting_State(uint32_t);

void Flash_Memory_init(fifo_flash* flashptr, uint32_t* flashArr, uint32_t Length);
Flash_Memory_Status Flash_Memory_Enqueue(fifo_flash* flashptr, uint32_t* pval);

// Flash_Memory_Status Flash_Memory_Dequeue(fifo_flash* flashptr, uint32_t* flashSize, uint32_t Length);

#endif /* FLASH_MEMORY_DRIVER_H_ */