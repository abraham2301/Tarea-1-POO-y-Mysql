
#include <mysql.h>
#include <iostream>
#include <string>
#include "Puesto.h"
#include "Cliente.h"
using namespace std;

int main()
{
   // string puesto;
    //cout << "Ingrese Puesto:";
    //getline(cin, puesto);
    //Puesto p = Puesto(puesto);
    //p.crear();
    //p.leer();
  /*  int q_estado;
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empresa@123", "db_empresa", 3306, NULL, 0);
    if (conectar)
    {
        //cout << "Conexion exitosa..." << endl;
        cout << "Ingresa el puesto:";
        string puesto;
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso.." << endl;
        }
        else {
            cout << "Error al Insertar xxx" << endl;
        }
        //select * from puestos
        string consulta = "select * from puestos;";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila=mysql_fetch_row(resultado)) {
                cout << fila[0] << "," << fila[1] << endl;
            }
        }
        else {
            cout << "Error al Insertar xxx" << endl;
        }
    }
    else
    {
        cout << "Error en la conexion" << endl;
    } */

   /* string nit, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "Ingrese Nit:";
    getline(cin, nit);
    cout << "Ingrese Nombres:";
    getline(cin, nombres);
    cout << "Ingrese Apellidos:";
    getline(cin, apellidos);
    cout << "Ingrese Direccion:";
    getline(cin, direccion);
    cout << "Ingrese Telefono:";
    cin >> telefono;
    cin.ignore();
    cout << "Fecha Nacimiento:";
    cin >> fecha_nacimiento;

    Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

    c.crear();
    c.leer();*/

    string proveedor1, nit1, direccion1, telefono1;
    int idproducto1, eleccion,modificar1;
    cout << "Bienvenido que deseas realizar:" << endl;
    cout << " Agregar nuevo proveedor = 1 " << endl;
    cout << " Mostrar proveedores = 2 " << endl;
    cout << " Eliminar un proveedor = 3 " << endl;
    cout << " Modificar un proveedor = 4 " << endl;
    cout << "Respuesta = ";
    cin >> eleccion;
    if (eleccion == 1) {
        cin.ignore();
        cout << "Ingresa el Proveedor de la empresa: ";
        getline(cin, proveedor1);
        cin.ignore();
        cout << "Ingresa el nit del proveedor: ";
        getline(cin, nit1);
        cin.ignore();
        cout << "Ingresa la direccion del proveedor: ";
        getline(cin, direccion1);
        cin.ignore();
        cout << "Ingresa el numero telefonico del proveedor: ";
        getline(cin, telefono1);
        cout << "Ingresa cualquier numero para verificar que no seas robot: ";
        cin >> modificar1;
        Cliente c = Cliente(proveedor1, nit1, direccion1, telefono1,modificar1);
        c.crearproveedor();
    }
    else {
        if (eleccion == 2) {
            Cliente l = Cliente();
            l.leerproveedor();
        }
        else {
            if (eleccion == 3) {
                cout << "Ingresa el ID del proveedor a eliminar: ";
                cin >> idproducto1;
                Cliente e = Cliente(idproducto1);
                e.Eliminarproveedor();
            }
            else {
                if (eleccion == 4) {
                    cin.ignore();
                    cout << "Ingresa el nuevo nombre Proveedor de la empresa a modificar: ";
                    getline(cin, proveedor1);
                    cin.ignore();
                    cout << "Ingresa el nuevo nit del proveedor a modificar: ";
                    getline(cin, nit1);
                    cin.ignore();
                    cout << "Ingresa la  nueva direccion del proveedor a modificar: ";
                    getline(cin, direccion1);
                    cin.ignore();
                    cout << "Ingresa el nuevo numero telefonico del proveedor a modificar: ";
                    getline(cin, telefono1);
                    cout << "Ingresa el ID del proveedor al que quieras modificar: ";
                    cin >> modificar1;

                    Cliente m = Cliente(proveedor1, nit1, direccion1, telefono1, modificar1);
                    m.Modificarproveedores();
                }
                else {
                    cout << "Eleccion incorrecta vuelva a ingresar nuevamente" << endl;
                }
            }
        }
    }


   
    system("pause");
    return 0;
}
