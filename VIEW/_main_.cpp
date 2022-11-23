#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <locale.h>
#include <vector>
#include"..\CONTROLLER\_usuarioController_.h"
#include"..\CONTROLLER\_clienteController_.h"
#include"..\CONTROLLER\_productoController_.h"
#include"..\CONTROLLER\_vendedorController_.h"
#include"..\CONTROLLER\VentaController.h"
#include"..\CONTROLLER\_DetalleVentaController_.h"


using namespace std;

//Variables globales
UsuarioController UsuarioVector;
ClienteController  cliente_vector;
ProductoController ProductoVector; 
VendedorController VendedorVector;
VentaController VectorVenta; 
DetalleVentaController vectorDetVenta;
//prototipos
void menuDeOpciones();
void menu2();
void menuCliente();
void addItems();
void addCliente();
void modificarCliente();
void listarClientes();
void EliminarRegistroCliente();
void BuscarRegistroCliente();
void menuProducto();
void addProducto();
void modificarProducto();
void listarProducto();
void eliminarRegistroProducto();
void buscarRegistroProducto();
void menuVendedores();
void addVendedor();
void modificarVendedor();
void listarVendedor();
void EliminarRegistroVendedor();
void BuscarRegistroVendedor();
void validacion();
void MenuDeVenta();

int main(int argc, char *argv[]) {
	
	menuDeOpciones();
	return 0;
}

//Implementación

void menuDeOpciones()
{
	setlocale(LC_ALL, "spanish");
	int opt;
	do
	{
		cout<<"\n\t------VENTA MAS COMPANY------\n";
		cout<<"\n\t******************************";
		cout<<"\n\t\tMENU DE OPCIONES\n";
		cout<<"\n\tREGISTRARSE    [1]";
		cout<<"\n\tINICIAR SESION [2]";
		cout<<"\n\tSALIR          [3]\n";
		cout<<"\n\t******************************";
		cout<<"\n\tINGRESE UNA OPCION:";
		cin>>opt;
		switch(opt)
		{
		case 1:system("cls");addItems();break; 
		case 2:system("cls");validacion();break; 
		case 3:system("cls");cout<<"Gracias por su preferencia!";break;
		default:cout<<"Ingrese una opción válida [1-3]";
		}
	}
	while(opt!=3);
}

void addItems()
{
	string flag;
	string usuario;
	string contra;
	do
	{
		cout<<"\n******************************";
		cout<<"\n\tUsuario: ";
		cin>>usuario;
		cout<<"\n\tContraseña: "; cin.ignore();
		char caracter;
		caracter=getch();
		
		while(caracter !=13)
		{
			contra.push_back(caracter);
			cout<<"*";
			caracter=getch();
		}
		
		cout<<"\n******************************";
		
		cout<<"\nContinuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		Usuario objuser(usuario,contra);
		/*Agregar el objeto al arreglo*/
		UsuarioVector.agregar(objuser);
		//grabar en archivo
		UsuarioVector.grabarEnArchivo(objuser);
		system("cls");
	} while(flag == "S" || flag == "s");
}


void validacion()
{
	
	bool ingresa = false;
	
	string usuario; 
	string contra;
	cout<<"\tIngrese su usuario: ";
	cin>>usuario;
	cout<<"\tIngrese su contraseña: ";
	
	
	char caracter;
	caracter=getch();
	
	while(caracter !=13)
	{
		contra.push_back(caracter);
		cout<<"*";
		caracter=getch();
	}
	
	
	for(int i=0; i<UsuarioVector.rows();i++)
	{
		if(UsuarioVector.get(i).getUsuario()==usuario && UsuarioVector.get(i).getContra() == contra)
		{
			ingresa = true; 
			break;
		}
		
	}
	
	if(!ingresa)
	{
		cout<<"\nEl usuario o la contraseña son incorrectos"<<endl;
		system("pause");
		system("cls");
		
		
	}
	else
	{
		system("cls");
		cout<<"\tBienvenido";
		menu2();
	}
	
}


