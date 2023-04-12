#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//연결리스트와 노드 선언
typedef struct _LinkedNode LinkedNode;

struct _LinkedNode {
	char element;
	LinkedNode* next_node; // 다음 노드를 가리킴.
};

typedef struct _LinkedList {
	LinkedNode* head; //헤드
	LinkedNode* curr; //현재 커서 위치
	LinkedNode* tail; //테일
	int position;
	int len;
} LinkedList;

//ADT 선언
void addTail(LinkedList* list, LinkedNode* newnode);
void add(LinkedList* list, LinkedNode* newnode);
void print(LinkedList* list);
void get_data(LinkedList* list);
void traverse_front(LinkedList* list);
void position_front(LinkedList* list);
void position_back(LinkedList* list);
void delete(LinkedList* list);
void traverse_rear(LinkedList* list);
void replace(LinkedList* list, char new_element);
void data_count(LinkedList* list);
void is_member(LinkedList* list, char element);
void is_empty(LinkedList* list);
void clear_list(LinkedList* list);
void show_odd(LinkedList* list); // 창작기능1 홀수번쨰 데이터만 보여주기
void show_even(LinkedList* list); // 창작기능2 짝수번쨰 데이터만 보여주기
void is_member_in(LinkedList* list, char element);//창작기능3 찾고자 하는 데이터가 리스트안에 존재하는지 확인하는 기능


int main(void)
{
	int biterationFlag = 1;
	LinkedList* myLinkedList = (LinkedList*)malloc(sizeof(LinkedList)); //연결리스트 동적할당
	myLinkedList->head = NULL; //헤드
	myLinkedList->curr = NULL; // 현재 커서 노드
	myLinkedList->tail = NULL; //테일
	myLinkedList->position = -1; //현재 연결리스트의 커서 위치
	myLinkedList->len = 0; //현재 연결리스트의 길이

	LinkedNode* newNode;// 노드 동적할당
	



	char judge[10];
	int cntoftraverse;

	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("=========================USE ADT COMMAND===================================\n");
	printf("===========================================================================\n");
	printf("===========================================================================\n");
	printf("+ :                                       add,addTail() ===================\n");
	printf("< :                                    traverse_front() ===================\n");
	printf("> :                                     traverse_rear() ===================\n");
	printf("P :                                    position_front() ===================\n");
	printf("N :                                     position_back() ===================\n");
	printf("= :                                           replace() ===================\n");
	printf("L :                                             print() ===================\n");
	printf("G :                                          get_data() ===================\n");
	printf("? :                                         is_member() ===================\n");
	printf("# :                                        data_count() ===================\n");
	printf("C :                                        clear_list() ===================\n");
	printf("E :                                          is_empty() ===================\n");
	printf("O :                                          show_odd() ===================\n");
	printf("e :                                         show_even() ===================\n");
	printf("I :                                      is_member_in() ===================\n");
	printf("Q:                                                 Quit ===================\n");
	printf("===========================================================================\n\n");
	while (biterationFlag)
	{
		printf("명령어를 입력하세요 : ");
		fgets(judge, 10, stdin);
		switch (judge[0])
		{
		case '+':
			newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
			newNode->next_node = NULL;
			newNode->element = judge[1];

			if (myLinkedList->position == myLinkedList->len - 1)
			{
				addTail(myLinkedList, newNode);
			}
			else
			{
				add(myLinkedList, newNode);
			}
			break;
		case '=':
			replace(myLinkedList, judge[1]);
			break;
		case 'L':
			print(myLinkedList);
			break;
		case 'G':
			get_data(myLinkedList);
			break;
		case '<':
			traverse_front(myLinkedList);
			break;
		case '>':
			traverse_rear(myLinkedList);
			break;
		case 'P':
			position_front(myLinkedList);
			break;
		case 'N':
			position_back(myLinkedList);
			break;
		case '?':
			is_member(myLinkedList, judge[1]);
			break;
		case 'E':
			is_empty(myLinkedList);
			break;
		case '#':
			data_count(myLinkedList);
			break;
		case 'C':
			clear_list(myLinkedList);
			break;
		case 'O':
			show_odd(myLinkedList);
			break;
		case 'e':
			show_even(myLinkedList);
			break;
		case 'I':
			is_member_in(myLinkedList, judge[1]);
			break;
		case 'Q':
			return 0;
		default:
			printf("명령어가 잘못 되었습니다 \n");
			break;
		}
	}
	free(myLinkedList);
	return 0;
}

//함수 정의
void addTail(LinkedList* list, LinkedNode* newnode)
{
	if (list->head == NULL) // 연결리스트의 헤드가 비어있을때
	{
		list->head = newnode;
		list->curr = newnode;
		list->tail = newnode;
		list->len++;
		list->position++;
	}
	else // 연결리스트의 헤드가 비어있지 않을때 
	{
		list->tail->next_node = newnode; 
		list->tail = newnode;
		list->curr = newnode;
		list->len++;
		list->position++;
	}

}

