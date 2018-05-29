/*
*******************************************************************************
*FILE			Stamp.h
*PROJECT		DS/OOP Project								  *
*PROGRAMMER		Wesley Martin and Ricardo Mohammed
*FIRST VERSION												  *
*DESCRIPTION													*
*																			  *
*******************************************************************************
*/ 


#ifndef _STAMP_H
#define _STAMP_H
#include "StampProject.h"


// Constants
#define kTrue 0
#define kFalse -1
#define kMaxDamage 10
#define kZeroID 0
#define kEarliestStamp 1840
#define kCurrentYear 2017
#define kMinDollarVal 0.1
#define kMinWidth 10
#define kMinLength 10
#define kMaxWidth 1360
#define kMaxLength 1770
#define kWidthIndex 1
#define kLengthIndex 2
#define kNonZeroStampCount 1
#define kZeroIndex 0
#define kCountryOptions 96
#define kImageOptions 4
#define kRarityOptions 4
#define kTypeOptions 27
#define kCurrencyOptions 21
#define kAdhesionTypes 6


const string kEmptyString = "";

// Constants for the data members
const std::string imageOptions[] = { "Portrait", "Emblem", "Numeric", "Pictorial", "end" };
const std::string rarityOptions[] = { "Very Rare", "Rare", "Uncommon", "Common", "end" };
const std::string adhesionTypes[] = { "Dextrin", "Acacia gum", "Glue", "Polyvinyl alcohol", "Self-adhesive", "Other", "end" };
const std::string typeOptions[] = { "Airmail", "Booklet", "Carrier's", "Certified mail", "Coil", "Commemorative",
								   "Computer vended", "Definitive", "Express", "Local post", "Make up", "Military",
								   "Newspaper", "Official mail", "Non-denominated", "Overprint", "Perforated",
								   "Personalised", "Pneumatic post", "Postage currency", "Postage due", "Charity",
								   "Souvenir sheet", "Specimen", "Test stamp", "Variable value", "War tax", "end" };
const std::string currencyOptions[] = { "CAD", "USD", "GBP", "RUB", "CNH", "AED", "AFN", "ARS", "BSD", "BHD", "AUD",
										"KRW", "INR", "BRL", "EUR", "JPY", "SEK", "NZD", "end" };
const std::string countryOptions[] = { "Canada", "United States", "England", "Russia", "China", "UAE",
									   "Afghanistan", "Argentina", "Bahamas", "Bahrain", "Bermuda", "Brazil", "Bulgaria",
									   "Burma", "Chile", "Colombia", "Congo", "Cuba", "Cyprus", "Czech Republic",
									   "Costa Rica", "Denmark", "Dominican Republic", "Dubai", "Ecuador", "Egypt", 
									   "El Salvador", "Estonia", "Fiji", "Finland",  "France", "Georgia", "Germany",
								       "Ghana", "Greece", "Greenland", "Guatemala", "Haiti", "Hong Kong", "Hungary",
									   "Iceland", "India", "Indonesia", "Iran", "Iraq", "Italy", "Jamaica", "Japan",
									   "Kazakhstan", "Israel", "Korea", "Latvia", "Luxembourg", "Macedonia", "Malawi",
									   "Malaysia", "Malta", "Mexico", "Moldova", "Mongolia", "Nepal", "Netherlands",
									   "New Zealand", "Nicaragua", "Nigeria", "Norway", "Pakistan", "Palestine", "Panama",
									   "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar", "Romania", "Samoa",
									   "Saudi Arabia", "Serbia", "Singapore", "Slovakia", "Slovenia", "South Africa",
							           "Spain", "Sri Lanka", "Sweden", "Switzerland", "Taiwan", "Thailand", "Turkey", 
									   "Uganda", "Ukraine", "Uruguay", "Venezuela", "Yugoslavia", "Zululand", "end" };
									    

// Return codes
#define kValid 0
#define kInvalid -1
static double _dimensions[kDimensions] = { 0,0 };

///
/// \class Stamp
/// 
/// NAME		: Stamp <br>
/// PURPOSE		: The Stamp class models the attributes of a stamp in a
///				  stamp collection. Attributes of a stamp include a
///				  description of its image, country of origin, the year
///				  it was first issued, its denomination, the stamp's dimensions
///				  in mm, its monetary value in CAD, how rare the stamp is, and  
///				  the type of adhesion the stamp uses.
///

