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


// classes

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
        bool  Arrest;
        bool DomesticViolence;
        int Beat;
        int District;
        int Ward;
        int Community;
        int Year;
    
    Crime(string datetime, string iucr, bool arrest, bool domestic, int beat, int district, int ward, int community, int year)
        : DateTime(datetime), IUCR(iucr), Arrest(arrest), DomesticViolence(domestic), Beat(beat), District(district), Ward(ward),
            Community(community), Year(year)
    { }
};

// main Function
int main()
{

}
// End of main Function
