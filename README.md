# Saturn-Engine [DEMO]
This is a demo of my game engine project that I am working on

Demo exe can be found in Demo folder

The demo has:

- A logging system, that allows you to show logs in different colors depending upon the severity of the situation (OK, INFO, WARN, FAIL)
- Simple 3D object loading system that can load all file types (meshes with a lot of submeshes aren't supported as of now)
- Simple lighting system using Phong lighting model
- Mini editor window that allows you to resize, rotate and move the 3D object in 3D space, it also allows you to change the skybox clear color and light color
- A simple menu implementation that allows you to close the window
- Simple File IO system to store engine config (currently the window size and 3D object render data)

(this implementation is written using OpenGL Graphics API)
