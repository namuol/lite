LIB         = liblite-core-sfml.so
LIB_STATIC  = liblite-core-sfml.a

LIBPATH         = ../../../lib
LIBNAME         = $(LIBPATH)/$(LIB)
LIBNAME_STATIC  = $(LIBPATH)/$(LIB_STATIC)

SRC     = $(wildcard *.cpp)
OBJ     = $(SRC:.cpp=.o)

ifeq ($(STATIC), yes)
    BUILD_NAME = $(LIB_STATIC)
else
    BUILD_NAME = $(LIB)
endif

all: $(BUILD_NAME)

$(LIB_STATIC): $(OBJ)
	$(AR) $(ARFLAGS) $(LIBNAME_STATIC) $(OBJ)

$(LIB): $(OBJ)
	$(CPP) $(LDFLAGS) -Wl,-soname,$(LIB).$(VERSION) -o $(LIBNAME) $(OBJ)

$(OBJ): %.o: %.cpp
	$(CPP) -o $@ -c $< $(CFLAGS)

clean:
	@(rm -rf $(OBJ))
	@(rm -rf $(LIBNAME))
	@(rm -rf $(LIBNAME_STATIC))
