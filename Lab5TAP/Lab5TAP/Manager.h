#pragma once
#include "Angajat.h"

class Manager :Angajat
{
private:
	int nrSubordonati;


public:
	Manager(double tarifOrar, int nrOre) : Angajat(tarifOrar, nrOre) {

	}
	Manager(const Angajat& other) :Angajat(other) {

	}

	double getSalar() override;
	double getTarifOrar()override;

};

