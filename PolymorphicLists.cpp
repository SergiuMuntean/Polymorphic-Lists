#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

enum optiune {
	iesire, inserareDecoratiuni, afisareDecoratiuni, cautareDecoratiuneDupaSerie, stergereArbustDupaPret, modificarePretStatuetaDupaAutorul
};

class decoratiuni {
protected:
	int serieUnica;
	double pret;
public:
	decoratiuni(int serieUnica, double pret) {
		this->serieUnica = serieUnica;
		this->pret = pret;
	}
	decoratiuni() {};
	int getSerieUnica() const {
		return serieUnica;
	}
	double getPret() const {
		return pret;
	}
	void setSerie(int serieUnica) {
		this->serieUnica = serieUnica;
	}
	void setPret(double pret) {
		this->pret = pret;
	}
	virtual void mesaj() {
		cout << "Am creat o decoratiune." << endl;
	}
	virtual void afisare() {
		cout << "Seria unica este: " << serieUnica << endl;
		cout << "Pretul este: " << pret << endl;
	}
	virtual int esteDecoratiune() {
		return 1;
	}
	virtual const char* getAutor() const {
		return " ";
	}
};

class statuete : public decoratiuni {
private:
	int inaltime;
	char material[30];
	char autor[30];
public:
	statuete(int inaltime, const char* material, const char* autor, int serieUnica, double pret)
		: decoratiuni(serieUnica, pret) {
		this->inaltime = inaltime;
		strcpy(this->material, material);
		strcpy(this->autor, autor);
	}
	statuete() {};
	int getInaltime() const {
		return inaltime;
	}
	const char* getMaterial() const {
		return material;
	}
	const char* getAutor() const override {
		return autor;
	}
	void setInaltime(int inaltime) {
		this->inaltime = inaltime;
	}
	void setMaterial(const char* material) {
		strcpy(this->material, material);
	}
	void setAutor(const char* autor) {
		strcpy(this->autor, autor);
	}
	void mesaj() override {
		cout << "Am creat o statueta." << endl;
	}
	void afisare() override {
		cout << "Seria unica este: " << serieUnica << endl;
		cout << "Pretul este: " << pret << endl;
		cout << "Inaltimea este: " << inaltime << endl;
		cout << "Materialul este: " << material << endl;
		cout << "Autorul este: " << autor << endl;
	}
	int esteDecoratiune() override {
		return 2;
	}
};

class arbusti : public decoratiuni {
private:
	char denumire[30];
	char tip[10];
public:
	arbusti(const char* denumire, const char* tip, int serieUnica, double pret)
		: decoratiuni(serieUnica, pret) {
		strcpy(this->denumire, denumire);
		strcpy(this->tip, tip);
	}
	arbusti() {};
	const char* getDenumire() const {
		return denumire;
	}
	const char* getTip() const {
		return tip;
	}
	void setDenumire(const char* denumire) {
		strcpy(this->denumire, denumire);
	}
	void setTip(const char* tip) {
		strcpy(this->tip, tip);
	}
	void mesaj() override {
		cout << "Am creat un arbust." << endl;
	}
	virtual void afisare() override {
		cout << "Seria unica este: " << serieUnica << endl;
		cout << "Pretul este: " << pret << endl;
		cout << "Denumirea este: " << denumire << endl;
		cout << "Tipul este: " << tip << endl;
	}
	int esteDecoratiune() override {
		return 3;
	}
};

struct NodDecoratiune {
	decoratiuni* data;
	NodDecoratiune* next;

	void init(decoratiuni* decor) {
		data = decor;
		next = nullptr;
	}
};

void inserare(NodDecoratiune*& cap, decoratiuni* decoratiune) {
	NodDecoratiune* nodNou = new NodDecoratiune;
	nodNou->init(decoratiune);
	nodNou->next = cap;
	cap = nodNou;
}

