#include<iostream>
#include <sstream>
#include<string.h>
#define n 3
#include <cstdio>
#include <cstring>
using namespace std;
char userName1[100], userName2[100];
int A[n][n];
int winer = 0;

void inputUsername() {
	cout << "\nEnter Player 1 Name: ";
	cin >> userName1;
	cout << "Enter Player 2 Name: ";
	fflush(stdin);
	cin >> userName2;
	fflush(stdin);
}
void NextPlay(int player, int next) {
	while (A[next / 10][next % 10] != 0) {
		cout << "This is not Empty. Please Enter again: ";
		cin >> next;
	}
	A[next / 10][next % 10] = player;
}
void A_init() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			A[i][j] = 0;
		}
	}
}
bool checkRow() {
	for (int i = 0; i<n; i++) {
		if (A[i][0] != 0) {
			int temp = A[i][0];
			for (int j = 0; j<n; j++) {
				if (temp != A[i][j]) break;
				if (j == n - 1) {
					winer = temp;
					//cout<<"row "<<i;
					return true;
				}
			}
		}
		else continue;
	}
	return false;
}
bool checkColumn() {
	for (int i = 0; i<n; i++) {
		if (A[0][i] != 0) {
			int temp = A[0][i];
			for (int j = 0; j<n; j++) {
				if (temp != A[j][i]) break;
				if (j == n - 1) {
					winer = temp;
					//cout<<"column: "<<i;
					return true;
				}
			}
		}
	}
	return false;
}
bool checkDiagonal() {
	if (A[0][0] != 0) {
		int temp = A[0][0];
		for (int i = 0; i<n; i++) {
			if (A[i][i] == temp&&i == n - 1) {
				winer = temp;
				return true;
			}
			if (A[i][i] != temp) break;
		}
	}
	if (A[0][n - 1] != 0) {
		int temp = A[0][n - 1];
		for (int i = 0, j = n - 1; i<n, j >= 0; i++, j--) {
			if (A[i][j] == temp&&i == n - 1) {
				winer = temp;
				return true;
			}
			if (A[i][j] != temp) return false;
		}
	}
}

bool checkFull() {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (A[i][j] == 0) return false;
		}
	}
	return true;
}
void Display() {
	cout << "\n  ";
	for (int i = 0; i<n; i++) {
		cout << i << " ";
	}
	for (int i = 0; i<n; i++) {
		cout << "\n" << i << "|";
		for (int j = 0; j<n; j++) {
			if (A[i][j] == 0)
				cout << " |";
			else if (A[i][j] == 1) cout << "o|";
			else cout << "x|";
		}
	}
}

void main() {
	int choose = 0;
	int next;
	/*Intro Game*/
	cout << "Welcome To Tic-tac-toe game! Play with your way!";
	cout << "\n\nSELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):";
	cin >> choose;

	/* */
	switch (choose) {
	case 1:
		inputUsername();
		A_init(); // initialize
		Display();
		while (1) {
			cout << "\nYour Turn " << userName1 << " - O: ";
			cin >> next;
			NextPlay(1, next);
			Display();
			if (!checkFull() && !checkColumn() && !checkRow() && !checkDiagonal()) {
				cout << "\nYour Turn " << userName2 << " - x: ";
				cin >> next;
				NextPlay(2, next);
				Display();
				//
				if (checkFull() || checkColumn() || checkRow() || checkDiagonal()) {
					if (winer == 1)	cout << "\n-----------Winer: " << userName1;
					if (winer == 2)	cout << "\n-----------Winer: " << userName2;
					break;
				}
			}
			else {
				if (winer == 1)	cout << "\n-----------Winer: " << userName1;
				if (winer == 2)	cout << "\n-----------Winer: " << userName2;
				break;
			}

		}
		break;
	default:
		break;
	}
	system("pause");
}