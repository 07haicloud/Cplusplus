#include "FluVirus.h"
#include<iostream>
#include <stdlib.h>
#include <time.h> 

FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}

FluVirus::~FluVirus()
{

}

FluVirus::FluVirus(const FluVirus * fluVirus) :Virus() {
	this->m_color = fluVirus->m_color;
}

void FluVirus::DoBorn() {
	cout << "Create a  Flu virus\n";
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
	delete this;
}

list<Virus*> FluVirus::DoClone()
{
	cout << "DoClone Flue Virus\n";
	FluVirus *a = new FluVirus(this);
	list<Virus*> temp;
	temp.push_back(a);
	temp.push_back(a);
	return temp;
}

int FluVirus::InitResistance() {
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
