/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** libGL
*/

#include "../include/libGL.hpp"

libGL::libGL()
{
	initializeGlfw();
	openWindow();
	initializeGlew();
	_bufferPos = 0;
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);
	_programID = loadShaders();
	prepareBuffer();
}

libGL::~libGL()
{
	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteBuffers(1, &_colorBuffer);
	glDeleteVertexArrays(1, &_vertexArrayID);
	glDeleteProgram(_programID);
	glfwTerminate();
}

void	libGL::handleError(const char *errorMsg)
{
	fprintf(stderr, "GL Error : %s\n", errorMsg);
	exit(84);
}

void	libGL::refreshW()
{
		glUseProgram(_programID);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
		glVertexAttribPointer(
			1,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		glDrawArrays(GL_TRIANGLES, 0, _bufferPos);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glfwSwapBuffers(_window);
		glfwPollEvents();
}

void	libGL::clearW()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void	libGL::getKey(int *key)
{
	*key = 0;
}

void	libGL::initializeGlfw()
{
	if(!glfwInit())
		handleError("Failed to initialize GLFW\n");
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void	libGL::openWindow()
{
	_window = glfwCreateWindow(1024, 768, "Arcade", NULL, NULL);
	if(_window == NULL) {
		glfwTerminate();
		handleError("Failed to open GLFW window.");
	}
	glfwMakeContextCurrent(_window);
}

void	libGL::initializeGlew()
{
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		handleError("Failed to initialize GLEW\n");
	}
}

void	libGL::prepareBuffer()
{
	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_size), 0, GL_STATIC_DRAW);
	glGenBuffers(1, &_colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_size), 0, GL_STATIC_DRAW);

}

void	libGL::setColor(GLfloat *tmp_color_buffer_data, int pos)
{
	for (int i = 0 ; i < 18 ; i++)
	{
		if (i % pos == 0)
			tmp_color_buffer_data[i] = 255;
	}
}

void	libGL::choseColor(GLfloat *tmp_color_buffer_data, const int &cell)
{
	if (cell == 1)
	{
		setColor(tmp_color_buffer_data, 1);
		setColor(tmp_color_buffer_data, 2);
		setColor(tmp_color_buffer_data, 3);
	}
	if (cell == 2) {
		setColor(tmp_color_buffer_data, 1);
	}
	if (cell == 3) {
		setColor(tmp_color_buffer_data, 2);
	}
	if (cell == 4) {
		setColor(tmp_color_buffer_data, 3);
	}
}

void	libGL::setCell(const int &x, const int &y, const int &cell)
{
	GLfloat tmp_vertex_buffer_data[] {
		x - 0.025f, y - 0.025f, 0.0f,
		x + 0.025f, y - 0.025f, 0.0f,
		x + 0.025f,  y + 0.025f, 0.0f,
		x - 0.025f, y - 0.025f, 0.0f,
		x - 0.025f, y + 0.025f, 0.0f,
		x + 0.025f, y + 0.025f, 0.0f,
	};
	GLfloat tmp_color_buffer_data[] {
		0.f,  0.f,  0.f,
		0.f,  0.f,  0.f,
		0.f,  0.f,  0.f,
		0.f,  0.f,  0.f,
		0.f,  0.f,  0.f,
		0.f,  0.f,  0.f,
	};
	choseColor(tmp_color_buffer_data, cell);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, _bufferPos * sizeof(float) * 3, (_bufferPos + 6) * sizeof(GLfloat) * 3, tmp_vertex_buffer_data);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _colorBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, _bufferPos * sizeof(float) * 3, (_bufferPos + 6) * sizeof(GLfloat) * 3, tmp_color_buffer_data);
	_bufferPos += 6;
}

void	libGL::setText(const int &x, const int &y, const std::string &text)
{
	printf("%s\n", text.c_str());
}

extern "C"
{
	libGL        *createLibGraph()
	{
		return (new libGL());
	}
}