//add() �Լ��� ȣ���ϴ� main() �Լ��� ������ ����. �Ʒ��� �䱸������ �����ϴ� ���α׷�
//add() �Լ��� �ߺ� �ۼ�
#include<iostream>
using namespace std;

int add(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum = a[i]+ sum;
	return sum;
}
int add(int a[], int n, int b[]) {//�ߺ� �ۼ�
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum = sum + a[i] + b[i];
	return sum;
}


int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); // �迭 a�� ������ ��� ���� �� ����
	int d = add(a, 5, b); // �迭 a�� b�� ������ ��� ���� �� ����
	cout << c << endl; // 15 ���
	cout << d << endl; // 55���
}