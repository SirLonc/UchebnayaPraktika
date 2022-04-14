#include <stdio.h>
#include <limits.h>

int book[4] = { { 0x00 },//00000
{ 0x0d },//01101
{ 0x16 },//10110
{ 0x1b }};//11011

int weight(int num) {
	int i = 0;
	while (num > 0) {
		i = i + (num & 1);
		num = num >> 1;
	}
	return i;
}

void print_num(int a) {
	for (int i = 0; i < 5; i++) {
		printf("%d", a & 1);
		a >>= 1;
	}
}

int Coder(int i) {
	if (i >= 0 && i < 4)
		return book[i];
	else
		return -1;
}

int Channel(int n, int e) {
	int b = n ^ e;
	return b;
}

int Decoder(int b) {
	printf("b = %d\n", b);
	int tmp = 0;
	int d[4] = { 0 };
	int count = 0;
	
	for (int i = 0; i < 4; i++) {
		tmp = b ^ book[i];
		d[i] = weight(tmp);
	}
	for (int i = 0; i < 4; i++)
		printf("Hamming_metric[%d] = %d \n", i, d[i]);

	
	int min = INT_MAX;
	int i_min;
	for (int i = 0; i < 4; i++) {
		if (d[i] < min) {
			min = d[i];
			i_min = i;
			printf("%d %d \n", min, i_min);
		}
	}
	return i_min;
}


int main()
{
	int e = 17;
	int errors[5] = { 0 };
	int num = 0;



	int result = Coder(3);
	int result_2 = Channel(result, e);
	int result_3 = Decoder(result_2);
	if (result != -1)
	{
		print_num(result);
		printf("\n");
		print_num(e);
		printf("\n");
		print_num(result_2);
		printf("\n");
		print_num(result_3);
	}
	else
		printf("ERROR");
	if ((weight(e) == 1) && (result_3 == num))
		errors[0]++;
	else if ((weight(e) == 2) && (result_3 == num))
		errors[1]++;
	else if ((weight(e) == 3) && (result_3 == num))
		errors[2]++;
	else if ((weight(e) == 4) && (result_3 == num))
		errors[3]++;
	else if ((weight(e) == 5) && (result_3 == num))
		errors[4]++;
	for (int k = 0; k < 5; k++) {
		printf("\n %d errors = %d", k + 1, errors[k]);
	}

	return 0;
}
