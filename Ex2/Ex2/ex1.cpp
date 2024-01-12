#include "ex1.h"
#include <iostream>

using namespace std;
class Fractie
{
public:
	Fractie();
	Fractie(int numarator);
	Fractie(int numarator, int numitor);
	Fractie(const Fractie& alt);
	void displayFractie();
	int adunare(const Fractie& f);
	int scadere(const Fractie& f);
	int inmultire(const Fractie& f);
	int impartire(const Fractie& f);
	static  int cmmdc(int a, int b);
	void simplifica();
	void reciproc();
	bool egal(const Fractie&);

private:
	int numarator;
	int numitor;

};

Fractie::Fractie() {
	numarator = 0;
	numitor = 0;
}
Fractie::Fractie(int numarator) {
	this->numarator = numarator;
	numitor = 1;
}
Fractie::Fractie(int numarator, int numitor) {
	this->numarator = numarator;
	if (numitor != 0) {
		this->numitor = numitor;
	}
	else {
		cout << "Numitorul nu poate fi 0" << endl;
		this->numitor = 1;
	}
}

Fractie::Fractie(const Fractie& alt) {
	numarator = alt.numarator;
	numitor = alt.numitor;
}

void Fractie::displayFractie() {
	cout << numarator << "/" << numitor << endl;
}


int Fractie::adunare(const Fractie& f) {
	int rezNumarator = this->numarator * f.numitor + f.numarator * this->numitor;
	int rezNumitor = this->numitor * f.numitor;
	cout << "Rezultatul adunarii: " << rezNumarator << "/" << rezNumitor << endl;
	return rezNumarator;
}

int Fractie::scadere(const Fractie& f) {
	int rezNumarator = this->numarator * f.numitor - f.numarator * this->numitor;
	int rezNumitor = this->numitor * f.numitor;
	cout << "Rezultatul scaderii: " << rezNumarator << "/" << rezNumitor << endl;
	return rezNumarator;
}

int Fractie::inmultire(const Fractie& f) {
	int rezNumarator = this->numarator * f.numarator;
	int rezNumitor = this->numitor * f.numitor;
	cout << "Rezultatul inmultirii: " << rezNumarator << "/" << rezNumitor << endl;
	return rezNumarator;
}

int Fractie::impartire(const Fractie& f) {
	int rezNumarator = this->numarator * f.numitor;
	int rezNumitor = this->numitor * f.numarator;
	cout << "Rezultatul impartirii: " << rezNumarator << "/" << rezNumitor << endl;
	return rezNumarator;
}

int Fractie::cmmdc(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void Fractie::simplifica() {
	int cmmdcValue = cmmdc(this->numarator, this->numitor);
	this->numarator /= cmmdcValue;
	this->numitor /= cmmdcValue;
	cout << "Fractia simplificata: " << this->numarator << "/" << this->numitor << endl;
}

bool Fractie::egal(const Fractie& f) {
	return (this->numarator * f.numitor == f.numarator * this->numitor);
}

void Fractie::reciproc() {
	if (this->numarator != 0) {
		int temp = this->numarator;
		this->numarator = this->numitor;
		this->numitor = temp;
		cout << "Fractia reciproca: " << this->numarator << "/" << this->numitor << endl;
	}
	else {
		cout << "Nu se poate calcula fractia reciproca pentru 0." << endl;
	}
}



int main() {
	Fractie fractia(10, 2);
	Fractie fractie2(1, 4);
	fractia.displayFractie();

	fractia.adunare(fractie2);
	fractia.scadere(fractie2);
	fractia.inmultire(fractie2);
	fractia.impartire(fractie2);
	fractia.simplifica();
	fractia.egal(fractie2);
	fractia.reciproc();

	return 0;
}


