#ifndef _TABLERO__
#define _TABLERO__

#include "matriz.h"

class Tablero{

  int turno;
  Matriz m;
  int alinear;
  int empates;
  int fichasturno;

  void CambiarTurno();

  void IncrementaEmpates();

public:


    Tablero(int fils, int cols, int al, int f);

    Tablero(Matriz mat, int al, int f);

    Tablero();

    ~Tablero();

    void operator=(const Tablero& t);

    int Filas() const;

    int Columnas() const;

    int Alinear() const;

    int Turno() const;

    int FichasTurno() const;

    int CuentaFichas() const;

    int TurnosJugados() const;

    Matriz& Contenido();

    bool Finalizada(int turn) const;

    void Vacia();

    bool Inserta(int col, int insertadas);

    int Espera() const;

    bool Ganador(int turn) const;

    void prettyPrint(std::ostream& os = std::cout) const;

    int Introducidas() const;

    int Empates() const;

    };

    std::ostream& operator<<(std::ostream& os, Tablero& t);

    std::istream& operator>>(std::istream& is, Tablero& t);


#endif
