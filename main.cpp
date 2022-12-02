#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>

//単方向リスト構造体
typedef struct Cell {

	char str[16];
	struct Cell* next;

};


void create(Cell* head , const char* str);
void index(Cell* head);

//main関数
int main() {

	char str[16];

	//先頭のセルを宣言
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

	//新規作成するセル分のメモリを確保する
	newCell = (Cell*)malloc(sizeof(Cell));

	//引数を新規作成したセルの値に入れる
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