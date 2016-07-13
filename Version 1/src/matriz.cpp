#include "matriz.h"
#include <cassert>

  Matriz::Matriz(int fils, int cols){
    bool error = (fils <= MAX_FIL_COL) && (cols <= MAX_FIL_COL) && (fils >= 0) && (cols >= 0);
    if(error){
      filas = fils;
      columnas = cols;
      for(int i = 0; i < fils; i++){
        for(int j = 0; j < cols; j++){
          matriz[i][j] = 0;
        }
      }
    }
  }
  int Matriz::Filas () const{
    return filas;
  }
  int Matriz::Columnas() const{
    return columnas;
  }
  int Matriz::Get(int f, int c) const{
    assert(f>=0 && f<filas && c >= 0 && c < columnas);
    return matriz[f][c];
  }
  void Matriz::Set(int f, int c, int v){
    assert(f>=0 && f<filas && c >= 0 && c < columnas);
    matriz[f][c] = v;
  }
