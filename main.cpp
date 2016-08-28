//
// Chicago Crime Analysis: top-5 crimes
//
// <<Daniel Pulley>>
// U. of Illinois, Chicago
// CS341, Fall 2016
// HW #01
//

// Preprocessor Directives
#include <iostream>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// namespaces
using std::string;
using std::ifstream;
using std::istream_iterator;
using std::vector;
using std::stringstream;
using std::getline;
using std::stoi;
using std::sort;
using std::cout;
using std::endl;
using std::setw;
using std::count;


/** classes **/

// CrimeCode Class
class CrimeCode
{
    public:
        string IUCR;        // Illinois Uniform Crime Reporting
        string Pdescript;   // Primary Description of code
        string Sdescript;   // Secondary Description of code
        int counter = 0;        // this counts the number of crimes associated with this crime code        

    CrimeCode(string iucr, string primary, string secondary)
        : IUCR(iucr), Pdescript(primary), Sdescript(secondary)
    { } 
};


// Crime Class
class Crime
{
    public:
        string DateTime;
        string IUCR;
        string  Arrest;    // TRUE OR FALSE
        string DomesticViolence;   // TRUE OR FALSE
        int Beat;
        int District;
        int Ward;
        int Community;
        int Year;
    
    Crime(string datetime, string iucr, string arrest, string domestic, int beat, int district, int ward, int community, int year)
        : DateTime(datetime), IUCR(iucr), Arrest(arrest), DomesticViolence(domestic), Beat(beat), District(district), Ward(ward),
            Community(community), Year(year)
    { }

};


/** End of Classes **/

/*
 * date_range() function
 *
 * Function outputs the range of the dates which marks from one period to another
 */
void date_range(vector<Crime>& myCrime)
{
			cout << "Date range: " << myCrime.front().DateTime << " - " << myCrime.back().DateTime << endl << endl;
}
// End of date_range function

/*
 * output_crimes() function
 *
 * Function outputs the number of crimes
 */
void output_crimes(vector<Crime>& myCrime)
{
	// Use size operation to get the number of crimes
	cout << "# of crimes: " << myCrime.size() << endl << endl;
	string mybool1,mybool2;	
	// Print first 3 crimes
	for(auto i = 0; i < 3; ++i){
		
		if(myCrime[i].Arrest == "TRUE")
			mybool1 = "arrest";
		else
			mybool2 = "	";
		if(myCrime[i].DomesticViolence == "TRUE")
			mybool2 ="domestic violence";
		else
			mybool2 = "	";
			
		cout << myCrime[i].IUCR << ":	" << myCrime[i].DateTime <<  ", "<< myCrime[i].District << "," 
				<< myCrime[i].Beat << ", " << myCrime[i].Ward << ", " << myCrime[i].Community << mybool1 
				<< ", " << mybool2 << endl;
	}
	
	cout << "..." << endl;
	
	// Print last 3 crimes
	for(auto i = myCrime.size()-3; i < myCrime.size(); ++i){
		
		if(myCrime[i].Arrest == "TRUE")
            mybool1 = "arrest";
        else
            mybool2 = " ";
        if(myCrime[i].DomesticViolence == "TRUE")
            mybool2 ="domestic violence";
        else
            mybool2 = " ";
             
        cout << myCrime[i].IUCR << ":   " << myCrime[i].DateTime <<  ", "<< myCrime[i].District << ", " 
                << myCrime[i].Beat << ", " << myCrime[i].Ward << ", " << myCrime[i].Community << ", " << mybool1
                << "   " << mybool2 << endl;
		
	}
}
// End of output_crimes function

/*
 * output_crime_codes() function
 * 
 * Function outputs the number of crime codes
 */
