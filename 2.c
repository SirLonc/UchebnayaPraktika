#include <stdio.h>


int func(unsigned int a) {
	int n[] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };
	int s = 0;


	while (a > 0) {
		s += n[a & 15];
		a >>= 4;
	}

	return s;
}



int main() {
	unsigned int a = 7;
	printf("%d", func(a));
}