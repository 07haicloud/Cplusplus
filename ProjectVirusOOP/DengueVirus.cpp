#include "DengueVirus.h"
#include<iostream>
#include <stdlib.h>
#include <time.h> 


DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
}

DengueVirus::~DengueVirus()
{
	DoDie();
}

DengueVirus::DengueVirus(const DengueVirus * dengue): Virus()
{
	this->m_protein[4] = dengue->m_protein[4];

}

void DengueVirus::DoBorn() {
	cout << "Create a  Dengue virus\n";
	this->LoadADNInformation();
	srand(time(0));
	int random = rand() % 3 + 1;
	if (random == 1) {
		this->m_protein[4] = 'NS3';
	}
	else if (random == 2) {
		this->m_protein[4] = 'NS5';
	}
	else {
		this->m_protein[4] = 'E)';
	}
}

void DengueVirus::DoDie()
{
	cout << "Killer";
	delete this;
}

list<Virus*> DengueVirus::DoClone()
{
	cout << "Do Clone a Dengue Virus\n";
	DengueVirus *a = new DengueVirus(this);
	list<Virus*> temp;
	temp.push_back(a);
	temp.push_back(a);
	temp.push_back(a);
	return temp;
}

int DengueVirus::InitResistance()
{
	if (this->m_protein[4] == 'NS3') {
		int resistance = rand() % (10 - 1 + 1) + 1;
		this->setM_resistance(resistance);
	}
	else if (this->m_protein[4] == 'NS5') {
		int resistance = rand() % (20 - 11 + 1) + 11;
		this->setM_resistance(resistance);
	}
	else {
		int resistance = rand() % (30 - 21 + 1) + 21;
		this->setM_resistance(resistance);
	}
	return this->getM_resistance();
}



