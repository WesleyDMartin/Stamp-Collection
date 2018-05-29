/*
*******************************************************************************
*FILE			Stamp.cpp										  *
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/

#include "stampProject.h"
#include "Stamp.h"
#include "StampCollection.h"


// Initialize the total stamp count:
int Stamp::stampCount = 0;


/**
* \brief Constructor for a Stamp object.
*
* <b>Description</b><br>
* This constructor instantiates a Stamp. 
*
* \param	  country		<b>string</b> - The country of origin of the stamp.
*			  image			<b>string</b> - The type of image on the stamp.
*			  denomination	<b>double</b> - The denomination on the stamp.
*/
Stamp::Stamp(std::string newImage, std::string newCountry, double newDenomination, int newDate, double newValue, std::string newRarity, 
	         double newDimensions[kDimensions], std::string newType, std::string newAdhesionType, std::string newCurrency)
{
	if (validateImage(newImage) == kSUCCESS)							     /// Validates an image for a Stamp.
	{
		image = newImage;
	}
	if (validateCountry(newCountry) == kSUCCESS)						     /// Validates a country for a Stamp.
	{
		country = newCountry;
	}
	if (validateType(newType) == kSUCCESS)								     /// Validates the type of Stamp.
	{
		type = newType;
	}
	if (validateDate(newDate) == kSUCCESS)									 /// Validates a date for a Stamp.
	{
		date = newDate;
	}
	if (validateDenomination(newDenomination) == kSUCCESS)					 /// Validates a denomination for a Stamp.
	{
		denomination = newDenomination;
	}
	if (validateCurrency(newCurrency) == kSUCCESS)					     /// Validates the currency for a Stamp.
	{
		currency = newCurrency;
	}
	if (validateDimensions(newDimensions) == kSUCCESS)			             /// Validates a dimension pair for a Stamp.
	{
		memcpy(dimensions, newDimensions, sizeof(double) * kDimensions);
	}
	if (validateRarity(newRarity) == kSUCCESS)							     /// Validates a rarity for a Stamp.
	{
		rarity = newRarity;
	}
	if (validateValue(newValue) == kSUCCESS)								 /// Validates a value for a Stamp.
	{
		value = newValue;
	}
	if (validateAdhesionType(newAdhesionType) == kSUCCESS)				     /// Validates an adhesion type for a Stamp.
	{
		adhesionType = newAdhesionType;
	}
	if (validateStampID(stampCount) == kSUCCESS)								 /// Validates a stamp ID for a Stamp.
	{
		stampID = stampCount;
		stampCount++;
	}
}


/**
* \brief Default Constructor for a Stamp object.
*
* <b>Description</b><br>
* This constructor instantiates a Stamp.
*
* \param	  country		<b>string</b> - The country of origin of the stamp.
*			  image			<b>string</b> - The type of image on the stamp.
*			  denomination	<b>double</b> - The denomination on the stamp.
*/
Stamp::Stamp()
{
	//stampID = stampCount;		// Set the stamp's unique ID and increment the total stamp count.
	//stampCount++;
}



/**
* \brief Destructor for the Stamp class.
*
* <b>Description</b><br>
* This is a destructor for a Stamp object.
*
*/
Stamp::~Stamp()
{

}



/**
* \brief This is an accessor for the image data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the image member.
*
*
* \param			      <b>void</b>			- No parameters.
* \return		image	  <b>const string</b>	- The value of image.
*
*/
const string Stamp::GetImage(void)
{
	return (const string)image;
}





/**
* \brief This is an accessor for the country data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the country member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const string</b> - The value of country.
*
*/
const string Stamp::GetCountry(void)
{
	return (const string)country;
}



/**
* \brief This is an accessor for the date data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the date member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const int</b> - The value of date.
*
*/
const int Stamp::GetDate(void)
{
	return (const int)date;
}



/**
* \brief This is an accessor for the denomination data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the denomination member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const double</b>	- The value of date.
*
*/
const double Stamp::GetDenomination(void)
{
	return (const double)denomination;
}





/**
* \brief This is an accessor for the currency data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the currency member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return	    <b>const string</b>		- The value of currency.
*
*/
const string Stamp::GetCurrency(void)
{
	return (const string)currency;
}




