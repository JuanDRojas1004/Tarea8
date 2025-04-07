//
// Created by juand on 06/04/2025.
//

#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include <iostream>
#include "Cuentas.h"
#include "json.hpp"
using namespace std;
using json = nlohmann::json;


class CuentaAhorros : public Cuentas {

private:

    int tasaInteres;

public:

    CuentaAhorros ( int n, int s, int id, int t);

    int getTasaInteres ();

    void mostrar() override;

    json toJson () override;

    string getTipo() const override;

    void setInteres (double valor);
};



#endif //CUENTAAHORROS_H
