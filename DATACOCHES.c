//DATACOCHES

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>	
#define N 30

typedef struct{
	int dia;
	int mes;
	int ano;
}Fecha;

typedef struct{
	char *nombre;
	int dia;
	int mes;
	int hora;
	int min;
}Cita;

typedef struct{
	char *marca;
	char *modelo;
	char *matricula;
	int kilometros;
}Vehiculo;

typedef struct {
	char *nombre;
	Fecha nacimiento;
	char sexo;
	char *nom_usuario;
	char *contrasena;
	int cochesasignados;
	Vehiculo coche;
}Cliente;
 
typedef struct{
 	char *nombre;
 	char *contrasena;
 	char *ocupacion;
}Empleado;

int MenuAcceso();
int IniciarSesionEmpleado();
int IniciarSesionCliente();
int CrearEmpleado();
int CrearCliente();
void CrearCita();
void MenuEmpleado();
void MenuCliente();
void Cambio(char antes[], char *despues);
void Vaciar(char cadena[]);

void main(){
	system("chcp 1252");//Código para que se puedan imprimir letras con tildes
    system("COLOR F0");//Código para cambiar el color del fondo (1er dígito) y de las letras (2o digito) (0 = Negro, 1 = Azul, 2 = Verde, 3 = Aqua, 4 = Rojo, 5 = Púrpura, 6 = Amarillo, 7 = Blanco, 8 =Gris, 9 = Azul Claro, A = Luz Verde, B = Aqua Luz, C = Rojo, D = Luz Violeta, E = = Amarillo Claro, F = Blanco Brillante)

	int opcion1;
	
	do{
	    opcion1 = MenuAcceso();
	    
	    if(opcion1 == 2){
	    	MenuEmpleado();
		}
		else if(opcion1 == 3){
			MenuCliente();
		}
	}
	while(opcion1 != 0);

}

int MenuAcceso(){
	system("chcp 1252");
	system("cls");//Código para limpiar pantalla
	int opcion, opcion1;
	printf("DATACOCHES\n\n");
	printf("¿Qué desea hacer?\n\n");
	do{
        printf("TECLA   ACCIÓN\n  1-    Iniciar sesión como empleado.\n  2-    Iniciar sesión como cliente.\n  0-    Salir del programa.\n\n   OPCIÓN: ");
        scanf("%i", &opcion1);
        
		switch(opcion){
    	    case 1: opcion1 = IniciarSesionEmpleado(opcion1); break;
    	    case 2: opcion1 = IniciarSesionCliente(opcion1); break;
    	    case 0: opcion1 = 0; printf("\nGracias por usar nuestro programa."); break;
    	    default: printf("\nTecla no reconocida."); break;
    	}
	}
    while(opcion != 2 && opcion != 1 && opcion != 0);
    
	return opcion1;
}

void MenuEmpleado(){
	system("chcp 1252");
	system("cls");
	int opcion;
    printf("DATACOCHES\n\n");
	printf("¿Qué desea hacer?\n\n");
	
	do{
	    printf("TECLA   ACCIÓN\n  1-    Consultar datos sobre un vehículo.\n  2-    Consultar estado de un vehículo.\n  _" //Con '_' podemos continuar con la misma instrucción en la siguiente línea
		"3-    Consultar calendario.\n  4-    Generar nueva cita.\n  5-    Crear nuevo cliente.\n  0-    Salir del programa.\n\n   OPCIÓN: ");
	    scanf("%i" ,&opcion);
	    printf("\n\n");
	    switch(opcion)
	    {
	    	case 1:
	    		printf("CONSULTA DE DATOS\nIntroduzca la matrícula del vehículo:");
	    		break;
	    	case 2:
	    		printf("CONSULTA DE ESTADO\nIntroduzca la matrícula del vehículo:");
		    	break;
	    	case 3:
		    	printf("CALENDARIO\n\n");
			    break;
	    	case 4:
		    	printf("NUEVA CITA\n\n");
		    	CrearCita();
			    break;
    		case 5:
	    		printf("NUEVO EMPLEADO\n\n");
	    		CrearEmpleado();
		    	break;
		    case 6:
	    		printf("NUEVO CLIENTE\n\n");
	    		CrearCliente();
		    	break;
    		case 0:
	    		printf("Gracias por usar nuestro programa.");
		    	break;
    		default:
	    		printf("Tecla no reconocida");
		    	break;	
    	}
    	printf("\n\n");//doble salto de línea provisional
	    system("pause");
	}
	while (opcion != 0);
}

