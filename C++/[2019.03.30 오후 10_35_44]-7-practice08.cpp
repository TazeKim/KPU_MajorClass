//�߽Ĵ��� �ֹ������� ���α׷����� ����
#include<iostream>
using namespace std;

int main()
{
	cout << "***** ������� ���� ���� ȯ���մϴ�. ***** \n";
	int menu,num;//manu : �޴��� ���� ���ڸ� ������ ���� //num : �� �κ����� ����

	while (1) {
		cout << "«�� : 1, ¥�� : 2, ������ : 3, ���� : 4 >>";//�޴� ����
		cin >> menu;
	
		if (menu == 4)//if ������ �б⸦ ������ �޴��� ���� ��� ����
		{
			cout << "���� ������ �������ϴ�.\n";
			return 0;
		}
		if (menu == 1)
		{
			cout << "�� �κ�? : ";
			cin >> num;
			cout << "«�� " << num << "�κ� ���Խ��ϴ�\n";
		}
		else if (menu == 2)
		{
			cout << "�� �κ�? : ";
			cin >> num;
			cout << "¥�� " << num << "�κ� ���Խ��ϴ�\n";
		}
		else if (menu == 3)
		{
			cout << "�� �κ�? : ";
			cin >> num;
			cout << "������ " << num << "�κ� ���Խ��ϴ�\n";
		}
		else if (menu!=1||2||3||4)//���� ������ ���
		{
			cout << "�ٽ� �ֹ��ϼ���!!\n";
		}

	}
}