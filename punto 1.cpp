#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int paginas;
    
public:
    Libro(string _titulo, string _autor, int _paginas) 
        : titulo(_titulo), autor(_autor), paginas(_paginas) {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getPaginas() const { return paginas; }
};

class Biblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
    }

    void eliminarLibro(const string& titulo) {
        for (auto it = libros.begin(); it != libros.end(); ++it) {
            if (it->getTitulo() == titulo) {
                libros.erase(it);
                break;
            }
        }
    }

    Libro* buscarLibro(const string& titulo) {
        for (auto& libro : libros) {
            if (libro.getTitulo() == titulo) {
                return &libro;
            }
        }
        return nullptr;
    }

    int totalPaginas() {
        int total = 0;
        for (auto& libro : libros) {
            total += libro.getPaginas();
        }
        return total;
    }

    void mostrarLibros() {
        for (auto& libro : libros) {
            cout << "Título: " << libro.getTitulo() << ", Autor: " << libro.getAutor() << ", Páginas: " << libro.getPaginas() << endl;
        }
    }
};

int main() {
    Biblioteca biblioteca;

    Libro libro1("El Quijote", "Cervantes", 500);
    Libro libro2("Cien Años de Soledad", "Gabriel García Márquez", 400);
    
    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);
    
    cout << "Libros en la biblioteca:" << endl;
    biblioteca.mostrarLibros();

    cout << "\nTotal de páginas: " << biblioteca.totalPaginas() << endl;
    
    Libro* encontrado = biblioteca.buscarLibro("El Quijote");
    if (encontrado) {
        cout << "\nLibro encontrado: " << encontrado->getTitulo() << endl;
    } else {
        cout << "\nLibro no encontrado." << endl;
    }

    biblioteca.eliminarLibro("Cien Años de Soledad");

    cout << "\nLibros en la biblioteca después de eliminar:" << endl;
    biblioteca.mostrarLibros();

    return 0;
}

