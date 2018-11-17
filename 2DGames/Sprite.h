#ifndef SPRITE_H
#define SPRITE_H

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ResourceManager.h"
#include "Utils.h"
#include "Camera.h"

struct UV 
{
	glm::vec2 topLeft;
	glm::vec2 topRight;
	glm::vec2 botLeft;
	glm::vec2 botRight;
};

float vertices[] = {
	0.5f, 0.5f, 0.0f,  // top right
	0.5f, -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f // top left
};

unsigned int indices[] = 
{
	0, 1, 3,
	1, 2, 3
};

/*
TODO: custom size sprite
the sprite is a rectangler that has two parameters: size x and size y
*/
class Sprite
{
private:
	std::string name;
	Material * mat;
	UV spriteUV;
	Mesh* sprite;

public:
	// default constructor, a square with size 1.0f and 1.0f
	Sprite(std::string name, Material* _mat, UV uv);
	Sprite(std::string name, Material* _mat, float sizeX, float sizeY, UV uv);
	~Sprite();

	std::string getName() { return name; }
	void setName(std::string name) { this->name = name; }

	void renderSprite(ShaderProgram* sp, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

private:
	void setupMesh();
};
#endif

