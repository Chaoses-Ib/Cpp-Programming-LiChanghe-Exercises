#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    cout <<
R"(
      *
    * * *
  * * * * *
* * * * * * *
    * * *
    * * *
    * * *
)";

    for(int n : {1,3,5,7,3,3,3}){
        string l;
        for(int i=0; i < n/2; i++)
            l += "* ";
        /*cout
        << right << setw(6) << l
        << "* "
        << left << setw(6) << l
        << endl;
        */
        printf("%6s* %-6s\n", l.c_str(), l.c_str());
    }
}