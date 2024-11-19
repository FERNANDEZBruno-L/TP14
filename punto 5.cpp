#include <iostream>
#include <string>
using namespace std;

class Calculadora {
public:
    // Método para sumar dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Sobrecarga para sumar dos números flotantes
    float sumar(float a, float b) {
        return a + b;
    }

    // Método para restar dos enteros
    int restar(int a, int b) {
        return a - b;
    }

    // Sobrecarga para restar dos números flotantes
    float restar(float a, float b) {
        return a - b;
    }

    // Método para multiplicar dos enteros
    int multiplicar(int a, int b) {
        return a * b;
    }

    // Sobrecarga para multiplicar dos números flotantes
    float multiplicar(float a, float b) {
        return a * b;
    }

    // Método para dividir dos enteros
    int dividir(int a, int b) {
        if (b != 0) return a / b;
        else {
            cout << "Error: División por cero!" << endl;
            return 0;
        }
    }

    // Sobrecarga para dividir dos números flotantes
    float dividir(float a, float b) {
        if (b != 0.0f) return a / b;
        else {
            cout << "Error: División por cero!" << endl;
            return 0.0f;
        }
    }
};

class Comparador {
public:
    // Método para comparar dos enteros
    bool comparar(int a, int b) {
        return a == b;
    }

    // Sobrecarga para comparar dos cadenas de texto
    bool comparar(const string& a, const string& b) {
        return a == b;
    }

    // Sobrecarga para comparar dos objetos de tipo personalizado (en este caso, se comparan los enteros de los objetos)
    bool comparar(const Comparador& a, const Comparador& b) {
        return a.valor == b.valor;
    }

    // Valor que podemos comparar
    int valor;

    Comparador(int v) : valor(v) {}
};

class Conversor {
public:
    // Método para convertir metros a centímetros
    float convertirMetrosACentimetros(float metros) {
        return metros * 100;
    }

    // Sobrecarga para convertir kilogramos a gramos
    float convertirKilogramosAGramos(float kilogramos) {
        return kilogramos * 1000;
    }

    // Sobrecarga para convertir Celsius a Fahrenheit
    float convertirCelsiusAFahrenheit(float celsius) {
        return (celsius * 9 / 5) + 32;
    }

    // Sobrecarga para convertir Fahrenheit a Celsius
    float convertirFahrenheitACelsius(float fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }
};

int main() {
    // Usando la calculadora
    Calculadora calc;
    cout << "Suma de 10 y 5: " << calc.sumar(10, 5) << endl;
    cout << "Suma de 10.5 y 5.3: " << calc.sumar(10.5f, 5.3f) << endl;

    cout << "Resta de 10 y 5: " << calc.restar(10, 5) << endl;
    cout << "Resta de 10.5 y 5.3: " << calc.restar(10.5f, 5.3f) << endl;

    cout << "Multiplicación de 10 y 5: " << calc.multiplicar(10, 5) << endl;
    cout << "Multiplicación de 10.5 y 5.3: " << calc.multiplicar(10.5f, 5.3f) << endl;

    cout << "División de 10 y 5: " << calc.dividir(10, 5) << endl;
    cout << "División de 10.5 y 2.5: " << calc.dividir(10.5f, 2.5f) << endl;

    // Usando Comparador
    Comparador comparador1(10);
    Comparador comparador2(10);
    Comparador comparador3(20);

    cout << "\nComparando 10 y 10: " << comparador1.comparar(10, 10) << endl;
    cout << "Comparando 'abc' y 'abc': " << comparador1.comparar("abc", "abc") << endl;
    cout << "Comparando objeto1 y objeto2 con valor 10: " << comparador1.comparar(comparador1, comparador2) << endl;
    cout << "Comparando objeto1 y objeto3 con valores 10 y 20: " << comparador1.comparar(comparador1, comparador3) << endl;

    // Usando Conversor
    Conversor conv;
    cout << "\n5 metros a centímetros: " << conv.convertirMetrosACentimetros(5) << " cm" << endl;
    cout << "5 kilogramos a gramos: " << conv.convertirKilogramosAGramos(5) << " g" << endl;
    cout << "25 grados Celsius a Fahrenheit: " << conv.convertirCelsiusAFahrenheit(25) << " °F" << endl;
    cout << "77 grados Fahrenheit a Celsius: " << conv.convertirFahrenheitACelsius(77) << " °C" << endl;

    return 0;
}

