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
	int area;//0 = Mecánica, 1 = Carrocería, 2 = Pintura
	int orden;
	int estado;//0 = En espera, 1 = En proceso, 2 = Terminado
}Estado;

typedef struct{
	char nombre[N];
	char marca[N];
	char modelo[N];
	char matricula[N];
	int kilometros;
	int numordenes;
	Estado rep[5];
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

typedef struct{
	int orden;
	char reparacion[M];
	float horas;
	float materiales;
	float total;
}Reparacion;

int MenuAcceso(char *user);
int IniciarSesion(char *user);
void CrearEmpleado();
void CrearCliente();
void CrearCita(int x, char *user);
void CrearVehiculo();
void MenuEmpleado(char *user);
void MenuCliente(char *user);
void DatosVehiculo();
void ConsultarCita(char *user);
void Mes(int mes, int d); 
void ListadoPrecios();
void Calendario();
void AnadirOrden();
void ConsultarEstado(int x, char *user);
void Vaciar(char cadena[]);
void animacionBuscar();
void animacionGuardarCambios();
void animacionGuardar();
void animacionIniciarSesion();
void animacionCerrarSesion();
void animacionVolver();

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
	    
        printf("  1-    Iniciar sesión.\n  0-    Salir del programa.\n\n   OPCIÓN: ");
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
    	
	    printf("  1-    Consultar datos sobre un vehículo.\n  2-    Consultar estado de un vehículo.\n  " 
		"3-    Modificar estado de un vehículo.\n  4-    Añadir orden de reparación.\n  5-    Crear nuevo empleado.\n  6-    Crear nuevo cliente.\n"
		"  7-    Crear nuevo vehículo.\n  8-    Generar nueva cita.\n  9-    Consultar calendario.\n  0-    Cerrar sesión.\n\n   OPCIÓN: ");
	    scanf("%c", &opcion);
	    fflush(stdin);
	    printf("\n");
	    switch(opcion)
	    {
	    	case '1':
                DatosVehiculo();
	    		break;
	    	case '2':
	    		ConsultarEstado(x, user);
		    	break;
	    	case '3':
		    	printf("MODIFICAR ESTADO\n");
			    break;
	    	case '4':
		    	AnadirOrden();
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
		    	CrearCita(x, user);
		    	break;
		    case '9':
		    	Calendario();
		    	break;
		    case '0':
		    	animacionCerrarSesion();
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
	int x = 1;
	char opcion;
	do{
    	system("cls");
        printf("DATACOCHES\n\n");
        printf("Cliente: %s\n\n", user);
    	printf("¿Qué desea hacer?\n\n");
		
	    printf("  1-    Consultar estado de un vehículo.\n  2-    Consultar citas.\n"
		"  3-    Generar nueva cita.\n  4-    Listado de precios.\n  0-    Cerrar sesión.\n\n   OPCIÓN: ");
	    scanf("%c", &opcion);
	    fflush(stdin);
	    switch(opcion)
	    {
	    	case '1':
	    		ConsultarEstado(x, user);
	    		break;
	    	case '2':
		    	ConsultarCita(user);
		    	break;
	    	case '3':
		    	CrearCita(x, user);
			    break;
			case '4':
				ListadoPrecios();
				break;
			case '0':
				animacionCerrarSesion();
				break;
    		default:
	    		printf("Tecla no reconocida.\n\n");
		    	break;	
    	}
	    system("pause");
	}
	while (opcion != '0');
}

int IniciarSesion(char *user){
	system("chcp 1252");
	
	int i, j, k = 4, aux, opcion1, e = 0, c = 0;
	char usuario[N], cont[N], adv;
	Empleado emp[10];
	Cliente clie[M];
	FILE *empleados;
	FILE *clientes;
	
	empleados = fopen("empleados.txt", "r");
	if (empleados == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(empleados); i++){
		fscanf(empleados, "%[^,]s", emp[i].nombre);
	   	adv = fgetc(empleados);//Para avanzar una posición en el fichero
	    	
    	fscanf(empleados, "%[^,]s", emp[i].ocupacion);
	   	adv = fgetc(empleados);
	    	
    	fscanf(empleados, "%[^\n]s", emp[i].contrasena);
	   	adv = fgetc(empleados);
	}
	fclose(empleados);
	e = i - 1;//Número de empleados
	
	clientes = fopen("clientes.txt", "r");
	if (clientes == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	fseek(clientes, 0, SEEK_SET);
	for(i = 0; !feof(clientes); i++){
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
	c = i - 1;//Número de clientes
	
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
	            	animacionIniciarSesion();
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
	            	animacionIniciarSesion();
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
			printf("\nUsuario no definido\n\n");
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
	    printf("NUEVA CITA\n");
	    if(x == 0){
	    	printf("\nNombre completo: ");
	        scanf("%[^\n]s", cita.nombre);
	        fflush(stdin);
		}
    	else{
    		strcpy(cita.nombre, user);
		}
	    do{
	    	printf("\nMes(nº): ");
		    scanf("%i", &cita.mes);
    		if(cita.mes < 1 || cita.mes > 12){
	    		printf("\nIntroduzca el mes de nuevo.\n");
		    }
    		fflush(stdin);
	    }
	    while(cita.mes < 1 || cita.mes > 12);
	    do{
		    aux1 = 0;
		    printf("\nDía: ");
		    scanf("%i", &cita.dia);
		    if((cita.mes == 1 || cita.mes == 3 || cita.mes == 5 || cita.mes == 7 || cita.mes == 8 || cita.mes == 10 || cita.mes == 12) && (cita.dia < 1 || cita.dia > 31)){
			    printf("\nIntroduzca el día de nuevo.\n");
			    aux1 = 1;
		    }
		    else if(cita.mes == 2 && (cita.dia < 1 || cita.dia > 28)){
			    printf("\nIntroduzca el día de nuevo.\n");
			    aux1 = 1;
		    }
		    else if((cita.mes == 4 || cita.mes == 6 || cita.mes == 9 || cita.mes == 11) && (cita.dia < 1 || cita.dia > 30)){
			    printf("\nIntroduzca el día de nuevo.\n");
			    aux1 = 1;
		    }
		    fflush(stdin);
	    }
	    while(aux1 == 1);
	    do{
		    aux2 = 0;
		    printf("\nHora(hh mm): ");
		    scanf("%i%i", &cita.hora, &cita.min);
		    if(cita.hora < 9 || cita.hora > 19){
			    printf("\nIntroduzca la hora de nuevo.\nHorario fuera de servicio.\n");
			    aux2 = 1;
		    }
		    else if(cita.min != 0 && cita.min != 10 && cita.min != 20 && cita.min != 30 && cita.min != 40 && cita.min != 50){
			    printf("\nIntroduzca la hora de nuevo.\nLos minutos indicados sólo pueden ser 00, 10, 20, 30, 40 y 50.\n");
			    aux2 = 1;
		    }
		    fflush(stdin);
	    }
	    while(aux2 == 1);
	    if(cita.min == 0){
	    	system("cls");
			printf("DATACOCHES\n\n");
		    printf("NUEVA CITA\n\n");
		    printf("Le confirmamos su cita: \nNOMBRE: %s \nHORA: %i:%i%i \nDÍA: %i/%i\n", cita.nombre, cita.hora, cita.min, cita.min, cita.dia, cita.mes);
    	}
	    else{
	    	system("cls");
			printf("DATACOCHES\n\n");
		    printf("NUEVA CITA\n\n");
	    	printf("Le confirmamos su cita: \nNOMBRE: %s \nHORA: %i:%i \nDÍA: %i/%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
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
	while(res != 's' && res != 'S');
	
	animacionGuardar();
	fprintf(citas, "%s,%i:%i,%i/%i\n", cita.nombre, cita.hora, cita.min, cita.dia, cita.mes);
	printf("¡Cita registrada correctamente!\n\n");
	system("pause");
	fclose(citas);
	
	animacionVolver();
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
		printf("\nContraseña de administrador: ");
		scanf("%i", &contrasena);
		fflush(stdin);
		if(contrasena == 1111){
			system("cls");
			printf("DATACOCHES\n\n");
	        printf("NUEVO EMPLEADO\n\n");
        	printf("Nombre de usuario: ");
			scanf("%s", nom);
			fflush(stdin);
			printf("\nOcupación: ");
			scanf("%s", ocup);
			fflush(stdin);
			printf("\nContraseña: ");
			scanf("%s", cont);
			fflush(stdin);
        	
			fprintf(empleados, "%s,%s,%s\n", nom, ocup, cont);
	    	animacionGuardar();
			printf("\n¡Empleado registrado correctamente!\n\n");
			system("pause");
			i = 0;//Ruta de escape
		}
		else{
			i--;
			if(i == 0){
				printf("\nConsulte con el administrador.\n\n");
				exit(1);
			}
			else if(i == 1)
			printf("\nContraseña incorrecta.\nQueda %i intento\n", i);
			else
			printf("\nContraseña incorrecta.\nQuedan %i intentos\n", i);
		}
	}
	fclose(empleados);
	
	animacionVolver();
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
		system("cls");
		printf("DATACOCHES\n\n");
	    printf("NUEVO CLIENTE\n\n");
	    
	    printf("Nombre completo: ");
		scanf("%[^\n]s", nom);
		fflush(stdin);
		printf("\nNombre de usuario: ");
		scanf("%[^\n]s", us);
		fflush(stdin);
		do{
			printf("\nSexo (Masculino 'M' o Femenino 'F' u Otro 'O'): ");
	    	scanf("%c", &sexo);
	    	fflush(stdin);
	    	if(sexo != 'M' && sexo != 'F' && sexo != 'O'){
	    		printf("\nIntroduzca de nuevo el sexo.\n\n");
			}
		}
		while(sexo != 'M' && sexo != 'F' && sexo != 'O');
		do{
			printf("\nFecha de nacimiento(día mes año): ");
			scanf("%i %i %i", &dia, &mes, &ano);
	    	fflush(stdin);
	    	if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) || (mes == 2 && (dia < 1 || dia > 28)) 
			|| ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) || (mes < 1 || mes > 12 || ano < 1900 || ano > 2001)){
	    		printf("\nIntroduzca de nuevo la fecha.\n\n");
			}
		}
		while(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) || (mes == 2 && (dia < 1 || dia > 28)) 
		|| ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 30)) || (mes < 1 || mes > 12 || ano < 1900 || ano > 2001));
		printf("\nContraseña: ");
		scanf("%s", cont);
	   	fflush(stdin);
        system("cls");
        printf("DATACOCHES\n\n");
	    printf("NUEVO CLIENTE\n\n");
		printf("Le confirmamos sus datos: \n\nNOMBRE: %s \nUSUARIO: %s \nSEXO: %c\nFECHA DE NACIMIENTO: %i/%i/%i\nCONTRASEÑA: %s\n", nom, us, sexo, dia, mes, ano, cont);
	    
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
	
	animacionGuardar();
	fprintf(clientes, "%s,%s,%c,%i/%i/%i,%s\n", nom, us, sexo, dia, mes, ano, cont);
	printf("¡Cliente registrado con éxito!\n\n");
	fclose(clientes);
	
	do{
		system("pause");
		system("cls");
		printf("DATACOCHES\n\n");
	    printf("NUEVO CLIENTE\n\n");
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
	    
			printf("VEHÍCULO %i\n\n", i);
		    printf("Marca: ");
		    scanf("%[^\n]s", mar);
	   	    fflush(stdin);
			printf("\nModelo: ");
		    scanf("%[^\n]s", mod);
	   	    fflush(stdin);
	   	    printf("\nMatrícula(0000AAA): ");
		    scanf("%s", mat);
	   	    fflush(stdin);
	   	    do{
	   	    	printf("\nKilómetros: ");
	   	    	scanf("%i", &kms);
	   	    	fflush(stdin);
	   	    	if(kms < 1 || kms > 1000000){
	   	    		printf("\nIntroduzca de nuevo los kilómetros.\n");
				}
			}
	   	    while(kms < 1 || kms > 1000000);
	    	animacionGuardar();
        	system("cls");
        	printf("DATACOCHES\n\n");
	        printf("NUEVO CLIENTE\n\n");
	        
		    printf("Le confirmamos los datos de su vehículo: \n\nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s\nKILÓMETROS: %i\n", mar, mod, mat, kms);
	    
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
		while(res != 's' || res != 'S');
		
		animacionGuardar(); 
		fprintf(vehiculos, "%s,%s,%s,%s,%i/0\n", nom, mar, mod, mat, kms);
		printf("¡Vehículo registrado con éxito!\n\n");
		system("pause");
		
		Vaciar(mar);
		Vaciar(mod);
		Vaciar(mat);
	}	
	
	fclose(vehiculos);
	
	animacionVolver();
}

