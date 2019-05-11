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
int IniciarSesion(char *nom_us);
int CrearEmpleado();
int CrearCliente();
void CrearCita();
void CrearVehiculo();
void MenuEmpleado();
void MenuCliente();
void Cambio(char antes[], char *despues);
void Vaciar(char cadena[]);

void main(){
	system("chcp 1252");//Código para que se puedan imprimir caracteres especiales, como letras con tildes y ñ
    system("COLOR F0");//Código para cambiar el color del fondo (1er dígito) y de las letras (2o digito) (0 = Negro, 1 = Azul, 2 = Verde, 3 = Aqua, 4 = Rojo, 5 = Púrpura, 6 = Amarillo, 7 = Blanco, 8 =Gris, 9 = Azul Claro, A = Luz Verde, B = Aqua Luz, C = Rojo, D = Luz Violeta, E = = Amarillo Claro, F = Blanco Brillante)

	int opcion1;
	char *nom_us;
	
	do{
	    opcion1 = MenuAcceso();
	    
	    if(opcion1 == 1){
	    	MenuEmpleado();
		}
		else if(opcion1 == 2){
			MenuCliente();
		}
	}
	while(opcion1 != 0);

}

int MenuAcceso(char *nom_us){
	system("chcp 1252");
	int opcion, opcion1 = 2;
	do{
		system("cls");//Código para limpiar pantalla
		printf("DATACOCHES\n\n");
	    printf("¿Qué desea hacer?\n\n");
	    
        printf("TECLA   ACCIÓN\n  1-    Iniciar sesión.\n  0-    Salir del programa.\n\n   OPCIÓN: ");
        scanf("%i", &opcion);
	    fflush(stdin);
        
		switch(opcion){
    	    case 1: opcion1 = IniciarSesion(nom_us); break;
    	    case 0: opcion1 = 0; printf("\nGracias por usar nuestro programa."); break;
    	    default: printf("\nTecla no reconocida.\n"); break;
    	}
	}
    while(opcion != 0 && opcion != 1);
    
	return opcion1;
}