void menu2()
{
	int opt; 
	cout<<"\nCLIENTE-------[1]";
	cout<<"\nVENDEDORES------[2]";
	cout<<"\nPRODUCTOS----[3]";
	cout<<"\nGENERAR VENTA-[4]";
	cout<<"\nCERRAR SESISON--[5]";
	cout<<"\nIngrese una opción: "<<endl;
	cin>>opt; 	
	
	switch(opt)
	{
		case 1: system("cls"); system("pause"); menuCliente(); break; 
		case 2: system("cls"); system("pause"); menuVendedores(); break;
		case 3: system("cls"); system("pause"); menuProducto(); break;
		case 4: system("cls"); system("pause"); MenuDeVenta(); break;
		case 5: system("cls"); system("pause"); menuDeOpciones(); break;
		default: "Elija una de las 5 opciones";
	}
}

void menuCliente()
{
	system("cls");
	int optCliente; 
	cout<<"\n------MENU CLIENTES------";
	cout<<"\nAgregar Cliente-----[1]";
	cout<<"\nModificar Cliente---[2]";
	cout<<"\nListar Clientes-----[3]";
	cout<<"\nEliminar Cliente----[4]";
	cout<<"\nBuscar Cliente------[5]";
	cout<<"\nRegresar------[6]";
	cout<<"\nEliga una opción: ";
	cin>>optCliente; 
	
	switch(optCliente)
	{
		case 1:system("cls"); addCliente(); break;
		case 2:modificarCliente(); break;
		case 3:listarClientes(); break;
		case 4:EliminarRegistroCliente(); break;
		case 5:BuscarRegistroCliente(); break;
		case 6:system("cls"); menu2(); break;
		default: cout<<"Ingrese una opción válida [1-6]";
	}
	
}

void addCliente()
{
	string nom, continuidad, ape, identi;
	int cod; 
	
	cout<<"\t--Añadir Clientes--\t"<<endl; 
	do
	{
		cout<<"\n";
		cod = cliente_vector.getCorrelativo(); 
		cout<<"Codigo: "<<"("<<cod<<")"<<endl; 
		cin.ignore();
		cout<<"Ingrese nombre del cliente: "; getline(cin, nom);
		cout<<"Ingrese apellido del cliente: "; getline(cin, ape);
		cout<<"Ingrese DNI del cliente: "; getline(cin, identi);
		cout<<"                         "<<endl;
		Cliente ClienteA;
		ClienteA.setNomCliente(nom);
		ClienteA.setApeCliente(ape);
		ClienteA.setDniCliente(identi);
		ClienteA.setCodCliente(cod);
		
		cliente_vector.agregar(ClienteA);
		cliente_vector.grabarEnArchivo(ClienteA);
		cout<<"Ingrese si o no para seguir ingresando datos: "; 
		cin>>continuidad; 
		system("cls");
	}while(continuidad == "SI" || continuidad == "si");
	menuCliente();
	
}

void modificarCliente()
{
	system("cls");
	int cod; 
	cout<<"Ingrese el codigo del cliente a modificar: "<<endl;
	cin>>cod; 
	Cliente objmod = cliente_vector.busquedaPorCod(cod); 
	
	cout<<"----Registro Encontrado----"<<endl;
	cout<<"Codigo: "<<objmod.getCodCliente()<<"\n"; 
	cout<<"Nombre: "<<objmod.getNomCliente()<<"\n";
	cout<<"Apellido: "<<objmod.getApeCliente()<<"\n";
	cout<<"DNI: "<<objmod.getDniCliente()<<"\n"; 
	cin.ignore();
	
	string nomClienteModi;
	string apeClienteModi;
	string dniClienteModi;
	cout<<"---ACTUALIZAR DATOS---\n";
	cout<<"Actualice nombre: "; getline(cin, nomClienteModi);
	cout<<"Actualice apellido: "; getline(cin, apeClienteModi);
	cout<<"Actualice DNI: "; getline(cin, dniClienteModi); 
	
	bool estado = cliente_vector.modificar(objmod, nomClienteModi, apeClienteModi, dniClienteModi);
	if(estado = true)
	{
		cout<<"Registro modificado con exito\n";
		cliente_vector.agregarRegistroModificado();
	}
	else
	{
		cout<<"Error al modificar los datos del cliente\n";
	}
	system("pause");
	menuCliente();
}

