#include <iostream>
#include<vector>
#include<fstream>
#include"..\MODELO\_venta_.h"

using std::stoi; 
using std::stof; 
using namespace std;

class VentaController 
	{
	private:
		vector<Venta> vectorVenta; 
	public:
		VentaController()
		{
			cargarDatosDelArchivoAlVector(); 
		}
		void addVenta(Venta obj) 
		{
			vectorVenta.push_back(obj);
		}
		Venta get(int posi)
		{
			return vectorVenta[posi];
		}
		int rows()
		{
			return vectorVenta.size(); 
		}
		
		int getPostArray(Venta obj)
		{
			for(int i=0; i<rows(); i++)
			{
				if(obj.getCodVenta() == get(i).getCodVenta())
				{
					return i; 
				}
			}
			return -1;
		}
		
		int getCorrelativo()
		{
			if(vectorVenta.size() == 0)
			{
				return 0;
			}
			else
			{
				return vectorVenta[vectorVenta.size()-1].getCodVenta()+1;
			}
		}
		
		void eliminarVenta(Venta obj)
		{
			vectorVenta.erase(vectorVenta.begin() + getPostArray(obj));
		}
		
		bool modificarVenta(Venta a, int codVenta, string fechaVenta, int numVenta , int totalVenta, string estVenta)
		{
			for(int i=0; i<rows();i++)
			{
				if(a.getCodVenta()==get(i).getCodVenta())
				{
					vectorVenta[i].setCodVenta(codVenta);
					vectorVenta[i].setFechaVenta(fechaVenta);
					vectorVenta[i].setNumVenta(numVenta);
					vectorVenta[i].setTotVenta(totalVenta);
					vectorVenta[i].setEstVenta(estVenta);
					return true; 
				}
			}
			return false; 
		}
		
		void grabarVentaEnArchivo(Venta venta)
		{
			try
			{
				fstream archivoVenta;
				archivoVenta.open("Base_de_Datos_venta.cvs", ios::app);
				if(archivoVenta.is_open())
				{
					archivoVenta<<venta.getNomCliente()<<";"<<venta.getApeCliente()<<";"<<venta.getCodVenta()<<";"<<venta.getFechaVenta()<<";"<<venta.getNumVenta()<<";"<<venta.getTotVenta()<<";"<<venta.getEstVenta()<<";"<<endl;
					archivoVenta.close();
				}
				
			}
			catch(exception e)
			{
				cout<<"ERROR AL GRABAR EL REGISTRO"<<endl; 
			}
		}
		
		void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int 	i;
				size_t 	posi;
				string 	linea;
				string 	temporal[9];
				fstream	archivoVenta;
				archivoVenta.open("venta.cvs",ios::in);
				if(archivoVenta.is_open())
				{
					while(!archivoVenta.eof() && getline(archivoVenta,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						Venta objVenta(temporal[0], temporal[1], temporal[2], std::stoi(temporal[3]), std::stoi(temporal[4]), temporal[5], std::stoi(temporal[6]), std::stoi(temporal[7]), temporal[8]);
						
						addVenta(objVenta);
					}
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
};

