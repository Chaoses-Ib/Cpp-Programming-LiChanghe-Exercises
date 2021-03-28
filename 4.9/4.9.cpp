#include <iostream>

using namespace std;

int main(){
    char a[20] = "auto567", *p = a, *p1;
    for(; *p; p++);
    for(p1 = p-1; p1 >= a; p++, p1 -= 2) *p = *p1;
    *p = 0;
    cout << a << endl;
    int s[][3] = {10, 20, 30, 40, 50, 60};
    int (*q)[3] = s;
    cout << q[0][0] << "," << *(q[0] + 1) << "," << (*q)[1] << '\n';
    cout << *s[0] + 1 << "," << *(*s + 1) << "," << *(s[0] + 1);  //?

    cout << endl;
    auto& b = *s;
    cout << **(s + 1);  //40
}

//auto56775ta
//10,20,20
//11,20,20