export DEBUG    = yes
export STATIC   = no

ifeq ($(DEBUG), yes)
    DEBUGFLAGS = -gstabs+ -DDEBUG
else
    DEBUGFLAGS = -O2 -DNDEBUG
endif

SRC = $(wildcard ../src/tile/*.cpp ../src/base/*.cpp ../src/impl/sfml/*.cpp ../src/math/*.cpp)
OBJ = $(SRC:.cpp=.o)

CPP         = g++
INCLUDES    = -I../src/base -I../src/math -I../src/impl/sfml -I../src/tile
LIBFLAGS    = -L../lib -lsfml-system -lsfml-graphics -lsfml-window
CFLAGS      = -Wall -pedantic $(LIBFLAGS) $(INCLUDES) $(DEBUGFLAGS)

all: $(OBJ) test

test: test.cpp
	$(CPP) $(CFLAGS) -o $@ $(OBJ) test.cpp

$(OBJ): %.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)

clean:
	@(rm -rf test)
