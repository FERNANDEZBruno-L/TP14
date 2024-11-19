#include <iostream>
#include <cmath>  

class Figura {
protected:
    std::string color; 
    float x, y;         

public:
    Figura(std::string c, float px, float py) : color(c), x(px), y(py) {}

    std::string obtenerColor() const {
        return color;
    }

    virtual float calcularArea() const = 0;
    virtual float calcularPerimetro() const = 0;
    
    void mostrarPosicion() const {
        std::cout << "Posición: (" << x << ", " << y << ")\n";
    }
    
    virtual void mostrarInfo() const {
        std::cout << "Figura de color: " << color << "\n";
        mostrarPosicion();
    }
};

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(std::string c, float px, float py, float r) 
        : Figura(c, px, py), radio(r) {}

    float calcularArea() const override {
        return M_PI * radio * radio;
    }

    float calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }

    void mostrarInfo() const override {
        Figura::mostrarInfo();
        std::cout << "Tipo: Círculo\n";
        std::cout << "Radio: " << radio << "\n";
        std::cout << "Área: " << calcularArea() << "\n";
        std::cout << "Perímetro: " << calcularPerimetro() << "\n";
    }
};

class Rectangulo : public Figura {
private:
    float ancho, alto; 

public:
    Rectangulo(std::string c, float px, float py, float a, float l)
        : Figura(c, px, py), ancho(a), alto(l) {}

    float calcularArea() const override {
        return ancho * alto;
    }

    float calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }

    void mostrarInfo() const override {
        Figura::mostrarInfo();
        std::cout << "Tipo: Rectángulo\n";
        std::cout << "Ancho: " << ancho << ", Alto: " << alto << "\n";
        std::cout << "Área: " << calcularArea() << "\n";
        std::cout << "Perímetro: " << calcularPerimetro() << "\n";
    }
};

class Triangulo : public Figura {
private:
    float base, altura, lado1, lado2, lado3; 

public:
    Triangulo(std::string c, float px, float py, float b, float h, float l1, float l2, float l3)
        : Figura(c, px, py), base(b), altura(h), lado1(l1), lado2(l2), lado3(l3) {}

    float calcularArea() const override {
        return 0.5f * base * altura;
    }

    float calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }

    void mostrarInfo() const override {
        Figura::mostrarInfo();
        std::cout << "Tipo: Triángulo\n";
        std::cout << "Base: " << base << ", Altura: " << altura << "\n";
        std::cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << "\n";
        std::cout << "Área: " << calcularArea() << "\n";
        std::cout << "Perímetro: " << calcularPerimetro() << "\n";
    }
};

int main() {
    Circulo c("Rojo", 0, 0, 5);
    Rectangulo r("Azul", 1, 1, 4, 6);
    Triangulo t("Verde", 2, 2, 3, 4, 3, 4, 5);

    c.mostrarInfo();
    std::cout << "--------------------------\n";
    r.mostrarInfo();
    std::cout << "--------------------------\n";
    t.mostrarInfo();

    return 0;
}

