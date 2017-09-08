#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funciones.h"
#include "mensajes.h"
#include "operacionesmatematicas.h"
#include "validaciones.h"

/*
UTN-2017
CARRERA: TECNICO EN PROGRAMACION
MATERIA: LABORATORIO I
ALUMNO: CHOQUE ALBORNOZ IVAN EMILIO
CURSO:1E - TN
*/
int main()
{
    /*DECLARAMOS VARIABLES GLOBALES*/
    char Seguir='S';
    char Opcion[]="0";
    int Verificado=0;
    char ValorUno[]="0";
    char ValorDos[]="0";
    float VarUno=0;
    float VarDos=0;

    /*MENU INICIAR
    MIENTRAS LA VARIABLE 'Seguir' DE TIPO CHAR SEA 'S', SE REFRESCARA EL MENU INICIAR
    -COMO VALOR DE ENTRADA LA PANTALLA REQUIERE SELECCIONAR UNA OPCION DEL MENU
    -COMO VALOR DE SALIDA ESTA SELECCION DE DERIVARA A UN SELECTOR PARA EJECUTAR LA OPERACION SOLICITADA*/
    while(Seguir=='S')
    {
        printf("\n*************CALCULADORA N1*************\n\n");
        printf("OPERACIONES:\n");
        printf("            1- Ingresar 1er operando (A=%0.f)\n",VarUno);
        printf("            2- Ingresar 2do operando (B=%0.f)\n",VarDos);
        printf("            3- Calcular la suma (A+B)\n");
        printf("            4- Calcular la resta (A-B)\n");
        printf("            5- Calcular la division (A/B)\n");
        printf("            6- Calcular la multiplicacion (A*B)\n");
        printf("            7- Calcular el factorial (A!)\n");
        printf("            8- Calcular todas las operacione\n");
        printf("            9- Salir\n\n");

        /*
        VALIDAMOS QUE SE INGRESE UN VALOR DE ENTRE LAS OPCIONES DADAS
        -LA VARIABLE DE TIPO 'Aux' CONTRENDRA EN VALOR FORMATEADO A ENTERO COMO VALIDACION DEL VALOR INGRESADO POR EL USUARIO
        */
        long Aux=0;
        do
        {
            printf("\nSELECCIONE UNA OPERACION: ");
            scanf("%s",&Opcion);
            Verificado = ValidarInt(Opcion);
            if(Verificado==1)
            {
                Aux = convertir_cadena_a_entero(Opcion);
                if(Aux>9 || Aux<1)
                {
                    printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
                }
            }
            else
            {
                printf("*_EL VALOR INGRESADO NO ES VALIDO\n");
            }
         }while(Aux>9 || Aux<1);

        /*
        SEGUN EL VALOR INGRESADO SELECCIONAREMOS LA OPERACION A REALIZAR
        */
        switch(Aux)
        {
            case 1: //INGRESAMOS PRIMER VALOR
                {
                    Verificado=0;
                    do{
                        if(VarUno==0)
                        {
                            printf("\nINGRESE VALOR 1er OPERANDO: ");
                        }
                        else
                        {
                            printf("\nVALOR ANTERIOR: %0.f\n",VarUno);
                            printf("\nMODIFICANDO VALOR 1er OPERANDO: ");
                        }
                        scanf("%s",&ValorUno);
                        /*VALIDAMOS QUE SEA ENTERO Y LO CONVERTIMOS A NUMERO*/
                        Verificado = ValidarInt(ValorUno);
                        if(Verificado==1)
                        {
                            VarUno = convertir_cadena_a_entero(ValorUno);
                            printf("VALOR CARGADO! %.0f\n",VarUno);
                        }
                        else
                        {
                            printf("*_EL VALOR INGRESADO NO ES VALIDO");
                        }
                        }while(Verificado==0);
                        /*PREGUNTAMOS SI DESEA SALIR O NO DE LA PANTALLA*/
                        int Resp = MensajeYESNO("Desea continuar operando?");
                        if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                        {
                            Seguir='N';
                        }
                        system("cls");
                        break;
                }
            case 2: //INGRESAMOS SEGUNDO VALOR
                {
                    Verificado=0;
                    do
                        {
                        if(VarDos==0)
                        {
                            printf("\nINGRESE VALOR 2do OPERANDO: ");
                        }
                        else
                        {
                            printf("\nVALOR ANTERIOR: %.0f\n",VarDos);
                            printf("\nMODIFICANDO VALOR 2do OPERANDO: ");
                        }
                        scanf("%s",&ValorDos);
                        /*VALIDAMOS QUE SEA ENTERO Y LO CONVERTIMOS A NUMERO*/
                        Verificado = ValidarInt(ValorDos);
                        if(Verificado==1)
                        {
                            VarDos = convertir_cadena_a_entero(ValorDos);
                            printf("VALOR CARGADO! %.0f\n",VarDos);
                        }
                        else
                        {
                            printf("*_EL VALOR INGRESADO NO ES VALIDO");
                        }
                        }while(Verificado==0);
                        /*PREGUNTAMOS SI DESEA SALIR O NO DE LA PANTALLA*/
                        int Resp = MensajeYESNO("Desea continuar operando?");
                        if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                        {
                            Seguir='N';
                        }
                        system("cls");
                        break;
                }
            case 3: //SUMA
                {
                    /*LLAMAMOS A LA FUNCION QUE SUMARA LAS VARIABLES INGRESADAS*/
                    float suma = Suma(VarUno,VarDos);
                    /*MOSTRAMOS POR PANTALLA EL RESULTADO*/
                    printf("\nRESULTADO: %.0f + %.0f = %.0f",VarUno,VarDos,suma);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 4: //RESTA
                {
                    /*LLAMAMOS A LA FUNCION QUE RESTARA LAS VARIABLES INGRESADAS*/
                    float resta = Resta(VarUno,VarDos);
                    /*MOSTRAMOS POR PANTALLA EL RESULTADO*/
                    printf("\nRESULTADO: %.0f - %.0f = %.0f",VarUno,VarDos,resta);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 5: //DIVICION
                {
                    /*LLAMAMOS A LA FUNCION QUE DIVIDIRA LAS VARIABLES INGRESADAS
                    -VALIDAMOS QUE NO DIVIDA POR CERO*/
                    float dividir = 0;
                    if (VarUno>VarDos)
                    {
                       dividir = Dividir(VarUno,VarDos);
                    }
                    /*MOSTRAMOS POR PANTALLA EL RESULTADO*/
                    printf("\nRESULTADO: %.0f / %.0f = %.2f",VarUno,VarDos,dividir);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 6: //MULTIPLICACION
                {
                    /*LLAMAMOS A LA FUNCION QUE MULTIPLICARA LAS VARIABLES INGRESADAS*/
                    float multiplicar = Multiplicar(VarUno,VarDos);
                    /*MOSTRAMOS POR PANTALLA EL RESULTADO*/
                    printf("\nRESULTADO: %.0f * %.0f = %.0f",VarUno,VarDos,multiplicar);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 7: //FACTORIAL
                {
                    /*LLAMAMOS A LA FUNCION QUE REALIZARA EL FACTORIAL LAS VARIABLES INGRESADAS*/
                    int factorialUno = Factorial(VarUno);
                    int factorialDos = Factorial(VarDos);
                    /*MOSTRAMOS POR PANTALLA EL RESULTADO*/
                    printf("\nRESULTADO:\n      -1er OPERANDO: %.0f! = %d\n      -2do OPERANDO: %.0f! = %d",VarUno,factorialUno,VarDos,factorialDos);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 8: //TODAS LAS OPERACIONES
                {
                    /*LLAMAMOS A LAS FUNCIONES QUE REALIZARAN LAS OPERACIONES MATEMATICAS CON LAS VARIABLES INGRESADAS*/
                    //SUMA
                    float suma = Suma(VarUno,VarDos);
                    printf("\nRESULTADO: %.0f + %.0f = %.0f",VarUno,VarDos,suma);
                    //RESTA
                    float resta = Resta(VarUno,VarDos);
                    printf("\nRESULTADO: %.0f - %.0f = %.0f",VarUno,VarDos,resta);
                    //DIVICION
                    float dividir = 0;
                    if (VarUno>VarDos)
                    {
                       dividir = Dividir(VarUno,VarDos);
                    }
                    printf("\nRESULTADO: %.0f / %.0f = %.2f",VarUno,VarDos,dividir);
                    //MULTIPLICACION
                    float multiplicar = Multiplicar(VarUno,VarDos);
                    printf("\nRESULTADO: %.0f * %.0f = %.0f",VarUno,VarDos,multiplicar);
                    //FACTORIAL
                    int factorialUno = Factorial(VarUno);
                    int factorialDos = Factorial(VarDos);
                    printf("\nRESULTADO:\n      -1er OPERANDO: %.0f! = %d\n      -2do OPERANDO: %.0f! = %d",VarUno,factorialUno,VarDos,factorialDos);
                    /*PREGUNTAMOS SI DESEA SALIR*/
                    int Resp = MensajeYESNO("Desea continuar operando?");
                    if(Resp==0) //SI LA RESPUESTA ES NEGATIVA
                    {
                        Seguir='N';
                    }
                    /*LIMPIAMOS PANTALLA*/
                    system("cls");
                    break;
                }
            case 9: //SALIMOS DE LA PANTALLA
                {
                    Seguir = 'N';
                    break;
                }
        }
    }
    return 0;
}
