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
class CrimeCode
{
    public:
        string IUCR;
        string Pdescript;
        string Sdescript; 

    CrimeCode(string iucr, string primary, string secondary)
        : IUCR(iucr), Pdescript(primary), Sdescript(secondary)
    { } 
};

// main Function
int main()
{

}
// End of main Function
