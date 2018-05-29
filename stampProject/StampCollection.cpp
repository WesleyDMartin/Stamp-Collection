/*
*******************************************************************************
*FILE			StampCollection.cpp										  *
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*		 																	  *
*******************************************************************************
*/



#include "stampProject.h"
#include "Stamp.h"
#include "StampCollection.h"
#include "StampCollector.h"


// Initialize the total stamp count:
int StampCollection::numberOfStamps = 0;
int StampCollection::retrievalIndex = 0;



/**
* \brief This is an accessor for the vector of Stamp objects found in a search.
*
* <b>Description</b><br>
* This accessor retrieves the results of a search for a stamp. The searches
* use a combination of the image, the country, and the year of the stamp
* in order to conduct the search.
*
*
* \param			      <b>void</b>					- No parameters.
* \return		    	  <b>const vector<Stamp></b>	- The vector of search results.
*
*/
const vector<Stamp> StampCollection::GetStampsFound(void)
{
	return stampsFound;
}





/**
* \brief This is an accessor for the vector of Stamp objects in the collection.
*
* <b>Description</b><br>
* This accessor retrieves the entire stamp collection.
*
*
* \param			      <b>void</b>					- No parameters.
* \return		    	  <b>const vector<Stamp></b>	- The stamp collection vector.
*
*/
dummyStamp* StampCollection::GetStampCollection(bool search, bool stop)
{
	dummyStamp *temp;
	try
	{
		 temp = new dummyStamp;
	}
	catch (bad_alloc)
	{
		throw "Could not create dummy stamp";
	}
	if (stop)
	{
		retrievalIndex = 0;
		return NULL;
	}

	if (!search)
	{
		if (Collection.size() > retrievalIndex)
		{
			*temp = StampToDummy(RetrieveStamp(retrievalIndex));
			retrievalIndex++;
			return temp;
		}
		else
		{
			retrievalIndex = kEMPTY;
			return NULL;
		}
	}
	else
	{
		if (stampsFound.size() > retrievalIndex)
		{
			*temp = StampToDummy(RetrieveStamp(retrievalIndex));
			retrievalIndex++;
			return temp;
		}
		else
		{
			retrievalIndex = kEMPTY;
			return NULL;
		}
	}


}





/**
* \brief This method adds a stamp to the Stamp Collection.
*
* <b>Description</b><br>
* This method inserts a stamp into sorted position in the Collection. The stamps are sorted by country.
* Within the section of the Collection for a stamp's country, the stamps are sorted from most recent to oldest.
*
*
* \param	stampToAdd		 <b>Stamp</b>  -  The stamp to add to the collection.
*
* \return	stampAdded		 <b>int</b>	   -  A code indicating if the stamp was added.
*
*/
int StampCollection::AddStamp(Stamp stampToAdd)
{
	int stampAdded = kFail;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// First, locate the place in the Collection for the stamp's country.
	vector<Stamp>::iterator S = Collection.begin();

	// Get the country and date of the stamp to be added.
	
	int stampToAddDate = stampToAdd.GetDate();


	while (S != end)
	{
		int lexicographicOrder = stricmp(stampToAdd.GetCountry().c_str(), (*S).GetCountry().c_str());

		if (lexicographicOrder < kStrEq)
		{
			Collection.insert(S, stampToAdd);
			stampAdded = kSuccess;
			break;
		}
		else if (lexicographicOrder == kStrEq)
		{
			while ((stampToAddDate < (*S).GetDate()) && (lexicographicOrder == kStrEq))
			{
				// The stamp being added is more recent than
				// the stamp that S is pointing to.
				++S;

				if (S == end)
				{
					break;
				}

				// Update the country order to make sure we're still in the same sorting section.
				lexicographicOrder = stricmp(stampToAdd.GetCountry().c_str(), (*S).GetCountry().c_str());
			}
			

			Collection.insert(S, stampToAdd);
			stampAdded = kSuccess;
			break;
		}
		else
		{
			// The spot to add the stamp hasn't been reached.
			++S;
		}
	}

	if (stampAdded == kFail)
	{
		// If the stamp hasn't been added yet, its position is the last in the Collection.
		Collection.push_back(stampToAdd);
		stampAdded = kSuccess;
	}

	return stampAdded;
}





