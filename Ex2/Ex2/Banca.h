// BANCA.H
#pragma once
#ifndef BANCA_H
#define BANCA_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Operatiuni {
public:
    virtual float getSumaTotala() = 0;
    virtual float getDobanda() = 0;
    virtual void depunere(float suma) = 0;
    virtual void extragere(float suma) = 0;
    virtual ~Operatiuni() {}
};

class ContBancar;

class Client {
public:
    Client(const Client& other)
        : nume(other.nume), prenume(other.prenume), adresa(other.adresa), nrConturi(other.nrConturi), conturi(other.conturi) {}

    std::string getNume() const {
        return nume;
    }

    void setNume(const std::string& nume) {
        this->nume = nume;
    }

    std::string getPrenume() const {
        return prenume;
    }

    void setPrenume(const std::string& prenume) {
        this->prenume = prenume;
    }

    std::string getAdresa() const {
        return adresa;
    }

    void setAdresa(const std::string& adresa) {
        this->adresa = adresa;
    }

    unsigned getNrConturi() const {
        return nrConturi;
    }

    void setNrConturi(unsigned nrConturi) {
        this->nrConturi = nrConturi;
    }

    std::vector<ContBancar>& getConturi() {
        return conturi;
    }

    void setConturi(const std::vector<ContBancar>& conturi) {
        this->conturi = conturi;
    }

private:
    std::string nume;
    std::string prenume;
    std::string adresa;
    unsigned nrConturi;
    std::vector<ContBancar> conturi;
};

class Banca : public Operatiuni {
public:
    Banca(const Banca& other)
        : codBanca(other.codBanca), nrClienti(other.nrClienti), clienti(other.clienti) {}

    std::string getCodBanca() const {
        return codBanca;
    }

    void setCodBanca(const std::string& codBanca) {
        this->codBanca = codBanca;
    }

    unsigned getNrClienti() const {
        return nrClienti;
    }

    void setNrClienti(unsigned nrClienti) {
        this->nrClienti = nrClienti;
    }

    std::vector<Client>& getClienti() {
        return clienti;
    }

    void setClienti(const std::vector<Client>& clienti) {
        this->clienti = clienti;
    }

    float getSumaTotala() override {
        float sumaTotala = 0.0f;
        for (const auto& client : clienti) {
            sumaTotala += client.getNrConturi();
        }
        return sumaTotala;
    }

    float getDobanda() override {

        return getSumaTotala() * 0.02f;
    }

    void depunere(float suma) override {

    }

    void extragere(float suma) override {

    }

private:
    std::string codBanca;
    unsigned nrClienti;
    std::vector<Client> clienti;
};

class ContBancar : public Operatiuni {
public:
    void transfer(ContBancar& contDest, float suma);
    ContBancar(const ContBancar& other)
        : suma(other.suma), moneda(other.moneda), numarCont(other.numarCont) {}

    std::string getNumarCont() const {
        return numarCont;
    }

    void setNumarCont(const std::string& numarCont) {
        this->numarCont = numarCont;
    }

    float getSuma() const {
        return suma;
    }

    void setSuma(float suma) {
        this->suma = suma;
    }

    std::string getMoneda() const {
        return moneda;
    }

    void setMoneda(const std::string& moneda) {
        this->moneda = moneda;
    }

    float getSumaTotala() override {
        return suma;
    }

    float getDobanda() override {
        return 0.0f;
    }

    void depunere(float sumaDepusa) override {
        suma += sumaDepusa;
    }

    void extragere(float sumaExtrasa) override {
        if (sumaExtrasa <= suma) {
            suma -= sumaExtrasa;
        }
        else {
            std::cout << "Fonduri insuficiente pentru extragere!" << std::endl;
        }
    }

private:
    std::string numarCont;
    float suma;
    std::string moneda; // ron sau euro
};

#endif // BANCA_H
