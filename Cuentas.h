//
// Created by juand on 06/04/2025.
//

#ifndef CUENTAS_H
#define CUENTAS_H
#include <iostream>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;


class Cuentas {

protected:

    int numero;
    int saldo;
    int id;


public:

    Cuentas(int n, int s, int i);

    int getNumero();

    int getSaldo();

    int getId();

    virtual void mostrar();

    virtual json toJson() {" ";};

    virtual string getTipo() const = 0;

    void consignar(int monto);

    virtual void retirar (int monto);
};



#endif //CUENTAS_H
