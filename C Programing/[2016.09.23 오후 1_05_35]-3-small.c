#include<stdio.h>

int main(){
int a,b ,c;
printf("ù��° ���� �Է� : ");
scanf("%d",&a);

printf("�ι�° ���� �Է� : ");
scanf("%d",&b);

c=(a>b)?b : a ;
(a!=b)? printf("�� ���� ���� : %d",c) : printf("����");

return 0;

}