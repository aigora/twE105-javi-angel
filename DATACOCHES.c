//DATACOCHES

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 30
#define M 50

typedef struct{
	int dia;
	int mes;
	int ano;
}Fecha;

typedef struct{
	char nombre[N];
	int dia;
	int mes;
	int hora;
	int min;
}Cita;

typedef struct{
	char marca[N];
	char modelo[N];
	char matricula[N];
	int kilometros;
}Vehiculo;

typedef struct {
	char nombre[N];
	Fecha nacimiento;
	char sexo;
	char nom_usuario[N];
	char contrasena[N];
	Vehiculo coche;
}Cliente;
 
typedef struct{
 	char nombre[N];
 	char contrasena[N];
 	char ocupacion[N];
}Empleado;

int MenuAcceso(char *user);
int IniciarSesion(char *user);
void CrearEmpleado();
void CrearCliente();
void CrearCita(int x, char *user);
void CrearVehiculo();
void MenuEmpleado(char *user);
void MenuCliente(char *user);
void ConsultarDatosVehiculo();
void ConsultarCita(char *user);
void Mes(int mes, int d); 
void Calendario();
void Vaciar(char cadena[]);

void main(){
	system("chcp 1252");//Código para que se puedan imprimir caracteres especiales, como letras con tildes y ñ
    system("COLOR F0");//Código para cambiar el color del fondo (1er dígito) y de las letras (2o digito) (0 = Negro, 1 = Azul, 2 = Verde, 3 = Aqua, 4 = Rojo, 5 = Púrpura, 6 = Amarillo, 7 = Blanco, 8 =Gris, 9 = Azul Claro, A = Luz Verde, B = Aqua Luz, C = Rojo, D = Luz Violeta, E = = Amarillo Claro, F = Blanco Brillante)
	system("cls");
    
    
	int i, opcion1;
	char user[N];
	
	printf(	"                                                                                                                        "
			"                                                                                                                        "
			"                                                                                                                        "
			"                                                       .....-------::::::-.                                             "
			"                                                ....-:--..----.........````............                                 "
			"                                          .......--..`               ``---.....`      ``........                        "
			"                                      ..-.``.--``                       `-. ``.---...         ```.---...                "
			"                          .......`` .-`` .-.`                           `.-:......---:-..........-----:-:-----..-`      "
			"                   ......``````````.-...-.            ````.`............````:````                         `:--.-/`      "
			"              .-::..`                 `--..............````````             `:                              `.-:/       "
			"           .-.``..--   .-::::-..`      :                                     -`             ``.......``         /       "
			"        .:-.....``` `.-..`   ```.-`    :                                    `:            `-.``      `.-`      `:       "
			"      .-.````      .-`            .-   -`                                  .-            .-`            -.     :`       "
			"     `:``         `:               -.  `:                                `-.            `:               -`   -.        "
			"      /.:         :`                :   :                             `.-.              :`               `:  .-         "
			"      `::         :`                :   `-`````````````````````````....`                :`               `:`-.          "
			"       .:         `:               :`    ``````````````````````````                     `:               /--`           "
			"        ..........`.-`           `:-`.....................................................-`           `--`             "
			"                     .-.``   ``.--`````````````````````````````````````````````````````    .-```   ``.-.                "
			"      -----------------:::::::::------------------------------------------------------------::::::::::---------------   "
			"                .ydyy.      yo    -dshhyh`    ss      -ysss`   :yy+     .ysss.  y-   y-  yhssss-  +hsssy. ®             "
			"                 .M./m.    /NN.   `/ ho`/    :NN-    :m-      :m:.d+   .m/      m/   N/  do       :d+` :.               "
			"                 .M. sh   `N/yy      ho      m+od    N/       m+  .M.  do       mhsssN/  ddso      `sh-                 "
			"                 .M.-m:   sNsyM:     ho     +MsyM/   od`      +d.`yy   /m-      m/```N/  do`      `` -do`               "
			"                .yMyd:   .N-``+h     yo    `m:``/m    +dsss`   +dhy     :dsss.  d/   m/  ddssss-  odsssN/               "
			"                 ```      `    `     `      `    `      ```     ``        ```   `    `   ``````    `````                \n\n\n\n\n");
	
	system("pause");
	
	do{
	    opcion1 = MenuAcceso(user);
	    if(opcion1 == 1){
	    	MenuEmpleado(user);
		}
		else if(opcion1 == 2){
			MenuCliente(user);
		}
	}
	while(opcion1 != 0);

}

