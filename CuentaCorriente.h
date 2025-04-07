//
// Created by juand on 06/04/2025.
//

#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Cuentas.h"
#include <iostream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;


class CuentaCorriente : public Cuentas{

private:

    int limiteSobregiro;

public:

    CuentaCorriente (int n, int s, int id, int l);

    int getLimiteSobregiro();

    void mostrar() override;

    json toJson () override;

    string getTipo() const override;
};



#endif //CUENTACORRIENTE_H
