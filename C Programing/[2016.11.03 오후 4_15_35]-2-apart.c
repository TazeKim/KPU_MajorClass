#include<stdio.h>
int main(){
	int array[3][3];
	int i,j;
	int total=0;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d�� %dȣ ������ �� ���Դϱ�?: ",i+1,j+1);
			scanf("%d",&array[i][j]);
			total+=array[i][j];

		}
	}
	printf("��������Ʈ �� �α����� %d���Դϴ�.\n",total);
	return 0;
}