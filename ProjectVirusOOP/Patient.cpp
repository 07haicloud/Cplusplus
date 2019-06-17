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
	int sumResistance = 0;
	list <Virus*> ::iterator it, it2;
	list<Virus*> new_virusList ;
	list<Virus*> new_virusList1 ;
	cout << "Take Medicine: "<<medicine_resistance<<endl;
	new_virusList1.clear();
	new_virusList.clear();

	//
	for (it = m_virusList.begin(); it != m_virusList.end(); it++ ) {
		cout<<"medicine : "<<(*it)->ReduceResistance(medicine_resistance)<<endl;
		if ((*it)->ReduceResistance(medicine_resistance) > 0) {
			new_virusList1 = (*it)->DoClone();
			for (it2 = new_virusList1.begin(); it2 != new_virusList1.end(); it2++) {
				new_virusList.push_back(*it2);
			}
		}
	}
	if (new_virusList.size() > 0) {
		m_virusList.clear();
		for (it2 = new_virusList.begin(); it2 != new_virusList.end(); it2++) {
			m_virusList.push_back(*it2);
			sumResistance += (*it2)->getM_resistance();
		}
		if (sumResistance > this->m_resistance) {
			cout << "Patient is Dead by virus"<<endl;
			this->setM_state(0);
		}
		else {
			cout << "Resistance's Patient: " << this->m_resistance<<endl;
			this->setM_state(0);
		}
	}
	else {
		cout << "All Virus is Dead"<<endl;
		this->setM_state(0);
	}
}

void Patient::DoDie()
{
	delete this;
}


