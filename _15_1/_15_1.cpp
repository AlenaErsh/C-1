// Ex15_lab1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*���� ������� ���������� ��� �������������, ��� � ������������� ��������. 
������� ��� �������, ���������� ������ ������������� ��������*/

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
		cout <<"�������� ���������� ��������:" << endl;
		cout << "1. ������ ������� ������" << endl << "2. ��������� ������ ���������" << endl;
		cin >> answ;
		switch (answ)
		{
		case 1:Menu(); break;
		case 2:return;
		default:
			cout << "������. ������� ���������� ����� ������ ����." << endl;
			Ex(); 
			break;
		}
}


void Task() {
	int col = 0;
	bool fl;
	int j;
	for ( j = 0; j < m; j++) {
		fl = true;
		for (int i = 0; (i < n)&&(fl); i++) {
			fl=(mas[i][j] > 0) ? true : false;
		}
		if (fl) {
			col++;
			continue;
		}
		for (int i = 0; i < n; i++) {
			mas[i][j - col] = mas[i][j];
		}
	}
	if (col == m) {
		cout << "������. ������� ������� ������ �� ������������� �����." << endl;
		Ex();
		return;
	}
	cout<<endl;
	cout << "������� ������:" << endl;
	PrintMatr(n, j-col);	
}

void PrintMatr(int str, int col){
	cout << "------------------" << endl;
	cout << "�������: " << endl;
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
		cout << "������������ ������. ������� ����� ������ 0" << endl;
		return false;
	}
	return true;
}

void Razm (){
	do{
		cout << "������� N(���������� ����� �������)= "; cin >> n;
	} while (!Corr_Dann());
	do {
		cout << "������� M(���������� �������� �������)= "; cin >> m;
	} while (!Corr_Dann());
}

void InputMatr(){
	bool fl;
	cout << "������� ������� ����� ����� A �������� " << n << " x " << m << endl;
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
		cout << "�������� ���������� ����� ����:" << endl;
		cout << "1. ��������� ������� �������;" << endl;
		cout << "2. ��������� ������� ��������." << endl;
		cin >> answ;
		switch (answ) {
		case 1: 
			InputMatr(); 
			break;
		case 2: 
			Rand();
			break;
		default:
			cout << "������. ������� ���������� ����� ������ ����" << endl;
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

