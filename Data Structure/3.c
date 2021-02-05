#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;		// ���� ���(element)�� �ڷ����� char�� ����

typedef struct  stackNode {	// ������ ��带 ����ü�� ����
	element data;
	struct stackNode *link;
} stackNode;

stackNode* top;				// ������ top ��带 �����ϱ� ���� ������ top ����

// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;		// ���� ��带 top�� ���� ����
	top = temp;				// top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ ��ȣ�� �˻��ϴ� ����
int testPair(char *exp) {
	int cnt=0;
	char symbol, open_pair;
	// char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			// (1) ���� ��ȣ�� ���ÿ� ����
		case '(':
		case '[':
		case '{':
			push(symbol); break;
		case '"':
			if (cnt == 1)
			{
				cnt = 0;
				open_pair = pop();
				if ((open_pair == '"' && symbol != '"')) {

					return 0;
				}
				else break;
			}
			else {
				push(symbol);
				cnt++;
				break;
			}
			// (2) ������ ��ȣ�� ������,
		case ')':
		case ']':
		case '}':
			if (top == NULL) return 0;
			else {
				// (2)-1 ���ÿ��� ���������� ���� ��ȣ�� ����
				open_pair = pop();
				// (2)-2 ��ȣ ���� �´��� �˻�
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}') || 
					(open_pair == '"' && symbol != '"'))
					// (2)-3 ��ȣ ���� Ʋ���� ���� ����
					return 0;
				// (2)-4 ��ȣ ���� ������ ���� symbol �˻縦 �����
				else break;
			}
		}
	}
	if (top == NULL) return 1;// ���� �˻縦 ��ģ �� ������ �����̸� 1�� ��ȯ
	else return 0;            // ������ �ƴϸ� 0�� ��ȯ(���� ��ȣ Ʋ��)
}

void main(void) {
	FILE* fp,*fp1;
	fp = fopen("3-1.txt", "rt");
	fp1 = fopen("3-2.txt", "at+");
	int id;
	char check[30];

	while (!feof(fp)) {
		fscanf(fp, "%d %s",&id, check);
		
		if (testPair(check) == 1) {
			fprintf(stdout, "%02d OK\n",id);
			fprintf(fp1, "%02d OK\n", id);
			getchar();
		}
		else {
			fprintf(stdout, "%02d NOK\n", id);
			fprintf(fp1, "%02d NOK\n", id);
			getchar();
		}
	}
	
	fclose(fp);
	fclose(fp1);
	system("notepad.exe 3-2.txt");
}



