/*
*******************************************************************************
*FILE			StampCollector.h
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/


#ifndef _STAMP_COLLECTOR_H
#define _STAMP_COLLECTOR_H


#include "stampProject.h"
#include <conio.h>
#include <iostream>
#define kADD_ITEM			'1'
#define kDELETE_ITEM		'2'
#define kSEARCH				'3'
#define kDELETE_DATABASE	'4'
#define kDISPLAY_DATABASE	'5'
#define kGENERATE_RANDOM	'6'
#define kDOMAIN_DETAILS		'7'
#define kEXIT				'0'
#define kINVALID_CHARACTER  255

#define kONE_INPUT			1
#define kFIRST_CHARACTER	0
#define kFieldWidth			50
#define kFieldWidthInfo		65
#define kBarWidth 85
#define kDecimal 10
#define kIntFound 1

///
/// \class StampCollector
/// NAME		: StampCollector <br>
/// PURPOSE		: The StampCollector generates user output for the Stamp Project.
///

class StampCollector
{
private:
	StampCollection stampbook;
	vector<dummyStamp> searchResults;

public:
	// Constructors
	StampCollector(void);

	// Methods
	
	
	// These methods aree all declared with int and void for now.
	int UseStampbook(void);											// The whole program should happen from in here
	int ProcessUserInput(void);										// Sits and waits
	int DisplayAllStamps(vector<dummyStamp> stamps);				// Prompts DAL for stamps one at a time, all the way through, and prints them out, uses DisplayStamp
	int DisplayStamp(vector<dummyStamp> stamps, int stampIndex);	// Displays a specific stamp
	int AddStamp(void);												// Add a stamp to the database. calls add stamp from DAL and passes in either a string or skeleton stamp	
	int DeleteStamp(int index);											// Deletes a specific stamp somehow?
	int DeleteAllStamps(void);										// Deletes all stamps
	int SearchStamps(void);											// Search all stamps
	// int DisplaySearchResults(void);								// Displays the results of a stamp search
	int LoadExistingStamps(void);									// Load all existing stamps from a file
	int DummyStamps(void);											// Fill the database with dummy stamps
	void GetDomainDetails(void);
	void EditStamp(dummyStamp& dummy);
	int DisplayDatabase(bool search = false);
	void DrawMenus(std::string menuChoice);							// Will draw the main menu to the screen
	int DisplaySingleStamp(const dummyStamp* dummy);
	static void StampCollector::ClearScreen(void);

	static char GetChar(std::string prompt = "");
	static std::string GetString(std::string prompt = "");
	static double GetDouble(std::string prompt = "");
};



#endif