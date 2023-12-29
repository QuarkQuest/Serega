#pragma warning (disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Max(int a, int b) {//������� ����������� ���������
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
void output(int** a, int n, int m) {//������� ������ �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int randomized(int** a,int n,int m) {//������� ���������� ���������� �������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 1 + rand() % 100;
		}
	}
	return **a;
}
int transport(int n,int m,int **a) {//������� ���������������� �������
	/*
	��������� ����� ������� � �������� �� ������ ��������� ��������� �� ���� 
	��� ��� �� ������ ������ i,j ������� �� j,i ������� 
	|1|2|3|		 |1|4|7|
	|4|5|6| -->  |2|5|8|
	|7|8|9|		 |3|6|9|
	2 �� 4, 3 �� 7, 8 �� 6
	*/
	int max = Max(n, m);
	if (n != m) {
		for (int i = 0; i < max; i++) {
			for (int j = i + 1; j < max; j++) {
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
	else {
		for (int i = 0; i < max; i++) {
			for (int j = i + 1; j < max; j++) {
				int temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}

	}
	return **a;
}
int main() {
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	/*
	������ �������� �������� �������� ��� ���������� ������,
	�� ����� ��� ������������� ������� ������ ��������� ���������� ������� 
	���� ���� ������� ������������� (����� �������� ������������� ���������������
	� �� �������������� ����� ���������� � ������� ������� calloc)
	colloc - ��� �� malloc ������ ���������� �������������� ���� ������ ������
	*/
	int max = Max(n, m);
	int** a;
	a = (int**)calloc(max,sizeof(int*));
	for (int i = 0; i < max; i++) {
		a[i] = (int*)calloc(max,sizeof(int));
	}
	srand(time(NULL));
	randomized(a, n, m);
	output(a, n, m);
	transport(n, m, a);
	output(a, m, n);

	for (int i = 0; i < max; i++) {
		free(a[i]);
	}
	free(a);
}