int MenuAcceso(char *user){
	system("chcp 1252");
	int opcion, opcion1;
	do{
		system("cls");//Código para limpiar pantalla
		printf("DATACOCHES\n\n");
	    printf("¿Qué desea hacer?\n\n");
	    
        printf("TECLA   ACCIÓN\n  1-    Iniciar sesión.\n  0-    Salir del programa.\n\n   OPCIÓN: ");
        scanf("%i", &opcion);
	    fflush(stdin);
        
		switch(opcion){
    	    case 1: 
			    opcion1 = IniciarSesion(user); 
				break;
    	    case 0: 
			    opcion1 = 0; 
				printf("\nGracias por usar el programa."); 
				break;
    	    default: 
			    printf("\nTecla no reconocida.\n\n"); 
				system("pause"); 
				break;
    	}
	}
    while(opcion != 0 && opcion != 1);
    
	return opcion1;
}

void MenuEmpleado(char *user){
	system("chcp 1252");
	int x = 0;
	char opcion;
	
	do{
    	system("cls");
        printf("DATACOCHES\n\n");
        printf("Logueado como %s\n\n", user);
    	printf("¿Qué desea hacer?\n\n");
    	
	    printf("TECLA   ACCIÓN\n  1-    Consultar datos sobre un vehículo.\n  2-    Consultar estado de un vehículo.\n  " 
		"3-    Consultar calendario.\n  4-    Generar nueva cita.\n  5-    Crear nuevo empleado.\n  6-    Crear nuevo cliente.\n"
		"  7-    Crear nuevo vehículo.\n  8-    Modificar estado de un vehículo.\n  9-    Añadir proceso.\n  0-    Volver.\n\n   OPCIÓN: ");
	    scanf("%c" ,&opcion);
	    fflush(stdin);
	    printf("\n");
	    switch(opcion)
	    {
	    	case '1':
                ConsultarDatosVehiculo();
	    		break;
	    	case '2':
	    		printf("CONSULTA DE ESTADO\n");
		    	break;
	    	case '3':
		    	Calendario();
			    break;
	    	case '4':
		    	CrearCita(x, user);
			    break;
    		case '5':
	    		CrearEmpleado();
		    	break;
		    case '6':
	    		CrearCliente();
		    	break;
		    case '7':
		    	CrearVehiculo();
		    	break;
		    case '8':
		    	printf("MODIFICAR ESTADO\n");
		    	break;
		    case 9:
		    	printf("AÑADIR PROCESO\n");
		    case '0':
		    	printf("¡Sesión cerrada!\n\n");
		    	break;
    		default:
	    		printf("Tecla no reconocida.\n\n");
		    	break;	
    	}
    	
	    system("pause");
	}
	while (opcion != '0');
}

void MenuCliente(char *user){
	system("chcp 1252");
	int opcion, x = 0;
	
	do{
    	system("cls");
        printf("DATACOCHES\n\n");
        printf("Cliente: %s\n\n", user);
    	printf("¿Qué desea hacer?\n\n");
		
	    printf("TECLA   ACCIÓN\n  1-    Consultar estado de un vehículo.\n  2-    Consultar citas.\n"
		"  3-    Generar nueva cita.\n  4-    Listado de precios.\n  0-    Volver.\n\n   OPCIÓN: ");
	    scanf("%i", &opcion);
	    fflush(stdin);
	    printf("\n");
	    switch(opcion)
	    {
	    	case 1:
	    		printf("CONSULTA DE ESTADO\nIntroduzca la matrícula del vehículo:");
	    		break;
	    	case 2:
		    	ConsultarCita(user);
		    	break;
	    	case 3:
		    	CrearCita(x, user);
			    break;
			case 4:
				printf("LISTADO DE PRECIOS\n");
			case 0:
		    	printf("¡Sesión cerrada!\n\n");
				break;
    		default:
	    		printf("Tecla no reconocida.\n\n");
		    	break;	
    	}
	    system("pause");
	}
	while (opcion != 0);
}

