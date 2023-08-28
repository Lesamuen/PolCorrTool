#ifndef SHADERS_H
#define SHADERS_H

// Flat vertex shader, for direct translation to screenspace (2D)
extern const char *flatVert;
// Flat fragment shader, for direct translation to screenspace (2D)
extern const char *flatFrag;

// Perspective vertex shader, for 3D transformation to screenspace
extern const char *perspVert;
// Perspective fragment shader, for 3D transformation to screenspace
extern const char *perspFrag;

#endif