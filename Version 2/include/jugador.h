#ifndef _JUGADOR__
#define _JUGADOR__

#include "tablero.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>



class Jugador{

  char* nombre;
  int turno;
  int puntuacion;
  int ganadas;
  int perdidas;
  int empatadas;

  int CalcularPuntuacion(Tablero &tablero) const;

  void SumarPuntuacion(Tablero &tablero);

  public:

    Jugador(int turn, int gan, int per, int emp, int punt, const char* nombr);

    Jugador(int turn, char nombr[]);

    Jugador();

    Jugador(const Jugador& j);

    ~Jugador();

    void operator=(const Jugador& j);

    const char* Nombre() const;

    int PedirColumna(Tablero &tablero) const;

    void ImprimirTurno() const;

    bool EscogeColumna(Tablero &tablero, int insertadas);

    int Turno() const;

    int Puntuacion() const;

    int Ganadas() const;

    int Perdidas() const;

    int Empatadas() const;

    void IncrementaEmpatadas();

    void IncrementaGanadas(Tablero &tablero);

    void IncrementaPerdidas();

};
    std::ostream& operator<<(std::ostream& os, Jugador& j);

    std::istream& operator>>(std::istream& is, Jugador& j);
#endif
