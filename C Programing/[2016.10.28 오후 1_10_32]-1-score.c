#include<stdio.h>
int main(void){
	int i, total = 0;
	int scores[10];

	for(i =0; i<10 ; i++)
	{
		scanf("%d",&scores[i]);
		total=total+scores[i];
	}
	printf("���� : %d",total);

	printf("��� : %.2lf",(double)total/10);

	return 0;


}