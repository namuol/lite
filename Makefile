all: lite lite-static lite-swig tests

debug: lite-debug lite-static-debug lite-swig-debug

lite:
	@(cd ./src && $(MAKE))

lite-debug:
	@(cd ./src && DEBUG=yes $(MAKE) -e)

lite-static:
	@(cd ./src && STATIC=yes $(MAKE) -e)

lite-static-debug:
	@(cd ./src && STATIC=yes DEBUG=yes $(MAKE) -e)

lite-swig:
	@(cd ./src && $(MAKE) $@)

lite-swig-debug:
	@(cd ./src && DEBUG=yes $(MAKE) lite-swig -e)

tests:
	@(cd ./test && $(MAKE))

clean:
	@(cd ./src && $(MAKE) $@)
	@(cd ./test && $(MAKE) $@)
