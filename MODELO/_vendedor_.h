#include <iostream>
#pragma once 

using namespace std; 

class Vendedor 
{
private:
	string nomVendedor, apeVendedor, direVendedor, dniVendedor; 
	int codVendedor; 
public:
	//set
	void setCodVendedor(int codVendedor)
	{
		this->codVendedor = codVendedor;
	}
	void setNomVendedor(string nomVendedor)
	{
		this->nomVendedor = nomVendedor;
	}
	void setApeVendedor(string apeVendedor)
	{
		this->apeVendedor = apeVendedor;
	}
	void setDireVendedor(string direVendedor)
	{
		this->direVendedor = direVendedor;
	}
	void setDniVendedor(string dniVendedor)
	{
		this->dniVendedor = dniVendedor;
	}
	//get
	int getCodVendedor()
	{
		return codVendedor;
	}
	string getNomVendedor()
	{
		return nomVendedor;
	}
	string getApeVendedor()
	{
		return apeVendedor;
	}
	string getDireVendedor()
	{
		return direVendedor;
	}
	string getDniVendedor()
	{
		return dniVendedor;
	}
};
