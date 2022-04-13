#include <stdio.h>
#include <limits.h>
int book[4] = { { 0x00 },
		{ 0x1d },
		{ 0x16 },
		{ 0x1b } };



int Coder(int i) {
		if (i >= 0 && i < 4)
			return book[i];
		else;
			return -1;
}

int Channel(int n, int e) {
	int b = n ^ e;
	return b;
}

int weight(int num) {
	int i = 0;
	while (num > 0) {
		i = i + (num & 1);
		num = num >> 1;
	}
	return i;
}

void hamming_metic_min(int b) {
	int min = INT_MAX;
	int tmp = 0;
	int d[4] = { 0 };
	int count = 0;

	for (int i = 0; i < 4; i++) {
		tmp = b ^ book[i];
		d[i] = weight(tmp);
	}
	for (int i = 0; i < 4; i++)
		printf("Hamming_metric[%d] = %d \n", i, d[i]);

	for (int i = 0; i < 3; i++) {
		if (min > d[i]) {
			min = d[i];
		}
	}

	printf("Minimal Hamming metric = %d \n", min);
}


int main() {
	int e = 17;
	int first = Coder(2);
	int second = Channel(first, e);
	hamming_metic_min(second);
}


