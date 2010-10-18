#!/usr/bin/env python

"""
setup.py file for SWIG python bindings for lite
"""

from distutils.core import setup, Extension


lite_module = Extension('_lite',
                           sources=['lite_wrap.c'],
                           )

setup (name = 'lite',
       version = '0.1',
       author      = "SWIG Docs",
       description = """SWIG bindings for the lite game library""",
       ext_modules = [lite_module],
       py_modules = ["lite"],
       )
