#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

//mainä÷êî
int main() {

	int year = 1970;

	std::list<std::string>yamanoteLine{
		{"Shinagawa"} ,
		{"Osaki"} ,
		{"Gotanda"} ,
		{"Meguro"} ,
		{"Ebisu"} ,
		{"Shibuya"} ,
		{"Harajuku"} ,
		{"Yoyogi"} ,
		{"Shinjuku"} ,
		{"Shin-Okubo"} ,
		{"Takadanobaba"} ,
		{"Ikebukuro"} ,
		{"Otuka"} ,
		{"Sugamo"} ,
		{"Komagome"} ,
		{"Tabata"} ,
		{"Nipori"} ,
		{"Uguisudani"} ,
		{"Ueno"} ,
		{"Okachimachi"} ,
		{"Akihabara"} ,
		{"Kanda"} ,
		{"Tokyo"} ,
		{"Yurakucho"} ,
		{"Shimbashi"} ,
		{"Hamamatsucho"} ,
	};

	printf("year:%d\n" , year);
	for (std::list<std::string>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); itr++) {
		std::cout << *itr << '\n';
	}
	putchar('\n');


	year = 2019;
	for (std::list<std::string>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); itr++) {
		if (*itr == "Nipori") {
			itr = yamanoteLine.insert(itr , "Nishi-Nippori");
			++itr;
		}
	}

	printf("year:%d\n" , year);
	for (std::list<std::string>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); itr++) {
		std::cout << *itr << '\n';
	}
	putchar('\n');

	year = 2022;
	yamanoteLine.push_back("TakanawaGatway");

	printf("year:%d\n" , year);
	for (std::list<std::string>::iterator itr = yamanoteLine.begin(); itr != yamanoteLine.end(); itr++) {
		std::cout << *itr << '\n';
	}
	putchar('\n');

	return 0;

}