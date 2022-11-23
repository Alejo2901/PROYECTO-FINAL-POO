#include <iostream>
#pragma once
#include "..\MODELO\_categoria_.h"
using namespace std; 

class Producto:public Categoria
{
private:
	int codProducto;
	string nomProducto;
	string desProducto;
	float costoProducto;
	int cantProducto; 
	
public:
	
	Producto(int codCategoria, string nomCat, int codProducto, string nomProducto, string desProducto, float costoProducto, int cantProducto):Categoria(codCategoria, nomCat)
	{
		this->codProducto = codProducto;
		this->nomProducto = nomProducto;
		this->desProducto = desProducto;
		this->costoProducto = costoProducto;
		this->cantProducto = cantProducto;
	}
	Producto()
	{
		
	}
	//set
	void setCodProducto(int codProducto)
	{
		this->codProducto = codProducto;
	}
	void setNomProducto(string nomProducto)
	{
		this->nomProducto = nomProducto;
	}
	void setDesProducto(string desProducto)
	{
		this->desProducto = desProducto;
	}
	void setCostoProducto(float costoProducto)
	{
		this->costoProducto = costoProducto;
	}
	void setCantProducto(int cantProducto)
	{
		this->cantProducto = cantProducto;
	}
	//get
	int getCodProducto()
	{
		return this->codProducto;
	}
	string getNomProducto()
	{
		return nomProducto; 
	}
	string getDesProducto()
	{
		return desProducto; 
	}
	float getCostoProducto()
	{
		return costoProducto;
	}
	int getCantProducto()
	{
		return cantProducto;
	}
};