void afisare(NodDecoratiune* cap) {
	NodDecoratiune* curent = cap;
	while (curent != NULL) {
		curent->data->afisare();
		cout << endl;
		curent = curent->next;
	}
}

void citesteDecoratiune(int& serieUnica, double& pret) {
	cout << endl;
	cout << "Introduceti seria (numar intreg): ";
	cin >> serieUnica;
	getchar();
	cout << "Introduceti pretul (numar rational): ";
	cin >> pret;
	getchar();
}

void citesteStatueta(int& serieUnica, double& pret, int& inaltime, char* material, char* autor) {
	citesteDecoratiune(serieUnica, pret);
	cout << "Introduceti inaltimea (numar intreg): ";
	cin >> inaltime;
	getchar();
	cout << "Introduceti materialul (litere): ";
	cin.getline(material, 30);
	cout << "Introduceti autorul (litere): ";
	cin.getline(autor, 30);
}

void citesteArbust(int& serieUnica, double& pret, char* denumire, char* tip) {
	citesteDecoratiune(serieUnica, pret);
	cout << "Introduceti denumire (litere): ";
	cin.getline(denumire, sizeof(denumire));
	cout << "Introduceti tipul (litere): ";
	cin.getline(tip, sizeof(tip));
}

bool cautaDecoratiuniDupaSerie(NodDecoratiune* cap, int serie) {
	cout << "Se cauta fanionul cu seria: " << serie << endl << "..................." << endl;
	NodDecoratiune* temp = cap;
	if (temp == NULL) {
		cout << "Elementul nu a fost gasit in lista de decoratiuni." << endl;
		return false;
	}
	bool gasit = false;
	while (temp != NULL) {
		if (temp->data->getSerieUnica() == serie) {
			cout << "A fost gasita decoratiunea cu seria: " << serie << endl;
			gasit = true;
			return gasit;
		}
		temp = temp->next;
	}
	if (!gasit) {
		cout << "Nu s-a gasit decoratiunea cu seria: " << serie << endl;
		return gasit;
	}
	return gasit;
}

void stergereArbustiDupaPret(NodDecoratiune*& cap, double fanion) {
	NodDecoratiune* curent = cap;
	NodDecoratiune* anterior = nullptr;
	bool gasit = false;
	while (curent != NULL) {
		if (curent->data->esteDecoratiune() == 3) {
			if (curent->data->getPret() == fanion) {
				NodDecoratiune* deSters = curent;
				if (anterior != NULL) {
					anterior->next = curent->next;
				}
				else {
					cap = curent->next;
				}
				curent = curent->next;
				delete deSters->data;
				delete deSters;
				gasit = true;
			}
			else {
				anterior = curent;
				curent = curent->next;
			}
		}
		else {
			anterior = curent;
			curent = curent->next;
		}
	}
	if (gasit) {
		cout << "Arbustul cu pretul: " << fanion << " a fost sters." << endl;
	}
	else {
		cout << "Nu am gasit vreun arbust cu acest pret." << endl;
	}
}

void modificarePretStatuetaDupaAutor(const char* autor, NodDecoratiune* cap) {
	if (cap == NULL) {
		cout << "Lista de statuete este goala..." << endl;
		return;
	}
	cout << "Se cauta autorul: " << autor << endl << "..................." << endl;
	NodDecoratiune* temp = cap;
	bool gasit = false;
	while (temp != NULL) {
		if (temp->data->esteDecoratiune() == 2) {
			if (strcmp(temp->data->getAutor(), autor) == 0) {
				cout << "Statueta cu autorul: " << autor << " a fost gasita." << endl;
				cout << "Introduceti noul pret: " << endl;
				double pret;
				cin >> pret;
				getchar();
				if (pret < 0) {
					cout << "Pretul nu poate fi negativ! Operatiunea a fost anulata." << endl;
					return;
				}
				temp->data->setPret(pret);
				cout << "Pretul a fost actualizat cu succes!" << endl;
				gasit = true;
				break;
			}
		}
		temp = temp->next;
	}

	if (!gasit) {
		cout << "Autorul nu a fost gasit in lista!" << endl;
	}
}

