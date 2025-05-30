//
// Created by juand on 06/04/2025.
//

#include "Banco.h"

Banco::Banco(string n): nombre(n) {cout << "El banco: " << nombre << " se ha creado con exito" << endl;}

string Banco::getNombre() {return nombre;}

void Banco::addCliente(string n, string d) {
    int nuevoId = clientes.empty() ? 1 : clientes.back().getId() + 1;
    clientes.emplace_back(n, d, nuevoId);
}

void Banco::addAhorro(int clienteId, int saldoInicial, int tasaInteres) {
    int nuevoNumero = cuentas.empty() ? 100 : cuentas.back()->getNumero() + 1;
    cuentas.push_back(new CuentaAhorros(nuevoNumero, saldoInicial, clienteId, tasaInteres));
}

void Banco::agregarCuentaCorriente(int clienteId, int saldoInicial, int limiteSobregiro) {
    int nuevoNumero = cuentas.empty() ? 100 : cuentas.back()->getNumero() + 1;
    cuentas.push_back(new CuentaCorriente(nuevoNumero, saldoInicial, clienteId, limiteSobregiro));
    cuentasCorritentes.push_back(new CuentaCorriente(nuevoNumero, saldoInicial, clienteId, limiteSobregiro));
}

void Banco::agregarCuentaAhorros(int clienteId, int saldoInicial, int tasaInteres) {
    int nuevoNumero = cuentas.empty() ? 100 : cuentas.back()->getNumero() + 1;
    cuentas.push_back(new CuentaAhorros(nuevoNumero, saldoInicial, clienteId, tasaInteres));
    cuentasAhorros.push_back(new CuentaAhorros(nuevoNumero, saldoInicial, clienteId, tasaInteres));
}

void Banco::mostrarClientes() {
    for (auto& cli : clientes) {
        cout << "Cliente: " << cli.getNombre() << "Con Id: " << cli.getId() << "y direccion: " << cli.getDireccion() << endl;
    }
}

void Banco::mostrarCuentas() {
    for (auto& cu : cuentas) {
        cu -> mostrar();
    }
}

int Banco::getTotalClientes() const {
    return clientes.size();
}

int Banco::getTotalCuentas() const {
    return cuentasCorritentes.size() + cuentasAhorros.size();
}

double Banco::getPromedioSaldos() const {
    if (cuentas.empty()) return 0.0;

    double total = 0.0;
    for (const auto& cuenta : cuentas) {
        total += cuenta->getSaldo();
    }
    return total / cuentas.size();
}

int Banco::contarCuentasAhorro() const {
    return cuentasAhorros.size();
}

int Banco::contarCuentasCorriente() const {
    return cuentasCorritentes.size();
}

json Banco::toJson() {
    json j;
    j["Nombre"] = nombre;

    json clientesJson;
    for (auto& c : clientes) {
        clientesJson.push_back(c.toJson());
    }

    j["Clientes"] = clientesJson;

    json cuentasJson;
    for (auto& c : cuentas) {
        cuentasJson.push_back(c->toJson());
    }

    j["Cuentas"] = cuentasJson;

    return j;

}

void Banco::aplicarTasa(double tasa) {
    for (CuentaAhorros* cuenta : cuentasAhorros) {
        cuenta->setInteres(tasa);
    }
}

void Banco::guardar(const string &archivo) {

    ofstream file(archivo);
    file << toJson ().dump(4);
    cout << "Datos guardados con exito en:" << archivo << endl;


}

void Banco::consignar(int numero, int valor) {

    for (Cuentas* cuenta : cuentas) {
        if (cuenta->getNumero() == numero) {
            cuenta->consignar(valor);
            cout << "Consigacion exitosa" << endl;
        }
    }

}

void Banco::retirar(int numero, int valor) {

    for (Cuentas* cuenta : cuentas) {
        if (cuenta->getNumero() == numero) {
            cuenta->retirar(valor);
        }
    }

}

void Banco::cargar(const string &archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cout << "No se pudo cargar el archivo..." << endl;
        return;
    }
    json datos;
    file >> datos;

    nombre = datos["Nombre"];

    clientes.clear();
    for (auto& clienteJson : datos["Clientes"]) {
        clientes.emplace_back(
            clienteJson["nombre"],
            clienteJson["direccion"],
            clienteJson["id"]
        );
    }
    for (auto& cuenta : cuentas) {
        delete cuenta;
    }
    cuentas.clear();

    for (auto& cuentaJson : datos["Cuentas"]) {
        string tipo = cuentaJson["tipo"];
        int numero = cuentaJson["numero"];
        double saldo = cuentaJson["saldo"];
        int idCliente = cuentaJson["idCliente"];

        if (tipo == "ahorros") {
            double tasa = cuentaJson["tasaInteres"];
            cuentas.push_back(new CuentaAhorros(numero, saldo, idCliente, tasa));
        } else if (tipo == "corriente") {
            double limite = cuentaJson["limiteSobregiro"];
            cuentas.push_back(new CuentaCorriente(numero, saldo, idCliente, limite));
        }
    }
    cout << "Datos cargados correctamente desde " << archivo << endl;



}


