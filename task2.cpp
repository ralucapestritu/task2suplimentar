#include <iostream>
#include <cstring>
using namespace std;

class aliment {
public:
    float greutate;
    float pret;
    char* denumire; // pointer pentru alocare din HEAP
    static int codProdus; // atribut static
    const int data_expirare; // atribut constant

    // Constructor fara parametrii
    aliment() : data_expirare(2025) {
        this->greutate = 450;
        this->pret = 11;
        this->denumire = new char[strlen("branza") + 1];
        strcpy_s(this->denumire, strlen("branza") + 1, "branza");
        codProdus++;
    }

    // Constructor cu 2 parametrii
    aliment(const char* denumire, int data) : data_expirare(data) {
        this->greutate = greutate;
        this->pret = pret;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        codProdus++;
    }

    // Constructor cu toti parametrii
    aliment(float greutate, const char* denumire, float pret, int data)
        : data_expirare(data) {
        this->greutate = greutate;
        this->pret = pret;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        codProdus++;
    }

    // Destructor pentru a elibera memorie
    ~aliment() {
        delete[] denumire;
    }

    static float pretMedie(aliment* produse, int nrProduse) {
        float suma = 0;
        for (int i = 0; i < nrProduse; i++) {
            suma += produse[i].pret;
        }
        return nrProduse > 0 ? suma / nrProduse : 0;
    }

    void afiseaza() {
        cout << "Aliment: " << denumire
            << ", Greutate: " << greutate
            << "g, Pret: " << pret
            << " lei, Data expirare: " << data_expirare << endl;
    }
};

// Initializarea atributului static
int aliment::codProdus = 0;

class magazinAlimentar {
public:
    int nrRaioane;
    int nrRafturi;
    int nrProduse;
    int nrClienti;
    char* numeMagazin;
    static int TVA;
    const int limitaLivrareGratuita;

    magazinAlimentar() : limitaLivrareGratuita(250) {
        this->nrRafturi = 100;
        this->nrRaioane = 10;
        this->nrProduse = 500;
        this->nrClienti = 1000;
        this->numeMagazin = new char[strlen("Lidl") + 1];
        strcpy_s(this->numeMagazin, strlen("Lidl") + 1, "Lidl");
    }

    magazinAlimentar(int nrRaioane, int nrRafturi, int limita)
        : limitaLivrareGratuita(limita) {
        this->nrRaioane = nrRaioane;
        this->nrRafturi = nrRafturi;
        this->nrProduse = nrProduse;
        this->nrClienti = nrClienti;
        this->numeMagazin = new char[strlen(numeMagazin) + 1];
        strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);
    }

    magazinAlimentar(int nrRaioane, int nrRafturi, int nrProduse, int nrClienti, int limita)
        : limitaLivrareGratuita(limita) {
        this->nrRaioane = nrRaioane;
        this->nrRafturi = nrRafturi;
        this->nrProduse = nrProduse;
        this->nrClienti = nrClienti;
        this->numeMagazin = new char[strlen(numeMagazin) + 1];
        strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);
    }

    ~magazinAlimentar() {
        delete[] numeMagazin;
    }

    static float calculeazaVenitTotal(float* preturi, int nrProduse) {
        float total = 0;
        for (int i = 0; i < nrProduse; i++) {
            total += preturi[i];
        }
        return total;
    }

    void afiseaza() {
        cout << "Magazinul " << numeMagazin << " are " << nrRaioane << " raioane, "
            << nrRafturi << " rafturi, "
            << nrProduse << " produse, "
            << nrClienti << " clienti, "
            << "Limita livrare gratuita: " << limitaLivrareGratuita << " lei" << endl;
    }
};

// Initializarea atributului static
int magazinAlimentar::TVA = 19;

class raion {
public:
    int lungimeRaion;
    float latimeRaion;
    bool locuriLibere;
    char* denumire;
    int nrProduseRaion;
    static int idRaion;
    const int greutateSustinuta;

    raion() : greutateSustinuta(1000) {
        this->denumire = new char[strlen("Lactate") + 1];
        strcpy_s(this->denumire, strlen("Lactate") + 1, "Lactate");
        this->latimeRaion = 25;
        this->lungimeRaion = 70;
        this->locuriLibere = false;
        this->nrProduseRaion = 30;
        idRaion++;
    }

    raion(const char* denumire, int lungimeRaion, int greutate) : greutateSustinuta(greutate) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->latimeRaion = latimeRaion;
        this->lungimeRaion = lungimeRaion;
        this->locuriLibere = locuriLibere;
        this->nrProduseRaion = nrProduseRaion;
        idRaion++;
    }

    raion(const char* denumire, int lungimeRaion, float latimeRaion, bool locuriLibere, int nrProduseRaion, int greutate)
        : greutateSustinuta(greutate) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
        this->latimeRaion = latimeRaion;
        this->lungimeRaion = lungimeRaion;
        this->locuriLibere = locuriLibere;
        this->nrProduseRaion = nrProduseRaion;
        idRaion++;
    }

    ~raion() {
        delete[] denumire;
    }

    static float calculeazaSuprafataRaion(int lungime, float latime) {
        return lungime * latime;
    }

    void afiseaza() {
        cout << "Raion: " << denumire
            << ", Lungime: " << lungimeRaion
            << "m, Latime: " << latimeRaion
            << "m, Locuri libere: " << (locuriLibere ? "da" : "nu")
            << ", Nr produse: " << nrProduseRaion
            << ", Greutate sustinuta: " << greutateSustinuta << "kg" << endl;
    }
};

// Initializarea atributului static
int raion::idRaion = 0;

int main() {
    // Creare obiecte din clasele definite
    aliment aliment1;
    aliment aliment2("lapte", 2024);
    aliment aliment3(500, "paine", 5.5, 2025);

    magazinAlimentar mg1;
    magazinAlimentar mg2(5, 50, 300);
    magazinAlimentar mg3(6, 70, 600, 1200, 300);

    raion raion1;
    raion raion2("bauturi", 80, 500);
    raion raion3("snack-uri", 60, 20.0, true, 100, 1500);

    // Afișare informații despre obiecte
    cout << "Informații despre alimente:\n";
    aliment1.afiseaza();
    aliment2.afiseaza();
    aliment3.afiseaza();

    cout << "\nInformații despre magazine:\n";
    mg1.afiseaza();
    mg2.afiseaza();
    mg3.afiseaza();

    cout << "\nInformații despre raioane:\n";
    raion1.afiseaza();
    raion2.afiseaza();
    raion3.afiseaza();

    // Exemplu de utilizare a funcțiilor statice complexe
    aliment produse[3] = { aliment1, aliment2, aliment3 };
    float preturi[3] = { aliment1.pret, aliment2.pret, aliment3.pret };

    cout << "\nPretul mediu al produselor: " << aliment::pretMedie(produse, 3) << endl;
    cout << "Venitul total din produse: " << magazinAlimentar::calculeazaVenitTotal(preturi, 3) << " lei" << endl;
    cout << "Suprafata raionului 2: " << raion::calculeazaSuprafataRaion(raion2.lungimeRaion, raion2.latimeRaion) << " mp" << endl;

    return 0;
}
