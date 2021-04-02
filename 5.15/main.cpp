#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<int>> MakeTable(int row, int col){
    vector<vector<int>> table(row, vector<int>(col, 0));
    
    int n = 1;
    int i = row - 1, j = col - 1;
    table[i][j] = n++;
    enum direction{up, down, left, right} d = up;

    do{
        switch(d){
            case up:
                while(--i >= 0 && !table[i][j]){
                    table[i][j] = n++;
                }
                ++i;
                d = left;
                break;
            case down:
                while(++i < row && !table[i][j]){
                    table[i][j] = n++;
                }
                --i;
                d = right;
                break;
            case left:
                while(--j >= 0 && !table[i][j]){
                    table[i][j] = n++;
                }
                j++;
                d = down;
                break;
            case right:
                while(++j < col && !table[i][j]){
                    table[i][j] = n++;
                }
                j--;
                d = up;
                break;
        }
    }while(n <= row*col);

    return table;
}

ostream& operator<<(ostream& o, vector<vector<int>> vv){
    if(vv.empty()) return o;
    int digits = 1;
    int n = vv.size() * vv[0].size();
    for(; n /= 10; ++digits);

    for(auto& v : vv){
        for(int a : v){
            o << setw(digits+1) << a;
        }
        o << endl;
    }
    return o;
}

int main(){
    cout << MakeTable(3, 4);
    cout << endl;
    cout << MakeTable(10, 10);
}