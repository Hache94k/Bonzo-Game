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

void dibujarTirada(int arreglo[], int tamanio)  // TOMA COMO PARAMETRO EL ARREGLO QUE CORRESPONDE A LA CANTIDAD DE DADOS DE LA TIRADA SEGUND LA CANTIDAD DE DADOS QUE POSEE
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

void mostrarTitulo()
{
    cout << "######   #######  ###   ##  #######   #######  " << endl;
    cout << "##   ##  ##   ##  ####  ##      ##    ##   ##  " << endl;
    cout << "######   ##   ##  ##  ####    ##      ##   ##  " << endl;
    cout << "##   ##  ##   ##  ##   ###  ##        ##   ##  " << endl;
    cout << "######   #######  ##    ##  #######   #######  " << endl;
    cout << "---------------------------------------------"<< endl << endl;

}

// MUESTRA TABLA FINAL ANTES QUE SE CIERRE EL JUEGO BONZO Y VUELVA AL MENU


void dibujarTabla(string nj1, int ptj1, int cada50pts1, int bonzo1, int mayorLanzamientos1,int puntajeTotal1,
                  string nj2, int ptj2, int cada50pts2, int bonzo2, int mayorLanzamientos2,int puntajeTotal2, int puntajeGanador, string nombreGanador)
{
    mostrarTitulo();
    cout << "--------------------------------------------------" << endl;
    cout << "| HITO\t\t\t| " << nj1 << "\t | " << nj2 << "\t  |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| Puntos\t\t| " << ptj1 << " PTS\t | " <<ptj2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| Cada 50 puntos\t| " << cada50pts1 << " PTS (" << (ptj1 / 50) << ")\t   | "
         << cada50pts2 << " PTS (" << ptj2 / 50 << ")\t |" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "| Bonzo, Ve a dormir\t| " << bonzo1 << " PTS (" << bonzo1 / 5 << ")\t   | " << bonzo2 << " PTS (" << bonzo2 / 5 << ")\t |" << endl;
    cout << "--------------------------------------------------" << endl;


    if( mayorLanzamientos1 > mayorLanzamientos2){
        cout << "| Mayor lanzamientos\t| " << "5 PTS ("s << mayorLanzamientos1 << ")" << " \t | " << "0 PTS (" <<mayorLanzamientos2 << ")\t |" << endl;
    }else if(mayorLanzamientos1 == mayorLanzamientos2){
        cout << "| Mayor lanzamientos\t| " << "5 PTS (" << mayorLanzamientos1 << ")" << " \t | " << "5 PTS (" <<mayorLanzamientos2 << ")\t |" << endl;
    }else{
        cout << "| Mayor lanzamientos\t| " << "0 PTS (" << mayorLanzamientos1 << ")" << " \t | " << "5 PTS (" <<mayorLanzamientos2 << ")\t |" << endl;
    }


    cout << "--------------------------------------------------" << endl;



    cout << "| TOTAL\t\t\t| " << puntajeTotal1 << " PTS\t | " << puntajeTotal2 << " PTS\t |" << endl;
    cout << "--------------------------------------------------" << endl;


    if(nombreGanador == "*"){

        cout << endl << endl << "NO HUBO GANADOR !!!" << endl << endl << endl;
    }else {
        cout << endl << endl << "GANADOR: " << nombreGanador << " con " << puntajeGanador << " puntos." << endl << endl;
    }



    cout << "Ingrese BONZO para continuar: ";
    string input;
    cin >> input;
    while (input != "BONZO" && input != "bonzo")
    {
        cout << "Ingrese BONZO para continuar: ";
        cin >> input;
    }
}