void CrearVehiculo(){
	system("chcp 1252");
	
	FILE *vehiculos;
	int kms;
	char nom[N], mar[N], mod[N], mat[N], res;
	
	vehiculos = fopen("vehiculos.txt", "a");
	
	if(vehiculos == NULL){
		printf("Error al abrir el fichero.\n");
		exit(1);
	}
	
	do{
		system("cls");
		printf("DATACOCHES\n\n");
	    printf("NUEVO VEHÍCULO\n\n");
	    
	    printf("Nombre completo: ");
	    scanf("%[^\n]s", nom);
	    fflush(stdin);
    	printf("\nMarca: ");
    	scanf("%[^\n]s", mar);
       	fflush(stdin);
    	printf("\nModelo: ");
    	scanf("%[^\n]s", mod);
   	    fflush(stdin);
   	    printf("\nMatrícula(0000AAA): ");
    	scanf("%s", mat);
       	fflush(stdin);
       	do{
       	   	printf("\nKilómetros: ");
       	   	scanf("%i", &kms);
   	       	fflush(stdin);
       	   	if(kms < 1 || kms > 1000000){
           		printf("\nIntroduzca de nuevo los kilómetros.\n");
    		}
	    }
   	    while(kms < 1 || kms > 1000000);
   	    system("cls");
		printf("DATACOCHES\n\n");
	    printf("NUEVO VEHÍCULO\n\n");
	    
   	    printf("Le confirmamos los datos del vehículo:\nPROPIETARIO: %s \nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s \nKILÓMETROS: %i\n\n", nom, mar, mod, mat, kms);
       	do{
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
			else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
				printf("\nTecla no reconocida.\n\n");
			}
		}
		while(res != 'n' && res != 'N' && res != 's' && res != 'S');
    }
   	while(res != 's' && res != 'S');
   	
	animacionGuardar();
   	
   	fprintf(vehiculos,"%s,%s,%s,%s,%i/0\n", nom, mar, mod, mat, kms);
   	
   	printf("¡Vehículo registrado con éxito!\n\n");
   	
   	fclose(vehiculos);
   	
   	system("pause");
   	
	animacionVolver();
}

