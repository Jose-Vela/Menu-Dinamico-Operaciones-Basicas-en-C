#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define xy gotoxy

void menu();
void navegarMenu(int,int);
float suma(float,float);
float resta(float,float);
float multiplicacion(float,float);
float division(float,float);

void main(){
 menu();
}

// Menú de opciones.
void menu(){
 int x=35, y=10;
 clrscr();
 xy(x-15,y-5);printf(".::OPERACIONES MATEMATICAS BASICAS::.");
 xy(x,y);printf("SUMA");
 xy(x,y+1);printf("RESTA");
 xy(x,y+2);printf("MULTIPLICACION");
 xy(x,y+3);printf("DIVISION");
 xy(x,y+4);printf("SALIR");
 navegarMenu(x,y);
}

// Metodo para navegar en las opciones del menú dinamicamente con las flechas de seleccion arriba y abajo.
void navegarMenu(int x, int y){
	char key;
   int cont = 1;
   float a, b, resultado;
	xy(x-2,y);printf(">");
   do{
   key=getch();   // Capturamos la tecla que presione el usuario con el metodo getch()
		switch(key){
        case 80: // flecha abajo
        	    if(cont < 5){                       // Validamos que la flechita (>) no se pase hacia abajo de las opciones disponibles
        		 	xy(x-2,y);printf("%c",'\0'); y++; // Borramos la flechita (>) de la posicion actual y aumentamos el valor de "y" en 1
               xy(x-2,y);printf(">");cont+=1;    // Imprimimos la flechita (>) en la nueva pasicion y aumentamos el valor de "cont" en 1
             }
             break;
        case 72: // flecha arriba
        		 if(cont > 1){                       // Validamos que la flechita (>) no se pase hacia arriba de las opciones disponibles
               xy(x-2,y);printf("%c",'\0'); y--; // Borramos la flechita (>) de la posicion actual y disminuimos el valor de "y" en 1
               xy(x-2,y);printf(">");cont-=1;    // Imprimimos la flechita (>) en la nueva pasicion y disminuimos el valor de "cont" en 1
             }
             break;
      }
   }while(key != 13);  //el cliclo do termina cuando el usuario presione la tecla "ENTER"

   // Validamos la opcion del usuario con el valor que tenga el contador
   clrscr();
   if(cont == 5) { exit(0); } 										  // Opcion "Salir"
   xy(x-5,y);printf("Numero a: ");scanf("%f", &a);    	     // Pedimos los números para
   xy(x-5,y+1);printf("Numero b: ");scanf("%f", &b);  		  // realizar la operacion seleccionada
   if(cont == 1) { resultado = suma(a,b);}               	  // Opcion "Suma"
   if(cont == 2) { resultado = resta(a,b);}      		  	  	  // Opcion "Resta"
   if(cont == 3) { resultado = multiplicacion(a,b);}     	  // Opcion "Multiplicacion"
   if(cont == 4) { resultado = division(a,b);}           	  // Opcion "Division"

   xy(x-5,y+3);printf("El resultado es %.2f ",resultado);
   getch();                                                   // Mostramos de nuevo el menú de opciones
   menu();
}

// Metodos de las operaciones matemáticas básicas
float suma(float a, float b){ return a+b; }
float resta(float a, float b){ return a-b; }
float multiplicacion(float a, float b){ return a*b; }
float division (float a, float b){ return a/b; }



