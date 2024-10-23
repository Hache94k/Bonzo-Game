#include <iostream>
#include <cstdlib>
#include <ctime>
#include "misFunciones.h"

using namespace std;


//main principal Bonzo

int main()
{
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

    int np = rondaActual;   //numero Prohibido igual a ronda actual;


    // WHILE PEDIR NOMBRES

    char confirmar = 'n';

    cout << "BONZO"<< endl;
    cout <<"--------------------------------------------------------"<< endl;
    cout <<"Antes de comenzar deben registrar sus nombres:"<<endl;

    while(confirmar != 'S' && confirmar != 's')
    {

        cout << "¿Nombre? ";
        cin >> nj1;
        cout << endl << endl <<"¿Nombre del otro jugador? ";
        cin >> nj2;

        cout << endl << endl << "¿Confirmar nombres? (S/N)" << endl ;
        cin >> confirmar;
        cout << confirmar;
    }


    //while principal
    while(rondaActual <= 6 && j1Juega && j2Juega)
    {
        cout << " ---- RONDA " << rondaActual << " -----" << endl << endl;

        cout << " ---- JUEGA J1 = "<< nj1 << "-----" << endl << endl;

        int juega = 0;
        cout << endl << "J1 desea hacer tirada? Si ( 1 uno) / No (0 cero)" << endl;
        cin >> juega;


        // while j1

        while(juega == 1)
        {

            int tiradaj1 [cdj1];  // array segun cantidad de dados

            for( int x = 0; x < cdj1; x++)
            {

                tiradaj1[x] = tirarDado();
            }

            cout << endl << tiradaj1[0] << endl;
            cout << tiradaj1[1] << endl;
            cout << tiradaj1[2] << endl << endl;

            dibujarTirada(tiradaj1,cdj1);


            cout << "J1 desea hacer tirada? Si ( 1 uno) / No (0 cero)" << endl;
            cin >> juega;

        }

        //Inicia WHILE J2"
        cout << endl << " ---- JUEGA J2 -----" << endl << endl;



        rondaActual++;

    }



    cout << "FIN DEL JUEGO"<< endl;


    return 0;
}
