using namespace std;


//Devuelve un entero random del 1 al 6

int tirarDado()
{

    return rand() % 6 + 1;
}



//Imprime dado en pantalla segun el numero que se le brinda

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



//Imprime en pantalla todos los dados de la tirada

void dibujarTirada(int arreglo[], int tamanio)
{

    switch(tamanio)
    {

    case 1:
        cout << dibujarDado(arreglo[0]) << endl;
        break;

    case 2:
        cout << dibujarDado(arreglo[0]) << dibujarDado(arreglo[1]) << endl;
        break;

    case 3:
        cout << dibujarDado(arreglo[0]) << dibujarDado(arreglo[1]) << dibujarDado(arreglo[2]) << endl;

        break;
    }


}




int sumarArray(int arreglo[], int tamanio) {
    int suma = 0;

    for (int i = 0; i < tamanio; ++i) {
        suma += arreglo[i];
    }
    return suma;
}



