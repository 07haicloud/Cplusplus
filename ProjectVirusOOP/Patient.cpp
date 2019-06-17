#include "Patient.h"
#include <iterator>


Patient::Patient()
{
	DoStart();
	m_state = 1;
}


Patient::~Patient()
{
}

void Patient::DoStart()
{
	int totalVirus = rand() % (20 - 10 + 1) + 10;
	for (int i = 0; i < totalVirus; i++) {
		//Sleep(1000);
		if ((rand() % (2 - 1 + 1) + 1) == 1) {
			m_virusList.push_back(new DengueVirus());
		}
		else {
			m_virusList.push_back(new FluVirus());
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	list <Virus *> ::iterator it, it2;
	list<Virus*> new_virusList;
	cout << "Take Medicine";
	
	for (it = m_virusList.begin(); it != m_virusList.end(); it++ ) {
		cout << (*it)->ReduceResistance(medicine_resistance)<<endl;
		if ((*it)->ReduceResistance(medicine_resistance) > 0) {
			
			list<Virus*> new_virusList1;
			new_virusList1.push_front();

			for(it2 = new_virusList1.begin(); it2 != new_virusList1.end(); it2++) {
				new_virusList.push_back(*it2);
			}
		}
	}
	m_virusList.clear();
	m_virusList = new_virusList;
}

void Patient::DoDie()
{
	delete this;
}


