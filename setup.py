from distutils.core import setup, Extension

module1 = Extension('ale_python_interface.ale_c_wrapper',
                    libraries = ['ale'],
                    sources=['ale_python_interface/ale_c_wrapper.cpp'])
setup(name = 'ale_python_interface',
      description = 'Python Arcade Learning Environment Interface',
      ext_modules = [module1],
      packages=['ale_python_interface'])

