#include <stdio.h>
#include <math.h>

double F1(double x) {
    return exp(x) + log(x) - 10 * x;
}

double F2(double x) {
    return cos(x) - exp(-pow(x, 2) / 2) + x - 1;
}

double f1(double x) {
    return log(10*x-log(x));
}

double f2(double x) {
    return 1 + exp(-pow(x, 2) / 2) - cos(x);
}

double F1_1(double x) {
    return exp(x) + 1 / x - 10;
}

double F2_1(double x) {
    return -sin(x) + x * exp(-pow(x, 2) / 2) + 1;
}

double dth(double f(double), double a, double b, double eps) {
    double x;
    while (fabs(a - b) > eps) {
        x = (a + b) / 2;
        if (f(x) * f(a) < 0) {
            b = x;
        } else {
            a = x;
        }
    }
    return (a+b)/2;
}

double itter(double f(double), double a, double b, double eps) {
    double x = (a + b) / 2;
    while (fabs(f(x) - x) > eps) {
        x = f(x);
    }
    return x;
}

double newton(double F(double), double F1(double), double a, double b, double eps) {
    double x = (a + b / 2);
    while (fabs(F(x) / F1(x)) > eps) {
        x -= F(x)/F1(x);
    }
    return x;
}
void ans(double F(double), double F1(double), double f(double), double a, double b, double eps){
    printf("Корень, полученный методом дихотомии: %11.7f\n", dth(F, a, b, eps));
    printf("Корень, полученный методом итераций: %11.7f\n", itter(f, a, b, eps));
    printf("Корень, полученный методом Ньютона: %11.7f\n", newton(F, F1, a, b, eps));
}
int main() {
    double eps = 1;
    while (1 + eps/2 > 1){
        eps /= 2;
    }
    printf("Функция exp(x) + ln(x) - 10x\n");
    ans(F1, F1_1, f1, 3, 4, eps);
    printf("Функция cos(x) - exp(-0.5*x^2) + x - 1\n");
    ans(F2, F2_1, f2, 1, 2, eps);
    return 0;
}