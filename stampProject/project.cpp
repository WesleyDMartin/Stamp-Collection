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



int main(void)
{
	// Seed random numbers
	srand((unsigned int)time(NULL));

	// stamp stuff
	StampCollector collector;
	collector.UseStampbook();

	//collector.DummyStamps(10);
	//collector.DisplayAllStamps();


	return kSUCCESS;
}