void MenuEmpleado(){
	system("chcp 1252");
	system("cls");
	int opcion;
    printf("DATACOCHES\n\n");
	printf("¿Qué desea hacer?\n\n");
	
	do{
	    printf("TECLA   ACCIÓN\n  1-    Consultar datos sobre un vehículo.\n  2-    Consultar estado de un vehículo.\n  " 
		"3-    Consultar calendario.\n  4-    Generar nueva cita.\n  5-    Crear nuevo empleado.\n  6-    Crear nuevo cliente.\n"
		"  7-    Crear nuevo vehículo.\n  0-    Volver.\n\n   OPCIÓN: ");
	    scanf("%i" ,&opcion);
	    fflush(stdin);
	    printf("\n\n");
	    switch(opcion)
	    {
	    	case 1:
	    		printf("CONSULTA DE DATOS\n");
	    		break;
	    	case 2:
	    		printf("CONSULTA DE ESTADO\n");
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
		    case 7:
		    	printf("NUEVO VEHÍCULO\n\n");
		    	CrearVehiculo();
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

void MenuCliente(){
	system("chcp 1252");
	system("cls");
	int opcion;
    printf("DATACOCHES\n\n");
	printf("¿Qué desea hacer?\n\n");
	
	do{
	    printf("TECLA   ACCIÓN\n  1-    Consultar estado de un vehículo.\n  2-    Consultar calendario.\n"
		"  3-    Generar nueva cita.\n  0-    Volver,\n\n   OPCIÓN: ");
	    scanf("%i" ,&opcion);
	    fflush(stdin);
	    printf("\n\n");
	    switch(opcion)
	    {
	    	case 1:
	    		printf("CONSULTA DE ESTADO\nIntroduzca la matrícula del vehículo:");
	    		break;
	    	case 2:
		    	printf("CALENDARIO\n\n");
		    	break;
	    	case 3:
		    	printf("NUEVA CITA\n\n");
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

int IniciarSesion(char *nom_us){
	system("chcp 1252");
	system("cls");
	
	int i = 0, j = 0, k = 3, aux, opcion1, e = 0, c = 0;
	char usuario[N], cont[N], auxc[N], adv;
	Empleado emp[10];
	Cliente clie[30];
	FILE *empleados;
	FILE *clientes;
	
	empleados = fopen("empleados.txt", "r");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(empleados)){
		fscanf(empleados, "%[^,]s", auxc);
	   	emp[e].nombre = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].nombre);
    	Vaciar(auxc);//Para volver a dejar la cadena 'aux' vacía
	   	adv = fgetc(empleados);//Para avanzar una posición en el fichero
	    	
    	fscanf(empleados, "%[^,]s", auxc);
	   	emp[e].ocupacion = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].ocupacion);
	   	Vaciar(auxc);
	   	adv = fgetc(empleados);
	    	
    	fscanf(empleados, "%[^\n]s", auxc);
	   	emp[e].contrasena = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].contrasena);
	   	Vaciar(auxc);
	   	adv = fgetc(empleados);
		
		e++;//Contador para saber el número de empleados
	}
	fclose(empleados);
	
	clientes = fopen("clientes.txt", "r");
	if (clientes == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(clientes)){
		fscanf(clientes, "%[^;]s", auxc);
	   	clie[c].nombre = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].nombre);
    	Vaciar(auxc);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^;]s", auxc);
	   	clie[c].nom_usuario = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].nom_usuario);
	   	Vaciar(auxc);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%c", &clie[c].sexo);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.dia);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.mes);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.ano);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^\n]s", auxc);
	   	clie[c].contrasena = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].contrasena);
	   	Vaciar(auxc);
	   	adv = fgetc(clientes);
		
		c++;//Contador para saber el número de clientes
	}
	fclose(clientes);
	
	printf("DATACOCHES\n\n");
	printf("INICIAR SESIÓN\n\n");
	
	do{
		aux = 0;
		printf ("Usuario: ");
    	scanf("%30s", usuario);
    	fflush(stdin);
    	while(i < e && aux == 0){
    		if(strcmp(emp[i].nombre, usuario) == 0){
    			aux = 1;
	    	}
	    	i++;
    	}
    	while(j < c && aux == 0){
    		if(strcmp(clie[j].nom_usuario, usuario) == 0){
    			aux = 2;
			}
			j++;
		}
		if(aux == 1){
			i--;
			do{
    	        printf("Contraseña: ");
        	    scanf("%30s", cont);
        	    fflush(stdin);
   		    	if(strcmp(emp[i].contrasena, cont) == 0){
	        		aux = 3;
	   			    opcion1 = 1;
	            	nom_us = (char*)malloc((strlen(usuario)+1)*sizeof(char));
	            	Cambio(usuario, nom_us);
    	    		printf("\n¡BIENVENIDO!\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("Gracias por usar el programa.");
	   		    		exit(1);
					}
					else
	   		        	printf("\nContraseña incorrecta\nQuedan %i intentos\n\n", k);
	   		    }
	   	    }
	   	    while(aux == 1);
		}
		if(aux == 2){
			j--;
			do{
    	        printf("Contraseña: ");
        	    scanf("%30s", cont);
        	    fflush(stdin);
   		    	if(strcmp(clie[j].contrasena, cont) == 0){
	        		aux = 3;
	   			    opcion1 = 2;
	            	nom_us = (char*)malloc((strlen(usuario)+1)*sizeof(char));
	            	Cambio(usuario, nom_us);
    	    		printf("\n¡BIENVENIDO!\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("Gracias por usar el programa.");
	   		    		exit(1);
					}
					else
	   		        	printf("\nContraseña incorrecta\nQuedan %i intentos\n\n", k);
	   		    }
	   	    }
	   	    while(aux == 2);
		}
    	else if(aux == 0){
			printf("Usuario no definido\n\n");
			Vaciar(usuario);
			i = 0;
			j = 0;
		}
	}
	while(aux == 0);
	system("pause");
	return opcion1;
}

