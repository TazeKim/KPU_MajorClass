//�Ҽ����� ������ 5���� �Ǽ��� �Է� �޾� ���� ū ���� ȭ�鿡 ����ϴ� ���α׷�
#include<iostream>
using namespace std;


int main()
{
	double num[5];//�Է��� �Ǽ��� ������ �迭 ����
	int i;//for�� ���� ����
	
	cout << "�Ǽ� 5�� �Է�\n>> ";
	for(i = 0; i < 5;i++ )
	{
		cin >> num[i];//i�� �Է��� �Ǽ� ����
	}
	i = 0;//i�� �ʱ�ȭ


	double max ;
	max = num[0];//�ִ��� �������� max���� ����

	for (i = 0; i < sizeof(num)/sizeof(double); i++)//sizeof(num)/sizeof(double)�� ����ϸ� 5
	{
		if (num[i] > max)//num�� max������ ũ�� max�� num�� �־��ش�.
		{
			max = num[i];
		}
	}
	
	cout << "�ִ��� " << max << "�Դϴ�.";

	return 0;
}
