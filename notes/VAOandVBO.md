# VAO and VBO

Since the shaders are running on the GPU, but the rest of the code isn't (even if the GPU is *on* the CPU, like an integrated Intel laptop CPU/GPU), then data needs to be transfered between the two. It could be 3 vertices for a triangle, or thousands of points for a 3D model, colors, texture coordinates, and such.

Enter VBOs and VAOs.

**VBO** = Vertex Buffer Objects
**VAO** = Vertex Array Objects

These are used to take data from the C++ program and send it to the shaders for rendering.

Older GL used to send data every frame, but modern GL must have the data sent to the GPU *before* it is rendered using VBOs. When you actually want to render the data, you have to set up VAOs that describe how to pull the data out of VBOs and feed it into the shaders' variables.

## Vertex Buffer Objects

Data must be sent, *uploaded*, to the video memory on the graphics card. This is exactly what VBOs do. They are "buffers" (aka, arrays) of video memory - a collection of bytes that contain binary data. It can upload anything, really, from 3D points to text documents, because it simply copies whatever it is told to.

## Vertex Array Objects

Once the VBO transfers/uploads the data to the GPU memory, OpenGL needs to be told what kind of data is in the buffer. This is what VAOs are used for.

In between the VBOs and the shader variables, the VAO works. VAOs describe what *type* of data is contained in the buffer (VBO) and which *shader variables* that data is associated with/sent to.

In the vertex shader, you have inputs such as this:

'''glsl
in vec3 vertexPositions;
'''

The VAO tells OpenGL that the VBO has 3D points in it, and to send them to the variable *vertexPositions* in the vertex shader.

This can be extended to contain texture coordinates, colors, and points. The VAO will "tell" GL about this and the pattern they are in so that they can actually be used.

Further reading:

https://www.opengl.org/discussion_boards/showthread.php/174577-Questions-on-VAOs
