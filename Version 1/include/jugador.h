#ifndef _JUGADOR__
#define _JUGADOR__

#include "tablero.h"
#include <iostream>

const int MAX_NOMBRE = 50;

class Jugador{

  int turno;
  char nombre[MAX_NOMBRE];
  int puntuacion;
  int ganadas;
  int perdidas;
  int empatadas;

  int CalcularPuntuacion(Tablero &tablero);

  void SumarPuntuacion(Tablero &tablero);

  public:

    Jugador(int turn, char nombr[]);

    int PedirColumnaError(Tablero &tablero);

    int PedirColumna(Tablero &tablero);

    int Turno();

    void ImprimirTurno();

    void EscogeColumna(Tablero &tablero);

    int Puntuacion();

    int Ganadas();

    int Perdidas();

    int Empatadas();

    void IncrementaEmpatadas();

    void IncrementaGanadas(Tablero &tablero);

    void IncrementaPerdidas();

};
#endif
