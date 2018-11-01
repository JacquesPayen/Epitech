/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** libGL
*/

#ifndef LIBGL_HPP_
	#define LIBGL_HPP_

#include "../../../include/core.hpp"

#include "../lib/glew.h"
#include "../lib/glfw3.h"

#define VERTEX "./shaders/VertexShader.vertexshader"
#define FRAGMENT "./shaders/FragmentShader.fragmentshader"

class libGL : public libGraphic
{
	public:
		libGL();
		virtual	~libGL();
		void	refreshW();
		void	clearW();
		void	getKey(int *key);
		void	setCell(const int &x, const int &y, const int &cell);
		void	setText(const int &x, const int &y, const std::string &text);
		void	initializeGlfw();
		void	openWindow();
		void	initializeGlew();
		void	prepareBuffer();
		GLuint	loadShaders();
		void	getFileContents(std::string &content, std::ifstream &file);
		void	compileShader(GLuint &ShaderID, std::string &ShaderCode);
		void	linkTheProg(GLuint &VertexShaderID, GLuint &FragmentShaderID, GLuint &ProgramID);
		void	handleError(const char *errorMsg);
		void	setColor(GLfloat *tmp_color_buffer_data, int pos);
		void	choseColor(GLfloat *tmp_color_buffer_data, const int &cell);
	private:
		GLFWwindow*	_window;
		GLuint	_programID;
		GLuint	_vertexArrayID;
		GLfloat _size[2048];
		GLuint _vertexBuffer;
		GLuint _colorBuffer;
		int	_bufferPos;
};

#endif /* !LIBGL_HPP_ */
