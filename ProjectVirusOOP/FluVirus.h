#pragma once
#include "Virus.h"
#include<list>
class FluVirus :	public Virus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	FluVirus(const FluVirus * fluVirus);
	void DoBorn() override;
	void DoDie() override;
	list<Virus*> DoClone() override;
	int InitResistance() override;
};

