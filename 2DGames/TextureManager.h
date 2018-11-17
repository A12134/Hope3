#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <vector>
#include "Texture.h"
#include <string>

class TextureManager
{
public:
	std::vector<Texture> mTextures;

public:
	TextureManager();
	~TextureManager();

	// load all Texture under directory assets\texture
	bool loadTextures();

	// get the texture rendering ID by name/by UID
	int getTextureID(std::string _name);
	int getTextureID(int UID);

	// get the texture class pointer by name/by UID
	Texture* getTexture(std::string _name);
	Texture* getTexture(int UID);
};
#endif