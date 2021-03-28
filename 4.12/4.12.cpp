#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ostringstream ss;
    copy_n(istream_iterator<string>(cin), 2, ostream_iterator<string>(ss));
    cout << ss.str() << endl;
}