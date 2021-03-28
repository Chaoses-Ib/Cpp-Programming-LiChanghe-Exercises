#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    string line;
    getline(cin, line);
    vector<int> v{ istream_iterator<int>(istringstream(line)), istream_iterator<int>() };
    if(v.empty()) return 1;

    for(int i=1; i < v.size(); i += 2)
        cout << v[i-1] + v[i] << ' ';
    if(v.size() % 2)
        cout << v.back() << "(未参与运算)";
    cout << endl;

    auto i = v.begin();
    auto ri = v.rbegin();
    while(i <= ri.base())
        cout << *i++ + *ri++ << ' ';
    cout << endl;
}