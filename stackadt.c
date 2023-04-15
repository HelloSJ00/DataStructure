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
	printf("D:                                           double_pop ===================\n");
	printf("T:                                           triple_pop ===================\n");
	printf("Q:                                                 Quit ===================\n");
	printf("===========================================================================\n\n");
}

// Stack 노드 정의 Stack 정의

typedef struct _stackNode {
	char element;
	struct _stackNode* preNode;
}Node;

typedef struct _Stack {
	Node* top;
	int capacity; // 스택의 크기
	int len;
}Stack;

//ADT 선언
void creatStack();
void push(Stack* stack,char data);
void print(Stack* stack);
void peek(Stack* stack);
void pop(Stack* stack);
void is_full(Stack* stack);
void element_count(Stack* stack);
void top(Stack* stack);
void is_member(Stack* stack,char data);
void replace(Stack* stack,char data);
void clear(Stack* stack);
void double_pop(Stack* stack); // 창작기능1 - 한번에 두개를 POP 
void triple_pop(Stack* stack); // 창작기능2 - 한번에 세개를 POP
void all_pop(Stack* stack); // 창작기능3 - 스택의 모든 노드를 POP

//main 함수
int main(){
	Stack* myStack =(Stack*)malloc(30*sizeof(Node)); //크기 30 스택 생성
	myStack->top = NULL;
	myStack->len = 0;
    myStack->capacity = 30;

	screen(); 

	int bIterFlag = 1;
	int i = 0;
	char judge[30];

	while (bIterFlag) {
		printf("명령어를 입력하세요 : ");
		fgets(judge,sizeof(judge),stdin);
		switch (judge[i]) {
		case '+': //오류
			while(1){
				if (judge[i]=='+'){
					if (judge[i + 2] == '\0') {
					push(myStack, judge[i + 1]);
					break;
					}
				push(myStack, judge[i + 1]);
				}
				i++;
			}
			break;
		case 'L':
			print(myStack);
			break;
		case 'P':
			peek(myStack);
			break;
		case '-':
			pop(myStack);
			break;
		case 'F':
			is_full(myStack);
			break;
		case '?':
			is_member(myStack,judge[i+1]);
			break;
		case 'C':
			clear(myStack);
			break;
		case '=':
			replace(myStack,judge[i+1]);
			break;
		case '#':
			element_count(myStack);
			break;
		case 'D':
			double_pop(myStack);
			break;
		case 'T':
			triple_pop(myStack);
			break;
		case 'A':
			all_pop(myStack);
			break;
		case 'Q':
			return 0;
		}
	}
}

//함수 정의
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
	if (stack->top==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	Stack* tmpStack = (Stack*)malloc(sizeof(Node*)); // 임시 스택
	tmpStack->top = NULL;
	tmpStack->len = 0;

	Node* tmpNode = malloc(sizeof(Node*)); // 임시 노드+
	tmpNode = stack->top;

	for (int i = 0; i < stack->len;i++) {
		push(tmpStack, tmpNode->element);
		tmpNode = tmpNode->preNode;
		tmpStack->len++;
	}

	tmpNode = tmpStack->top;
	for (int j = 0;j < stack->len; j++) {
		printf("%c ", tmpNode->element);
		tmpNode = tmpNode->preNode;
	}
	printf("\n");

	free(tmpNode);
	free(tmpStack);
}//오류
void peek(Stack* stack) {
	if (stack->top != NULL) printf("현재 스택의 TOP에는 %c 가 있습니다 !! ", stack->top->element);
	else printf("현재 스택은 비어 있습니다 !! !\n");
}
void pop(Stack* stack) {
	if (stack->top==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	printf(" %c 가 POP 되었습니다 !\n", stack->top->element);
	stack->top = stack->top->preNode;
	stack->len--;
}
void is_full(Stack* stack) {
	if (stack->len >= stack->capacity) printf("TRUE!!\n");
	else printf("FALSE!!\n");
}
void element_count(Stack* stack) {
	printf("스택의 크기는 %d 입니다 ! \n", stack->len);
}
void top(Stack* stack) {
	if (stack->top==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	printf("TOP 높이는 %d , TOP의 ELEMENT는 %c 입니다 ! \n", stack->len, stack -> top->element);
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
			printf("True!!! \n");
            return;
		}
	}
	printf("False!!!\n");
}
void replace(Stack* stack,char data) {
	if (stack->top==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	stack->top->element = data;
}// 오류 
void clear(Stack* stack) {
	stack->top = NULL;
	stack->len = 0;
}
void double_pop(Stack* stack) {
	if (stack->top==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	if (stack->len<2){
		printf("현재 스택에는 하나의 노드만 존재합니다 ! \n");
		return;
	}
	printf(" %c %c 가 차례로 POP 되었습니다 ! \n",stack->top->element,stack->top->preNode->element);
	stack->top = stack->top->preNode->preNode;
	stack->len= stack->len-2;
}
void triple_pop(Stack* stack) {
	if (stack->top ==NULL){
		printf("현재 스택은 비어있습니다! \n");
		return;
	}
	if (stack->len<3){
		printf("현재 스택에는 3개 이하의 노드가 존재합니다 ! \n");
		return;
	}
	printf(" %c %c %c 가 차례로 POP 되었습니다 ! \n",stack->top->element,stack->top->preNode->element,stack->top->preNode->preNode->element);
	stack->top = stack->top->preNode->preNode->preNode;
	stack->len= stack->len-3;
}
void all_pop(Stack* stack){
	for (int i=0;i<stack->len;i++){
		printf("%c ",stack->top->element);
		stack->top = stack->top->preNode;
	}
	stack->len=0;
	printf("스택의 모든 노드가 POP되었습니다 !! \n");

}