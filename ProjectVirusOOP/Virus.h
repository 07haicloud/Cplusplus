#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	virtual ~Virus();
	Virus(char * m_dna, int m_resistance);
	Virus(const Virus &virus);
	void LoadADNInformation();
	int ReduceResistance(int medicine_resistance);
	int getM_resistance();
	void setM_resistance(int resistance);
	
	virtual void DoBorn() =0;
	virtual list<Virus *>  DoClone() = 0;
	virtual void DoDie() = 0;
	virtual int InitResistance() = 0;
};

