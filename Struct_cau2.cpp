#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct sinhvien {
    char MSSV[15], HoTen[50], DiaChi[50];
    int Tuoi;
    float DiemSo;
};
typedef sinhvien SV;

//Ham xoa xuong dong
void xoaXuongDong(char x[]) {
    size_t DoDai = strlen(x);
    if(x[DoDai-1] == '\n')
        x[DoDai-1] = '\0';
}

//Nhap 1 sinh vien
void input (SV *sv) {
    printf("Nhap MSSV: "); fgets(sv->MSSV, sizeof(sv->MSSV), stdin); xoaXuongDong(sv->MSSV);
    printf("Nhap ho va ten: "); fgets(sv->HoTen, sizeof(sv->HoTen), stdin); xoaXuongDong(sv->HoTen);
    printf("Nhap dia chi: "); fgets(sv->DiaChi, sizeof(sv->DiaChi), stdin); xoaXuongDong(sv->DiaChi);
    printf("Nhap tuoi: "); scanf("%d", &sv->Tuoi); getchar();
    printf("Nhap diem: "); scanf("%f", &sv->DiemSo); getchar();
}

//Xuat 1 sinh vien
void output (SV *sv) {
    printf("MSSV: %s\t", sv->MSSV);
    printf("Ho va ten: %s\t", sv->HoTen);
    printf("Dia chi: %s\t", sv->DiaChi);
    printf("Tuoi: %d\t", sv->Tuoi);
    printf("Diem so: %.2f\t", sv->DiemSo);
    printf("\n");
}

//Nhap danh sach sinh vien
void list_SV (SV *sv, int &size) {
    for(int i = 1; i <= size; i++) {
        printf("NHAP THONG TIN SINH VIEN THU %d:\n", i);
        input((sv+i));
    }
}

//Xuat danh sach sinh vien 
void output_list_SV (SV *sv, int size) {
    for(int i = 1; i <= size; i++) {
       printf("THONG TIN SINH VIEN THU %d\n", i);
       output(sv+i);
    }
}

//Sap xep sinh vien theo so tuoi tang dan
void sapXepTangTheoTuoi(SV *sv, int size) {
    for(int i = 1; i < size; i++) {
        for(int j = 2; j <= size; j++) {
            if((sv+i)->Tuoi > (sv+j)->Tuoi) {
                SV temp = *(sv+i);
                *(sv+i) = *(sv+j);
                *(sv+j) = temp;
            }
        }
    }
}

//Tim sinh vien co diem thi thap nhat
void sinhVienThapDiemNhat(SV *sv, int size) {
    int min = (sv+1)->DiemSo;
    int t = 1;
    for(int i = 1; i <= size; i++) {
        if(min > (sv+i)->DiemSo) {
             min = (sv+i)->DiemSo;
             t = i;
        }
    }
    printf("%s", (sv+t)->HoTen);
}

//Tinh diem trung binh
float diemTB(SV *sv, int size) {
    float sum = 0;
    for(int i = 1; i <= size; i++) {
        sum += (sv+i)->DiemSo;
    }
    return sum/size;
}

//Tinh so sinh vien co diem lon hon diem trung binh
int SoLuongSinhVienCoDiemLonHonTB(SV *sv, int size) {
    int dem = 0;
    for(int i = 1; i <= size; i++) {
        if((sv+i)->DiemSo > diemTB(sv, size))
            dem++;
    }
    return dem;
}

//Tim sinh vien theo MSSV
int timSV(SV *sv, int size, char timMSSV[]) {
    for(int i = 1; i <= size; i++) {
        if(strcmp(timMSSV, (sv+i)->MSSV) == 0)
            return i;
    }
    return 0;
}

//In ra thong tin cua sinh vien tim duoc
void SinhVienTheoMSSV(SV *sv, int size, char timMSSV[]) {
    if(timSV(sv, size, timMSSV) != 0)
        output((sv+timSV(sv, size, sv->MSSV)));
    else
        printf("MSSV khong hop le");
}
//ham main
int main() {
    
    int size;
    printf("Nhap so luong sinh vien: "); scanf("%d", &size); getchar();
    SV sv;
    SV *ptr = &sv;
    ptr = (SV *) malloc(size * sizeof(SV));
    list_SV(ptr, size); 
    output_list_SV(ptr, size);

    printf("\n\nSap sep danh sach sinh vien theo so tuoi tang dan\n\n");
    sapXepTangTheoTuoi(ptr, size);
    output_list_SV(ptr, size);

    printf("\nSinh vien co diem thap nhat: ");
    sinhVienThapDiemNhat(ptr, size);

    printf("\nCo %d sinh vien co diem lon hon TB\n", SoLuongSinhVienCoDiemLonHonTB(ptr, size));

    char timMSSV[15];
    printf("Nhap MSSV cua sinh vien can tim: "); scanf("%s", &timMSSV);
    SinhVienTheoMSSV(ptr, size, timMSSV);
    free(ptr);
}