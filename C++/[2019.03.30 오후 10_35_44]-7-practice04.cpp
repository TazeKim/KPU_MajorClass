//Ű������ Enter Ű�� �Էµ� ������ ���ڵ��� �а�
//�Էµ� ���ڿ����� ���� 'x'�� ������ ȭ�鿡 ����ϴ� ���α׷�
#include<iostream>
using namespace std;
int main() {
	cout << "���� �Է�(100�� �̸�) : ";
	char letter[100];//���ڿ��� �־��� ������ 100�� �迭 letter����

	cin.getline(letter, 100, '\n');//�ִ� 99���ǹ��ڸ��о� letter�迭�� �����ϰ� ���߿� <Enter> Ű�������� �Է� �ߴ�
	
	int i,count=0;//for���� ���� ���� i ���� ,count�� x�� ���� ����
	for (i = 0; letter[i] != '\0'; i++)//�ι��ڸ� ������ �ߴ��ϴ� for��
	{
		if (letter[i] == 'x')
			count++;//x�� ���� ����
	}
	
	cout << "x�� ������ " << count << "�� �Դϴ�.";
}