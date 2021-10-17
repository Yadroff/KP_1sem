/* Курсовой проект. Задание №3. Вариант 28.
 * Студент группы 08-101 А.Ядров*/
#include <stdio.h>
#include <math.h>

int main() {
    double ans, f;
    double eps = 1.0;
    while (1 + eps / 2 > 1) eps /= 2;
    int n, cnt;
    printf("Машинное эпсилон для типа double в системе CLion = %.16e\n", eps);
    int k = 43;
    printf("Введите число n\n");
    scanf("%d", &n);
    printf("n = %d, \n", n);
    double l = M_PI / 5;
    double r = 6 * M_PI / 5;
    printf("Таблица значений ряда Тейлора и стандартной функции для f(x) = -ln|2*sin(x/2)|\n");
    printf("___________________________________________________________________\n");
    printf("|   x  |         sum         |      f(x)          |число итераций|\n");
    printf("___________________________________________________________________\n");
    double x = 0;
    for (int i = 1; i <= n+1; i++) {
        double d = 1;
        x += (r - l)/n;
        ans = 0;
        cnt = 1;
        f = -log(fabs(2 * sin(x / 2)));
        while (fabs(d) > eps * k && cnt < 100) {
            d = cos(cnt * x) / cnt;
            ans += d;
            cnt++;
        }
        printf("| %.2f | %.16f | %.16f |      %d       |\n", x, ans, f, cnt);
        printf("___________________________________________________________________\n");
    }
    return 0;
}