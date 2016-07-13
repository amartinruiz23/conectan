#ifndef _TABLERO__
#define _TABLERO__

#include "matriz.h"

class Tablero{

  int turno;
  Matriz m;
  int alinear;
  int empates;

  void CambiarTurno();

  void IncrementaEmpates();

  public:

    Tablero(int fils, int cols, int a);

    int Filas() const;

    int Columnas() const;

    int Alinear() const;

    int Turno() const;

    bool Finalizada(int turn) const;

    void Vacia();

    bool Inserta(int col);

    int Espera() const;

    bool Ganador(int turn) const;

    void Imprimir();

    int Introducidas();

    int Empates();

    };




#endif
