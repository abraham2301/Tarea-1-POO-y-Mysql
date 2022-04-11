#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
#include "ConexionBD.h"
class Puesto
{
	//atributos
	private:string puesto;
		   //constructor
	public:
		Puesto(){}
		Puesto(string p) {
			puesto = p;
		}
		void setPuesto(string p) {	puesto = p;	}
		string getPuesto() { return puesto; }
		void crear() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string insertar = "insert into puestos(puesto) value('"+ puesto +"')";
				const char* i = insertar.c_str();
				//executar el query
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "Ingreso exitoso..." << endl;
				}
				else {
					cout << "XXX Error al ingresar" << endl;
				}
			}
			else {
				cout << "xxx Error en la Conexion xxx" << endl;
			}
			cn.cerrar_conexion();
		}
		void leer() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				cout << "---------- Datos de los Puestos ----------" << endl;
				string consulta = "select * from puestos";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << "," << fila[1] << endl;
					}
				}

			}
			else {
				cout << "Error al conectar" << endl;
			}
			cn.cerrar_conexion();
		}
};
