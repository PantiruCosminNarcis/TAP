#include "Banca.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Banca banca1;
    Banca banca2;


    banca1.setCodBanca("BC123");
    banca2.setCodBanca("BC456");


    Client client1;
    Client client2;


    client1.setNume("Popescu");
    client1.setPrenume("Ion");
    client1.setAdresa("Str. Primaverii, Nr. 1");
    client1.setNrConturi(2);

    client2.setNume("Ionescu");
    client2.setPrenume("Maria");
    client2.setAdresa("Str. Libertatii, Nr. 10");
    client2.setNrConturi(2);


    ContBancar contRonClient1;
    ContBancar contEuroClient1;


    contRonClient1.setNumarCont("RO01");
    contRonClient1.setMoneda("RON");
    contRonClient1.setSuma(1000);

    contEuroClient1.setNumarCont("EU01");
    contEuroClient1.setMoneda("EUR");
    contEuroClient1.setSuma(500);


    std::vector<ContBancar> conturiClient1;
    conturiClient1.push_back(contRonClient1);
    conturiClient1.push_back(contEuroClient1);
    client1.setConturi(conturiClient1);


    ContBancar contRonClient2;
    ContBancar contLeiClient2;


    contRonClient2.setNumarCont("RO02");
    contRonClient2.setMoneda("RON");
    contRonClient2.setSuma(2000);

    contLeiClient2.setNumarCont("RO03");
    contLeiClient2.setMoneda("RON");
    contLeiClient2.setSuma(1500);


    std::vector<ContBancar> conturiClient2;
    conturiClient2.push_back(contRonClient2);
    conturiClient2.push_back(contLeiClient2);
    client2.setConturi(conturiClient2);



    return 0;
}
