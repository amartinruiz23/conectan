#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include <cstring>

using namespace std;

void Guardar(const char* archivo, Tablero t, Jugador jug1, Jugador jug2){
  ofstream ofs(archivo);
  ofs << "#MP−CONECTAN−1.0" << endl;
  ofs << jug1 << endl;
  ofs << jug2 << endl;
  ofs << t << endl;
  ofs.close();
}

void Cargar( const char* archivo, Tablero& t, Jugador& jug1, Jugador& jug2){

  ifstream ifs(archivo);
  char nom[200];
  if((ifs.getline(nom, 200) && !(strcmp(nom, "#MP−CONECTAN−1.0")))){
    if(ifs >> jug1)
      if(ifs >> jug2)
        ifs >> t;

  }
}

void DialogoSalvar(Tablero t, Jugador jug1, Jugador jug2){
  char* nom;
  nom = new char[50];
  char recibe;
  cout << "¿Desea guardar la partida? (S/n) ";
  cin >> recibe;
  if (recibe == 's' || recibe == 'S'){
    cout << "Introduzca el nombre del archivo para guardar: ";
    cin >> nom;
    Guardar(nom, t, jug1, jug2);
  }
}

int main(int argc, char* argv[]){
  srand(time(NULL));
  int filas, columnas, alinear, introducir;
  char j1[50], j2[50];
  char leido;
  Jugador jugador1;
  Jugador jugador2;
  bool cargar;

  Tablero tablero;

  cout << "\n~~~Bienvenido a conecta N~~~" << endl;

  if(argc == 2)
   Cargar(argv[1], tablero,  jugador1, jugador2);

  else if (argc == 1){

  cout << "Introduzca filas: ";
  cin >> filas;
  cout << "Introduzca columnas: ";
  cin >> columnas;
  cout << "Introduzca fichas a alinear(3-5): ";
  cin >> alinear;
  while(alinear < 3 || alinear > 5){
    cout << "Número de fichas inválido. Introduzca un número entre 3 y 5: ";
    cin >> alinear;
  }
  cout << "Introduzca cuantas fichas se introducen cada turno: ";
  cin >> introducir;
  while(introducir > alinear - 2 ){
      cout << "Número de fichas inválido. Introduzca un número como máximo " <<  alinear - 2 << ": ";
      cin >> introducir;
  }
  cout << "Introduzca nombre del primer jugador: ";
  cin >> j1;
  cout << "Introduzca nombre del segundo jugador: ";
  cin >> j2;


  Jugador player1(1, j1);
  Jugador player2(2, j2);
  Tablero tab(filas, columnas, alinear, introducir);

  jugador1 = player1;
  jugador2 = player2;
  tablero = tab;

  cout << endl;

}

do{
  do{

    for(int i = 0; i < tablero.FichasTurno() && !tablero.Finalizada(tablero.Turno()); i++){
      if(tablero.Turno() == 1 ){
        while(!jugador1.EscogeColumna(tablero, i+1)){
          cerr << "\nColumna incorrecta. ";
          DialogoSalvar(tablero, jugador1, jugador2);
          cout << "\nSeleccione una columna válida: \n";
          jugador1.EscogeColumna(tablero, i+1);
        }
      }
      else{
        while(!jugador2.EscogeColumna(tablero, i+1)){
          cerr << "\nColumna incorrecta. ";
          DialogoSalvar(tablero, jugador1, jugador2);
          cout << "\nSeleccione una columna válida: \n";
          jugador2.EscogeColumna(tablero, i+1);
        }
      }
    }

  }while(!tablero.Finalizada(tablero.Espera()) && !tablero.Finalizada(tablero.Turno()));


  cout << "FIN\n" << endl;


  tablero.prettyPrint();

  cout << "\nGanador: ";
  if(tablero.Ganador(1) ){
    jugador1.IncrementaGanadas(tablero);
    cout << jugador1.Nombre() << endl;

  }
  else {
    if (tablero.Ganador(2)){
      jugador2.IncrementaGanadas(tablero);
      cout << jugador2.Nombre() << endl;

    }
    else{
      cout << " EMPATE\n";
      jugador1.IncrementaEmpatadas();
      jugador2.IncrementaEmpatadas();

    }
  }

  cout << "¿Desea continuar jugando?(S/n): ";
  cin >> leido;

  tablero.Vacia();

  DialogoSalvar(tablero, jugador1, jugador2);

  cout << endl;

}while(leido == 'S' || leido == 's');

cout << "Resultados finales :\n";

cout << jugador1.Nombre() << " ha ganado " << jugador1.Ganadas() << " partidas con una puntuación de : " << jugador1.Puntuacion() << " puntos.\n";

cout << jugador2.Nombre() << " ha ganado " << jugador2.Ganadas() << " partidas con una puntuación de : " << jugador2.Puntuacion() << " puntos.\n";

cout << "Empates: " << jugador1.Empatadas();

  cout << "\n";

}
