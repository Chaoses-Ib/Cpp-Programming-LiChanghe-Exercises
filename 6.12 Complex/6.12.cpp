#include <iostream>
#include "Complex.hpp"

using namespace std;

int main(){
    Complex c(3,2);
    cout << c << endl;
    cout << 3+2_i << endl;

    Complex c2;
    cin >> c2;
    if(cin.fail()){
        cout << "Invalid input\n";
        return 1;
    }
    c2 += c;
    cout << c2 << endl;

    c2 = 1+2_i;
    c2 = c2 + -1-1_i - 1_i;
    cout << (c2 == 0_i) << endl;
}