/**
* \brief This is an accessor for the rarity data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the rarity member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const string</b>	- The value of rarity.
*
*/
const string Stamp::GetRarity(void)
{
	return (const string)rarity;
}




/**
* \brief This is an accessor for the value data member.
*
* <b>Description</b><br>
* This accessor retrieves the value data member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const string</b>	- The value of the value data member.
*
*/
const double Stamp::GetValue(void)
{
	return (const double)value;
}




/**
* \brief This is an accessor for the dimensions data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the dimensions member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const int*</b>	- The value of dimensions.
*
*/
const double* Stamp::GetDimensions(void)
{
	return (const double*)dimensions;
} 




/**
* \brief This is an accessor for the adhesionType data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the adhesionType member for
* a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const string</b>	- The value of adhesionType.
*
*/
const string Stamp::GetAdhesionType(void)
{
	return (const string)adhesionType;
}





/**
* \brief This is an accessor for the type data member.
*
* <b>Description</b><br>
* This accessor retrieves the type member for a stamp object.
*
*
* \param	<b>void</b>			- No parameters.
*
* \return   <b>const string</b>	- The value of type.
*
*/
const string Stamp::GetType(void)
{
	return (const string)type;
}





/**
* \brief This is an accessor for the stampID data member.
*
* <b>Description</b><br>
* This accessor retrieves the value of the stampID member for
* a stamp object.
*
*
* \param	<b>void</b>			- No return value.
*
* \return   <b>const string</b>	- The value of stampID.
*
*/
const int Stamp::GetID(void)
{
	return (const int)stampID;
}




/**
* \brief This is mutator for the image data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the image data member only
* if the new image value is valid.
*
*
* \param	newImage	<b>string</b> - The new image to attempt to set the member to.
*
* \return	validInput	<b>int</b>	 - A code indicating if the image was valid/set.
*
*/
int Stamp::SetImage(string newImage)
{
	int validInput = kValid;

	validInput = validateImage(newImage);

	if (validInput == kValid)
	{
		// The image was valid.
		image = newImage;
	}

	return validInput;
}




/**
* \brief This is mutator for the country data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the country data member only
* if the new country value is valid.
*
*
* \param	newCountry	<b>string</b> - The new country to attempt to set the member to.
*
* \return	validInput	<b>int</b>	 - A code indicating if the country was valid/set.
*
*/
int Stamp::SetCountry(string newCountry)
{
	int validInput = kValid;

	validInput = validateCountry(newCountry);

	if (validInput == kValid)
	{
		// The country was valid.
		country = newCountry;
	}

	return validInput;
}




/**
* \brief This is mutator for the date data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the date data member only
* if the new date value is valid.
*
*
* \param	newDate		<b>int</b>	 - The new date to attempt to set the member to.
*
* \return	validInput	<b>int</b>	 - A code indicating if the date was valid/set.
*
*/
int Stamp::SetDate(int newDate)
{
	int validInput = kValid;

	validInput = validateDate(newDate);

	if (validInput == kValid)
	{
		// The date was valid.
		date = newDate;
	}

	return validInput;
}




/**
* \brief This is mutator for the type data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the type data member if it is valid.
*
*
* \param	newType     	  <b>string</b> - The new type to attempt to set the member to.
*
* \return	validInput		  <b>int</b>   - A code indicating if the type was valid/set.
*
*/
int Stamp::SetType(string newType)
{
	int validInput = kValid;

	validInput = validateType(newType);

	if (validInput == kValid)
	{
		// The type was valid.
		type = newType;
	}

	return validInput;
}






/**
* \brief This is mutator for the denomination data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the denomination data member only
* if the new denomination value is valid.
*
*
* \param	newDenomination	  <b>double</b> - The new denomination to attempt to set the member to.
*
* \return	validInput		  <b>int</b>   - A code indicating if the denomination was valid/set.
*
*/
int Stamp::SetDenomination(double newDenomination)
{
	int validInput = kValid;

	validInput = validateDenomination(newDenomination);

	if (validInput == kValid)
	{
		// The denomination was valid.
		denomination = newDenomination;
	}

	return validInput;
}




