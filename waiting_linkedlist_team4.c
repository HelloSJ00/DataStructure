//맛집 대기자 관리 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//노드와 연결리스트 정의
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

//함수 선언
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
    printf("==========================4조 자구자구해보자구=====================\n");
    printf("=======================맛집 대기자 관리 프로그램===================\n");
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
        printf("명령어를 입력하세요! : ");
        scanf_s("%c", &order);

        switch (order) {
        case '+':
            printf("이름을 입력하세요 :");
            scanf_s("%s", &name,20);
            printf("번호를 입력하세요 :");
            scanf_s("%s", &number,20);
            ADD(myList, name, number);
            break;
        case 'F':
            if (myList == NULL) {
                // 예외 처리: list가 NULL인 경우
                printf("대기줄이 비었습니다! \n");
                break;
            }
            printf("자신의 번호를 입력하세요 : ");
            fgets(number, 20, stdin);
            printf("\n");
            CheckFront(myList, number);
            break;
        case 'T':
            CheckTotal(myList);
            break;
        case 'R':
            if (myList == NULL) {
                // 예외 처리: list가 NULL인 경우
                printf("대기줄이 비었습니다! \n");
                break;
            }
            Ready(myList);
            break;
        case '-':
            if (myList == NULL) {
                // 예외 처리: list가 NULL인 경우
                printf("대기줄이 비었습니다! \n");
                break;
            }
            DeleteHead(myList);
            break;
        case 'D':
            if (myList == NULL) {
                // 예외 처리: list가 NULL인 경우
                printf("대기줄이 비었습니다! \n");
                break;
            }
            printf("자신의 번호를 입력하세요 : ");
            fgets(number, 20, stdin);
            Delete(myList, number);
            break;
        case 'S':
            if (myList == NULL) {
                // 예외 처리: list가 NULL인 경우
                printf("대기줄이 비었습니다! \n");
                break;
            }
            else if (myList->len == 1) {
                // 손님이 한팀있을 경우
                printf("순서를 바꿀 손님이 존재하지 않습니다 ! \n");
                break;
            }
            Switch(myList);
            break;
        }
    }
}

//함수 정의
void ADD(List* list, char* name, char number[20]) {
    Node* newNode = malloc(sizeof(Node));
    newNode->_name = _strdup(name);
    strcpy_s(newNode->_number, sizeof(newNode->_number), number);

ㄷ    if (list->curr == NULL) {
        // 리스트가 비어있는 경우
        newNode->pre = NULL;
        list->head = newNode;
        list->tail = newNode;
        list->curr = newNode;
    }
    else {
        // 리스트에 이미 노드가 있는 경우
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
            printf("현재 고객님 앞에 %d 팀이 대기중입니다! \n",cnt);
        }
        cnt++;
    }
}

void CheckTotal(List* list) {
    return printf("대기줄에는 총 %d 팀이 대기중입니다 !\n\n", list->len);
}

void Ready(List* list) {
    list->curr = list->head;
    printf("곧 입장할 팀들입니다 ! \n");

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
    list->head->pre = NULL; // 헤드 삭제

    list->curr->next = list->head->next;
    list->head->next = list->curr;// 원래의 헤드를 두번째로 삽입
}