int IniciarSesion(char *user){
	system("chcp 1252");
	
	int i, j, k = 4, aux, opcion1, e = 0, c = 0;
	char usuario[N], cont[N], adv, basura[80];
	Empleado emp[10];
	Cliente clie[M];
	FILE *empleados;
	FILE *clientes;
	
	empleados = fopen("empleados.txt", "r");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(empleados)){
		fscanf(empleados, "%[^\n]s", basura);
		adv = fgetc(empleados);
		e++;//Contador para saber el número de empleados
	}
	fseek(empleados, 0, SEEK_SET);
	for(i = 0; i < e; i++){
		fscanf(empleados, "%[^,]s", emp[i].nombre);
	   	adv = fgetc(empleados);//Para avanzar una posición en el fichero
	    	
    	fscanf(empleados, "%[^,]s", emp[i].ocupacion);
	   	adv = fgetc(empleados);
	    	
    	fscanf(empleados, "%[^\n]s", emp[i].contrasena);
	   	adv = fgetc(empleados);
	}
	fclose(empleados);
	
	clientes = fopen("clientes.txt", "r");
	if (clientes == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	while(!feof(clientes)){
		fscanf(clientes, "%[^\n]s", basura);
		adv = fgetc(clientes);
		c++;//Contador para saber el número de clientes
	}
	c--;//El bucle cuenta una vez de más, por eso restamos 1 al contador
	fseek(clientes, 0, SEEK_SET);
	for(i = 0; i < c; i++){
		fscanf(clientes, "%[^,]s", clie[i].nombre);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^,]s", clie[i].nom_usuario);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%c", &clie[i].sexo);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[i].nacimiento.dia);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[i].nacimiento.mes);
	   	adv = fgetc(clientes);
	   	
	   	fscanf(clientes, "%i", &clie[i].nacimiento.ano);
	   	adv = fgetc(clientes);
	    	
    	fscanf(clientes, "%[^\n]s", clie[i].contrasena);
	   	adv = fgetc(clientes);
	}
	fclose(clientes);
	
	do{
	    system("cls");
		printf("DATACOCHES\n\n");
	    printf("INICIAR SESIÓN\n\n");
	    
		aux = 0;
		printf ("Usuario: ");
    	scanf("%30s", usuario);
    	fflush(stdin);
    	for(i = 0; i < e && aux == 0; i++){
    		if(strcmp(emp[i].nombre, usuario) == 0){
    			aux = 1;
	    	}
    	}
    	for(j = 0; j < c && aux == 0; j++){
    		if(strcmp(clie[j].nom_usuario, usuario) == 0){
    			aux = 2;
			}
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
	            	strcpy(user, emp[i].nombre);
    	    		printf("\n¡BIENVENIDO!\n\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("\nGracias por usar el programa.");
	   		    		exit(1);
					}
					else if(k == 1){
						printf("\nContraseña incorrecta.\nQueda %i intento\n\n", k);
					}
	   		        else{
	   		        	printf("\nContraseña incorrecta.\nQuedan %i intentos\n\n", k);
					}
	   		    }
	   	    }
	   	    while(aux == 1);
		}
		else if(aux == 2){
			j--;
			do{
    	        printf("Contraseña: ");
        	    scanf("%30s", cont);
        	    fflush(stdin);
   		    	if(strcmp(clie[j].contrasena, cont) == 0){
	        		aux = 3;
	   			    opcion1 = 2;
	            	strcpy(user, clie[j].nombre);
    	    		printf("\n¡BIENVENIDO!\n\n");
	        	}
	        	else{
	        		Vaciar(cont);
					k--;//Contador de intentos
	   		    	if(k == 0){
	   		    		printf("\nGracias por usar el programa.");
	   		    		exit(1);
					}
					else if(k == 1){
						printf("\nContraseña incorrecta\nQueda %i intento\n\n", k);
					}
					else{
						printf("\nContraseña incorrecta\nQuedan %i intentos\n\n", k);
					}
	   		        	
	   		    }
	   	    }
	   	    while(aux == 2);
		}
    	else if(aux == 0){
			printf("Usuario no definido\n\n");
			system("pause");
			Vaciar(usuario);
			i = 0;
			j = 0;
		}
	}
	while(aux == 0);
	system("pause");
	return opcion1;
}