/**
* \brief This is mutator for the currency data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the currency data member only
* if the new currency value is valid.
*
*
* \param	newCurrency		  <b>string</b>	- The new currency to attempt to set the member to.
*
* \return	validInput		  <b>int</b>    - A code indicating if the currency was valid/set.
*
*/
int Stamp::SetCurrency(string newCurrency)
{
	int validInput = kValid;

	validInput = validateCurrency(newCurrency);

	if (validInput == kValid)
	{
		// The currency was valid.
		currency = newCurrency;
	}

	return validInput;
}






/**
* \brief This is mutator for the rarity data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the rarity data member only
* if the new rarity value is valid.
*
*
* \param	newRarity	<b>string</b> - The new rarity to attempt to set the member to.
*
* \return	validInput	<b>int</b>	 - A code indicating if the rarity was valid/set.
*
*/
int Stamp::SetRarity(string newRarity)
{
	int validInput = kValid;

	validInput = validateRarity(newRarity);

	if (validInput == kValid)
	{
		// The rarity was valid.
		rarity = newRarity;
	}

	return validInput;
}




/**
* \brief This is mutator for the rarity data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the rarity data member only
* if the new rarity value is valid.
*
*
* \param	howManyLeft 	<b>int</b>	 -   The new rarity to attempt to set the member to.
*
* \return	validInput  	<b>int</b>	 -   A code indicating if the rarity was valid/set.
*
*/
int Stamp::SetRarity(int howManyLeft)
{
	int validInput = kInvalid;

	if (howManyLeft >= kNonZeroStampCount)
	{
		// There are a non-zero number of stamps left identical to this one.
		validInput = kValid;
	}

	return validInput;
}





/**
* \brief This is mutator for the value data member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the value data member only
* if the new value value is valid.
*
*
* \param	newValue 	<b>double</b>	 -   The new value to attempt to set the member to.
*
* \return	validInput  <b>int</b>		 -   A code indicating if the value was valid/set.
*
*/
int Stamp::SetValue(double newValue)
{
	int validInput = kValid;

	validInput = validateValue(newValue);

	if (validInput == kValid)
	{
		// The value was valid.
		value = newValue;
	}

	return validInput;
}




/**
* \brief This is mutator for the dimensions member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the dimensions data member only
* if the new dimensions value is valid.
*
*
* \param	newDimensions[]  <b>double[]</b>  -  The new dimensions to attempt to set the member to.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the dimensions was valid/set.
*
*/
int Stamp::SetDimensions(double newDimensions[kDimensions])
{
	int validInput = kValid;

	validInput = validateDimensions(newDimensions);

	if (validInput == kValid)
	{
		// The dimensions were valid.
		dimensions[kWidthIndex] = newDimensions[kWidthIndex];
		dimensions[kLengthIndex] = newDimensions[kLengthIndex];
	}

	return validInput;
}




/**
* \brief This is mutator for the adhesion type member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the adhesion type data member only
* if the new adhesion type value is valid.
*
*
* \param	newAdhesionType  <b>string</b>  -  The new adhesion type to attempt to set the member to.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the adhesion type was valid/set.
*
*/
int Stamp::SetAdhesionType(string newAdhesionType)
{
	int validInput = kValid;

	validInput = validateAdhesionType(newAdhesionType);

	if (validInput == kValid)
	{
		// The adhesion type was valid.
		adhesionType = newAdhesionType;
	}

	return validInput;
}




/**
* \brief This is mutator for the stamp ID member of a Stamp.
*
* <b>Description</b><br>
* This mutator will validate and set the stamp ID data member if it is valid.
*
*
* \param	newId		     <b>int</b>	   -  The new ID to attempt to set the member to.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the stamp ID was valid/set.
*
*/
int Stamp::SetStampID(int newId)
{
	int validInput = kValid;

	validInput = validateStampID(newId);

	if (validInput == kValid)
	{
		// The stamp ID was valid.
		stampID = newId;
	}

	return validInput;
}





