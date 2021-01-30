//BaseArray�� ��ӹ޾� ťó�� �۵��ϴ� MyQueue Ŭ������ �ۼ�
#include <iostream>
using namespace std;
class BaseArray {
private:
	int capacity; // �迭�� ũ��
	int *mem; // ���� �迭�� ����� ���� �޸��� ������
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray {
	int enqindex;		//���Կ� �ʿ��� �ε���
	int deindex;		//������ �ʿ��� �ε���
public:
	MyQueue(int size) : BaseArray(size) { enqindex = 0; deindex = -1; }
	void enqueue(int n) {
		put(enqindex, n);
		enqindex++;
	}
	int capacity() { return getCapacity(); }
	int length() { return enqindex; }
	int dequeue() {
		enqindex--;
		deindex++; return get(deindex);
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; ++i) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ����ũ�� : " << mQ.length() << endl;
}