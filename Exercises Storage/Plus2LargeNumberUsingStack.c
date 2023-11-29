#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], sum[100];
    int carry = 0, i;

    scanf("%s %s", a, b);

    int len_a = strlen(a), len_b = strlen(b);

    int max_len = len_a > len_b ? len_a : len_b;

    for (i = 0; i < max_len; i++) {
        int digit_a = i < len_a ? a[len_a - 1 - i] - '0' : 0;
        int digit_b = i < len_b ? b[len_b - 1 - i] - '0' : 0;

        int digit_sum = digit_a + digit_b + carry;

        sum[max_len - 1 - i] = digit_sum % 10 + '0';
        carry = digit_sum / 10;
    }

    if (carry > 0) {
        sum[max_len] = carry + '0';
        sum[max_len + 1] = '\0';
    } else {
        sum[max_len] = '\0';
    }

    printf("%s\n", sum);

    return 0;
}
