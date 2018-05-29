/*
*******************************************************************************
*FILE			StampCollector.cpp										  *
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*		 																	  *
*******************************************************************************
*/



#include "stampProject.h"
#include "StampCollection.h"
#include "StampCollector.h"


StampCollector::StampCollector(void)
{

}

// Takes in the book. The whole program should happen from in here
// So far it loads any existing stamps then passes control to input handler
int StampCollector::UseStampbook(void)	
{
	// Load all existing stamps
	LoadExistingStamps();

	// Process button input
	ProcessUserInput();


	return kSUCCESS;
}



// Sits and waits
int StampCollector::ProcessUserInput(void)
{
	unsigned char input = ' ';
	// This loop will run until the program is quit
	while (input != kEXIT)
	{
		// Draw the main menu
		DrawMenus("Main");

		// Print error message if last character was invalid
		if (input == kINVALID_CHARACTER)
		{
			printf("Sorry, that was an invalid selection, please try again\n");
		}

		// Get user input
		input = GetChar();

		// Choose appropriate action based on input
		switch (input)
		{
		case kADD_ITEM:
			AddStamp();
			break;

		case kDELETE_ITEM:
			DeleteStamp((int)GetDouble("\nPlease enter a stamp index to delete  >>  "));
			break;

		case kSEARCH:
			SearchStamps();
			break;

		case kDELETE_DATABASE:
			DeleteAllStamps();
			break;

		case kDISPLAY_DATABASE:
			DisplayDatabase();
			break;

		case kGENERATE_RANDOM:
			DummyStamps();
			break;

		case kDOMAIN_DETAILS:
			GetDomainDetails();
			break;

			// Exit the program
		case kEXIT:
			stampbook.ExportDatabase();
			break;

			// Set the invalid character flag
		default:
			input = kINVALID_CHARACTER;
			break;
		}
	}
	return kSUCCESS;
}


void StampCollector::GetDomainDetails(void)
{
	char * printPointer = (char *)malloc(stampbook.GetDomainDetails().length());
	strcpy(printPointer, stampbook.GetDomainDetails().c_str());


	ClearScreen();	
	while (*printPointer != '\0')
	{
		if (*printPointer != '\v')
		{

			printf("%c", *printPointer);
			printPointer++;
		}
		else
		{
			GetChar("\nPlease press enter to continue");
			printPointer++;
			ClearScreen();
		}
	}

	
	GetChar("Press any key to return to main menu\n");
	ClearScreen();
}



/**
* \brief This method displays the entire stamp collection, one stamp at a time.
*
* <b>Description</b><br>
* This method removes a stamp from the stamp Collection.
*
*
* \param	Collection		 <b>StampCollection</b>	   -  The stamp collection to look for the stamp in.
*
* \return	kSucess			 <b>int</b>				   -  A code indicating if the stamp was displayed.
*
*/
int StampCollector::DisplayAllStamps(vector<dummyStamp> stamps)
{
	const string kBar = "-----------------------------------------------------------------------------";
	const char kNewline = '\n';
	size_t size = stamps.size();
	unsigned int index = 0;		// The Stamp's index in the collection.

	if (size > 0)
	{
		cout.width(kBarWidth);
		cout << kBar;
		cout << kNewline;

		while (index < size)
		{
			DisplayStamp(stamps, index);
			index++;
		}
	}
	else
	{
		cout << "There were no matches for your search criteria.\n";
		cout << kNewline;
	}


	return kSUCCESS;
}

int StampCollector::DisplayDatabase(bool search)
{
	const string kBar = "-----------------------------------------------------------------------------";
	const char kNewline = '\n';
	const dummyStamp* stamp;
	bool exit = false;


		cout.width(kBarWidth);
		cout << kBar;
		cout << kNewline;

		while ((stamp = stampbook.GetStampCollection(search)) != NULL && !exit)
		{
			ClearScreen();
			DisplaySingleStamp(stamp);
			switch (GetChar("    Enter : Display Next Stamp\n    d    : Delete this stamp\n    x     : Stop Displaying Stamps\n    >> "))
			{
			case '\n':
				continue;
			case 'x':
				stampbook.GetStampCollection(search, false);
				exit = true;
				break;
			case 'd':
				DeleteStamp(stamp->stampID);
				break;

			}
		}
		if (!exit)
		{
			while (GetChar("All Stamps Displayed, Press r Key to Return to Main Menu\n>> ") != 'r');
		}


		ClearScreen();
	return kSUCCESS;
}



