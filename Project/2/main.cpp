#include <iostream>
#include <cmath>

using namespace std;

void xu_ly(int n)
{
    int i, j, m = 0, vong = ceil(n/2), chi_so_i = 0, chi_so_j = 0, chieu_dai = n - 1, a[n][n], b[n][n];
    bool chan = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = ++m;
        }
    }
    while (vong)
    {
        if (chan)
        {
            for (j = chi_so_j; j - chi_so_j < chieu_dai; j++)
            {
                b[chi_so_i][j] = a[chi_so_i][j + 1];
            }
            chi_so_j = j;
            for (i = chi_so_i; i - chi_so_i < chieu_dai; i++)
            {
                b[i][chi_so_j] = a[i + 1][chi_so_j];
            }
            chi_so_i = i;
            for (j = chi_so_j; chi_so_j - j < chieu_dai; j--)
            {
                b[chi_so_i][j] = a[chi_so_i][j - 1];
            }
            chi_so_j = j;
            for (i = chi_so_i; chi_so_i - i < chieu_dai; i--)
            {
                b[i][chi_so_j] = a[i - 1][chi_so_j];
            }
        }
        else
        {
            for (i = chi_so_i; i - chi_so_i < chieu_dai; i++)
            {
                b[i][chi_so_j] = a[i + 1][chi_so_j];
            }
            chi_so_i = i;
            for (j = chi_so_j; j - chi_so_j < chieu_dai; j++)
            {
                b[chi_so_i][j] = a[chi_so_i][j + 1];
            }
            chi_so_j = j;
            for (i = chi_so_i; chi_so_i - i < chieu_dai; i--)
            {
                b[i][chi_so_j] = a[i - 1][chi_so_j];
            }
            chi_so_i = i;
            for (j = chi_so_j; chi_so_j - j < chieu_dai; j--)
            {
                b[chi_so_i][j] = a[chi_so_i][j - 1];
            }
        }
        chi_so_i = i + 1;
        chi_so_j = j + 1;
        chieu_dai -= 2;
        chan = !chan;
        vong--;
        if (chieu_dai == 0)
        {
            b[n/2][n/2] = a[n/2][n/2];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << b[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    while (cin.fail() || n < 0)
    {
        cin.clear();
        cin.ignore(999, '\n');
        cin >> n;
    }
    xu_ly(n);
    return 0;
}
