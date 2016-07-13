#ifndef _MATRIZ_INT__
#define _MATRIZ_INT__

const int MAX_FIL_COL = 50;

class Matriz{

  int matriz[MAX_FIL_COL][MAX_FIL_COL];
  int filas, columnas;

  public:

    Matriz(int fils, int cols);

    int Filas() const;

    int Columnas() const;

    int Get(int f, int c) const;

    void Set(int f, int c, int v);
};


#endif
