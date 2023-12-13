#include <stdio.h>
#include <math.h>

//Hàm xoay hình
void swap(int B[][8], int n){
    for(int b = 0; b < 8; b++){
        int temp0 = B[n][0];
        int temp1 = B[n][1];
        B[n][b] = B[n][b+2];
        if(b > 5){
            B[n][6] = B[n][0];
            B[n][7] = B[n][1];
            break;
        }
    }
}

//Hàm kiểm tra hình nhập vào có khớp với hình mẫu hay không
bool soSanh(int A[][8], int n, float c1, float c2, float c3, float c4){
    float a1 = sqrt(pow(A[n][2] - A[n][0], 2) + pow(A[n][3] - A[n][1], 2));
    float a2 = sqrt(pow(A[n][4] - A[n][2], 2) + pow(A[n][5] - A[n][3], 2));
    float a3 = sqrt(pow(A[n][6] - A[n][4], 2) + pow(A[n][7] - A[n][5], 2));
    float a4 = sqrt(pow(A[n][0] - A[n][6], 2) + pow(A[n][1] - A[n][7], 2));

    if(a1 == c1 && a2 == c2 && a3 == c3 && a4 == c4)
        return true;
    else 
        return false;
}


int main(){
//Mảng M[8] chứa tọa độ các đỉnh của hình mẫu
//k là sô hình nhập vào
    int M[8], k; 
    for(int i = 0;i < 8; i++)
        scanf("%d", &M[i]);

//Độ dài các cạnh của hình mẫu
    float c1 = sqrt(pow(M[2] - M[0], 2) + pow(M[3] - M[1], 2));
    float c2 = sqrt(pow(M[4] - M[2], 2) + pow(M[5] - M[3], 2));
    float c3 = sqrt(pow(M[6] - M[4], 2) + pow(M[7] - M[5], 2));
    float c4 = sqrt(pow(M[0] - M[6], 2) + pow(M[1] - M[7], 2));

    scanf("%d", &k);
    int A[k][8];
    for(int i = 0; i < k; i++)
        for(int j = 0; j < 8; j++)
            scanf("%d", &A[i][j]);

    int count = 0;
    for(int i = 0; i < k; i++){
        if(soSanh(A, i, c1, c2, c3, c4) == true) {
            count++;
            continue;
        }
        else   
            swap(A, i);

        if(soSanh(A, i, c1, c2, c3, c4) == true) {
            count++;
            continue;
        }
        else   
            swap(A, i);

        if(soSanh(A, i, c1, c2, c3, c4) == true) {
            count++;
            continue;
        }
        else   
            swap(A, i);
    }
    printf("%d", count);
}