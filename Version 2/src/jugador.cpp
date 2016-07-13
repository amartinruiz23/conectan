#include "jugador.h"
#include "tablero.h"
#include <cstring>

using namespace std;


Jugador::Jugador(int turn, char nombr[]){
  puntuacion = 0;
  ganadas = 0;
  perdidas = 0;
  empatadas = 0;
  nombre = new char[strlen(nombr)+1];
  int i;
  for(i = 0; nombr[i] != '\0'; i++)
    nombre[i] = nombr[i];
  nombre[i] = '\0';
  turno = turn;
}
Jugador::Jugador(){
  puntuacion = 0;
  ganadas = 0;
  perdidas = 0;
  empatadas = 0;
  nombre = 0;
  turno = 0;

}

Jugador::Jugador(int turn, int gan, int per, int emp, int punt, const char* nombr){
  puntuacion = punt;
  ganadas = gan;
  perdidas = per;
  empatadas = emp;
  nombre = new char[strlen(nombr)+1];
  int i;
  for(i = 0; nombr[i] != '\0'; i++)
    nombre[i] = nombr[i];
  nombre[i] = '\0';

  turno = turn;
}


Jugador::~Jugador(){
  delete[] nombre;
  puntuacion = 0;
  ganadas = 0;
  perdidas = 0;
  empatadas = 0;
  turno = 0;
}

Jugador::Jugador(const Jugador& j){
  puntuacion = j.puntuacion;
  ganadas = j.ganadas;
  perdidas = j.perdidas;
  empatadas = j.empatadas;
  turno = j.turno;
  char *puntero = new char[strlen(j.Nombre()) +1];
  int i;
  for (i=0; j.nombre[i] != '\0'; i++)
    puntero[i] = j.nombre[i];
  puntero[i] = '\0';
  nombre = puntero;

}

void Jugador::operator=(const Jugador& j){
  puntuacion = j.puntuacion;
  ganadas = j.ganadas;
  perdidas = j.perdidas;
  empatadas = j.empatadas;
  turno = j.turno;
  if (this != &j){
    delete[] nombre;
    char *puntero = new char[strlen(j.Nombre()) +1];
    int i;
    for (i=0; j.nombre[i] != '\0'; i++)
      puntero[i] = j.nombre[i];
    puntero[i] = '\0';
    nombre = puntero;

    }
}

ostream& operator<<(ostream& os, Jugador& j){
  os << '#' << j.Nombre();

  os << "\n" << j.Turno() << " " << j.Puntuacion() << " ";
  os << j.Ganadas() << " " << j.Perdidas() << " " << j.Empatadas();
  return os;
}

istream& operator>>(istream& is, Jugador& j){
  char c;
  int t=0, pun=0, gan=0, per=0, emp=0;
  char *nom = new char[500];

 is >> c;
  is.getline(nom,500);
  is >> t >> pun;
  is >> gan >>  per >>  emp;
  if (is){
    Jugador jug(t, gan, per, emp, pun, nom);
    j = jug;
  }


  return is;
}

const char* Jugador::Nombre() const{
  return nombre;
}

int Jugador::Turno() const{
  return turno;
}

int Jugador::PedirColumna(Tablero &tablero) const{
  char columna;
  tablero.prettyPrint();

  cout << "\nColumna para colocar ficha:";
  cin >> columna;
  cout << endl;
  return columna-'a';

}
void Jugador::ImprimirTurno() const{
  if(Turno()== 1){
    cout << "Turno de " << "\033[1;31m";
    for(int i = 0; nombre[i] != '\0'; i++)
      cout << nombre[i];
      cout << " (x)" << endl;
     }
  else{
    cout << "Turno de " << "\033[1;32m";
    for(int i = 0; nombre[i] != '\0'; i++)
      cout << nombre[i];
      cout << " (o)" << endl;

  }

}

bool Jugador::EscogeColumna(Tablero &tablero, int insertadas){
  int col;

  if(nombre[0] =='@'){
    ImprimirTurno();
    col = rand()%tablero.Columnas();
    tablero.prettyPrint();
  }
  else{
    ImprimirTurno();
    col = PedirColumna(tablero);
  }
  if(tablero.Inserta(col, insertadas))
    return true;
  else
    return false;
}

int Jugador::CalcularPuntuacion(Tablero &tablero) const{
  return(1000 + tablero.Filas()*tablero.Columnas()*10 - tablero.Introducidas()*10 + tablero.Alinear()*100);
}

void Jugador::SumarPuntuacion(Tablero &tablero){
  puntuacion+=CalcularPuntuacion(tablero);
}

int Jugador::Puntuacion() const{
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

int Jugador::Ganadas() const{
  return ganadas;
}

int Jugador::Perdidas() const{
  return perdidas;
}

int Jugador::Empatadas() const{
  return empatadas;
}
