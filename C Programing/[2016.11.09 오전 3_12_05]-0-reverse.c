#include<stdio.h>
	int main(){
		int i;
		int ary[5] = { 1, 2, 3, 4, 5 };
		printf("ó�� �� : ");
		for (i = 0;i < 5;i++) {
			printf("%d", ary[i]);
		}
		printf("\n");
		printf("���� �� : ");
		for (i = 4;i >= 0;i--) {
			printf("%d", ary[i]);
		}
		printf("\n");
}