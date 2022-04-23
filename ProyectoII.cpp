#include <iostream>
#include <mysql.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void agregar();
void mostrar ();
char serverdb[] = "localhost";
char userdb[] = "root";
char passworddb[] = "A5000shg";
char database[] = "umg";
	
void agregar(){
MYSQL* connection;
long alumno;
string clave;
string name;
string correo;
string promedio;
string grado;
string codigo_grado;
string seccion;
string sql;
string nota1;
string nota2;
string nota3;
string nota4;
const char* query;
int result;
connection = mysql_init(0);
	if (connection) 
	{
	cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
	connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
	if (connection) 
	{
	cout << "Conexion exitosa a la base de datos" << endl;
	system("cls");
	getline(cin, clave);
	cout  <<"Ingrese la clave del alumno: ";
	getline(cin, clave);
	cout << "Ingrese el nombre del alumno: ";
	getline(cin, name);
    cout << "Ingrese el correo del alumno: ";
	getline(cin, correo);
	cout << "Ingrese el grado del alumno: ";
	getline(cin, grado);
	cout << "Ingrese el codigo del grado del alumno: ";
	getline(cin, codigo_grado);
	cout << "Ingrese la seccion del alumno (A,B,C): ";
	getline(cin, seccion);
	cout  <<"Ingrese la nota del primer bimestre: ";
	getline(cin, nota1);
	cout << "Ingrese la nota del segundo bimestre: ";
	getline(cin, nota2);
    cout << "Ingrese la nota del tercer bimestre: ";
	getline(cin, nota3);
	cout << "Ingrese la nota del cuarto bimestre: ";
	getline(cin, nota4);	
	sql = "INSERT INTO alumno(clave, name, correo, grado, codigo_grado, seccion, nota1, nota2, nota3, nota4) VALUES ('" + clave + "','" + name + "', '" + correo + "', '" + grado + "', '" + codigo_grado + "', '" + seccion + "','" + nota1 + "','" + nota2 + "', '" + nota3 + "', '" + nota4 + "')";    
	query = sql.c_str();
	result = mysql_query(connection, query);
	if (result == 0) 
	{
	cout << "Registro guardado"<< endl;				
	}
	else
	{
	cout << "No fue posible guardar el registro " << mysql_error(connection) << endl;
			}	
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	
	
void buscar ()	{
MYSQL* connection;
long alumno;
string sql;
string x;
int i, j, k, l;
unsigned long   *lon;
const char* query;
int result;
connection = mysql_init(0);
	
	if (connection) 
	{
	cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
	connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
	if (connection) 
		{
		cout << "Conexion exitosa a la base de datos" << endl;	
		cout << "Ingresa el nombre del alumno que deseas ver" << endl;
		cin>>x;							
		MYSQL_ROW row;
		MYSQL_RES* data;
		sql = "SELECT clave, name,correo,grado,codigo_grado,seccion, nota1,nota2,nota3,nota4, (nota1 + nota2 + nota3 + nota4) / 4 prom FROM alumno WHERE name = ('" + x + "')" ;
		query = sql.c_str();
		result = mysql_query(connection, query);
		if (result == 0) 
			{
			cout << "Se han obtenido los datos de forma exitosa" << endl;
			if((data=mysql_store_result(connection))){
				i=(int)mysql_num_rows(data);
				j=(int)mysql_num_fields(data);
				cout<<endl<<"		Datos de Todos Los Alumnos"<<endl;
				l=1;
				for(l=0;l<i;l++){
				row=mysql_fetch_row(data);
				lon=mysql_fetch_lengths(data);
				cout<<endl;
				for(k=0;k<j;k++){
				cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
		}			
	}
	else 
	{
		cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
	}
	}
	else 
	{
	cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	}
	
void buscar1()	{
MYSQL* connection;
long alumno;
string sql;
string x;
int i, j, k, l;
unsigned long   *lon;
const char* query;
int result;
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			cout << "Ingresa el grado del alumno que deseas ver" << endl;
			cin>>x;							
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT clave, name,correo,grado,codigo_grado,seccion, nota1,nota2,nota3,nota4, (nota1 + nota2 + nota3 + nota4) / 4 prom FROM alumno WHERE grado = ('" + x + "')" ;
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				if((data=mysql_store_result(connection))){
					i=(int)mysql_num_rows(data);
					j=(int)mysql_num_fields(data);
					cout<<endl<<"		Datos de Todos Los Alumnos"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(data);
						lon=mysql_fetch_lengths(data);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<" ";
					}
					cout<<endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}			
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	}
	

void eliminar()	{
MYSQL* connection;
long alumno;
string sql;
string x;
unsigned long   *lon;
const char* query;
int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			cout << "Ingresa el nombre del alumno que deseas eliminar" << endl;
			cin>>x;							
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "DELETE FROM alumno WHERE name = ('" + x + "')" ;
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se ha eliminado el registro de forma exitosa" << endl;
				cout<<endl;
	}
	}
	}
	}
	
void modificar ()	{
MYSQL* connection;
long alumno;
string clave;
string name;
string correo;
string sql;
string nota1;
string nota2;
string nota3;
string nota4;
string x;
int i, j, k, l;
unsigned long   *lon;

const char* query;
int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			system("cls");
			cout << "Ingresa el nombre del alumno que deseas modificar" << endl;
			cin>>x;							
        	getline(cin, clave);
        	cout  <<"Ingrese el nuevo nombre del alumno: ";
			getline(cin, name);
			cout << "Ingrese el nuevo correo del alumno: ";
			getline(cin, correo);
   			cout << "Ingrese la nota nueva del primer bimestre : ";
			getline(cin, nota1);
			cout << "Ingrese la nota nueva del segundo bimestre : ";
			getline(cin, nota2);
			cout << "Ingrese la nota nueva del tercer bimestre : ";
			getline(cin, nota3);
			cout << "Ingrese la nota nueva del cuarto bimestre : ";
			getline(cin, nota4);
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "UPDATE alumno SET name = ('" + name + "'), correo = ('" + correo + "'), nota1 = ('" + nota1 + "'), nota2 = ('" + nota2 + "'), nota3 = ('" + nota3 + "'), nota4 = ('" + nota4 + "') WHERE name = ('" + x + "')" ;
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han modificado los datos de forma exitosa" << endl;
				if((data=mysql_store_result(connection))){
					i=(int)mysql_num_rows(data);
					j=(int)mysql_num_fields(data);
					cout<<endl<<""<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(data);
						lon=mysql_fetch_lengths(data);
						cout<<endl;
						for(k=0;k<j;k++){
					}
					cout<<endl;
				}
			}
			else
			{
				cout << " No se pudo realizar la modificacio" << mysql_error(connection) << endl;
			}			
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	}		
	
void modificar1 ()	{
MYSQL* connection;
long alumno;
string clave;
string grado;
string codigo_grado;
string seccion;
string sql;
string x;
int i, j, k, l;
unsigned long   *lon;
const char* query;
int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			system("cls");
			cout << "Ingresa el nombre del alumno que deseas modificar" << endl;
			cin>>x;							
        	getline(cin, clave);
        	cout  <<"Ingrese el nuevo grado del alumno: ";
			getline(cin, grado);
			cout << "Ingrese el nuevo codigo del grado: ";
			getline(cin, codigo_grado);
   			cout << "Ingrese la nueva seccion del alumno(A,B,C): ";
			getline(cin, seccion);
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "UPDATE alumno SET grado = ('" + grado + "'), codigo_grado = ('" + codigo_grado + "'), seccion = ('" + seccion + "') WHERE name = ('" + x + "')";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han modificado los datos de forma exitosa" << endl;
				if((data=mysql_store_result(connection))){
					i=(int)mysql_num_rows(data);
					j=(int)mysql_num_fields(data);
					cout<<endl<<"		Datos de Todos Los Alumnos"<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(data);
						lon=mysql_fetch_lengths(data);
						cout<<endl;
						for(k=0;k<j;k++){
					}
					cout<<endl;
				}
			}
			else
			{
				cout << " No se pudo realizar la modificacion" << mysql_error(connection) << endl;
			}			
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	}
	
void mostrar()	{
MYSQL* connection;
long alumno;
string sql;
string x;
string y;
int i, j, k, l;
unsigned long   *lon;

const char* query;
int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			cout << "Ingresa el grado" << endl;
			cin>>x;	
			cout << "Ingresa la seccion (A,B,C)" << endl;
			cin>>y;							
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT * FROM alumno WHERE grado = ('" + x + "') AND seccion = ('" + y + "')" ;
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				if((data=mysql_store_result(connection))){
					i=(int)mysql_num_rows(data);
					j=(int)mysql_num_fields(data);
					cout<<endl<<""<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(data);
						lon=mysql_fetch_lengths(data);
						cout<<endl;
						for(k=0;k<j;k++){
						cout<<"	"<<((row[k]==NULL)?"NULL":row[k])<<" ";
					}
					cout<<endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}			
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	}
		
	
	int main() {
	MYSQL* connection;
	long alumno;
	string clave_id;
	string name;
	string correo;
	string promedio;
	string grado;
	string codigo_grado;
	string seccion;
	string sql;
	const char* query;
	int result;
	connection = mysql_init(0);

	int eleccion=0;
    do{
        system("cls");
        cout<<"*****MANEJO BASE DE DATOS (CRUD)*****"<<endl;
        cout<<"1 - INGRESAR NUEVO ALUMNO"<<endl;
        cout<<"2 - BUSCAR ALUMNO"<<endl;
        cout<<"3 - BUSCAR ALUMNOS POR EL GRADO"<<endl;
        cout<<"4 - ELIMINAR UN ALUMNO"<<endl;
        cout<<"5 - MODIFICA ALUMNO(nombre,correo, notas)"<<endl;
        cout<<"6 - MODIFICAR ALUMNO(grado, codigo del grado, seccion)"<<endl;    
        cout<<"7 - MOSTRAR ALUMNOS POR GRADO Y SECCION"<<endl;
        cout<<"8 - SALIR"<<endl;
        cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl;
        cin>>eleccion;
        
  switch (eleccion){
	    case 1: agregar();
	    system ("pause");
        break;
        
        case 2: buscar();
        system ("pause");
        break;
        
        case 3: buscar1();
        system ("pause");
        break;
        
        case 4: eliminar();
        system ("pause");
        break;

        case 5: modificar();
        system ("pause");
        break;
        
        case 6: modificar1();
        system ("pause");
        break;
        
        case 7: mostrar();
        system ("pause");
        break;
        
        case 8:
        cout<<"Saliendo..."; 
		system ("pause");
        break;
        
        default:
        cout<<"opcion Invalida";system ("pause");
         break;    
    }
       }while (eleccion!=8);
    system("cls");
    return 0;        
	}
	
	
	
	
	


