#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Empleado {
private:
    string nombre;
    float salario;
    string departamento;

public:
    Empleado(string _nombre, float _salario, string _departamento)
        : nombre(_nombre), salario(_salario), departamento(_departamento) {}

    string getNombre() const { return nombre; }
    float getSalario() const { return salario; }
    string getDepartamento() const { return departamento; }
};

class Empresa {
private:
    vector<Empleado> empleados;

public:
    void agregarEmpleado(const Empleado& empleado) {
        empleados.push_back(empleado);
    }

    float calcularNominaTotal() {
        float total = 0;
        for (auto& empleado : empleados) {
            total += empleado.getSalario();
        }
        return total;
    }

    Empleado* empleadoConMayorSalario() {
        Empleado* maxSalario = nullptr;
        for (auto& empleado : empleados) {
            if (maxSalario == nullptr || empleado.getSalario() > maxSalario->getSalario()) {
                maxSalario = &empleado;
            }
        }
        return maxSalario;
    }

    void listarEmpleadosDeDepartamento(const string& departamento) {
        cout << "Empleados del departamento " << departamento << ":" << endl;
        for (auto& empleado : empleados) {
            if (empleado.getDepartamento() == departamento) {
                cout << "Nombre: " << empleado.getNombre() << ", Salario: " << empleado.getSalario() << endl;
            }
        }
    }
};

int main() {
    Empresa empresa;

    empresa.agregarEmpleado(Empleado("Juan", 2500, "Ventas"));
    empresa.agregarEmpleado(Empleado("Maria", 3000, "Marketing"));
    empresa.agregarEmpleado(Empleado("Carlos", 3500, "Ventas"));

    cout << "Nómina total: " << empresa.calcularNominaTotal() << endl;

    Empleado* mayorSalario = empresa.empleadoConMayorSalario();
    cout << "Empleado con mayor salario: " << mayorSalario->getNombre() << ", Salario: " << mayorSalario->getSalario() << endl;

    empresa.listarEmpleadosDeDepartamento("Ventas");

    return 0;
}