void listarClientes()
{
	cout<<"Nuestros Clientes: "<<endl; 
	if(cliente_vector.tam()==0)
	{
		cout<<"\n";
		cout<<"No se han encontrado datos\n"<<endl;
		system("pause"); 
		menuCliente();
	}
	else
	{
		for(int i=0; i<cliente_vector.tam();i++)
		{
			cout<<"\n";
			cout<<"Codigo: "<<cliente_vector.extraer(i).getCodCliente()<<endl; 
			cout<<"Nombre: "<<cliente_vector.extraer(i).getNomCliente()<<endl; 
			cout<<"Apellido: "<<cliente_vector.extraer(i).getApeCliente()<<endl; 
			cout<<"DNI: "<<cliente_vector.extraer(i).getDniCliente()<<endl; 
		}
		system("pause");
		system("cls");
		menuCliente();
	}
}

void EliminarRegistroCliente()
{
	int cod;
	string eleccion; 
	system("cls");
	cout<<"Ingrese el codigo del registro que quiere eliminar: "<<endl; 
	cin>>cod; 
	Cliente ClienteEliminar = cliente_vector.busquedaPorCod(cod);
	cout<<"\n";
	if(ClienteEliminar.getNomCliente() == "Error")
	{
		cout<<"No se encontraron datos"<<endl; 
		system("pause");
		menuCliente();
	}
	else
	{
		cout<<"\n---REGISTRO HALLADO---";
		cout<<"Codigo: "<<ClienteEliminar.getCodCliente()<<endl; 
		cout<<"Nombre: "<<ClienteEliminar.getNomCliente()<<endl; 
		cout<<"Apellido: "<<ClienteEliminar.getApeCliente()<<endl;
		cout<<"DNI: "<<ClienteEliminar.getDniCliente()<<endl;
		cin.ignore();
		cout<<"Esta seguro de eliminar el registro? [Si/No]: ";
		cin>>eleccion; 
		if(eleccion == "si" || eleccion == "SI")
		{
			cliente_vector.eliminar(ClienteEliminar);
			cout<<"REGISTRO ELIMINADO CON EXITO"<<endl; 
			cliente_vector.agregarRegistroModificado();
			system("pause");
			menuCliente();
		}
		else
		{
				system("pause");
				EliminarRegistroCliente();
		}
	}
}

void BuscarRegistroCliente()
{
	system("cls");
	int cod; 
	cout<<"BUSQUEDA DE REGISTRO: "<<endl; 
	cout<<"Ingrese el codigo del registro a buscar: "<<endl; 
	cin>>cod; 
	Cliente ClienteBuscar = cliente_vector.busquedaPorCod(cod); 
	if(ClienteBuscar.getNomCliente() != "Error")
	{
		cout<<"\nREGISTRO HALLADO: ";
		cout<<"Codigo: "<<ClienteBuscar.getCodCliente()<<endl;
		cout<<"Nombre: "<<ClienteBuscar.getNomCliente()<<endl;
		cout<<"Apellido: "<<ClienteBuscar.getApeCliente()<<endl;
		cout<<"DNI: "<<ClienteBuscar.getDniCliente()<<endl; 
		system("pause");
		menuCliente();
	}
	else 
	{
		cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
	}
	system("pause");
	menuCliente();
}

