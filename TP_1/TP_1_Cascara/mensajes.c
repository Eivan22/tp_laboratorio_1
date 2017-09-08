#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*ESTA FUNCION EJECUTA UN MENSAJE CON RESPUESTA YES/NO QUE EL USUARIO DESEEE
-VALORES DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR, LA QUE SE MOSTRARA EN EL CUERPO DEL MENSAJE
-VALORES DE SALIDA: DEVUEVE UNA VARIABLE DE TIPO ENTERO HACIENDO REFERENCIA A LA RESPUESTA DEL USUARIO ANTE EL MENSAJE,
DONDE 0 ES RESPUESTA NEGATIVA Y 1 ES RESPUESTA POSITIVA*/
int MensajeYESNO(char Mensaje[])
{
    char Respuesta;
    printf("\n\n%s S/N",Mensaje);
    scanf(" %s",&Respuesta);
    if((Respuesta=='S') || (Respuesta=='s'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
