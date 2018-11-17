#ifndef MESH_H
#define MESH_H
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "Utils.h"
#include "ShaderProgram.h"

class Mesh
{
private:
	std::string name;
	unsigned int VAO, VBO, EBO;
	ShaderProgram* sp;

public:
	Mesh(std::string name);
	~Mesh();

	// @return the pointer of mesh's VAO
	unsigned int* getVAOHandler() { return &VAO; }
	// @return the pointer of mesh's VBO
	unsigned int* getVBOHandler() { return &VBO; }
	// @return the pointer of mesh's EBO
	unsigned int* getEBOHandler() { return &EBO; }

	// Set the shaderProgram for this mesh
	// @sp: shader program pointer
	void setShaderProgram(ShaderProgram* sp) { this->sp = sp; }

	// get the reference of the shaderProgram
	ShaderProgram* getShaderProgram();
};
#endif

