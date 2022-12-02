#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//単方向リスト構造体
typedef struct Cell {

	char str[16];
	struct Cell* prev;
	struct Cell* next;

};


void Create(Cell* currentCell , const char* str);
void Index(Cell* endCell);
Cell* GetInsertCellAddress(Cell* endCell , int iterator);

//main関数
int main() {

	int iterator;
	char str[16];
	Cell* insertCell;

	//先頭のセルを宣言
	Cell head;
	head.prev = nullptr;
	head.next = nullptr;

	while (true) {

		printf("何番目のセルの後に挿入しますか?\n");
		scanf_s("%d" , &iterator);

		printf("挿入する文字列を入力してください\n");
		scanf_s("%s" , str , 16);

		insertCell = GetInsertCellAddress(&head,iterator);
		printf("リストを表示します\n");
		Create(insertCell , str);

		Index(&head);

	}

	return 0;

}

void Create(Cell* currentCell , const char* str) {

	Cell* newCell;

	//新規作成するセル分のメモリを確保する
	newCell = (Cell*)malloc(sizeof(Cell));

	//引数を新規作成したセルの値に入れる
	strcpy_s(newCell->str ,16 , str);
	
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		Cell* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;

}

void Index(Cell* endCell) {

	int num = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("%d:" , num);
		printf("%p" ,endCell->prev);
		printf("%s" , endCell->str);
		printf("(%p)" , endCell);
		printf("%p" , endCell->next);
		putchar('\n');
		num++;
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