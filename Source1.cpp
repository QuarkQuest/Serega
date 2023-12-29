#pragma warning (disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
void output(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	int max = Max(n, m);
	int** a;
	a = (int**)calloc(max,sizeof(int*));
	for (int i = 0; i < max; i++) {
		a[i] = (int*)calloc(max,sizeof(int));
	}
	srand(time(NULL));
	if (n != m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 1 + rand() % 100;
			}
		}
		output(a, n, m);
		for (int i = 0; i < max; i++) {
			for (int j = i + 1; j < max; j++) {
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
		output(a, m, n);
		
	}
	else {
		for (int i = 0; i < max; i++) {
			for (int j = 0; j < max; j++) {
				a[i][j] = 1 + rand() % 100;
			}
		}
		output(a, n, m);
		for (int i = 0; i < max; i++) {
			for (int j = i + 1; j < max; j++) {
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
		output(a, n, m);
	
	}

	for (int i = 0; i < max; i++) {
		free(a[i]);
	}
	free(a);
}