// 6lab_Moskalik.cpp : Defines the entry point for the console application.
//Структура содержит информацию об абонентах междугородной телефонной станции: фамилия, адрес, номер телефона. 
//Создать массив структур.
//a)	Создать и вывести список абонентов по возрастанию номеров телефонов.
//b)	Вывести список абонентов дома, адрес которого вводится.
//c)	Во всех номерах телефонов, заканчивающихся цифрой х, заменить её на цифру y.
#include "stdafx.h"
#include <iostream>
using namespace std;
struct telStation { //заполняем структуру
	int tel;
	char *familiya;
	char *addres;
};
void Abonent(telStation* mas); //объявляем прототипы функций
void Addres(telStation* mas);
void Tel(telStation* mas);
int main() {
	telStation mas[5]; //создаем массив структур

	mas[0].tel = 2015419;
	mas[0].familiya = "Moskalik";
	mas[0].addres = "Parkovaya, 17";

	mas[1].tel = 2548749;
	mas[1].familiya = "Kovalenko";
	mas[1].addres = "Kovalevskaya, 14";

	mas[2].tel = 1458659;
	mas[2].familiya = "Vasilevich";
	mas[2].addres = "Lenina, 36";

	mas[3].tel = 1523654;
	mas[3].familiya = "Tristen";
	mas[3].addres = "Novatora, 42";

	mas[4].tel = 8521937;
	mas[4].familiya = "Serebraykov";
	mas[4].addres = "Bobra, 9";

	Abonent(mas);
	Addres(mas);
	Tel(mas);
	system("pause");
	return 0;
}
void Abonent(telStation* mas) {
	int t = 0;
	bool flag = true; //сортируем номера телефонов
	while (flag) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			if (mas[i].tel > mas[i+1].tel) {
				t = mas[i + 1].tel;
				mas[i + 1].tel = mas[i].tel;
				mas[i].tel = t;
				flag = true;
			}
		}
	}
	cout << "Telephone" << " " << "Familiya" << "     " << "Adress" << endl;
	for (int i = 0; i < 5; i++) {
		cout << mas[i].tel << "   " << mas[i].familiya << "  " << mas[i].addres << endl;
	}
}
void Addres(telStation* mas) { //сравниваем адреса
	char str[30];
	cout << "enter the addres" << endl; 
	gets_s(str);
	cout << "Telephone" << " " << "Familiya" << "     " << "Adress" << endl;
	for (int i = 0; i<7; i++) {
		if (strcmp(mas[i].addres, str) == 0) {
			cout << mas[i].tel << "   " << mas[i].familiya << "  " << mas[i].addres << endl; 
		}
	}
}
void Tel(telStation* mas) { //заменяем цифру в номере
	int n, m;
	cout << "Vvedite chifry kotoryu nado zamenit= ";
	cin >> n;
	cout << "Vvedite chifry na kotoryu zamenit= ";
	cin >> m;
	cout << "Telephone" << "  " << "Familiya" << "     " << "Adress" << endl;
	for (int i = 0; i < 5; i++) {
		if (mas[i].tel % 10 == n) {
			cout << (mas[i].tel / 10) * 10 + m << "    " << mas[i].familiya << "  " << mas[i].addres << endl;
		}
	}
}
