#include <iostream>
#include <vector>
#include "Sample.hpp"

using namespace std;

ostream& operator<<(ostream& o, vector<int> v){
    for(int a : v)
        o << a << ' ';
    o << endl;
    return o;
}

int main(){
    vector<int> v {3,2,1,5};
    cout << v;

    Sample<vector<int>::iterator> sample;
    auto less = [](int a, int b){
        return a < b;
    };
    auto greater = [](int a, int b){
        return a > b;
    };
    //or std::less and std::greater (in <functional>)

    sample.sort<decltype(sample)::selection>(v.begin(), v.end(), less);
    cout << v;
    sample.sort<decltype(sample)::insertion>(v.begin(), v.end(), greater);
    cout << v;
    sample.sort<decltype(sample)::bubble>(v.begin(), v.end(), less);
    cout << v;
}