#include <iostream>
#include <fstream>
#include <ios>
#include <cstdlib>

using namespace std;

int main() {
    ofstream ofile;
    ofile.open("in.txt", ios::in);
    for (int i = 0; i < 1000; ++i) {
        ofile << 1 << endl;
    }
    ofile.close();
}
