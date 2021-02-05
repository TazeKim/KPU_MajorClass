//���� �ȵ�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996) //scanf_s() �Ǵ� printf_s()�� ������� �ʾƼ� �߻��ϴ� ������ �����ϴ� �ڵ�
#include <time.h>




// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	int a;
	int b;
	struct ListNode* link;
} listNode;

// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
} linkedList_h;

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}


////////////////////////////////////////////////////////////////////
// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* L) {
	listNode* p;


	p = L->head;
	while (p != NULL) {
		printf("(%d,%d)", p->a, p->b);

		p = p->link;
	}


	// ù ��° ���� �����ϴ� ����
	void insertFirstNode(linkedList_h *L, int x, int y) {
		listNode* newNode;
		newNode = (listNode*)malloc(sizeof(listNode));	// ������ �� ��� �Ҵ�
		newNode->a = x;		// �� ����� ������ �ʵ忡 x ���� 
		newNode->b = y;
		newNode->link = L->head;
		L->head = newNode;
	}

	// ��带 pre �ڿ� �����ϴ� ����
	void insertMiddleNode(linkedList_h* L, listNode *pre, int x, int y) {
		listNode* newNode;
		newNode = (listNode*)malloc(sizeof(listNode));
		newNode->a = x;		// �� ����� ������ �ʵ忡 x ���� 
		newNode->b = y;
		if (L == NULL) {				// ���� ����Ʈ�� ���
			newNode->link = NULL;		// �� ��带 ù ��°���� ������ ���� ����
			L->head = newNode;
		}
		else if (pre == NULL) {			// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
			L->head = newNode;			// �� ��带 ù ��° ���� ����
		}
		else {
			newNode->link = pre->link;	// ������ pre�� ��� �ڿ� �� ��� ����
			pre->link = newNode;
		}
	}

	// ������ ���� �����ϴ� ���� 
	void insertLastNode(linkedList_h* L, int x, int y) {
		listNode* newNode;
		listNode* temp;
		newNode = (listNode*)malloc(sizeof(listNode));
		newNode->a = x;		// �� ����� ������ �ʵ忡 x ���� 
		newNode->b = y;
		newNode->link = NULL;
		if (L->head == NULL) {		// ���� ����Ʈ�� ������ ���					
			L->head = newNode;		// �� ��带 ����Ʈ�� ���� ���� ����
			return;
		}
		// ���� ����Ʈ�� ������ �ƴ� ��� 	
		temp = L->head;
		while (temp->link != NULL) temp = temp->link;	// ���� ����Ʈ�� ������ ��带 ã��
		temp->link = newNode;							// �� ��带 ������ ���(temp)�� ���� ���� ���� 
	}


	listNode* searchNode(linkedList_h* L, int x, int y) {
		listNode *temp;
		temp = L->head;
		while (temp != NULL) {
			if (temp->a == x && temp->b == y) return temp;
			else temp = temp->link;
		}
		return temp;
	}


	int main()
	{
		

		linkedList_h* L;
		L = createLinkedList_h();
		clock_t start, finish;
		double duration;
		int n, datl, datr;
		listNode *p;
		FILE* fp;
		fp = fopen("1.txt", "at+");

		start = clock();


		insertFirstNode(L, 0, 0);

		p = searchNode(L, 0, 0);
		while (1) {
			fprintf(stdout, "������ �Ͻðڽ��ϱ�? 1: ��ǥ ���� 2 : ��ǥ ���� ����\n");
			scanf("%d", &n);
			
			if (n == 1)
			{
				fprintf(stdout, "(0,0)���� (5,5)������ ������ ��ǥ �Ҵ�\n");
				scanf("%d %d", &datl, &datr);
				insertMiddleNode(L, p, datl, datr);
			}
			else if (n == 2) {
				printf("���� ����\n");

				break;
			}
			else
			{
				printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
			}
		}

		insertLastNode(L, 5, 5);

		printList(L); getchar();

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		fprintf(stdout, "�ɸ� �ð� : %lf\n", duration);
		fprintf(fp, "�ɸ� �ð� : %lf\n", duration);
		getchar();


		fprintf(stdout, "ù��° ��忡 ���ο� ��� 5�� ����\n");
		start = clock();

		for (int i = 0; i < 5; i++)
		{
			scanf("%d %d", &datl, &datr);
			insertFirstNode(L, datl, datr);
			printList(L); getchar();
		}
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		fprintf(stdout, "�ɸ� �ð� : %lf\n", duration);
		fprintf(fp, "�ɸ� �ð� : %lf\n", duration);
		getchar();




		fprintf(stdout, "�߰���� ��ġ�� ��� 5�� ����\n");

		start = clock();
		p = searchNode(L, 0, 0);
		for (int i = 0; i < 5; i++)
		{
			scanf("%d %d", &datl, &datr);
			insertMiddleNode(L, p, datl, datr);
			printList(L); getchar();
		}
		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		fprintf(stdout, "�ɸ� �ð� : %lf\n", duration);
		fprintf(fp, "�ɸ� �ð� : %lf\n", duration);




		fprintf(stdout, "������ ��� ��ġ�� ��� 5�� ����\n");
		start = clock();
		for (int i = 0; i < 5; i++)
		{
			scanf("%d %d", &datl, &datr);
			insertLastNode(L, datl, datr);
			printList(L); getchar();
		}

		finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		fprintf(stdout, "�ɸ� �ð� : %lf\n", duration);
		fprintf(fp, "�ɸ� �ð� : %lf\n", duration);

		fclose(fp);
		system("notepad.exe 1.txt");
		getchar();

		return 0;
	}