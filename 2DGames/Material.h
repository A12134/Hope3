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
};

#endif

