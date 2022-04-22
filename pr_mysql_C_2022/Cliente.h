#pragma once
#include <mysql.h>
#include "Persona.h"
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Proveedor.h"
#include "ConexionBD.h"
#include "Id_proveedores.h"
using namespace std;
class Cliente : Persona, Proveedor, Id_proveedores{
	//atributos
private: string nit;

	//constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel,string fn ,string n) : Persona(nom, ape, dir, tel,fn) {
		nit = n;
	}

	Cliente(string pro, string ni, string dire, string tele, int modi) : Proveedor(pro,ni,dire,tele, modi) {
	}
	Cliente(int idprove) : Id_proveedores(idprove) {

	}
	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setProveedor(string pro) { proveedor = pro; }
	void setNitt(string ni) { nitt = ni; }
	void setlugar(string dire) { lugar = dire; }
	void setTelefono(string tele) { celular = tele; }
	void setIdproveedores(int idprove) { id_proveedores = idprove; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombre() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getProveedor() { return proveedor; }
	string	getNitt() { return nitt; }
	string getlugar() { return lugar; }
	string getCelular() { return celular; }
	int getid_proveedores() { return id_proveedores; }

	//metodos
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('"+nit+"','"+nombres+"','"+apellidos+"','"+direccion+"','"+t+"','"+fecha_nacimiento+"');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else{
				cout << "----- Error al ingresar la informacion -----" << endl;
			}
		}
		else{
			cout << "----- Error en la Conexion -----" << endl;
		}
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()){
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "--------------- Clientes ---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "-" << fila[1] << "-" << fila[2] << "-" << fila[3] << "-" << fila[4] << "-" << fila[5] << "-" << fila[6] << endl;
				}
			}
		}
		else{
			cout << "----- Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}


	void leerproveedor() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Proveedores ----------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << endl;
				}
			}
			else {
				cout << "---- ERROR AL MOSTRAR A LOS PROVEEDORES INTENTA MAS TARDE" << endl;
			}
		}
		else {
			cout << "-----Error en la conexion-----" << endl;
		}
		cn.cerrar_conexion();
	}
	void crearproveedor() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "insert into proveedores(proveedor,nit,direccion,telefono)VALUES('" + proveedor + "','" + nitt + "','" + lugar + "','" + celular + "')";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso satisfactorio" << endl;
			}
			else {
				cout << "Error al ingresa los datos comprueba nueva mente" << endl;
			}
	
		}
		else {
			cout << "----- Error en la conexion -----" << endl;
		}
		cn.cerrar_conexion();
	}

	void Eliminarproveedor() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(id_proveedores);
			string consulta = "DELETE FROM proveedores WHERE id_proveedores='" + borrar + "'";
			const char* e = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "Eliminacion satisfactoria" << endl;
			}
			else {
				cout << " Error en la eliminacion comprueba tu conexion" << endl;
			}
		}
		else {
			cout << "----- Error en la conexion -----" << endl;
		}
		cn.cerrar_conexion();
	}

	void Modificarproveedores() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(modificar);
			string consulta = "UPDATE proveedores SET proveedor='" + proveedor + "', nit='" + nitt + "',direccion='" + lugar + "',telefono='" + celular + "' WHERE id_proveedores='" + borrar + "'";
			const char* m = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), m);
			if (!q_estado) {
				cout << "Modificacion exitosa" << endl;
			}
			else {
				cout << "Ocurrio un erro en la modificacion,verifica tu conexion" << endl;
			}
		}
		else {
			cout << "----- Error en la conexion -----" << endl;
		}
		cn.cerrar_conexion();

	}
};

