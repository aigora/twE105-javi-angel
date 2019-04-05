//DATACOCHES

#include<stdio.h>

typedef struct
{
	char propietario;
	char matricula;
	char marca;
	char modelo;
	char kilometraje;
}ficha;

int main(){
	system("chcp 1252");//Código para que se puedan imprimir letras con tildes
	system("cls");//Código para que no se imprima la línea anterior
	system("COLOR F0");//Código para cambiar el color del fondo (1er dígito) y de las letras (2o digito) (0 = Negro, 1 = Azul, 2 = Verde, 3 = Aqua, 4 = Rojo, 5 = Púrpura, 6 = Amarillo, 7 = Blanco, 8 =Gris, 9 = Azul Claro, A = Luz Verde, B = Aqua Luz, C = Rojo, D = Luz Violeta, E = = Amarillo Claro, F = Blanco Brillante)
	
	int opcion;
	
	printf("DATACOCHES\n\n¿Qué desea hacer?\n\n");
	
	do{
	    printf("TECLA   ACCIÓN\n  1-    Consultar datos sobre un vehículo.\n  2-    Consultar estado de un vehículo.\n  3-    Consultar calendario.\n  4-    Generar nueva cita.\n  5-    Crear nuevo usuario.\n  0-    Salir del programa.\n\n    OPCIÓN: ");
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
			    break;
    		case 5:
	    		printf("NUEVO USUARIO\n\n");
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
	
	
	return 0;
}
