#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void screen() {
	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("=========================USE ADT COMMAND===================================\n");
	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("+ :                                              push() ===================\n");
	printf("L :                                             print() ===================\n");
	printf("-- :                                              pop() ===================\n");
	printf("F :                                           is_full() ===================\n");
	printf("P :                                              peek() ===================\n");
	printf("T :                                               top() ===================\n");
	printf("= :                                           replace() ===================\n");
	printf("C :                                             clear() ===================\n");
	printf("? :                                         is_member() ===================\n");
	printf("# :                                     element_count() ===================\n");
	printf("Q:                                                 Quit ===================\n");
	printf("===========================================================================\n\n");
}

// Stack ����� Stack ����.

typedef struct _stackNode {
	char element;
	struct _stackNode* preNode;
}Node;

typedef struct _Stack {
	Node* top;
	int capacity; // ������ ũ��
	int len;
}Stack;

//ADT ����
void creatStack();
void push(Stack* stack,char data);
void print(Stack* stack);
void peek(Stack* stack);
void pop(Stack* stack);
void is_full(Stack* stack);
void element_count(Stack* stack);
void top(Stack* stack);
void is_member(Stack* stack);
void replace(Stack* stack,char data);
void clear(Stack* stack);
void double_pop(Stack* stack);
void triple_pop(Stack* stack);
//â�� ��� 1�� �߰��ؾ���.

//main �Լ�
int main(void){
	Stack* myStack =(Stack*)malloc(sizeof(Node)); //���� ����
	myStack->top = NULL;
	myStack->len = 0;

	screen(); // ����

	int bIterFlag = 1;
	int i = 0;
	char judge[30];

	while (bIterFlag) {
		printf("��ɾ �Է��ϼ��� : ");
		fget(judge, 30, stdin);
		while()
		switch (judge[i]) {
		case '+':
			if (judge[i + 2] == '\0') {
				push(myStack, judge[i + 1]);
				break;
			}
			push(myStack, judge[i + 1]);
			i++;
			break;
		case 'L':
			break;
		case 'P':
			break;
		case '-':
			break;
		case 'F':
			break;
		case '?':
			break;
		case 'C':
			break;
		}
	}
}

//�Լ� ����
void creatStack() {
	Stack* mystack = malloc(sizeof(Node*));
	mystack->len = 0;
	mystack->top = NULL;
	mystack->capacity = 30;
	return mystack;
}
void push(Stack* stack,char data) {
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->element = data;
	newNode->preNode = NULL;

	Node* tmp = malloc(sizeof(Node*));
	if (stack == NULL) {
		stack->top = newNode;
		stack->len++;
		return;
	}
	tmp = stack->top;
	stack->top = newNode;
	stack->top->preNode = tmp;
	free(tmp);
}
void print(Stack* stack) {
	Stack* tmpStack = (Stack*)malloc(sizeof(Node*));
	tmpStack->top = NULL;
	tmpStack->len = 0;

	Node* tmpNode = malloc(sizeof(Node*));
	tmpNode = stack->top;

	for (int i = 0; i < stack->len;i++) {
		push(tmpStack, tmpNode->element);
		tmpNode = tmpNode->preNode;
		tmpStack->len++;
	}

	tmpNode = tmpStack->top;
	for (int j = 0;j < stack->len; j++) {
		printf("%c ", tmpNode);
		tmpNode = tmpNode->preNode;
	}
	printf('\n');
	free(tmpNode);
	free(tmpStack);
}
void peek(Stack* stack) {
	if (stack->top != NULL) printf("���� ������ TOP���� %c�� �ֽ��ϴ� ! ", stack->top);
	else printf("���� ������ ����ֽ��ϴ� !");
}
void pop(Stack* stack) {
	printf(" %c �� POP �Ǿ����ϴ� !\n", stack->top->element);
	stack->top = stack->top->preNode;
	stack->len--;
}
void is_full(Stack* stack) {
	if (stack->len >= stack->capacity) printf("TRUE!!\n");
	else printf("FALSE!!\n");
}
void element_count(Stack* stack) {
	printf("������ ũ��� %d �Դϴ� ! \n", stack->len);
}
void top(Stack* stack) {
	printf("TOP ���̴� %d , TOP�� ELEMENT�� %c �Դϴ�! \n", stack->len, stack -> top->element);
}
void is_member(Stack* stack,char data) {
	Stack* tmpStack = malloc(sizeof(Node*));
	tmpStack->top = NULL;
	tmpStack->len = 0;
	tmpStack->capacity = 30;

	Node* tmpNode = malloc(sizeof(Node*));
	tmpNode = stack->top;

	for (int i = 0; i < stack->len;i++) {
		push(tmpStack, tmpNode->element);
		tmpNode = tmpNode->preNode;
		tmpStack->len++;
		if (tmpNode->element == data) {
			return printf("True!!! \n");
		}
	}
	return printf("False!!!\n");
}
void replace(Stack* stack,char data) {
	stack->top->element = data;
}
void clear(Stack* stack) {
	stack->top = NULL;
	stack->len = 0;
}
void double_pop(Stack* stack) {

}
void triple_pop(Stack* stack) {

}
