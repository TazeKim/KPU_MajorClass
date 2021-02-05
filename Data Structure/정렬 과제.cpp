#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_SIZE 100;
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )


// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char name[10];
	int age;
	struct ListNode* link;
} listNode;

typedef struct Indexnumber {
	int num;
	struct ListNode* link;
}Index;


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



// ���� ����Ʈ�� ������� ����ϴ� ����
void printList( Index *in) {
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("%d", in[i].num);
		printf("%s ", in[i].link->name);
		printf("%d\n", in[i].link->age);
	
	}
}

// ù ��° ���� �����ϴ� ����
void insertFirstNode(linkedList_h *L ,char *x, int a) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// ������ �� ��� �Ҵ�
	strcpy(newNode->name, x);						// �� ����� ������ �ʵ忡 x ����  
	newNode->age = a;
	newNode->link = L->head;
	L->head = newNode;
}





void selection_sort(Index *list, int n)
{
	int i, j, least;
	Index temp;
	for (i = 0; i<n - 1; i++) {
		least = i;
		for (j = i + 1; j<n; j++) // �ּڰ� Ž��
			if (list[j].num<list[least].num) least = j;
		SWAP(list[i].num, list[least].num, temp.num);
	}
}
void linkindex(linkedList_h *L, Index in, int n)
{
	
}

int main(void)
{
	Index in[10];

	linkedList_h* L;
	L = createLinkedList_h();


	printf("(1) ���� ����Ʈ �����ϱ�! \n");


	insertFirstNode(L, "������", 20);
	in[0].num = 2;
	in[0].link = L->head;
	insertFirstNode(L, "������", 21);
	in[1].num = 4;
	in[1].link = L->head;
	insertFirstNode(L, "����", 22);
	in[2].num = 6;
	in[2].link = L->head;
	insertFirstNode(L, "�ٴٴ�", 22);
	in[3].num = 8;
	in[3].link = L->head;
	insertFirstNode(L, "����", 22);
	in[4].num = 10;
	in[4].link = L->head;
	insertFirstNode(L, "������", 22);
	in[5].num = 9;
	in[5].link = L->head;
	insertFirstNode(L, "�ٹٹ�", 22);
	in[6].num = 7;
	in[6].link = L->head;
	insertFirstNode(L, "����", 22);
	in[7].num = 5;
	in[7].link = L->head;
	insertFirstNode(L, "�ƾƾ�", 22);
	in[8].num = 3;
	in[8].link = L->head;
	insertFirstNode(L, "������", 22);
	in[9].num = 1;
	in[9].link = L->head;

	printf("���� ��\n");
	printList(in);

	selection_sort(in, 10);
	printf("���� ��\n");
	printList(in);


}