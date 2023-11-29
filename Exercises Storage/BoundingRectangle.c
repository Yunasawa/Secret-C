/*
Description
    Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất bao tất cả các 
    hình chữ nhật trong danh sách trên
    Dữ liệu
    · Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
    · Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) là tọa độ 2 đỉnh 
    đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
Kết quả
    · Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
Ví dụ
Dữ liệu
    3
    2 4 2 7
    3 2 4 7
    1 2 5 2
Kết quả
    20
*/

#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    int x1, y1, x2, y2;
    int min_x = 1000, min_y = 1000, max_x = 0, max_y = 0;
    
    for(int i = 0; i < n; i++) 
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 < min_x) min_x = x1;
        if(x2 < min_x) min_x = x2;
        if(y1 < min_y) min_y = y1;
        if(y2 < min_y) min_y = y2;
        if(x1 > max_x) max_x = x1;
        if(x2 > max_x) max_x = x2;
        if(y1 > max_y) max_y = y1;
        if(y2 > max_y) max_y = y2;
    }
    
    int area = (max_x - min_x) * (max_y - min_y);
    printf("%d\n", area);
    
    return 0;
}