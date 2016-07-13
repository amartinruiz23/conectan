#include "matriz.h"
#include <cassert>
using namespace std;

  Matriz::Matriz(int fils, int cols){

    assert ((fils <= MAX_FIL_COL) && (cols <= MAX_FIL_COL) && (fils >= 0) && (cols >= 0));
      filas = fils;
      columnas = cols;
      matriz = new int[fils*cols];
      for(int i = 0; i < fils; i++){
        for(int j = 0; j < cols; j++){
          matriz[i*cols+j] = 0;
        }
      }
    }


  Matriz::~Matriz(){
    filas=0;
    columnas=0;
    delete[] matriz;
  }

  Matriz::Matriz(const Matriz& m){
    filas = m.filas;
    columnas = m.columnas;
    int *puntero = new int[filas*columnas];
    for (int i=0; i < filas*columnas; i++)
      puntero[i] = m.matriz[i];
    matriz = puntero;
  }
  Matriz::Matriz(){
    filas = 1;
    columnas = 1;
    int *puntero = new int[filas*columnas];
    for (int i=0; i < filas*columnas; i++)
      puntero[i] = 0;
    matriz = puntero;
  }

  Matriz& Matriz::operator=(const Matriz& m){//Matriz por referenci

    if (this != &m){
      filas = m.filas;
      columnas = m.columnas;
      delete[] matriz;
      int *puntero = new int[filas*columnas];
      for (int i=0; i < filas*columnas; i++)
      puntero[i] = m.matriz[i];
      matriz = puntero;
    }
    return *this;
  }

  std::ostream& operator<<(std::ostream& os, Matriz& m){
    os << m.Filas() << " " << m.Columnas() << "\n";
    for (int i=0; i < m.Filas(); i++)
      for (int j=0; j < m.Columnas(); j++)
        os << m.Get(i,j) << " ";
    return os;
  }

  std::istream& operator>>(std::istream& is, Matriz& m){

    int filas, columnas, valor;
    is >> filas >> columnas;

    Matriz mat(filas, columnas);
    for (int i=0; i < mat.Filas(); i++){
      for (int j=0; j < mat.Columnas(); j++){
        is >> valor;
        mat.Set(i, j, valor);
      }
    }

    if (is){
      m = mat;
    }
    return is;
  }

  int Matriz::Filas () const{
    return filas;
  }
  int Matriz::Columnas() const{
    return columnas;
  }
  int Matriz::Get(int f, int c) const{
    assert(f>=0 && f<filas && c >= 0 && c < columnas);
    return matriz[f*columnas+c];
  }

  void Matriz::Set(int f, int c, int v){
    assert(f>=0 && f<filas && c >= 0 && c < columnas);
    matriz[f*columnas+c] = v;
  }
