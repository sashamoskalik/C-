// 3lab_Moskalik_19_03_18.cpp : Defines the entry point for the console application.
//Определить сколько слов в строке имеют заданную длину и содержат 
//заданный символ. Вывести такие слова на экран.
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int vvod(char*, int); //объявляем прототипы функции
void vivod(char*);
int oper(char*, int);
int main()
{
	int n;
	cout << "vvedi dliny stroki: ";  cin >> n;
	char *p = new char[n]; //создаем динамический массив
	cin.ignore();
	int vibor;
	while (1) { //добавляем меню
		cout << "\n vvedite nomer punkta:\n";
		cout << "vvod------>1" << endl
			<< "operation----->2" << endl
			<< "vivod------>3" << endl
			<< "exit------>4" << endl;
		cin >> vibor;
		switch (vibor) {
		case 1:
			vvod(p, n);               break;
		case  2:
			oper(p, n); break;
		case  3:
			vivod(p); break;
		case  4:
			cout << "Good-Bye!";
			delete[] p; //высвобождаем память
			break;
		}
	}
	cout << endl;
}
int vvod(char *p, int n) {
	cout << "Vvedi stroky : ";
	cin.ignore();
	gets_s(p,n);
	cout << p << endl;
	cout << endl;
	return 0;
}
int oper(char*p, int n) {
	int len = 0, k, v=0;
	char m;
	char slovo[20];
	char *sp = " ";
	cout << "Vvedi zadanyu dliny ="; //вводим искомую длину
	cin >> k;
	cout << "Vvedi zadanyu bykvy ="; //вводим искомую букву
	cin >> m;
	while (p) {
		p = p + strspn(p, sp); //находим начало слова
		cout << "P" << p << endl;
		len = strcspn(p, sp); //находим длину слова
		cout << "Len" << len << endl;
		if (!len) break;
		strncpy_s(slovo, p, len); //собираем слово
		if (len == k) { //проверям слово на искомую длину
			for (int i = 0; i < len; i++) {
				if (*(p + i) == m) { //проверяем слово на искомую букву
					cout << "Slovo = " << slovo << ' '; //выводим слово
					v++; //считаем количество подходящих слов
				}
			}
		}
		p = p + len;
	}
	cout << "Kolvo slov = " << v << endl;
	return 0;
}
void vivod(char*p) { //выводим исходную строку
	cout << "isxodnya stroka : ";
	cout << p << endl;
}
