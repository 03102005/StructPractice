#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef struct PhanSo
{
int tuSo;
int mauSo;
} PS;

// Nhap phan so
void nhapPS(PS *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &(ps->tuSo));
    printf("Nhap mau so: ");
    scanf("%d", &(ps->mauSo));
}
// Xuat phan so
void inPS(PS ps) {
    printf("%d/%d\n", ps.tuSo, ps.mauSo);
}

// Tim uoc chung lon nhat
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

// Rut gon phan so
void rutGon(PS *ps) {
    int a = UCLN(ps->tuSo, ps->mauSo);
    ps->tuSo = ps->tuSo / a;
    ps->mauSo = ps->mauSo / a;
}

// Cong phan so
PS Tong(PS ps1, PS ps2) {
    PS ketQua;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    rutGon(&ketQua);
    return ketQua;
}

// Tru phan so
PS Hieu(PS ps1, PS ps2) {
    PS ketQua;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    rutGon(&ketQua);
    return ketQua;
}

// Nhan phan so
PS Tich(PS ps1, PS ps2) {
    PS ketQua;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    rutGon(&ketQua);
    return ketQua;
}

// Chia phan so
PS Thuong(PS ps1, PS ps2) {
    PS ketQua;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    rutGon(&ketQua);
    return ketQua;
}

// So sanh phan so
int soSanh(PS ps1, PS ps2) {
    int phanso1 = ps1.tuSo * ps2.mauSo;
    int phanso2 = ps2.tuSo * ps1.mauSo;
    if (phanso1 == phanso2)
        return 0;
    else if (phanso1 > phanso2)
        return 1;
    else
        return -1;
}

int main() {
    PS ps1, ps2, ketQua;
    printf("Nhap phan so 1:\n");
    nhapPS(&ps1);
    printf("Nhap phan so 2:\n");
    nhapPS(&ps2);
    printf("Phan so 1: ");
    inPS(ps1);
    printf("Phan so 2: ");
    inPS(ps2);
    ketQua = Tong(ps1, ps2);
    printf("Tong hai phan so la: ");
    inPS(ketQua);
    ketQua = Hieu(ps1, ps2);
    printf("Hieu hai phan so la: ");
    inPS(ketQua);ketQua = Tich(ps1, ps2);
    printf("Tich hai phan so la: ");
    inPS(ketQua);
    ketQua = Thuong(ps1, ps2);
    printf("Thuong hai phan so la: ");
    inPS(ketQua);
    int ketquasosanh = soSanh(ps1, ps2);
    if (ketquasosanh == 0)
        printf("Hai phan so bang nhau!\n");
    else if (ketquasosanh == 1)
        printf("Phan so 1 lon hon phan so 2.\n");
    else if (ketquasosanh == -1)
        printf("Phan so 2 lon hon phan so 1.\n");

    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerName(computerName, &size)) {
        printf("\n\nTen may tinh la: %s\n", computerName);
    }
    return 0;
}