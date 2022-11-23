#include<iostream>
#pragma once

using namespace std; 

class Cliente 
{
	private:
		string nomC, apeC, dniC; 
		int codC;
	public:
		Cliente(string nomC, string apeC, string dniC, int codC)
		{
			this->nomC = nomC;
			this->apeC = apeC;
			this->dniC = dniC;
			this->codC = codC; 
		}
		Cliente()
		{
			
		}
	//set 
		void setNomCliente(string nomC)
		{
			this->nomC = nomC; 
		}
		void setApeCliente(string apeC)
		{
			this->apeC = apeC;
		}
		void setDniCliente(string dniC)
		{
			this->dniC = dniC;
		}
		void setCodCliente(int codC)
		{
			this->codC = codC; 
		}
	//get 
		string getNomCliente()
		{
			return nomC;
		}
		string getApeCliente()
		{
			return apeC;
		}
		string getDniCliente()
		{
			return dniC;
		}
		int getCodCliente()
		{
			return codC;
		}
		
};
