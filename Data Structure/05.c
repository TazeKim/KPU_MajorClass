
//��µ� note�� ������ ���� ����Ǿ� �ֽ��ϴ�.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define MAX(a,b) ((a>b)?a:b)

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* LL_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treeNode* RL_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

// ���� Ʈ���� ���̸� ���ϴ� ����
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// ���� Ʈ���� ���̸� �̿��� ���� �μ� BF�� ���ϴ� ����
int getBF(treeNode* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// BF�� �˻��Ͽ� �ұ����� �߻��� ���, ȸ�� ���� ȣ��
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);
	if (BF > 1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else    *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

// AVL Ʈ���� ��带 �����ϴ� ����: ���� Ž�� ����ó�� ������ �Ŀ�, rebalance() ȣ�� 
treeNode* insert_AVL_Node(treeNode** root, element x) {
	if (*root == NULL) {
		*root = (treeNode*)malloc(sizeof(treeNode));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key) {
		(*root)->left = insert_AVL_Node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x >(*root)->key) {
		(*root)->right = insert_AVL_Node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else {
		printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");
		exit(1);
	}
	return *root;
}

// ���� Ž�� Ʈ���� ��带 �����ϴ� ���� : [���� 7-4]�� 25~39��
treeNode* insert_BST_Node(treeNode *p, element x) {
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)  p->left = insert_BST_Node(p->left, x);
	else if (x > p->key)  p->right = insert_BST_Node(p->right, x);
	else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return p;
}

// ���� Ž�� Ʈ���� AVL Ʈ������ Ű�� x�� Ž���ϴ� ���� : [���� 7-4]�� 12~22�� ����
treeNode* searchTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->key) p = p->left;
		else if (x == p->key) {
			printf("Ž�� ����");
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("Ž�� ����! ã�� Ű�� �����ϴ�!");
	return 1;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ���� : [���� 7-4]�� 098~104��
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		printf("_%d ", root->key);
		displayInorder(root->right);
	}
}

int main() {
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;

	//////////////////////////////////////////////////////////////////
	root_AVL = insert_AVL_Node(&root_AVL, 2019130323); // AVL Ʈ�� �����
	insert_AVL_Node(&root_AVL, 2018152011);
	insert_AVL_Node(&root_AVL, 2018152017);
	insert_AVL_Node(&root_AVL, 2019130044);
	insert_AVL_Node(&root_AVL, 2017130042);
	insert_AVL_Node(&root_AVL, 2016140323);
	insert_AVL_Node(&root_AVL, 2015152011);
	insert_AVL_Node(&root_AVL, 2018153017);
	insert_AVL_Node(&root_AVL, 2017130045);
	insert_AVL_Node(&root_AVL, 2019101042);



	/////////////////////////////////////////////////////////////////////////////
	root_BST = insert_BST_Node(root_BST, 2019130323); //BST �����
	insert_BST_Node(root_BST, 2018152011);
	insert_BST_Node(root_BST, 2018152017);
	insert_BST_Node(root_BST, 2019130044);
	insert_BST_Node(root_BST, 2017130042);
	insert_BST_Node(root_BST, 2016140323);
	insert_BST_Node(root_BST, 2015152011);
	insert_BST_Node(root_BST, 2018153017);
	insert_BST_Node(root_BST, 2017130045);
	insert_BST_Node(root_BST, 2019101042);




	FILE* fp1;

	fp1 = fopen("AVL.txt", "wt");

	int num;
	treeNode* foundedNode = NULL;

	clock_t start, finish;
	double duration1, duration2;


	printf("AVL�� ����Ʈ���� Ž���� ��� �й� �Է� : ");
	scanf("%d", &num);



	start = clock();
	
	foundedNode = searchTree(root_AVL, num);
	if (foundedNode == 1)
	{
		return 0;
	}
	finish = clock();

	duration1 = (double)(finish - start) / CLOCKS_PER_SEC;

	fprintf(fp1,"�ɸ� �ð� : %lf��\n", duration1);
	system("notepad.exe AVL.txt");
	fclose(fp1);

	FILE* fp2;
	fp2 = fopen("BST.txt", "wt");

	start = clock();
	foundedNode = searchTree(root_BST, num);

	finish = clock();
	duration2 = (double)(finish - start) / CLOCKS_PER_SEC;

	fprintf(fp2, "�ɸ� �ð� : %lf��\n", duration2);
	system("notepad.exe BST.txt");
	fclose(fp2);
	
	if (duration1 < duration2)
	{
		printf("AVL�� BST���� %lf�� �� ����", duration2-duration1);
	}
	else
	{
		printf("BST�� AVL���� %lf�� �� ����", duration1 - duration2);
	}

	return 0;
}