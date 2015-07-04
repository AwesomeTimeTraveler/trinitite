# What are Shaders?

Shaders are programs written in GLSL code that run on the GPU instead of the CPU.

http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Chapter-1:-The-Graphics-Pipeline.html

### Vertex Shaders

The main purpose of a vertex shader is to transform points of the (x,y,z) coordinate space into different points. A vertex is a point on a geometrical shape, more than one are vertices.

### Fragment Shaders

The main purpose of fragment shaders is to calculate the color of each pixel that is drawn.

"Fragment" ~= pixel, therefore a fragment shader is practically a "pixel shader"." A fragment *can* be smaller than a pixel, though.
