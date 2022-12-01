#include <stdio.h>
#include <windows.h>
#include <random>
#include <functional>

typedef void (*PVoidFunc)(int);
typedef int (*PIntFunc)(int);

//関数のプロトタイプ宣言
//偶数か奇数かを問う関数
void Question(int& inputNum);

//秒単位をミリ秒単位として扱うようにする関数
int ConvertMilliSec(int time);

//乱数を生成する関数
int CreateRandomNum(float min , float max);

//メッセージを表示する関数
void DisplayTimerMessage(int s);

//指定した秒数待つ関数
void SetTimeOut(PVoidFunc pVoid ,PIntFunc pInt, int s);

//正解か調べる関数
void CheckCorrectAnswer(int inputNum , int randomNum);

//main関数
int main() {

	//変数の宣言と初期化
	int inputNum = 0;
	int randomNum = 0;
	const int time = 3;

	PVoidFunc pVoid = DisplayTimerMessage;
	PIntFunc pInt = ConvertMilliSec;

	Question(inputNum);

	randomNum = CreateRandomNum(1,100);

	SetTimeOut(pVoid , pInt , time);

	CheckCorrectAnswer(inputNum , randomNum);

	return 0;

}

//関数の定義
//偶数か奇数かを問う関数
void Question(int& inputNum) {

	while (true) {

		printf("奇数か偶数かを選んでください。\n");
		printf("奇数:1\n");
		printf("偶数:2\n");

		scanf_s("%d" , &inputNum);

		if (inputNum == 1 || inputNum == 2) {
			break;
		}
		else {
			printf("エラー:無効な入力です\n");
		}

	}
}

//秒単位をミリ秒単位として扱うようにする関数
int ConvertMilliSec(int time) {
	return time * 1000;
}

//乱数を生成する関数
int CreateRandomNum(float min , float max) {
	//乱数シード生成器
	std::random_device seed_gen;
	//メルセンヌ・ツイスターの乱数エンジン
	std::mt19937_64 engine(seed_gen());
	//乱数範囲の設定
	std::uniform_real_distribution<float> dist(min , max);

	return dist(engine);
}

//メッセージを表示する関数
void DisplayTimerMessage(int s) {

	printf("判定中です。(待ち時間:%d秒)\n" , s);

}

//指定した秒数待つ関数
void SetTimeOut(PVoidFunc pVoid, PIntFunc pInt ,int s) {

	pVoid(s);

	Sleep(pInt(s));
}

//正解か調べる関数
void CheckCorrectAnswer(int inputNum , int randomNum) {

	int answer = 0;

	if (randomNum % 2 == 1) {
		answer = 1;
	}
	else {
		answer = 2;
	}

	if (inputNum == answer) {
		printf("正解です、おめでとうございます。\n");
		printf("生成された数字:%d\n" , randomNum);
	}
	else {
		printf("残念、不正解でした。\n");
		printf("生成された数字:%d\n" , randomNum);
	}

}