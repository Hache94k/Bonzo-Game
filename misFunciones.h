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

                for(int i = 4; i > x; i--)
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


    cout<< endl << "TIRAREMOS UN DADO PARA VER QUIEN EMPIEZA, SI ES..." << endl << endl;
    cout<<"IMPAR, INICIA: "<< nj1 << "       PAR, INICIA: " << nj2 << endl << endl << endl << endl;

    system("pause");

    if (esPar(dado))
    {
        //invertimos las variables porque si es par comienza el j2
        auxNombre=nj2;
        nj2= nj1;
        nj1= auxNombre;

        cout << dibujarDado(dado)<<endl;

        cout<<"EL NUMERO ES: "<<dado<<endl << endl;
        cout<<"COMIENZA A JUGAR: "<<nj1<<endl << endl;
        system("pause");

    }
    else
    {
        cout<< endl;
        cout<< endl<< endl << dibujarDado(dado)<<endl;

        cout<<"EL NUMERO ES: "<<dado<<endl << endl;
        cout<<"COMIENZA A JUGAR: "<<nj1<<endl << endl;
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

void mostrarTitulo(){
    cout << "######   #######  ###   ##  #######   #######  " << endl;
    cout << "##   ##  ##   ##  ####  ##      ##    ##   ##  " << endl;
    cout << "######   ##   ##  ##  ####    ##      ##   ##  " << endl;
    cout << "##   ##  ##   ##  ##   ###  ##        ##   ##  " << endl;
    cout << "######   #######  ##    ##  #######   #######  " << endl;
    cout << "---------------------------------------------"<< endl << endl;

}

 // MUESTRA TABLA FINAL ANTES QUE SE CIERRE EL JUEGO BONZO Y VUELVA AL MENU

void mostrarTablaPuntajes(string nj1, int puntos1, int puntosCada50_1, int bonzo1, int mayorLanzamientos1,
                           string nj2, int puntos2, int puntosCada50_2, int bonzo2, int mayorLanzamientos2) {
    cout << "BONZO" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| HITO\t\t\t| " << nj1 << "\t | " << nj2 << "\t |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Puntos\t\t| " << puntos1 << " PTS\t | " << puntos2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Cada 50 puntos\t| " << puntosCada50_1 << " PTS\t | "
         << puntosCada50_2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Bonzo, Ve a dormir\t| " << bonzo1 << " PTS\t | " << bonzo2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Mayor lanzamientos\t| " << mayorLanzamientos1 << " PTS\t | " << mayorLanzamientos2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------------" << endl;

    int total1 = puntos1 + puntosCada50_1 + bonzo1 + mayorLanzamientos1;
    int total2 = puntos2 + puntosCada50_2 + bonzo2 + mayorLanzamientos2;

    cout << "| TOTAL\t\t\t| " << total1 << " PTS\t | " << total2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------------" << endl;

    if (total1 > total2) {
        cout << "GANADOR: " << nj1 << " con " << total1 << " puntos." << endl;
    } else {
        cout << "GANADOR: " << nj2 << " con " << total2 << " puntos." << endl;
    }

    cout << "Ingrese BONZO para continuar: ";
    string input;
    cin >> input;
    while (input != "BONZO" && input != "bonzo") {
        cout << "Ingrese BONZO para continuar: ";
        cin >> input;
    }
}

