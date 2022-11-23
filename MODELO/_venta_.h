#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#pragma once
#include"..\MODELO\_cliente_.h"


using namespace std;

class Venta:public Cliente
{
private:
	int codVenta;
	string fechaVenta;
	int numVenta;
	int totVenta;
	string estVenta;
	
	
	
public:
	
	Venta(string nomC, string apeC, string dniC, int codC, int codVenta, string fechaVenta,int numVenta,int totVenta,string estVenta):Cliente(nomC, apeC, dniC, codC)
	{
		this->codVenta=codVenta;
		this->fechaVenta=fechaVenta;
		this->numVenta=numVenta;
		this->totVenta=totVenta;
		this->estVenta=estVenta;
		
		
	}
	Venta()
	{
		
	}
	//set
	void setCodVenta(int codVenta)
	{
		this->codVenta=codVenta;
	}
	void setFechaVenta(string fechaVenta)
	{
		this->fechaVenta=fechaVenta;
	}
	void setNumVenta(int numVenta)
	{
		this->numVenta=numVenta;
	}
	void setTotVenta(int totVenta)
	{
		this->totVenta=totVenta;
	}
	void setEstVenta(string estVenta)
	{
		this->estVenta=estVenta;
	}
	
	//get
	int getCodVenta()
	{
		return this->codVenta;
	}
	string getFechaVenta()
	{
	stringstream stream;
	string fechaVenta;
	time_t t;
	t = time(NULL);
	struct tm* fecha;
	fecha = localtime(&t);
	stream << fecha->tm_mday << "-" << (fecha->tm_mon + 1) << "-" << (fecha->tm_year + 1900);
	
	fechaVenta = stream.str();
	
	return fechaVenta;
	} 
	
	int getNumVenta()
	{
		return this->numVenta;
	}
	int getTotVenta()
	{
		return this->totVenta;
	}
	string getEstVenta()
	{
		return this->estVenta;
	}
	
	
};
