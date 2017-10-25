#include "tablero.h"
using namespace std;


  Tablero::Tablero(int fils, int cols, int al, int f):m(fils, cols){
    turno = 1;
    alinear = al;
    empates = 0;
    fichasturno = f;
    fichas_en_tablero = 0;
  }

  Tablero::Tablero(Matriz mat, int al, int f){
    turno = 1;
    alinear = al;
    empates = 0;
    m = mat;
    fichasturno = f;
    fichas_en_tablero = 0;
  }

  Tablero::Tablero(){
    turno = 1;
    fichasturno = 0;
    alinear = 0;
    empates = 0;
    Matriz mat;
    m = mat;
    fichas_en_tablero = 0;
  }

  Tablero::~Tablero(){
    fichasturno = 0;
    turno = 0;
    alinear = 0;
    empates = 0;
    fichas_en_tablero = 0;
  }

  void Tablero::operator=(const Tablero& t){
    m = t.m;
    turno = t.turno;
    alinear = t.alinear;
    empates = t.empates;
    fichasturno = t.fichasturno;
  }

  int Tablero::Filas() const{
    return m.Filas();
  }

  int Tablero::CuentaFichas() const{
    int contador = 0;
      for(int i = 0; i < Filas(); i++ ){
        for (int j = 0; j < Columnas(); j++){
          if(m.Get(i,j)!=0)
            contador++;
      }
    }

    return contador;

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

  int Tablero::FichasTurno() const{
    return fichasturno;
  }

  Matriz& Tablero::Contenido(){
    return m;
  }

  ostream& operator<<(ostream& os, Tablero& t){
    os << t.Contenido() << " " << t.Alinear() << " " << t.FichasTurno();
    return os ;
  }
  istream& operator>>(istream& is, Tablero& t){
    int ali, f;
    Matriz mat;

    is >> mat >> ali >> f;

    Tablero tab(mat, ali, f);
    if(is)
      t = tab;
    return is;
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
    if(TurnosJugados()%2 == 0){//Empieza el que acaba
      CambiarTurno();
  }
}

 bool Tablero::Inserta(int col, int insertadas){
   if(col >= 0 && col < Columnas()){
    if((m.Get(Filas()-1, col)) == 0){
      int i = 0;
      while(m.Get(i, col) != 0 && i < Filas()){
        i++;
      }
      m.Set(i, col, Turno());
      if (insertadas == FichasTurno())
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

  void Tablero::prettyPrint(ostream& os) const{
    bool columna = 1;

    for (char k = 'a'; k < Columnas()+'a'; k++){
      if(columna)
        os << " " << "\033[1;36m" << k;
      else
        os << " " << "\033[1;34m" << k;
      columna = !columna;
    }
        os << "\n";
    columna = 1;
    for(int i = 0; i < Filas(); i++){
      for(int j = 0; j < Columnas(); j++){
        if(columna)
         os << "\033[1;36m|\033[0m";
        else{
          os << "\033[1;34m|\033[0m";
        }
        if(m.Get(Filas()-i-1,j)==1)
          os << "\033[1;31mx\033[0m";
        else if (m.Get(Filas()-i-1,j)==2)
          os << "\033[1;32mo\033[0m";
            else
              os << " ";
        columna = !columna;
      }
      if(columna)
       os << "\033[1;36m|\033[0m\n";
      else{
        os << "\033[1;34m|\033[0m\n";
      }
      columna = 1;
    }
    for (char k = 'a'; k < Columnas()+'a'; k++){
      if(columna)
        os << " " << "\033[1;36m" << k << "\033[0m";
      else
        os << " " << "\033[1;34m" << k << "\033[0m";
      columna = !columna;
  }
}

int Tablero::Introducidas() const{
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

  int Tablero::Empates() const{
    return empates;
  }

  int Tablero::TurnosJugados() const{
    return Introducidas()/FichasTurno();
  }

  void Tablero::setFichasTablero(int fichas) {
    fichas_en_tablero = fichas;
  }

  int Tablero::fichasTotalesEnTablero() const {
    return fichas_en_tablero;
  }
