#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string filename;
    cout << "Input file a and b:" << endl;
    getline(cin, filename);
    ifstream file_a(filename, ios::binary);
    getline(cin, filename);
    ifstream file_b(filename, ios::binary);
    if(file_a.fail() || file_b.fail()){
        cout << "Opening input files failed." << endl;
        return 1;
    }

    cout << "Input output filename:" << endl;
    getline(cin, filename);
    ofstream file(filename, ios::binary | ios::trunc);
    if(file_a.fail() || file_b.fail()){
        cout << "Opening output file failed." << endl;
        return 2;
    }

    //streambuf_iterator<uint8_t> is invalid (and stream_iterator<uint8_t> is for string stream), so we need streambuf_iterator<char>
    auto i = copy(istreambuf_iterator<char>(file_a), istreambuf_iterator<char>(), ostreambuf_iterator<char>(file));
    copy(istreambuf_iterator<char>(file_b), istreambuf_iterator<char>(), i);
}

//In practice, we use `cat a.txt b.txt > c.txt`