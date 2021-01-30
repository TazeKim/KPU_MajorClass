// += ������ �Լ��� ����Լ��� ����, -= ������ �Լ��� �����带 �̿��� �ܺ� �Լ��� ����
#include <iostream>
#include <string>
using namespace std;
class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	Book& operator +=(int price);
	friend Book operator-=(Book& op2, int price);
};

Book& Book::operator+=(int price)
{
	this->price += price;
	return *this;
}


Book operator-=(Book &op2,int price) { //&op2
    op2.price -= price;
    return op2;
}



int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; // å a�� ���� 500�� ����
	b -= 500; // å b�� ���� 500�� ����
	a.show();
	b.show();
}