#include <iostream>
#include<vector>
#include"..\modelo\_usuario_.h"
#include<fstream>
using namespace std;

class UsuarioController
{
private:
	
	vector<Usuario> vectorUsuario; //creando el vector objeto
	
public:
	
	UsuarioController()
	{
		cargarDatosDelArchivoAlVector();
	}
	
	//Agregar objetos al arreglo 
	void agregar(Usuario obj)
	{
		vectorUsuario.push_back(obj);
	}
	
	
	void grabarEnArchivo(Usuario obj)
	{
		try 
		{
			fstream archivoUsuario;
			archivoUsuario.open("usuarios.bin",ios::app|ios::binary);
			if(archivoUsuario.is_open())
			{
				archivoUsuario<<obj.getUsuario()<<";"<<obj.getContra()<<";"<<endl; 
				archivoUsuario.close();
			}
		}
		
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar ";
		}
		
	}
	
	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[2];
			fstream	archivoUsuario;
			archivoUsuario.open("usuarios.bin",ios::in|ios::binary);
			if(archivoUsuario.is_open())
			{
				while(!archivoUsuario.eof() && getline(archivoUsuario,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						++i;
					}
					
					Usuario objUsuario(temporal[0],temporal[1]);
					
					agregar(objUsuario);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
	
	Usuario get(int pos)
	{
		return vectorUsuario[pos];
	}
	int rows()
	{		
		return vectorUsuario.size();
	}
	
};

