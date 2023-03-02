#include <iostream>
#include <cmath>

using namespace std;

typedef struct
{
    int tu, mau;
} phan_so;

void nhap(phan_so &x)
{
    cout << "Tu = ";
    cin >> x.tu;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Nhap loi! Tu = ";
        cin >> x.tu;
    }
    cout << "Mau = ";
    cin >> x.mau;
    while (cin.fail() || x.mau == 0)
    {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Nhap loi! Mau = ";
        cin >> x.mau;
    }
}

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a%b == 0)
    {
        return b;
    }
    else
    {
        if (b > a)
        {
            return gcd(b, a);
        }
        else
        {
            return gcd(b, a%b);
        }
    }
}

void toi_gian(phan_so &x)
{
    int t = gcd(x.tu, x.mau);
    x.tu /= t;
    x.mau /= t;
    if (x.mau < 0)
    {
        x.tu *= -1;
        x.mau *= -1;
    }
}

void xuat(phan_so x)
{
    cout << x.tu;
    if (x.mau != 1)
    {
        cout << "/" << x.mau;
    }
}

phan_so cong(phan_so a, phan_so b)
{
    phan_so t;
    t.tu = a.tu*b.mau + a.mau*b.tu;
    t.mau = a.mau*b.mau;
    return t;
}

phan_so tru(phan_so a, phan_so b)
{
    phan_so t;
    t.tu = a.tu*b.mau - a.mau*b.tu;
    t.mau = a.mau*b.mau;
    return t;
}

phan_so nhan(phan_so a, phan_so b)
{
    phan_so t;
    t.tu = a.tu*b.tu;
    t.mau = a.mau*b.mau;
    return t;
}

phan_so chia(phan_so a, phan_so b)
{
    phan_so t;
    t.tu = a.tu*b.mau;
    t.mau = a.mau*b.tu;
    return t;
}

int main()
{
    phan_so a, b, tong, hieu, tich, thuong;
    cout << "Nhap tu va mau cua phan so a:" << endl;
    nhap(a);
    toi_gian(a);

    cout << "Nhap tu va mau cua phan so b:" << endl;
    nhap(b);
    toi_gian(b);

    cout << endl << "a = ";
    xuat(a);
    cout << endl << "b = ";
    xuat(b);
    cout << endl;

    tong = cong(a, b);
    toi_gian(tong);
    cout << "a + b = ";
    xuat(tong);
    cout << endl;

    hieu = tru(a, b);
    toi_gian(hieu);
     cout << "a - b = ";
    xuat(hieu);
    cout << endl;

    tich = nhan(a, b);
    toi_gian(tich);
    cout << "a*b = ";
    xuat(tich);
    cout << endl;

    if (b.tu != 0)
    {
        thuong = chia(a, b);
        toi_gian(thuong);
        cout << "a/b = ";
        xuat(thuong);
        cout << endl;
    }
    else
    {
        cout << "Phan so b = 0 nen khong the thuc hien phep chia!" << endl;
    }
    return 0;
}
