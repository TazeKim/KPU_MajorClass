//�Լ� big()�� ȣ���ϴ� ���α׷�
// big() �Լ��� 2�� �ߺ��Ͽ� �ۼ�

#include<iostream>
using namespace std;

int big(int a, int b)
{
	int x;
	x = (a > b) ? a : b;
	return (x < 100) ? x : 100;
}
int big(int a, int b, int m)//�ߺ� �ۼ�
{
	int x;
	x = (a > b) ? a : b;
	return (x < m) ? x : m;
}



int main() {
	int x = big(3, 5); // 3�� 5 �� ū �� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
	int y = big(300, 60); // 300�� 60 �� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
	int z = big(30, 60, 50); // 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
	cout << x << ' ' << y << ' ' << z << endl;
}