#pragma once
/*
*******************************************************************************
*FILE			stampProject.h
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/


#ifndef _STAMP_PROJECT_H
#define _STAMP_PROJECT_H
#define kSUCCESS 		0
#define kFAILURE 		-1
#define kTRUE			1
#define kEMPTY			0
#define kSTRINGS_EQUAL	0
#define kDimensions		2
#define kWIDTH_INDEX	0
#define kSKIP_FIELD			-1
#define kLENGTH_INDEX	1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <vector>
#include <new>
#include <time.h>
#include <random>
#include <windows.h>
#include "StampProject.h"

// Pragmas
#pragma warning(disable: 4996)


typedef struct tagdummyStamp
{
	std::string		image;
	std::string		country;
	double			denomination;
	std::string		type;
	int				year;
	std::string		currency;
	double			dimensions[kDimensions];
	std::string		rarity;
	double			value;
	std::string		adhesionType;
	int				stampID;

} dummyStamp;

using namespace std;
#endif