#!/usr/bin/env python

"""
setup.py file for lite SWIG-python bindings
"""

from distutils.core import setup, Extension


lite_module = Extension('_lite',
                           sources=['lite_wrap.cxx'],
                           )

setup (name = 'lite',
       version = '0.1',
       author      = "louis.acresti@gmail.com",
       description = """SWIG bindings for the lite game library""",
       ext_modules = [lite_module],
       py_modules = ["lite"],
       )
