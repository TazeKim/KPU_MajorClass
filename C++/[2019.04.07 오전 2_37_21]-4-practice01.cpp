// year�� 10���� �ʱ�ȭ�ϴ� �����ڿ� year ���� �����ϴ� getYear() ����
class Calendar {
private:
	int year;
public:
	Calendar();
	int getYear();
};

Calendar::Calendar() {         //������ ����
	year = 10;
}

int Calendar::getYear() {      //getYear() ����
	return year;

}