/**
* \brief This method finds and displays the information for a stamp in the collection.
*
* <b>Description</b><br> This method displays the information for a stamp in the collection given its index.
* 
*
* \param	Collection		 <b>StampCollection</b>	   -  The stamp collection to look for the stamp in.
* \param	stampIndex		 <b>int</b>				   -  The index in the Collection of the stamp to delete.
*
* \return	kSucess			 <b>int</b>				   -  A code indicating if the stamp was displayed.
*
*/
int StampCollector::DisplayStamp(vector<dummyStamp> stamps, int stampIndex)
{
	const char kTab	    = '\t';
	const char kNewline = '\n';
	const string kSpaces = "  ";
	const string kBar = "-----------------------------------------------------------------------------";

	dummyStamp* dummy;

	dummy = &(stamps.at(stampIndex));

	cout.width(kFieldWidthInfo);
	cout << "Displaying information for Stamp #" << dummy->stampID << kNewline << kNewline;
	cout.width(kFieldWidth);
	cout << "Image:" << kSpaces;
	cout << dummy->image << kNewline;
	cout.width(kFieldWidth);
	cout << "Country:" << kSpaces;
	cout << dummy->country << kNewline;
	cout.width(kFieldWidth);
	cout << "Denomination:" << kSpaces;
	cout << dummy->denomination << kNewline;
	if (!dummy->type.empty())
	{
		cout.width(kFieldWidth);
		cout << "Type:" << kSpaces;
		cout << dummy->type << kNewline;
	}
	if (dummy->year != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Date:" << kSpaces;
		cout << dummy->year << kNewline;
	}
	if (!dummy->currency.empty())
	{
		cout.width(kFieldWidth);
		cout << "Currency:" << kSpaces;
		cout << dummy->currency << kNewline;
	}
	if (dummy->dimensions[kLENGTH_INDEX] != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Width:" << kSpaces;
		cout << dummy->dimensions[kLENGTH_INDEX] << kNewline;
	}
	if (dummy->dimensions[kWIDTH_INDEX] != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Length:" << kSpaces;
		cout << dummy->dimensions[kWIDTH_INDEX] << kNewline;
	}
	if (!dummy->rarity.empty())
	{
		cout.width(kFieldWidth);
		cout << "Rarity:" << kSpaces;
		cout << dummy->rarity << kNewline;
	}
	if (dummy->value != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Value:" << kSpaces;
		cout << dummy->value << kNewline;
	}
	if (!dummy->rarity.empty())
	{
		cout.width(kFieldWidth);
		cout << "Adhesion Type:" << kSpaces;
		cout << dummy->adhesionType << kNewline << kNewline;
	}

	return kSUCCESS;
}

