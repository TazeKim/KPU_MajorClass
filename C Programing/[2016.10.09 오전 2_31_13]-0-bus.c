#include<stdio.h>

int main() {
	char ch;
	int age;
	int charge;

	printf("�л��Դϱ�? (y/n) : ");
	scanf("%c", &ch);
	printf("���̴� : ");
	scanf("%d", &age);

	if (age >= 65)
		charge = 0;
	else if (age < 12)
		charge = 600;
	else if (ch == 'y')
		charge = 1000;
	else if (age < 65 && age>11)
		charge = 1000;
	else
		charge = 1200;

	printf("����� %d �Դϴ�.", charge);

	return 0;
}