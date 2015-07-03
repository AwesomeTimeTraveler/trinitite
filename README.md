# trinitite

This is a project based on modern OpenGL and C++ (GL 3.2 and up, and C++11 ISO standards)

The goal of the project is not defined, it is entirely experimental and will end up wherever it ends up.

Some ideas I have are procedural terrain generation in 3 dimensions, particle simulations using Newtonian mechanics and electromagnetic effects, and integration into a Python3 server client base.

# Config

trinitite is being developed in ArchLinux using the Atom text editor. It is compiled with G++ version 5.1 using the C++11 ISO standard.

OpenGL is provided and utilized by the libraries GLFW, GLEW, and GLM.

# Currently working on (aka ToDo):
- [ ] Finish IO to enable mouse, cursor, full keyboard, etc. using GLFW callbacks
  - [ ] Touchscreen?
- [ ] Begin threading; graphics on one thread, audio on one, etc.
- [ ] Compatibility
  - [ ] Switching to Cmake (trivial at this stage, just need to do it) for cross platform compatibility
  - [ ] Adding cross platform flags
- [ ] Add 3 dimensional rendering
- [ ] Geometry shader
- [ ] Begin camera work