void menuProducto()
{
	system("cls");
	int optProducto; 
	cout<<"\n------MENU PRODUCTO------";
	cout<<"\nAgregar Producto-----[1]";
	cout<<"\nModificar Producto---[2]";
	cout<<"\nListar Producto------[3]";
	cout<<"\nEliminar Producto----[4]";
	cout<<"\nBuscar Producto------[5]";
	cout<<"\nRegresar------[6]";
	cout<<"\nEliga una opción: ";
	cin>>optProducto;
	
	switch(optProducto)
	{
	case 1: addProducto(); system("cls"); break;
	case 2: modificarProducto(); break;
	case 3: listarProducto(); system("pause"); system("cls"); break;	
	case 4: eliminarRegistroProducto(); break;
	case 5: buscarRegistroProducto(); break;
	case 6: menu2(); break;
	default: cout<<"Ingrese una opcion correcta [1-6]"<<endl;
	system("pause");
	system("cls");
	menuProducto();
	}
}

void addProducto()
{
	int codPro, cantPro, codCate; 
	string desPro, nomPro; 
	float costo;
	string eleccion; 
	do{
		cout<<"\nINGRESE LOS DATOS DEL PRODUCTO"<<endl;
		codPro = ProductoVector.getCorrelativo();
		
		cout<<"\nCodigo: "<<"["<<codPro+1<<"]"<<endl; 
		cout<<"\nIngrese nombre del producto: "; cin>>nomPro;  cin.ignore();
		cout<<"\nIngrese descripción del producto: "; getline(cin, desPro);
		cout<<"\nIngrese precio del producto: "; cin>>costo; 
		cout<<"\nIngrese la cantidad del producto: "; cin>>cantPro;
		
		cout<<"*******CATEGORIAS*********\n";
		cout<<"[1]PRODUCTOS DE ESCRITORIO\n";
		cout<<"[2]PRODUCTOS DOMESTICOS\n";
		cout<<"[3]PRODUCTOS TECNOLOGIA\n";
		cout<<"Elige una categoria: \n";
		cin>>codCate;
			
		Producto producto;
		producto.setCodProducto(codPro);
		producto.setNomProducto(nomPro);
		producto.setCodCategoria(codCate);
		producto.setDesProducto(desPro);
		producto.setCostoProducto(costo);
		producto.setCantProducto(cantPro); 
		
		ProductoVector.addProducto(producto);
		ProductoVector.grabarProductoEnArchivo(producto);
		
		cout<<"Desea agregar mas registros? [Si/No]: "; 
		cin>>eleccion;
		system("cls"); 
	} while(eleccion=="SI"||eleccion=="si");
	menuProducto();
}

void modificarProducto()
{
	system("cls");
	int codigo; 
	string eleccion; 
	do
	{
		cout<<"Modulo de Modificacion"<<endl;
		cout<<"Ingrese el codigo del registro a modificar: "; 
		cin>>codigo;
		Producto objmodi = ProductoVector.busquedaPorCodigoProducto(codigo);
		
		string desMod, nomMod;
		int cantMod, codCat;
		float precioMod;
		
		cout<<"REGISTRO BUSCADO: "<<endl; 
		cout<<"Codigo: "<<"00"<<objmodi.getCodProducto()<<endl; 
		cout<<"Nombre Producto: "<<objmodi.getNomProducto()<<endl;
		cout<<"Descripcion del producto: "<<objmodi.getDesProducto()<<endl;
		cout<<"Precio: "<<"$"<<objmodi.getCostoProducto()<<endl; 
		cout<<"Cantidad(stock): "<<objmodi.getCantProducto()<<endl;
		cin.ignore();
		
		cout<<"\n";
		cout<<"----Datos por modificar: ----"<<endl;
		cout<<"Nombre: "; cin>>nomMod;
		cout<<"Descripcion: "; cin>>desMod;
		cout<<"Precio: "; cin>>precioMod;
		cout<<"Cantidad(stock): "; cin>>cantMod;
		
		bool estado = ProductoVector.modificarProducto(objmodi, codCat, nomMod, desMod,  precioMod, cantMod);
		if(estado = true)
		{
			cout<<"REGISTRO MODIFICADO CON EXITO"<<endl;
			ProductoVector.grabarProductoModificadoEnArchivo();
			cout<<"Regresar al menu PRODUCTO? [si/no]"; cin>>eleccion; 
		}
		else
		{
			cout<<"ERROR AL MODIFICAR EL REGISTRO"; 
		}
	} while(eleccion=="NO"||eleccion=="no");
	system("pause");
	system("cls");
	menuProducto();
}

