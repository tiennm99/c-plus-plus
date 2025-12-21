#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_SIZE 1000

using namespace std;

int main()
{
  int a[MAX_SIZE][MAX_SIZE];
  int size;
  {
    ifstream ifile;
    string str;
    int    i = 0;
    ifile.open("in.txt", ios::in);

    while (getline(ifile, str)) {
      istringstream(str) >> a[0][i];
      ++i;
    }
    size = i;
    ifile.close();
  }

  for (int i = 1; i < size; ++i) {
    for (int j = 0; j < size - i; ++j) {
      a[i][j] = a[i - 1][j] + a[i - 1][j + 1];
    }
  }

  int max = a[0][0];
  int l   = 0;
  int r   = 0;

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - i; ++j) {
      if (a[i][j] > max) {
        max = a[i][j];
        l   = j;
        r   = i + j;
      }
    }
  }

  {
    ofstream ofile;
    ofile.open("out.txt", ios::out);

    for (int i = l; i <= r; ++i) {
      ofile << a[0][i] << ",\t\t";
    }
    ofile << "\n";

    for (int i = 0; i <= size; ++i) {
      for (int j = 0; j <= size - i; ++j) {
        ofile << a[i][j] << ",\t\t";
      }
      ofile << "\n";
    }
    ofile.close();
  }

  return 0;
}