/**
* \brief This is a validator for the image member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given image string for validity.
*
*
* \param	newImage         <b>string</b>  -  The new image to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the image was valid.
*
*/
int Stamp::validateImage(string newImage)
{
	int validInput = kInvalid;

	if (validateInput(newImage, imageOptions) && newImage != "end")
	{
		// The entered image is valid.
		validInput = kValid;
	}

	return validInput;
}




/**
* \brief This is a validator for the country member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given country string for validity.
*
*
* \param	newCountry       <b>string</b>  -  The entered country to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the country was valid.
*
*/
int Stamp::validateCountry(string newCountry)
{
	int validInput = kInvalid;

	if (validateInput(newCountry, countryOptions) && newCountry != "end")
	{
		// The entered image is valid.
		validInput = kValid;
	}
	
	return validInput;
}





/**
* \brief This is a validator for the date member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given date string for validity.
*
*
* \param	newDate		     <b>int</b>  -  The new date to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the date was valid.
*
*/
int Stamp::validateDate(int newDate)
{
	int validInput = kValid;

	if (newDate < kEarliestStamp)
	{
		// The earliest stamp was used in 1840.
		validInput = kInvalid;
	}
	if (newDate == kSKIP_FIELD)
	{
		validInput = kValid;
	}
	return validInput;
}





/**
* \brief This is a validator for the type member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given type for validity.
*
*
* \param	newType          <b>string</b>  -  The new type to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the type was valid.
*
*/

int Stamp::validateType(string newType)
{
	int validInput = kInvalid;

	if (validateInput(newType, typeOptions) && newType != "end")
	{
		// The entered image is valid.
		validInput = kValid;
	}

	if (newType.compare("") == kSTRINGS_EQUAL)
	{
		validInput = kValid;
	}
	return validInput;
}





/**
* \brief This is a validator for the denomination member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given denomination for validity.
*
*
* \param	newDenomination  <b>string</b>  -  The new denomination to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the denomination was valid.
*
*/

int Stamp::validateDenomination(double newDenomination)
{
	int validInput = kValid;

	if (newDenomination < (double)kMinDollarVal)
	{
		// The denomination cannot be less than 0.1
		validInput = kInvalid;
	}

	return validInput;
}





/**
* \brief This is a validator for the currency member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given currency for validity.
*
*
* \param	newCurrency      <b>string</b>  -  The new currency to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the currency was valid.
*
*/

int Stamp::validateCurrency(string newCurrency)
{
	int validInput = kInvalid;

	if (validateInput(newCurrency, currencyOptions) && newCurrency != "end")
	{
		// The entered currency is valid.
		validInput = kValid;
	}
	if (newCurrency.compare("") == kSTRINGS_EQUAL)
	{
		validInput = kValid;
	}
	return validInput;
}




/**
* \brief This is a validator for the dimensions member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given array of dimensions for validity.
*
*
* \param	newDimensions[]  <b>string</b>  -  The new dimensions to attempt to check for validity.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the dimensions were valid.
*
*/
int Stamp::validateDimensions(double newDimensions[kDimensions])
{
	int validInput = kInvalid;

	if ((newDimensions[kWIDTH_INDEX] >= (double)kMinWidth)
		&& (newDimensions[kWIDTH_INDEX] <= (double)kMaxWidth)
		&& (newDimensions[kLENGTH_INDEX] >= (double)kMinLength)
		&& (newDimensions[kLENGTH_INDEX] <= (double)kMaxLength))
	{
		// The input fell within range of dimensions of 
		// the smallest and largest stamps ever.
		validInput = kValid;
	}

	if (newDimensions[kWIDTH_INDEX] == kSKIP_FIELD && newDimensions[kLENGTH_INDEX] == kSKIP_FIELD)
	{
		validInput = kValid;
	}


	return validInput;
}





/**
* \brief This is a validator for the rarity member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given rarity string for validity.
*
*
* \param	newAdhesionType  <b>string</b>  -  The new rarity to attempt to set the member to.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the rarity was validity.
*
*/
int Stamp::validateRarity(string newRarity)
{
	int validInput = kInvalid;

	if (validateInput(newRarity, rarityOptions) && newRarity != "end")
	{
		// The entered rarity is valid.
		validInput = kValid;
	}
	if (newRarity.compare("") == kSTRINGS_EQUAL)
	{
		validInput = kValid;
	}
	return validInput;
}





