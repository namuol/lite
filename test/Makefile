SRC = $(wildcard ../src/tile/*.cpp ../src/core/base/*.cpp ../src/core/sfml/*.cpp ../src/math/*.cpp)
OBJ = $(SRC:.cpp=.o)

CPP         = g++
INCLUDES    = -I../src/core/base -I../src/math -I../src/core/sfml -I../src/tile
LIBFLAGS    = -L../lib -lsfml-system -lsfml-graphics -lsfml-window
CFLAGS      = -O0 -gstabs+ -Wall -pedantic $(LIBFLAGS) $(INCLUDES)

all: $(OBJ) test

test:
	$(CPP) $(CFLAGS) -o $@ $(OBJ) test.cpp

$(OBJ): %.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)

clean:
	@(rm -rf test)
