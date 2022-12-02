#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int strlength = 16;

//双方向リスト構造体
typedef struct Cell {

	char str[strlength];
	struct Cell* prev;
	struct Cell* next;

};


void Create(Cell* currentCell , const char* str);
void Index(Cell* endCell);
void Edit(Cell* currentCell , const char* str);
void Delete(Cell* currentCell);
Cell* GetInsertCellAddress(Cell* endCell , int iterator);

//main関数
int main() {

	int iterator;
	char str[strlength];
	Cell* insertCell;

	//先頭のセルを宣言
	Cell head;
	head.prev = nullptr;
	head.next = nullptr;

	int cellVal = 0;

	int firstMenu = 0;
	int secondMenu = 0;
	int thirdMenu = 0;

	int isOperationPossible = 0;
	int isEndOperation = 0;

	while (true) {

		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		if (cellVal != 0) {
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
		}
		printf("9.終了\n");
		putchar('\n');
		printf("----------------------------\n");
		printf("操作を選択してください\n");

		scanf_s("%d" , &firstMenu);
		putchar('\n');

		if (cellVal == 0) {
			if (firstMenu == 1 ||
				firstMenu == 2) {
				isOperationPossible = true;
			}
			else if (firstMenu == 9) {
				break;
			}
			else {
				isOperationPossible = false;
			}
		}
		else {
			if (firstMenu == 1 ||
				firstMenu == 2 ||
				firstMenu == 3 ||
				firstMenu == 4 ) {
				isOperationPossible = true;
			}
			else if (firstMenu==9) {
				break;
			}
			else {
				isOperationPossible = false;
			}
		}

		if (isOperationPossible == true) {
			while (true) {
				switch (firstMenu) {
				case(1):
#pragma region//要素の表示

				if (0 < cellVal) {

					printf("[要素の表示]\n");
					printf("1.要素の一覧表示\n");
					printf("2.要素の順番を指定して表示\n");
					printf("9.要素操作に戻る\n");
					putchar('\n');
					printf("操作を選択してください\n");

					scanf_s("%d" , &secondMenu);
					putchar('\n');

					if (secondMenu == 1) {
						printf("要素一覧:{\n");
						Index(&head);
						printf("}\n");
						putchar('\n');
						printf("要素数:%d\n" , cellVal);
						putchar('\n');
						printf("----------------------------\n");
						while (true) {
							printf("1.要素の表示に戻る\n");
							printf("2.要素の操作に戻る\n");
							scanf_s("%d" , &thirdMenu);
							putchar('\n');
							if (thirdMenu == 1) {
								break;
							}
							else if (thirdMenu == 2) {
								isEndOperation = true;
								break;
							}
							else {
								printf("エラー:無効な入力です\n");
							}
							
						}

					}
					else if (secondMenu == 2) {
						printf("[順番を指定して要素を表示]\n");
						printf("[表示したい要素の順番を指定してください\n");
						scanf_s("%d" , &iterator);
						putchar('\n');

						if (0 < iterator && iterator <= cellVal) {
							insertCell = GetInsertCellAddress(&head , iterator);
							printf("%d:%s\n" , iterator , insertCell->str);
						}
						else {
							printf("エラー:その場所には要素はありません\n");
						}
						putchar('\n');
						printf("----------------------------\n");
						while (true) {
							printf("1.要素の表示に戻る\n");
							printf("2.要素の操作に戻る\n");
							scanf_s("%d" , &thirdMenu);
							putchar('\n');
							if (thirdMenu == 1) {
								break;
							}
							else if (thirdMenu == 2) {
								isEndOperation = true;
								break;
							}
							else {
								printf("エラー:無効な入力です\n");
							}

						}
					}
					else if (secondMenu == 9) {
						isEndOperation = true;
					}
				}
				else {
					printf("まだ要素はありません\n");
					isEndOperation = true;
				}
#pragma endregion
				break;

				case(2):
#pragma region//要素の挿入

				printf("[リスト要素の挿入]\n");
				printf("要素を追加する場所を選んでください。最後尾に追加する場合は0を入力してください\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				printf("追加する要素の値を入力してください(半角%d文字まで)\n" , strlength);
				scanf_s("%s" , str , strlength);

				if (strlen(str) < strlength) {

					if (iterator == 0) {
						iterator = cellVal;
						insertCell = GetInsertCellAddress(&head , iterator);
						Create(insertCell , str);
					}
					else {
						insertCell = GetInsertCellAddress(&head , iterator - 1);
						Create(insertCell , str);
					}
					insertCell = GetInsertCellAddress(&head , iterator);
					putchar('\n');
					printf("要素”%s”が%d番目に挿入されました\n" , insertCell->str , iterator);
					cellVal++;
					putchar('\n');
				}
				else {
					printf("文字列が長すぎたため要素を追加できませんでした\n");
				}

				isEndOperation = true;

#pragma endregion
				break;

				case(3):
#pragma region//要素の編集
				printf("[要素の編集]\n");
				printf("編集したい要素の番号を指定してください\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				if (0 < iterator && iterator <= cellVal) {
					printf("%d番目の要素を変更する値を入力してください\n",iterator);
					scanf_s("%s" , str , strlength);
					if (strlen(str) < strlength) {
						insertCell = GetInsertCellAddress(&head , iterator);
						Edit(insertCell , str);
						putchar('\n');

						printf("%d番目の要素の値が”%s”に変更されました\n" , iterator , insertCell->str);
						putchar('\n');
					}
					else {
						printf("文字列が長すぎたため要素を変更できませんでした\n");
					}
				}
				else {
					printf("%d番目の要素が見つかりませんでした\n" , iterator);
					putchar('\n');
				}
				isEndOperation = true;

#pragma endregion
				break;

				case(4):
#pragma region//要素の削除
				printf("[要素の編集]\n");
				printf("編集したい要素の番号を指定してください\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				if (0 < iterator && iterator <= cellVal) {
					insertCell = GetInsertCellAddress(&head , iterator);
					printf("%d番目の要素”%s”が削除されました\n" , iterator , insertCell->str);
					Delete(insertCell);
					cellVal--;
					putchar('\n');
				}
				else {
					printf("%d番目の要素が見つかりませんでした\n" , iterator);
					putchar('\n');
				}
				isEndOperation = true;
#pragma endregion
				break;

				default:
				break;
				}

				if (isEndOperation == true) {
					isEndOperation = false;
					break;
				}
			}


		}
		else {
			printf("エラー:無効な入力です\n");
			putchar('\n');
		}

	}

	return 0;

}

void Create(Cell* currentCell , const char* str) {

	Cell* newCell;

	//新規作成するセル分のメモリを確保する
	newCell = (Cell*)malloc(sizeof(Cell));

	//引数を新規作成したセルの値に入れる
	strcpy_s(newCell->str , strlength , str);

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
		printf(" %d:" , num);
		printf("”%s”" , endCell->str);
		if (endCell->next) {
			putchar(',');
		}
		putchar('\n');
		num++;
	}

	putchar('\n');

}

void Edit(Cell* currentCell , const char* str) {
	strcpy_s(currentCell->str , strlength , str);
}

void Delete(Cell* currentCell) {

	Cell* tempCell = currentCell;

	if (currentCell->prev) {
		currentCell->prev->next = tempCell->next;
	}

	if (currentCell->next) {
		currentCell->next->prev = tempCell->prev;
	}
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