using namespace std;


int tirarDado()
{

    return rand() % 6 + 1;
}


string dibujarDado(int numero)
{
    string dado;

    switch (numero)
    {
    case 1:
        dado =  "+-------+\n"
                "|       |\n"
                "|   o   |\n"
                "|       |\n"
                "+-------+\n";
        break;
    case 2:
        dado =  "+-------+\n"
                "| o     |\n"
                "|       |\n"
                "|     o |\n"
                "+-------+\n";
        break;
    case 3:
        dado =  "+-------+\n"
                "| o     |\n"
                "|   o   |\n"
                "|     o |\n"
                "+-------+\n";
        break;
    case 4:
        dado =  "+-------+\n"
                "| o   o |\n"
                "|       |\n"
                "| o   o |\n"
                "+-------+\n";
        break;
    case 5:
        dado =  "+-------+\n"
                "| o   o |\n"
                "|   o   |\n"
                "| o   o |\n"
                "+-------+\n";
        break;
    case 6:
        dado =  "+-------+\n"
                "| o   o |\n"
                "| o   o |\n"
                "| o   o |\n"
                "+-------+\n";
        break;

    }
    return dado;
}

void dibujarTirada(int arreglo[], int tamanio){

    for( int x = 0; x < tamanio ; x++){
        cout << dibujarDado(arreglo[x]) << endl;
    }
}

/*


int sumarArray(int arreglo[], int tamanio) {
    int suma = 0;

    for (int i = 0; i < tamanio; ++i) {
        suma += arreglo[i];
    }

    return suma;
}

*/


