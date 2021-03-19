#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
    double pi = 4.;
    double deno = 3;
    do{
        pi -= 4/deno;
        deno += 2;
        pi += 4/deno;
        deno += 2;
        //cout << pi << endl;
    }while(abs(pi - M_PI) >= 1e-5);
    cout << pi << endl;
}