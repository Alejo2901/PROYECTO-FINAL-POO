#include <iostream>
using namespace std;

class Usuario
{
private:
	string usuario;
	string contra;
	
public:
	
	Usuario()
	{
		
	}
	Usuario(string usuario,string contra)
	{
		this->usuario=usuario;
		this->contra=contra;
	}
	
	//set
	void setUsuario(string usuario)
	{
		this->usuario=usuario;
	}
	void setContra(string contra)
	{
		this->contra=contra;
	}
	//get
	string getUsuario()
	{
		return this->usuario;
	}
	
	string getContra()
	{
		return this->contra;
	}
	
	
};