/**
* \brief This is a validator for the value member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given value for validity.
*
*
* \param	newAdhesionType  <b>string</b>  -  The new value to attempt to set the member to.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the value was valid.
*
*/
int Stamp::validateValue(double newValue)
{
	int validInput = kValid;

	if (newValue < (double)kMinDollarVal)
	{
		// The value cannot be less than 0.1
		validInput = kInvalid;
	}
	if (newValue == kSKIP_FIELD)
	{
		validInput = kValid;
	}
	return validInput;
}





/**
* \brief This is a validator for the adhesion type member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given adhesion type for validity.
*
*
* \param	newAdhesionType  <b>string</b>  -  The new adhesion type to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the adhesion type was valid.
*
*/
int Stamp::validateAdhesionType(string newAdhesionType)
{
	int validInput = kInvalid;

	if (validateInput(newAdhesionType, adhesionTypes) && newAdhesionType != "end")
	{
		// The entered adhesion type is valid.
		validInput = kValid;
	}
	if (newAdhesionType.compare("") == kSTRINGS_EQUAL)
	{
		validInput = kValid;
	}
	return validInput;
}




/**
* \brief This is a validator for the stamp ID member of a Stamp.
*
* <b>Description</b><br>
* This method checks the given stamp ID for validity.
*
*
* \param	newStampID	     <b>string</b>  -  The new stamp ID to validate.
*
* \return	validInput		 <b>int</b>	   -  A code indicating if the stamp ID was valid.
*
*/
int Stamp::validateStampID(int newStampID)
{
	int validInput = kInvalid;

	if (newStampID >= kZeroID)
	{
		// The stamp ID was non-zero.
		validInput = kValid;
	}

	return validInput;
}




/**
* \brief This is a validator for a user inputted string.
*
* <b>Description</b><br>
* This function checks the user's string against the strings in the array of valid values
* for that data member.
*
* \param	input			 <b>string</b>  -  The user-entered string.
*
* \return	validInput		 <b>const string[]</b>  -  The string of valid values for the data member.
*
*/
bool Stamp::validateInput(string input, const string validValues[])
{
	bool stringFound = false;
	int index = 0;				// The index in the validValues array.


	while (validValues[index] != "end")
	{
		if (stricmp(input.c_str(), validValues[index].c_str()) == kSTRINGS_EQUAL)
		{
			// The string was found:
			stringFound = true;
			break;
		}

		// The string wasn't found, so keep searching:
		index++;
	}

	return stringFound;
}



std::ifstream& operator>>(std::ifstream& inputStream, Stamp& op2)
{

	bool retCode = false;
	int counter = kEMPTY;
	std::string input;
	std::string temp;
	std::getline(inputStream, input);
	size_t pipe;
	pipe = input.find_first_of("|");
	do
	{
		pipe = input.find_first_of("|");
		temp = input.substr(0, pipe).c_str();
		switch (counter)
		{
		case 0:
			op2.stampID = atoi(temp.c_str());
			if (op2.stampID >= Stamp::stampCount)
			{
				Stamp::stampCount = op2.stampID;
			}
			break;

		case 1:
			op2.image = temp;
			break;

		case 2:
			op2.country = temp;
			break;

		case 3:
			op2.date = atoi(temp.c_str());
			break;

		case 4:
			op2.type = temp;
			break;

		case 5:
			op2.denomination = atof(temp.c_str());
			break;

		case 6:
			op2.currency = temp;
			break;

		case 7:
			op2.dimensions[kWIDTH_INDEX] = atof(temp.c_str());
			break;

		case 8:
			op2.dimensions[kLENGTH_INDEX] = atof(temp.c_str());
			break;

		case 9: 
			op2.rarity = temp;
			break;

		case 10:
			op2.value = atof(temp.c_str());
			break;

		case 11:
			op2.adhesionType = temp;
			break;

		default:
			break;
			//throw "ERROR: File input error";
		}
		counter++;
		input = input.erase(0, pipe + 1);
	} while (pipe != string::npos);
	return inputStream;
}


