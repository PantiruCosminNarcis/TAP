#include "Angajat.h"
#include "Manager.h"

int main() {
	Angajat* a1 = new Angajat(12.5, 30);
	Manager manager(20.1, 40);



	std::cout << "Numarul de ore pentru manager: " << manager.getTarifOrar() << std::endl;


	std::cout << "Salariul pentru manager: " << manager.getSalar() << std::endl;

	return 0;



	delete a1;
}