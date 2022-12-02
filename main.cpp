#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int strlength = 16;

//�o�������X�g�\����
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

//main�֐�
int main() {

	int iterator;
	char str[strlength];
	Cell* insertCell;

	//�擪�̃Z����錾
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

		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		if (cellVal != 0) {
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}
		printf("9.�I��\n");
		putchar('\n');
		printf("----------------------------\n");
		printf("�����I�����Ă�������\n");

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
#pragma region//�v�f�̕\��

				if (0 < cellVal) {

					printf("[�v�f�̕\��]\n");
					printf("1.�v�f�̈ꗗ�\��\n");
					printf("2.�v�f�̏��Ԃ��w�肵�ĕ\��\n");
					printf("9.�v�f����ɖ߂�\n");
					putchar('\n');
					printf("�����I�����Ă�������\n");

					scanf_s("%d" , &secondMenu);
					putchar('\n');

					if (secondMenu == 1) {
						printf("�v�f�ꗗ:{\n");
						Index(&head);
						printf("}\n");
						putchar('\n');
						printf("�v�f��:%d\n" , cellVal);
						putchar('\n');
						printf("----------------------------\n");
						while (true) {
							printf("1.�v�f�̕\���ɖ߂�\n");
							printf("2.�v�f�̑���ɖ߂�\n");
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
								printf("�G���[:�����ȓ��͂ł�\n");
							}
							
						}

					}
					else if (secondMenu == 2) {
						printf("[���Ԃ��w�肵�ėv�f��\��]\n");
						printf("[�\���������v�f�̏��Ԃ��w�肵�Ă�������\n");
						scanf_s("%d" , &iterator);
						putchar('\n');

						if (0 < iterator && iterator <= cellVal) {
							insertCell = GetInsertCellAddress(&head , iterator);
							printf("%d:%s\n" , iterator , insertCell->str);
						}
						else {
							printf("�G���[:���̏ꏊ�ɂ͗v�f�͂���܂���\n");
						}
						putchar('\n');
						printf("----------------------------\n");
						while (true) {
							printf("1.�v�f�̕\���ɖ߂�\n");
							printf("2.�v�f�̑���ɖ߂�\n");
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
								printf("�G���[:�����ȓ��͂ł�\n");
							}

						}
					}
					else if (secondMenu == 9) {
						isEndOperation = true;
					}
				}
				else {
					printf("�܂��v�f�͂���܂���\n");
					isEndOperation = true;
				}
#pragma endregion
				break;

				case(2):
#pragma region//�v�f�̑}��

				printf("[���X�g�v�f�̑}��]\n");
				printf("�v�f��ǉ�����ꏊ��I��ł��������B�Ō���ɒǉ�����ꍇ��0����͂��Ă�������\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				printf("�ǉ�����v�f�̒l����͂��Ă�������(���p%d�����܂�)\n" , strlength);
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
					printf("�v�f�h%s�h��%d�Ԗڂɑ}������܂���\n" , insertCell->str , iterator);
					cellVal++;
					putchar('\n');
				}
				else {
					printf("�����񂪒����������ߗv�f��ǉ��ł��܂���ł���\n");
				}

				isEndOperation = true;

#pragma endregion
				break;

				case(3):
#pragma region//�v�f�̕ҏW
				printf("[�v�f�̕ҏW]\n");
				printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				if (0 < iterator && iterator <= cellVal) {
					printf("%d�Ԗڂ̗v�f��ύX����l����͂��Ă�������\n",iterator);
					scanf_s("%s" , str , strlength);
					if (strlen(str) < strlength) {
						insertCell = GetInsertCellAddress(&head , iterator);
						Edit(insertCell , str);
						putchar('\n');

						printf("%d�Ԗڂ̗v�f�̒l���h%s�h�ɕύX����܂���\n" , iterator , insertCell->str);
						putchar('\n');
					}
					else {
						printf("�����񂪒����������ߗv�f��ύX�ł��܂���ł���\n");
					}
				}
				else {
					printf("%d�Ԗڂ̗v�f��������܂���ł���\n" , iterator);
					putchar('\n');
				}
				isEndOperation = true;

#pragma endregion
				break;

				case(4):
#pragma region//�v�f�̍폜
				printf("[�v�f�̕ҏW]\n");
				printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
				scanf_s("%d" , &iterator);
				putchar('\n');

				if (0 < iterator && iterator <= cellVal) {
					insertCell = GetInsertCellAddress(&head , iterator);
					printf("%d�Ԗڂ̗v�f�h%s�h���폜����܂���\n" , iterator , insertCell->str);
					Delete(insertCell);
					cellVal--;
					putchar('\n');
				}
				else {
					printf("%d�Ԗڂ̗v�f��������܂���ł���\n" , iterator);
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
			printf("�G���[:�����ȓ��͂ł�\n");
			putchar('\n');
		}

	}

	return 0;

}

void Create(Cell* currentCell , const char* str) {

	Cell* newCell;

	//�V�K�쐬����Z�����̃��������m�ۂ���
	newCell = (Cell*)malloc(sizeof(Cell));

	//������V�K�쐬�����Z���̒l�ɓ����
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
		printf("�h%s�h" , endCell->str);
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