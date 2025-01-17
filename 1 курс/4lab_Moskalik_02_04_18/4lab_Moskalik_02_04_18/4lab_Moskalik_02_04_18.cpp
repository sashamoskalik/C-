// 4lab_Moskalik_02_04_18.cpp : Defines the entry point for the console application.
//В массиве А(N,M) удалить строку с максимальной суммой цифр элементов последнего столбца.
//Остальные строки расположить в порядке возрастания суммы цифр элементов последнего столбца. 
//Указатели на строки.
#include "stdafx.h"
#include<iostream>
using namespace std;
void vivod(int**, int, int); //объявляем прототипы функций
void  vvod(int**, int, int);
int oper(int**, int, int);
int main() {
	int n, m;
	cout << "vvedi n, m : ";  cin >> n >> m;
	int **p = new int *[n]; //динамический массив указателей на строки
	for (int i = 0; i < n; i++) {
		p[i] = new int[m]; //выделение памяти для каждой строки по числу столбцов
	}
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
			vvod(p, n, m);  break;
		case 2:
			oper(p, n, m); 	break;
		case  3:
			vivod(p, n, m);  break;
		case  4:
			cout << "Good-Bye!";
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		delete[] p[i]; //удаление строк
	}
	delete[] p; //высвобождение памяти 
}
void vvod(int **p, int n, int m) { //вводим матрицу
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	}
}
int oper(int **p, int n, int m) {
	int a = 0, b = 0, h = 0;
	for (int i = 0; i < n; i++) { //считаем сумму чисел элементов последнего столбца
		int j = m - 1;
		h = p[i][j];
		while (h != 0) {
			a = h % 10;
			b = b + a;
			h /= 10;
		}
		p[i][j + 1] = b; //записываем значения в новый столбец
		b = 0;
	}
	int c = 0;
	bool flag = true; //сортируем двумерный массив
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (p[i][m] > p[i + 1][m]) {
				int * x = p[i];
				p[i] = p[i + 1];
				p[i + 1] = x;
				flag = true;
			}
		}
	}
	return 0;
}

void vivod(int **p, int n, int m) { //выводим матрицу
	cout << "Poluch Matrix " << endl; //выводим полученную матрицу
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(5);
			cout << p[i][j];
		}
		cout << endl;
	}
}