void listarProducto()
{
	system("cls");
	if(ProductoVector.rows()==0)
	{
		cout<<"NO SE ENCONTRARON REGISTROS"<<endl;
		system("pause");
		menuProducto();
	}
	else
	{
		for(int i=0;i<ProductoVector.rows();i++)
		{
			cout<<"Codigo: "<<"00"<<ProductoVector.get(i).getCodProducto()<<endl; 
			cout<<"Nombre: "<<ProductoVector.get(i).getNomProducto()<<endl;
			cout<<"Descripcion: "<<ProductoVector.get(i).getDesProducto()<<endl; 
			cout<<"Precio: "<<ProductoVector.get(i).getCostoProducto()<<endl;
			cout<<"Cantidad: "<<ProductoVector.get(i).getCantProducto()<<endl; 
		}
	}
}

void eliminarRegistroProducto()
{
	int codigo;
	string eleccion; 
	system("cls");
	cout<<"Ingrese el codigo del registro que quiere eliminar: "<<endl; 
	cin>>codigo; 
	Producto ProductoEliminar = ProductoVector.busquedaPorCodigoProducto(codigo);
	cout<<"\n";
	if(ProductoEliminar.getNomProducto() == "Error")
	{
		cout<<"No se encontraron datos"<<endl; 
		system("pause");
		menuProducto();
	}
	else
	{
		cout<<"\n---REGISTRO HALLADO---";
		cout<<"Codigo: "<<ProductoEliminar.getCodProducto()<<endl; 
		cout<<"Nombre: "<<ProductoEliminar.getNomProducto()<<endl; 
		cout<<"Descripcion: "<<ProductoEliminar.getDesProducto()<<endl;
		cout<<"Precio: "<<ProductoEliminar.getCostoProducto()<<endl;
		cout<<"Cantidad: "<<ProductoEliminar.getCantProducto()<<endl;
		cin.ignore();
		cout<<"Esta seguro de eliminar el registro? [Si/No]: ";
		cin>>eleccion; 
		if(eleccion == "si" || eleccion == "SI")
		{
			ProductoVector.eliminarProducto(ProductoEliminar);
			cout<<"REGISTRO ELIMINADO CON EXITO"<<endl; 
			ProductoVector.grabarProductoModificadoEnArchivo();
			system("pause");
			menuProducto();
		}
		else
		{
			system("pause");
			eliminarRegistroProducto();
		}
	}
	
}


void buscarRegistroProducto()
{
	system("cls");
	int codigo; 
	cout<<"BUSQUEDA DE PRODUCTO: "<<endl; 
	cout<<"Ingrese el codigo del registro a buscar: "<<endl; 
	cin>>codigo; 
	Producto ProductoBuscar = ProductoVector.busquedaPorCodigoProducto(codigo); 
	if(ProductoBuscar.getNomProducto() != "Error")
	{
		cout<<"\nREGISTRO HALLADO: ";
		cout<<"Codigo: "<<ProductoBuscar.getCodProducto()<<endl;
		cout<<"Nombre: "<<ProductoBuscar.getNomProducto()<<endl;
		cout<<"Descripcion: "<<ProductoBuscar.getDesProducto()<<endl;
		cout<<"Precio: "<<ProductoBuscar.getCostoProducto()<<endl; 
		cout<<"Cantidad: "<<ProductoBuscar.getCantProducto()<<endl;
		system("pause");
		menuProducto();
	}
	else 
	{
		cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
	}
	system("pause");
	menuProducto();
	
}

