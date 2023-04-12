#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���Ḯ��Ʈ�� ��� ����
typedef struct _LinkedNode LinkedNode;

struct _LinkedNode {
	char element;
	LinkedNode* next_node; // ���� ��带 ����Ŵ.
};

typedef struct _LinkedList {
	LinkedNode* head; //���
	LinkedNode* curr; //���� Ŀ�� ��ġ
	LinkedNode* tail; //����
	int position;
	int len;
} LinkedList;

//ADT ����
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
void show_odd(LinkedList* list); // â�۱��1 Ȧ������ �����͸� �����ֱ�
void show_even(LinkedList* list); // â�۱��2 ¦������ �����͸� �����ֱ�
void is_member_in(LinkedList* list, char element);//â�۱��3 ã���� �ϴ� �����Ͱ� ����Ʈ�ȿ� �����ϴ��� Ȯ���ϴ� ���


int main(void)
{
	int biterationFlag = 1;
	LinkedList* myLinkedList = (LinkedList*)malloc(sizeof(LinkedList)); //���Ḯ��Ʈ �����Ҵ�
	myLinkedList->head = NULL; //���
	myLinkedList->curr = NULL; // ���� Ŀ�� ���
	myLinkedList->tail = NULL; //����
	myLinkedList->position = -1; //���� ���Ḯ��Ʈ�� Ŀ�� ��ġ
	myLinkedList->len = 0; //���� ���Ḯ��Ʈ�� ����

	LinkedNode* newNode;// ��� �����Ҵ�
	



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
		printf("��ɾ �Է��ϼ��� : ");
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
			printf("��ɾ �߸� �Ǿ����ϴ� \n");
			break;
		}
	}
	free(myLinkedList);
	return 0;
}

//�Լ� ����
void addTail(LinkedList* list, LinkedNode* newnode)
{
	if (list->head == NULL) // ���Ḯ��Ʈ�� ��尡 ���������
	{
		list->head = newnode;
		list->curr = newnode;
		list->tail = newnode;
		list->len++;
		list->position++;
	}
	else // ���Ḯ��Ʈ�� ��尡 ������� ������ 
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
		printf("���Ḯ��Ʈ�� ����ֽ��ϴ�.\n");
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
	printf("���� Ŀ���� ��ġ�� %d �Դϴ�!", list->position);
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
	LinkedNode* temp; // �ӽ� ��忡 ���� ����� ���� ��带 ����.
	temp = list->curr->next_node;
	list->curr = list->head;

	for (int i = 0; i < list->position - 1;i++)
	{
		list->curr = list->curr->next_node;
	}
	list->curr->next_node = temp;
	list->curr = temp; // ������ ��� ������带 ������� ����
	list->len--; //position(Ŀ���� ��ġ)�� �״���̴� �ٲ��� ����
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
} //���� ��ħ

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
	printf("�������� ������ %d ���Դϴ�\n", list->len);
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
			printf("\n %c �� %d��° ������ �Դϴ�.\n", element, cnt);
			break;
		}
		else if (cnt == list->len) {
			printf("ã�� �����ʹ� �����ϴ�.\n");
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
	
}// â�۱��1 Ȧ������ �����͸� �����ֱ�

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

}// â�۱��2 ¦������ �����͸� �����ֱ�

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
}//â�۱��3 ã���� �ϴ� �����Ͱ� ����Ʈ�ȿ� �����ϴ��� Ȯ���ϴ� ���