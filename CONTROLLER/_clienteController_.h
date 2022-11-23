#include<iostream>
#include<vector>
#include"..\MODELO\_cliente_.h"
#include<fstream>

using std::stoi;
using namespace std;  

class ClienteController
{
	private:
		vector<Cliente> vectorClienteA;
	public: 
		ClienteController()
		{
			cargarDatosDelArchivoAlVector();
			vector<Cliente> vectorClienteA; 
		}
		
		int getCorrelativo()
		{
			if(vectorClienteA.size()==0)
			{
				return 1;
			}
			else
			{
				return vectorClienteA[vectorClienteA.size()-1].getCodCliente()+1;
			}
		}
		
		void agregar(Cliente obj) /*agregar objetos al vector*/
		{
			vectorClienteA.push_back(obj);
		}
		Cliente extraer(int posi)
		{
			return vectorClienteA[posi]; 
		}
		int tam()
		{
			return vectorClienteA.size();
		}
		
		Cliente busquedaPorCod(int cod)
		{
			Cliente objError;
			objError.setNomCliente("Error");
			for(int i=0;i<tam();i++)
			{
				if(cod == extraer(i).getCodCliente())
				{
					return extraer(i);
				}
			}
			return objError;
		}
		
		Cliente busquedaPorNom(string nombre)
		{
			Cliente objError;
			objError.setNomCliente("Error");
			for(int i=0;i<tam();i++)
			{
				if(nombre == extraer(i).getNomCliente())
				{
					return extraer(i);
				}
			}
			return objError;
		}
		
		
		int getPostArray(Cliente obj)
		{
			for(int i=0;i<tam();i++)
			{
				if(obj.getCodCliente() == vectorClienteA[i].getCodCliente())
				{
					return i; 
				}
			}
		  return -1; 
		}
		
		void eliminar(Cliente obj)
		{
			vectorClienteA.erase(vectorClienteA.begin() + getPostArray(obj));
		}
		
		bool modificar(Cliente obj, string nom, string ape, string identi)
		{
			for(int i=0;i<tam();i++)
			{
				if(obj.getCodCliente() == extraer(i).getCodCliente())
				{
					vectorClienteA[i].setNomCliente(nom);
					vectorClienteA[i].setApeCliente(ape);
					vectorClienteA[i].setDniCliente(identi);
					return true; 
				}
			}
			return false; 
		}
		
		void grabarEnArchivo(Cliente ClienteA)
		{
			try
			{
				fstream archivoClienteA;
				archivoClienteA.open("Base_De_Datos_CLIENTES.cvs", ios::app);
				if(archivoClienteA.is_open())
				{
					archivoClienteA<<ClienteA.getCodCliente()<<";"<<ClienteA.getNomCliente()<<";"<<ClienteA.getApeCliente()<<";"<<ClienteA.getDniCliente()<<";"<<endl;
					archivoClienteA.close();
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
				fstream archivoClienteA;
				archivoClienteA.open("Base_De_Datos_CLIENTES.cvs", ios::out);
				if(archivoClienteA.is_open())
				{
					for(Cliente x:vectorClienteA)
					{
						archivoClienteA<<x.getCodCliente()<<";"<<x.getNomCliente()<<";"<<x.getApeCliente()<<";"<<x.getDniCliente()<<";"<<endl;
					}	
					archivoClienteA.close();
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
				string temporal[4];
				fstream archivoClienteA;
				archivoClienteA.open("Base_De_Datos_CLIENTES.cvs",ios::in);
				if(archivoClienteA.is_open())
				{
					while(!archivoClienteA.eof())
					{
						while(getline(archivoClienteA, linea))
							{
								i=0;
								while((posi = linea.find(";")) != string::npos)
								{
									temporal[i] = linea.substr(0,posi);
									linea.erase(0,posi+1);
									i++;
								}
					 			
					 			//Crear objeto cliente
					 			Cliente ClienteA;
					 			ClienteA.setCodCliente(std::stoi(temporal[0]));
					 			ClienteA.setNomCliente(temporal[1]);
					 			ClienteA.setApeCliente(temporal[2]);
					 			ClienteA.setDniCliente(temporal[3]);
					 			
					 			agregar(ClienteA);
							}
					}
				}
				archivoClienteA.close();
			}
			catch(exception e)
			{
				cout<<"OCURRIO UN ERROR AL LEER UN ARCHIVO1";
			}
			
		}
};



































