#include <iostream>
#include <cstdlib>
#include <ctime>
#include "misFunciones.h"

using namespace std;


//main principal Bonzo

int main()
{

    //DECLARACIONES FUNCIONALES

    int opc;

    char confirmar;

    bool salida= false;


    //  DECLARACIONES RANK

    int puntajeGanador = 0;
    string nombreGanador= "*";


    // RANKING
    int posiciones[5];
    int puntajes[5];
    string nombres[5];

    posiciones[0] = 1;
    puntajes[0] = 90;
    nombres[0] = "VALENTINA";

    posiciones[1] = 2;
    puntajes[1] = 80;
    nombres[1] = "NICOLAS";

    posiciones[2] = 3;
    puntajes[2] = 70;
    nombres[2] = "BRUNO";

    posiciones[3] = 4;
    puntajes[3] = 60;
    nombres[3] = "HERNAN";

    posiciones[4] = 5;
    puntajes[4] = 50;
    nombres[4] = "MAXIMILIANO";



    //BUCLE DEL MENU INFINITO HASTA QUE EL USUARIO QUIERA SALIR DEL PROGRAMA ENTERO

    while(!salida)
    {
        system("cls");

        mostrarTitulo();
        cout<<"---------------------"<<endl;
        cout<<"1 - JUGAR"<<endl;
        cout<<"2 - ESTADISTICAS"<<endl;
        cout<<"3 - CREDITOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0 - SALIR"<<endl<<endl;
        cout<<"INGRESE LA OPCION QUE DESEA ELEGIR"<<endl;
        cin>>opc;

        switch(opc)
        {
        case 1:
        {
            system("cls");

            // funciones de las librerias para poder generar n RANDOMS
            void srand(unsigned int seed);
            time_t time(time_t* t);
            srand(time(NULL));


            // Inicializar variables principales

            string nj1; //nombre j1
            string nj2; //nombre j2

            int cdj1 = 3;   //cantidad dados que posee j1
            int cdj2 = 3;   //cantidad dados que posee j2

            int ptj1 = 0;    //Acumulador puntaje total j1
            int ptj2 = 0;    //Acumulador puntaje total j1


            bool j1Juega = true; //Bandera para saber si Sigue jugando o Perdió
            bool j2Juega = true; //Bandera para saber si Sigue jugando o Perdió


            int rondaActual = 1;  // N° Ronda Actual

            bool inicia=true;
            int bandPrueba=0;
            int bandPruebaj1=0;


            int mayorLanzamientos1= 0;
            int mayorLanzamientos2= 0;

            int conBonzo1 = 0;
            int conBonzo2 = 0;

            //numero Prohibido igual a ronda actual;


            // WHILE PEDIR NOMBRES

            char confirmar = 'n';

            mostrarTitulo();
            cout <<"--------------------------------------------------------"<< endl;
            cout <<"Antes de comenzar deben registrar sus nombres:"<<endl;

            while(confirmar != 'S' && confirmar != 's')
            {

                cout << endl <<"Nombre? ";
                cin >> nj1;
                cout << endl << endl <<"Nombre? ";
                cin >> nj2;

                cout << endl << endl << "Confirmar nombres? (S/N)" << endl ;
                cin >> confirmar;
                system ("cls");


            }

            mostrarTitulo();
            //se tira un dado para saber que jugador comienza
            juegaPrimero(nj1,nj2);

            system("cls");


            //while principal
            while(rondaActual <= 6 && j1Juega && j2Juega)
            {
                bool bandera2dadosIguales= true;
                bool banderaBonzo=true;
                int puntajeRondaj1 = 0; // acumulador de los puntajes de cada tirada en una ronda
                int puntajeRondaj2 = 0; // acumulador de los puntajes de cada tirada en una ronda
                system("cls");


                // TABLERO --------------------

                mostrarTitulo();
                cout << "--------------------------------------------------------" << endl;
                cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

                cout << "TURNO DE "<< nj1 << endl << endl;

                cout <<"+---------------------------------+" << endl;
                cout << "RONDA #" << rondaActual << endl;  // MUESTRA RONDA ACTUAL
                cout << "PUNTOS DE LA RONDA: " << endl;
                cout << "LANZAMIENTOS: " << endl;
                cout <<"+---------------------------------+" << endl;


                // while j1

                bandPruebaj1=0;
                system("cls");

                cout << endl << " ----- JUEGA " << nj1 << " -----" << endl << endl;


                char continuar = 'S';

                cout << endl <<"Continuar? (S/N)" << endl;
                cin >> continuar;

                int lanzamiento = 0; // CONTADOR DE LANZAMIENTOS
                int contProhibidos = 0;



                while(continuar == 's' || continuar == 'S')
                {
                    int puntajeTirada = 0;   //suma el valor de cantidaddados por tirada
                    // TABLERO --------------------
                    system("cls");
                    mostrarTitulo();
                    cout << "--------------------------------------------------------" << endl;
                    cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

                    cout << "TURNO DE "<< nj1 << endl << endl;

                    cout <<"+---------------------------------+" << endl;
                    cout << "RONDA #" << rondaActual << endl;
                    cout << "PUNTOS DE LA RONDA: " << puntajeRondaj1<< endl;
                    cout << "LANZAMIENTOS: " << lanzamiento << endl;
                    cout <<"+---------------------------------+" << endl;

                    int tiradaj1 [cdj1];  // array segun cantidad de dados

                    for( int x = 0; x < cdj1; x++)
                    {

                        tiradaj1[x] = tirarDado();  // POR CADA POSICION LE GENERA 1 NUM RANDOM
                        if (tiradaj1[x] == rondaActual)
                        {
                            contProhibidos++;
                        }
                    }

                    lanzamiento++;  // SUMA 1 LANZAMIENTO

                    cout<<"El numero prohibido es: "<<rondaActual<<endl <<endl;
                    cout <<"lanzamiento #" << lanzamiento << endl << endl;

                    dibujarTirada(tiradaj1,cdj1);


                    puntajeTirada = sumarArray(tiradaj1,cdj1);

                    //aca es donde vamos accionar segun salga 1, 2 o 3 dados prohibidos

                    if (contProhibidos==1)
                    {
                        puntajeRondaj1=0; //esto es para que no se sumen los puntos de la ronda en el contador total
                        cout <<"SALIO EL NUMERO PROHIBIDO, PIERDE LOS PUNTOS Y EL TURNO"<<endl << endl;
                        system("pause");
                        break;
                    }
                    //
                    if (contProhibidos==2)
                    {
                        cout << "SALIO DOS VECES EL NUMERO PROHIBIDO" << endl << endl ;
                        cout << "PIERDES LOS PUNTOS DE LA RONDA" << endl << endl;

                        if(cdj1 == 3)
                        {
                            bandera2dadosIguales = false;
                            cout << "PIERDES 1 DADO PARA LA SIGUIENTE RONDA" << endl << endl;
                        }

                        cout << "PIERDES EL TURNO" << endl << endl;

                        puntajeRondaj1 = 0;



                        system("pause");
                        break;
                    }
                    //
                    if (contProhibidos==3)
                    {
                        cout << nj1<< " HAS PERDIDO" << endl ;
                        puntajeRondaj1=0;
                        puntajeTirada=0;
                        ptj1=0;
                        j1Juega = false;

                        system("pause");
                        break;
                    }


                    //BONZO VE A DORMIR:

                    int opcBonzo=0;

                    if(tiradaj1[0]==tiradaj1[1]&&tiradaj1[1]==tiradaj1[2])
                    {
                        if(tiradaj1[2]!=rondaActual)
                        {
                            conBonzo1++;
                            cout<<"BONZO VE A DORMIR ACTIVADO"<<endl;
                            cout<<"ELIJA UNA DE LAS SIGUIENTES OPCIONES"<<endl;
                            cout<<"1- Quitarle un dado a "<<nj2<<" en la siguiente ronda"<<endl;
                            cout<<"2- Duplicar los puntos de la tirada"<<endl;
                            cin>>opcBonzo;

                            if(opcBonzo==1)
                            {
                                if(cdj2 == 3)
                                {
                                    banderaBonzo=false;
                                }
                                else
                                {
                                    cout << "Tu rival ya tiene 1 dado menos, seguirá con 2 dados.. " << endl << endl;
                                }
                            }
                            else
                            {
                                puntajeTirada=puntajeTirada*2;
                            }
                        }
                    }


                    // CONTADOR MAYOR LANZAMIENTO J1  /////

                    if(contProhibidos == 0 && mayorLanzamientos1 < lanzamiento)
                    {
                        mayorLanzamientos1 = lanzamiento;
                    }




                    puntajeRondaj1+=puntajeTirada;  // se suman las tiradas en un acumulador de ronda

                    cout << "SUMASTE " << puntajeTirada << " PUNTOS " <<endl;

                    cout << endl <<"Continuar? (S/N)" << endl;

                    cin >> continuar;

                }
                ptj1 += puntajeRondaj1;   //aca se suma el puntaje de la ronda en el acumulador total


                //resolucion de 2 dados iguales

                if(!bandera2dadosIguales)
                {
                    cdj1-=1;
                    bandera2dadosIguales=true;
                    bandPruebaj1=1;
                }
                else
                {
                    cdj1=3;
                }

                //resolucion BONZO VE A DORMIR opcion 1

                if(!banderaBonzo)
                {
                    cdj2-=1;
                    banderaBonzo=true;
                }
                else
                {
                    if(bandPrueba==0)
                    {
                        cdj2=3;
                    }

                }

                ///////////////////////////////////////////////////////////////////////////////////////////////////
                //Inicia WHILE J2"
                system("cls");

                cout << endl << " ----- JUEGA " << nj2 << " -----" << endl << endl;

                // while j2

                bandPrueba = 0;
                continuar = 'S';

                cout << endl <<"Continuar? (S/N)" << endl;
                cin >> continuar;

                lanzamiento = 0; // CONTADOR DE LANZAMIENTOS
                contProhibidos = 0;


                while(continuar == 's' || continuar == 'S')
                {
                    int puntajeTirada = 0;   //suma el valor de cantidaddados por tirada
                    // TABLERO --------------------
                    system("cls");
                    mostrarTitulo();
                    cout << "--------------------------------------------------------" << endl;
                    cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

                    cout << "TURNO DE "<< nj2 << endl << endl;

                    cout <<"+---------------------------------+" << endl;
                    cout << "RONDA #" << rondaActual << endl;
                    cout << "PUNTOS DE LA RONDA: " << puntajeRondaj2<< endl;
                    cout << "LANZAMIENTOS: " << lanzamiento << endl;
                    cout <<"+---------------------------------+" << endl;

                    int tiradaj2 [cdj2];  // array segun cantidad de dados

                    for( int x = 0; x < cdj2; x++)
                    {

                        tiradaj2[x] = tirarDado();

                        if (tiradaj2[x] == rondaActual)
                        {
                            contProhibidos++;
                        }
                    }

                    lanzamiento++;  // SUMA 1 LANZAMIENTO

                    cout<<"El numero prohibido es: "<<rondaActual<<endl <<endl;
                    cout <<"lanzamiento #" << lanzamiento << endl << endl;

                    dibujarTirada(tiradaj2,cdj2);


                    puntajeTirada = sumarArray(tiradaj2,cdj2);

                    //aca es donde vamos accionar segun salga 1, 2 o 3 dados prohibidos

                    if (contProhibidos ==1)
                    {

                        puntajeRondaj2 = 0; //esto es para que no se sumen los puntos de la ronda en el contador total
                        cout <<"SALIO EL NUMERO PROHIBIDO, PIERDE LOS PUNTOS Y EL TURNO"<<endl << endl;
                        system("pause");
                        break;
                    }
                    //
                    if (contProhibidos == 2)
                    {
                        cout << "SALIO DOS VECES EL NUMERO PROHIBIDO" << endl << endl ;
                        cout << "PIERDES LOS PUNTOS DE LA RONDA" << endl << endl;

                        if(cdj2 == 3)
                        {
                            bandera2dadosIguales = false;
                            cout << "PIERDES 1 DADO PARA LA SIGUIENTE RONDA" << endl << endl;
                        }

                        cout << "PIERDES EL TURNO" << endl << endl;

                        puntajeRondaj2 = 0;



                        system("pause");
                        break;
                    }
                    //
                    if (contProhibidos == 3)
                    {
                        cout << nj2<< " HAS PERDIDO" << endl ;
                        puntajeRondaj2=0;
                        puntajeTirada=0;
                        ptj2=0;
                        j2Juega = false;

                        system("pause");
                        break;
                    }


                    //BONZO VE A DORMIR:

                    int opcBonzo=0;

                    if(tiradaj2[0]==tiradaj2[1]&&tiradaj2[1]==tiradaj2[2])
                    {
                        if(tiradaj2[2]!=rondaActual)
                        {
                            conBonzo2++;
                            cout<<"BONZO VE A DORMIR ACTIVADO"<<endl;
                            cout<<"ELIJA UNA DE LAS SIGUIENTES OPCIONES"<<endl;
                            cout<<"1- Quitarle un dado a "<<nj1<<" en la siguiente ronda"<<endl;
                            cout<<"2- Duplicar los puntos de la tirada"<<endl;
                            cin>>opcBonzo;

                            if(opcBonzo==1)
                            {
                                if(cdj1 == 3)
                                {
                                    banderaBonzo=false;
                                }
                                else
                                {
                                    cout << "Tu rival ya tiene 1 dado menos, seguirá con 2 dados.. " << endl << endl;
                                }
                            }
                            else
                            {
                                puntajeTirada=puntajeTirada*2;
                            }
                        }
                    }


                    // CONTADOR MAYOR LANZAMIENTO J2  /////

                    if(contProhibidos == 0 && mayorLanzamientos2 < lanzamiento)
                    {
                        mayorLanzamientos2 = lanzamiento;
                    }

                    puntajeRondaj2 += puntajeTirada;  // se suman las tiradas en un acumulador de ronda

                    cout << "SUMASTE " << puntajeTirada << " PUNTOS " <<endl;

                    cout << endl <<"Continuar? (S/N)" << endl;

                    cin >> continuar;

                }



                ptj2 += puntajeRondaj2;   //aca se suma el puntaje de la ronda en el acumulador total


                //resolucion de 2 dados iguales

                if(!bandera2dadosIguales)
                {
                    cdj2-=1;
                    bandera2dadosIguales=true;
                    bandPrueba = 1;
                }
                else
                {
                    cdj2=3;
                }

                //resolucion BONZO VE A DORMIR opcion 1

                if(!banderaBonzo)
                {
                    cdj1-=1;
                    banderaBonzo=true;

                }
                else
                {
                    if(bandPruebaj1==0)
                    {
                        cdj1=3;
                    }

                }


                rondaActual++;  // SUMA 1 RONDA ACTUAL
            }







            /////////////////////////////////////////////////////////////////////////////////////////////////////////



            // HITOS - POR EJE, SI TAL PERSONA HIZO MAS BONZOS QUE EL OTRO SUMA TANTOS PUNTOS
            // SUMATORIAS POR HITOS





            // TABLA FINAL /////////////////
            system("pause");
            system ("cls");



            // CALCULO PUNTAJE + 50 J1
            int cada50pts1=0;
            if (ptj1<50)
            {
                cada50pts1=0;
            }
            else
            {
                cada50pts1=((int)ptj1/50)*3;
            }


            // CALCULO PUNTAJE + 50 J2

            int cada50pts2=0;

            if (ptj2<50)
            {
                cada50pts2=0;
            }
            else

            {
                cada50pts2=((int)ptj2/50)*3;
            }


            // calculo puntajes adicionales finales



            int bonzo1=0;
            int bonzo2=0;

            bonzo1 = conBonzo1 * 5;
            bonzo2 = conBonzo2 * 5;


            int puntajeMayorLanzamiento = 5;


            int puntajeTotal1 =0;
            int puntajeTotal2 =0;



            if(mayorLanzamientos1 > mayorLanzamientos2)
            {

                puntajeTotal1 = ptj1 + cada50pts1 + bonzo1  + puntajeMayorLanzamiento;
                puntajeTotal2 = ptj2 + cada50pts2 + bonzo2;
            }
            else if(mayorLanzamientos1 == mayorLanzamientos2)
            {
                puntajeTotal1 = ptj1 + cada50pts1 + bonzo1 + puntajeMayorLanzamiento;
                puntajeTotal2 = ptj2 + cada50pts2 + bonzo2 + puntajeMayorLanzamiento;
            }
            else
            {
                puntajeTotal1 = ptj1 + cada50pts1 + bonzo1;
                puntajeTotal2 = ptj2 + cada50pts2 + bonzo2 + puntajeMayorLanzamiento;
            }



            // CALCULAR EL GANADOR Y DESICION DE QUIEN GANÓ


            if((j1Juega && !j2Juega) || (puntajeTotal1 > puntajeTotal2))
            {

                puntajeGanador = puntajeTotal1;
                nombreGanador= nj1;
            }
            else if( (j1Juega && j2Juega) && (puntajeTotal1 == puntajeTotal2))
            {

                //  SEGUN QUIEN TIENE MAS BONZO VE A DORMIR GANA, SINO EMPATE

                if( bonzo1 > bonzo2)
                {
                    puntajeGanador = puntajeTotal1;
                    nombreGanador= nj1;
                }
                else if( bonzo1 == bonzo2 )
                {
                }
                else
                {
                    puntajeGanador = puntajeTotal2;
                    nombreGanador= nj2;
                }

            }
            else
            {
                puntajeGanador = puntajeTotal2;
                nombreGanador= nj2;
            }




            // SE MUESTRA TABLERO FINAL

            dibujarTabla(nj1, ptj1,cada50pts1,bonzo1,mayorLanzamientos1,puntajeTotal1, nj2, ptj2,cada50pts2,bonzo2,mayorLanzamientos2, puntajeTotal2, puntajeGanador, nombreGanador);



            // FORMULA METE AL ULTIMO GANADOR AL RANKING EN CASO DE CORRESPONDER
            incluirAlRankDe5(puntajeGanador, nombreGanador, puntajes, nombres);



            // BONZO PARA SALIR

            cout << endl << endl << "Ingrese BONZO para salir: " << endl << endl;
            string salirBonzo= "";
            cin >> salirBonzo;
            while(salirBonzo != "BONZO" && salirBonzo != "bonzo")
            {
                cout << "Ingrese BONZO para salir: ";
                cin >> salirBonzo;
            }



            cout << endl << endl << "----------- FIN DEL JUEGO -----------"<< endl << endl;

            system("pause");
            break;

        }




        case 2:
        {

            system("cls");

            //ACTUALIZAR PUNTAJE Y NOMBRE DEL ULTIMO JUGADOR

            mostrarTitulo();

            cout << "----------------ESTADISTICAS DEL GANADOR DEL ULTIMO JUEGO----------------" << endl << endl;
            cout << "PUNTAJE ---- NOMBRE"<< endl << endl;
            cout << "  " << puntajeGanador << "          " << nombreGanador << endl << endl;


            cout << "----------------RANKING----------------" << endl << endl;




            // DIBUJA RANKING;
            dibujarRanking(posiciones, puntajes, nombres, 5);

            system("pause");
            break;
        }


        case 3:
        {
            system("cls");

            mostrarTitulo();

            // MUESTRA CREDITOS
            mostrarCreditos();

            break;
        }


        case 0:
        {
            system("cls");
            cout<<" ESTA SEGURO DE QUE DESEA SALIR DEL JUEGO?"<<endl;
            cin>>confirmar;
            if(confirmar =='S' || confirmar == 's')
            {
                salida = true;

            }
            break;
        }


        default:
        {
            cout<<"La opcion elegida no corresponde a una valida"<<endl;
            system("pause");
        }

        }
    }
    return 0;
}
