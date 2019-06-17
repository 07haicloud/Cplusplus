#include "Virus.h"

Virus::Virus()
{
}

Virus::~Virus()
{
}

Virus::Virus(char * m_dna, int m_resistance) {
	this->m_dna = m_dna;
	this->m_resistance = m_resistance;
}

//Coppy constructor
Virus::Virus(const Virus &virus) {
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}

void Virus::LoadADNInformation() {
	ifstream inFile;
	char result[100];
	inFile.open("ATGX.bin");
	if (inFile.is_open()) {
		inFile >> result;
		this->m_dna = result;
		inFile.close();
	}
	else {
		cout << "Load Error\n";
	}
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