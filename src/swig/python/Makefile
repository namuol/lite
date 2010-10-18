all: lite-bindings

lite-bindings:
	@(swig -c++ -python -outcurrentdir ../lite.i)
	@(python setup.py build_ext --inplace)

clean:
	@(rm -rf build lite.py lite.pyc lite_wrap.cxx _lite.so)
