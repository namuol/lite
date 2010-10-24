export VERSION  = 0.1

export DEBUG    = no
export STATIC   = no

ifeq ($(DEBUG), yes)
    DEBUGFLAGS = -gstabs+ -DDEBUG
else
    DEBUGFLAGS = -O2 -DNDEBUG
endif

ifeq ($(STATIC), yes)
    BUILDFLAGS =
    LINKFLAGS  =
else
    BUILDFLAGS = -fPIC
    LINKFLAGS  = -shared
endif

export CC       = gcc
export CPP      = g++
export INCLUDES = -I../../math -I../base -I../core/sfml -I../math -I../core/base
export CFLAGS   = -Wall -pedantic $(INCLUDES) $(DEBUGFLAGS) $(BUILDFLAGS)
export LDFLAGS  = $(LINKFLAGS)
export AR       = ar
export ARFLAGS  = rcs

all: lite-math lite-core lite-tile

lite-math:
	@(cd ./math && $(MAKE))

lite-core:
	@(cd ./core && $(MAKE))

lite-tile:
	@(cd ./tile && $(MAKE))

lite-swig:
	@(cd ./swig && $(MAKE))

clean:
	@(cd ./swig && $(MAKE) $@)
	@(cd ./tile && $(MAKE) $@)
	@(cd ./core && $(MAKE) $@)
	@(cd ./math && $(MAKE) $@)
