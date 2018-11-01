/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** libGLShaders
*/

#include "../include/libGL.hpp"

void	libGL::getFileContents(std::string &content, std::ifstream &file)
{
	if(file.is_open()) {
		std::stringstream sstr;
		sstr << file.rdbuf();
		content = sstr.str();
	}
	else
		handleError("Failed to open shaders files !");
}

void	libGL::compileShader(GLuint &shaderID, std::string &shaderCode)
{
	int	InfoLogLength = 0;
	GLint	Result = GL_FALSE;
	char const	*VertexSourcePointer = shaderCode.c_str();

	glShaderSource(shaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(shaderID);

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		handleError("Failed to compile shaders !");
	}
}

void	libGL::linkTheProg(GLuint &vertexShaderID, GLuint &fragmentShaderID, GLuint &programID)
{
	int	InfoLogLength = 0;
	GLint	Result = GL_FALSE;

	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &Result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		handleError("Failed to link shaders with the prog !");
	}
}

GLuint libGL::loadShaders()
{
	GLuint	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	std::string	fragmentShaderCode;
	std::ifstream	fragmentShaderStream(FRAGMENT, std::ios::in);
	std::string	vertexShaderCode;
	std::ifstream	vertexShaderStream(VERTEX, std::ios::in);
	GLuint		programID;

	getFileContents(vertexShaderCode, vertexShaderStream);
	getFileContents(fragmentShaderCode, fragmentShaderStream);
	compileShader(vertexShaderID, vertexShaderCode);
	compileShader(fragmentShaderID, fragmentShaderCode);
	programID = glCreateProgram();
	linkTheProg(vertexShaderID, fragmentShaderID, programID);
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	return programID;
}