void CrearCita(){	
	system("chcp 1252");
	system("cls");
	
	FILE *citas;
	Cita cita;
	int aux1, aux2;
	char nom[N];
	
	citas = fopen("citas.txt", "a");
	if (citas == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	
	printf("DATACOCHES\n\n");
	printf("NUEVA CITA\n\n");
	
	printf("Nombre y apellido: ");
	scanf("%[^\n]s", nom);
	cita.nombre = (char*)malloc((strlen(nom)+1)*sizeof(char));
	Cambio(nom, cita.nombre);
	fflush(stdin);
	do{
		printf("Mes(nº): ");
		scanf("%i", &cita.mes);
		if(cita.mes < 1 || cita.mes > 12){
			printf("Introduzca el mes de nuevo\n");
		}
		fflush(stdin);
	}
	while(cita.mes < 1 || cita.mes > 12);
	do{
		aux1 = 0;
		printf("Día: ");
		scanf("%i", &cita.dia);
		if((cita.mes == 1 || cita.mes == 3 || cita.mes == 5 || cita.mes == 7 || cita.mes == 8 || cita.mes == 10 || cita.mes == 12) && (cita.dia < 1 || cita.dia > 31)){
			printf("Introduzca el día de nuevo\n");
			aux1 = 1;
		}
		else if(cita.mes == 2 && (cita.dia < 1 || cita.dia > 28)){
			printf("Introduzca el día de nuevo\n");
			aux1 = 1;
		}
		else if((cita.mes == 4 || cita.mes == 6 || cita.mes == 9 || cita.mes == 11) && (cita.dia < 1 || cita.dia > 30)){
			printf("Introduzca el día de nuevo\n");
			aux1 = 1;
		}
		fflush(stdin);
	}
	while(aux1 == 1);
	do{
		aux2 = 0;
		printf("Hora(hh mm): ");
		scanf("%i %i", &cita.hora, &cita.min);
		if(cita.hora < 9 || cita.hora > 19 || cita.hora == 14){
			printf("Introduzca la hora de nuevo\n");
			aux2 = 1;
		}
		if (cita.min != 0 && cita.min != 10 && cita.min != 20 && cita.min != 30 && cita.min != 40 && cita.min != 50){
			printf("Los minutos indicados sólo pueden ser 0, 10, 20, 30, 40 y 50\n");
			aux2 = 1;
		}
		fflush(stdin);
	}
	while(aux2 == 1);
	
	fprintf(citas, "%s,%i:%i,%i,%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
	
	printf("\nLe confirmamos su cita: \nNOMBRE: %s HORA: %i:%i DÍA: %i MES: %i", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
	
	fclose(citas);
}

int CrearEmpleado(){
	system("chcp 1252");
	system("cls");
	
	FILE *empleados;
	int i = 0, contrasena;
	char nom[N], ocup[N], cont[N];//Cadenas de caracteres para memoria dinámica
	Empleado emp;
	
	empleados = fopen("empleados.txt", "a");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	printf("DATACOCHES\n\n");
	printf("NUEVO EMPLEADO\n\n");
	
	while(i < 3){
		printf("Contraseña de administrador: ");
		scanf("%i", &contrasena);
		if(contrasena == 1111){
			printf("\nIntroduzca los datos del empleado.\n");
        	printf("Nombre: ");
			scanf("%s", nom);
        	emp.nombre = (char*)malloc((strlen(nom)+1)*sizeof(char));//Asignamos el espacio para el string dinámico
			Cambio(nom, emp.nombre);
			printf("Ocupación: ");
			scanf("%s", ocup);
        	emp.ocupacion = (char*)malloc((strlen(ocup)+1)*sizeof(char));
			Cambio(ocup, emp.ocupacion);
			printf("Contraseña: ");
			scanf("%s", cont);
        	emp.contrasena = (char*)malloc((strlen(cont)+1)*sizeof(char));
        	Cambio(cont, emp.contrasena);
        	
			fprintf(empleados, "%s,%s,%s\n", emp.nombre, emp.ocupacion, emp.contrasena);
			
			printf("¡Empleado registrado correctamente!");
			
			i = 3;//Ruta de escape
		}
		else{
			i++;
			printf("Quedan %i intentos\n", 3 - i);
			if(i == 3)
        	printf("Consulte con el administrador");
		}
	}
	fclose(empleados);
	return 1;
}

int CrearCliente(){//Mismo funcionamiento que NuevoEmpleado()
	system("chcp 1252");
	system("cls");
	
	FILE *clientes, *vehiculos;
	int i;
	char nom[N], us[N], cont[N], mar[N], mod[N], mat[N];//Usuario = us, Marca = mar
	Cliente clie;
	
	clientes = fopen("clientes.txt", "a");
	if (clientes == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	
	vehiculos = fopen("vehiculos.txt", "a");
	if (vehiculos == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	
	printf("DATACOCHES\n\n");
	printf("NUEVO CLIENTE\n\n");
	
	printf("\nIntroduzca sus datos\n");
    printf("Nombre completo: ");
	scanf("%[^\n]s", nom);
   	clie.nombre = (char*)malloc((strlen(nom)+1)*sizeof(char));
	Cambio(nom, clie.nombre);
	fflush(stdin);
	printf("Nombre de usuario: ");
	scanf("%[^\n]s", us);
   	clie.nom_usuario = (char*)malloc((strlen(us)+1)*sizeof(char));
	Cambio(us, clie.nom_usuario);
	fflush(stdin);
	do{
		printf("Sexo (Masculino 'M' o Femenino 'F' u Otro 'O'): ");
    	scanf("%c", &clie.sexo);
    	fflush(stdin);
    	if(clie.sexo != 'M' && clie.sexo != 'F' && clie.sexo != 'O'){
    		printf("Introduzca de nuevo el sexo\n");
		}
	}
	while(clie.sexo != 'M' && clie.sexo != 'F' && clie.sexo != 'O');
	do{
		printf("Fecha de nacimiento(día mes año): ");
		scanf("%i %i %i", &clie.nacimiento.dia, &clie.nacimiento.mes, &clie.nacimiento.ano);
    	fflush(stdin);
    	if(clie.nacimiento.dia < 1 || clie.nacimiento.dia > 31 || clie.nacimiento.mes < 1 || clie.nacimiento.mes > 12 || clie.nacimiento.ano < 1900 || clie.nacimiento.ano > 2001){
    		printf("Introduzca de nuevo la fecha\n");
		}
	}
	while(clie.nacimiento.dia < 1 || clie.nacimiento.dia > 31 || clie.nacimiento.mes < 1 || clie.nacimiento.mes > 12 || clie.nacimiento.ano < 1900 || clie.nacimiento.ano > 2001);
	printf("Contraseña: ");
	scanf("%s", cont);
   	clie.contrasena = (char*)malloc((strlen(cont)+1)*sizeof(char));
   	Cambio(cont, clie.contrasena);
   	fflush(stdin);
   	do{
   		printf("Número de coches: ");
   		scanf("%i", &clie.cochesasignados);
   		fflush(stdin);
   		if(clie.cochesasignados < 1){
   			printf("Debe introducir al menos un vehículo\n");
		}
	}
	while(clie.cochesasignados < 1);
	
	for(i = 1; i <= clie.cochesasignados; i++){
		printf("\nCOCHE %i\n", i);
	    printf("Marca: ");
	    scanf("%s", mar);
   	    clie.coche.marca = (char*)malloc((strlen(mar)+1)*sizeof(char));
   	    Cambio(mar, clie.coche.marca);
   	    fflush(stdin);
		printf("Modelo: ");
	    scanf("%[^\n]s", mod);
   	    clie.coche.modelo = (char*)malloc((strlen(mod)+1)*sizeof(char));
   	    Cambio(mod, clie.coche.modelo);
   	    fflush(stdin);
   	    printf("Matrícula(0000AAA): ");
	    scanf("%s", mat);
   	    clie.coche.matricula = (char*)malloc((strlen(mat)+1)*sizeof(char));
   	    Cambio(mat, clie.coche.matricula);
   	    fflush(stdin);
   	    do{
   	    	printf("Kilómetros: ");
   	    	scanf("%i", &clie.coche.kilometros);
   	    	fflush(stdin);
   	    	if(clie.coche.kilometros < 1 || clie.coche.kilometros > 1000000){
   	    		printf("Introduzca de nuevo los kilómetros\n");
			}
		}
   	    while(clie.coche.kilometros < 1 || clie.coche.kilometros > 1000000);
	    
	    
	    fprintf(vehiculos, "%s,coche %i,%s,%s,%s,%i\n", clie.nombre, i, clie.coche.marca, clie.coche.modelo, clie.coche.matricula, clie.coche.kilometros);
	}	
	
	fprintf(clientes, "%s,%s,%c,%i/%i/%i,%s\n", clie.nombre, clie.nom_usuario, clie.sexo, clie.nacimiento.dia, clie.nacimiento.mes, clie.nacimiento.ano, clie.contrasena);
	
	printf("¡Cliente registrado con éxito!");
	
	fclose(clientes);
	fclose(vehiculos);
	
	return 1;
}

void Cambio(char antes[], char *despues){//Función de asignación dinámica de memoria para cadenas de caracteres que van dentro de estructuras
	int i;
	if (despues == NULL) { 
	    printf("Error: memoria no disponible.\n");
	    exit(-1); 
    }
	for(i = 0; antes[i] != '\0'; i++){
		*(despues+i) = antes[i];
	}
}

void Vaciar(char cadena[]){
	int i;
	for(i = 0; cadena[i] != '\0'; i++)
    	cadena[i] = '\0';
}
