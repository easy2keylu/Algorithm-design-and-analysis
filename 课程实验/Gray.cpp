#include<stdio.h>
#include<math.h>


void Gray(int n, int arry[][100])
{
	int a = pow(2, n);
	int b = a / 2;
	if (n == 1)
	{
		arry[0][0] = 0;
		arry[1][0] = 1;
	}
	else {
		int c = n - 1;
		Gray(c, arry);
		for (int i = 0; i < pow(2, c); i++)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				arry[i][j + 1] = arry[i][j];
			}
		}
		int q = pow(2, n) - 1;
		for (int i = 0; i < pow(2, c); i++)
		{
			for (int j = 1; j < c + 1; j++)
			{
				arry[q - i][j] = (arry[i][j] + 2) % 2;
			}
		}
		for (int i = 0; i < b; i++)
			arry[i][0] = 0;
		for (int i = a - 1; i >= b; i--)
			arry[i][0] = 1;
	}
}

int main() {
	FILE *fr, *fw;
	int n, a;
	if ((fr = fopen("D:\\input.txt", "r")) == NULL)
	{
		printf("Failed to open the file");
	}
	if ((fw = fopen("D:\\output.txt", "w")) == NULL)
	{
		printf("Failed to open the file");
	}
	fscanf(fr,"%d", &n);
	a = pow(2, n);
	int c = n;
	int d = a;
	int arry[100][100] = { 0 };
	Gray(n, arry);
	int u = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fprintf(fw,"%d ", arry[i][j]);
			u++;
			if (u%c == 0)
		        fprintf(fw,"\n");
		}
	}
	return 0;
}