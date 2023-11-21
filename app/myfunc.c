#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "myfunc.h"

void myfunc(double* roots, double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
	roots[0] = NAN;
	roots[1] = NAN;
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
	roots[1] = NAN;
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
	roots[0] = root1;
	roots[1] = root2;
    }
}
int val;

int fibonachi(int num) {
    int prev = 1;
    int next = 1;

    if (num < 0)
        return 0;

    if (num <= 2)
        return num;

    int i = 2;
    while (i < num) {
        next += prev;
        prev = next - prev;
        i++;
    }

    return next;
}

void printStdoutMessages() {
    printf("This is a test message from myfunc.c\n");
    printf("Do not disturb\n");
}