void CrearCita(int x, char *user){	
	system("chcp 1252");
	
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
    	system("cls");
		printf("DATACOCHES\n\n");
	    printf("NUEVA CITA\n\n");
	    if(x == 0){
	    	printf("Nombre completo: ");
	        scanf("%[^\n]s", cita.nombre);
	        fflush(stdin);
		}
    	else{
    		strcpy(cita.nombre, user);
		}
	    do{
	    	printf("Mes(nº): ");
		    scanf("%i", &cita.mes);
    		if(cita.mes < 1 || cita.mes > 12){
	    		printf("\nIntroduzca el mes de nuevo.\n\n");
		    }
    		fflush(stdin);
	    }
	    while(cita.mes < 1 || cita.mes > 12);
	    do{
		    aux1 = 0;
		    printf("Día: ");
		    scanf("%i", &cita.dia);
		    if((cita.mes == 1 || cita.mes == 3 || cita.mes == 5 || cita.mes == 7 || cita.mes == 8 || cita.mes == 10 || cita.mes == 12) && (cita.dia < 1 || cita.dia > 31)){
			    printf("\nIntroduzca el día de nuevo.\n\n");
			    aux1 = 1;
		    }
		    else if(cita.mes == 2 && (cita.dia < 1 || cita.dia > 28)){
			    printf("\nIntroduzca el día de nuevo.\n\n");
			    aux1 = 1;
		    }
		    else if((cita.mes == 4 || cita.mes == 6 || cita.mes == 9 || cita.mes == 11) && (cita.dia < 1 || cita.dia > 30)){
			    printf("\nIntroduzca el día de nuevo.\n\n");
			    aux1 = 1;
		    }
		    fflush(stdin);
	    }
	    while(aux1 == 1);
	    do{
		    aux2 = 0;
		    printf("Hora(hh mm): ");
		    scanf("%i%i", &cita.hora, &cita.min);
		    if(cita.hora < 9 || cita.hora > 19){
			    printf("\nIntroduzca la hora de nuevo.\n\n");
			    aux2 = 1;
		    }
		    if (cita.min != 0 && cita.min != 10 && cita.min != 20 && cita.min != 30 && cita.min != 40 && cita.min != 50){
			    printf("\nLos minutos indicados sólo pueden ser 00, 10, 20, 30, 40 y 50.\n\n");
			    aux2 = 1;
		    }
		    fflush(stdin);
	    }
	    while(aux2 == 1);
	    if(cita.min == 0){
		    printf("\nLe confirmamos su cita: \nNOMBRE: %s \nHORA: %i:%i%i \nDÍA: %i/%i\n", cita.nombre, cita.hora, cita.min, cita.min, cita.dia, cita.mes);
    	}
	    else{
	    	printf("\nLe confirmamos su cita: \nNOMBRE: %s \nHORA: %i:%i \nDÍA: %i/%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
    	}
	    
	    printf("\n¿Está de acuerdo?(Si = s / No = n): ");
       	scanf("%c", &res);
       	fflush(stdin);
       	do{
		    if(res == 'n' || res == 'N'){
	        	system("cls");
				Vaciar(nom);
			}
			else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
				printf("\nTecla no reconocida.\n\n");
			}
		}
		while(res != 'n' && res != 'N' && res != 's' && res != 'S');
	}
	while(res != 's' || res != 's');
	
	printf("\n¡Cita confirmada!\n\n");
	
	fprintf(citas, "%s,%i:%i,%i/%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
		
	fclose(citas);
}

void CrearEmpleado(){
	system("chcp 1252");
	system("cls");
	
	FILE *empleados;
	int i = 4, contrasena;
	char nom[N], ocup[N], cont[N];
	
	empleados = fopen("empleados.txt", "a");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	printf("DATACOCHES\n\n");
	printf("NUEVO EMPLEADO\n");
	
	while(i > 0){
		printf("Contraseña de administrador: ");
		scanf("%i", &contrasena);
		fflush(stdin);
		if(contrasena == 1111){
        	printf("Nombre de usuario: ");
			scanf("%s", nom);
			fflush(stdin);
			printf("Ocupación: ");
			scanf("%s", ocup);
			fflush(stdin);
			printf("Contraseña: ");
			scanf("%s", cont);
			fflush(stdin);
        	
			fprintf(empleados, "%s,%s,%s\n", nom, ocup, cont);
			
			printf("\n¡Empleado registrado correctamente!\n\n");
			
			i = 3;//Ruta de escape
		}
		else{
			i--;
			if(i == 0)
        	printf("\nConsulte con el administrador.\n\n");
			else if(i == 1)
			printf("\nContraseña incorrecta.\nQueda %i intento\n\n", i);
			else
			printf("\nContraseña incorrecta.\nQuedan %i intentos\n\n", i);
		}
	}
	fclose(empleados);
}

