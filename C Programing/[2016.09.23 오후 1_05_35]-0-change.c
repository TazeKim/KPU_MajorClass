#include<stdio.h>

int main(){
	int mon , price , ob , b ,os , s;

	printf("���� �� �Է� : ");
	scanf("%d",&mon);
	printf("����� �� �Է� : ");
	scanf("%d",&price);

	ob = (mon - price)/500;
	b = (mon - price)%500/100;
	os = (mon - price)%500%100/50;
	s = (mon - price)%500%100%50/10;

	printf("500�� : %d , 100�� : %d , 50�� : %d , 10�� :%d ",ob,b,os,s);


return 0;
}