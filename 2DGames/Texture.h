#ifndef TEXTURE_H
#define TEXUTRE_H

#include <string>

// Texture wrapper class
class Texture
{
private:

	// Texture id -- after loaded in
	unsigned int id;

	// the Type of the texture -- the type is undefined
	std::string type;

	// Texture location and name -- don't know if I ever need this, just put it here in case
	std::string name;

	float width, height;

public:
	
	Texture(std::string name);
	Texture(unsigned int id, std::string type);
	Texture(unsigned int id, std::string type, std::string name);

	~Texture();

	unsigned int getTextureID() { return id; };

	unsigned int* getTextureIDHandle() { return &id; }

	void setType(std::string type) { this->type = type; }

	void setName(std::string name) { this->name = name; }

	std::string getName() { return this->name; }

	void setWidthHeight(float _width, float _height) { this->width = _width; this->height = _height; }

	float getWidth() { return this->width; }

	float getHeight() { return this->height; }

};

#endif

