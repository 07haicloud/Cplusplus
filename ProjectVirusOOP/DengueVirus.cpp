#include "DengueVirus.h"
#include<iostream>
#include <stdlib.h>
#include <time.h> 
#include <iomanip>


DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
	cout << "Resistance: " << this->getM_resistance() << endl;
}

DengueVirus::~DengueVirus()
{
	DoDie();
}

DengueVirus::DengueVirus(const DengueVirus & dengue): Virus(dengue)
{
	m_protein[4] = dengue.m_protein[4];

}

void DengueVirus::DoBorn() {
	cout <<"\t\t"<<left<<setw(30)<< "Create a  Dengue virus. ";
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
	
	DengueVirus *a = new DengueVirus(*this);
	list<Virus*> temp;
	temp.push_back(a);
	cout << "\t\t" << left<<setw(20)<<"Dengue Virus.  "<< left << setw(20)<<"Resistance:"<<this->getM_resistance()<<endl;
	temp.push_back(a);
	cout << "\t\t" << left << setw(20) << "Dengue Virus. " << left << setw(20) << "Resistance:" << this->getM_resistance() << endl;
	temp.push_back(a);
	cout << "\t\t" << left << setw(20) << "Dengue Virus. " << left << setw(20) << "Resistance:" << this->getM_resistance() << endl;
	return temp;
}

int DengueVirus::InitResistance()
{
	srand(time(0));
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



