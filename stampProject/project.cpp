/*
*******************************************************************************
*FILE			stampCollection.cpp										  *
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/


#include "StampProject.h"
#include "StampCollection.h"
#include "StampCollector.h"


// This is the entry point for our very simple stample collection
int main(void)
{
	// Seed random numbers
	srand((unsigned int)time(NULL));

	// stamp stuff
	StampCollector collector;
	collector.UseStampbook();


	return kSUCCESS;
}


