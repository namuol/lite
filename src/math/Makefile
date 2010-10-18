SRC     = $(wildcard *.cpp)
OBJ     = $(SRC:.cpp=.o)

all: $(OBJ)

$(OBJ): %.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)

clean:
	@(rm -rf $(OBJ))
