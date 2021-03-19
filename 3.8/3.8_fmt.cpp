#include <string>
#include <fmt/core.h>

#pragma comment(lib, "fmt.lib")

using namespace std;

int main(){
    for(int n : {1,3,5,7,3,3,3}){
        string l;
        for(int i=0; i < n-1; i++)
            l += "* ";
        l += '*';
        fmt::print("{:^13}\n", l);
    }
}