#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class SoPhuc
{
    double thuc;
    double ao;
public:
    SoPhuc()
    {
        double thuc = 0;
        double ao = 0;
    }
    ~SoPhuc()
    {
        double thuc = 0;
        double ao = 0;
    }
    void Nhap();
    void Xuat(int a, int b);
    void Tong(SoPhuc a, SoPhuc b);
    void Hieu(SoPhuc a, SoPhuc b);
    void Tich(SoPhuc a, SoPhuc b);
    void Thuong(SoPhuc a, SoPhuc b);
};

void SoPhuc :: Nhap()
{
    cout << "nhap phan thuc: ";
    cin >> thuc;
    cout << "nhap phan ao: ";
    cin >> ao;
}

void SoPhuc ::Xuat(int a, int b)
{
    if(a == 0)
    {
        if(b == 0)
            cout << "0" << endl;
        else
            cout << b << "i" << endl;
    }
    else if(a != 0)
    {
        if(b == 0)
             cout << a << endl;
        else if(b > 0)
            cout << a << "+" << b << "i" << endl;
        else if(b < 0)
            cout << a << b << "i" << endl;
    }
}

void SoPhuc :: Tong(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.thuc = a.thuc + b.thuc;
    c.ao = a.ao + b.ao;
    c.Xuat(c.thuc, c.ao);
}

void SoPhuc :: Hieu(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.thuc = a.thuc - b.thuc;
    c.ao = a.ao - b.ao;
    c.Xuat(c.thuc, c.ao);
}

void SoPhuc :: Tich(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.thuc =  a.thuc * b.thuc - a.ao * b.ao;
    c.ao = a.thuc * b.ao + a.ao * b.thuc;
    c.Xuat(c.thuc, c.ao);
}

void SoPhuc :: Thuong(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.thuc = (a.thuc * b.thuc + a.ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
    c.ao = (b.thuc * a.ao - a.thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
    c.Xuat(c.thuc, c.ao);
}

int main()
{
    SoPhuc a;
    SoPhuc b;
    cout << "Nhap so phuc thu nhat: \n";
    a.Nhap();
    cout << "Nhap so phuc thu hai: \n";
    b.Nhap();
    cout << "Tong hai so phuc: ";
    a.Tong(a, b);
    cout << "Hieu hai so phuc: ";
    a.Hieu(a, b);
    cout << "Tich hai so phuc: ";
    a.Tich(a, b);
    cout << "Thuong hai so phuc: ";
    a.Thuong(a, b);
    return 0;
}
