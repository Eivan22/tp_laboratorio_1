#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*ESTA FUNCION VALIDA SI ES QUE EL VALOR PASADO EN LA ENTRADA ES NUMERICO
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO ENTERO: 0=TRUE 1:FALSE*/
int ValidarInt(char *Cadena[])
{
    int valido = 0;
    int control = 0;
    int control2 = 0;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if(isdigit(Cadena[a])==0)
        {
            control2=atoi(Cadena);
            control = control + 1;
        }
    }
    if(control2 == 0)
    {
        valido=1;
    }
    return valido;
}
/*ESTA FUNCION VALIDA QUE EL VALOR INGREADO SEA UN NUMERICO DE TIPO FLOTANTE
-VALOR DE ENTRADA: REQUIERE UNA CADENA DE TIPO CHAR
-VALOR DE SALIDA: ENTREGA UN NUMERICO DE TIPO FLOTANTE*/
int ValidarFloat(char *Cadena[])
{
    int valido=0;
    int CantSignos=0;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if((Cadena[a] =='.')||(Cadena[a] ==','))
        {
            CantSignos++;
        }
        if((Cadena[a] !='-'&&a>0) && (Cadena[a] !='.') && (Cadena[a] !=',') && (isdigit(Cadena[a]) != 0))
        {
            valido = 1;
        }
    }
    return valido;
}
/*ESTA FUNCION VALIDA QUE EL LARGO DE LA CADENA INGREADA SEA DEL TAMAÑO DESEADO
-VALOR DE ENTRADA: REQUIERE UNA CADENA Y EL LARGO MAXIMO QUE SE ESPERA
-VALOR DE SALIDA: ENTREGA UN "0" SI ES VALIDA O "1" SINO*/
int ValidarLengthMax(char *Cadena[],int Length_Max)
{
    int valido=0;
    if (LengtCadena(Cadena)>Length_Max)
    {
        valido = 1;
        return valido;
    }
    return valido;
}
/*ESTA FUNCION VALIDA SI LA CADENA INGRESADA CORRESPONDE A UN NUMERO
-VALOR DE ENTRADA: REQUIERE UNA CADENA
-VALOR DE SALIDA: ENTREGA UN "0" SI ES VALIDA O "1" SINO*/
int ValidarIsNumero(char *Cadena)
{
    int valido = 0; //0:true
    int CantSignos = 0;
    int a;
    for (a=0;a<LengtCadena(Cadena);a++)
    {
        if(atof(Cadena[a])==0)
        {
            printf(">>ATIO_no");
            /*printf(">>IF1:%d",1);
            if(ConvertInt_ToString(Cadena[a])=='.' || ConvertInt_ToString(Cadena[a])==',')
            {
                printf(">>CANTSIGNOS:%d",1);
                CantSignos=CantSignos++;
                if(CantSignos > 1)
                {
                    valido=1;
                    return valido;
                }
            }
            printf(">>IF2:%d",1);
            if(Cadena[a]=='-' && a>0)
            {
                valido=1;
                return valido;
            }*/
        }
        else
        {
            printf(">>ATIO_isnumbre");
            /*if(atoi(Cadena[a])!=0)
            {
                valido=1;
                return valido;
            }*/
        }
    }
    printf(">>VALIDO:%d",valido);
    return valido;
}
/*ESTA FUNCION VALIDA QUE LA CADENA INGREADA SEA DEL RANGO DE OPCIONES DESEADAS
-VALOR DE ENTRADA: REQUIERE UNA CADENA, EL VALOR MINIMO DE OPCION Y EL VALOR MAXIMO DE OPCIONES
-VALOR DE SALIDA: ENTREGA UN "0" SI ES VALIDA O "1" SINO*/
int ValidarOpcionesInt(char *Cadena,int MinOpcion,int MaxOpcion)
{
    int rango=0;
    int valido=0;
    rango=LengtCadena(ConvertInt_ToString(MaxOpcion));
    if(LengtCadena(ConvertInt_ToString(MinOpcion))<LengtCadena(ConvertInt_ToString(MaxOpcion)))
    {
        rango=LengtCadena(ConvertInt_ToString(MinOpcion));
    }
    if (ValidarLengthMax(Cadena,rango)>0) //VALIDO POR LARGO DEL STRING
    {
        valido = 1;
    }
    else
    {
        //VALIDO POR INTERO
        if (ValidarInt(Cadena)>0)
        {
            valido = 1;
        }
        else
        {
            //VALIDO POR RANGO
            if ((ConvertString_ToInt_Int(Cadena) < MinOpcion)||(ConvertString_ToInt_Int(Cadena) > MaxOpcion))
            {
                //printf("->VALIDO POR RANGO:%d",1);
                valido = 1;
            }
        }
    }
    return valido; //0=OK ,1=ERROR
}
