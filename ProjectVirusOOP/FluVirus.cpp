#include "FluVirus.h"
#include<iostream>
#include <stdlib.h>
#include <time.h> 
#include<iomanip>

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
	cout << "Resistance: " << this->getM_resistance();
	cout << "\tcolor: " << this->m_color<<endl;
}

FluVirus::~FluVirus()
{
	DoDie();
}

FluVirus::FluVirus(const FluVirus & fluVirus) :Virus(fluVirus) {
	this->m_color = fluVirus.m_color;
}

void FluVirus::DoBorn() {
	cout << "\t\t" << left << setw(30) << "Create a  Flu virus. ";
	this->LoadADNInformation();
	srand(time(0));
	int random = rand() % 2 + 1;
	if (random == 1) {
		//Red Flu
		this->m_color = 0x0000ff;
	}
	else {
		//blue Flu
		this->m_color = 0xff0000;
	}
}

void FluVirus::DoDie()
{
	cout << "Killer Flu\n";
	m_color = 0;
}

list<Virus*> FluVirus::DoClone()
{
	FluVirus *a = new FluVirus(*this);
	list<Virus*> temp;
	temp.push_back(a);
	cout << "\t\t" << left << setw(20) << "Flu virus. " << left << setw(20) << "Resistance:" << this->getM_resistance() << endl;	
	return temp;
}

int FluVirus::InitResistance() {
	srand(time(NULL));
	if (this->m_color == 0x0000ff) {
		//random 10-20 for Red Flu
		int resistance = rand() % (20 - 10 + 1) + 10;
		this->setM_resistance(resistance);
	}
	else {
		//ramdom 10-15 for Blue Flu
		int resistance = rand() % (15 - 10 + 1) + 10;
		this->setM_resistance(resistance);
	}
	return this->getM_resistance();
}

