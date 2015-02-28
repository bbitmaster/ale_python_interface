A python interface for the Arcade Learning Environment

This provides a python library to interface with the arcade learning environment that can be found here:
http://www.arcadelearningenvironment.org/

This library hooks into the shared object file for the arcade learnign environment and bypasses using the slower FIFO interface.
It is designed to be fast. Example code is provided that demonstrates an agent that can be controlled from the keyboard.

To use this library, a build script is provided ./build.sh It requires the arcade learning environment header and library be on
the path.

The following examples are provided

ale_python_test1.py
This is a direct port to python of the shared library example from ALE provided in

ale_python_test2.py
This modified ale_python_test1.py to do more extensive tests of the python interface
by calling more functions

ale_python_test_pygame.py
This modified ale_python_test1.py to do display screen contents using pygame

ale_python_test_pygame_player.py
This modified ale_python_test_pygame.py to provide a fully interactive experience allowing the player
to play. RAM Contents, current action, and reward are also displayed.
keys are:
arrow keys -> up/down/left/right
z -> fire button


NOTE:
This library was written quickly, and still needs organizational work. The following tasks should be completed:
1. Move code into a directory tree, for example, example code should be in /example
2. Provide a setup.py script for installing the module
3. Provide an actual makefile. A build.sh script is messy and ugly
