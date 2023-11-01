#include <stdio.h>
#include <dlfcn.h>

int main() {
    int a = 10;
    int b = 5;
    int result = 0;

    void *handle = dlopen("./lib_Arithmetic.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "오류: %s\n", dlerror());
        return 1;
    }

    int (*add_func)(int, int) = dlsym(handle, "add");
    int (*sub_func)(int, int) = dlsym(handle, "sub");
    int (*mul_func)(int, int) = dlsym(handle, "mul");
    int (*div_func)(int, int) = dlsym(handle, "div");

    result = add_func(a, b);
    printf("더한 결과: %d\n", result);

    result = sub_func(a, b);
    printf("뺀 결과: %d\n", result);

    result = mul_func(a, b);
    printf("곱한 결과: %d\n", result);

    result = div_func(a, b);
    if (result == 0) {
        printf("0으로 나눌 수 없습니다.\n");
    } else {
        printf("나눗셈 결과: %d\n", result);
    }

    dlclose(handle);
    return 0;
}
