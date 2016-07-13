#include <iostream>
#include "tablero.h"
#include "jugador.h"



using namespace std;

int main(){

  int filas, columnas, alinear;
  char j1[MAX_NOMBRE], j2[MAX_NOMBRE];
  char leido;


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
  cout << "Introduzca nombre del primer jugador: ";
  cin >> j1;
  cout << "Introduzca nombre del segundo jugador: ";
  cin >> j2;

  Jugador jugador1(1, j1);
  Jugador jugador2(2, j2);

  Tablero tablero(filas, columnas, alinear);


  cout << "\n";
do{
  do{

    if(tablero.Turno() == 1 )
      jugador1.EscogeColumna(tablero);
    else
      jugador2.EscogeColumna(tablero);

  }while(!tablero.Finalizada(tablero.Espera()));

  cout << "FIN\n" << endl;


  tablero.Imprimir();

  cout << "\nGanador: ";
  if(tablero.Ganador(1) ){
    jugador1.IncrementaGanadas(tablero);
    cout << j1 << endl;

  }
  else {
    if (tablero.Ganador(2)){
      jugador2.IncrementaGanadas(tablero);
      cout << j2 << endl;;

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

}while(leido == 'S' || leido == 's');

cout << "Resultados finales :\n";

cout << j1 << " ha ganado " << jugador1.Ganadas() << " partidas con una puntuación de : " << jugador1.Puntuacion() << " puntos.\n";

cout << j2 << " ha ganado " << jugador2.Ganadas() << " partidas con una puntuación de : " << jugador2.Puntuacion() << " puntos.\n";

cout << "Empates: " << jugador1.Empatadas();

  cout << "\n";
}
