#include<stdio.h>
int main(){

int a,b;

printf("�� �� �Է� : ");
scanf("%d",&a);
scanf("%d",&b);

if(a>b){
	printf("ū ���� %d�Դϴ�.\n",a);
}
else if(a<b){
	printf("ū ���� %d�Դϴ�.\n",b);
}
else if(a==b){
	printf("�� ���� �����ϴ�.\n");
}

return 0;

}