void meniu(int& opt) {
	cout << endl;
	cout << "Optiunile disponibile..." << endl;
	cout << "1 - Inserare Tip Decoratiune" << endl << "2 - Afisare Decoratiuni" << endl << "3 - Cautare Decoratiune Dupa Serie" << endl;
	cout << "4 - Stergere Arbust Dupa Pret" << endl << "5 - Modificare Pret Statueta Dupa Autor" << endl;
	cout << "0 - Iesire din program" << endl;
	cout << "Introduceti optiunea: ";
	cin >> opt;
	getchar();
}

static int contor = 0;

int main() {
	cout << "Bine ati venit la aplicatia magazinului nostru de gestionare a decoratiunilor." << endl;
	cout << "Mai jos aveti facilitatile oferite de catre aceasta." << endl;
	cout << endl;
	cout << "Introduceti ce tip de date se cere va rugam, pentru o buna functionalitate (numar intreg, numar rational, litere/sir de caractere)..." << endl;
	cout << endl;
	int opt = 7;
	NodDecoratiune* cap = nullptr;
	do {
		meniu(opt);
		if (opt == 0) {
			return 0;
		}
		while (opt < 1 || opt > 5) {
			cout << "Optiunea introdusa a fost gresita." << endl;
			meniu(opt);
			if (opt == 0) {
				return 0;
			}
		}
		cout << "Optiunea dumneavoastra a fost introdusa..." << endl;
		cout << endl;
		switch (opt) {
		case inserareDecoratiuni: { //optiunea 1
			cout << endl;
			cout << "Adaugati va rog o decoratiune in lista..." << endl;
			cout << "1 - Insereaza statueta / 2 - Insereaza arbust" << endl;
			cout << "Suboptiunea ta este: ";
			int op;
			cin >> op;
			getchar();
			while (op != 1 && op != 2) {
				cout << "Optiune invalida, reintroduceti optiunea." << endl;
				cout << "Optiunea ta este: ";
				cin >> op;
			}
			switch (op) {
			case 1: {
				int serieUnica; double pret; int inaltime; char material[30]; char autor[30];
				citesteStatueta(serieUnica, pret, inaltime, material, autor);
				statuete* decoratiune = new statuete(inaltime, material, autor, serieUnica, pret);
				inserare(cap, decoratiune);
				break;
			}
			case 2: {
				int serieUnica; double pret; int inaltime; char denumire[30]; char tip[30];
				citesteArbust(serieUnica, pret, denumire, tip);
				arbusti* decoratiune = new arbusti(denumire, tip, serieUnica, pret);
				inserare(cap, decoratiune);
				break;
			}
			case 0: {
				break;
			}
			}
			break;
		}
		case afisareDecoratiuni: { //optiunea 2
			cout << "Decoratiunile din lista sunt: " << endl;
			afisare(cap);
			break;
		}
		case cautareDecoratiuneDupaSerie: { //optiunea 3
			int serie;
			cout << "Introduceti seria de cautat: ";
			cin >> serie;
			getchar();
			cautaDecoratiuniDupaSerie(cap, serie);
			break;
		}
		case stergereArbustDupaPret: { //optiunea 4
			double pret;
			cout << "Introduceti pretul: ";
			cin >> pret;
			getchar();
			stergereArbustiDupaPret(cap, pret);
			break;
		}
		case modificarePretStatuetaDupaAutorul: { //optiunea 5
			char autor[30];
			cout << "Introduceti autorul: ";
			cin.getline(autor, 30);
			modificarePretStatuetaDupaAutor(autor, cap);
			break;
		}
		case iesire: { //optiunea 0
			return 0;
		}
		default: cout << "Optiune invalida!" << endl; break;
		}
	} while (opt);
	return 0;
}