#include "shaders.h"

const char *flatVert = R"shader(
#version 450

layout (location = 0) in vec2 in_pos;
layout (location = 1) in vec4 in_col;
out vec4 vert_col;

void main(void)
{
	gl_Position = vec4(in_pos, 0.0, 1.0);
	vert_col  = in_col;
}
)shader";

const char *flatFrag = R"shader(
#version 450

in  vec4 vert_col;
layout (location = 0) out vec4 frag_col;

void main(void)
{
	frag_col = vert_col;
}
)shader";

const char *perspVert = R"shader(
#version 450

layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec4 in_col;
out vec4 vert_col;

// camera matrix is combination of projection, view, and model matrices
layout (location = 0) uniform mat4 camera;

void main(void)
{
	gl_Position = camera * vec4(in_pos, 1.0);
	vert_col  = in_col;
}
)shader";

const char *perspFrag = R"shader(
#version 450

in  vec4 vert_col;
layout (location = 0) out vec4 frag_col;

void main(void)
{
	frag_col = vert_col;
}
)shader";