class Stamp
{
private:
	static int stampCount;						/// Keeps track of the total number of stamps in the collection.
	std::string image;							/// The type of image on the stamp.
	std::string country;						/// The stamp's country of origin.
	std::string type;							/// The type of stamp.
	int date;									/// The year the stamp was first used.
	double denomination;						/// The monetary denomination on the stamp.
	std::string currency;						/// The currency the stamp is in.
	double dimensions[kDimensions];				/// The dimensions of the stamp in millimeters.
	std::string rarity;							/// How rare the stamp is as a word or as the number of stamps left.
	double value;								/// The monetary value of the stamp.
	std::string adhesionType;					/// The type of adhesion the stamp uses.
	int stampID;								/// The unique ID of the stamp in the collection.

	// ================ Private Methods ================
	static int validateImage(std::string newImage);									 /// Validates an image for a Stamp.
	static int validateCountry(std::string newCountry);								 /// Validates a country for a Stamp.
	static int validateType(std::string newType);								     /// Validates the type of Stamp.
	static int validateDate(int newDate);									         /// Validates a date for a Stamp.
	static int validateDenomination(double newDenomination);					     /// Validates a denomination for a Stamp.
	static int validateCurrency(string newCurrency);						         /// Validates the currency for a Stamp.
	static int validateDimensions(double newDimensions[kDimensions]);			     /// Validates a dimension pair for a Stamp.
	static int validateRarity(std::string newRarity);							     /// Validates a rarity for a Stamp.
	static int validateValue(double newValue);									     /// Validates a value for a Stamp.
	static int validateAdhesionType(std::string newAdhesionType);				     /// Validates an adhesion type for a Stamp.
	static int validateStampID(int newStampID);										 /// Validates a stamp ID for a Stamp.
	static bool validateInput(std::string input, const std::string validValues[]);   /// Validates a user-entered string.


public:
	// ================ Constructors ================
	Stamp(std::string image, 
		  std::string country, 
		       double denomination,
		          int date = 0,
		       double value = 0,
		  std::string rarity = "",
		       double dimensions[kDimensions] = _dimensions,
		  std::string type = "",
		  std::string adhesionType = "",
		  std::string currency = "");	/// Constructor for Stamp object
	Stamp();															/// Constructor for Stamp object

	// ================ Destructors	================
	~Stamp();								/// Destructor for Stamp object


	// ================ Accessors ================
	const std::string GetImage(void);			/// Accessor for the image member
	const std::string GetType(void);			/// Accessor for the type of stamp
	const std::string GetCountry(void);			/// Accessor for the country member
	const int GetDate(void);					/// Accessor for the date member
	const double GetDenomination(void);			/// Accessor for the denomination member
	const std::string GetCurrency(void);		/// Accessor for the currency member
	const std::string GetRarity(void);			/// Accessor for the rarity member
	const double GetValue(void);				/// Accessor for the value member
	const double* GetDimensions(void);			/// Accessor for the dimensions member
	const std::string GetAdhesionType(void);	/// Accessor for the adhesion type member
	const vector<string> getDamage(void);		/// Accessor for a full damage report
	const std::string getDamage(int element);	/// Accessor for a specific damage descriptor
	const int GetID(void);						/// Accessor for the ID member


	// ================ Mutators ================
	int SetImage(std::string newImage);						/// Mutator for the image member
	int SetCountry(std::string newCountry);					/// Mutator for the country member
	int SetDate(int newDate);								/// Mutator for the date member
	int SetType(std::string newType);						/// Mutator for the type of stamp
	int SetDenomination(double newDenomination);			/// Mutator for the denomination member
	int SetCurrency(std::string newCurrency);				/// Mutator for the currency member
	int SetRarity(std::string newRarity);					/// Mutator for the rarity member (string)
	int SetRarity(int howManyLeft);							/// Mutator for the rarity member (int)
	int SetValue(double newValue);							/// Mutator for the value member
	int SetDimensions(double newDimensions[kDimensions]);	/// Mutator for the dimensions member
	int SetAdhesionType(std::string newAdhesionType);		/// Mutator for the adhesion type member
	int SetStampID(int newId);								/// Mutator for the ID member



	// Other Methods
	static std::string PreValidation(dummyStamp input);
	static std::string DomainDetails(void);
	static std::string DumpArray(const std::string whichArray[], std::string& output, int newLine = 10);

	friend std::ifstream& operator>>(std::ifstream& output, Stamp& op2);
	friend std::ofstream& operator<<(std::ofstream& output, const Stamp& op2);

};


;



#endif