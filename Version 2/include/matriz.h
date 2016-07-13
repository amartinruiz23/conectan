#ifndef _MATRIZ_INT__
#define _MATRIZ_INT__
#include <iostream>
#include <fstream>

const int MAX_FIL_COL = 31 ;//Numero máximo de caracteres que no producen error al imprimir

class Matriz{

  int *matriz;
  int filas, columnas;

  public:

    Matriz(int fils, int cols);

    Matriz(const Matriz& m);

    Matriz();

    ~Matriz();

    Matriz& operator=(const Matriz& m);

    int Filas() const;

    int Columnas() const;

    int Get(int f, int c) const;

    int Get(int p) const;

    void Set(int f, int c, int v);

  };

std::ostream& operator<<(std::ostream& of, Matriz& m);

std::istream& operator>>(std::istream& is, Matriz& m);

#endif
