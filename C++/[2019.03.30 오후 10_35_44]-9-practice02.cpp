//cout�� << �����ڸ� �̿��Ͽ� ������ ���� �������� ����ϴ� ���α׷�
#include<iostream>
using namespace std;

int main()
{
	int i, j; //���� for�� ���� ����
	for (i = 1; i < 10; i++)//���� for��
	{
		for (j = 1; j < 10; j++)
		{
			cout << j << "*" << i << "=" << i * j<<"\t";//���� �� ������ �и�
		}
		cout << "\n";// ����
	}

}
