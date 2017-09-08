#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0

/*ESTA FUNCION CONVIERTE DE UNA VARIABLE TIPO TEXTO(CHAR) A UNA NUEMRICA(INT)
-VALORES DE ENTREDA: REQUIERE UNA VARIABLE TIPO CHAR PASADA POR VALOR
-VALORES DE SALIDA: DEVUELVE UNA VARIABLE NUMERICA TIPO LONG CON LA CADENA CONVERTIDA, EN CASO DE NO HABERCE PODIDO HABER LLEGADO A REALIZAR LA CONVERCION DEVUELVE CERO*/
int ConvertString_ToInt_Int(const char *cad)
{
    int num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }

    return num;
}

/*ESTA FUNCION CONVIERTE DE UNA VARIABLE TIPO TEXTO(CHAR) A UNA NUEMRICA(LONG)
-VALORES DE ENTREDA: REQUIERE UNA VARIABLE TIPO CHAR PASADA POR VALOR
-VALORES DE SALIDA: DEVUELVE UNA VARIABLE NUMERICA TIPO LONG CON LA CADENA CONVERTIDA, EN CASO DE NO HABERCE PODIDO HABER LLEGADO A REALIZAR LA CONVERCION DEVUELVE CERO*/
long ConvertString_ToInt_Long(const char *cad)
{
    long num = 0;
    int tam  = strlen(cad);  /* Longitud de la cadena recibida */
    int digito;
    int i;

    for (i = tam ; i > 0; --i) {
        digito = (int) (cad[i - 1] - 48);
        num += digito * pow(10.0, tam - i);
    }

    return num;
}
/*ESTA FUNCION CONVIERTE ENTEROS EN TEXTO
-VALORES DE ENTRADA: REQUIERE UNA VARIBLE NUMERICA DE TIPO INTERO
-VALORES DE SALIDA: DEVUELVE UNA VARIBLE DE TIPO CHAR CON EL LA CADENA CONVERTIDA*/
char * ConvertInt_ToString(int num)
{
#define MAX_TAM 80

    char *cad;
    int digito;
    int i = 0;

    cad = (char*) malloc(MAX_TAM * sizeof(char));  /* No olvidar liberar la memoria asignada */
    memcpy(cad, "\0", MAX_TAM);  /* Bruto, pero efectivo :) */

    while (num >= 1) {
        digito = num % 10;

        if (i < MAX_TAM - 1) {
            cad[i] = (char) (digito + 48);
            num -= digito;
            num /= 10;
        }

        ++i;
    }

    /* Pero los dígitos de la cadena han quedado en orden inverso,  */
    /* así que los ordenamos correctamente */

    int  tam = strlen(cad);
    char temp;

    for (i = 0; i < tam / 2; ++i) {
        temp = cad[i];
        cad[i] = cad[tam - i - 1];
        cad[tam - i - 1] = temp;
    }

    return cad;
}

/*ESTA FUNCION CUENTA LA LONGITUD DE LA CADENA PASADA COMO ENTRADA
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALORES DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO CON LA CANTIDAD DE CARACTERES QUE TIENE LA CADENA DE ENTRADA*/
int LengtCadena(char *Cadena)
{
    int a=0;
    while(Cadena[a]!='\0')
    {
        a++;
    }
    return a;
}

/*ESTA FUNCION CONVIERTE ENTEROS EN FLOTENATES
-VALORES DE ENTRADA: REQUIERE UNA VARIBLE  TIPO CHAR PASADA POR VALOR
-VALORES DE SALIDA: DEVUELVE UNA VARIBLE DE TIPO FLOAT CON EL LA CADENA CONVERTIDA*/
float ConvertString_ToFloat(char *Cadena)
{
    float numero=0;
    if(strchr(Cadena,'.'))//strchr devuelve NULL si no encuentra un punto '.'
    {
        if(atof(Cadena)!=0)
        {
            numero=atof(Cadena);
        }
    }
    else
    {
        if(ValidarInt(Cadena)==0)
        {
            numero=atoi(Cadena);
        }
    }
    return numero;
}
