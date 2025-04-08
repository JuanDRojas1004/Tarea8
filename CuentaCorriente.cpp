//
// Created by juand on 06/04/2025.
//

#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(int n, int s, int id, int l): Cuentas(n, s, id), limiteSobregiro(l) {cout << " Cuenta de corriente creada con exito" << endl;}

int CuentaCorriente::getLimiteSobregiro() {return limiteSobregiro;}

void CuentaCorriente::mostrar() {cout << "Cuenta: " << numero << "con saldo: " << saldo << " asociado al id:  " << id << " con limite de sobregiro: "<< limiteSobregiro <<  endl;}

json CuentaCorriente::toJson() {
    return json {{"Numero", numero}, {"Saldo", saldo}, {"ID", id}, {"Limite Sobregiro", limiteSobregiro}};
}

string CuentaCorriente::getTipo() const { return "corriente"; }

void CuentaCorriente::retirar(int monto) {
    if (saldo - monto >= -limiteSobregiro) {
        saldo -= monto;
    } else {
        cout << "Has superado el limite" << endl;
    }
}

