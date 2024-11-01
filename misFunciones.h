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




int sumarArray(int arreglo[], int tamanio)
{
    int suma = 0;

    for (int i = 0; i < tamanio; ++i)
    {
        suma += arreglo[i];
    }
    return suma;
}

//DIBUJA RANKING
void dibujarRanking(int posiciones[], int puntajes[], string nombres[], int tamanio)
{
    cout << "PUESTO ---- PUNTAJE ---- NOMBRE" << endl;
    for(int x = 0; x < tamanio ; x++)
    {
        cout <<"  " << posiciones[x] << "           " << puntajes[x] << "         " << nombres[x] << endl << endl;
    }
}


//INCLUYE PUNTAJE Y NOMBRE DEL GANADOR AL RANK
void incluirAlRankDe5(int puntajeGanador, string nombreGanador, int (&puntajes)[5], string (&nombres)[5])
{

    for(int x = 0; x < 5; x++)
    {

        if( puntajeGanador >= puntajes[x])
        {

            if(x != 4)
            {

                for(int i = 4; i> x; i--)
                {
                    puntajes[i] = puntajes[i-1];
                    nombres[i] = nombres[i-1];
                }
                puntajes[x] = puntajeGanador;
                nombres[x] = nombreGanador;
            }
            else
            {
                puntajes[4] = puntajeGanador;
                nombres[4] = nombreGanador;
            }
            break;
        }

    }

}


bool esPar(int nro)
{
    return nro % 2 == 0;
}


//se tira un dado para saber que jugador comienza
void juegaPrimero(string &nj1, string &nj2)
{

    string auxNombre;
    int dado = tirarDado();
    cout<<dibujarDado(dado)<<endl;

    if (esPar(dado))
    {
        //invertimos las variables porque si es par comienza el j2
        auxNombre=nj2;
        nj2= nj1;
        nj1=auxNombre;

        cout<<"TIRAMOS EL DADO Y SALIO UN NUMERO PAR"<<endl;
        cout<<"EL NUMERO ES: "<<dado<<endl;
        cout<<"COMIENZA A JUGAR: "<<nj1<<endl;
        system("pause");

    }
    else
    {

        cout<<"TIRAMOS EL DADO Y SALIO UN NUMERO IMPAR"<<endl;
        cout<<"EL NUMERO ES: "<<dado<<endl;
        cout<<"COMIENZA A JUGAR: "<<nj1<< endl << endl;

        system("pause");

    }

}


void mostrarCreditos()
{

    cout<<"----------------CREDITOS-----------------"<<endl;
    cout<<"NOMBRE DEL EQUIPO: Grupo 6"<<endl;
    cout<<"Nombre           Apellido          Legajo"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Bruno            Berti              31837"<<endl;
    cout<<"Valentina        Gomez              31932"<<endl;
    cout<<"Hernan           Solis              31703"<<endl;
    cout<<"Nicolas          Cubilla            31830"<<endl << endl;

    system("pause");
}


