#include<stdio.h>
int main(){
	int array[5];
	int i,min,max;
	printf("input : ");

	for(i=0;i<5;i++){
		scanf("%d",&array[i]);
	}
    max=array[0];
	min=array[0];
	for(i=0;i<5;i++){
		if(array[i]>=max){
			max=array[i];
		}
		else if(array[i]<=min){
			min=array[i];
		}
	}

	printf("�ִ� : %d\n",max);
	printf("�ּҰ� : %d\n",min);
	return 0;
}