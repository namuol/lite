all: lite-core-base lite-core-sfml

lite-core-base:
	@(cd ./base && $(MAKE))

lite-core-sfml:
	@(cd ./sfml && $(MAKE))

clean:
	@(cd ./sfml && $(MAKE) $@)
	@(cd ./base && $(MAKE) $@)