void CrearCliente(){//Mismo funcionamiento que NuevoEmpleado()
	system("chcp 1252");
	system("cls");
	
	FILE *clientes, *vehiculos;
	int i, dia, mes, ano, coches, kms;
	char nom[N], us[N], cont[N], mar[N], mod[N], mat[N], sexo, res;//Usuario = us, Marca = mar
	
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
	
	do{
		printf("DATACOCHES\n\n");
	    printf("NUEVO CLIENTE\n\n");
	    
	    printf("Nombre completo: ");
		scanf("%[^\n]s", nom);
		fflush(stdin);
		printf("Nombre de usuario: ");
		scanf("%[^\n]s", us);
		fflush(stdin);
		do{
			printf("Sexo (Masculino 'M' o Femenino 'F' u Otro 'O'): ");
	    	scanf("%c", &sexo);
	    	fflush(stdin);
	    	if(sexo != 'M' && sexo != 'F' && sexo != 'O'){
	    		printf("\nIntroduzca de nuevo el sexo.\n\n");
			}
		}
		while(sexo != 'M' && sexo != 'F' && sexo != 'O');
		do{
			printf("Fecha de nacimiento(día mes año): ");
			scanf("%i %i %i", &dia, &mes, &ano);
	    	fflush(stdin);
	    	if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) || (mes == 2 && (dia < 1 || dia > 28)) 
			|| ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) || (mes < 1 || mes > 12 || ano < 1900 || ano > 2001)){
	    		printf("\nIntroduzca de nuevo la fecha.\n\n");
			}
		}
		while(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) || (mes == 2 && (dia < 1 || dia > 28)) 
		|| ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) || (mes < 1 || mes > 12 || ano < 1900 || ano > 2001));
		printf("Contraseña: ");
		scanf("%s", cont);
	   	fflush(stdin);
		
		printf("\nLe confirmamos sus datos: \n\nNOMBRE: %s \nUSUARIO: %s \nSEXO: %c\nFECHA DE NACIMIENTO: %i/%i/%i\nCONTRASEÑA: %s\n", nom, us, sexo, dia, mes, ano, cont);
	    
	    do{
		    printf("\n¿Está de acuerdo?(Si = s / No = n): ");
	       	scanf("%c", &res);
	       	fflush(stdin);
		    if(res == 'n' || res == 'N'){
	        	system("cls");
				Vaciar(nom);
				Vaciar(us);
				Vaciar(cont);
			}
			else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
				printf("\nTecla no reconocida.\n\n");
			}
	    }
	    while(res != 'n' && res != 'N' && res != 's' && res != 'S');
	}
	while(res != 's' || res != 's');
		
	do{
	   	printf("Número de vehículos: ");
	   	scanf("%i", &coches);
		fflush(stdin);
	   	if(coches < 1){
	   		printf("\nDebe introducir al menos un vehículo\n\n");
		}
	}
	while(coches < 1);
	
	for(i = 1; i <= coches; i++){
		do{
        	system("cls");
        	
	    	printf("DATACOCHES\n\n");
	        printf("NUEVO CLIENTE\n\n");
	    
			printf("\nVEHÍCULO %i\n", i);
		    printf("Marca: ");
		    scanf("%[^\n]s", mar);
	   	    fflush(stdin);
			printf("Modelo: ");
		    scanf("%[^\n]s", mod);
	   	    fflush(stdin);
	   	    printf("Matrícula(0000AAA): ");
		    scanf("%s", mat);
	   	    fflush(stdin);
	   	    do{
	   	    	printf("Kilómetros: ");
	   	    	scanf("%i", &kms);
	   	    	fflush(stdin);
	   	    	if(kms < 1 || kms > 1000000){
	   	    		printf("\nIntroduzca de nuevo los kilómetros.\n\n");
				}
			}
	   	    while(kms < 1 || kms > 1000000);
		    
		    printf("\nLe confirmamos los datos de su vehículo: \n\nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s\nKILÓMETROS: %i\n", mar, mod, mat, kms);
	    
		    do{
				printf("\n¿Está de acuerdo?(Si = s / No = n): ");
		       	scanf("%c", &res);
		       	fflush(stdin);
			    if(res == 'n' || res == 'N'){
					Vaciar(mar);
					Vaciar(mod);
					Vaciar(mat);
				}
				else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
					printf("\nTecla no reconocida.\n\n");
				}
		    }
	        while(res != 'n' && res != 'N' && res != 's' && res != 'S');
		}
		while(res != 's' || res != 's');
		    
		fprintf(vehiculos, "%s,%s,%s,%s,%i\n", nom, mar, mod, mat, kms);
		 
		Vaciar(mar);
		Vaciar(mod);
		Vaciar(mat);
	}	
	
	fprintf(clientes, "%s,%s,%c,%i/%i/%i,%s\n", nom, us, sexo, dia, mes, ano, cont);
	
	printf("\n¡Cliente registrado con éxito!\n\n");
	
	system("pause");
	
	fclose(clientes);
	fclose(vehiculos);
	
}

