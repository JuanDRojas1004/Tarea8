//
// Created by juand on 06/04/2025.
//

#ifndef BANCO_H
#define BANCO_H
#include <fstream>
#include <iostream>
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include "Clientes.h"
#include <vector>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;


class Banco {

private:

    string nombre;
    vector<Clientes> clientes;
    vector<CuentaAhorros*> cuentasAhorros;
    vector<CuentaCorriente*> cuentasCorritentes;
    vector<Cuentas*> cuentas;


public:

    Banco(string n);

    string getNombre();

    void addCliente (string n, string d);

    void addAhorro (int clienteId, int saldoInicial, int tasaInteres);

    void agregarCuentaCorriente(int clienteId, int saldoInicial, int limiteSobregiro);

    void agregarCuentaAhorros(int clienteId, int saldoInicial, int tasaInteres);

    void mostrarClientes();

    void mostrarCuentas ();

    int getTotalClientes() const;

    int getTotalCuentas() const;

    double getPromedioSaldos() const;

    int contarCuentasAhorro() const;

    int contarCuentasCorriente() const;

    json toJson ();

    void aplicarTasa(double tasa);

    void guardar(const string&  archivo = "BancoJaveriano.json");

    void consignar (int numero, int valor);

    void retirar (int numero, int valor);
};



#endif //BANCO_H
