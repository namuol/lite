all: lite-bindings

lite-bindings:
	@(mkdir -p build/static-libs)
	@(cd build/static-libs && ln -sf ../../../../../lib/*.a .)
	@(swig -nodirprot -c++ -python -outcurrentdir ../lite.i)
	@(python setup.py build_ext --inplace)

clean:
	@(rm -rf build lite.py lite.pyc lite_wrap.cxx lite_wrap.h _lite.so)