void menuVendedores()
{
	system("cls");
	int optVendedor; 
	cout<<"\n------MENU VENDEDOR------";
	cout<<"\nAgregar vendedor-----[1]";
	cout<<"\nModificar vendedor---[2]";
	cout<<"\nListar vendedor-----[3]";
	cout<<"\nEliminar vendedor----[4]";
	cout<<"\nBuscar vendedor------[5]";
	cout<<"\nMenú principal------[6]";
	cout<<"\nEliga una opción: ";
	cin>>optVendedor; 
	
	switch(optVendedor)
	{
	case 1:system("cls"); addVendedor(); break;
	case 2:modificarVendedor(); break;
	case 3:listarVendedor(); break;
	case 4:EliminarRegistroVendedor(); break;
	case 5:BuscarRegistroVendedor(); break;
	case 6:system("cls"); menu2(); break;
	default: cout<<"Ingrese una opción válida [1-6]";
	}
}

void addVendedor()
{
	string nom, continuidad, ape, direVendedor, identi;
	int cod; 
	
	cout<<"\t--Añadir Vendedores--\t"<<endl; 
	do
	{
		cout<<"\n";
		cod = VendedorVector.getCorrelativo(); 
		cout<<"Codigo: "<<"("<<cod<<")"<<endl; 
		cin.ignore();
		cout<<"Ingrese nombre del vendedor: "; getline(cin, nom); cin.ignore();
		cout<<"Ingrese apellido del vendedor: "; getline(cin, ape); cin.ignore();
		cout<<"Ingrese direccion del vendedor: "; getline(cin, direVendedor); cin.ignore();
		cout<<"Ingrese DNI del vendedor: "; cin>>identi; 
		cout<<"                         "<<endl;
		
		Vendedor VendedorA;
		VendedorA.setCodVendedor(cod);
		VendedorA.setNomVendedor(nom);
		VendedorA.setApeVendedor(ape);
		VendedorA.setDireVendedor(direVendedor);
		VendedorA.setDniVendedor(identi);
		
		
		
		VendedorVector.agregarVendedor(VendedorA);
		VendedorVector.grabarEnArchivo(VendedorA);
		cout<<"Ingrese si o no para seguir ingresando datos: "; 
		cin>>continuidad; 
		system("cls");
	}while(continuidad == "SI" || continuidad == "si");
	menuVendedores();
	
}
//FALTA MODIFICAR:
void modificarVendedor()
{
	system("cls");
	int cod; 
	cout<<"Ingrese el codigo del vendedor a modificar: "<<endl;
	cin>>cod; 
	Vendedor objmod = VendedorVector.busquedaPorCodVendedor(cod); 
	
	cout<<"----Registro Encontrado----"<<endl;
	cout<<"Codigo: "<<objmod.getCodVendedor()<<"\n"; 
	cout<<"Nombre: "<<objmod.getNomVendedor()<<"\n";
	cout<<"Apellido: "<<objmod.getApeVendedor()<<"\n";
	cout<<"Direccion: "<<objmod.getDireVendedor()<<"\n";
	cout<<"DNI: "<<objmod.getDniVendedor()<<"\n"; 
	cin.ignore();
	
	string nomVendedorModi;
	string apeVendedorModi;
	string direVendedorModi;
	string dniVendedorModi;
	cout<<"---ACTUALIZAR DATOS---\n";
	cout<<"Actualice nombre: "; getline(cin, nomVendedorModi);
	cout<<"Actualice apellido: "; getline(cin, apeVendedorModi);
	cout<<"Actualice direccion: "; getline(cin, direVendedorModi);
	cout<<"Actualice DNI: "; getline(cin, dniVendedorModi); 
	
	bool estado = VendedorVector.modificar(objmod, nomVendedorModi, apeVendedorModi, direVendedorModi, dniVendedorModi);
	if(estado = true)
	{
		cout<<"Registro modificado con exito\n";
		VendedorVector.agregarRegistroModificado();
	}
	else
	{
		cout<<"Error al modificar los datos del cliente\n";
	}
	system("pause");
	menuVendedores();
}

