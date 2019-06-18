#include "Virus.h"

Virus::Virus()
{
}

Virus::~Virus()
{
	delete[]m_dna;
	m_dna = NULL;
}

Virus::Virus(char * m_dna, int m_resistance) {
	this->m_dna = m_dna;
	this->m_resistance = m_resistance;
}

//Coppy constructor
Virus::Virus(const Virus &virus) {
	m_dna = new char[strlen(virus.m_dna)+1];
	for (int i = 0; i < strlen(virus.m_dna); i++) {
		m_dna[i] = virus.m_dna[i];
	}
	this->m_dna[strlen(virus.m_dna)] = '\0';
	this->m_resistance = virus.m_resistance;
}

void Virus::LoadADNInformation() {
	ifstream inFile;
	char result[100];
	inFile.open("ATGX.bin");
	std::string str;
	if (inFile.is_open()) {
		inFile >> str;
		inFile.close();
	}
	else {
		cout << "Load Error\n";
	}
	m_dna = new char[str.size() + 1];
	for (int i = 0; i < str.size(); i++)
	{
		this->m_dna[i] = str[i];
	}
	this->m_dna[str.size()] = '\0';
}

int Virus::ReduceResistance(int medicine_resistance) {
	this->m_resistance -= medicine_resistance;
	return this->m_resistance;
}

int Virus::getM_resistance() {
	return this->m_resistance;
}

void Virus::setM_resistance(int resistance) {
	this->m_resistance = resistance;
}