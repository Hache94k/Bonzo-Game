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
    string nombreGanador= "*****";


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
        cout<<"BONZO"<<endl;
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


            bool j1Juega = true; //Bandera para saber si Sigue jugando o Perdi�
            bool j2Juega = true; //Bandera para saber si Sigue jugando o Perdi�


            int rondaActual = 1;  // N� Ronda Actual

            bool inicia=true;

            //numero Prohibido igual a ronda actual;


            // WHILE PEDIR NOMBRES

            char confirmar = 'n';

            cout << "BONZO"<< endl;
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

                cout <<endl << "BONZO" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

                cout << "TURNO DE "<< nj1 << endl << endl;

                cout <<"+---------------------------------+" << endl;
                cout << "RONDA #" << rondaActual << endl;  // MUESTRA RONDA ACTUAL
                cout << "PUNTOS DE LA RONDA: " << endl;
                cout << "LANZAMIENTOS: " << endl;
                cout <<"+---------------------------------+" << endl;


                // while j1


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
                    cout << "BONZO" << endl;
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

                        tiradaj1[x] = tirarDado();

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
                        cout <<"SALIO EL NUMERO PROHIBIDO, PIERDE LOS PUNTOS Y EL TURNO"<<endl;
                        system("pause");
                        break;
                    }
                    //completar
                    if (contProhibidos==2)
                    {
                        cout << "SALIERON DOS NUMEROS PROHIBIDOS" << endl ;

                        puntajeRondaj1=0;
                        bandera2dadosIguales=false;
                        system("pause");
                        break;
                    }
                    //completar
                    if (contProhibidos==3)
                    {
                        cout << nj1<< "HAS PERDIDO" << endl ;
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
                            cout<<"BONZO VE A DORMIR ACTIVADO"<<endl;
                            cout<<"ELIJA UNA DE LAS SIGUIENTES OPCIONES"<<endl;
                            cout<<"1- Quitarle un dado a "<<nj2<<" en la siguiente ronda"<<endl;
                            cout<<"2- Duplicar los puntos de la tirada"<<endl;
                            cin>>opcBonzo;

                            if(opcBonzo==1)
                            {
                                banderaBonzo=false;
                            }
                            else
                            {
                                puntajeTirada=puntajeTirada*2;
                            }
                        }
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
                    cdj2=3;
                }


                //Inicia WHILE J2"
                cout << endl << " ---- JUEGA J2 -----" << endl << endl;



                rondaActual++;  // SUMA 1 RONDA ACTUAL
            }


            // MOSTRAR GANADOR Y PERDEDOR Y MOSTRAR CREDITOS O AGRADECIMIENTOS

            // MOSTRAR TABLA FINAL

            // ADICIONAR EL GANAR AL ARRAY DE GANADORES


            if((j1Juega && !j2Juega) || (ptj1 > ptj2))
            {

                puntajeGanador = ptj1;
                nombreGanador= nj1;
            }
            else
            {
                puntajeGanador = ptj2;
                nombreGanador= nj2;
            }

            // FORMULA METE AL ULTIMO GANADOR AL RANKING EN CASO DE CORRESPONDER
            incluirAlRankDe5(puntajeGanador, nombreGanador, puntajes, nombres);





            cout << "FIN DEL JUEGO"<< endl;

            // TABLA DE POSICION

            /*

            string bonzo= "";
            // le pedimos que escriba bonzo al usuario

            while(bonzo != "bonzo" || bonzo != "BONZO")
            {
                // le pedimos que escriba bonzo al usuario

            }


            */


            system("pause");
            break;

        }




        case 2:
        {

            system("cls");

            //ACTUALIZAR PUNTAJE Y NOMBRE DEL ULTIMO JUGADOR

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

            // MUESTRA CREDITOS
            mostrarCreditos();

            break;
        }


        case 0:
        {
            system("cls");
            cout<<" ESTA SEGURO DE QUE DESEA SALIR DEL JUEGO? (S/N) MAYUSCULA"<<endl;
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

