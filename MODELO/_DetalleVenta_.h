#include <iostream>
#include"..\MODELO\_venta_.h"
#include"..\MODELO\_producto_.h"

using namespace std;

class DetalleVenta:public Venta, public Producto
	{
	private:
		int cantVenta; 
		float precioVenta; 
	public: 
		DetalleVenta(string nomC, string apeC, string dniC, int codC, int codVenta, string fechaVenta, 
			int numVenta, int totVenta, string estVenta, int codCategoria, string nomCat, int codProducto, 
			string nomProducto, string desProducto, float costoProducto, int cantProducto, int cantVenta, 
			float precioVenta):
			Venta(nomC, apeC, dniC, codC, codVenta, fechaVenta, numVenta, totVenta, estVenta), 
			Producto(codCategoria, nomCat, codProducto, nomProducto, desProducto, costoProducto, cantProducto)
		{
			this->cantVenta = cantVenta;
			this->precioVenta = precioVenta; 
		}
		DetalleVenta()
		{
			
		}
	//set
		void setCantVenta(int cantVenta)
		{
			this->cantVenta=cantVenta;
		}
		void setPrecioVenta(float precioVenta)
		{
			this->precioVenta=precioVenta;
		}
	//get
		int getCantVenta()
		{
			return this->cantVenta;
		}
		float getPrecioVenta()
		{
			return this->precioVenta;
		}
		float getSubTotal()
		{
			precioVenta = this->getCostoProducto() * this->getCantVenta();
			return precioVenta;
		}
};


