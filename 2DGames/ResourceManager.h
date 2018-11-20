#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

// A all in one class that stores the data needs to be shared between multiple classes
// include all type of resources class here, texture/meshe/audio
// flipbooks -- 2D animation
// audio clip
// particle effects
#include <unordered_map>
#include "ShaderManager.h"
#include "Texture.h"
#include "Mesh.h"
#include "Audio.h"
#include "Flipbook.h"
#include "Model.h"
#include "Material.h"
#include "Window.h"
#include "Game.h"
#include "Scene.h"
#include "Sprite.h"
#include "TileMap.h"

class ResourceManager
{
private:

	// Game class-- only one Game class is allowed
	static Game* mainGameEvent;

	// Windows -- Currently is limited to one only
	static Window* mainWindow;

	// Shaders
	static ShaderManager* mShaderManager;

	// Textures
	static std::unordered_map<std::string, Texture*> mTextures;
	
	// Meshes
	static std::unordered_map<std::string, Mesh*> mMeshes;
	
	// Audios
	static std::unordered_map<std::string, Audio*> mAudios;
	
	// Flipbooks
	static std::unordered_map<std::string, Flipbook*> mFlipbooks;

	// Models -- combined meshes, material and shaders
	static std::unordered_map<std::string, Model*> mModels;

	// Materials -- combined textures, each material contains maximum 16 textures
	static std::unordered_map<std::string, Material*> mMaterials;

	// Scenes -- a place to store each scene
	static std::unordered_map<std::string, Scene*> mScenes;

	// Scene pointer
	static Scene* currentScene;

	// Sprites
	static std::unordered_map<std::string, Sprite*> mSprites;

	// tileMap
	static std::unordered_map<std::string, TileMap*> mTileMaps;

public:
	ResourceManager();
	~ResourceManager();

	static void addTileMap(std::string name, TileMap* map);

	static TileMap* getTileMap(std::string name);

	static void addSprite(std::string name, Sprite* sprite);

	static Sprite* getSprite(std::string name);

	// Get the current scene
	static inline Scene* getCurrentScene() { return currentScene; }

	// Create a new Game event class
	// @return: Game class pointer
	static Game* createNewGame();

	// Get the current Game event class pointer
	// @return: Game Class pointer
	static inline Game* getGameEvent();

	// Store the game class pointer into resource manager
	// @param: Game Class pointer
	static void setGameEvent(Game* _gameEvent);

	// Get the current window pointer
	// @return: window class pointer
	static inline Window* getCurrentWindow() { return mainWindow; };

	// Store the current window pointer
	static void setCurrentWindow(Window* _window);

	// Create a new Window with simple two resolution params
	// @Params: Resolution_x: the resolution on x axis;
	//			Resolution_y: the resolution on y axis;
	// @return: return the newly created window pointer
	static Window* createNewWindow(int Resolution_x, int Resolution_y);

	// Get the material files which contians a list of texture file name
	// @name: the name of the assets
	static inline Material* getMaterial(std::string name);

	// Get the assets from hashmap, if does not exist load from the disk, if not exist on disk, load the default asset.
	// @name: the name of the asset
	static inline Texture* getTexture(std::string name);

	// Get the assets from hashmap, if does not exist load from the disk, if not exist on disk, load the default asset.
	// @name: the name of the asset
	static inline Mesh getMesh(std::string name);

	// Get the assets from hashmap, if does not exist load from the disk, if not exist on disk, load the default asset.
	// @name: the name of the asset
	static inline Audio getAudio(std::string name);

	// Get the assets from hashmap, if does not exist load from the disk, if not exist on disk, load the default asset.
	// @name: the name of the asset
	static inline Flipbook getFlipbook(std::string name);

	// Get the assets from hashmap, if does not exist load from the disk, if not exist on disk, load the default asset.
	// @name: the name of the asset
	static inline Model getModel(std::string name);

	// Unload the assets by name
	// @name: asset's name
	static void unloadTexture(std::string name);

	// Unload the assets by name
	// @name: asset's name
	static void unloadMesh(std::string name);

	// Unload the assets by name
	// @name: asset's name
	static void unloadAudio(std::string name);

	// Unload the assets by name
	// @name: asset's name
	static void unloadFlipbook(std::string name);

	// Unload the assets by name
	// @name: asset's name
	static void unloadModel(std::string name);

	// Caution!!!
	// unload all assets of the type
	static void unloadTexture();

	// Caution!!!
	// unload all assets of the type
	static void unloadMesh();

	// Caution!!!
	// unload all assets of the type
	static void unloadAudio();

	// Caution!!!
	// unload all assets of the type
	static void unloadFlipbook();

	// Caution!!!
	// unload all assets of the type
	static void unloadModel();

private:

	static Material* loadMaterial(std::string name);
	static Texture* loadTexture(std::string name);
	static Mesh loadMesh(std::string name);
	static Audio loadAudio(std::string name);
	static Flipbook loadFlipbook(std::string name);
	static Model loadModel(std::string name);
};

#endif

