#include <stdio.h>
#include <stdlib.h>

#include "myfunc.h"

int main(int argc, char *argv[])
{
    if (argc != 4) {
	printf("Используйте: %s x y z\n", argv[0]);
	return 1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    if (a == 0.0 || b == 0.0 || c == 0.0) {
	printf("Введите целые и/или дробные числа, отличные от нуля\n");
	return 1;
    }

    double* roots = (double*)malloc(2 * sizeof(double));
    myfunc(roots, a, b, c);
    printf("Корни уравнения: %.2f, %.2f\n\n", roots[0], roots[1]);
    free(roots);

    int fib_a = fibonachi((int)a);
    int fib_b = fibonachi((int)b);
    int fib_c = fibonachi((int)c);
    printf("Числа Фибоначчи по порядковому номеру:\na(%.2f) - %d\nb(%.2f) - %d\nc(%.2f) - %d\n", a, fib_a, b, fib_b, c, fib_c);
    return 0;
}