/**
* \brief This method finds and displays the information for a stamp in the collection.
*
* <b>Description</b><br> This method displays the information for a stamp in the collection given its index.
*
*
* \param	Collection		 <b>StampCollection</b>	   -  The stamp collection to look for the stamp in.
* \param	stampIndex		 <b>int</b>				   -  The index in the Collection of the stamp to delete.
*
* \return	kSucess			 <b>int</b>				   -  A code indicating if the stamp was displayed.
*
*/
int StampCollector::DisplaySingleStamp(const dummyStamp* dummy)
{
	const char kTab = '\t';
	const char kNewline = '\n';
	const string kSpaces = "  ";
	const string kBar = "-----------------------------------------------------------------------------";


	cout.width(kFieldWidthInfo);
	cout << "Displaying information for Stamp #" << dummy->stampID << kNewline << kNewline;
	cout.width(kFieldWidth);
	cout << "Image:" << kSpaces;
	cout << dummy->image << kNewline;
	cout.width(kFieldWidth);
	cout << "Country:" << kSpaces;
	cout << dummy->country << kNewline;
	cout.width(kFieldWidth);
	cout << "Denomination:" << kSpaces;
	cout << dummy->denomination << kNewline;
	if (!dummy->type.empty())
	{
		cout.width(kFieldWidth);
		cout << "Type:" << kSpaces;
		cout << dummy->type << kNewline;
	}
	if (dummy->year != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Date:" << kSpaces;
		cout << dummy->year << kNewline;
	}
	if (!dummy->currency.empty())
	{
		cout.width(kFieldWidth);
		cout << "Currency:" << kSpaces;
		cout << dummy->currency << kNewline;
	}
	if (dummy->dimensions[kLENGTH_INDEX] != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Width:" << kSpaces;
		cout << dummy->dimensions[kLENGTH_INDEX] << kNewline;
	}
	if (dummy->dimensions[kWIDTH_INDEX] != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Length:" << kSpaces;
		cout << dummy->dimensions[kWIDTH_INDEX] << kNewline;
	}
	if (!dummy->rarity.empty())
	{
		cout.width(kFieldWidth);
		cout << "Rarity:" << kSpaces;
		cout << dummy->rarity << kNewline;
	}
	if (dummy->value != kSKIP_FIELD)
	{
		cout.width(kFieldWidth);
		cout << "Value:" << kSpaces;
		cout << dummy->value << kNewline;
	}
	if (!dummy->adhesionType.empty())
	{
		cout.width(kFieldWidth);
		cout << "Adhesion Type:" << kSpaces;
		cout << dummy->adhesionType << kNewline << kNewline;
	}

	cout.width(kBarWidth);
	cout << kBar;
	cout << kNewline << kNewline;

	return kSUCCESS;
}




// Add a stamp to the database. calls add stamp from DAL and passes in either a string or skeleton stamp
int StampCollector::AddStamp(void)
{
	// Initializations
	string validator;
	dummyStamp dummy;
	char input = kEMPTY;

	// Tell user what is happening
	DrawMenus("Add Stamp");

	// Get Country
	dummy.country = GetString("    >> Please Enter Country of Stamp: ");

	// Get Denomination
	dummy.denomination = GetDouble("    >> Please Enter Denomination (i.e. , 1 of Stamp: ");

	// Get Image
	dummy.image = GetString("    >> Please Enter Image Type of Stamp: ");

	// Ask if they wish to provide more detailed information
	printf("\nThat is it all that is required. Would you like to add more detail?\n");
	do
	{
		input = GetChar("    y: Add more detail\n    n: Finish Entry\n");
	} while (input != 'y' && input != 'n');
	if (input == 'y')
	{
		DrawMenus("Add Details");

		// Get Year
		dummy.year = (int)GetDouble("    >> Please Enter Year of Stamp: ");

		// Get Value
		dummy.value = GetDouble("    >> Please Enter Value of Stamp: ");

		// Get Rarity
		dummy.rarity = GetString("    >> Please Enter Rarity of Stamp: ");

		// Get Dimensions
		// -- Get Width
		dummy.dimensions[kWIDTH_INDEX] = GetDouble("    >> Please Enter Width of Stamp: ");
		// -- Get Length
		dummy.dimensions[kLENGTH_INDEX] = GetDouble("    >> Please Enter Length of Stamp: ");

		// Get Type
		dummy.type = GetString("    >> Please Enter Type of Stamp: ");

		// Get Adhesion Type
		dummy.adhesionType = GetString("    >> Please Enter Adhesion Type of the Stamp: ");

		// Get Currency
		dummy.currency = GetString("    >> Please Enter Type of Stamp: ");
	}
	else
	{
		dummy.year = kSKIP_FIELD;
		dummy.value = kSKIP_FIELD;
		dummy.rarity = "";
		dummy.dimensions[kWIDTH_INDEX] = kSKIP_FIELD;
		dummy.dimensions[kLENGTH_INDEX] = kSKIP_FIELD;
		dummy.type = "";
		dummy.adhesionType = "";
		dummy.currency = "";
	}

	EditStamp(dummy);

	try
	{
		stampbook.AddStamp(dummy);
	}
	catch (const char* e)
	{
		printf("%s", e);
	}
	catch (...)
	{

	}

	return kSUCCESS;
}


