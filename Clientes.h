//
// Created by juand on 06/04/2025.
//

#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;





class Clientes {
private:

    string nombre;
    string direccion;
    int id;


public:

    Clientes(string n, string d, int id);

    string getNombre();

    string getDireccion();

    int getId();

    json toJson();
};



#endif //CLIENTES_H