void DatosVehiculo(){
    system("chcp 1252");
	
	int i, j, k, v = 0, aux, res = 2, op;
	char mat[10], adv, res2 = 'n'; 
	Vehiculo coche[M];
	FILE *vehiculos, *newvehiculos;
	
	vehiculos = fopen("vehiculos.txt", "r");
	if (vehiculos == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(vehiculos); i++){
		fscanf(vehiculos, "%[^,]s", coche[i].nombre);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].marca);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].modelo);
    	adv = fgetc(vehiculos);
    	
    	fscanf(vehiculos, "%[^,]s", coche[i].matricula);
    	adv = fgetc(vehiculos);
		
		fscanf(vehiculos, "%i", &coche[i].kilometros);
    	adv = fgetc(vehiculos);
    	
    	fscanf(vehiculos, "%i", &coche[i].numordenes);
    	adv = fgetc(vehiculos);
    	
    	for(k = 0; adv == ';'; k++){
    		fscanf(vehiculos, "%i", &coche[i].rep[k].area);
    		adv = fgetc(vehiculos);
    		fscanf(vehiculos, "%i", &coche[i].rep[k].orden);
    		adv = fgetc(vehiculos);
    		fscanf(vehiculos, "%i", &coche[i].rep[k].estado);
    		adv = fgetc(vehiculos);
		}
	}
	fclose(vehiculos);
	v = i - 1;//Número de vehículos
	
	do{
		do{
			system("cls");
			printf("DATACOCHES\n\n");
	    	printf("CONSULTAR DATOS DE VEHÍCULO\n\n");
	    	
	    	i = 0;
			aux = 0;
			printf("Introduzca matrícula(0 para salir): ");
			scanf("%10s", mat);
			fflush(stdin);
			if(mat[0] == '0' && mat[1] == '\0'){
				aux = 1;
				res = 0;
			}
			else{
				animacionBuscar();
				printf("DATACOCHES\n\n");
		    	printf("CONSULTAR DATOS DE VEHÍCULO\n");
				while(i < v && aux == 0){
		    		if(strcmp(mat, coche[i].matricula) == 0){
		    			aux = 1;
			    	}
			    	i++;
		    	}
		    	if(aux == 1){
		    		i--;
		    		printf("\nPROPIETARIO: %s \nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s \nKILÓMETROS: %i\n\n", coche[i].nombre, coche[i].marca, coche[i].modelo, coche[i].matricula, coche[i].kilometros);
		    		aux = 2;
		    		system("pause");
				}
				else if(aux == 0){
					printf("\nVehículo no registrado.\n\n");
					system("pause");
					Vaciar(mat);
				}
			}
		}
		while(aux == 0);
		
		while(res != 0 && res != 1){
			do{
				system("cls");
				printf("DATACOCHES\n\n");
		    	printf("CONSULTAR DATOS DE VEHÍCULO\n\n");
				printf("¿Qué desea hacer?\n\n  1-    Consultar otro vehículo.\n  2-    Modificar datos del vehículo.\n  0-    Volver.\n\n   OPCIÓN: ");
			    scanf("%i", &res);
			    fflush(stdin);
			    if(res != 0 && res != 1 && res != 2){
			        printf("\nTecla no reconocida.\n\n");
			        system("pause");
			    }
			}
			while(res != 0 && res != 1 && res != 2);
			
		    if(res == 2){
		    	do{
			    	do{
			    		system("cls");
			    		printf("DATACOCHES\n\n");
				    	printf("¿Qué datos desea modificar?\n\n   1-    Marca\n   2-    Modelo\n   3-    Matrícula\n   4-    Kilometros\n\n   OPCIÓN: ");
			    		scanf("%i", &op);
			    		fflush(stdin);
			    		switch(op)
						{
			    			case 1:
			    				Vaciar(coche[i].marca);
			    				printf("\nIntroduzca la nueva marca: ");
			    				scanf("%[^\n]s", coche[i].marca);
			    				fflush(stdin);
			    				break;
			    			case 2:
								printf("\nIntroduzca el nuevo modelo: ");
			    				scanf("%[^\n]s", coche[i].modelo);
			    				fflush(stdin);
			    				break;
			    			case 3:
								printf("\nIntroduzca la nueva matrícula: ");
			    				scanf("%[^\n]s", coche[i].matricula);
			    				fflush(stdin);
			    				break;
			    			case 4:
								printf("\nIntroduzca los kilómetros: ");
			    				scanf("%i", &coche[i].kilometros);
			    				fflush(stdin);
			    				break;
			    			default:
			    				printf("\nTecla no reconocida\n\n");
			    				system("pause");
			    				break;	
						}
				    }
				    while(op != 1 && op != 2 && op != 3 && op != 4);
				    
					printf("\nEstos son los nuevos datos:\nPROPIETARIO: %s \nMARCA: %s \nMODELO: %s \nMATRÍCULA: %s \nKILÓMETROS: %i\n\n", coche[i].nombre, coche[i].marca, coche[i].modelo, coche[i].matricula, coche[i].kilometros);
	    			
					do{
						printf("¿Está conforme con los datos?(Si = s / No = n): ");
						scanf("%c", &res2);
						fflush(stdin);
						if(res2 == 's' || res2 == 'S'){
							newvehiculos = fopen("vehiculos.txt", "w");
							if (newvehiculos == NULL){ 
							printf("Error al abrir el fichero.\n"); 
							exit(1); 
							}
							for(j = 0; j < v; j++){
								fprintf(newvehiculos, "%s,%s,%s,%s,%i/%i", coche[i].nombre, coche[j].marca, coche[j].modelo, coche[j].matricula, coche[j].kilometros, coche[i].numordenes);
								for(k = 0; k < coche[i].numordenes; k++){
									fprintf(newvehiculos, ";%i,%i,%i", coche[j].rep[k].area, coche[j].rep[k].orden, coche[j].rep[k].estado);
								}
								fprintf(newvehiculos, "\n");
							}
							animacionGuardarCambios();
							printf("\n¡Datos modificados correctamente!\n\n");
							system("pause");
							fclose(newvehiculos);
						}
						else if(res2 != 's' && res2 != 'S' && res2 != 'n' && res2 != 'N'){
							printf("\nTecla no reconocida.\n\n");
						}
					}
					while(res2 != 's' && res2 != 'S' && res2 != 'n' && res2 != 'N');
				}
				while(res2 == 'n' || res2 == 'N');
			}
			else{
		    	Vaciar(mat);
			}
		}
	}
	while(res != 0);
	
	animacionVolver();
}

