#include<iostream>
#include<vector>
#include<fstream>
#include"..\MODELO\_producto_.h"

using namespace std; 
using std::stoi;
using std::stof;

class ProductoController
	{
	private:
		vector<Producto> vectorProductoA; 
	public:
		ProductoController()
		{
			cargarDatosDelArchivoAlVector(); 
		}
		void addProducto(Producto obj) 
		{
			vectorProductoA.push_back(obj);
		}
		Producto get(int posi)
		{
			return vectorProductoA[posi];
		}
		int rows()
		{
			return vectorProductoA.size(); 
		}
		Producto busquedaPorCodigoProducto(int cod)
		{
			Producto objError;
			objError.setDesProducto("Error"); 
			for(Producto x:vectorProductoA)
			{
				if(cod == x.getCodProducto())
				{
					return x; 
				}
			}
			return objError;
		}
		
		int getPostArray(Producto obj)
		{
			for(int i=0; i<rows(); i++)
			{
				if(obj.getCodProducto() == get(i).getCodProducto())
				{
					return i; 
				}
			}
			return -1;
		}
		
		int getCorrelativo()
		{
			if(vectorProductoA.size() == 0)
			{
				return 0;
			}
			else
			{
				return vectorProductoA[vectorProductoA.size()-1].getCodProducto()+1;
			}
		}
		
		void eliminarProducto(Producto obj)
		{
			vectorProductoA.erase(vectorProductoA.begin() + getPostArray(obj));
		}
		
		bool modificarProducto(Producto a, int codCat, string nomProducto, string desProducto, int cantProducto, float costoProducto)
		{
			for(int i=0; i<rows();i++)
			{
				if(a.getCodProducto()==get(i).getCodProducto())
				{
					vectorProductoA[i].setCodCategoria(codCat);
					vectorProductoA[i].setNomProducto(nomProducto);
					vectorProductoA[i].setDesProducto(desProducto);
					vectorProductoA[i].setCostoProducto(costoProducto);
					vectorProductoA[i].setCantProducto(cantProducto);
					return true; 
				}
			}
			return false; 
		}
		
		
		void grabarProductoEnArchivo(Producto producto)
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("Base_de_Datos_PRODUCTOS.cvs", ios::app);
				if(archivoProducto.is_open())
				{
					archivoProducto<<producto.getCodProducto()<<";"<<producto.getCodCategoria()<<";"<<producto.getNomProducto()<<";"<<producto.getDesProducto()<<";"<<producto.getCostoProducto()<<";"<<producto.getCantProducto()<<";"<<endl;
					archivoProducto.close();
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
				int i;
				size_t posi;
				string linea;
				string temporal[6];
				fstream archivoProducto;
				archivoProducto.open("Base_de_Datos_PRODUCTOS.cvs",ios::in);
				if(archivoProducto.is_open())
				{
					while(!archivoProducto.eof())
					{
						while(getline(archivoProducto, linea))
						{
							i=0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi+1);
								i++;
							}
							Producto producto;
							producto.setCodProducto(std::stoi(temporal[0]));
							producto.setCodCategoria(std::stoi(temporal[1]));
							producto.setNomProducto(temporal[2]);
							producto.setDesProducto(temporal[3]);
							producto.setCostoProducto(std::stoi(temporal[4]));
							producto.setCantProducto(std::stoi(temporal[5]));
							addProducto(producto);
						}
					}
				}
				archivoProducto.close();
				
			}
			catch(exception e)
			{
				cout<<"ERROR AL LEER REGISTRO"<<endl;
			}
		}
		
		void grabarProductoModificadoEnArchivo()
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("Base_de_Datos_PRODUCTOS.cvs",ios::out);
				if(archivoProducto.is_open())
				{
					for(Producto x:vectorProductoA)
					{
						archivoProducto<<x.getCodCategoria()<<";"<<x.getCodProducto()<<";"<<x.getNomProducto()<<";"<<x.getDesProducto()<<";"<<x.getCostoProducto()<<";"<<x.getCantProducto()<<";"<<endl;
					}
					archivoProducto.close();
				}
			}
			catch (exception e)
			{
				cout<<"ERROR AL GRABAR";
			}
		}
};
