#pragma once
#include<list>
#include"Virus.h"
#include"FluVirus.h"
#include"DengueVirus.h"
#include<Windows.h>
class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
	
public:
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
	int getM_state() {
		return this->m_state;
	}
	void setM_state(int newState) {
		this->m_state = newState;
	}
	Patient();
	~Patient();
};