void CrearCita(){	
	system("chcp 1252");
	system("cls");
	
	FILE *citas;
	Cita cita;
	int aux1, aux2;
	char nom[N], res;
	
	citas = fopen("citas.txt", "a");
	if (citas == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	
	do{
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
		    printf("Hora(hh:mm): ");
		    scanf("%i%i", &cita.hora, &cita.min);
		    if(cita.hora < 9 || cita.hora > 19 || cita.hora == 14){
			    printf("Introduzca la hora de nuevo\n");
			    aux2 = 1;
		    }
		    if (cita.min != 0 && cita.min != 10 && cita.min != 20 && cita.min != 30 && cita.min != 40 && cita.min != 50){
			    printf("Los minutos indicados sólo pueden ser 00, 10, 20, 30, 40 y 50\n");
			    aux2 = 1;
		    }
		    fflush(stdin);
	    }
	    while(aux2 == 1);
	    if(cita.min == 0){
		    printf("\nLe confirmamos su cita: \nNOMBRE: %s HORA: %i:%i%i DÍA: %i/%i", cita.nombre, cita.hora, cita.min, cita.min, cita.dia, cita.mes);
    	}
	    else{
	    	printf("\nLe confirmamos su cita: \nNOMBRE: %s HORA: %i:%i DÍA: %i/%i", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
    	}
	    
	    printf("¿Está de acuerdo?(Si = s / No = n): ");
       	scanf("%c", &res);
	    if(res == 'n' || res == 'N'){
        	system("cls");
			Vaciar(nom);
		}
	}
	while(res == 'n' || res == 'N');
	
	fprintf(citas, "%s,%i:%i,%i/%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
		
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
        	printf("Nombre de usuario: ");
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
	    scanf("%[^\n]s", mar);
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
	    
	    
	    fprintf(vehiculos, "%s,%s,%s,%s,%i\n", clie.nombre, clie.coche.marca, clie.coche.modelo, clie.coche.matricula, clie.coche.kilometros);
	}	
	
	fprintf(clientes, "%s,%s,%c,%i/%i/%i,%s\n", clie.nombre, clie.nom_usuario, clie.sexo, clie.nacimiento.dia, clie.nacimiento.mes, clie.nacimiento.ano, clie.contrasena);
	
	printf("¡Cliente registrado con éxito!");
	
	fclose(clientes);
	fclose(vehiculos);
	
	return 1;
}

void CrearVehiculo(){
	system("chcp 1252");
	system("cls");
	
	FILE *vehiculos;
	Vehiculo coche;
	char nom[N], mar[N], mod[N], mat[N], *nombre, res;
	
	vehiculos = fopen("vehiculos.txt", "a");
	
	if(vehiculos == NULL){
		printf("Error al abrir el fichero.\n");
		exit(1);
	}
	
	do{
		printf("DATACOCHES\n\n");
	    printf("NUEVO VEHÍCULO\n\n");
	    
	    printf("Nombre completo: ");
	    scanf("%[^\n]s", nom);
        nombre = (char*)malloc((strlen(nom)+1)*sizeof(char));
	    Cambio(nom, nombre);
	    fflush(stdin);
    	printf("Marca: ");
    	scanf("%[^\n]s", mar);
        coche.marca = (char*)malloc((strlen(mar)+1)*sizeof(char));
       	Cambio(mar, coche.marca);
       	fflush(stdin);
    	printf("Modelo: ");
    	scanf("%[^\n]s", mod);
   	    coche.modelo = (char*)malloc((strlen(mod)+1)*sizeof(char));
   	    Cambio(mod, coche.modelo);
   	    fflush(stdin);
   	    printf("Matrícula(0000AAA): ");
    	scanf("%s", mat);
       	coche.matricula = (char*)malloc((strlen(mat)+1)*sizeof(char));
       	Cambio(mat, coche.matricula);
       	fflush(stdin);
       	do{
       	   	printf("Kilómetros: ");
       	   	scanf("%i", &coche.kilometros);
   	       	fflush(stdin);
       	   	if(coche.kilometros < 1 || coche.kilometros > 1000000){
           		printf("Introduzca de nuevo los kilómetros\n");
    		}
	    }
   	    while(coche.kilometros < 1 || coche.kilometros > 1000000);
   	    printf("\nLe confirmamos los datos del vehículo:\n PROPIETARIO: %s MARCA: %s MODELO: %s MATRÍCULA: %s KILÓMETROS: %i\n", nombre, coche.marca, coche.modelo, coche.matricula, coche.kilometros);
   	    printf("¿Está de acuerdo?(Si = s / No = n): ");
       	scanf("%c", &res);
       	fflush(stdin);
       	if(res == 'n' || res == 'N'){
        	system("cls");
			Vaciar(nom);
			Vaciar(mar);
			Vaciar(mod);
			Vaciar(mat);
		}
    }
   	while(res == 'n' || res == 'N');
   	
   	fprintf(vehiculos,"%s,%s,%s,%s,%i\n", nombre, coche.marca, coche.modelo, coche.matricula, coche.kilometros);
   	
   	printf("\n\n¡Vehículo registrado con éxito!\n");
   	
   	fclose(vehiculos);
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
	for(i = 0; i < N; i++)
    	cadena[i] = '\0';
}
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

int main(){
	system("chcp 1252");
	system("cls");
	
	int i = 0, j = 0, k = 3, aux, opcion1, e = 0, c = 0;
	char usuario[N], cont[N], auxc[N], adv;
	Empleado emp[10];
	Cliente clie[30];
	FILE *empleados;
	FILE *clientes;
	
	empleados = fopen("empleados.txt", "r");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(empleados)){
		fscanf(empleados, "%[^,]s", auxc);
	   	emp[e].nombre = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].nombre);
    	Vaciar(auxc);//Para volver a dejar la cadena 'aux' vacía
	   	adv = fgetc(empleados);//Para avanzar una posición en el fichero
	    	
    	fscanf(empleados, "%[^,]s", auxc);
	   	emp[e].ocupacion = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].ocupacion);
	   	Vaciar(auxc);
	   	adv = fgetc(empleados);
	    	
    	fscanf(empleados, "%[^\n]s", auxc);
	   	emp[e].contrasena = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, emp[e].contrasena);
	   	Vaciar(auxc);
	   	adv = fgetc(empleados);
		
		e++;//Contador para saber el número de empleados
	}
	fclose(empleados);
	
	clientes = fopen("clientes.txt", "r");
	if (clientes == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(clientes)){
		fscanf(clientes, "%[^;]s", auxc);
	   	clie[c].nombre = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].nombre);
    	Vaciar(auxc);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^;]s", auxc);
	   	clie[c].nom_usuario = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].nom_usuario);
	   	Vaciar(auxc);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%c", &clie[c].sexo);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.dia);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.mes);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[c].nacimiento.ano);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^\n]s", auxc);
	   	clie[c].contrasena = (char*)malloc((strlen(auxc)+1)*sizeof(char));
	   	Cambio(auxc, clie[c].contrasena);
	   	Vaciar(auxc);
	   	adv = fgetc(clientes);
		
		c++;//Contador para saber el número de clientes
	}
	fclose(clientes);
	
	printf("%s;\n%s;\n%c;\n%i/%i/%i;\n%s", clie[0].nombre, clie[0].nom_usuario, clie[0].sexo, clie[0].nacimiento.dia, clie[0].nacimiento.mes, clie[0].nacimiento.ano, clie[0].contrasena);
	
	
	printf("DATACOCHES\n\n");
	printf("INICIAR SESIÓN\n\n");
	
	do{
		aux = 0;
		printf ("Usuario: ");
    	scanf("%30s", usuario);
    	fflush(stdin);
    	while(i < e && aux == 1){
    		if(strcmp(emp[i].nombre, usuario) == 0){
    			aux = 1;
	    	}
	    	i++;
    	}
    	while(j < c && aux == 1){
    		if(strcmp(clie[j].nom_usuario, usuario) == 0){
    			aux = 2;
			}
			j++;
		}
		if(aux == 1){
			i--;
			do{
    	        printf("Contraseña: ");
        	    scanf("%30s", cont);
        	    fflush(stdin);
   		    	if(strcmp(emp[i].contrasena, cont) == 0){
	        		aux = 3;
	   			    opcion1 = 1;
    	    		printf("\n¡BIENVENIDO!\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("Gracias por usar el programa.");
	   		    		exit(1);
					}
					else
	   		        	printf("Contraseña incorrecta\nQuedan %i intentos\n", k);
	   		    }
	   	    }
	   	    while(aux == 1);
		}
		if(aux == 2){
			j--;
			do{
    	        printf("Contraseña: ");
        	    scanf("%30s", cont);
        	    fflush(stdin);
   		    	if(strcmp(clie[j].contrasena, cont) == 0){
	        		aux = 3;
	   			    opcion1 = 2;
    	    		printf("\n¡BIENVENIDO!\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("Gracias por usar el programa.");
	   		    		exit(1);
					}
					else
	   		        	printf("Contraseña incorrecta\nQuedan %i intentos\n", k);
	   		    }
	   	    }
	   	    while(aux == 2);
		}
    	else{
			printf("Usuario no definido\n\n");
			Vaciar(usuario);
			i = 0;
			j = 0;
		}
	}
	while(aux == 0);
	system("pause");
	return opcion1;
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
