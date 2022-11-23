#include <iostream>
#include"..\MODELO\_DetalleVenta_.h"

using std::stoi;
using namespace std;

class DetalleVentaController 
	{
	private:
		vector<DetalleVenta> vectorDetVenta; 
	public: 
		DetalleVentaController()
		{
			cargarDatosDelArchivoAlVector();
			vector<DetalleVenta> vectorDetVenta; 
		}
		
		int getCorrelativo()
		{
			if(vectorDetVenta.size()==0)
			{
				return 1;
			}
			else
			{
				return vectorDetVenta[vectorDetVenta.size()-1].getCodProducto()+1;
			}
		}
		
		void agregar(DetalleVenta obj) /*agregar objetos al vector*/
		{
			vectorDetVenta.push_back(obj);
		}
		DetalleVenta extraer(int posi)
		{
			return vectorDetVenta[posi]; 
		}
		int tam()
		{
			return vectorDetVenta.size();
		}
		
		DetalleVenta busquedaPorCod(int cod)
		{
			DetalleVenta objError;
			objError.setNomCliente("Error");
			for(int i=0;i<tam();i++)
			{
				if(cod == extraer(i).getCodProducto())
				{
					return extraer(i);
				}
			}
			return objError;
		}
		
		int getPostArray(DetalleVenta obj)
		{
			for(int i=0;i<tam();i++)
			{
				if(obj.getCodProducto() == vectorDetVenta[i].getCodProducto())
				{
					return i; 
				}
			}
			return -1; 
		}
		
		void eliminar(DetalleVenta obj)
		{
			vectorDetVenta.erase(vectorDetVenta.begin() + getPostArray(obj));
		}
		
		bool modificar(DetalleVenta obj, int cantVenta, float precioVenta)
		{
			for(int i=0;i<tam();i++)
			{
				if(obj.getCodProducto() == extraer(i).getCodProducto())
				{
					vectorDetVenta[i].setCantVenta(cantVenta);
					vectorDetVenta[i].setPrecioVenta(precioVenta);
					return true; 
				}
			}
			return false; 
		}
		
		void grabarEnArchivo(DetalleVenta DetalleVent)
		{
			try
			{
				fstream archivoDetalleVent;
				archivoDetalleVent.open("Base_De_Datos_DETALLE_VENTA.cvs", ios::app);
				if(archivoDetalleVent.is_open())
				{
					archivoDetalleVent<<DetalleVent.getCodVenta()<<";"<<DetalleVent.getCodProducto()<<";"<<DetalleVent.getCantProducto()<<";"<<DetalleVent.getCostoProducto()<<";"<<DetalleVent.getPrecioVenta()<<endl;
					archivoDetalleVent.close();
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
				fstream archivoDetalleVent;
				archivoDetalleVent.open("Base_De_Datos_DETALLE_VENTA.cvs", ios::out);
				if(archivoDetalleVent.is_open())
				{
					for(DetalleVenta x:vectorDetVenta)
					{
						archivoDetalleVent<<x.getCodVenta()<<";"<<x.getCodProducto()<<";"<<x.getCantProducto()<<";"<<x.getCostoProducto()<<";"<<x.getPrecioVenta()<<";"<<x.getSubTotal()<<";"<<endl;
					}	
					archivoDetalleVent.close();
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
				fstream archivoDetalleVent;
				archivoDetalleVent.open("Base_De_Datos_DETALLE_VENTA.cvs",ios::in);
				if(archivoDetalleVent.is_open())
				{
					while(!archivoDetalleVent.eof())
					{
						while(getline(archivoDetalleVent, linea))
						{
							i=0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi+1);
								i++;
							}
							
							//Crear objeto cliente
							DetalleVenta DetalleVent;
							DetalleVent.setCodVenta(std::stoi(temporal[0]));
							DetalleVent.setCodProducto(std::stoi(temporal[1]));
							DetalleVent.setCantProducto(std::stoi(temporal[2]));
							DetalleVent.setCostoProducto(std::stoi(temporal[3]));
							DetalleVent.setPrecioVenta(std::stoi(temporal[4]));
							DetalleVent.getSubTotal();
							agregar(DetalleVent);
						}
					}
				}
				archivoDetalleVent.close();
			}
			catch(exception e)
			{
				cout<<"OCURRIO UN ERROR AL LEER UN ARCHIVO2";
			}
			
		}
};

