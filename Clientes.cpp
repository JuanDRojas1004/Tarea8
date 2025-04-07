//
// Created by juand on 06/04/2025.
//

#include "Clientes.h"

Clientes::Clientes(string n, string d, int id): nombre(n), direccion(d), id(id) {cout << "El cliente ha sido creado con exito" << endl;}

string Clientes::getNombre() {return nombre;}

string Clientes::getDireccion() {return direccion;}

int Clientes::getId() {return id;}

json Clientes::toJson() {return json{{"Nombre", nombre}, {"Direccion", direccion}, {"ID", id}};}
