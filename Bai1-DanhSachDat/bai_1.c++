/**
 MỘT SỐ THAO TÁC DANH SÁCH DẶT
    - Nhập danh sách
    - Xuất danh sách
    - Tìm kiếm danh sách
    - Thêm một phần tử vào trị trí i trong danh sách
    - Xóa một phần tử tại vị trí i trong danh sách
 */

#include <iostream>
using namespace std;
#define MAX 100

// Định nghĩa struct DsDat
struct DsDat
{
    int a[MAX];
    int n;
};

// Nhập danh sách
void nhapDsDat(DsDat &ds)
{
    cout << "Nhap gia tri n = ";
    cin >> ds.n;
    for (int i = 0; i < ds.n; i++)
    {
        cout << "Nhap mang a[" << i << "] = ";
        cin >> ds.a[i];
    }
}

// Xuất danh sách
void xuatDsDat(const DsDat &ds)
{
    for (int i = 0; i < ds.n; i++)
    {
        cout << "a[" << i << "] = " << ds.a[i] << endl;
    }
}

// Tìm kiếm vị trí đầu tiên của giá trị x
int timKiemDsDatDauTien(const DsDat &ds, int x)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Tìm kiếm vị trí cuối cùng của giá trị x
int timKiemDsDatCuoiCung(const DsDat &ds, int x)
{
    for (int i = ds.n - 1; i >= 0; i--)
    {
        if (ds.a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// Chèn một phần tử vào vị trí i
bool chenViTri(DsDat &ds, int viTri, int giaTri)
{
    if (viTri < 0 || viTri > ds.n || ds.n >= MAX)
        return false;
    for (int i = ds.n; i > viTri; i--)
    {
        ds.a[i] = ds.a[i - 1];
    }
    ds.a[viTri] = giaTri;
    ds.n++;
    return true;
}

// Xóa một phần tử tại vị trí i
bool xoaViTri(DsDat &ds, int viTri)
{
    if (viTri < 0 || viTri >= ds.n)
        return false;
    for (int i = viTri; i < ds.n - 1; i++)
    {
        ds.a[i] = ds.a[i + 1];
    }
    ds.n--;
    return true;
}

int main()
{
    DsDat ds;
    nhapDsDat(ds);
    xuatDsDat(ds);

    // Tìm kiếm giá trị
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int vt = timKiemDsDatDauTien(ds, x);
    if (vt != -1)
    {
        cout << "Tim thay gia tri tai vi tri dau tien: " << vt << endl;
    }
    else
    {
        cout << "Khong tim thay gia tri trong danh sach." << endl;
    }

    int vt2 = timKiemDsDatCuoiCung(ds, x);
    if (vt2 != -1)
    {
        cout << "Tim thay gia tri tai vi tri cuoi cung: " << vt2 << endl;
    }
    else
    {
        cout << "Khong tim thay gia tri trong danh sach." << endl;
    }

    // Chèn giá trị vào danh sách
    int giaTri, viTri;
    cout << "Nhap gia tri can them: ";
    cin >> giaTri;
    cout << "Nhap vi tri can chen: ";
    cin >> viTri;
    if (chenViTri(ds, viTri, giaTri))
    {
        cout << "Them thanh cong. Danh sach moi:" << endl;
        xuatDsDat(ds);
    }
    else
    {
        cout << "Them that bai." << endl;
    }

    // Xóa giá trị khỏi danh sách
    cout << "Nhap vi tri can xoa: ";
    cin >> viTri;
    if (xoaViTri(ds, viTri))
    {
        cout << "Xoa thanh cong. Danh sach moi:" << endl;
        xuatDsDat(ds);
    }
    else
    {
        cout << "Xoa that bai." << endl;
    }

    return 0;
}
