//���� ����� ���� ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���� ���Ḯ��Ʈ ����
typedef struct _LinkedNode {
    char* _name;
    char* _number;
    struct _LinkedNode* next;
    struct _LinkedNode* pre;
}Node;

typedef struct _LinkedList {
    Node* head;
    Node* curr;
    Node* tail;
    int len;
}List;

//�Լ� ����
void ADD(List* list, char name[20], char number[20]);
void CheckFront(List* list, char number[20]);
void CheckTotal(List* list);
void Ready(List* list);
void DeleteHead(List* list);
void Delete(List* list, char numbe[20]);
void Switch(List* list);
void screen() {
    printf("==================================================================\n");
    printf("==================================================================\n");
    printf("==========================4�� �ڱ��ڱ��غ��ڱ�=====================\n");
    printf("=======================���� ����� ���� ���α׷�===================\n");
    printf("ADD()        : '+'\n");
    printf("CheckFront() : 'F'\n");
    printf("CheckTotal() : 'T'\n");
    printf("Ready()      : 'R'\n");
    printf("DeleteHead() : '-'\n");
    printf("Delete()     : 'D'\n");
    printf("Switch()     : 'S'\n");
    printf("==================================================================\n");
    printf("==================================================================\n");
    printf("==================================================================\n");
}

int main(void) {
    List* myList = (List*)malloc(sizeof(Node*));
    myList->head = NULL;
    myList->curr = NULL;
    myList->tail = NULL;
    myList->len = 0;

    int bIterFlag = 1;
    screen();

    char order;
    char name[20];
    char number[20];
    int i = 0;
    while (bIterFlag) {
        printf("��ɾ �Է��ϼ���! : ");
        scanf_s("%c", &order);

        switch (order) {
        case '+':
            printf("�̸��� �Է��ϼ��� :");
            scanf_s("%s", &name,20);
            printf("��ȣ�� �Է��ϼ��� :");
            scanf_s("%s", &number,20);
            ADD(myList, name, number);
            break;
        case 'F':
            if (myList == NULL) {
                // ���� ó��: list�� NULL�� ���
                printf("������� ������ϴ�! \n");
                break;
            }
            printf("�ڽ��� ��ȣ�� �Է��ϼ��� : ");
            fgets(number, 20, stdin);
            printf("\n");
            CheckFront(myList, number);
            break;
        case 'T':
            CheckTotal(myList);
            break;
        case 'R':
            if (myList == NULL) {
                // ���� ó��: list�� NULL�� ���
                printf("������� ������ϴ�! \n");
                break;
            }
            Ready(myList);
            break;
        case '-':
            if (myList == NULL) {
                // ���� ó��: list�� NULL�� ���
                printf("������� ������ϴ�! \n");
                break;
            }
            DeleteHead(myList);
            break;
        case 'D':
            if (myList == NULL) {
                // ���� ó��: list�� NULL�� ���
                printf("������� ������ϴ�! \n");
                break;
            }
            printf("�ڽ��� ��ȣ�� �Է��ϼ��� : ");
            fgets(number, 20, stdin);
            Delete(myList, number);
            break;
        case 'S':
            if (myList == NULL) {
                // ���� ó��: list�� NULL�� ���
                printf("������� ������ϴ�! \n");
                break;
            }
            else if (myList->len == 1) {
                // �մ��� �������� ���
                printf("������ �ٲ� �մ��� �������� �ʽ��ϴ� ! \n");
                break;
            }
            Switch(myList);
            break;
        }
    }
}

//�Լ� ����
void ADD(List* list, char* name, char number[20]) {
    Node* newNode = malloc(sizeof(Node));
    newNode->_name = _strdup(name);
    strcpy_s(newNode->_number, sizeof(newNode->_number), number);

��    if (list->curr == NULL) {
        // ����Ʈ�� ����ִ� ���
        newNode->pre = NULL;
        list->head = newNode;
        list->tail = newNode;
        list->curr = newNode;
    }
    else {
        // ����Ʈ�� �̹� ��尡 �ִ� ���
        newNode->pre = list->curr;
        list->curr->next = newNode;
        list->curr = newNode;
        list->tail = newNode;
    }

    list->len++;
}
void CheckFront(List* list, char number[20]) {
    int cnt = 0;
    for (int i = 0; i < list->len;i++) {
        if (list->head->_number == _strdup(number[20])) {
            printf("���� ���� �տ� %d ���� ������Դϴ�! \n",cnt);
        }
        cnt++;
    }
}

void CheckTotal(List* list) {
    return printf("����ٿ��� �� %d ���� ������Դϴ� !\n\n", list->len);
}

void Ready(List* list) {
    list->curr = list->head;
    printf("�� ������ �����Դϴ� ! \n");

    if (list->len < 3) {
        for (int j = 0;j < list->len;j++) {
            printf("%d. %s , %s", j+1, list->curr->_name, list->curr->_number);
            list->curr = list->curr->next;
        }
    }
    for (int i = 0;i < 3;i++) {
        printf("%d. %s , %s", i+1, list->curr->_name, list->curr->_number);
        list->curr = list->curr->next;
    }
}

void DeleteHead(List* list) {
    list->head = list->head->next;
    list->head->pre = NULL;
    list->len--;
}

void Delete(List* list, char number[20]) {
    list->curr = list->head;
    for (int i = 0;i < list->len;i++) {
        if (list->curr->_number == number[12]) {
            list->curr->pre->next = list->curr->next;
        }
    }
}

void Switch(List* list) {
    list->curr = list->head;
    list->head = list->head->next;
    list->head->pre = NULL; // ��� ����

    list->curr->next = list->head->next;
    list->head->next = list->curr;// ������ ��带 �ι�°�� ����
}