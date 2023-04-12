#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct myArray {
	char arraylist[30]; // �迭
	int idx; // ���� ��ġ idx
	int length; // �迭�� ����
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
void moveidx(myArrayinfo* a, int new_idx); //â�� ���1 : ���ϴ� ��ġ�� ���� ��ġ�� idx���� ���� 
void print_odd(myArrayinfo* a); //â�� ���2 : Ȧ�� �ڸ��� �����ֱ�
void print_even(myArrayinfo* a); //â�� ���3 : ¦�� �ڸ��� �����ֱ�

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
		printf("��ɾ �Է��ϼ��� : ");
		fgets(judge, sizeof(judge), stdin);
		judge[strcspn(judge, "\n")] = '\0'; // ���๮�� ����

		switch (judge[0])
		{
		case '+':
			if (myArray1->length < 30) // �迭�� ũ�Ⱑ 30���� �������� �߰��� ����
			{
				insert(myArray1, judge[1]);
			}
			else
			{
				printf("�迭�� ���� �� �ֽ��ϴ� \n");
			}
			break;
		case '<':
			traverse_front(myArray1);
			int i = 1; //judge[0]�� ���� �̹� ����ؼ� judge[1]���� ���� �� �ְ��ϱ� ����.
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
			int j = 1; //judge[0]�� ���� �̹� ����ؼ� judge[1]���� ���� �� �ְ��ϱ� ����.
			while (j < 3)
			{
				if (judge[j] == "\0") { break; } // ���� NULL�̶�� �� �ڷδ� �ƹ��͵� ������ ����.
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
				printf("��ɾ �ٽ� Ȯ�����ּ��� \n");
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
			printf("�Է°��� �߸� �Ǿ����ϴ� \n");
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
			printf("�Է°��� �߸� �Ǿ����ϴ� \n");
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
			printf("�迭�� ������ϴ� \n");
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
			printf("�迭�� ������ϴ� \n");
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
			printf("�迭�� ������ϴ� \n");
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
		if (new_position >= a->length) // �ű���� �ϴ� ��ġ�� �迭�� ���̺��� ���ų� Ŭ�� 
		{
			printf("�Է��� �߸� �Ǿ����ϴ� \n");
		}
		else
		{
			tmp = a->arraylist[a->idx]; // ������ġ data�� �ӽ÷� ����.

			if (a->idx < new_position) // idx�� new_positon���� ���� ��
			{
				for (int i = a->idx;i < new_position;i++)
				{
					a->arraylist[i] = a->arraylist[i + 1];
				}
				a->arraylist[new_position] = tmp;
			}
			else if (a->idx > new_position) // idx�� new_position���� Ŭ��
			{
				for (int i = new_position;i < a->idx;i++)
				{
					a->arraylist[i] = a->arraylist[i + 1];
				}
				a->arraylist[new_position] = tmp;
			}
			else if (a->idx == new_position) // idx�� new_position�� ������
			{
				printf("�Է��� �߸� �Ǿ����ϴ� \n");
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
			printf("\n���� Ŀ���� ��ġ�� %d �Դϴ� \n", a->idx);
		}
		else {
			printf("�迭�� ������ϴ� \n");
		}
	}

	void moveidx(myArrayinfo * a, int new_idx) // â�۱��1
	{
		a->idx = new_idx;
	}

	void print_odd(myArrayinfo * a) //â�۱��2 Ȧ����
	{
		for (int i = 0; i < a->length;i += 2)
		{
			printf("%c\t", a->arraylist[i]);
		}
		printf("\n");
	}

	void print_even(myArrayinfo * a) //â�۱��3 ¦���� 
	{
		for (int i = 1; i < a->length;i += 2)
		{
			printf("%c\t", a->arraylist[i]);
		}
		printf("\n");
	}