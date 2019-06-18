#include"Patient.h"
#include<iostream>
#include <ctime>
#include<vld.h>
using namespace std;
void main() {
	Patient p;
	int t = 0;
	srand(time(NULL));
	while (p.getM_state() == 1)
	{
		cout<<"Take Medicine (0 = NO, 1 = YES): ";
		cin >> t;
		if (t == 1)
		{
			int min = 1;
			int max = 5;
			srand(time(NULL));
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(1);
		}
	}
	system("pause");
}