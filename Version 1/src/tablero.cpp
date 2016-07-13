#include "tablero.h"
#include <iostream>

using namespace std;

  Tablero::Tablero(int fils, int cols, int a):m(fils, cols){
    turno = 1;
    alinear = a;
  }

  int Tablero::Filas() const{
    return m.Filas();
  }

  int Tablero::Columnas() const{
    return m.Columnas();
  }

  int Tablero::Alinear() const{
    return alinear;
  }

  int Tablero::Turno() const{
    return turno;
  }

  bool Tablero::Finalizada(int turn) const{
    bool lleno = 1;
      for (int i = 0; i < Columnas(); i++){
        if (m.Get(Filas()-1, i) == 0){
          lleno = 0;
        }
      }

      cout << endl;

    return(Ganador(turn) || lleno);
  }

  void Tablero::Vacia(){
    for(int i = 0; i < Filas(); i++){
      for (int j = 0; j < Columnas(); j++){
        m.Set(i, j, 0);
      }
    }
  }

 bool Tablero::Inserta(int col){
   if(col >= 0 && col < Columnas()){
    if((m.Get(Filas()-1, col)) == 0){
      int i = 0;
      while(m.Get(i, col) != 0 && i < Filas()){
        i++;
      }
      m.Set(i, col, Turno());
      CambiarTurno();
      return true;
    }
    else
      return false;
  }
  else
    return false;
}

int Tablero::Espera() const{
  if(turno == 1)
    return 2;
  else
    return 1;
}

  bool Tablero::Ganador(int turn) const{

    int seguidas;

    for(int i = 0; i < Filas(); i++ ){
      for (int j = 0; j < Columnas()-Alinear()+1; j++){
        seguidas = 0;
        for(int k = 0; k < Alinear(); k++){
          if(m.Get(i,j+k)==turn)
            seguidas++;
          else
            seguidas = 0;
        }
        if (seguidas == Alinear())
          return true;

        }
      }

    for(int i = 0; i < Filas()- Alinear() +1; i++ ){
      for (int j = 0; j < Columnas(); j++){
        seguidas = 0;
        for(int k = 0; k < Alinear(); k++){
          if(m.Get(i+k,j)==turn)
            seguidas++;
          else
            seguidas = 0;
        }
        if (seguidas == Alinear())
          return true;
      }
    }

    for(int i = 0; i < Filas()- Alinear() +1; i++ ){
      for (int j = 0; j < Columnas()-Alinear()+1; j++){
        seguidas = 0;
        for(int k = 0; k < Alinear(); k++){
          if(m.Get(i+k,j+k)==turn)
            seguidas++;
          else
              seguidas = 0;
        }
        if (seguidas == Alinear())
          return true;
      }
    }

    for(int i = 0; i < Filas() - Alinear() + 1 ; i++ ){
      for (int j = Columnas()-1; j > Alinear() - 2; j--){
        seguidas = 0;
        for(int k = 0; k < Alinear(); k++){
          if(m.Get(i+k,j-k)==turn)
            seguidas++;
          else
              seguidas = 0;
        }
        if (seguidas == Alinear())
          return true;
      }
    }
    return false;

  }

  void Tablero::CambiarTurno(){
    if(turno == 1)
      turno = 2;
    else
      turno = 1;
  }

  void Tablero::Imprimir(){
    bool columna = 1;

    for (char k = 'a'; k <= Columnas()+'a'-1; k++){
      if(columna)
        cout << " " << "\033[1;36m" << k;
      else
        cout << " " << "\033[1;34m" << k;
      columna = !columna;
    }
        cout << "\n";
    columna = 1;
    for(int i = 0; i < Filas(); i++){
      for(int j = 0; j < Columnas(); j++){
        if(columna)
         cout << "\033[1;36m|\033[0m";
        else{
          cout << "\033[1;34m|\033[0m";
        }
        if(m.Get(Filas()-i-1,j)==1)
          cout << "\033[1;31mx\033[0m";
        else if (m.Get(Filas()-i-1,j)==2)
          cout << "\033[1;32mo\033[0m";
            else
              cout << " ";
        columna = !columna;
      }
      if(columna)
       cout << "\033[1;36m|\033[0m\n";
      else{
        cout << "\033[1;34m|\033[0m\n";
      }
      columna = 1;
    }
  }

  int Tablero::Introducidas(){
    int introducidas=0;
    for(int i = 0; i < Filas(); i++){
      for(int j = 0; j < Columnas(); j++){
        if (m.Get(i,j) != 0)
          introducidas++;
      }
    }
    return introducidas;

  }

  void Tablero::IncrementaEmpates(){
    empates++;
  }

  int Tablero::Empates(){
    return empates;
  }
