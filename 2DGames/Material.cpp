#include "Material.h"
#include "LogManager.h"
#include "includes/GLFW/glfw3.h"
#include "includes/glad/glad.h"


Material::Material()
{
}

Material::Material(std::string mName)
{
	this->mName = mName;
}


Material::~Material()
{
}

void Material::addNewTexture(Texture * texture)
{
	if (mTextures.size() < 16)
	{
		mTextures.push_back(texture);
	}
	else 
	{
		LogManager::addLog(ELogType::E_WARNING, this->mName + " has reached maximum texture limit. " + texture->getName() + " fail to add.");
	}
}

void Material::useThisMaterial()
{
	for (unsigned int i = 0; i < mTextures.size(); i++) 
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, mTextures.at(i)->getTextureID());
	}
}
