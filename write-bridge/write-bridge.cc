/**
 * @file    main.cpp
 * @brief	FPGA-writeBridge 
 * @author  Robin Sebastian (https://github.com/robseb) (git@robseb.de)
 * @mainpage
 * rstools application to write to any HSP-to-FPGA Bridges or the MPU address space
 * address
 */

#include <cstdio>
#include "hps.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sstream>
using namespace std;

#define DEC_INPUT 1
#define HEX_INPUT 0
#define BIN_INPUT 2

// Bridge Interfaces Base addresses 
#define LWHPSFPGA_OFST  0xff200000 // LWHPS2FPGA Bridge 
#define HPSFPGA_OFST    0xC0000000 // HPS2FPGA Bridge 
#define MPU_OFSET		0x0        // MPU (HPS Address space)

// Bridge interface End address 
#define LWHPSFPGA_END   0xFF3FFFFF
#define HPSFPGA_END     0xFBFFFFFF
#define MPU_END         0xFFFFFFFF

// Bridge interface range (allowed input offset)
#define LWH2F_RANGE    (LWHPSFPGA_END - LWHPSFPGA_OFST)
#define H2F_RANGE      (HPSFPGA_END - HPSFPGA_OFST)
#define MPU_RANGE      (MPU_END - MPU_OFSET)

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

#pragma region Check user input 
bool checkIfInputIsVailed(string input, bool DecHex)
{
	if (input.length() < 1) return false;
	uint16_t i = 0;

	// remove suffix "0x"
	if ((input.find_first_of("0x", 0) == 0) && (!DecHex))
	{
		input.replace(0, 2, "");
	}

	for (i = 0; i < input.length(); i++)
	{
		if (i != input.find_first_of(DecHex ? "0123456789" : "0123456789abcdefABCDEF", i)) break;
	}

	if (i == input.length()) return true;

	return false;
}
#pragma endregion

int main(void)
{
	

	return 0;
}

