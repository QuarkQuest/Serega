#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int UI;
UI InputBV(char s[], int n) {
	UI x = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		x <<= 1;
		if (s[i] == '1')x++;
	}
	return x;
}
int Wieght(UI x, int n) {
	int w, i;
	UI mask = 1;
	for (w = 0, i = 0; i < n; i++, mask <<= 1) {
		if (x & mask)w++;
	}
	return w;
}
int SetUp1(UI x,int k) {
	UI mask = 1;
	mask <<= k;
	x |= mask;
	return x;
}
UI Invert(UI x, int k) {
	UI mask = 1;
	mask <<= k;
	x ^= mask;
	return x;
}
void OutputBV(UI x, int n) {
	UI mask = 1; int i;
	mask <<= n - 1;
	for (i = 0; i < n; i++, mask >>= 1) {
		if (x & mask)printf("1");
		else printf("0");
	}
}
void io(UI num,int n) {
	for (int i = n; i >= 0; --i)
		printf("%d", ((num >> i) & 1));
	printf("\n");
}
int main() {
	char s[99];
	int k;
	UI x;
	printf("input v: ");
	scanf("%s", &s);
	int n = strlen(s);
	printf("input k: ");
	scanf("%d", &k);
	printf("\n\n");
	x = InputBV(s, n);
	io(x, n - 1);
	x = SetUp1(x, k);
	io(x, n - 1);
	x = Invert(x, k+1);
	io(x, n - 1);

	printf("insert %d bit, and invert %d bit: ",k,k+1);
	io(x,n-1);
	printf("Weight V = %d", Wieght(x, n));
}