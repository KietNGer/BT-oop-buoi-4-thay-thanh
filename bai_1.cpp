#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class PhanSo
{
private:
    int TuSo;
    int MauSo;
public:
     PhanSo()
     {
         int TuSo = 0;
         int MauSo = 1;
     }
     ~PhanSo()
     {
         int TuSo = 0;
         int MauSo = 1;
     }
     void Nhap();
     void Xuat(PhanSo A, PhanSo B);
     void Cong(PhanSo A, PhanSo B);
     void Tru(PhanSo A, PhanSo B);
     void Tich(PhanSo A, PhanSo B);
     void Thuong(PhanSo A, PhanSo B);
};

void PhanSo :: Nhap()
{
    cout << "Nhap tu so: ";
    cin >> TuSo;
    cout << "Nhap mau so: ";
    cin >> MauSo;
}

int UCLN(int a, int b)
{
    if(a < 0)
        a *= -1;
    if(b < 0)
        b *= -1;
    if(a == 0 || b == 0)
        return a + b;
    while(a != b)
    {
        if(a > b)
            a -= b;
        else if(b > a)
            b -= a;
    }
    return a;
}

void Rut_gon(int a, int b)
{
    if(b < 0)
    {
        a *= -1;
        b *= -1;
    }
    if(b == 0)
        cout << "khong the rut gon";
    else if(a == 0)
        cout << "0";
    else if(a % b == 0)
        cout << a/b;
    else
        cout << "<" << a/UCLN(a, b) << "/" << b/UCLN(a, b) << ">" << endl;
}

void PhanSo :: Cong(PhanSo A, PhanSo B)
{
    int a[2];
    a[0] = A.TuSo * B.MauSo + A.MauSo * B.TuSo;
    a[1] = A.MauSo * B.MauSo;
    Rut_gon(a[0], a[1]);
}

void PhanSo :: Tru(PhanSo A, PhanSo B)
{
    int a[3];
    a[0] = A.TuSo * B.MauSo - A.MauSo * B.TuSo;
    a[1] = A.MauSo * B.MauSo;
    Rut_gon(a[0], a[1]);
}

void PhanSo :: Tich(PhanSo A, PhanSo B)
{
    int a[2];
    a[0] = A.TuSo * B.TuSo;
    a[1] = A.MauSo * B.MauSo;
    Rut_gon(a[0], a[1]);
}

void PhanSo ::Thuong(PhanSo A, PhanSo B)
{
    int a[2];
    a[0] = A.TuSo * B.MauSo;
    a[1] = A.MauSo * B.TuSo;
    Rut_gon(a[0], a[1]);
}

void PhanSo :: Xuat(PhanSo A, PhanSo B)
{
    PhanSo C;
    cout << "Tong hai phan so: ";
    C.Cong(A, B);
    cout << "\nHieu hai phan so: ";
    C.Tru(A, B);
    cout << "\nTich hai phan so: ";
    C.Tich(A, B);
    cout << "\nThuong hai phan so: ";
    C.Thuong(A, B);
}

int main()
{
    PhanSo A;
    PhanSo B;
    cout << "Nhap phan so thu nhat: \n";
    A.Nhap();
    cout << "Nhap phan so thu hai: \n";
    B.Nhap();
    A.Xuat(A, B);
    return 0;
}
