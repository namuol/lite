all: lite lite-static lite-swig tests

lite:
	@(cd ./src && $(MAKE))

lite-static:
	@(cd ./src && STATIC=yes $(MAKE) -e)

lite-swig:
	@(cd ./src && $(MAKE) $@)

tests:
	@(cd ./test && $(MAKE))

clean:
	@(cd ./src && $(MAKE) $@)
	@(cd ./test && $(MAKE) $@)
