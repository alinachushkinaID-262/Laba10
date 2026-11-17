#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // Для функции log() и fabs()
#include <windows.h> // Для русского языка

// Прототипы функций
double ln_n(double x, int N);
double ln_eps(double x, double eps);

int main(void)
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	double x, eps;
	int N;

	printf("=== Задание 2 (Вариант 5). Разложение функции ln(x) ===\n");
	printf("Введите x (x > 0), число членов N и точность eps (например 1e-6): ");
	if (scanf("%lf %d %lf", &x, &N, &eps) != 3 || x <= 0.0 || N <= 0 || eps <= 0.0) {
		printf("Ошибка: x, N и eps должны быть строго положительными числами!\n");
		return 1;
	}

	double res_n = ln_n(x, N);
	double res_eps = ln_eps(x, eps);
	double res_math = log(x);

	printf("\nРезультаты вычислений:\n");
	printf("ln_n(x, %d) = %.8lf (отклонение: %.2e)\n", N, res_n, fabs(res_n - res_math));
	printf("ln_eps(x, eps) = %.8lf (отклонение: %.2e)\n", res_eps, fabs(res_eps - res_math));
	printf("Точный log(x) = %.8lf\n", res_math);

	return 0;
}

// 1. Вычисление по заданному количеству членов N
double ln_n(double x, int N)
{
	double z = (x - 1.0) / (x + 1.0);
	double z2 = z * z;
	double u = z; // u = z^(2n+1)
	double sum = 0.0;

	for (int n = 0; n < N; n++)
	{
		sum += u / (2 * n + 1);
		u *= z2; // Шаг к следующей нечетной степени
	}

	return 2.0 * sum;
}

// 2. Вычисление с заданной пользователем точностью eps
double ln_eps(double x, double eps)
{
	double z = (x - 1.0) / (x + 1.0);
	double z2 = z * z;
	double u = z;
	double sum = 0.0;
	double term;
	int n = 0;

	do
	{
		term = u / (2 * n + 1);
		sum += term;
		u *= z2;
		n++;
	} while (fabs(2.0 * term) > eps);

	return 2.0 * sum;
}
