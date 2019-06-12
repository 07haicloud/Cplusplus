#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Define struct and assign array  for students 
struct Student {
	int id;
	string name;
	float score;
};


//DispalyDefault
void DisplayDefault(int &choose) {
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
//Input Students And Check Funtions

void CheckNumberStudents(int &numStudents) {
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

bool CheckDuplicatedID(int index, Student newStudent, Student *students) {
	for (int i = 0; i < index; i++) {
		if (newStudent.id == students[i].id) {
			return true;
		}
	}
	return false;
}
void input(Student *students, int &index, int &numStudents) {
	cout << "Enter number of students: ";
	cin >> numStudents;
	numStudents += index;
	CheckNumberStudents(numStudents);
	int i = index;
	Student newStudent;
	for (; i<numStudents; i++) {
		cout << "\nNo." << i + 1 << endl;
		cout <<left<<setw(10)<< "\id: ";
		cin >> newStudent.id;
		while (CheckDuplicatedID(index, newStudent, students)) {
			cout << "Duplicated! Please Enter ID Of Students Again: ";
			cin >> newStudent.id;
		}
		cout << left << setw(10)<< "name: ";
		cin.ignore();
		getline(cin, newStudent.name);
		cout << left << setw(10) << "score: ";
		cin >> newStudent.score;
		
		CheckLitmitScore(newStudent);
		students[i] = newStudent;
		index++;
	}
}

// Display List
void DisplayList(Student *students, int &index) {
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
string ReplaceString(string content ,char after, char before) {
	for (int i = 0; i < content.size(); i++) {
		if (content.at(i) == after) {
			content.at(i) = before;
		}
	}
	return content;
}

void SaveFile(string FileName, Student * students, int index) {
	ofstream fileOut;
	fileOut.open(FileName, std::ios_base::out);
	if (fileOut.is_open()) {
		fileOut << index << endl;
		for (int i = 0; i < index; i++) {
			fileOut << students[i].id<<" ";
			string tempName = ReplaceString(students[i].name, ' ', '_');
			fileOut << tempName<<" ";
			fileOut << students[i].score<<endl;
		}
		cout << "Save susscess to file";
		fileOut.close();
	}
	else {
		cout << "Error";
	}
	
}
void main()
{
	int numStudents = 0;
	int choose = -1;
	Student *students = new Student[100];
	int index =0;
	bool exit = 0;
	string fileName = "ListStudent.txt";


	//static int index = 0;
	while (1) {
		switch (choose) {
		case 1:	//input
			input(students,index, numStudents);
			DisplayDefault(choose);
			break;
		case 2:
			DisplayList(students, index);
			DisplayDefault(choose);
			break;
		case 3:// Save file
			SaveFile(fileName, students, index);
			DisplayDefault(choose);
			break;
		case 4: //Load from file

			DisplayList(students, index);
			break;
		case 0:
			exit = 1;
			break;
		default:
			DisplayDefault(choose);
			break;
		}
		// Check Choose Case 0
		if (exit) {
			break;
		}
	}
	system("PAUSE");
}