void StampCollector::EditStamp(dummyStamp& dummy)
{
	std::string errors;
	size_t pipe;
	while (!(errors = stampbook.DoPreValidation(dummy)).empty())
	{
		DrawMenus("Edit");


		//printf("The follow fields are invalid");
		pipe = errors.find_first_of("|");
		errors = errors.erase(0, pipe + 1);
		do
		{
			pipe = errors.find_first_of("|");
			printf("   >>%s\n", errors.substr(0, pipe).c_str());
			errors = errors.erase(0, pipe + 1);
		} while (pipe != string::npos);
		DisplaySingleStamp(&dummy);
		printf("\n\nOption    Field\n");
		printf("    0 >> Country      \n");
		printf("    1 >> Denomination \n");
		printf("    2 >> Image        \n");
		printf("    3 >> Year         \n");
		printf("    4 >> Value        \n");
		printf("    5 >> Rarity       \n");
		printf("    6 >> Dimnesions   \n");
		printf("    7 >> Type         \n");
		printf("    8 >> Adhesion     \n");
		printf("    9 >> Currency     \n");
		printf("    h >> Get Help     \n");

		switch (GetChar())
		{
		case '0':// Get Country
			dummy.country = GetString("    >> Please Enter Country of Stamp: ");
			break;
		case '1':	// Get Denomination
			dummy.denomination = GetDouble("    >> Please Enter Denomination (i.e. , 1 of Stamp: ");
			break;
		case '2':	// Get Image
			dummy.image = GetString("    >> Please Enter Image Type of Stamp: ");
			break;
		case '3':	// Get Year
			dummy.year = (int)GetDouble("    >> Please Enter Year of Stamp: ");
			break;
		case '4':	// Get Value
			dummy.value = GetDouble("    >> Please Enter Value of Stamp: ");
			break;
		case '5':	// Get Rarity
			dummy.rarity = GetString("    >> Please Enter Rarity of Stamp: ");
			break;
		case '6':	// Get Dimensions
			// -- Get Width
			dummy.dimensions[kWIDTH_INDEX] = GetDouble("    >> Please Enter Width of Stamp: ");
			// -- Get Length
			dummy.dimensions[kLENGTH_INDEX] = GetDouble("    >> Please Enter Length of Stamp: ");
			break;
			// Get Type
		case '7':dummy.type = GetString("    >> Please Enter Type of Stamp: ");
			break;
			// Get Adhesion Type
		case '8':dummy.adhesionType = GetString("    >> Please Enter Adhesion Type of the Stamp: ");
			break;
			// Get Currency
		case '9':dummy.currency = GetString("    >> Please Enter Type of Stamp: ");
			break;

		case 'h':
			GetDomainDetails();
			break;
		}
	}
	ClearScreen();
}

// Deletes a specific stamp somehow?
int StampCollector::DeleteStamp(int index)
{
	try
	{
		stampbook.DeleteStamp(index);
	}
	catch (const char *)
	{
		printf("A stamp with that ID could not be found\n");
	}


	return kSUCCESS;
}


// Deletes all stamps
int StampCollector::DeleteAllStamps(void)
{
	stampbook.DeleteAllStamps();
	return kSUCCESS;
}