void CrearVehiculo(){
	system("chcp 1252");
	system("cls");
	
	FILE *vehiculos;
	int kms;
	char nom[N], mar[N], mod[N], mat[N], res;
	
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
	    fflush(stdin);
    	printf("Marca: ");
    	scanf("%[^\n]s", mar);
       	fflush(stdin);
    	printf("Modelo: ");
    	scanf("%[^\n]s", mod);
   	    fflush(stdin);
   	    printf("Matrícula(0000AAA): ");
    	scanf("%s", mat);
       	fflush(stdin);
       	do{
       	   	printf("Kilómetros: ");
       	   	scanf("%i", &kms);
   	       	fflush(stdin);
       	   	if(kms < 1 || kms > 1000000){
           		printf("\nIntroduzca de nuevo los kilómetros.\n\n");
    		}
	    }
   	    while(kms < 1 || kms > 1000000);
   	    printf("\nLe confirmamos los datos del vehículo:\nPROPIETARIO: %s \nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s \nKILÓMETROS: %i\n\n", nom, mar, mod, mat, kms);
   	    printf("\n¿Está de acuerdo?(Si = s / No = n): ");
       	scanf("%c", &res);
       	fflush(stdin);
       	do{
	       	if(res == 'n' || res == 'N'){
	        	system("cls");
				Vaciar(nom);
				Vaciar(mar);
				Vaciar(mod);
				Vaciar(mat);
			}
			else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
				printf("Tecla no reconocida.\n");
			}
		}
		while(res != 'n' && res != 'N' && res != 's' && res != 'S');
    }
   	while(res != 's' || res != 'S');
   	
   	fprintf(vehiculos,"%s,%s,%s,%s,%i\n", nom, mar, mod, mat, kms);
   	
   	printf("\n¡Vehículo registrado con éxito!\n\n");
   	
   	fclose(vehiculos);
   	
   	system("pause");
}

