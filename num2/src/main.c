#include <stdio.h>

extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);
extern double div(int a, int b);

int main() {
    int a = 10, b = 5;
    int result;

    result = add(a, b);
    printf("덧셈 결과: %d\n", result);

    result = sub(a, b);
    printf("뺄셈 결과: %d\n", result);

    result = mul(a, b);
    printf("곱셈 결과: %d\n", result);

    double div_result = div(a, b);
    if (div_result == 0.0) {
        printf("나눗셈 오류: 0으로 나눌 수 없음\n");
    } else {
        printf("나눗셈 결과: %.2f\n", div_result);
    }

    return 0;
}
