#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�P�������X�g�\����
typedef struct Cell {

	char str[16];
	struct Cell* prev;
	struct Cell* next;

};


void create(Cell* currentCell , const char* str);
void index(Cell* endCell);
Cell* GetInsertCellAddress(Cell* endCell , int iterator);

//main�֐�
int main() {

	int iterator;
	char str[16];
	Cell* insertCell;

	//�擪�̃Z����錾
	Cell head;
	head.prev = nullptr;
	head.next = nullptr;

	while (true) {

		printf("���Ԗڂ̃Z���̌�ɑ}�����܂���?\n");
		scanf_s("%d" , &iterator);

		printf("�}�����镶�������͂��Ă�������\n");
		scanf_s("%s" , str , 16);

		printf("���X�g��\�����܂�\n");
		insertCell = GetInsertCellAddress(&head,iterator);
		create(&head , str);

		index(&head);

	}

	return 0;

}

void create(Cell* currentCell , const char* str) {

	Cell* newCell;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (Cell*)malloc(sizeof(Cell));

	//������V�K�쐬�����Z���̒l�ɓ����
	strcpy_s(newCell->str ,16 , str);
	
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		Cell* nextCell = currentCell->next;
		nextCell = newCell;
	}

	currentCell->next = newCell;

}

void index(Cell* endCell) {

	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%s\n" , endCell->str);
	}

	putchar('\n');

}

Cell* GetInsertCellAddress(Cell* endCell , int iterator) {

	for (int i = 0; i < iterator; i++) {
		if (endCell->next) {
			endCell = endCell->next;
		}
		else {
			break;
		}
	}
	return endCell;
}