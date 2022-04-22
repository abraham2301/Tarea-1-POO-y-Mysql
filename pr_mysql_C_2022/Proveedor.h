#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
using namespace std;

class Proveedor{
	//atributos
protected: string proveedor, nitt, lugar, celular;
		 int modificar;
	//metodos
protected:
	Proveedor() {

	}
	Proveedor(string pro, string ni, string dire, string tele, int modi) {
		proveedor = pro;
		nitt = ni;
		lugar = dire;
		celular = tele;
		modificar = modi;
	}
};

