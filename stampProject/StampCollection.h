/*
*******************************************************************************
*FILE			StampCollection.h
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/


#include "StampProject.h"
#include "Stamp.h"
#include <fstream>
#include <iostream>
#ifndef _STAMP_COLLECTION_H
#define _STAMP_COLLECTION_H


#define kStampsFound 0
#define kStampsNotFound -1
#define kSuccess 0
#define kFail -1
#define kStrEq 0


// Search Specifications
const char kRaritySpec = 'r';
const char kImageSpec = 'i';



///
/// \class StampCollection
/// NAME		: StampCollection <br>
/// PURPOSE		: The StampCollection class models a stamp collection of
///				  Stamp objects.
///
class StampCollection
{
private:
	static int numberOfStamps;
	static int retrievalIndex;
	std::vector<Stamp> Collection;									/// The collection of Stamp objects.
	std::vector<Stamp> stampsFound;									/// Holds the results of a Stamp search.
	std::ifstream stampFile;

public: 
	Stamp RetrieveStamp(int stampIndex);							/// An accessor for a stamp in the collection.
	const vector<Stamp> GetStampsFound(void);						/// An accessor for the stamps found in a search.
	dummyStamp* GetStampCollection(bool search = false, bool stop = false);
	int AddStamp(Stamp stampToAdd);									/// Adds a Stamp to the collection.
	int AddStamp(dummyStamp stampToAdd);							/// Adds a Stamp to the collection.
	int DeleteStamp(int stampIndex);								///	Deletes a Stamp from the collection.
	void DeleteAllStamps(void);										/// Deletes all Stamps from the collection
	int SearchForStamp(string entry, char spec);					/// Searches for a Stamp by rarity or image.
	int SearchForStamp(std::string country);						/// Searches for a Stamp given its country.
	int SearchByImage(string image);								/// Searches for a stamp by image.
	int SearchByRarity(string rarity);								/// Searches for a stamp by rarity.
	int SearchForStamp(int date);									/// Searches for a Stamp given its date of use.
	int SearchForStamp(std::string country, int date);				/// Searches for a Stamp given its country and date.
	int SearchForStamp(std::string country, std::string rarity);	/// Searches for a Stamp given its country and rarity.
	int FilterByDate(int date);
	int FilterByRarity(string rarity);
	int FilterByImage(string image);
	bool ClearStampsFound(void);

	bool ImportDatabase(void);
	bool ExportDatabase(void);
	int AddRandomDummies(int howMany);
	dummyStamp* MakeRandomDummy(void);
	string randomStampValue(const string values[], int valueCount);
	double randomStampDenomination(void);
	int randomDate(void);
	std::string GetDomainDetails(void);

	std::string StampCollection::DoPreValidation(dummyStamp input);
	Stamp DummyToStamp(dummyStamp input);
	static dummyStamp StampToDummy(Stamp input);
	static vector<dummyStamp> ConvToDummySearchResults(vector<Stamp> results);

};







#endif