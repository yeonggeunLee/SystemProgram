#include <stdio.h>

extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);
extern int div(int a, int b);

int main() {
    int a = 10;
    int b = 5;
    int result = 0;

    result = add(a, b);
    printf("더한 결과 : %d\n", result);

    result = sub(a, b);
    printf("뺀 결과: %d\n", result);

    result = mul(a, b);
    printf("곱한 결과: %d\n", result);

    result = div(a, b);
    if (result == 0) {
        printf("0으로 나눌 수 없습니다.\n");
    } else {
        printf("나눗셈 결과: %d\n", result);
    }

    return 0;
}

