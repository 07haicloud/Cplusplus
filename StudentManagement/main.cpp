#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

// Define struct and assign array  for students 
struct Student {
	int id;
	string name;
	float score;
};
Student *students = new Student[100];

//DispalyDefault
int choose = -1;
void DisplayDefault() {
	cout << "----------------MENU-----------" << endl;
	cout << "\t1. Input" << endl;
	cout << "\t2. Display" << endl;
	cout << "\t3. Save to file" << endl;
	cout << "\t4. Load from file" << endl;
	cout << "\t0. Exit" << endl;
	cout << "-------------------------------" << endl;
	cout << "Choose: ";
	cin >> choose;
}
static int index = 0;

//input
int numStudents = 0;
void CheckNumberStudents() {
	while (numStudents <= 0) {
		cout << "Please Enter Number Of Students again: ";
		cin >> numStudents;
	}
}
void CheckLitmitScore(Student &newStudent) {
	while (newStudent.score<0 || newStudent.score>10) {
		cout << "Please Enter Score of student again: ";
		cin >> newStudent.score;
	}
}

bool CheckDuplicatedID(int index, Student newStudent) {
	for (int i = 0; i < index; i++) {
		if (newStudent.id == students[i].id) {
			return true;
		}
	}
	return false;
}
void input(int &index) {
	cout << "Enter number of students: ";
	cin >> numStudents;
	numStudents += index;
	CheckNumberStudents();
	int i = index;
	Student newStudent;
	for (; i<numStudents; i++) {
		cout << "\nNo." << i + 1 << endl;
		cout << "\id: ";
		cin >> newStudent.id;
		while (CheckDuplicatedID(index, newStudent)) {
			cout << "Duplicated! Please Enter ID Of Students Again: ";
			cin >> newStudent.id;
		}
		cout << "name: ";
		cin.ignore();
		getline(cin, newStudent.name);
		cout << "score: ";
		cin >> newStudent.score;
		
		CheckLitmitScore(newStudent);
		students[i] = newStudent;
		index++;
	}
}

// Display List
void DisplayList(int &index) {
	//cout << index;
	cout << left << setw(10) << "ID";
	cout << left << setw(30) << "Name";
	cout << left << setw(10) << "Score"<<endl;
	for (int i = 0; i < index; i++) {
		cout << left << setw(10) << students[i].id;
		cout << left << setw(30) << students[i].name;
		cout << left << setw(10) << students[i].score<<endl;
	}
}
void main()
{
	int index =0;
	bool exit = 0;
	while (1) {
		switch (choose) {
		case 1:	//input
			input(index);
			DisplayDefault();
			break;
		case 2:
			DisplayList(index);
			DisplayDefault();
			break;
		case 0:
			exit = 1;
			break;
		default:
			DisplayDefault();

			break;
		}
		if (exit) {
			break;
		}
	}
	system("PAUSE");
}