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

        cout << endl <<"Nombre? ";
        cin >> nj1;
        cout << endl << endl <<"Nombre? ";
        cin >> nj2;

        cout << endl << endl << "Confirmar nombres? (S/N)" << endl ;
        cin >> confirmar;
    }


    //while principal
    while(rondaActual <= 6 && j1Juega && j2Juega)
    {
        system("cls");
        // TABLERO --------------------

        cout << "BONZO" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

        cout << "TURNO DE "<< nj1 << endl << endl;

        cout <<"+---------------------------------+" << endl;
        cout << "RONDA #" << rondaActual << endl;
        cout << "PUNTOS DE LA RONDA: " << endl;
        cout << "LANZAMIENTOS: " << endl;
        cout <<"+---------------------------------+" << endl;


        // while j1


        char continuar = 'S';

        cout << endl <<"Continuar? (S/N)" << endl;
        cin >> continuar;

        while(continuar == 's' || continuar == 'S')
        {
            // TABLERO --------------------
            system("cls");
            cout << "BONZO" << endl;
            cout << "--------------------------------------------------------" << endl;
            cout << nj1 << ": " << ptj1 << " puntos          " << nj2 << ": " << ptj2 << " puntos" << endl << endl;

            cout << "TURNO DE "<< nj1 << endl << endl;

            cout <<"+---------------------------------+" << endl;
            cout << "RONDA #" << rondaActual << endl;
            cout << "PUNTOS DE LA RONDA: " << endl;
            cout << "LANZAMIENTOS: " << endl;
            cout <<"+---------------------------------+" << endl;

            int tiradaj1 [cdj1];  // array segun cantidad de dados

            for( int x = 0; x < cdj1; x++)
            {

                tiradaj1[x] = tirarDado();
            }


            dibujarTirada(tiradaj1,cdj1);

            ptj1 += sumarArray(tiradaj1,cdj1);


            cout << "PUNTAJE TOTAL ACUMULADO: " << ptj1 << endl;




            cout << endl <<"Continuar? (S/N)" << endl;
            cin >> continuar;

        }

        //Inicia WHILE J2"
        cout << endl << " ---- JUEGA J2 -----" << endl << endl;



        rondaActual++;

    }



    cout << "FIN DEL JUEGO"<< endl;


    return 0;
}
