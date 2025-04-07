//
// Created by juand on 06/04/2025.
//

#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(int n, int s, int id, int t): Cuentas (n, s, id), tasaInteres(t) {cout << " Cuenta de ahorro creada con exito" << endl;}

int CuentaAhorros::getTasaInteres() {return tasaInteres;}

void CuentaAhorros::mostrar() {
    cout << "Cuenta: " << numero << "con saldo: " << saldo << " asociado al id:  " << id << " con tasa de interes de: "<< tasaInteres <<  endl;
}

json CuentaAhorros::toJson () {
    return json {{"Numero", numero}, {"Saldo", saldo}, {"ID", id}, {"Tasa Interes", tasaInteres}};
}

string CuentaAhorros::getTipo() const { return "ahorros"; }

void CuentaAhorros::setInteres(double valor) {

    tasaInteres = valor;

}

