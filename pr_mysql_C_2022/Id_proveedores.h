#pragma once
#include "mysql.h"
#include <iostream>
using namespace std;
class Id_proveedores{
	//atributos
protected: int id_proveedores;
		 //metodos
protected:
	Id_proveedores(){}

	Id_proveedores(int idprove) {
		id_proveedores = idprove;
	}
};

