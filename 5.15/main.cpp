#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

vector<vector<int>> MakeTable(int row, int col){
    vector<vector<int>> table(row, vector<int>(col));
    int n = 1;
    int i = row, j = col - 1;
    enum direction{up, down, left, right} d = up;

    do{
        switch(d){
            case up:
                for(int k=0; k < row; k++)
                    table[--i][j] = n++;
                d = left;
                col--;
                break;
            case down:
                for(int k=0; k < row; k++)
                    table[++i][j] = n++;
                d = right;
                col--;
                break;
            case left:
                for(int k=0; k < col; k++)
                    table[i][--j] = n++;
                d = down;
                row--;
                break;
            case right:
                for(int k=0; k < col; k++)
                    table[i][++j] = n++;
                d = up;
                row--;
                break;
        }
    }while(col && row);

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

pair<int,int> FindFactorPair(int n){
    int root = floor(sqrt(n));
    int a = 1, b = n;
    for(int i = root; i >= 2; --i){
        int j = n / i;
        if(i * j == n || i * ++j == n){
            a = i, b = j;
            break;
        }
    }
    return {a,b};
}

vector<vector<int>> MakeTable(int n){
    auto [r, c] = FindFactorPair(n);
    return MakeTable(r, c);
}

int main(){
    cout << "12 = 3*4\n" << MakeTable(12) << endl;
    cout << "100 = 10*10\n" << MakeTable(100) << endl;
    cout << "100 = 5*20\n" << MakeTable(5, 20) << endl;
    cout << "520 = 20*26\n" << MakeTable(520) << endl;
}