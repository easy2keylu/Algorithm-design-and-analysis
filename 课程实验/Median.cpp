#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int median(int a[], int b[], int a_low, int a_high, int b_low, int b_high) {
	if (a_low == a_high) {
		return a[a_low];
	}
	else if (b_low == b_high) {
		return b[b_low];
	}

	int a_mid, b_mid;
	a_mid = (a_low + a_high) / 2;
	b_mid = (b_low + b_high) / 2;

	if (a[a_mid] > b[b_mid]) {
		a_high = a_mid;
		b_low = b_mid;
	}
	else if (a[a_mid] < b[b_mid]) {
		a_low = a_mid;
		b_high = b_mid;
	}
	else {
		return a[a_mid];
	}
	median(a, b, a_low, a_high, b_low, b_high);
}

int main()
{
	FILE *fr, *fw;
	int m[100], n[100];
	int i, j, k;
	if ((fr = fopen("D:\\input.txt", "r")) == NULL)
	{
		printf("Failed to open the file");
	}
	if ((fw = fopen("D:\\output.txt", "w")) == NULL)
	{
		printf("Failed to open the file");
	}
	fscanf(fr, "%d", &k);
	for (i = 0; i < k; i++)
		fscanf(fr, "%d", &m[i]);
	for (i = 0; i < k; i++)
		fscanf(fr, "%d", &n[i]);
	i = median(m, n, 0, k - 1, 0, k - 1);
	fprintf(fw, "%d", i);
	return 0;
}