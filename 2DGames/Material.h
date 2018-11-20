#ifndef MATERIAL_H
#define MATERIAL_H
#include <vector>
#include "Texture.h"

class Material
{
private:
	std::vector<Texture*> mTextures;
	std::string mName;

public:
	Material();
	Material(std::string mName);
	~Material();

	void addNewTexture(Texture* texture);

	void useThisMaterial();

	// get the width of texture_0
	float getTexWidth() { return this->mTextures.at(0)->getWidth(); }
	// get the height of texture_0
	float getTexHeight() { return this->mTextures.at(0)->getHeight(); }
};

#endif

