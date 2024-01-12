#pragma once
#include <iostream>

class Angajat
{
private:
	double tarifOrar = 5.5;
	int nrOre;

public:
	Angajat(double tarifOrar, int nrOre);
	Angajat(const Angajat& other);
	~Angajat();

	virtual double getSalar();
	virtual double getTarifOrar();




	//suprascriere operatori

	friend std::istream& operator>>(std::istream& input, Angajat& angajat); //Citire
	friend std::ostream& operator<<(std::ostream& output, const Angajat& angajat); //Scriere
	Angajat& operator=(const Angajat& other);//Atribuire
};

