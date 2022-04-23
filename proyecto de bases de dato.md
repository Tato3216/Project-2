#*proyecto 2*
##bases de datos por medio de MYSQl

Autores

-*Santos Genaro Hernandez Gabriel*

-*Bairon Ismael Castellanos Valle*

-*Elmer Eduardo Istupe Ruiz*

##Librerías para la funcion en general

#include <iostream>#include <mysql.h>#include <cstdlib>#include <fstream>#include <windows.h>#include <string.h>#include <stdio.h>#include <stdlib.h>

###using namespace std;

void agregar();
void mostrar ();

char serverdb[] = "localhost";
char userdb[] = "root";
char passworddb[] = "A5000shg";
char database[] = "umg";
_________________________________________________
##Variables Globales

1)string clave;

2)string name;

3)string correo;


4)string promedio;

5)string grado;

6)string codigo_grado;

7)string seccion;

8)string sql;

9)string nota1;

10)string nota2;

11)string nota3;

12)string nota4;

----------------------------------------------------------------------
>[!NOTE]
>
>En esta funcion el sistema nos dara a conocer que la vinculacion con la bases de datos fue correcta*

const char* query;
int result;
connection = mysql_init(0);
	if (connection) 
	{
	  cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
	  connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
	  if (connection)
---------------------------------------------------------------------
Contrario: si la conexion fue exitosa automaticamente abrira un menu

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
	cout << "Ingrese la seccion del alumno: ";
	getline(cin, seccion);
	cout  <<"Ingrese la nota del primer bimestre: ";
	getline(cin, nota1);
	cout << "Ingrese la nota del segundo bimestre: ";
	getline(cin, nota2);
    cout << "Ingrese la nota del tercer bimestre: ";
	getline(cin, nota3);
	cout << "Ingrese la nota del cuarto bimestre: ";

*Al tener todos los datos del usuario se ingresaran al archivo en su orden correspondiente*

           	sql = "INSERT INTO alumno(clave, name, correo, grado, codigo_grado, seccion, nota1, nota2, nota3, nota4) VALUES ('" + clave + "','" + name + "', '" + correo + "', '" + grado + "', '" + codigo_grado + "', '" + seccion + "','" + nota1 + "','" + nota2 + "', '" + nota3 + "', '" + nota4 + "')";    
	query = sql.c_str();
	result = mysql_query(connection, query);
        

### si el registro no fue guardado automaticante el sistema mostrar los siguiente ###

        
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

----------------------------------------------------------------------------
#void mostrar ()	{
*MYSQL connection;*
1)long alumno;

2)string clave;

3)string name;

4)string correo;

5)string promedio;

6)string grado;

7)string codigo_grado;

8)string seccion;

9)string sql;

10)string nota1;

11)string nota2;

12)string nota3;

13)string nota4;

---------------------------------------------------------------------------
##Se abrira el archivo (mysql se ha iniciado) y al ingresar el identificador buscara en el archivo

int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 

####Leera el archivo de inicio a fin

    cout << "Conexion exitosa a la base de datos" << endl;	
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT clave, name,correo,grado,codigo_grado,seccion, nota1,nota2,nota3,nota4, (nota1 + nota2 + nota3 + nota4) / 4 prom FROM alumno";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 

###Mostrara los datos que esten en la linea del identificador que se encuentre

cout << "Se han obtenido los datos de forma exitosa" << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i< countColumns; i++)
					{
						cout<<row[i] << "\t";
					}
					cout<<endl;
----------------------------------------------------------------
##Despues el sistema dara inicio al manejo de datos

int eleccion=0;
    do{
        system("cls");
        cout<<"*****MANEJO BASE DE DATOS (CRUD)*****"<<endl;
        cout<<"1 - INGRESAR ALUMNO"<<endl;
        cout<<"2 - BUSCAR ALUMNO"<<endl;
        cout<<"3 - MOSTRAR ALLUMNOS"<<endl;
        cout<<"4 - SALIR"<<endl;
        cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl;
        cin>>eleccion;

###en la cual empezara el metodo de eleccion

switch (eleccion){
	    case 1: agregar();
	    system ("pause");
        break;
        
        case 3: mostrar();
        system ("pause");
        break;
        
        case 4:
        cout<<"Saliendo..."; system ("pause");
        break;
        
        default:
        cout<<"opcion Invalida";system ("pause");
         break;    
    }
       }while (eleccion!=4);
    system("cls");
    return 0;        
	}
	