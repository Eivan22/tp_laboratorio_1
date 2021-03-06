#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*ESTA FUNCION SUMA DOS VALORES INGRESADOS POR EL USUARIO
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE SUMARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA SUMA*/
float Suma(float ValorOne, float ValorTwo)
{
    return ValorOne+ValorTwo;
}
/*ESTA FUNCION RESTA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA SE RESTARA DE LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA RESTA*/
float Resta(float ValorOne, float ValorTwo)
{
    return ValorOne-ValorTwo;
}
/*ESTA FUNCION DIVIDE DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, DE LAS CUALES LA SEGUNDA DIVIDE A LA PRIMERA
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA DIVICION*/
float Dividir(float ValorOne, float ValorTwo)
{
    if(ValorTwo<1)
    {
        return 0;
    }
    else
    {
        return ValorOne/ValorTwo;
    }
}
/*ESTA FUNCION MULTIPLICA DOS VALORES INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: DOS VARIABLES NUMERICAS DE TIPO FLOTANTE, LAS CUALES SE MULTIPLICARAN
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DE LA MULTIPLICACION*/
float Multiplicar(float ValorOne, float ValorTwo)
{
    return ValorOne*ValorTwo;
}
/*ESTA FUNCION FACTORIZA UN VALOR INGRESADOS POR EL USUARIOS
-VALORES DE ENTRADA: UNA VARIABLE NUMERICAS DE TIPO FLOTANTE, LA CUAL SE CALCULARA EL FACTORIAL
-VALORES DE SALIDA: RETORNA UNA VARIBLE NUMERICA DE TIPO FLOTANTE CON EL RESULTADO DEL FACTORIAL*/
int Factorial(float *Valor)
{
    int aux=0;
    int factor= 1;
    for (aux = Valor; aux > 1; aux--)
    {
        factor = factor * aux;
    }
    return factor;
}
