#include "jugador.h"
#include "tablero.h"

using namespace std;


Jugador::Jugador(int turn, char nombr[]){
  for(int i = 0; i < 50; i++)
    nombre[i] = nombr[i];
  turno = turn;
}

int Jugador::Turno(){
  return turno;
}

int Jugador::PedirColumna(Tablero &tablero){
  char columna;
  tablero.Imprimir();

  cout << "\nColumna para colocar ficha:";
  cin >> columna;
  cout << endl;
  return columna-'a';

}
int Jugador::PedirColumnaError(Tablero &tablero){
  char columna;
  ImprimirTurno();
  tablero.Imprimir();


  cout << "\nColumna incorrecta. Seleccione una columna válida: ";
  cin >> columna;
  cout << endl;
  return columna-'a';

}
void Jugador::ImprimirTurno(){
  for(int i = 0; i < 50; i++)
    cout << "\n";
  if(Turno()== 1)
    cout << "Turno de " << "\033[1;31m" << nombre << " (x)" << endl;
  else
    cout << "Turno de " << "\033[1;32m" << nombre << " (o)" << endl;

}
void Jugador::EscogeColumna(Tablero &tablero){

  int col;
  ImprimirTurno();
  col = PedirColumna(tablero);
  while(!tablero.Inserta(col)){
    col = PedirColumnaError(tablero);
  }
}

int Jugador::CalcularPuntuacion(Tablero &tablero){
  return(1000 + tablero.Filas()*tablero.Columnas()*10 - tablero.Introducidas()*10 + tablero.Alinear()*100);
}

void Jugador::SumarPuntuacion(Tablero &tablero){
  puntuacion+=CalcularPuntuacion(tablero);
}

int Jugador::Puntuacion(){
  return puntuacion;
}

void Jugador::IncrementaGanadas(Tablero &tablero){
  SumarPuntuacion(tablero);
  ganadas++;
}

void Jugador::IncrementaPerdidas(){
  perdidas++;
}

void Jugador::IncrementaEmpatadas(){
  empatadas++;
}

int Jugador::Ganadas(){
  return ganadas;
}

int Jugador::Perdidas(){
  return perdidas;
}

int Jugador::Empatadas(){
  return empatadas;
}
