#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a == b)
		return true;
	else if (a > b) {
		big = a;
		return false;
	}
	else if (a < b)
	{
		big = b;
		return false;
	}
	
}

int main()
{
	int num1, num2;
	int big;
	cout << "�� ���� ������ �Է����ּ���>>";
	cin >> num1 >> num2;
	if (bigger(num1, num2, big))
	{
		cout << "a�� b�� �����ϴ�." << endl;
	}
	else
	{
		cout << "�� ū��>>" << big << endl;
	}

}