void listarVendedor()
{
	cout<<"Nuestros Vendedores: "<<endl; 
	if(VendedorVector.tamVendedor()==0)
	{
		cout<<"\n";
		cout<<"No se han encontrado datos\n"<<endl;
		system("pause"); 
		menuVendedores();
	}
	else
	{
		for(int i=0; i<VendedorVector.tamVendedor();i++)
		{
			cout<<"\n";
			cout<<"Codigo: "<<VendedorVector.extraer(i).getCodVendedor()<<endl; 
			cout<<"Nombre: "<<VendedorVector.extraer(i).getNomVendedor()<<endl; 
			cout<<"Apellido: "<<VendedorVector.extraer(i).getApeVendedor()<<endl; 
			cout<<"Direccion: "<<VendedorVector.extraer(i).getDireVendedor()<<endl;
			cout<<"DNI: "<<VendedorVector.extraer(i).getDniVendedor()<<endl; 
		}
		system("pause");
		system("cls");
		menuVendedores();
	}
}

void EliminarRegistroVendedor()
{
	int cod;
	string eleccion; 
	system("cls");
	cout<<"Ingrese el codigo del registro que quiere eliminar: "<<endl; 
	cin>>cod; 
	Vendedor VendedorEliminar = VendedorVector.busquedaPorCodVendedor(cod);
	cout<<"\n";
	if(VendedorEliminar.getNomVendedor() == "Error")
	{
		cout<<"No se encontraron datos"<<endl; 
		system("pause");
		menuVendedores();
	}
	else
	{
		cout<<"\n---REGISTRO HALLADO---";
		cout<<"Codigo: "<<VendedorEliminar.getCodVendedor()<<endl; 
		cout<<"Nombre: "<<VendedorEliminar.getNomVendedor()<<endl; 
		cout<<"Apellido: "<<VendedorEliminar.getApeVendedor()<<endl;
		cout<<"Dirección: "<<VendedorEliminar.getDireVendedor()<<endl;
		cout<<"DNI: "<<VendedorEliminar.getDniVendedor()<<endl;
		cin.ignore();
		cout<<"Esta seguro de eliminar el registro? [Si/No]: ";
		cin>>eleccion; 
		if(eleccion == "si" || eleccion == "SI")
		{
			VendedorVector.eliminar(VendedorEliminar);
			cout<<"REGISTRO ELIMINADO CON EXITO"<<endl; 
			VendedorVector.agregarRegistroModificado();
			system("pause");
			menuVendedores();
		}
		else
		{
			system("pause");
			EliminarRegistroVendedor();
		}
	}
}


void BuscarRegistroVendedor()
{
	system("cls");
	int cod; 
	cout<<"BUSQUEDA DE REGISTRO: "<<endl; 
	cout<<"Ingrese el codigo del registro a buscar: "<<endl; 
	cin>>cod; 
	Vendedor VendedorBuscar = VendedorVector.busquedaPorCodVendedor(cod); 
	if(VendedorBuscar.getNomVendedor() != "Error")
	{
		cout<<"\nREGISTRO HALLADO: ";
		cout<<"Codigo: "<<VendedorBuscar.getCodVendedor()<<endl;
		cout<<"Nombre: "<<VendedorBuscar.getNomVendedor()<<endl;
		cout<<"Apellido: "<<VendedorBuscar.getApeVendedor()<<endl;
		cout<<"Direccion: "<<VendedorBuscar.getDireVendedor()<<endl;
		cout<<"DNI: "<<VendedorBuscar.getDniVendedor()<<endl; 
		system("pause");
		menuVendedores();
	}
	else 
	{
		cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
	}
	system("pause");
	menuVendedores();
}

void fechaVenta()
{
	string resultado;
	time_t t;
	t = time(NULL);
	struct tm* fecha;
	fecha = localtime(&t);
	cout	<< "Fecha de Emision: " << fecha->tm_mday << "-" << fecha->tm_mon + 1 << "-" << fecha->tm_year + 1900 << "\t"
		<< "Hora: " << fecha->tm_hour << ":" << fecha->tm_min<< endl;
	
}

