#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n][n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[0][i + j];
        }
    }
    int max = arr[0][0], chi_so_i = 0, chi_so_j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[i][j] >= max)
            {
                max = arr[i][j];
                chi_so_i = i;
                chi_so_j = j;
            }
        }
    }
    for (int i = chi_so_j; i <= chi_so_i + chi_so_j; i++)
    {
        cout << arr[0][i] << "\t";
    }
    cout << endl << max << endl;
    return 0;
}
