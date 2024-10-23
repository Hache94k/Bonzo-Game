#include <iostream>
#include <cstdlib>
#include <ctime>
#include "misFunciones.h"


using namespace std;


int main()
{
    void srand(unsigned int seed);
    time_t time(time_t* t);
    srand(time(NULL));

    string nj1; //nombre j1
    string nj2; //nombre j2

    int cdj1 = 3;   //cantidad dados que posee j1
    int cdj2 = 3;   //cantidad dados que posee j2

    int ptj1 = 0;    //puntaje total j1
    int ptj2 = 0;    //puntaje total j1


    bool j1Juega = true;
    bool j2Juega = true;


    int rondaActual = 1;

    int np = rondaActual;   //numero Prohibido igual a ronda actual;






    while(rondaActual <= 6 && j1Juega && j2Juega)
    {
        cout << " ---- RONDA " << rondaActual << " -----" << endl << endl;

        cout << " ---- JUEGA J1 -----" << endl << endl;

        int juega = 0;
        cout << endl << "J1 desea hacer tirada? Si ( 1 uno) / No (0 cero)" << endl;
        cin >> juega;


        while(juega == 1)
        {
            int tiradaj1 [cdj1];

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

        cout << endl << " ---- JUEGA J2 -----" << endl << endl;

        rondaActual++;

    }





    return 0;
}
