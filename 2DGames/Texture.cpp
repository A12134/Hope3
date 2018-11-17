#include "Texture.h"


Texture::Texture(std::string name)
{
	this->setName(name);
}

Texture::Texture(unsigned int id, std::string type)
{
	this->id = id;
	this->setType(type);
}

Texture::Texture(unsigned int id, std::string type, std::string name)
{
	this->id = id;
	this->setType(type);
	this->setName(name);
}

Texture::~Texture()
{
}
