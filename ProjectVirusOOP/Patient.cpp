#include "Patient.h"
#include <iterator>
#include <ctime>
#include<time.h>

Patient::Patient()
{
	InitResistance();
	cout << " Resistance: "<<this->m_resistance<<endl;
	DoStart();
	m_state = 1;
}


Patient::~Patient()
{
}

void Patient::InitResistance()
{
	srand(time(NULL));
	this->m_resistance = rand() % (9000 - 1000 + 1) + 1000;
}

void Patient::DoStart()
{
	srand(time(0));
	int totalVirus = rand() % (20 - 10 + 1) + 10;
	cout << "Start with " << totalVirus << " virus" << endl;
	for (int i = 0; i < totalVirus; i++) {
		srand(time(0));
		Sleep(300);
		if ((rand() % 2 + 1) == 1) {
			m_virusList.push_back(new DengueVirus());
		}
		else {
			m_virusList.push_back(new FluVirus());
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	list <Virus*> ::iterator k;
	for (list <Virus*> ::iterator i = this->m_virusList.begin(); i != this->m_virusList.end();) {
		int ResistanceLate = (*i)->ReduceResistance(medicine_resistance);
		if (ResistanceLate > 0) {
			list <Virus*> List_Clone = (*i)->DoClone();
			for (list <Virus*>::iterator j = List_Clone.begin(); j != List_Clone.end(); j++) {
				this->m_virusList.push_back(*j);
			}
			i++;
		}
		else {
			k = i;
			k++;
			this->m_virusList.erase(i);
			i = k;
		}
	}
	for (list <Virus*> ::iterator i = this->m_virusList.begin(); i != this->m_virusList.end(); i++) {
		cout<<"resistance: "<<(*i)->getM_resistance()<<endl;
	}
}

void Patient::DoDie()
{
	delete this;
}


