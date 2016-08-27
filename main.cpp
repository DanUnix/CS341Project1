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


/** classes **/

// CrimeCode Class
class CrimeCode
{
    public:
        string IUCR;        // Illinois Uniform Crime Reporting
        string Pdescript;   // Primary Description of code
        string Sdescript;   // Secondary Description of code

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
}
// End of output_crimes function

/*
 * output_crime_codes() function
 * 
 * Function outputs the number of crime codes
 */
void output_crime_codes()
{
	cout << "# of crime codes: " << endl << endl;
}
// End of output_crime_codes

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

	istream_iterator<string> start(crime_file), end;

    string line, date_time, iucr, arrest, domestic, beat, district, ward, community, year;

    if(!crime_file.good()){
        cout << "cannot open file!" << endl;
        return -1;
    }

    // Input data into a vector of crime objects:
    vector<Crime> crimes;
    
    getline(crime_file, line);  // skip header

    while( getline(crime_file, line)){
        
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
	
	// Output date range (recall crimes are in order by date)	
	date_range(crimes);	 

	// Output Total number of crimes
	output_crimes(crimes);
}
// End of main Function
