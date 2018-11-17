#include "ResourceManager.h"
#include "includes/assimp/Importer.hpp"
#include "includes/assimp/scene.h"
#include "includes/assimp/postprocess.h"
#include "stb_image.h"
#include "includes/GLFW/glfw3.h"
#include "includes/glad/glad.h"
#include "Utils.h"

Game* ResourceManager::mainGameEvent = nullptr;
Window* ResourceManager::mainWindow = nullptr;
ShaderManager* ResourceManager::mShaderManager = new ShaderManager();
std::unordered_map<std::string, Texture*> ResourceManager::mTextures;
std::unordered_map<std::string, Mesh*> ResourceManager::mMeshes;
std::unordered_map<std::string, Audio*> ResourceManager::mAudios;
std::unordered_map<std::string, Flipbook*> ResourceManager::mFlipbooks;
std::unordered_map<std::string, Model*> ResourceManager::mModels;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

Game * ResourceManager::createNewGame()
{
	mainGameEvent = new Game();
	return mainGameEvent;
}

Game * ResourceManager::getGameEvent()
{
	return mainGameEvent;
}

void ResourceManager::setGameEvent(Game * _gameEvent)
{
	mainGameEvent = _gameEvent;
}

Window * ResourceManager::getCurrentWindow()
{
	return mainWindow;
}

void ResourceManager::setCurrentWindow(Window* _window)
{
	mainWindow = _window;
}

Window * ResourceManager::createNewWindow(int Resolution_x, int Resolution_y)
{
	mainWindow = new Window(Resolution_x, Resolution_y, "Main Window", NULL, NULL);
	return mainWindow;
}

Material * ResourceManager::getMaterial(std::string name)
{
	Material* retVal = mMaterials[name];

	if (retVal)
		return retVal;
	else
		return loadMaterial(name);
}

Texture * ResourceManager::getTexture(std::string name)
{
	Texture* retVal = mTextures[name];

	if(retVal)
		// return asset
		return retVal;
	else 
		// load asset from the disk if it is not inside the memory
		return loadTexture(name);
}


Material * ResourceManager::loadMaterial(std::string name)
{
	// create a new Material
	Material* mat = new Material(name);
	// get the material file
	std::vector<std::string> materialFile = Utils::readTxtFile(name);

	if (materialFile.empty()) 
	{
		//TODO: return the default material
		return;
	}
	else
	{
		// iterate through the texture vector, and assign the texture to the material
		for (unsigned int i = 0; i < materialFile.size(); i++)
		{
			mat->addNewTexture(getTexture(materialFile.at(i)));
		}

		return mat;
	}
}

Texture* ResourceManager::loadTexture(std::string name)
{

	int width, height, nrChannels;
	std::string directory = "assets\\textures\\" + name;
	unsigned char* imageData = stbi_load(directory.c_str(), &width, &height, &nrChannels, 0);

	if (!imageData) {
		// image does not exist, return default assets
		// TODO return Default
	}
	else {

		// process imageData if exist
		GLenum format;
		if (nrChannels == 1) 
		{
			format = GL_RED;
		}
		else if (nrChannels == 3) 
		{
			format = GL_RGB;
		}
		else if (nrChannels == 4) 
		{
			format = GL_RGBA;
		}

		Texture* tmpTexture = new Texture(name);
		unsigned int* _id = tmpTexture->getTextureIDHandle();

		glGenTextures(1, _id);
		glBindTexture(GL_TEXTURE_2D, *_id);

		Utils::setTexProperty(WRAP_TAG::REPEAT, FLITER_TAG::LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);
		stbi_image_free(imageData);

		// add to hashmap
		mTextures[name] = tmpTexture;

		return tmpTexture;
	}

	
}
