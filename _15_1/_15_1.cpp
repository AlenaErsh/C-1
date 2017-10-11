// Ex15_lab1.cpp: определяет точку входа для консольного приложения.
//
/*Дана матрица содержащая как положительные, так и отрицательные элементы. 
Удалить все столбцы, содержащие только положительные элементы*/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "iomanip" 

using namespace std;

typedef int TElem;

void Ex();
void Task();
void PrintMatr(int str, int col);
bool Corr_Dann();
void Razm();
void InputMatr();
void Rand();
void Menu();

TElem mas[500][500];
int n = 0, m = 0;
bool ex ;

void Ex() {
	short answ;
		cout <<"Выберите дальнейшее действие:" << endl;
		cout << "1. Ввести матрицу заново" << endl << "2. Закончить работу программы" << endl;
		cin >> answ;
		switch (answ)
		{
		case 1:Menu(); break;
		case 2:return;
		default:
			cout << "Ошибка. Введите корректный номер пункта меню." << endl;
			Ex(); 
			break;
		}
}


void Task() {
	int col_only_positive = 0;
	bool only_positive;
	int j;
	for ( j = 0; j < m; j++) {
		only_positive = true;
		for (int i = 0; (i < n)&&(only_positive); i++) {
			if (mas[i][j] <= 0) {
				only_positive = false;
			}
		}
		if (only_positive) {
			col_only_positive++;
			continue;
		}
		for (int i = 0; i < n; i++) {
			mas[i][j - col_only_positive] = mas[i][j];
		}
	}
	if (col_only_positive == m) {
		cout << "Ошибка. Матрица состоит только из положительных чисел." << endl;
		Ex();
		return;
	}
	cout<<endl;
	cout << "Решение задачи:" << endl;
	PrintMatr(n, j-col_only_positive);	
}

void PrintMatr(int str, int col){
	cout << "------------------" << endl;
	cout << "Матрица: " << endl;
	for (int i = 0; i < str; i++){
		for (int j = 0; j < col; j++)
			cout << setw(4) << setprecision(2) << mas[i][j] << ' ';
		cout << endl;
	}
	if (ex) {
		ex = false;
		Task();
	}
}

bool Corr_Dann(){
	if (n < 1){
		cout << "Некорректные данные. Введите число больше 0" << endl;
		return false;
	}
	return true;
}

void Razm (){
	do{
		cout << "Введите N(количество строк матрицы)= "; cin >> n;
	} while (!Corr_Dann());
	do {
		cout << "Введите M(количество столбцов матрицы)= "; cin >> m;
	} while (!Corr_Dann());
}

void InputMatr(){
	bool fl;
	cout << "Введите матрицу целых чисел A размером " << n << " x " << m << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
				cout << "[" << i + 1 << "," << j + 1 << "]="; cin >> mas[i][j];
		}
	}
	ex = true;
	PrintMatr(n,m);
}

void Rand(){
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			mas[i][j] = rand() % 240 - 20;
		}
	}
	ex = true;
	PrintMatr(n,m);
}

void Menu(){
	short answ;
		cout << "Выберите подходящий пункт меню:" << endl;
		cout << "1. Заполнить матрицу вручную;" << endl;
		cout << "2. Заполнить матрицу рандомом." << endl;
		cin >> answ;
		switch (answ) {
		case 1: 
			InputMatr(); 
			break;
		case 2: 
			Rand();
			break;
		default:
			cout << "Ошибка. Введите корректный номер пункта меню" << endl;
			Menu();
			break;
		}
}


int main(){
	int n=0, m=0;
	setlocale(LC_ALL, "RUS");
	Razm();
	Menu();
	system("pause");
	return 0;
}

