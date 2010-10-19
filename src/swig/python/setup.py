#!/usr/bin/env python

"""
setup.py file for lite SWIG-python bindings
"""

from distutils.core import setup, Extension


lite_module = Extension('_lite',
                        include_dirs=[
                            '../../core/base',
                            '../../core/sfml',
                            '../../math',
                            '../../tile'
                        ],
                        library_dirs=[
                            'build/static-libs'
                        ],
                        libraries=[
                            'lite-core-base',
                            'lite-core-sfml',
                            'sfml-system',
                            'sfml-graphics',
                            'sfml-window'
                        ],
                        sources=[
                            'lite_wrap.cxx',
                        ],
                    )

setup (name = 'lite',
       version = '0.1',
       author      = "Louis Acresti",
       author_email= "louis.acresti@gmail.com",
       description = """SWIG bindings for the lite game library""",
       ext_modules = [lite_module],
       py_modules = ["lite"],
       )