void ConsultarCita(char *user){
	system("chcp 1252");
	system("cls");
	
	int i, n, aux = 0, x = 1, c = 0;
	char adv, res;
	Cita cita[M];
	FILE *citas;
	
	citas = fopen("citas.txt", "r");
	if(citas == NULL){
		printf("Error al abrir el fichero.\n");
		exit(1);
	}
	for(i = 0; !feof(citas); i++){
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
	n = i - 1;//Número de citas
	
	animacionBuscar();
	
	printf("DATACOCHES\n\n");
    printf("CONSULTA DE CITAS\n\n");
	for(i = 0; i < n; i++){
		if(strcmp(user, cita[i].nombre) == 0){
			c++;//Contador de citas
			aux = 1;
			if(cita[i].min == 0){
			    printf("CITA %i: \nNOMBRE: %s \nDÍA: %i/%i \nHORA: %i:%i%i\n\n", c, cita[i].nombre, cita[i].dia, cita[i].mes, cita[i].hora, cita[i].min, cita[i].min);
	        }
		    else{
		       	printf("CITA %i: \nNOMBRE: %s \nDÍA: %i/%i \nHORA: %i:%i\n\n", c, cita[i].nombre, cita[i].dia, cita[i].mes, cita[i].hora, cita[i].min);
	       	}
		}
	}

	if(aux == 1){
       	printf("Por favor, no olvide traer la documentación de su vehículo.\n");
        printf("\nSi lo desea puede concertar otra cita(Si = s / No = n): ");
	}
	else{
		printf("No tiene ninguna cita concertada.\n\nSi lo desea puede concertar una (Si = s / No = n): ");
	}
	do{
		scanf("%c", &res);
		fflush(stdin);
		if(res == 's' || res == 'S'){
			CrearCita(x, user);
		}
		else if(res != 's' && res != 'S' && res != 'n' && res != 'N'){
			printf("\nTecla no reconocida.\n\n¿Quiere concertar una cita?(Si = s / No = n): ");
		}
		else{
			printf("\nSi en algún otro momento desea concertar una cita, puede hacerlo a través del programa, o bien, llamando al 911 111 111.\n\n");
			system("pause");
			animacionVolver();
		}
	}
	while(res != 's' && res != 'S' && res != 'n' && res != 'N');
}

void ListadoPrecios(){
	system("chcp 1252");
	
	int opcion, i, j;
	char adv;
	FILE *mecanica, *carroceria, *pintura;
	Reparacion proceso[M];
	
	do{
		system("cls");
		printf("DATACOCHES\n\n");
	    printf("¿Qué precios desea consultar?\n\n");
	    printf("  1-    MECÁNICA\n  2-    CARROCERÍA\n  3-    PINTURA\n  0-    Volver.\n\n   OPCIÓN: ");
	    scanf("%i", &opcion);
	    fflush(stdin);
	    switch(opcion)
	    {
	    	case 1:
	    		system("cls");
				printf("DATACOCHES\n\n");
	    		mecanica = fopen("mecanica.txt", "r");
				if (mecanica == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
	    		for(i = 0; !feof(mecanica); i++){
					fscanf(mecanica, "%i", &proceso[i].orden);
				   	adv = fgetc(mecanica);
				   	
					fscanf(mecanica, "%[^,]s", proceso[i].reparacion);
				   	adv = fgetc(mecanica);
				    	
			    	fscanf(mecanica, "%f", &proceso[i].horas);
				   	adv = fgetc(mecanica);
				   	
				   	fscanf(mecanica, "%f", &proceso[i].materiales);
				   	adv = fgetc(mecanica);
				   	
				   	fscanf(mecanica, "%f", &proceso[i].total);
				   	adv = fgetc(mecanica);
				}
				i--;
	            fclose(mecanica);
	            
	            printf("PRECIOS MECÁNICA\n\n");
	            
	            for(j = 0; j < i; j++){
	            	printf("   %i-\t%s\n\tHoras: %g", proceso[j].orden, proceso[j].reparacion, proceso[j].horas);
	            	if(proceso[j].materiales != 0){
	            		printf("\tMateriales: %g€", proceso[j].materiales);
					}
	            	proceso[j].total = proceso[j].horas*42.50 + proceso[j].materiales;
					printf("\n\tPrecio total: %g€\n\n", proceso[j].total);
				}
				printf("\n**Precio/hora mano de obra mecánica: 42,50€.\n\n");
				system("pause");
	    		break;
	    	case 2:
	    		system("cls");
				printf("DATACOCHES\n\n");
	    		carroceria = fopen("carroceria.txt", "r");
				if (carroceria == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
	    		for(i = 0; !feof(carroceria); i++){
					fscanf(carroceria, "%i", &proceso[i].orden);
				   	adv = fgetc(carroceria);
				   	
					fscanf(carroceria, "%[^,]s", proceso[i].reparacion);
				   	adv = fgetc(carroceria);
				    	
			    	fscanf(carroceria, "%f", &proceso[i].horas);
				   	adv = fgetc(carroceria);
				   	
				   	fscanf(carroceria, "%f", &proceso[i].materiales);
				   	adv = fgetc(carroceria);
				}
				i--;
	            fclose(carroceria);
	            
	            printf("PRECIOS CARROCERIA\n\n");
	            
	            for(j = 0; j < i; j++){
	            	printf("   %i-\t%s\n\tHoras: %g", proceso[j].orden, proceso[j].reparacion, proceso[j].horas);
	            	if(proceso[j].materiales != 0){
	            		printf("\tMateriales: %g€", proceso[j].materiales);
					}
	            	proceso[j].total = proceso[j].horas*62.50 + proceso[j].materiales;
					printf("\n\tPrecio total: %g€\n\n", proceso[j].total);
				}
				printf("\n**Precio/hora mano de obra carrocería: 62,50€.\n\n");
				system("pause");
		    	break;
	    	case 3:
	    		system("cls");
				printf("DATACOCHES\n\n");
	    		pintura = fopen("pintura.txt", "r");
				if (pintura == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
	    		for(i = 0; !feof(pintura); i++){
					fscanf(pintura, "%i", &proceso[i].orden);
				   	adv = fgetc(pintura);
				   	
					fscanf(pintura, "%[^,]s", proceso[i].reparacion);
				   	adv = fgetc(pintura);
				    	
			    	fscanf(pintura, "%f", &proceso[i].horas);
				   	adv = fgetc(pintura);
				   	
				   	fscanf(pintura, "%f", &proceso[i].materiales);
				   	adv = fgetc(pintura);
				}
				i--;
	            fclose(pintura);
	            
	            printf("PRECIOS PINTURA\n\n");
	            
	            for(j = 0; j < i; j++){
	            	printf("   %i-\t%s\n\tHoras: %g", proceso[j].orden, proceso[j].reparacion, proceso[j].horas);
	            	if(proceso[j].materiales != 0){
	            		printf("\tMateriales: %g€", proceso[j].materiales);
					}
	            	proceso[j].total = proceso[j].horas*68.50 + proceso[j].materiales;
					printf("\n\tPrecio total: %g€\n\n", proceso[j].total);
				}
				printf("\n**Precio/hora mano de obra pintura: 68,50€.\n\n");
				system("pause");
			    break;
			case 0:
				break;
    		default:
	    		printf("Tecla no reconocida.\n\n");
	    		system("pause");
		    	break;	
    	}
	}
	while(opcion != 0);
	
	animacionVolver();
}

void AnadirOrden(){
	system("chcp 1252");
	
	int op, i;
	float total;
	char res, adv;
	Reparacion orden, basura[M];
	FILE *mecanica, *newmecanica, *carroceria, *newcarroceria, *pintura, *newpintura;
	
	do{
		system("cls");
        printf("DATACOCHES\n\n");
        printf("AÑADIR ORDEN\n\n");
        printf("  1-    MECÁNICA\n  2-    CARROCERÍA\n  3-    PINTURA\n  0-    VOLVER\n\n   OPCIÓN: ");
        scanf("%i", &op);
        fflush(stdin);
        
        switch(op){
        	case 1:	
        		mecanica = fopen("mecanica.txt", "r");
				if (mecanica == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				for(i = 0; !feof(mecanica); i++){//Bucle para contar el número de órdenes ya existentes
					fscanf(mecanica, "%[^\n]s", basura);
					adv = fgetc(mecanica);
				}
				fclose(mecanica);
				
				newmecanica = fopen("mecanica.txt", "a");
				if (newmecanica == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				
				do{
					system("cls");
			        printf("DATACOCHES\n\n");
			        printf("AÑADIR ORDEN MECÁNICA\n\n");
					printf("Introduzca la orden: ");
					scanf("%[^\n]s", orden.reparacion);
					fflush(stdin);
					
					printf("\nIntroduzca las horas de mano de obra: ");
					scanf("%f", &orden.horas);
					fflush(stdin);
					
					printf("\nIntroduzca el valor(€) de los materiales empleados: ");
					scanf("%f", &orden.materiales);
					fflush(stdin);
					
					orden.total = orden.horas*42.50 + orden.materiales;
					
					printf("\nORDEN %i: %s\tHoras: %g\t", i, orden.reparacion, orden.horas);
					if(orden.materiales != 0){
						printf("Materiales: %g€\t", orden.materiales);
					}
					printf("Precio total: %g€\n\n", orden.total);
					do{
				   	    printf("¿Está de acuerdo?(Si = s / No = n): ");
				       	scanf("%c", &res);
				       	fflush(stdin);
				       	if(res == 'n' || res == 'N'){
				        	system("cls");
							Vaciar(orden.reparacion);
						}
						else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
							printf("\nTecla no reconocida.\n\n");
						}
					}
					while(res != 'n' && res != 'N' && res != 's' && res != 'S');
				}
				while(res == 'N' || res == 'n');
				
				animacionGuardar();
				fprintf(newmecanica, "%i,%s,%g,%g,%g\n", i, orden.reparacion, orden.horas, orden.materiales, orden.total);
				fclose(newmecanica);
				Vaciar(orden.reparacion);
				printf("¡Orden registrada correctamente!\n\n");
				system("pause");
        		break;
        		
        	case 2:
        		carroceria = fopen("carroceria.txt", "r");
				if (carroceria == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				for(i = 0; !feof(carroceria); i++){
					fscanf(carroceria, "%[^\n]s", basura);
					adv = fgetc(carroceria);
				}
				fclose(carroceria);
				
				newcarroceria = fopen("carroceria.txt", "a");
				if (newcarroceria == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				
				do{
	        		system("cls");
			        printf("DATACOCHES\n\n");
			        printf("AÑADIR ORDEN CARROCERÍA\n\n");
					printf("Introduzca la orden: ");
					scanf("%[^\n]s", orden.reparacion);
					fflush(stdin);
					
					printf("\nIntroduzca las horas de mano de obra: ");
					scanf("%f", &orden.horas);
					fflush(stdin);
					
					printf("\nIntroduzca el valor(€) de los materiales empleados: ");
					scanf("%f", &orden.materiales);
					fflush(stdin);
					
					orden.total = orden.horas*62.50 + orden.materiales;
					
					printf("\nORDEN %i: %s\tHoras: %g\t", i, orden.reparacion, orden.horas);
					if(orden.materiales != 0){
						printf("Materiales: %g€\t", orden.materiales);
					}
					printf("Precio total: %g€\n\n", orden.total);
					do{
				   	    printf("¿Está de acuerdo?(Si = s / No = n): ");
				       	scanf("%c", &res);
				       	fflush(stdin);
				       	if(res == 'n' || res == 'N'){
				        	system("cls");
							Vaciar(orden.reparacion);
						}
						else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
							printf("\nTecla no reconocida.\n\n");
						}
					}
					while(res != 'n' && res != 'N' && res != 's' && res != 'S');
				}
				while(res == 'N' || res == 'n');
				
				animacionGuardar();
				fprintf(newcarroceria, "%i,%s,%g,%g,%g\n", i, orden.reparacion, orden.horas, orden.materiales, orden.total);
				fclose(newcarroceria);
				Vaciar(orden.reparacion);
				printf("¡Orden registrada correctamente!\n\n");
				system("pause");
        		break;
        		
        	case 3:
        		pintura = fopen("pintura.txt", "r");
				if (pintura == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				for(i = 0; !feof(pintura); i++){
					fscanf(pintura, "%[^\n]s", basura);
					adv = fgetc(pintura);
				}
				fclose(pintura);
				
				newpintura = fopen("pintura.txt", "a");
				if (newpintura == NULL){ 
				printf("Error al abrir el fichero.\n"); 
				exit(1); 
				}
				
				do{
	        		system("cls");
			        printf("DATACOCHES\n\n");
			        printf("AÑADIR ORDEN PINTURA\n\n");
					printf("Introduzca la orden: ");
					scanf("%[^\n]s", orden.reparacion);
					fflush(stdin);
					
					printf("\nIntroduzca las horas de mano de obra: ");
					scanf("%f", &orden.horas);
					fflush(stdin);
					
					printf("\nIntroduzca el valor(€) de los materiales empleados: ");
					scanf("%f", &orden.materiales);
					fflush(stdin);
					
					orden.total = orden.horas*68.50 + orden.materiales;
					
					printf("\nORDEN %i: %s\tHoras: %g\t", i, orden.reparacion, orden.horas);
					if(orden.materiales != 0){
						printf("Materiales: %g€\t", orden.materiales);
					}
					printf("Precio total: %g€\n\n", orden.total);
					do{
				   	    printf("¿Está de acuerdo?(Si = s / No = n): ");
				       	scanf("%c", &res);
				       	fflush(stdin);
				       	if(res == 'n' || res == 'N'){
				        	system("cls");
							Vaciar(orden.reparacion);
						}
						else if(res != 'n' && res != 'N' && res != 's' && res != 'S'){
							printf("\nTecla no reconocida.\n\n");
						}
					}
					while(res != 'n' && res != 'N' && res != 's' && res != 'S');
				}
				while(res == 'N' || res == 'n');
				
				animacionGuardar();
				fprintf(newpintura, "%i,%s,%g,%g,%g\n", i, orden.reparacion, orden.horas, orden.materiales,orden.total);
				fclose(newpintura);
				Vaciar(orden.reparacion);
				printf("¡Orden registrada correctamente!\n\n");
				system("pause");
        		break;
        		
        	case 0:
        		break;
        		
        	default:
        		printf("Tecla no reconocida.\n\n");
        		system("pause");
        		break;
		}
		
	}
	while(op != 0);
	
	animacionVolver();
}

void Calendario(){
	system("chcp 1252");
	system("cls");
	
	int mes, dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Días que tiene cada mes
	
	animacionBuscar();
	
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
	system("pause");
	animacionVolver();
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

void ConsultarEstado(int x, char *user){
	system("chcp 1252");
	
	int i, j, k, n, aux, res, m, c, p, op, v;
	char mat[10], adv;
	Vehiculo coche[N], cocheaux[5];
	Reparacion mec[N], carr[N], pint[N];
	FILE *vehiculos, *mecanica, *carroceria, *pintura;
	
	vehiculos = fopen("vehiculos.txt", "r");
	if (vehiculos == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(vehiculos); i++){
		fscanf(vehiculos, "%[^,]s", coche[i].nombre);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].marca);
	   	adv = fgetc(vehiculos);
	    	
    	fscanf(vehiculos, "%[^,]s", coche[i].modelo);
    	adv = fgetc(vehiculos);
    	
    	fscanf(vehiculos, "%[^,]s", coche[i].matricula);
    	adv = fgetc(vehiculos);
		
		fscanf(vehiculos, "%i", &coche[i].kilometros);
    	adv = fgetc(vehiculos);
    	
    	fscanf(vehiculos, "%i", &coche[i].numordenes);
    	adv = fgetc(vehiculos);
    	
    	for(k = 0; adv == ';'; k++){
    		fscanf(vehiculos, "%i", &coche[i].rep[k].area);
    		adv = fgetc(vehiculos);
    		fscanf(vehiculos, "%i", &coche[i].rep[k].orden);
    		adv = fgetc(vehiculos);
    		fscanf(vehiculos, "%i", &coche[i].rep[k].estado);
    		adv = fgetc(vehiculos);
		}
	}
	fclose(vehiculos);
	v = i - 1;//Número de vehículos
	
	mecanica = fopen("mecanica.txt", "r");
	if (mecanica == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(mecanica); i++){
		fscanf(mecanica, "%i", &mec[i].orden);
	   	adv = fgetc(mecanica);
	   	
		fscanf(mecanica, "%[^,]s", mec[i].reparacion);
	   	adv = fgetc(mecanica);
	    	
    	fscanf(mecanica, "%f", &mec[i].horas);
	   	adv = fgetc(mecanica);
	   	
	   	fscanf(mecanica, "%f", &mec[i].materiales);
	   	adv = fgetc(mecanica);
	   	
	   	fscanf(mecanica, "%f", &mec[i].total);
	   	adv = fgetc(mecanica);
	}
	m = i - 1;
    fclose(mecanica);
    
    carroceria = fopen("carroceria.txt", "r");
	if (carroceria == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(carroceria); i++){
		fscanf(carroceria, "%i", &carr[i].orden);
	   	adv = fgetc(carroceria);
	   	
		fscanf(carroceria, "%[^,]s", carr[i].reparacion);
	   	adv = fgetc(carroceria);
	    	
    	fscanf(carroceria, "%f", &carr[i].horas);
	   	adv = fgetc(carroceria);
	   	
	   	fscanf(carroceria, "%f", &carr[i].materiales);
	   	adv = fgetc(carroceria);
	   	
	   	fscanf(carroceria, "%f", &carr[i].total);
	   	adv = fgetc(carroceria);
	}
	c = i - 1;
    fclose(carroceria);
    
    pintura = fopen("pintura.txt", "r");
	if (pintura == NULL){ 
	printf("Error al abrir el fichero.\n"); 
	exit(1); 
	}
	for(i = 0; !feof(pintura); i++){
		fscanf(pintura, "%i", &pint[i].orden);
	   	adv = fgetc(pintura);
	   	
		fscanf(pintura, "%[^,]s", pint[i].reparacion);
	   	adv = fgetc(pintura);
	    	
    	fscanf(pintura, "%f", &pint[i].horas);
	   	adv = fgetc(pintura);
	   	
	   	fscanf(pintura, "%f", &pint[i].materiales);
	   	adv = fgetc(pintura);
	   	
	   	fscanf(pintura, "%f", &pint[i].total);
	   	adv = fgetc(pintura);
	}
	p = i -1;
    fclose(pintura);
	
	if(x == 0){
		do{
			do{
				system("cls");
				printf("DATACOCHES\n\n");
				printf("CONSULTAR ESTADO DE VEHÍCULO\n");
				
				aux = 0;
				printf("\nIntroduzca la matrícula(0 para salir): ");
				scanf("%10s", mat);
			    fflush(stdin);
				if(mat[0] == '0' && mat[1] == '\0'){
					res = 0;
					aux = 1;
				}
				else{
					animacionBuscar();
					printf("DATACOCHES\n\n");
			    	printf("CONSULTAR ESTADO DE VEHÍCULO\n");
			    	for(i = 0; i < v && aux == 0; i++){
			    		if(strcmp(mat, coche[i].matricula) == 0){
			    			aux = 1;
				    	}
			    	}
			    	if(aux == 1){
			    		i--;
			    		if(coche[i].numordenes == 0){
			    			printf("\nEl vehículo con matrícula %s no tiene abierta ninguna orden de trabajo.\n\n", mat);
						}
						else{
							printf("\nMATRÍCULA: %s \n\n", coche[i].matricula);
				    		for(k = 0; k < coche[i].numordenes; k++){
				    			if(coche[i].rep[k].area == 0){
				    				printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, mec[coche[i].rep[k].orden].reparacion, mec[coche[i].rep[k].orden].horas);
				    				if(mec[coche[i].rep[k].orden].materiales != 0){
				    					printf("\tMateriales: %g€", mec[coche[i].rep[k].orden].materiales);
									}
									printf("\tPrecio total: %g€\n", mec[coche[i].rep[k].orden].total);
									if(coche[i].rep[k].estado == 0){
										printf("\tESTADO: En espera.\n\n");
									}
									else if(coche[i].rep[k].estado == 1){
										printf("\tESTADO: En proceso.\n\n");
									}
									else{
										printf("\tESTADO: Terminado.\n\n");
									}
								}
				    			else if(coche[i].rep[k].area == 1){
				    				printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, carr[coche[i].rep[k].orden].reparacion, carr[coche[i].rep[k].orden].horas);
				    				if(carr[coche[i].rep[k].orden].materiales != 0){
				    					printf("\tMateriales: %g€", carr[coche[i].rep[k].orden].materiales);
									}
									printf("\tPrecio total: %g€\n", carr[coche[i].rep[k].orden].total);
									if(coche[i].rep[k].estado == 0){
										printf("\tESTADO: En espera.\n\n");
									}
									else if(coche[i].rep[k].estado == 1){
										printf("\tESTADO: En proceso.\n\n");
									}
									else{
										printf("\tESTADO: Terminado.\n\n");
									}
								}
								else{
									printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, pint[coche[i].rep[k].orden].reparacion, pint[coche[i].rep[k].orden].horas);
				    				if(pint[coche[i].rep[k].orden].materiales != 0){
				    					printf("\tMateriales: %g€", pint[coche[i].rep[k].orden].materiales);
									}
									printf("\tPrecio total: %g€\n", pint[coche[i].rep[k].orden].total);
									if(coche[i].rep[k].estado == 0){
										printf("\tESTADO: En espera.\n\n");
									}
									else if(coche[i].rep[k].estado == 1){
										printf("\tESTADO: En proceso.\n\n");
									}
									else{
										printf("\tESTADO: Terminado.\n\n");
									}
								}
							}
						}
			    		aux = 2;
			    		system("pause");
					}
					else if(aux == 0){
						printf("\nVehículo no registrado.\n\n");
						system("pause");
						Vaciar(mat);
					}
				}
			}
			while(aux == 0);
			
			do{
				system("cls");
				printf("DATACOCHES\n\n");
		    	printf("CONSULTAR ESTADO DE VEHÍCULO\n\n");
				printf("¿Qué desea hacer?\n\n  1-    Consultar otro vehículo.\n  0-    Volver.\n\n   OPCIÓN: ");
			    scanf("%i", &res);
			    fflush(stdin);
			    if(res != 0 && res != 1){
			        printf("\nTecla no reconocida.\n\n");
			        system("pause");
			    }
			    else if(res == 1){
			    	Vaciar(mat);
				}
			}
			while(res != 0 && res != 1);
		}
		while(res == 1);	
	}
	else{
		do{
			do{
				system("cls");
				printf("DATACOCHES\n\n");
				printf("CONSULTAR ESTADO DE VEHÍCULO\n\n");
				n = 0;
				for(i = 0; i < v; i++){
					if(strcmp(user, coche[i].nombre) == 0){
						n++;//Contador de vehículos a su nombre con ordenes de reparación
						aux = 1;
						strcpy(cocheaux[n-1].nombre, coche[i].nombre);
						strcpy(cocheaux[n-1].marca, coche[i].marca);
						strcpy(cocheaux[n-1].modelo, coche[i].modelo);
						strcpy(cocheaux[n-1].matricula, coche[i].matricula);
						cocheaux[n-1].kilometros = coche[i].kilometros;
						cocheaux[n-1].numordenes = coche[i].numordenes;
						for(j = 0; j < coche[i].numordenes; j++){
							cocheaux[n-1].rep[j].area = coche[i].rep[j].area;
							cocheaux[n-1].rep[j].orden = coche[i].rep[j].orden;
							cocheaux[n-1].rep[j].estado = coche[i].rep[j].estado;
						}
						printf("VEHÍCULO %i\nMARCA: %s\nMODELO: %s\nMATRÍCULA: %s\nKILÓMETROS: %i\n\n", n, coche[i].marca, coche[i].modelo, coche[i].matricula, coche[i].kilometros);
					}
				}
				if(n > 1){
					printf("Indique el vehículo: ");
					scanf("%i", &op);
				    fflush(stdin);
				    if((op != 1 && op != 2 && op != 3 && op != 4 && op != 5) || (op > n)){
				    	printf("\nTecla no reconocida.\n\n");
				    	system("pause");
					}
				}
				else{
					system("pause");
					op = 1;
				}
			}
			while((op != 1 && op != 2 && op != 3 && op != 4 && op != 5) || (op > n));
			
			animacionBuscar();
			printf("DATACOCHES\n\n");
			printf("CONSULTAR ESTADO DE VEHÍCULO\n");
			
			if(cocheaux[op-1].numordenes == 0){
				printf("\nEl vehículo no tiene abierta ninguna orden de trabajo.\n\n");
				system("pause");
			}
			else{
				printf("\nMATRÍCULA: %s \n\n", cocheaux[op-1].matricula);
	    		for(k = 0; k < cocheaux[op-1].numordenes; k++){
	    			if(cocheaux[op-1].rep[k].area == 0){
	    				printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, mec[cocheaux[op-1].rep[k].orden].reparacion, mec[cocheaux[op-1].rep[k].orden].horas);
	    				if(mec[cocheaux[op-1].rep[k].orden].materiales != 0){
	    					printf("\tMateriales: %g€", mec[cocheaux[op-1].rep[k].orden].materiales);
						}
						printf("\tPrecio total: %g€\n", mec[cocheaux[op-1].rep[k].orden].total);
						if(cocheaux[op-1].rep[k].estado == 0){
							printf("\tESTADO: En espera.\n\n");
						}
						else if(cocheaux[op-1].rep[k].estado == 1){
							printf("\tESTADO: En proceso.\n\n");
						}
						else{
							printf("\tESTADO: Terminado.\n\n");
						}
					}
	    			else if(cocheaux[op-1].rep[k].area == 1){
	    				printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, carr[cocheaux[op-1].rep[k].orden].reparacion, carr[cocheaux[op-1].rep[k].orden].horas);
	    				if(carr[cocheaux[op-1].rep[k].orden].materiales != 0){
	    					printf("\tMateriales: %g€", carr[cocheaux[op-1].rep[k].orden].materiales);
						}
						printf("\tPrecio total: %g€\n", carr[cocheaux[op-1].rep[k].orden].total);
						if(cocheaux[op-1].rep[k].estado == 0){
							printf("\tESTADO: En espera.\n\n");
						}
						else if(cocheaux[op-1].rep[k].estado == 1){
							printf("\tESTADO: En proceso.\n\n");
						}
						else{
							printf("\tESTADO: Terminado.\n\n");
						}
					}
					else{
						printf("ORDEN %i: %s.\n\tHoras: %g", k + 1, pint[cocheaux[op-1].rep[k].orden].reparacion, pint[cocheaux[op-1].rep[k].orden].horas);
	    				if(pint[cocheaux[op-1].rep[k].orden].materiales != 0){
	    					printf("\tMateriales: %g€", pint[cocheaux[op-1].rep[k].orden].materiales);
						}
						printf("\tPrecio total: %g€\n", pint[cocheaux[op-1].rep[k].orden].total);
						if(cocheaux[op-1].rep[k].estado == 0){
							printf("\tESTADO: En espera.\n\n");
						}
						else if(cocheaux[op-1].rep[k].estado == 1){
							printf("\tESTADO: En proceso.\n\n");
						}
						else{
							printf("\tESTADO: Terminado.\n\n");
						}
					}
				}
			}
			system("pause");
			
			if(n > 1){
				do{
					system("cls");
					printf("DATACOCHES\n\n");
			    	printf("CONSULTAR ESTADO DE VEHÍCULO\n\n");
					printf("¿Qué desea hacer?\n\n  1-    Consultar otro vehículo.\n  0-    Volver.\n\n   OPCIÓN: ");
				    scanf("%i", &res);
				    fflush(stdin);
				    if(res != 0 && res != 1){
				        printf("\nTecla no reconocida.\n\n");
				        system("pause");
				    }
				}
				while(res != 0 && res != 1);
			}
			else{
				res = 0;
			}
		}
		while(res == 1);
	}
	animacionVolver();
}

void Vaciar(char cadena[]){
	int i;
	for(i = 0; i < N; i++)
    	cadena[i] = '\0';
}

void animacionGuardarCambios(){
	system("cls");
	printf("Guardando cambios\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios .\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios . . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios .\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando cambios . . .\n");
	Sleep(250);
	system("cls");
}

void animacionGuardar(){
	system("cls");
	printf("Guardando\n");
	Sleep(250);
	system("cls");
	printf("Guardando .\n");
	Sleep(250);
	system("cls");
	printf("Guardando . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando . . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando\n");
	Sleep(250);
	system("cls");
	printf("Guardando .\n");
	Sleep(250);
	system("cls");
	printf("Guardando . .\n");
	Sleep(250);
	system("cls");
	printf("Guardando . . .\n");
	Sleep(250);
	system("cls");
}

void animacionBuscar(){
	system("cls");
	printf("Buscando datos\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos .\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos . .\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos . . .\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos .\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos . .\n");
	Sleep(250);
	system("cls");
	printf("Buscando datos . . .\n");
	Sleep(250);
	system("cls");
}

void animacionIniciarSesion(){
	system("cls");
	printf("Iniciando sesión .\n");
	Sleep(250);
	system("cls");
	printf("Iniciando sesión . .\n");
	Sleep(250);
	system("cls");
	printf("Iniciando sesión . . .\n");
	Sleep(250);
	system("cls");
	printf("Iniciando sesión .\n");
	Sleep(250);
	system("cls");
	printf("Iniciando sesión . .\n");
	Sleep(250);
	system("cls");
	printf("Iniciando sesión . . .\n");
	Sleep(250);
	system("cls");
}

void animacionCerrarSesion(){
	system("cls");
	printf("Cerrando sesión .\n");
	Sleep(250);
	system("cls");
	printf("Cerrando sesión . .\n");
	Sleep(250);
	system("cls");
	printf("Cerrando sesión . . .\n");
	Sleep(250);
	system("cls");
	printf("Cerrando sesión .\n");
	Sleep(250);
	system("cls");
	printf("Cerrando sesión . .\n");
	Sleep(250);
	system("cls");
	printf("Cerrando sesión . . .\n");
	Sleep(250);
	system("cls");
}

void animacionVolver(){
	system("cls");
	printf("Volviendo .\n");
	Sleep(250);
	system("cls");
	printf("Volviendo . .\n");
	Sleep(250);
	system("cls");
	printf("Volviendo . . .\n");
	Sleep(250);
	system("cls");
}
