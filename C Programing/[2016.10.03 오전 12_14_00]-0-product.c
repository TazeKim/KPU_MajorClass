#include<stdio.h>

int main() {


	int a, count = 0;
	int b;

	printf("���� ���� �Է� : ");
	scanf("%d", &b);

	a = b;

	while (a <= 100) {
		printf("%3d\n", a);
		
	
		a = a + b;
		count++;
		
	}
	printf("%d�� ���� : %d\n", b, count);

	return 0;
}