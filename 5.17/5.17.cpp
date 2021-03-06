#include <iostream>

using namespace std;

int main(){
    char base_char[] = "0123456789ABCDEFGHIJKLMNOP";
    cout << "Format: num N M  (N,M <= 26)" << endl;

    string s_n;
    int n, m;
    cin >> s_n >> n >> m;

    long long v = 0;
    for(size_t i = 0; i < s_n.size(); ++i){
        char c = s_n[i];
        int digit;
        if('0' <= c && c <= '9')
            digit = c - '0';
        else if('A' <= c && c <= 'P')
            digit = c - 'A' + 10;
        else if('a' <= c && c <= 'p')
            digit = c - 'a' + 10;
        else
            break;

        v = v * n + digit;
    }

    cout << v << endl;

    string s_m;
    do{
        s_m.insert(s_m.begin(), base_char[v % m]);
    }while(v /= m);
    cout << s_m << endl;
}