/**
* \brief This method adds a stamp to the Stamp Collection.
*
* <b>Description</b><br>
* This method inserts a stamp into sorted position in the Collection. The stamps are sorted by country.
* Within the section of the Collection for a stamp's country, the stamps are sorted from most recent to oldest.
*
*
* \param	stampToAdd		 <b>Stamp</b>  -  The stamp to add to the collection.
*
* \return	stampAdded		 <b>int</b>	   -  A code indicating if the stamp was added.
*
*/
int StampCollection::AddStamp(dummyStamp stampToAdd)
{
	int stampAdded = kSuccess;

	Stamp test(stampToAdd.image, stampToAdd.country, stampToAdd.denomination, stampToAdd.year, 
		stampToAdd.value, stampToAdd.rarity, stampToAdd.dimensions, stampToAdd.type, stampToAdd.adhesionType, stampToAdd.currency);


	AddStamp(test);
	return stampAdded;
}




int StampCollection::AddRandomDummies(int howMany)
{
	int stampsAdded = 0;
	dummyStamp* newDummy;

	for (stampsAdded = 0; stampsAdded < howMany; stampsAdded++)
	{
		newDummy = MakeRandomDummy();
		AddStamp(*newDummy);
		delete newDummy;
	}

	return stampsAdded;
}



dummyStamp* StampCollection::MakeRandomDummy(void)
{
	dummyStamp* newDummy = new dummyStamp;

	newDummy->image = randomStampValue(imageOptions, kImageOptions);
	newDummy->country = randomStampValue(countryOptions, kCountryOptions);
	newDummy->year = randomDate();
	newDummy->denomination = randomStampDenomination();
	newDummy->rarity = randomStampValue(rarityOptions, kRarityOptions);
	newDummy->value = ((rand() % 100) + 1.0);
	newDummy->dimensions[kWIDTH_INDEX] = (rand() % 50) + 10;
	newDummy->dimensions[kLENGTH_INDEX] = (rand() % 100) + 10;
	newDummy->type = randomStampValue(typeOptions, kTypeOptions);
	newDummy->adhesionType = randomStampValue(adhesionTypes, kAdhesionTypes);
	newDummy->currency = randomStampValue(currencyOptions, kCurrencyOptions);

	return newDummy;
}


string StampCollection::randomStampValue(const string values[], int valueCount)
{
	int randomIndex = 0;

	// Generate a random index in the array of strings:
	randomIndex = rand() % valueCount;
	
	return values[randomIndex];
}


double StampCollection::randomStampDenomination(void)
{
	return kMinDollarVal;
}



int StampCollection::randomDate(void)
{
	int enumerateYears = kCurrentYear - kEarliestStamp;
	int addFactor = 0;
	unsigned int year = kEarliestStamp;

	// Generate a random year:
	addFactor = rand() % enumerateYears;
	year = kEarliestStamp + addFactor;


	return year;
}


/**
* \brief This method deletes a stamp from the collection given its position.
*
* <b>Description</b><br>
* This method removes a stamp from the stamp Collection.
*
*
* \param	stampIndex		 <b>int</b>	   -  The index in the Collection of the stamp to delete.
*
* \return	stampDeleted	 <b>int</b>	   -  A code indicating if the stamp was deleted.
*
*/
int StampCollection::DeleteStamp(int stampID)
{
	int stampDeleted = kFail;

	// A reference to the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// A reference to the start of the collection.
	vector<Stamp>::iterator S = Collection.begin();


	try
	{
		while (S != end)
		{
			if (stampID == (*S).GetID())
			{
				// The stampID matches; delete the stamp from the collection.
				Collection.erase(S);
				stampDeleted = kSuccess;
				break;
			}

			// The stamp with the correct ID has not yet been found.
			++S;
		}
	}
	catch (const std::out_of_range oor)
	{
		throw "The stamp index could not be found in the Collection.\n";
	}


	return stampDeleted;
}





/**
* \brief This method deletes all stamps from the collection of stamps.
*
* <b>Description</b><br>
* This method removes a all stamps from the collection.
*
*
* \param					 <b>void</b>   -  No parameters.
*
* \return					 <b>void</b>   -  No return.
*
*/
void StampCollection::DeleteAllStamps(void)
{
	Collection.clear();
}





