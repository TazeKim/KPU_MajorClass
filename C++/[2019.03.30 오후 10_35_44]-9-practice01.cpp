//�ݺ����� �̿��ؼ� �����Ҷ����� �ϳ��� �þ�� *���
#include <iostream>
using namespace std;
int main()
{
	int i,j; //���� for�� ���� ����
	for (i = 1 ; i < 6 ; i++)//���� for��
	{
		for (j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << "\n";//�� ���� ����ϸ� ����
	}
}