void MenuDeVenta()
{	
	string flag, arg, busqPro, nombreCli, nombrePro;
	int cod, codVendedor, cantidad, codPro;
	float total;
	fechaVenta();
	
	cout << "\tCODIGO VENTA ( "<<VectorVenta.getCorrelativo()<<" )"<<endl;
	
	cout << "Nombre del cliente: ";
	cin >> nombreCli;
	Cliente objCli = cliente_vector.busquedaPorNom(nombreCli);
	cout << "DNI: " << objCli.getDniCliente()<<endl;
	cout << "Codigo Cliente: "<<objCli.getCodCliente()<<endl;
	cout << "\n\n";
	DetalleVenta detalle;
	do
	{	
		cout << "\t   GENERANDO VENTA\n";
		cout << "\t---------------------\n";
		
		cin.ignore();
		cout << "Buscar producto por nombre: ";
		getline(cin, busqPro);
		transform(busqPro.begin(), busqPro.end(), busqPro.begin(), ::toupper); 
		
		cout << setw(9) << left << "CODIGO" << setw(28) << left << "DESCRIPCION" <<"PRECIO\n\n"; 
		listarProducto(); 
		
		cout << "\nCodigo del producto: ";
		cin >> codPro;
		Producto producto = ProductoVector.busquedaPorCodigoProducto(codPro);
		
		if (producto.getNomProducto() != "Error")
		{
			cout << "\n\t*** SE ANADIO A SU CARRITO ***\n\n";
			cout	<< "000" << setw(6) << left << producto.getCodProducto() 
				<< setw(28) << left << producto.getNomProducto()
				<< setw(9) << left << producto.getCostoProducto() << endl;
		}
		else
		{
			cout << "NO SE ENCONTRO EL PRODUCTO\n"; break;
		}
		
		cout << "CANTIDAD: "; 
		cin >> cantidad;
		
		detalle.setCodVenta(VectorVenta.getCorrelativo());
		detalle.setDesProducto(producto.getDesProducto());
		detalle.setCodProducto(codPro);
		detalle.setCantProducto(cantidad);
		detalle.setTotVenta(producto.getCostoProducto());
		vectorDetVenta.agregar(detalle);
		total = cantidad*detalle.getTotVenta();
		vectorDetVenta.getPostArray(detalle);
		
		cout << "Desea continuar?(S/s): ";
		cin >> flag;
		system("cls");
	} while (flag == "S" || flag == "s");
	
	vectorDetVenta.grabarEnArchivo(detalle);
	
	Venta venta;
	venta.setCodVenta(VectorVenta.getCorrelativo());
	venta.setCodCliente(cod);
	venta.setFechaVenta(arg);
	venta.setTotVenta(total);
	
	
		cout << "\t******** BOLETA VENTA MAS ********\n";
		fechaVenta();
		cout << "CODIGO: " << venta.getCodVenta() << endl;
		cout << "DNI: " << objCli.getDniCliente() << endl;
		cout << "CLIENTE: " << objCli.getNomCliente() << " " << objCli.getApeCliente() << endl;
		cout << "\tCOD\t" 
			<< "\tDESCRIPCION\t"
			<< "\tCANT\t" 
			<< "\tSUBTOTAL\n\n"; 
		
		for (int i = 0; i < vectorDetVenta.tam(); i++)
		{
			cout	<< "\t000" << vectorDetVenta.extraer(i).getCodProducto()
				<<  "\t\t" << vectorDetVenta.extraer(i).getDesProducto()  
				<<  "\t\t\t" << vectorDetVenta.extraer(i).getCantProducto()  
				<<  "\t\t\t" << vectorDetVenta.extraer(i).getTotVenta()<<  "\n";
			cout << "\t ---------------------------------------------------------\n\n";
			
		}
	cout << setw(49) << right << "IMPORTE TOTAL S/ : " << total << endl;
	system("pause");
	
	VectorVenta.addVenta(venta);
	VectorVenta.grabarVentaEnArchivo(venta);
}





