void output_crime_codes(vector<CrimeCode>& myCrimeCode)
{
	// Display the number of crime codes
	cout << "# of crime codes: " << myCrimeCode.size() << endl << endl;


	// Sort the crime codes
	sort(myCrimeCode.begin(), myCrimeCode.end(), [](CrimeCode& a, CrimeCode& b){
		if(a.IUCR < b.IUCR)
			return true;
		else
			return false;
	});

	// Output the first 3 crime codes
	for(auto i = 0; i < 3; ++i){
		
		cout << myCrimeCode[i].IUCR <<  myCrimeCode[i].Pdescript << myCrimeCode[i].Sdescript << endl;
	}	
	cout << "..." << endl;
	// Output the last 3 crime codes
	for(auto i = myCrimeCode.size()-3; i < myCrimeCode.size(); ++i){
		cout << myCrimeCode[i].IUCR <<  myCrimeCode[i].Pdescript << myCrimeCode[i].Sdescript << endl << endl;	
	}
}
// End of output_crime_codes

void top_five_crimes(vector<Crime>& myCrime, vector<CrimeCode>& myCrimeCode)
{
    cout << endl << "** Top-5 Crimes **" << endl;  	
    for(auto i = 0; i < myCrime.size(); ++i){
        for(auto j = 0; j < myCrimeCode.size(); ++j){
            myCrimeCode[j].counter = 0; 
            if(myCrime[i].IUCR == myCrimeCode[j].IUCR) 
                myCrimeCode[j].counter++;
        }    
    }
    cout << "Code:  " << "Total,    " << "Description" << endl;
    sort(myCrimeCode.begin(), myCrimeCode.end(), [](CrimeCode& a, CrimeCode& b){
    
        if(a.counter < b.counter)
            return true;
        else
            return false;
    });
    for(auto i = 0; i < 5; ++i){
        
        cout << myCrimeCode[i].IUCR << myCrimeCode[i].counter << ", " << myCrimeCode[i].Pdescript << myCrimeCode[i].Sdescript << endl;
    } 
    
} 

/* 
 * main Function
 *
 * Starts the program and reads the CSV files
 */
int main(int argc, char* argv[])
{
    // Print title of Program
    cout << "** Crime Analysis **" << endl << endl;

    // Open crime.csv file 
    ifstream crime_file("crimes.csv");
	// String values to get crime statistics
    string line, date_time, iucr, arrest, domestic, beat, district, ward, community, year;

	// Open crime-codes.csv file
	ifstream crime_code_file("crime-codes.csv");
	// String vaules to get crime code statistics
	string line2, crime_code_iucr, prime, secondary;

	istream_iterator<string> start(crime_file), end;

	// Check if crime file exist, if not exit program
    if(!crime_file.good()){
        cout << "cannot open file!" << endl;
        return -1;
    }
	if(!crime_code_file.good()){
		cout << "cannot open crime code file!" << endl;
		return -1;
	}

    // Input data into a vector of crime objects:
    vector<Crime> crimes;
    
    getline(crime_file, line);  // skip header

    while( getline(crime_file, line) ){
        
        stringstream ss(line);  // Use stringstream to help parse CSV file
        
        // parse line:
        getline(ss, date_time, ',');
        getline(ss, iucr, ',');
        getline(ss, arrest, ',');
        getline(ss, domestic, ',');
        getline(ss, beat, ',');
        getline(ss, district, ',');
        getline(ss, ward, ',');
        getline(ss, community, ',');
        getline(ss, year);

        Crime C(date_time, iucr,
                arrest, domestic,
                stoi(beat), stoi(district),
                stoi(ward), stoi(community),
                stoi(year));

        // insert @ end;
        crimes.push_back(C); 
    }
	
	// Input Crime codes into a vector of crime code objects
	vector<CrimeCode> crimeCodes;

	getline(crime_code_file, line2);
	while( getline(crime_code_file, line2) ){
		
		stringstream ss2(line2);	// Use string stream to help parse crime codes CSV file

		// parse line2
		getline(ss2, crime_code_iucr);
		getline(ss2, prime);
		getline(ss2, secondary);

		CrimeCode C2(crime_code_iucr, prime, secondary);
		
		// insert @ end;
		crimeCodes.push_back(C2);
	}
	// Output date range (recall crimes are in order by date)	
	date_range(crimes);	 

	// Output total number of crime codes and codes
	output_crime_codes(crimeCodes);

	// Output Total number of crimes and crimes
	output_crimes(crimes);

	// Top-5 Crimes
	top_five_crimes(crimes, crimeCodes);	
    
    cout << endl << "** Done ** " << endl;
}
// End of main Function
