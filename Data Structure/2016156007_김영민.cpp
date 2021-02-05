
//����ü �迭 ��� ���� ��� ������ ���� ���Ḯ��Ʈ�� ���� �Ͽ����ϴ�.
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

typedef int element;		// ���� Ž�� Ʈ�� element�� �ڷ����� char�� ����

typedef struct treeNode {
	char name[10];
	int num;
	int guk;
	int eng;
	int math;

	double v;
	char hak;
	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;


// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertNode(treeNode *p, int x, char* n, int g, int e, int m) {
	treeNode *newNode;
	double average;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->num = x;
		strcpy(newNode->name, n);
		newNode->guk = g;
		newNode->eng = e;
		newNode->math = m;

		newNode->v = (g + e + m) / 3;

		if (newNode->v >= 90)
			newNode->hak = 'A';
		else if (newNode->v >= 80)
			newNode->hak = 'B';
		else if (newNode->v >= 70)
			newNode->hak = 'c';
		else
			newNode->hak = 'F';


		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->num)  p->left = insertNode(p->left, x, n, g, e, m);
	else if (x > p->num)  p->right = insertNode(p->right, x, n, g, e, m);
	else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}


void deleteNode(treeNode *root, element num) {
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->num != num)) {
		parent = p;
		if (num < p->num) p = p->left;
		else p = p->right;
	}


	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}


	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}


	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)  succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->num = succ->num;
		p = succ;
	}
	free(p);
}


void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);

		printf("%s ", root->name);
		printf("%d ", root->num);
		printf("%.1lf ", root->v);
		printf("%c\n", root->hak);

		displayInorder(root->right);
	}
}

void menu() {
	printf("(1) �߰� (2) ���� (3) ���� (4) ��� (5) ����\n");

}

int main() {

	treeNode* root = NULL;
	treeNode* foundedNode = NULL;



	char choice;
	char name[10];
	int num;
	int guk;
	int eng;
	int math;



	while (1) {
		menu();
		scanf_s(" %d", &choice);

		switch (choice) {
		case 1:
			printf("�л� ������ �Է��ϼ���.\n");

			printf("�й� : ");
			scanf_s("%d", &num);
			printf("�̸� : ");
			scanf("%s", name);
			printf("���� : ");
			scanf_s("%d", &guk);
			printf("���� : ");
			scanf_s("%d", &eng);
			printf("���� : ");
			scanf_s("%d", &math);


			if (root == NULL) {
				root = insertNode(root, num, name, guk, eng, math);
			}
			else {
				insertNode(root, num, name, guk, eng, math);
			}

			break;

		case 2:	printf("������ �й��� �Է��ϼ��� : ");//�̸� �Էµ��� ��� ������ ���� �й����� �����Ͽ����ϴ�.
			scanf_s("%d", &num);
			deleteNode(root, num);

			printf("�й� : ");
			scanf_s("%d", &num);
			printf("�̸� : ");
			scanf("%s", name);
			printf("���� : ");
			scanf_s("%d", &guk);
			printf("���� : ");
			scanf_s("%d", &eng);
			printf("���� : ");
			scanf_s("%d", &math);

			if (root == NULL) {
				root = insertNode(root, num, name, guk, eng, math);
			}
			else {
				insertNode(root, num, name, guk, eng, math);
			}

			break;

		case 3:	printf("������ �й��� �Է��ϼ��� : ");
			scanf_s("%d", &num);
			deleteNode(root, num);
			break;

		case 4:
			displayInorder(root);


			break;

		case 5:
			printf("�����մϴ�.\n");

			return 0;
		default: printf("���� �޴��Դϴ�. �ٽ� �����ϼ���. \n");
			break;
		}
	}
}