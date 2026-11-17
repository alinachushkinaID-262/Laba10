#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // Для стандартной функции sin() и fabs()
#include <windows.h> // Для поддержки русского языка

// Объявление функции (прототип)
double sin_n(double x, int N);

int main(void)
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	double x;
	int N;

	printf("=== Задание 1. Вычисление sin(x) через ряд Маклорена ===\n");
	printf("Введите значение x (в радианах) и число членов N: ");
	if (scanf("%lf %d", &x, &N) != 2 || N <= 0) {
		printf("Ошибка ввода данных!\n");
		return 1;
	}

	double my_sin = sin_n(x, N);
	double math_sin = sin(x);

	printf("\nРезультаты:\n");
	printf("sin_n(x) [по ряду, N=%d] = %.8lf\n", N, my_sin);
	printf("sin(x) [из math.h] = %.8lf\n", math_sin);
	printf("Абсолютная погрешность = %.2e\n", fabs(my_sin - math_sin));

	return 0;
}

// Реализация функции sin_n
double sin_n(double x, int N)
{
	double term = x; // Первый член ряда при n = 0
	double sum = term;

	for (int n = 1; n < N; n++)
	{
		// Рекуррентная формула: домножаем на -x^2 / ((2n)*(2n+1))
		term *= -x * x / ((2 * n) * (2 * n + 1));
		sum += term;
	}

	return sum;
}
