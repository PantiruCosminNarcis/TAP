#include "Manager.h"


Manager::Manager(double tarifOrar, int nrOre) : Angajat(tarifOrar, nrOre) {

}
Manager::Manager(const Angajat& other) : Angajat(other) {

}

double Manager::getSalar() {
    return Angajat::getSalar() * 50 / 100;
}
