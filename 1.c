#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int a[4000][4000], b[4000][4000], c[4000][4000], elem_c;
int main(void)
{
	setlocale(LC_ALL, "Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 4000)
	{
		while (j < 4000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 4000)
	{
		while (j < 4000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock(); // начало замера времени
	for (i = 0; i < 4000; i++)
	{
		for (j = 0; j < 4000; j++)
		{
			elem_c = 0;
			for (r = 0; r < 4000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock(); // конец замера времени
	double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Время выполнения программы: %f секунд\n", cpu_time_used);
	return(0);
}
