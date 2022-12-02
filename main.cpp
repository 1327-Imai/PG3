#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>

//�P�������X�g�\����
typedef struct Cell {

	char str[16];
	struct Cell* next;

};


void create(Cell* head , const char* str);
void index(Cell* head);

//main�֐�
int main() {

	char str[16];

	//�擪�̃Z����錾
	Cell head;
	head.next = nullptr;

	while (true) {

		scanf_s("%s" , str , 16);

		create(&head , str);

		index(&head);

	}

	return 0;

}

void create(Cell* head , const char* str) {

	Cell* newCell;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (Cell*)malloc(sizeof(Cell));

	//������V�K�쐬�����Z���̒l�ɓ����
	strcpy_s(newCell->str ,16 , str);
	newCell->next = nullptr;

	while (head->next != nullptr) {
		head = head->next;
	}

	head->next = newCell;

}

void index(Cell* head) {

	while (head->next != nullptr) {
		head = head->next;
		printf("%s\n" , head->str);
	}

	putchar('\n');

}