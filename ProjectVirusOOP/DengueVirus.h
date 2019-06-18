#pragma once
#include "Virus.h"
class DengueVirus :	public Virus
{
private:
	string m_protein;
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus & dengue);



	void DoBorn() override;
	void DoDie() override;
	list<Virus*> DoClone() override;
	int InitResistance() override;
};

