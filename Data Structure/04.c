#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include <time.h>

typedef int element;		// ���� Ž�� Ʈ�� element�� �ڷ����� char�� ����
typedef struct treeNode {
	int num;
	char name[10];
	int age;
	double grade;
	char soge[30];
	clock_t start, finish;
	double duration;

	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, int x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->num) p = p->left;
		else if (x == p->num) return p;
		else p = p->right;
	}
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertNode(treeNode *p, int x, char *n, int a, double g, char *s) {
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->num = x;
		strcpy(newNode->name, n);
		newNode->age = a;
		newNode->grade = g;
		strcpy(newNode->soge, s);
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;				//�� �ڵ��� �ǹ̴� ���� �Ʒ��� p->right�� ���ο� ��带 �߰��ϱ� ����
	}
	else if (x < p->num)  p->left = insertNode(p->left, x, n, a, g, s);  //��Ʈ���� ���� ������ ���
	else if (x > p->num)  p->right = insertNode(p->right, x, n, a, g, s);//��Ʈ���� ���� ������ ���
	else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;		//�ٽ� p�� return ���ִ� ������ ��� ȣ�� ���ͽÿ� p->right�� �����͸� �Է�
}

//2019130323
//2018152011
//2018152017
//2019130044
//2017130042
//2016140323
//2015152011
//2018153017
//2017130045
//2019101042
//�Է�

int main() {
	FILE* fp;

	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char choice;
	int num, number;
	int n = 0;
	char name[10];
	int age;
	double grade;
	char soge[30];

	clock_t start, finish;
	double duration;

	char tmp[15];

	int a=0;
	while (a < 10)
	{
		printf("Ʈ���� �ۼ��� �й��� 10�� �Է��ϼ��� : ");
		scanf("%d", &n);
		sprintf(tmp, "%d", n);

		strcat(tmp, ".txt");//�й�.txt

		if (fopen(tmp, "rt") == NULL)
		{
			printf("�߸� �Է� �ϼ̽��ϴ�.\n");
			return 0;
		}
		fp = fopen(tmp, "rt");

		fscanf(fp, "%s %d %d %d %s", name, &number, &age, &grade, soge);
		if (root == NULL) {
			root = insertNode(root, number, name, age, grade, soge);
		}
		else {
			insertNode(root, number, name, age, grade, soge);
		}
		a++;
	}

	char note1[30] = "notepad.exe ";
	char tmp1[15];

	printf("Ž���� ��� �й� �Է� : ");
	scanf("%d", &num);

	sprintf(tmp1, "%d", num);

	strcat(tmp1, ".txt");//�й�.txt
	strcat(note1, tmp1);//notepad.exe �й�.txt

	//if (fopen(tmp, "rt") == NULL)
	//{
	//	printf("ã�� �й� ����\n");
	//	return 0;
	//}
	//fp = fopen(tmp, "rt");

	//fscanf(fp, "%s %d %d %d %s", name, &number, &age, &grade, soge);

	start = clock();
	foundedNode = searchBST(root, root->num);
	if (foundedNode != NULL)
		printf("�й� Ž�� ����\n");
	else  printf("ã�� �й� ����\n");
	
	finish = clock();
	system(note1);
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	printf("�ɸ� �ð� : %lf��\n", duration);

	fclose(fp);

	return 0;
}