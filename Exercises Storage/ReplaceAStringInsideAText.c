/*
Description
    Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
    Dữ liệu
    · Dòng 1: xâu P1
    · Dòng 2: xâu P2
    · Dòng 3: văn bản T
Kết quả:
    · Ghi văn bản T sau khi thay thế
Ví dụ
Dữ liệu
    AI
    Artificial Intelligence
    Recently, AI is a key technology. AI enable efficient operations in many fields.
Kết quả
    Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() 
{
    char P1[MAX_LENGTH], P2[MAX_LENGTH], T[MAX_LENGTH];
    fgets(P1, MAX_LENGTH, stdin);
    fgets(P2, MAX_LENGTH, stdin);
    fgets(T, MAX_LENGTH, stdin);

    int len_P1 = strlen(P1) - 1;
    int len_P2 = strlen(P2) - 1;
    int len_T = strlen(T) - 1;

    for (int i = 0; i < len_T; i++) 
    {
        if (strncmp(&T[i], P1, len_P1) == 0) 
        {
            printf("%s", P2);
            i += len_P1 - 1;
        } 
        else 
        {
            printf("%c", T[i]);
        }
    }

    return 0;
}