/**
* \brief This method searches for stamps of a given image type.
*
* <b>Description</b><br>
* This method searches for stamps given the image. All stamps matching the criteria are returned.
*
*
* \param	image		     <b>string</b>	   -  The image type to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchForStamp(string entry, char spec)
{
	int stampFound = kStampsNotFound;

	// Clear the search results.
	stampsFound.clear();

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();

	string currentStampComparator;

	// Determines if the search is to done by image or rarity:
	switch (spec)
	{
	case kImageSpec:
		currentStampComparator = (*S).GetImage();
		break;

	case kRaritySpec:
		currentStampComparator = (*S).GetRarity();
		break;
	}


	// Compile search results
	while (S != end)
	{
		if (entry == currentStampComparator)
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);
			stampFound = kStampsFound;
		}

		++S;
	}

	return stampFound;
}




/**
* \brief This method searches for stamps given their country of origin.
*
* <b>Description</b><br>
* This method searches for stamps given its country.
* All stamps matching the criteria are returned.
*
*
* \param	country		     <b>string</b>	   -  The country of origin of the stamp.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchForStamp(string country)
{
	int stampFound = kStampsNotFound;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();


	while (S != end)
	{
		if (stricmp(country.c_str(), (*S).GetCountry().c_str()) < kStrEq)
		{
			// Stamps with the given specifications won't be found 
			// after this position in the Collection.
			break;
		}
		else if (stricmp(country.c_str(),  (*S).GetCountry().c_str()) == kStrEq)
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}


	return stampFound;
}




/**
* \brief This method searches for stamps given its image type.
*
* <b>Description</b><br>
* This method searches for stamps given its image.
* All stamps matching the criteria are returned.
*
*
* \param	image		     <b>string</b>	   -  The image on the stamp.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchByImage(string image)
{
	int stampFound = kStampsNotFound;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();

	

	while (S != end)
	{
		if (stricmp(image.c_str(), (*S).GetImage().c_str()) == kStrEq)
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}


	return stampFound;
}




/**
* \brief This method searches for stamps given its image type.
*
* <b>Description</b><br>
* This method searches for stamps given its image.
* All stamps matching the criteria are returned.
*
*
* \param	image		     <b>string</b>	   -  The image on the stamp.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchByRarity(string rarity)
{
	int stampFound = kStampsNotFound;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();


	while (S != end)
	{
		if (stricmp(rarity.c_str(), (*S).GetRarity().c_str()) == kStrEq)
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}


	return stampFound;
}





/**
* \brief This method filters a dummyStamp collection by date.
*
* <b>Description</b><br>
* This method searches for stamps given its date.
* All stamps matching the criteria are returned.
*
*
* \param	date		     <b>int</b>		   -  The year of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::FilterByDate(int date)
{
	if (stampsFound.size() > 0)
	{
		// A marker for the end of the collection.
		vector<Stamp>::iterator begin = stampsFound.begin();

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator S = stampsFound.end() - 1;

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator N = stampsFound.begin();


		// Compile search results
		while (S != begin)
		{
			if (date < (*S).GetDate())
			{
				// Erase the stamps prior to and including 
				// the stamp we are checking for the date:
				stampsFound.erase(stampsFound.begin(), S);
				S = stampsFound.begin();
				break;
			}
			else if (date != (*S).GetDate())
			{
				// Remove the stamp from the filtered results since it does not
				// have the type of image being searched for.
				N = S - 1;
				stampsFound.erase(S);
				S = N;
			}
			else
			{
				--S;
			}
		}

		// One more case is necessary for the first element.
		if (date != (*S).GetDate())
		{
			// Remove the first stamp since it doesn't fit the filter criteria
			stampsFound.erase(S);
		}
	}

	return (int)stampsFound.size();
}





/**
* \brief This method filters a dummyStamp collection by image.
*
* <b>Description</b><br>
* This method searches for stamps given its date.
* All stamps matching the criteria are returned.
*
*
* \param	date		     <b>int</b>		   -  The year of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::FilterByImage(string image)
{
	bool erased = false;

	if (stampsFound.size() > 0)
	{
		// A marker for the end of the collection.
		vector<Stamp>::iterator begin = stampsFound.begin();

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator S = stampsFound.end() - 1;

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator N = stampsFound.begin();


		// Compile search results
		while (S != begin)
		{
			if (stricmp(image.c_str(), (*S).GetImage().c_str()) != kStrEq)
			{
				// Remove the stamp from the filtered results since it does not
				// have the type of image being searched for.
				N = S - 1;
				stampsFound.erase(S);
				S = N;
				erased = true;
			}
			else
			{
				--S;
			}
		}

		// One more case is necessary for the first element.
		if (stricmp(image.c_str(), (*S).GetImage().c_str()) != kStrEq)
		{
			// Remove the first stamp since it doesn't fit the filter criteria
			stampsFound.erase(S);
		}
	}
	
	return (int)stampsFound.size();
}





/**
* \brief This method filters a dummyStamp collection by image.
*
* <b>Description</b><br>
* This method searches for stamps given its date.
* All stamps matching the criteria are returned.
*
*
* \param	date		     <b>int</b>		   -  The year of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::FilterByRarity(string rarity)
{
	bool erased = false;

	if (stampsFound.size() > 0)
	{
		// A marker for the end of the collection.
		vector<Stamp>::iterator begin = stampsFound.begin();

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator S = stampsFound.end() - 1;

		// Start searching at the beginning of the Collection.
		vector<Stamp>::iterator N = stampsFound.begin();


		// Compile search results
		while (S != begin)
		{
			if (stricmp(rarity.c_str(), (*S).GetRarity().c_str()) != kStrEq)
			{
				// Remove the stamp from the filtered results since it does not
				// have the type of image being searched for.
				N = S - 1;
				stampsFound.erase(S);
				S = N;
				erased = true;
			}
			else
			{
				--S;
			}
		}

		// One more case is necessary for the first element.
		if (stricmp(rarity.c_str(), (*S).GetRarity().c_str()) != kStrEq)
		{
			// Remove the first stamp since it doesn't fit the filter criteria
			stampsFound.erase(S);
		}
	}

	return (int)stampsFound.size();
}






/**
* \brief This method searches for stamps given their date of use.
*
* <b>Description</b><br>
* This method searches for stamps given its date.
* All stamps matching the criteria are returned.
*
*
* \param	date		     <b>int</b>		   -  The year of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchForStamp(int date)
{
	int stampFound = kStampsNotFound;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();


	while (S != end)
	{
		//if (date > (*S).GetDate())
		//{
		//	// Stamps with the given specifications won't be found 
		//	// after this position in the Collection.
		//	break;
		//}
		//else 
		if (date == (*S).GetDate())
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}

	return stampFound;
}




/**
* \brief This method searches for stamps given their country of origin and year of use.
*
* <b>Description</b><br>
* This method searches for stamps given its country and year.
* All stamps matching the criteria are returned.
*
*
* \param	country		     <b>string</b>	   -  The country of origin of the stamp.
* \param	date		     <b>int</b>		   -  The year of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchForStamp(string country, int date)
{
	int stampFound = kStampsNotFound;

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();

	while (S != end)
	{
		if ((country < (*S).GetCountry()) || (date > (*S).GetDate()))
		{
			// Stamps with the given specifications won't be found 
			// after this position in the Collection.
			break;
		}
		else if ((country == (*S).GetCountry()) && (date == (*S).GetDate()))
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}

	return stampFound;
}






/**
* \brief This method searches for stamps given their country of origin and rarity.
*
* <b>Description</b><br>
* This method searches for stamps given its country and rarity.
* All stamps matching the criteria are returned.
*
*
* \param	country		     <b>string</b>	   -  The country of origin of the stamp.
* \param	rarity		     <b>string</b>	   -  The rarity of the stamp to search for.
*
* \return	stampFound		 <b>int</b>		   -  A code indicating if any matching stamps were found.
*
*/
int StampCollection::SearchForStamp(string country, string rarity)
{
	int stampFound = kStampsNotFound;

	// Clear the search results.
	// stampsFound.clear();

	// A marker for the end of the collection.
	vector<Stamp>::iterator end = Collection.end();

	// Start searching at the beginning of the Collection.
	vector<Stamp>::iterator S = Collection.begin();


	while (S != end)
	{
		if (country < (*S).GetCountry())
		{
			// Stamps with the given specifications won't be found 
			// after this position in the Collection.
			break;
		}
		else if ((country == (*S).GetCountry()) && (rarity == (*S).GetRarity()))
		{
			// Add the stamp to the list of stamps found with the given specs.
			stampsFound.push_back(*S);

			if (stampFound != kStampsFound)
			{
				stampFound = kStampsFound;
			}
		}

		++S;
	}


	return stampFound;
}




