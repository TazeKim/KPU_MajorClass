//main() �Լ��� ����ǵ��� Point Ŭ������ ��ӹ޴� ColorPoint Ŭ������ �ۼ�, ��ü ���α׷� �ϼ�
#include <iostream>
#include <string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point { // point Ŭ���� ���
	string name;
public:
	ColorPoint() : Point(0, 0) { name = "BLACK"; }			
	ColorPoint(int x, int y) : Point(x, y) { name = "BLACK"; }
	void setPoint(int x, int y) { move(x, y); }		//private�� �����ϱ� ����
	void setColor(string name) { this->name = name; }//private�� �����ϱ� ����
	void show() { cout << name << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl; }
};
int main() {
	ColorPoint zeroPoint; // BLACK ���� (0, 0) ��ġ�� ��
	zeroPoint.show(); // zeroPoint�� ����Ѵ�.
	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp�� ����Ѵ�.
}