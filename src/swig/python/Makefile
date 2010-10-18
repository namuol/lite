all: lite-bindings

lite-bindings:
	@(swig -python -outcurrentdir ../lite.i)
	@(python setup.py build_ext --inplace)

clean:
	@(rm -rf build lite.py lite.pyc lite_wrap.c _lite.so)
