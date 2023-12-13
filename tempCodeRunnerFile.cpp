#include <stdio.h>
#include <math.h>
#include <windows.h>

typedef struct {
    int maTinh;
    char tenTinh[100];
    int danSo;
    float dienTich;
} Tinh;

// Nhap thong tin Tinh
void nhapTinh(Tinh *tinh) {
    printf("Nhap ma tinh: ");
    scanf("%d", &(tinh->maTinh));
    printf("Nhap ten tinh: ");
    scanf("%s", tinh->tenTinh);
    printf("Nhap dan so: ");
    scanf("%d", &(tinh->danSo));
    printf("Nhap dien tich: ");
    scanf("%f", &(tinh->dienTich));
}

// Xuat thong tin
void xuatTinh(Tinh tinh) {
    printf("Ma tinh: %d\n", tinh.maTinh);
    printf("Ten tinh: %s\n", tinh.tenTinh);
    printf("Dan so: %d\n", tinh.danSo);
    printf("Dien tich: %.2f\n", tinh.dienTich);
}

// Nhap danh sach Tinh
void nhapDanhSachTinh(Tinh *dsTinh, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nNhap thong tin tinh thu %d:\n", i + 1);
        nhapTinh(&dsTinh[i]);
    }
}

// Xuat cac tinh co dan so hon 1 trieu
void xuatTinhDanSoLonHonMotTrieu(Tinh *dsTinh, int n) {
    int i;
    printf("\nCac tinh co dan so lon hon 1 trieu:\n");
    for (i = 0; i < n; i++) {
        if (dsTinh[i].danSo > 1000000) {
            xuatTinh(dsTinh[i]);
        }
    }
}

// Tim tinh co dien tich lon nhat
Tinh timTinhDienTichLonNhat(Tinh *dsTinh, int n) {
    int i;
    Tinh tinhLonNhat = dsTinh[0];
    for (i = 1; i < n; i++) {
        if (dsTinh[i].dienTich > tinhLonNhat.dienTich) {
            tinhLonNhat = dsTinh[i];
        }
    }
    return tinhLonNhat;
}

int main() {
    int n;
    printf("Nhap so luong tinh: ");
    scanf("%d", &n);
    Tinh *dsTinh = (Tinh *)malloc(n * sizeof(Tinh));
    nhapDanhSachTinh(dsTinh, n);
    printf("\nThong tin cac tinh:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Tinh thu %d:\n", i + 1);
        xuatTinh(dsTinh[i]);
    }
    xuatTinhDanSoLonHonMotTrieu(dsTinh, n);
    Tinh tinhLonNhat = timTinhDienTichLonNhat(dsTinh, n);
    printf("\nTinh co dien tich lon nhat:\n");xuatTinh(tinhLonNhat);

    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerName(computerName, &size)) {
        printf("\n\nTen may tinh la: %s\n", computerName);
    }
    return 0;
}
