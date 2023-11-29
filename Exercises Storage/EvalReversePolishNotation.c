/*
Description
    Viết chương trình tính biểu thức toán học được biểu diễn dưới dạng Reverse Polish Notation (RPN).
    Giới hạn:
    Toán hạng: số nguyên dương 01 chữ số từ '0' đến '9'
    Toán tử: '+' và '*' (chú ý phép nhân thực hiện trước)
Định dạng đầu vào và đầu ra:
    Đầu vào: chuỗi kí tự chứa các toán hạng và toán tử theo định dạng postfix (RPN). Các toán tử và toán hạng cách nhau 01 khoảng trắng. Không có khoảng trắng bắt đầu và kết thúc.
    Đầu ra: kết quả dạng số nguyên
Ví dụ 1:
    Đầu vào: 2 3 * 9 +
    Đầu ra: 15
Ví dụ 2:
    Đầu vào: 2 3 9 * +
    Đầu ra: 29
Thuật toán chi tiết tham khảo ở đây: https://isaaccomputerscience.org/concepts/dsa_toc_rpn?examBoard=all&stage=all
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char input[100];
    int i, a, b, result;

    fgets(input, 100, stdin);

    for (i = 0; input[i] != '\n'; i++) {
        if (isdigit(input[i])) {
            push(input[i] - '0');
        } else if (input[i] == '+') {
            a = pop();
            b = pop();
            push(a + b);
        } else if (input[i] == '*') {
            a = pop();
            b = pop();
            push(a * b);
        }
    }

    result = pop();

    printf("%d\n", result);

    return 0;
}