vector<dummyStamp> StampCollection::ConvToDummySearchResults(vector<Stamp> results)
{
	// The vector to store the results in after converting to dummies
	vector<dummyStamp> searchResults;

	// A marker for the end of the search results.
	vector<Stamp>::iterator end = results.end();

	// Start searching at the beginning of the search results.
	vector<Stamp>::iterator S = results.begin();


	// Convert the stamps
	while (S != end)
	{
		searchResults.push_back(StampToDummy(*S));
		++S;
	}

	return searchResults;
}




bool StampCollection::ClearStampsFound(void)
{
	bool resultsCleared = false;

	stampsFound.clear();

	if (stampsFound.size() == 0)
	{
		resultsCleared = true;
	}

	return resultsCleared;
}


bool  StampCollection::ExportDatabase(void)
{
	bool retCode = true;
	std::ofstream stampFile;
	stampFile.open("ricardomoh.txt");
	// Check to see that the file is open
	if (stampFile.is_open())
	{
		vector<Stamp>::iterator S = Collection.begin();


		// Convert the stamps
		while (S != Collection.end())
		{
			stampFile << *S;
			++S;
		}

	}
	// Return false if file could not be opened
	else
	{
		retCode = false;
	}

	// Close the file
	stampFile.close();

	return retCode;
}

