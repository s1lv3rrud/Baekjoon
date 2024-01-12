#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int a, b, c, i, j, k, mul;
	int count[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	mul = a * b * c;
	while (mul != 0) {
		count[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", count[i]);
	}

	return 0;
}