//���̸� �˷��ִ� TowerŬ������ �ۼ�
#include <iostream>
using namespace std;
class Tower {
	int high;
public:
	Tower();//������(�޴� ���ڰ� ������)
	Tower(int h);//������(�޴� ���ڰ� ������)
	int getHeight();
};
Tower:: Tower(){
	high = 1;
}
Tower::Tower(int h) {
	high = h;
}
int Tower::getHeight() {
	return high;
}
int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
	system("pause");
}