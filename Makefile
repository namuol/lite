all: lite lite-static tests

lite:
	@(cd ./src && $(MAKE))

lite-static:
	@(cd ./src && STATIC=yes $(MAKE) -e)

tests:
	@(cd ./test && $(MAKE))

clean:
	@(cd ./src && $(MAKE) $@)
	@(cd ./test && $(MAKE) $@)
