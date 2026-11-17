#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // Для русского языка

// Прототипы функций
float area_triangle(float a);
void print_definition(void);
void draw_triangle(int a);
void compare_triangles(float a1, float a2);

int main(void)
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	int choice;
	float a, a2;

	do
	{
		printf("\n================ МЕНЮ (Вариант 5) ================\n");
		printf("1. Рассчитать площадь треугольника\n");
		printf("2. Вывести определение фигуры\n");
		printf("3. Нарисовать контур треугольника (*)\n");
		printf("4. Сравнить две фигуры по площади\n");
		printf("0. Выход из программы\n");
		printf("Выберите пункт меню: ");
		if (scanf("%d", &choice) != 1) {
			break;
		}

		switch (choice)
		{
		case 1:
			printf("Введите размер катета a: ");
			scanf("%f", &a);
			printf("Площадь прямоугольного треугольника S = %.2f\n", area_triangle(a));
			break;

		case 2:
			print_definition();
			break;

		case 3:
			printf("Введите размер катета a (например 6): ");
			scanf("%f", &a);
			printf("\nКонтур фигуры:\n\n");
			draw_triangle((int)a);
			break;

		case 4:
			printf("Введите катет первого треугольника: ");
			scanf("%f", &a);
			printf("Введите катет второго треугольника: ");
			scanf("%f", &a2);
			compare_triangles(a, a2);
			break;

		case 0:
			printf("Выход из программы.\n");
			break;

		default:
			printf("Неверный пункт меню! Попробуйте снова.\n");
			break;
		}

	} while (choice != 0);

	return 0;
}

// 1. Вычисление площади: S = (a * b) / 2 = a^2 / 2
float area_triangle(float a)
{
	return 0.5f * a * a;
}

// 2. Определение фигуры
void print_definition(void)
{
	printf("\nОпределение:\n");
	printf("Прямоугольный равнобедренный (равносторонний) треугольник — это треугольник,\n");
	printf("у которого один угол прямой (90 градусов), а два катета равны между собой (a = b).\n");
}

// 3. Рисование контура треугольника символом '*'
void draw_triangle(int a)
{
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// Условие контура: катеты (j=1, i=a) или гипотенуза (j=i)
			if (j == 1 || j == i || i == a)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

// 4. Сравнение двух треугольников по площади
void compare_triangles(float a1, float a2)
{
	float s1 = area_triangle(a1);
	float s2 = area_triangle(a2);

	printf("\nПлощадь 1-й фигуры: %.2f\n", s1);
	printf("Площадь 2-й фигуры: %.2f\n", s2);
	printf("Разница площадей: %.2f\n", s1 - s2);
}