// Search all stamps
int StampCollector::SearchStamps(void)
{
	const char kNewline = '\n';
	unsigned int resultsFound = 0;

	bool dateSkipped = false;
	bool filtered = false;
	bool displayed = false;

	const string kSkip = "x";
	const string kDisplay = "d";

	unsigned char keyEntered = 0;
	string userEntry = "";


	DrawMenus("Search");
	getline(cin, userEntry);

	for (;;)
	{
		// Clear the searchResults:
		stampbook.ClearStampsFound();
		searchResults.clear();

		// Filter by country?
		if (userEntry != kSkip && userEntry != kDisplay)
		{
			stampbook.SearchForStamp(userEntry);
			searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
			filtered = true;
		}
		else if (userEntry == kDisplay)
		{
			searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());

			if (resultsFound > 0)
			{
				cout << kNewline;
				DisplayAllStamps(searchResults);
			}
			else
			{
				cout << kNewline;
				cout << kNewline << "There were no stamps that matched all of your search criteria.\n";
				cout << kNewline;
			}

			break;
		}


		// Filter by date?
		cout << "Type a stamp's year to search by, 'x' to skip this search criterion, or 'd' to display results >>  ";
		userEntry = "";
		getline(cin, userEntry);

		if (userEntry != kSkip && userEntry != kDisplay)
		{
			if (filtered == true)
			{
				int dateEntry = 0;
				int intFound = 0;

				intFound = sscanf(userEntry.c_str(), "%d", &dateEntry);

				// If the user entered a non-numeric value,
				// re-prompt until the number is valid:
				while (intFound != kIntFound)
				{
					cout << "A number must be entered for the stamp's year. Please re-enter the year or 'x' to skip >> ";
					userEntry = "";
					getline(cin, userEntry);

					if (userEntry == kSkip)
					{
						dateSkipped = true;
						break;
					}
				}

				if (dateSkipped == false)
				{
					// Filter the searchResults:
					stampbook.FilterByDate(dateEntry);
					searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
					resultsFound = (unsigned int)stampbook.GetStampsFound().size();
				}
			}
			else
			{
				int dateEntry = 0;
				int intFound = 0;

				intFound = sscanf(userEntry.c_str(), "%d", &dateEntry);


				while (intFound != kIntFound)
				{
					cout << "A number must be entered for the stamp's year. Please re-enter the year or 'x' to skip >> ";
					userEntry = "";
					getline(cin, userEntry);

					if (userEntry == kSkip)
					{
						dateSkipped = true;
						break;
					}
				}

				// Searches for date (by using an int parameter)
				stampbook.SearchForStamp(dateEntry);
				searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
				filtered = true;
			}
		}
		else if (userEntry == kDisplay)
		{
			searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
			resultsFound = (unsigned int)stampbook.GetStampsFound().size();

			if (resultsFound > 0)
			{
				cout << kNewline;
				DisplayAllStamps(searchResults);
			}
			else
			{
				cout << kNewline;
				cout << "There were no stamps that matched all of your search criteria.\n";
				cout << kNewline;
			}
			
			break;
		}



		// Filter by image?
		cout << "Type a stamp's image to search by, or 'x' to skip this search criterion, or 'd' to display results >>  ";
		userEntry = "";
		getline(cin, userEntry);

		if (userEntry != kSkip && userEntry != kDisplay)
		{
			stampbook.FilterByImage(userEntry);
			searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
		}
		else if (userEntry == kDisplay)
		{
			cout << kNewline;
			DisplayAllStamps(searchResults);
			break;
		}


		// Filter by rarity?
		cout << "Type a stamp's rarity to search by, or 'd' to display results >>  ";
		userEntry = "";
		getline(cin, userEntry);

		if (userEntry != kSkip && userEntry != kDisplay)
		{
			stampbook.FilterByRarity(userEntry);
			searchResults = StampCollection::ConvToDummySearchResults(stampbook.GetStampsFound());
			resultsFound = (unsigned int)stampbook.GetStampsFound().size();
			DisplayAllStamps(searchResults);
		}

		resultsFound = (unsigned int)stampbook.GetStampsFound().size();

		if (resultsFound > 0)
		{
			cout << kNewline;
			DisplayAllStamps(searchResults);
		}
		else
		{
			cout << kNewline;
			cout << "There were no stamps that matched all of your search criteria.\n";
			cout << kNewline;
		}
		//--------------------------------------------- END OF FILTER BY RARITY -------------------------------------------

		break;
	}
	DrawMenus("Delete");
	// Get user input
	char input = GetChar();

	// Choose appropriate action based on input
	switch (input)
	{
	case kADD_ITEM:
		SearchStamps();
		break;

	case kDELETE_ITEM:
		DeleteStamp((int)GetDouble("\nPlease enter a stamp index to delete  >>  "));
		break;

	case kSEARCH:
		ClearScreen();
	default:
		break;
	}
	return kSUCCESS;
}






// Load all existing stamps from a file
int StampCollector::LoadExistingStamps(void)
{
	stampbook.ImportDatabase();
	return kSUCCESS;
}


// Fill the database with dummy stamps
int StampCollector::DummyStamps(void)
{
	const char kNewline = '\n';
	string userEntry = "";
	unsigned int howMany = 0;

	cout << kNewline << "How many random stamps would you like to add?  >> ";
	getline(cin, userEntry);
	howMany = stoi(userEntry, NULL, kDecimal);

	int stampsAdded = stampbook.AddRandomDummies(howMany);

	cout << "Added " << stampsAdded << " random stamps to the collection.\n" << kNewline;


	return kSUCCESS;
}


