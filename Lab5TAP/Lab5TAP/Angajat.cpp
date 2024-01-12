#include "Angajat.h"


Angajat::Angajat(double tarifOrar, int nrOre)
{
    this->nrOre = nrOre;
    this->tarifOrar = tarifOrar;
}
Angajat::Angajat(const Angajat& other)
{
    this->tarifOrar = other.tarifOrar;
    this->nrOre = other.nrOre;
}

Angajat::~Angajat() {

}

double Angajat::getSalar()
{
    return tarifOrar * nrOre;
}

double Angajat::getTarifOrar() {
    return tarifOrar;
}


//suprascrierea operatorilor implementare functii

std::istream& operator>>(std::istream& input, Angajat& angajat) {
    input >> angajat.tarifOrar >> angajat.nrOre;
    return input;
}//citire

std::ostream& operator<<(std::ostream& output, const Angajat& angajat) {
    output << "Tarif Orar: " << angajat.tarifOrar << ", Numar Ore: " << angajat.nrOre;
    return output;
}//scriere


Angajat& Angajat::operator=(const Angajat& other) {
    if (this != &other) {
        this->tarifOrar = other.tarifOrar;
        this->nrOre = other.nrOre;
    }
    return *this;
}//egal,atribuire