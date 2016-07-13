SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)

all: $(BIN)/conectaN

# ************ Compilación de módulos ************

$(OBJ)/matriz.o : $(SRC)/matriz.cpp $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/matriz.cpp -o $(OBJ)/matriz.o
$(OBJ)/tablero.o : $(SRC)/tablero.cpp $(INC)/tablero.h $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/tablero.cpp -o $(OBJ)/tablero.o
$(OBJ)/jugador.o : $(SRC)/jugador.cpp $(INC)/jugador.h $(INC)/tablero.h $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/jugador.cpp -o $(OBJ)/jugador.o
$(OBJ)/conectaN.o : $(SRC)/conectaN.cpp $(INC)/tablero.h $(INC)/jugador.h $(INC)/matriz.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/conectaN.cpp -o $(OBJ)/conectaN.o
$(BIN)/conectaN : $(OBJ)/conectaN.o $(OBJ)/jugador.o $(OBJ)/tablero.o $(OBJ)/matriz.o
	$(CXX) -o $(BIN)/conectaN $(OBJ)/conectaN.o $(OBJ)/jugador.o $(OBJ)/tablero.o $(OBJ)/matriz.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/*
