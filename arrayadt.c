#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct myArray {
	char arraylist[30]; // 배열
	int idx; // 현재 위치 idx
	int length; // 배열의 길이
}myArrayinfo;

void insert(myArrayinfo* a, char data);
void traverse_front(myArrayinfo* a);
void traverse_rear(myArrayinfo* a);
void movefront(myArrayinfo* a);
void idxfront(myArrayinfo* a);
void moverear(myArrayinfo* a);
void idxrear(myArrayinfo* a);
void delete(myArrayinfo* a);
void replace(myArrayinfo* a, char new_data);
void empty(myArrayinfo* a);
void get_data(myArrayinfo* a);
void move(myArrayinfo* a, int new_position);
void print(myArrayinfo* a);
void moveidx(myArrayinfo* a, int new_idx); //창작 기능1 : 원하는 위치로 현재 위치인 idx값을 변경 
void print_odd(myArrayinfo* a); //창작 기능2 : 홀수 자리만 보여주기
void print_even(myArrayinfo* a); //창작 기능3 : 짝수 자리만 보여주기

int main(void)
{

	myArrayinfo* myArray1 = (myArrayinfo*)malloc(sizeof(myArrayinfo)); // create
	myArray1->idx = -1;
	myArray1->length = 0;
	char judge[4];

	printf("\n\n");
	printf("================================================================\n");
	printf("======================== Use ADT Command========================\n");
	printf("================================================================\n");

	while (1)
	{
		printf("명령어를 입력하세요 : ");
		fgets(judge, sizeof(judge), stdin);
		judge[strcspn(judge, "\n")] = '\0'; // 개행문자 제거

		switch (judge[0])
		{
		case '+':
			if (myArray1->length < 30) // 배열의 크기가 30보다 작을때만 추가가 가능
			{
				insert(myArray1, judge[1]);
			}
			else
			{
				printf("배열이 가득 차 있습니다 \n");
			}
			break;
		case '<':
			traverse_front(myArray1);
			int i = 1; //judge[0]의 값은 이미 사용해서 judge[1]부터 읽을 수 있게하기 위함.
			while (i < 3)
			{
				if (judge[i] == "\0") { break; }
				switch (judge[i])
				{
				case 'P':
					idxfront(myArray1);
					break;
				case 'N':
					idxrear(myArray1);
					break;
				}
				i++;
			}
			break;
		case '>':
			traverse_rear(myArray1);
			int j = 1; //judge[0]의 값은 이미 사용해서 judge[1]부터 읽을 수 있게하기 위함.
			while (j < 3)
			{
				if (judge[j] == "\0") { break; } // 값이 NULL이라면 그 뒤로는 아무것도 없으니 종료.
				switch (judge[j])
				{
				case 'P':
					idxfront(myArray1);
					break;
				case 'N':
					idxrear(myArray1);
					break;
				}
				j++;
			}
			break;
		case '-':
			delete(myArray1);
			break;
		case '@':
			get_data(myArray1);
			break;
		case '=':
			replace(myArray1, judge[1]);
			break;
		case 'E':
			empty(myArray1);
			break;
		case 'M':

			switch (judge[1])
			{
			case 'P':
				movefront(myArray1);
				break;
			case 'N':
				moverear(myArray1);
				break;
				break;
			case 'L':
				print(myArray1);
				break;
			case 'C':
				moveidx(myArray1, judge[1]);
				break;
			case 'O':
				print_odd(myArray1);
				break;
			case 'e':
				print_even(myArray1);
				break;
			default:
				printf("명령어를 다시 확인해주세요 \n");
			}
		}
		return 0;

	}
	}