void ConsultarDatosVehiculo(){
    system("chcp 1252");
	
	int i, v = 0, aux, res;
	char nombre[M][N], mat[10], adv, basura[80]; 
	Vehiculo coche[M];
	FILE *vehiculos;
	
	vehiculos = fopen("vehiculos.txt", "r");
	if (vehiculos == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	
	while(!feof(vehiculos)){
		fscanf(vehiculos, "%[^\n]s", basura);
		adv = fgetc(vehiculos);
		v++;//Contador para saber el número de vehículos
	}
	v--;
	fseek(vehiculos, 0, SEEK_SET);//Para volver al inicio de un fichero
	
	for(i = 0; i < v; i++){
		fscanf(vehiculos, "%[^,]s", nombre[i]);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].marca);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].modelo);
    	adv = fgetc(vehiculos);
    	
    	fscanf(vehiculos, "%[^,]s", coche[i].matricula);
    	adv = fgetc(vehiculos);
		
		fscanf(vehiculos, "%i", &coche[i].kilometros);
    	adv = fgetc(vehiculos);
	}
	
	do{
		system("cls");
		printf("DATACOCHES\n\n");
    	printf("CONSULTA DE DATOS DEL VEHÍCULO\n\n");
    	
    	i = 0;
		aux = 0;
		printf("Introduzca matrícula: ");
		scanf("%10s", mat);
		fflush(stdin);
		while(i < v && aux == 0){
    		if(strcmp(mat, coche[i].matricula) == 0){
    			aux = 1;
	    	}
	    	i++;
    	}
    	if(aux == 1){
    		i--;
    		printf("\nPROPIETARIO: %s \nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s \nKILÓMETROS: %i\n\n", nombre[i], coche[i].marca, coche[i].modelo, coche[i].matricula, coche[i].kilometros);
    		aux = 2;
		}
		else if(aux == 0){
			printf("\nVehículo no registrado.\n\n");
			Vaciar(mat);
		}
		
		do{
			printf("¿Qué desea hacer?\n  1-    Consultar otro vehículo.\n  0-    Volver.\n   OPCIÓN: ");
		    scanf("%i", &res);
		    fflush(stdin);
		    if(res != 0 && res != 1){
		        printf("\nTecla no reconocida.\n\n");
		        system("pause");
		    }
		    else{
		    	Vaciar(mat);
			}
		}
		while(res != 0 && res != 1);
		
	}
	while(res != 0);
	
	printf("\n");
}

void ConsultarCita(char *user){
	system("chcp 1252");
	system("cls");
	
	int i, n, aux = 0, x = 1;
	char basura[M], adv, res;
	Cita cita[M];
	FILE *citas;
	
	citas = fopen("citas.txt", "r");
	if(citas == NULL){
		printf("Error al abrir el fichero.\n");
		exit(1);
	}
	while(!feof(citas)){
		fscanf(citas, "%[^\n]s", basura);
		adv = fgetc(citas);
		n++;//Contador para saber el número de citas
    }
	n--;
	fseek(citas, 0, SEEK_SET);
	
	for(i = 0; i < n; i++){
		fscanf(citas, "%[^,]s", cita[i].nombre);
	   	adv = fgetc(citas);
	    	
    	fscanf(citas, "%i", &cita[i].hora);
	   	adv = fgetc(citas);
	    	
    	fscanf(citas, "%i", &cita[i].min);
    	adv = fgetc(citas);
    	
    	fscanf(citas, "%i", &cita[i].dia);
    	adv = fgetc(citas);
		
		fscanf(citas, "%i", &cita[i].mes);
    	adv = fgetc(citas);
	}
	fclose(citas);
	
	printf("DATACOCHES\n\n");
	printf("CONSULTA DE CITAS\n\n");
	
	for(i = 0; i < n && aux == 0; i++){
		if(strcmp(user, cita[i].nombre) == 0){
			aux = 1;
		}
	}

	if(aux == 1){
		if(cita[i].min == 0){
		    printf("Le mostramos los datos de su cita: \nNOMBRE: %s \nDÍA: %i/%i \nHORA: %i:%i%i\n", cita[i].nombre, cita[i].dia, cita[i].mes, cita[i].hora, cita[i].min, cita[i].min);
        }
	    else{
	       	printf("Le mostramos los datos de su cita: \nNOMBRE: %s \nDÍA: %i/%i \nHORA: %i:%i\n", cita[i].nombre, cita[i].dia, cita[i].mes, cita[i].hora, cita[i].min);
       	}
       	printf("Por favor, no olvide traer la documentación de su vehículo.\n");
        printf("\nSi lo desea puede concertar otra cita(Si = s / No = n):");
	}
	else{
		printf("No tiene ninguna cita concertada.\n\nSi lo desea puede concertar una (Si = s / No = n):");
	}
	do{
		scanf("%c", &res);
		fflush(stdin);
		if(res == 's' || res == 'S'){
			CrearCita(x, user);
		}
		else if(res != 's' && res != 'S' && res != 'n' && res != 'N'){
			printf("\nTecla no reconocida.\n\n¿Quiere concertar una cita?(Si = s / No = n):");
		}
		else{
			printf("\nSi en algún otro momento desea concertar una cita, puede hacerlo a través del programa, o bien, llamando al 911 111 111\n\n");
		}
	}
	while(res != 's' && res != 'S' && res != 'n' && res != 'N');
	
	system("pause");
}

