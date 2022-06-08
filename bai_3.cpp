#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Candidate
{
private:
    int Ma;
    char NgaySinh[10];
    char Ten[30];
    double Toan;
    double Van;
    double Anh;
public:
    Candidate()
    {
        int Ma = 0;
        char NgaySinh[10] = "";
        char Ten[30] = "";
        double Toan = 0;
        double Van = 0;
        double Anh = 0;
    }
    ~Candidate()
    {
        int Ma = 0;
        char NgaySinh[10] = "";
        char Ten[30] = "";
        double Toan = 0;
        double Van = 0;
        double Anh = 0;
    }
    void Nhap();
    float Diem_tong();
    void Xuat();
};

class TestCandidate
{
public:
    void Tim_kiem(Candidate c[100], int So_luong);
};

void Candidate :: Nhap()
{
    cout << "Nhap ma cua thi sinh: ";
    cin >> Ma;
    cin.ignore();
    cout << "Nhap ngay sinh cua thi sinh: ";
    cin.getline(NgaySinh, 10);
    cout << "Nhap ten cua thi sinh: ";
    cin.getline(Ten, 30);
    cout << "Nhap diem toan: ";
    cin >> Toan;
    cout << "Nhap diem van: ";
    cin >> Van;
    cout << "Nhap diem anh: ";
    cin >> Anh;
}

float Candidate ::Diem_tong()
{
    float sum = 0;
    sum = Toan + Van + Anh;
    return sum;
}

void Candidate :: Xuat()
{
    cout << "\nMa thi sinh: " << Ma << endl;
    cout << "Ngay sinh thi sinh: " << NgaySinh << endl;
    cout << "Ho the thi sinh: " << Ten << endl;
    cout << "Diem Toan: " << Toan << endl;
    cout << "Diem Van: " << Van << endl;
    cout << "Diem Anh: " << Anh << endl;
}

void TestCandidate ::Tim_kiem(Candidate A[100], int SoLuong)
{
    int dem = 0;
    for(int i = 0; i < SoLuong; i++)
    {
        if(A[i].Diem_tong() > 15)
        {
            cout << "\nThi sinh thu " << dem + 1 << " : ";
            A[i].Xuat();
        }
        dem++;
    }
}

int main()
{
    int SoLuong;
    Candidate A[100];
    cout << "Nhap so luong: ";
    cin >> SoLuong;
    for(int i = 0; i < SoLuong; i++)
    {
        cout << "Thi sinh thu nhat " << i + 1 << endl;
        A[i].Nhap();
    }
    cout << "\n==Danh sach thi sinh ==";
    for(int i = 0; i < SoLuong; i++)
    {
        A[i].Xuat();
    }
    TestCandidate C;
    cout << "\n--Danh sach thi sinh co diem tren 15: ";
    C.Tim_kiem(A, SoLuong);
    return 0;
}