std::ofstream& operator << (std::ofstream& outputStream, const Stamp& op2)
{
	bool retCode = false;
			outputStream << op2.stampID << '|';

			outputStream << op2.image << '|';

			outputStream << op2.country << '|';

			outputStream << op2.date << '|';

			outputStream << op2.type << '|';

			outputStream << op2.denomination << '|';

			outputStream << op2.currency << '|';

			outputStream << op2.dimensions[kWIDTH_INDEX] << '|';

			outputStream << op2.dimensions[kLENGTH_INDEX] << '|';

			outputStream << op2.rarity << '|';

			outputStream << op2.value << '|';

			outputStream << op2.adhesionType << '|' << std::endl;

	return outputStream;
}





std::string Stamp::PreValidation(dummyStamp input)
{
	std::string errorReturn;
	if (validateCountry(input.country) != kValid)
	{
		errorReturn.append("|Country was invalid");
	}
	if (validateDenomination(input.denomination) != kValid)
	{
		errorReturn.append("|Denomination was invalid");
	}
	
	if (validateImage(input.image) != kValid)
	{
		errorReturn.append("|Image was invalid");
	}
	
	if (validateDate(input.year) != kValid)
	{
		errorReturn.append("|Year was invalid");
	}
	
	if (validateValue(input.value) != kValid)
	{
		errorReturn.append("|Value was invalid");
	}
	
	if (validateRarity(input.rarity) != kValid)
	{
		errorReturn.append("|Rarity was invalid");
	}
	
	if (validateDimensions(input.dimensions) != kValid)
	{
		errorReturn.append("|Dimensions were invalid");
	}
	
	if (validateType(input.type) != kValid)
	{
		errorReturn.append("|Type was invalid");
	}
	
	if (validateAdhesionType(input.adhesionType) != kValid)
	{
		errorReturn.append("|Adhesion Type was invalid");
	}
	
	if (validateCurrency(input.currency) != kValid)
	{
		errorReturn.append("|Currency was invalid");
	}
	return errorReturn;
}


std::string Stamp::DomainDetails(void)
{
	std::string returnString;

	returnString.append("------------------- VALID COUNTRIES --------------------------------------\n\n\n");
	DumpArray(countryOptions, returnString, 7);
	returnString.append("\n");

	returnString.append("\v------------------- VALID IMAGE TYPE--------------------------------------\n\n\n");
	DumpArray(imageOptions, returnString);
	returnString.append("\n");

	returnString.append("------------------- VALID RARITY OPTIONS----------------------------------\n\n\n");
	DumpArray(rarityOptions, returnString);
	returnString.append("\n");

	returnString.append("------------------- VALID STAMP TYPES-------------------------------------\n\n\n");
	DumpArray(typeOptions, returnString, 5);
	returnString.append("\n");

	returnString.append("\v------------------- VALID STAMP CURRENCIES--------------------------------\n\n\n");
	DumpArray(currencyOptions, returnString, 14);
	returnString.append("\n");

	returnString.append("------------------- VALID ADHESION TYPES ---------------------------------\n\n\n");
	DumpArray(adhesionTypes, returnString);
	returnString.append("\n");

	returnString.append("------------------- OTHER RULES ------------------------------------------\n\n");
	returnString.append("Stamp denomination must be greater than .01\n");
	returnString.append("Stamp year must be later than 1840\n");
	returnString.append("Stamp value must be greater than 1\n");
	returnString.append("Stamp width and height must both be greater than 10 mm\n");

	returnString.append("\n\n");
	return returnString;
}

std::string Stamp::DumpArray(const std::string whichArray[], std::string& output, int newLine)
{
	int i = kEMPTY;
	while (whichArray[i].compare("end") != kSTRINGS_EQUAL)
	{
		output.append(whichArray[i]);

		if (whichArray[i + 1].compare("end") != kSTRINGS_EQUAL)
		{
			output.append(", ");
		}
		else
		{
			break;
		}
		i++;
		if (i % newLine == 0)
		{
			output.append("\n");
		}


	}
	output.append("\n\n");
	return output;
}







