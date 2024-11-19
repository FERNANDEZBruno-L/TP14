#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mesa {
private:
    int numComensales;
    bool ocupada;

public:
    Mesa(int _numComensales) : numComensales(_numComensales), ocupada(false) {}

    bool estaOcupada() const { return ocupada; }
    int getNumComensales() const { return numComensales; }

    void reservar() { ocupada = true; }
    void liberar() { ocupada = false; }
};

class Restaurante {
private:
    vector<Mesa> mesas;

public:
    Restaurante(int numMesas) {
        for (int i = 0; i < numMesas; ++i) {
            mesas.push_back(Mesa(4)); 
        }
    }

    void reservarMesa(int indice) {
        if (indice >= 0 && indice < mesas.size() && !mesas[indice].estaOcupada()) {
            mesas[indice].reservar();
            cout << "Mesa " << indice + 1 << " reservada." << endl;
        } else {
            cout << "La mesa ya está ocupada o el índice es inválido." << endl;
        }
    }

    void liberarMesa(int indice) {
        if (indice >= 0 && indice < mesas.size() && mesas[indice].estaOcupada()) {
            mesas[indice].liberar();
            cout << "Mesa " << indice + 1 << " liberada." << endl;
        } else {
            cout << "La mesa no está ocupada o el índice es inválido." << endl;
        }
    }

    int mesasLibres() {
        int libres = 0;
        for (auto& mesa : mesas) {
            if (!mesa.estaOcupada()) {
                libres++;
            }
        }
        return libres;
    }
};

int main() {
    Restaurante restaurante(5);

    restaurante.reservarMesa(0);
    restaurante.reservarMesa(1);

    restaurante.liberarMesa(1);

    cout << "\nMesas libres: " << restaurante.mesasLibres() << endl;

    return 0;
}

