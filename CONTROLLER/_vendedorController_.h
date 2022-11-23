#include <iostream>
#include<vector>
#include<fstream>
#include"..\MODELO\_vendedor_.h"

using namespace std; 
using std::stoi;

class VendedorController
{
private:
	vector<Vendedor> vectorVendedorA;
public: 
	VendedorController()
	{
		cargarDatosDelArchivoAlVector();
		vector<Vendedor> vectorVendedorA; 
	}
	
	int getCorrelativo()
	{
		if(vectorVendedorA.size()==0)
		{
			return 1;
		}
		else
		{
			return vectorVendedorA[vectorVendedorA.size()-1].getCodVendedor()+1;
		}
	}
	
	void agregarVendedor(Vendedor obj)
	{
		vectorVendedorA.push_back(obj);
	}
	
	Vendedor extraer(int posi)
	{
		return vectorVendedorA[posi];
	}
	
	int tamVendedor()
	{
		return vectorVendedorA.size();
	}
	
	Vendedor busquedaPorCodVendedor(int cod)
	{
		Vendedor objError;
		objError.setNomVendedor("Error");
		for(int i=0;i<tamVendedor();i++)
		{
			if(cod == extraer(i).getCodVendedor())
			{
				return extraer(i);
			}
		}
		return objError;
	}
	
	int getPostArray(Vendedor obj)
	{
		for(int i=0;i<tamVendedor();i++)
		{
			if(obj.getCodVendedor() == vectorVendedorA[i].getCodVendedor())
			{
				return i; 
			}
		}
		return -1; 
	}
	
	void eliminar(Vendedor obj)
	{
		vectorVendedorA.erase(vectorVendedorA.begin() + getPostArray(obj));
	}
	
	bool modificar(Vendedor obj, string nomVendedor, string apeVendedor, string direVendedor, string dniVendedor)
	{
		for(int i=0;i<tamVendedor();i++)
		{
			if(obj.getCodVendedor() == extraer(i).getCodVendedor())
			{
				vectorVendedorA[i].setNomVendedor(nomVendedor);
				vectorVendedorA[i].setApeVendedor(apeVendedor);
				vectorVendedorA[i].setDireVendedor(direVendedor);
				vectorVendedorA[i].setDniVendedor(dniVendedor);
				return true; 
			}
		}
		return false; 
	}
	
	void grabarEnArchivo(Vendedor VendedorA)
	{
		try
		{
			fstream archivoVendedorA;
			archivoVendedorA.open("Base_De_Datos_VENDEDORES.cvs", ios::app);
			if(archivoVendedorA.is_open())
			{
				archivoVendedorA<<VendedorA.getCodVendedor()<<";"<<VendedorA.getNomVendedor()<<";"<<VendedorA.getApeVendedor()<<";"<<VendedorA.getDireVendedor()<<";"<<VendedorA.getDniVendedor()<<";"<<endl;
				archivoVendedorA.close();
			}
		}
		catch(exception e)
		{
			cout<<"OCURRIO UN ERROR AL GRABAR";
		}
	}
	
	void agregarRegistroModificado()
	{
		try
		{
			fstream archivoVendedorA;
			archivoVendedorA.open("Base_De_Datos_VENDEDORES.cvs", ios::out);
			if(archivoVendedorA.is_open())
			{
				for(Vendedor x:vectorVendedorA)
				{
					archivoVendedorA<<x.getCodVendedor()<<";"<<x.getNomVendedor()<<";"<<x.getApeVendedor()<<";"<<x.getDireVendedor()<<";"<<x.getDniVendedor()<<";"<<endl;
				}	
				archivoVendedorA.close();
			}	
		}
		catch(exception e)
		{
			cout<<"OCURRIO UN ERROR AL GRABAR";	
		}	
	}
	
	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i; 
			size_t posi; 
			string linea;
			string temporal[5];
			fstream archivoVendedorA;
			archivoVendedorA.open("Base_De_Datos_VENDEDORES.cvs",ios::in);
			if(archivoVendedorA.is_open())
			{
				while(!archivoVendedorA.eof())
				{
					while(getline(archivoVendedorA, linea))
					{
						i=0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							i++;
						}
						
						//Crear objeto cliente
						Vendedor VendedorA;
						VendedorA.setCodVendedor(std::stoi(temporal[0]));
						VendedorA.setNomVendedor(temporal[1]);
						VendedorA.setApeVendedor(temporal[2]);
						VendedorA.setDireVendedor(temporal[3]);
						VendedorA.setDniVendedor(temporal[4]);
						
						agregarVendedor(VendedorA);
					}
				}
			}
			archivoVendedorA.close();
		}
		catch(exception e)
		{
			cout<<"OCURRIO UN ERROR AL LEER UN ARCHIVO";
		}
		
	}
};


