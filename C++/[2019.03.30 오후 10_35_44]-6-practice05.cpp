// "yes"�� �Էµ� ������ ������� �ʴ� ���α׷�
#include<iostream>
#include<string>//string Ŭ������ ����ϱ� ���� ��� ����
using namespace std;
int main()
{
	string answer;
	int a=0;
	string want_answer("yes");//���ڿ� want_answer
	while (1)//while�� ���ѷ���
	{
		cout << "�����ϰ������ yes�� �Է��ϼ���.>> ";
		
		getline(cin, answer);//getline()���� string Ÿ���� ���ڿ��� �Է�

		if (answer == want_answer) {
			break;//�����̸� ���ѷ��� ����

		}

	}
	cout << "�����մϴ�...";

}
