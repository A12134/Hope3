#include "Sprite.h"
#include <vector>


Sprite::Sprite(std::string _name, Material* _mat, UV uv)
{
	this->mat = _mat;
	this->spriteUV = uv;
	setName(_name);

	// this mesh is inaccessible from the resourceManager
	sprite = new Mesh(_name + "_mesh");
	// setup the sprite mesh
	setupMesh();
}

Sprite::Sprite(std::string _name, Material* _mat, float sizeX, float sizeY, UV uv)
{
	this->mat = _mat;
	this->spriteUV = uv;

	setName(_name);

	// this mesh is inaccessible from the resourceManager
	sprite = new Mesh(_name + "_mesh");

	// hard coded sprite size calculation
	
	// top right
	vertices[0] = sizeX / 2;
	vertices[1] = sizeY / 2;

	// bottom right
	vertices[3] = sizeX / 2;
	vertices[4] = -sizeY / 2;

	// bottom left
	vertices[6] = -sizeX / 2;
	vertices[7] = -sizeY / 2;

	// top left
	vertices[9] = -sizeX / 2;
	vertices[10] = sizeY / 2;

	// setup the sprite mesh
	setupMesh();

}


Sprite::~Sprite()
{
}

void Sprite::renderSprite(ShaderProgram * sp, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
{
	sp->useThis();
	mat->useThisMaterial();

	glm::mat4 matrices = projection * view * model;

	sp->setUniformMatrix4x4fv("transform", matrices, GL_FALSE);

	glBindVertexArray(*(sprite->getVAOHandler()));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// reset material usage
	glActiveTexture(GL_TEXTURE0);
}

void Sprite::setupMesh()
{
	// convert all data into a vector of Vertex data structure
	std::vector<Vertex> vert;
	Vertex v;
	
	// top right
	v.mPosition = glm::vec3(vertices[0], vertices[1], vertices[2]);
	v.mNormal = glm::vec3(0.0f);
	v.mTexCoords = spriteUV.topRight;

	vert.push_back(v);

	// bottom right
	v.mPosition = glm::vec3(vertices[3], vertices[4], vertices[5]);
	v.mNormal = glm::vec3(0.0f);
	v.mTexCoords = spriteUV.botRight;

	vert.push_back(v);

	// bottom left
	v.mPosition = glm::vec3(vertices[6], vertices[7], vertices[8]);
	v.mNormal = glm::vec3(0.0f);
	v.mTexCoords = spriteUV.botLeft;

	vert.push_back(v);

	// top left
	v.mPosition = glm::vec3(vertices[9], vertices[10], vertices[11]);
	v.mNormal = glm::vec3(0.0f);
	v.mTexCoords = spriteUV.topLeft;

	vert.push_back(v);


	// process indices
	std::vector<unsigned int> _indices;

	for (unsigned int i = 0; i < 6; i++)
	{
		_indices.push_back(indices[i]);
	}

	Utils::setupMesh(sprite, vert, _indices);
}