void insert(myArrayinfo * a, char data)
{
	a->idx++;
		a->length++;
		a->arraylist[a->idx] = data;
}

	void traverse_front(myArrayinfo * a)
	{
		a->idx = 0;
	}

	void traverse_rear(myArrayinfo * a)
	{
		a->idx = a->length - 1;
	}

	void movefront(myArrayinfo * a)
	{
		char tmp;

		if (a->idx > 0)
		{
			tmp = a->arraylist[a->idx - 1];
			a->arraylist[a->idx - 1] = a->arraylist[a->idx];
			a->arraylist[a->idx] = tmp;
			a->idx--;
		}
		else
		{
			printf("입력값이 잘못 되었습니다 \n");
		}
	}
	void idxfront(myArrayinfo * a)
	{
		if (a->idx > 0)
		{
			a->idx--;
		}
	}
	void moverear(myArrayinfo * a)
	{
		char tmp;
		if (a->idx + 1 < a->length)
		{
			tmp = a->arraylist[a->idx];
			a->arraylist[a->idx] = a->arraylist[a->idx + 1];
			a->arraylist[a->idx + 1] = tmp;
			a->idx++;
		}
		else
		{
			printf("입력값이 잘못 되었습니다 \n");
		}
	}
	void idxrear(myArrayinfo * a)
	{
		if (a->idx < a->length - 1)
		{
			a->idx++;
		}
	}

	void delete(myArrayinfo * a)
	{
		if (a->length > 0)
		{
			for (int i = a->idx;i < a->length - 1;i++)
			{
				a->arraylist[i] = a->arraylist[i + 1];
			}
			a->arraylist[a->length - 1] = "\0";
			a->idx--;
			a->length--;
		}
		else
		{
			printf("배열이 비었습니다 \n");
		}
	}

	void get_data(myArrayinfo * a)
	{
		if (a->idx >= 0 && a->idx < a->length)
		{
			printf("%c \n", a->arraylist[a->idx]);
		}
		else
		{
			printf("배열이 비었습니다 \n");
		}
	}

	void replace(myArrayinfo * a, char new_data)
	{
		if (a->idx >= 0 && a->idx < a->length)
		{
			a->arraylist[a->idx] = new_data;
		}
		else
		{
			printf("배열이 비었습니다 \n");
		}
	}

	void empty(myArrayinfo * a)
	{
		for (int i = 0; i < a->length; i++)
		{
			a->arraylist[i] = "\0";
		}
		a->length = 0;
		a->idx = -1;
	}

	void move(myArrayinfo * a, int new_position)
	{
		char tmp;
		if (new_position >= a->length) // 옮기고자 하는 위치가 배열의 길이보다 같거나 클때 
		{
			printf("입력이 잘못 되었습니다 \n");
		}
		else
		{
			tmp = a->arraylist[a->idx]; // 현재위치 data를 임시로 저장.

			if (a->idx < new_position) // idx가 new_positon보다 작을 때
			{
				for (int i = a->idx;i < new_position;i++)
				{
					a->arraylist[i] = a->arraylist[i + 1];
				}
				a->arraylist[new_position] = tmp;
			}
			else if (a->idx > new_position) // idx가 new_position보다 클때
			{
				for (int i = new_position;i < a->idx;i++)
				{
					a->arraylist[i] = a->arraylist[i + 1];
				}
				a->arraylist[new_position] = tmp;
			}
			else if (a->idx == new_position) // idx랑 new_position이 같을때
			{
				printf("입력이 잘못 되었습니다 \n");
			}
		}
	}

	void MovetoEnd(myArrayinfo * a)
	{
		char tmp;
		tmp = a->arraylist[a->idx];
		for (int i = a->idx;i < a->length - 1;i++)
		{
			a->arraylist[i] = a->arraylist[i + 1];
		}
		a->arraylist[a->length - 1] = tmp;

	}

	void MovetoFront(myArrayinfo * a)
	{
		char tmp;
		tmp = a->arraylist[a->idx];
		a->arraylist[a->idx] = a->arraylist[a->idx - 1];
		a->arraylist[a->idx - 1] = tmp;
	}

	void MovetoBack(myArrayinfo * a)
	{
		char tmp;
		tmp = a->arraylist[a->idx];
		a->arraylist[a->idx] = a->arraylist[a->idx + 1];
		a->arraylist[a->idx + 1] = tmp;
	}

	void print(myArrayinfo * a) {
		if (a->length > 0) {
			for (int i = 0; i < a->length; i++) {
				printf("%c ", a->arraylist[i]);
			}
			printf("\n현재 커서의 위치는 %d 입니다 \n", a->idx);
		}
		else {
			printf("배열이 비었습니다 \n");
		}
	}

	void moveidx(myArrayinfo * a, int new_idx) // 창작기능1
	{
		a->idx = new_idx;
	}

	void print_odd(myArrayinfo * a) //창작기능2 홀수만
	{
		for (int i = 0; i < a->length;i += 2)
		{
			printf("%c\t", a->arraylist[i]);
		}
		printf("\n");
	}

	void print_even(myArrayinfo * a) //창작기능3 짝수만 
	{
		for (int i = 1; i < a->length;i += 2)
		{
			printf("%c\t", a->arraylist[i]);
		}
		printf("\n");
	}