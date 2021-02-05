#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE  8

typedef int element;		// ť ����(element)�� �ڷ����� char�� ����
typedef struct {
	element queue[cQ_SIZE];	// 1���� �迭 ť ����
	int front, rear;
} QueueType;

QueueType *createQueue() {
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;       // front �ʱ갪 ����
	cQ->rear = 0;        // rear �ʱ갪 ����
	return cQ;
}



// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType *cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front) {		//����ť�̱� ������ ������ ���� Ȱ��
		printf("  Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType *cQ, element item) {
	if (isFull(cQ))	return;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;		//���� ť�̱⶧���� �� �ڵ� Ȱ���ϱ�
		cQ->queue[cQ->rear] = item;
	}
}







void main(void) {
	QueueType *cQ = createQueue();  // ť ����
	element data;
	int num=1;
	int p, tmp=0;
	int price;
	while(1) {
		printf("%d ��° �մ� ǥ ���� ���� : ", num);
		scanf("%d", &p);
		if (p < 0)
		{
			price = tmp * 9000;
			printf("\n���� ���� : %d�� �Ǹ�, ���� %d��\n", tmp, price);
			return 0;
		}

		enQueue(cQ, p);
		num++;
		tmp = p + tmp;
	}
	
}