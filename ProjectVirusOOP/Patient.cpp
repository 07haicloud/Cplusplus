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
	int SizeListVirus = 0;
	int SumResistanceVirus = 0;
	list <Virus*> ::iterator k;
	cout << "\tMedicine: " << medicine_resistance << endl;
	for (list <Virus*> ::iterator i = this->m_virusList.begin(); i != this->m_virusList.end();) {
		
		(*i)->ReduceResistance(medicine_resistance);
		
		if ((*i)->getM_resistance() > 0) {
			list <Virus*> List_Clone;
			List_Clone.clear();
			List_Clone = (*i)->DoClone();
			
			for (list <Virus*>::iterator j = List_Clone.begin(); j != List_Clone.end(); j++) {
				this->m_virusList.push_front(*j);
				SizeListVirus++;
				cout << "-Ressistance:" << (*j)->getM_resistance() << endl;
			}
			cout << endl << SizeListVirus << " " << endl;
			i++;
		}
		else {
			SizeListVirus++;
			k = i;
			k++;
			this->m_virusList.erase(i);
			i = k;
		}
	}
	cout << "size1 : " << SizeListVirus << endl;
	SizeListVirus = 0;

	for (list <Virus*> ::iterator i = this->m_virusList.begin(); i != this->m_virusList.end(); i++) {
		cout<<"\t\t-Resistance: "<<(*i)->getM_resistance()<<endl;
		SumResistanceVirus += (*i)->getM_resistance();
		SizeListVirus++;
		cout << SizeListVirus << " ";
	}
	cout << "size2 : " << SizeListVirus << endl;

	if (m_virusList.size() > 0) {
		if (SumResistanceVirus > this->m_resistance) {
			cout << "Patient is Dead by virus" << endl;
			this->setM_state(0);
		}
		else {
			cout << "Total Resistance's Viruss: " <<SumResistanceVirus<<endl;
			cout << "Resistance's Patient: " <<this->m_resistance << endl;
		}
	}
	else {
		cout << "All Virus is Dead" << endl;
		this->setM_state(0);
	}
}

void Patient::DoDie()
{
	delete this;
}


