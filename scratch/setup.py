from distutils.core import setup
from distutils.extension import Extension

'''
Fixes cythonize import error.
Link: https://bit.ly/2THKTvU
'''
try:
    from cython.Build import cythonize

except ImportError:
    def cythonize(*args, **kwargs):
        from Cython.Build import cythonize
        return cythonize(*args, **kwargs)

examples_extension = Extension(
    name="pyfactors",
    sources=["pyfactors.pyx"],
    libraries=["rsa"]
)
setup(
    name="pyfactors",
    ext_modules=cythonize([examples_extension])
)
