#include<iostream>
using namespace std;

char& find(char a[], char c, bool& success)
{
	int cnt;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == c)
		{
			success = true;
			cnt = i;
		}
		
	}
	return a[cnt];
}



int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
		return 0;
	}
	loc = 'm'; // 'M' ��ġ�� 'm' ���
	cout << s << endl; // "mike"�� ��µ�
}