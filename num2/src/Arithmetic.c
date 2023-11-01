int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

double div(int a, int b) {
    if (b == 0) {
        return 0.0;
    }
    return (double)a / b;
}

