export VERSION  = 0.1

export DEBUG    = no
export STATIC   = no

ifeq ($(DEBUG), yes)
    DEBUGFLAGS = -O0 -gstabs+ -DDEBUG
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
export INCLUDES = -I../math -I../../math -I../../base -I../base -I../../../base
export CFLAGS   = -Wall -pedantic $(INCLUDES) $(DEBUGFLAGS) $(BUILDFLAGS)
export LDFLAGS  = $(LINKFLAGS)
export AR       = ar
export ARFLAGS  = rcs

all: lite-math lite-core-base lite-core-sfml lite-tile

lite-math:
	@(cd ./math && $(MAKE))

lite-core-base:
	@(cd ./base && $(MAKE))

lite-core-sfml:
	@(cd ./impl && $(MAKE) $@)

lite-tile:
	@(cd ./tile && $(MAKE))

lite-swig:
	@(cd ./swig && $(MAKE))

clean:
	@(cd ./impl && $(MAKE) $@)
	@(cd ./tile && $(MAKE) $@)
	@(cd ./base && $(MAKE) $@)
	@(cd ./math && $(MAKE) $@)
