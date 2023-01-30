#include <stdio.h>
#include <windows.h>
#include <random>
#include <functional>

typedef void (*PVoidFunc)(int);
typedef int (*PIntFunc)(int);

//�֐��̃v���g�^�C�v�錾
//�����������₤�֐�
void Question(int& inputNum);

//�b�P�ʂ��~���b�P�ʂƂ��Ĉ����悤�ɂ���֐�
int ConvertMilliSec(int time);

//�����𐶐�����֐�
int CreateRandomNum(float min , float max);

//���b�Z�[�W��\������֐�
void DisplayTimerMessage(int s);

//�w�肵���b���҂֐�
void SetTimeOut(PVoidFunc pVoid , PIntFunc pInt , int s);

//���������ׂ�֐�
void CheckCorrectAnswer(int inputNum , int dice);

//main�֐�
int main() {

	//�ϐ��̐錾�Ə�����
	const int time = 3;

	PVoidFunc pVoid = DisplayTimerMessage;
	PIntFunc pInt = ConvertMilliSec;

	std::function<void(int)> ChohanGame = [=](int time) {
		int inputNum;
		Question(inputNum);
		int dice = CreateRandomNum(1 , 6);
		SetTimeOut(pVoid , pInt , time);
		CheckCorrectAnswer(inputNum , dice);
	};

	ChohanGame(time);

	return 0;

}

//�֐��̒�`
//�����������₤�֐�
void Question(int& inputNum) {

	while (true) {

		printf("�����������I��ł��������B\n");
		printf("�:1\n");
		printf("����:2\n");

		scanf_s("%d" , &inputNum);

		if (inputNum == 1 || inputNum == 2) {
			break;
		}
		else {
			printf("�G���[:�����ȓ��͂ł�\n");
		}

	}
}

//�b�P�ʂ��~���b�P�ʂƂ��Ĉ����悤�ɂ���֐�
int ConvertMilliSec(int time) {
	return time * 1000;
}

//�����𐶐�����֐�
int CreateRandomNum(float min , float max) {
	//�����V�[�h������
	std::random_device seed_gen;
	//�����Z���k�E�c�C�X�^�[�̗����G���W��
	std::mt19937_64 engine(seed_gen());
	//�����͈͂̐ݒ�
	std::uniform_real_distribution<float> dist(min , max);

	return dist(engine);
}

//���b�Z�[�W��\������֐�
void DisplayTimerMessage(int s) {

	printf("���蒆�ł��B(�҂�����:%d�b)\n" , s);

}

//�w�肵���b���҂֐�
void SetTimeOut(PVoidFunc pVoid , PIntFunc pInt , int s) {

	pVoid(s);

	Sleep(pInt(s));
}

//���������ׂ�֐�
void CheckCorrectAnswer(int inputNum , int dice) {

	int answer = 0;

	if (dice % 2 == 1) {
		answer = 1;
	}
	else {
		answer = 2;
	}

	if (inputNum == answer) {
		printf("�����ł��A���߂łƂ��������܂��B\n");
	}
	else {
		printf("�c�O�A�s�����ł����B\n");
	}
	printf("�������ꂽ����:%d\n" , dice);

}