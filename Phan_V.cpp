#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void inputArr(int *a, int *n){
    for(int i = 0; i < *n; i++){
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", (a+i));
    }
}

void outputArr(int *a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%5d", *(a+i));
}

//Ham tinh tong cac phan tu trong mang
int total(int *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += *(a+i);
    return sum;
}

//Ham tim vi tri co gia tri nho nhat trong mang
int location_Min(int *a, int n){
    int count = 0;
    int min = *(a+0);
    for(int i = 0; i < n; i++){
        if(min > *(a+i)){
            min = *(a+i);
            count = i;
        }
    }
    return count;
}

//Ham kiem tra trong mang cac so nguyen co ton tai gia tri chan nho hon 2004 hay khong
bool check_Even_Number_Less_2004(int *a, int n){
    for(int i = 0; i < n; i++){
        if(*(a+i) % 2 == 0 && *(a+i) < 2004){
            return true;
        }
    }
    return false;
}

//Ham tinh tong cac gia tri am trong mang 1 chieu
int total_Negative_Value(int *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(*(a+i) < 0)
            sum += *(a+i);
    }
    return sum;
}

//Ham sap xep mang 1 chieu cac so nguyen tang dan
void sort_Up_Ascending(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(*(a+i) > *(a+j)){
                int temp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = temp;
            }
        }
    }
}

//Ham liet ke cac vi tri co gia tri am
void list_Location_Negative_Value(int *a, int n){
    for(int i = 0; i < n;i++){
        if(*(a+i) < 0){
            printf("%5d", i);
        }
    }
}

//Ham tim so chan cuoi cung trong mang
int last_Even_Numbers(int *a, int n){
    int temp, count = 0;
    for(int i = 0; i < n; i++){
        if(*(a+i) % 2 == 0){
            temp = *(a+i);
            count++;
        }
    }
    if(count == 0) return -1;
    else return temp;
}

//Kiem tra mang co tang dan hay khong
bool check_Ascending_Arr(int *a, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(*(a+i) > *(a+j))
            return false;
        } 
    }
    return true;
}

//Ham kiem tra 1 so co dang 3^k hay khong
bool check_3_luyThua_k(int n){
    if(n <= 0)
        return false;
    else if(n == 1) return true;
    else if(n % 3 != 0) return false;
    else{
        while(n % 3 == 0){
            n /= 3;
            if(n % 3 != 0 && n != 1)
                return false;
            if(n == 1) return true;
        }
    }
}

//Ham  liet ke cac so dang 3^k
void lietKeSoDang_3_luyThua_k(int *a, int n){
    for(int i = 0; i < n; i++){
        if(check_3_luyThua_k(*(a+i)) == true)
            printf("%5d", *(a+i));
    }
}

//Ham dem so duong chia het cho 7 trong mang
int demSoDuongChiaHetCho7(int *a, int n){
    int dem = 0;
    for(int i = 0; i < n; i++)
        if(*(a+i) % 7 == 0 && *(a+i) > 0)
            dem++;
    return dem;
}

int main(){
    int n;
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int));
    inputArr(a, &n);
    outputArr(a, n);

    printf("\nVi tri co gia tri nho nhat la: %d", location_Min(a, n));

    if(check_Even_Number_Less_2004(a, n) == true)
        printf("\nTon tai gia tri chan nho hon 2004 !");
    else
        printf("\nKhong ton tai gia tri chan nho hon 2004 !");

    printf("\nTong cac gia tri trong mang la %d !", total(a, n));
    printf("\nTong cac gia tri am trong mang la %d !", total_Negative_Value(a, n));
    
    printf("\nNhung vi tri co gia tri am la: ");
    list_Location_Negative_Value(a, n);

    printf("\nSo chan cuoi cung trong mang la: %d !", last_Even_Numbers(a, n));

    if(check_Ascending_Arr(a, n) == true)
        printf("\nMang da nhap la mang tang dan !");
    else
        printf("\nMang da nhap khong phai la mang tang dan !");

    printf("\nSap xep mang tang dan\n");
        sort_Up_Ascending(a, n);
        outputArr(a, n);

    printf("\nCac so co dang 3^k la: ");
    lietKeSoDang_3_luyThua_k(a, n);

    printf("\nCo %d so duong chia het cho 7 !", demSoDuongChiaHetCho7(a, n));

    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName);
    if (GetComputerName(computerName, &size)) {
        printf("\n\nTen may tinh la: %s\n", computerName);
    }
    return 0;
}