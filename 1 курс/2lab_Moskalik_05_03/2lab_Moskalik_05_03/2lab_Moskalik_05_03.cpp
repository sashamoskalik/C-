// 2lab_Moskalik_05_03.cpp : Defines the entry point for the console application.
//Если максимальный элемент (последний) массива А(N) число чётное, то все элементы, 
//стоящие за ним, расположить в порядке возрастания.
#include "stdafx.h"
#include<iostream>
using namespace std;
void vivod(int*, int); //объявляем прототипы функций
void  vvod(int*, int);
int oper(int*, int);
int main() {
	int n;
	cout << "vvedi kol-vo elementov massiva: ";  cin >> n;
	int *p = new int[n]; //создаем динамический массив
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
		case 2:
			oper(p, n); 	       break;
		case  3:
			vivod(p, n); break;
		case  4:
			cout << "Good-Bye!";
			delete[] p; //высвобождаем память
			break;
		}
	}
	cout << endl;


}
void vvod(int *p, int n) { //вводим массив
	cout << "Enter massiv =";
	for (int i = 0; i < n; i++)
		cin >> *(p + i);
}
int oper(int *p, int n) {
	int k = 0, m = 0, t = 0;
	for (int i = 0; i < n; i++) { //находим последний максимальный элемент
		if (*(p + i) >= m) {
			m = *(p + i);
			k = i+1; //считаем индекс максимального элемента
		}
		}
	if (m % 2 == 0) { //проверяем четность максимального элемента
		for (int i = n-1; i >= k; --i) { //сортируем массив по возрастанию
			for (int j = k; j < i; ++j) { 
				if (*(p + j) > *(p + j + 1)) {
					t = *(p + j);
					*(p + j) = *(p + j + 1);
					*(p + j + 1) = t;
				}
			}
		}
		cout << "Result = "; //выводим результат
			for (int i = 0; i < n; i++) {
				cout << *(p + i) <<' ';
			}
		}
	else cout << "Chislo nechetnoe" << endl;
	return 0;
}

void vivod(int *p, int n) { //выводим массив
	cout << "massiv = ";
	for (int i = 0; i < n; i++)
		cout  << *(p + i) << ' ';
	cout << endl;
}