// Will draw all the menus, based off of selection passed in
void StampCollector::DrawMenus(std::string menuChoice)
{
	if (menuChoice.compare("Main") == kSTRINGS_EQUAL)
	{
		//ClearScreen();
		printf("What would you like to do? Please make a selection and press enter!\n");
		printf("    1 >> Add a new stamp\n");
		printf("    2 >> Delete a stamp\n");
		printf("    3 >> Search for a stamp or set of stamps\n");
		printf("    4 >> Delete all the stamps\n");
		printf("    5 >> Display all stamps\n");
		printf("    6 >> Generate a random set of stamps\n");
		printf("    7 >> Get Help\n");
		printf("    0 >> Exit the program\n\n");
	}

	else if (menuChoice.compare("Add Stamp") == kSTRINGS_EQUAL)
	{
		ClearScreen();
		printf("Please provide some basic information about the stamp\n");
	}

	else if (menuChoice.compare("Add Details") == kSTRINGS_EQUAL)
	{
		//ClearScreen();
		printf("Enter any details you have about the stamp\n");
		printf("Press enter on a blank line to skip a field\n");
	}

	// Print this menu if user wants to request domain details
	else if (menuChoice.compare("Request Rules") == kSTRINGS_EQUAL)
	{
		ClearScreen();
		printf("Some fields have a specific range of valid entries. Those Fields are Listed Below\n");
		printf("For which field would you like to request details?\n");
		printf("    1 >> Image\n");
		printf("    2 >> Country\n");
		printf("    3 >> Date\n");
		printf("    4 >> Dimensions\n");
		printf("    5 >> Rarity\n");
		printf("    6 >> Adhesion Type\n\n");
	}
	else if (menuChoice.compare("Search") == kSTRINGS_EQUAL)
	{
		ClearScreen();
		printf("Multiple search terms may be entered to search for a stamp.\n");
		printf("Type a country name to search by, 'x' to skip this search criterion, or 'd' to display results >>  ");
	}
	else if (menuChoice.compare("Delete") == kSTRINGS_EQUAL)
	{
		// ClearScreen();
		printf("What would you like to do now?\n");
		printf("    1 >> Search again\n");
		printf("    2 >> Delete a stamp\n");
		printf("    3 >> Return to main menu\n");
	}
	else if (menuChoice.compare("Edit") == kSTRINGS_EQUAL)
	{
		ClearScreen();
		printf("There were a couple of fields that were invalid in your stamp entry\n");
		printf("Please select from the following menu options to fix this up!\n\n");
	}
}



// Get char from user with optional prompt
char StampCollector::GetChar(std::string prompt)
{
	if (!prompt.empty())
	{
		printf("%s", prompt.c_str());
	}
	unsigned char retCode = ' ';
	std::string input;
	getline(std::cin, input);
	if (strlen(input.c_str()) != kONE_INPUT)
	{
		retCode = kINVALID_CHARACTER;
	}
	else
	{
		retCode = input.at(kFIRST_CHARACTER);
	}
	return retCode;
}


// Get string from user with optional prompt
std::string StampCollector::GetString(std::string prompt)
{
	if (!prompt.empty())
	{
		printf("%s", prompt.c_str());
	}
	std::string input;
	getline(std::cin, input);
	return input;
}


// Get double from user with optional prompt
double StampCollector::GetDouble(std::string prompt)
{
	if (!prompt.empty())
	{
		printf("%s", prompt.c_str());
	}
	string input;
	double returnDouble = kEMPTY;
	std::size_t found;
	do
	{
		getline(std::cin, input);
		if (input.empty())
		{
			return returnDouble = kSKIP_FIELD;
			break;
		}
		found = input.find_first_not_of("01234567890.");
		if (found != std::string::npos)
		{
			printf("         ERROR: Please enter a proper number: ");
		}

	} while (found != std::string::npos);

	returnDouble = atof(input.c_str());

	return returnDouble;
}

// Taken with a great deal of gratitude from http://www.cplusplus.com/articles/4z18T05o/
void StampCollector::ClearScreen(void)
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

