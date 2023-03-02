#include <iostream>

#define MAX_SIZE 10

using namespace std;

int main()
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
    while (cin.fail() || n < 0 || n > MAX_SIZE)
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Nhap khong thoa yeu cau! Vui long nhap lai: n = ";
        cin >> n;
    }
    cout << endl;
    int i, j, a = 0, chi_so_i = 0, chi_so_j = 0, chieu_dai = n - 1, mang[MAX_SIZE][MAX_SIZE];
    while (a < n*n)
    {
        if (chieu_dai == 0)
        {
            mang[n/2][n/2] = ++a;
        }
        for (j = chi_so_j; j - chi_so_j < chieu_dai; j++)
        {
            mang[chi_so_i][j] = ++a;
        }
        chi_so_j = j;
        for (i = chi_so_i; i - chi_so_i < chieu_dai; i++)
        {
            mang[i][chi_so_j] = ++a;
        }
        chi_so_i = i;
        for (j = chi_so_j; chi_so_j - j < chieu_dai; j--)
        {
            mang[chi_so_i][j] = ++a;
        }
        chi_so_j = j;
        for (i = chi_so_i; chi_so_i - i < chieu_dai; i--)
        {
            mang[i][chi_so_j] = ++a;
        }
        chi_so_j = j + 1;
        chi_so_i = i + 1;
        chieu_dai -= 2;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << mang[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
