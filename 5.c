#include <stdio.h>

int book[4] = { { 0x00 },
{ 0x1d },
{ 0x16 },
{ 0x1b } };

int Coder(int i) {
	if (i >= 0 && i < 4)
		return book[i];
	else
		return -1;
}

int channel(int a, int e) {
	int b = a ^ e;
	return b;
}

int main() {
	int e = 17; // 10001
	int m = 2;
	int a = Coder(m);

	int b = channel(a, e);
	/* if(a != -1)
	for (int i = 0; i < 5; i++) {
	printf("%d", a & 1);
	a »= 1;
	}
	else{
	printf("Error");
	}*/
	printf("\nm = %d", m);
	printf("\na = %d", a);
	printf("\nb = %d", b);
	return 0;
}