void print(LinkedList* list)
{
	if (list->head == NULL)
	{
		printf("연결리스트가 비어있습니다.\n");
		return;
	}

	LinkedNode* printNode = list->head;
	printf("%c ", printNode->element);

	for (int i = 0; i < list->len - 1; i++)
	{
		printNode = printNode->next_node;
		printf("%c ", printNode->element);
	}
	printf("\n");
	printf("현재 커서의 위치는 %d 입니다!", list->position);
	printf("\n");
}

void get_data(LinkedList* list)
{
	printf("%c\n", list->curr->element);
}

void traverse_front(LinkedList* list)
{
	list->curr = list->head;
	list->position = 0;
}
void position_front(LinkedList* list)
{
	list->curr = list->head;
	for (int i = 0;i < list->position;i++)
	{
		list->curr = list->curr->next_node;
	}
	list->position--;
}
void position_back(LinkedList* list)
{
	list->curr = list->curr->next_node;
	list->position++;
}

void delete(LinkedList* list)
{
	LinkedNode* temp; // 임시 노드에 현재 노드의 다음 노드를 저장.
	temp = list->curr->next_node;
	list->curr = list->head;

	for (int i = 0; i < list->position - 1;i++)
	{
		list->curr = list->curr->next_node;
	}
	list->curr->next_node = temp;
	list->curr = temp; // 지워진 노드 다음노드를 현재노드로 지정
	list->len--; //position(커서의 위치)은 그대로이니 바꾸지 않음
}

void add(LinkedList* list, LinkedNode* newnode)
{
	LinkedNode* temp1=(LinkedNode*)malloc(sizeof(LinkedNode));
	temp1 = list->curr->next_node;
	LinkedNode* temp2 = (LinkedNode*)malloc(sizeof(LinkedNode));
	temp2 = list->head;

	for (int i = 0;i < list->position;i++)
	{
		temp2 = temp2->next_node;
	}

	temp2->next_node = newnode;
	newnode->next_node = temp1;

	list->len++;
	list->position++;
} //오류 고침

void traverse_rear(LinkedList* list)
{
	list->curr = list->tail;
	list->position = list->len - 1;
}

void replace(LinkedList* list, char new_element)
{
	list->curr->element = new_element;
}

void data_count(LinkedList* list)
{
	printf("데이터의 개수는 %d 개입니다\n", list->len);
}

void is_member(LinkedList* list, char element)
{
	int cnt = 1;
	LinkedNode* temp1 = (LinkedNode*)malloc(sizeof(LinkedNode));
	temp1=list->head;
	LinkedNode* temp2 = (LinkedNode*)malloc(sizeof(LinkedNode));
	temp2=list->head;

	while (1)
	{
		if (temp1->element == element)
		{
			printf("%d :", cnt);
			for (int i = 0;i < list->len;i++)
			{
				printf("%c", temp2->element);
				temp2 = temp2->next_node;
			}
			printf("\n %c 는 %d번째 데이터 입니다.\n", element, cnt);
			break;
		}
		else if (cnt == list->len) {
			printf("찾는 데이터는 없습니다.\n");
			break;
		}
		else
		{
			temp1 = temp1->next_node;
			cnt++;
		}
	}
	free(temp1);
	free(temp2);
}

void clear_list(LinkedList* list)
{
	list->head = NULL;
	list->len = 0;
	list->position = -1;
}

void is_empty(LinkedList* list)
{
	if (list->head == NULL)
	{
		printf("TRUE\n");
		return;
	}

	printf("False\n");
}
void show_odd(LinkedList* list)
{
	LinkedNode* temp;
	temp = list->head;
	for (int i = 0;i < list->len;i += 2)
	{
		printf("%c ", temp->element);

		if (temp == list->tail || temp->next_node == list->tail)
		{

		}
		else
		{
			temp = temp->next_node->next_node;
		}

	}
	printf("\n");
	
}// 창작기능1 홀수번쨰 데이터만 보여주기

void show_even(LinkedList* list)
{
	LinkedNode* temp;
	temp = list->head->next_node;
	for (int i = 1;i < list->len;i += 2)
	{
		printf("%c ", temp->element);

		if (temp == list->tail || temp->next_node == list->tail)
		{
			
		}
		else 
		{
			temp = temp->next_node->next_node;
		}
		
	}
	printf("\n");

}// 창작기능2 짝수번쨰 데이터만 보여주기

void is_member_in(LinkedList* list, char element)
{
	LinkedNode* temp;
	temp = list->head;

	int cnt = 0;

	for (int i = 0;i < list->len;i++)
	{
		if (temp->element == element)
		{
			printf("IS IN HERE\n");
		}
		else if (cnt == list->len)
		{
			printf("IS NOT IN HERE\n");
		}
		else
		{
			temp = temp->next_node;
			cnt++;
		}
	}
}//창작기능3 찾고자 하는 데이터가 리스트안에 존재하는지 확인하는 기능