bool  StampCollection::ImportDatabase(void)
{
	// Initialization
	int totalStamps = kEMPTY;
	Stamp newStamp;

	stampFile.open("ricardomoh.txt");
	bool retCode = true;

	// Check to see that the file is open
	if (stampFile.is_open())
	{
		while(kTRUE)
		{
			// Step through the file, one line at a time
			stampFile.get();
			if (stampFile.eof())
			{
				break;
			}
			stampFile.unget();

			stampFile >> newStamp;
			this->AddStamp(newStamp);
		}
	}
	// Return false if file could not be opened
	else
	{
		retCode = false;
	}

	// Check for an empty file
	if (Collection.empty())
	{
		retCode = false;
	}
	// Close the file
	stampFile.close();

	return retCode;
}



/**
* \brief This method returns a reference to a stamp at the given index in the Collection.
*
* <b>Description</b><br>
* This method retrieves a stamp in the Collection. The stamp's index in the Collection is
* a parameter.
*
*
* \param	stampIndex		 <b>int</b>				-  The index of the stamp in the collection.
*
* \return					 <b>const Stamp&</b>	-  The stamp if it was found.
*
*/
Stamp StampCollection::RetrieveStamp(int stampIndex)
{
	Stamp retrievedStamp;

	try
	{
		// Attempt to locate the stamp in the Collection.
		retrievedStamp = Collection.at(stampIndex);
	}
	catch (const std::out_of_range oor)
	{
		cout << "The stamp index could not be found in the Collection.\n";
	}

	return retrievedStamp;
}





dummyStamp StampCollection::StampToDummy(Stamp input)
{
	dummyStamp dummy;
	dummy.image = input.GetImage();
	dummy.country = input.GetCountry();
	dummy.denomination = input.GetDenomination();
	dummy.type = input.GetType();
	dummy.year = input.GetDate();
	dummy.currency = input.GetCurrency();
	memcpy(dummy.dimensions, input.GetDimensions(), kDimensions * sizeof(double));
	dummy.rarity = input.GetRarity();
	dummy.value = input.GetValue();
	dummy.adhesionType = input.GetAdhesionType();
	dummy.stampID = input.GetID();
	return dummy;
}





Stamp StampCollection::DummyToStamp(dummyStamp input)
{
	Stamp newStamp;
	newStamp.SetImage(input.image);
	newStamp.SetCountry(input.country);
	newStamp.SetDenomination(input.denomination);
	newStamp.SetType(input.type);
	newStamp.SetDate(input.year);
	newStamp.SetCurrency(input.currency);
	memcpy((void *)newStamp.GetDimensions(), input.dimensions, kDimensions * sizeof(double));
	newStamp.SetRarity(input.rarity);
	newStamp.SetValue(input.value);
	newStamp.SetAdhesionType(input.adhesionType);
	newStamp.SetStampID(input.stampID);
	return newStamp;
}

std::string StampCollection::DoPreValidation(dummyStamp input)
{
	return Stamp::PreValidation(input);
}

std::string StampCollection::GetDomainDetails(void)
{
	return Stamp::DomainDetails();
}