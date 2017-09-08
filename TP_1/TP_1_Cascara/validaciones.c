#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*ESTA FUNCION VALIDA SI ES QUE EL VALOR PASADO EN LA ENTRADA ES NUMERICO
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO*/
int ValidarInt(char Cadena[])
{
    int valido=1;
    int a;
    int control = 0;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if(isdigit(Cadena[a]) == 0)
        {
            control = control + 1;
        }
    }
    if(control > 0)
    {
        valido=0;
    }
    return valido;
}
/*ESTA FUNCION VALIDA QUE EL VALOR INGREADO SEA UN NUMERICO DE TIPO FLOTANTE
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO FLOTANTE*/
int ValidarFloat(char Cadena[])
{
    int valido=1;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if((Cadena[a] !='-') && (Cadena[a] !='.') && (isdigit(Cadena[a]) == 0))
        {
            valido = 0;
            return valido;
        }
    }
    return valido;
}
