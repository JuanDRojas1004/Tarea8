#include <iostream>
#include "Banco.h"

using namespace std;


int main() {

    Banco banco("Banco Javeriano");
    banco.cargar("BancoJaveriano.json");


    int limiteSobregiro, saldo, opcionP, opcionSub, tipoCuenta, id, parametro, numero, valor;
    string nombre, direccion;

    while (true) {
        cout << "\n\n** MENU BANCO JAVERIANO **\n";
        cout << "1) MANTENIMIENTO DE CLIENTES\n";
        cout << "2) MANTENIMIENTO DE CUENTAS\n";
        cout << "3) ESTADISTICAS\n";
        cout << "4) OPERACIONES FINANCIERAS\n";
        cout << "5) SALIR\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionP;

        switch (opcionP) {
            case 1:
                do {

                    cout << "1.1) Agregar Clientes\n";
                    cout << "1.2) Listar Clientes\n";
                    cin >> opcionSub;

                    switch (opcionSub) {

                        case 1: {
                            cout << "Agregar Clientes" << endl;
                            cout << "Ingrese nombre:" << endl;
                            cin >> nombre;
                            cin.ignore();
                            cout << "Ingrese direccion:" << endl;
                            getline(cin, direccion);

                            banco.addCliente(nombre, direccion);
                            cout << "Cliente guardado con exito" << endl;
                            break;

                        }

                        case 2: {

                            cout << "Listar clientes" << endl;
                            banco.mostrarClientes();
                            break;


                        }

                        default:
                            cout << "Opcion no valida!\n";
                    }

                } while (opcionSub !=2);
            break;

            case 2 : {
                do {
                    cout << "2.1) Agregar Cuenta\n";
                    cout << "2.2) Listar Cuentas\n";
                    cin >> opcionSub;
                    switch (opcionSub) {
                        case 1: {
                            cout << "Agregar Cuenta" << endl;
                            cout << "ID del cliente: ";
                            cin >> id;
                            cout << "Saldo inicial: ";
                            cin >> saldo;
                            cout << "Tipo de cuenta (1=Ahorros, 2=Corriente): ";
                            cin >> tipoCuenta;
                            if(tipoCuenta == 1) {
                                cout << "Tasa de interes (%): ";
                                cin >> parametro;
                                banco.agregarCuentaAhorros(id, saldo, parametro);
                            }
                            else {
                                cout << "Limite de sobregiro: ";
                                cin >> parametro;
                                banco.agregarCuentaCorriente(id,saldo,parametro);


                            }
                            cout << "Cuenta agregada con exito!\n";
                            break;
                        }
                        case 2: {
                            cout << "\nLISTADO DE CUENTAS\n";
                            banco.mostrarCuentas();
                            break;

                        }

                        default:
                            cout << "Opcion no valida!\n";
                    }

                }
                while (opcionSub != 2);
                break;



            }


            case 3 : {
                do {
                    cout << "3.1) Total de Clientes\n";
                    cout << "3.2) Total de Cuentas\n";
                    cout << "3.3) Promedio del Saldo de las Cuentas\n";
                    cout << "3.4) Numero de Cuentas de Ahorro\n";
                    cout << "3.5) Numero de Cuentas Corrientes\n";

                    cin >> opcionSub;

                    switch (opcionSub) {

                        case 1: {
                            cout << "Total de Clientes: " << banco.getTotalClientes() << endl;
                            break;
                        }

                        case 2: {
                            cout << "Total de Cuentas: " << banco.getTotalCuentas() << endl;
                            break;
                        }

                        case 3: {
                            cout << "Promedio del Saldo: $" << banco.getPromedioSaldos() << endl;
                            break;
                        }

                        case 4: {
                            cout << "Cuentas de Ahorro: " << banco.contarCuentasAhorro() << endl;
                            break;
                        }
                        case 5: {
                            cout << "Cuentas Corrientes: " << banco.contarCuentasCorriente() << endl;
                            break;
                        }


                    }

                }while (opcionSub != 5);

            }
            break;



            case 4 : {
                do{

                    cout << "4.1) Aplicar Tasa de Interes a Cuentas de Ahorro\n";
                    cout << "4.2) Consignar Dinero en una Cuenta\n";
                    cout << "4.3) Retirar Dinero de una Cuenta\n";
                    cout << "4.4) Salir\n";
                    cin >> opcionSub;

                    switch (opcionSub) {

                        case 1: {

                            cout << "Ingrese una tasa de interes: " << endl;
                            double tasa;
                            cin >> tasa;

                            banco.aplicarTasa(tasa);

                            break;

                        }

                        case 2: {

                            cout << "ingrese el numero de cuenta:" << endl;
                            cin >> numero;
                            cout << "Ingrese el monto a consignar:" << endl;
                            cin >> valor;

                            banco.consignar(numero, valor);

                            break;




                        }

                        case 3: {
                            cout << "ingrese el numero de cuenta:" << endl;
                            cin >> numero;
                            cout << "Ingrese el monto a retirar:" << endl;
                            cin >> valor;

                            banco.retirar(numero, valor);

                            break;

                        }
                    }



                } while (opcionSub != 4);
                break;

            }


            case 5 : {

                do{

                    cout << "5.1) Guardar y salir\n";
                    cin >> opcionSub;
                    switch (opcionSub)

                        case 1 : {


                        banco.guardar("BancoJaveriano.json");
                        cout << "Datos guardados. Saliendo del programa...\n";
                        break;
                        }


                }while (opcionSub != 1);
                return 0;



            }
        }
    }



}




