all: python-bindings

python-bindings: lite-static
	@(cd ./python && $(MAKE))

lite-static:
	@(cd ../.. && $(MAKE) $@)

clean:
	@(cd ./python && $(MAKE) $@)
