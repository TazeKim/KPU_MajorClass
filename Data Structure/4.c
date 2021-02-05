#pragma warning (disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CL_SIZE 10;

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	int id;
	char data[15];
	int searchNum;
	struct ListNode* link;
} listNode;

//struct ListNode* p[1000];
int structCnt = 0;

// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
} linkedList_h;


// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));   // ��� ��� �Ҵ�
	CL->head = NULL;                              // ���� ����Ʈ�̹Ƿ� NULL�� ����
	return CL;
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* CL, FILE* fp) {
	listNode* p;
	p = CL->head;
	do {
		fprintf(stdout, "%d %s %d\n", p->id, p->data, p->searchNum);
		fprintf(fp, "%d %s %d\n", p->id, p->data, p->searchNum);
		p = p->link;

	} while (p != CL->head);
}

// ù ��° ��� ���� ����
void insertFirstNode(linkedList_h *CL, char* x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));   // ������ �� ��� �Ҵ�
	strcpy(newNode->data, x);	//���ĺ� �Է�
	if (CL->head == NULL) {      // ���� ���� ����Ʈ�� ������ ���   
		CL->head = newNode;      // �� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode;
	}
	else {                  // ���� ���� ����Ʈ�� ������ �ƴ� ���    
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;   // ������ ��带 ù ��° ����� new�� ���� ���� 
		CL->head = newNode;
	}
}

// pre �ڿ� ��带 �����ϴ� ����
void insertMiddleNode(linkedList_h* CL, listNode *pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));		
	strcpy(newNode->data, x);	//���ĺ� �Է�
	newNode->searchNum = 0;		//searchNum 0 ���� �ʱ�ȭ
	if (CL->head == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else if (pre == NULL)      //Ž���� ���� ������ �� pre�� NULL�� ��쵵 �߰��Ͽ���
	{
		return;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// ���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ����
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;               // ������ ����� ������ ��带 ��Ÿ���� ������   
	if (CL->head == NULL) return;   // ���� ����Ʈ�� ���, ���� ���� �ߴ�   
	if (CL->head->link == NULL) {   // ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(CL->head);            // ù ��° ����� �޸𸮸� �����ϰ�
		CL->head = NULL;            // ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (old == NULL) return;   // ������ ��尡 ���� ���, ���� ���� �ߴ�   
	else {
		pre = CL->head;            // ������ pre�� ����Ʈ�� ���� ��忡 ����      
		while (pre->link != old) {
			pre = pre->link;         // ������ ��带 ������ pre�� �̿��� ã��
		}
		pre->link = old->link;
		if (old == CL->head)
			CL->head = old->link;
		free(old);               // ���� ����� �޸𸮸� ����          
	}
}

// ���� ���� ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode *temp;
	temp = CL->head;

	if (strcmp(temp->data, x) == 0) //ó���� temp!=NULL�̾��µ� ���� ã�� ��尡 ���ٸ� ���ѹݺ��� �Ǳ⶧���� �ڵ带 ������
		return temp;
	else temp = temp->link;

	while (temp != CL->head) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	temp = NULL;
	return temp;   //ã�°��� ������� NULL��ȯ
}

void Input(linkedList_h* CL, FILE* fp1);
void searchalp(linkedList_h* CL, FILE* fp2, char * search);
int main()
{
	FILE* fp;
	linkedList_h* CL;
	CL = createLinkedList_h();
	ListNode* p;
	p = (listNode*)malloc(sizeof(listNode));
	p = CL->head;

	printf("���ĺ� ����\n");
	char alpha[2] = "a";
	insertFirstNode(CL, alpha);
	for (int i = 0; i < CL_SIZE i++)
	{
		p = searchNode(CL, alpha);
		alpha[0] = alpha[0] + 1;
		insertMiddleNode(CL, p, alpha);
	}

	int chose;
	while (true)
	{
		printf("1. �������� �ܾ��� ���� 2. ����");
		scanf("%d", &chose);
		if (chose == 1)
		{
			srand((unsigned)time(NULL));
			int y;
			y = rand();
			y = rand() % CL_SIZE;
			char note[20] = "notepad.exe ";
			char txt[10] = ".txt";
			char alp1[2] = "a";
			char alp2[10] = "a";
			alp1[0] = alp1[0] + y;
			alp2[0] = alp2[0] + y;
			strcat(note, alp1);
			strcat(note, txt);
			system(note);

			strcat(alp2, ".txt");// ex)a.txt �ҷ�����

			fp = fopen(alp2, "at+");
			
			
			fclose(fp);
		}
		else if (chose == 2)
		{
			printf("���α׷��� �����մϴ�.");
			break;

		}
	}
}

//void Input(linkedList_h* CL, FILE* fp1)
//{
//	FILE* fp2;
//	fp2 = fopen("allAlpha.txt", "at+");
//	int id, searchNum = 0;
//	char alphabet[15];
//	ListNode* p, *pre;
//	p = (listNode*)malloc(sizeof(listNode));
//	p = CL->head;
//
//	pre = NULL;
//	structCnt = 0;
//	while (!feof(fp1))
//	{
//		fscanf(fp1, "%d %s", &id, alphabet);
//		insertMiddleNode(CL, pre, id, alphabet, searchNum);
//		pre = searchNode(CL, alphabet);
//		structCnt++;
//	}
//	printList(CL, fp2);			//���� ���Ḯ��Ʈ ���
//
//	fprintf(fp2, "�ܾ��� ���� : %d\n", structCnt);
//	fprintf(stdout, "�ܾ��� ���� : %d\n", structCnt);
//	fprintf(fp2, "-----------------------\n");
//	fclose(fp2);
//	printf("---------------------------\n");
//}