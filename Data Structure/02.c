#include <stdio.h>
#include <malloc.h>

typedef int element;     // ���� ť ����(element)�� �ڷ����� char�� ����
typedef struct QNode {    // ���� ť�� ��带 ����ü�� ����
	element data;
	struct QNode *link;
} QNode;

typedef struct {		// ���� ť���� ����ϴ� ������ front�� rear�� ����ü�� ����
	QNode *front, *rear;	//�����ͷ� �����߱� ������ ���� ������ ���� ������ ����.
} LQueueType;

// ���� ���� ť�� �����ϴ� ����
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}


// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// ���� ���� ť�� ���� ������ ���
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// ���� ���� ť�� ���� ���°� �ƴ� ���
		LQ->rear->link = newNode;		// A ť �ο� Bť�� �̾��ش�.
		LQ->rear = newNode;			//rear�� Bť�� ����Ų��.
	}
}


void main(void) {

	LQueueType *LQ = createLinkedQueue();  // ���� ť ����
	element data;
	int num = 1;
	int p, tmp = 0;
	int price;

	while (1) {
		printf("%d ��° �մ� ǥ ���� ���� : ", num);
		scanf("%d", &p);
		if (p < 0)
		{
			price = tmp * 9000;
			printf("\n���� ���� : %d�� �Ǹ�, ���� %d��\n", tmp, price);
			return 0;
		}

		enQueue(LQ, p);
		num++;
		tmp = p + tmp;
	}


}