void Calendario(){
	system("chcp 1252");
	system("cls");
	
	int mes, dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Días que tiene cada mes
	
	printf("DATACOCHES\n\n");
	printf("CALENDARIO\n\n");
	
	for(mes = 1; mes <= 12; mes++){
		switch(mes)
		{
			case 1: 
			    printf("ENERO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 2: 
			    printf("FEBRERO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 3: 
			    printf("MARZO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 4: 
			    printf("ABRIL\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 5: 
			    printf("MAYO\n");
			    Mes(mes, dias[mes-1]);
			case 6: 
			    printf("JUNIO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 7: 
			    printf("JULIO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 8: 
			    printf("AGOSTO\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 9: 
			    printf("SEPTIEMBRE\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 10: 
			    printf("OCTUBRE\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 11: 
			    printf("NOVIEMBRE\n");
			    Mes(mes, dias[mes-1]);
				break;
			case 12: 
			    printf("DICIEMBRE\n");
			    Mes(mes, dias[mes-1]);
				break;
		}
	}
}

void Mes(int mes, int d){//Para representar los meses en el calendario
	int dia, i, j, k, n = 0, aux;
	char basura[M], adv;//Usamos basura y adv para recorrer el fichero de forma rápida y contar las filas que tiene
	Cita cita[M], citaux;
	FILE *citas;
	
	citas = fopen("citas.txt", "r");
	if(citas == NULL){
		printf("Error al abrir el fichero.\n");
		exit(1);
	}
	while(!feof(citas)){
		fscanf(citas, "%[^\n]s", basura);
		adv = fgetc(citas);
		n++;//Contador para saber el número de citas
    }
	n--;
	fseek(citas, 0, SEEK_SET);
	
	for(i = 0; i < n; i++){//Bucle para extraer datos del fichero
		fscanf(citas, "%[^,]s", cita[i].nombre);
	   	adv = fgetc(citas);
	    	
    	fscanf(citas, "%i", &cita[i].hora);
	   	adv = fgetc(citas);
	    	
    	fscanf(citas, "%i", &cita[i].min);
    	adv = fgetc(citas);
    	
    	fscanf(citas, "%i", &cita[i].dia);
    	adv = fgetc(citas);
		
		fscanf(citas, "%i", &cita[i].mes);
    	adv = fgetc(citas);
	}
	fclose(citas);
	
	for(i = 0; i < n; i++){//Bucle para ordenar las citas según la fecha y la hora
		while(cita[i+1].mes < cita[i].mes){
			citaux = cita[i+1];
			cita[i+1] = cita[i];
			cita[i] = citaux;
			i = 0;
			
		}
		while(cita[i+1].mes == cita[i].mes && cita[i+1].dia < cita[i].dia){
			citaux = cita[i+1];
			cita[i+1] = cita[i];
			cita[i] = citaux;
			i = 0;
		}
		while(cita[i+1].mes == cita[i].mes && cita[i+1].dia == cita[i].dia && cita[i+1].hora < cita[i].hora){
			citaux = cita[i+1];
			cita[i+1] = cita[i];
			cita[i] = citaux;
			i = 0;
		}
		while(cita[i+1].mes == cita[i].mes && cita[i+1].dia == cita[i].dia && cita[i+1].hora == cita[i].hora && cita[i+1].min < cita[i].min){
			citaux = cita[i+1];
			cita[i+1] = cita[i];
			cita[i] = citaux;
			i = 0;
		}
	}
	
	for(dia = 1; dia <= d; dia++){
		printf("%i", dia);
    	aux = 0;
    	for(k = 0; k < n; k++){
    		if(cita[k].mes == mes && cita[k].dia == dia){
    			aux = 1;
    			if(cita[k].min == 0){
    				printf("\t%i:%i%i %s\n", cita[k].hora, cita[k].min, cita[k].min, cita[k].nombre);
				}
				else{
					printf("\t%i:%i %s\n", cita[k].hora, cita[k].min, cita[k].nombre);
				}
			}
		}
    	if(aux == 0){
    		printf("\t----------\n");
    	}
	}
	printf("\n");
}

void Vaciar(char cadena[]){
	int i;
	for(i = 0; i < N; i++)
    	cadena[i] = '\0';
}
