//
// Created by juand on 06/04/2025.
//

#include "Cuentas.h"

Cuentas::Cuentas(int n, int s, int i): numero(n), saldo(s), id (i) {}

int Cuentas::getNumero() {return numero;}

int Cuentas::getSaldo() {return saldo;}

int Cuentas::getId() {return id;}

void Cuentas::mostrar() {
    cout << "Cuenta: " << numero << "con saldo: " << saldo << " asociado al id:  " << id << endl;
}

void Cuentas::consignar(int monto) {
    if (monto > 0) {
        saldo += monto;
    }
}

