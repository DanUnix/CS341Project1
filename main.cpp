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
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// namespaces
using std::string;
using std::ifstream;
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
 * date_range function
 *
 * Function outputs the range of the dates which marks from one period to another
 */
void date_range()
{

}
// End of date_range function

// main Function
int main()
{
    // Print title of Program
    cout << "** Crime Analysis **" << endl;

    // Open crime.csv file 
    ifstream crime_file("crimes.csv");
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
}
// End of main Function
