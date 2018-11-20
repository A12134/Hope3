#ifndef TILE_MAP_H
#define TILE_MAP_H

#include "ResourceManager.h"
#include <vector>
#include <string>
#include "Sprite.h"

// the parameters for a single sprite
struct TileParams 
{
	// the width and height for the single sprite
	float spriteWidth;
	float spriteHeight;
	// the UV offset for each sprite
	float offsetX;
	float offsetY;
};

// The class stores bunch of texture sets and their corresponding coordinates

class TileMap
{
private:
	// TileMap name
	std::string name;

	// 2D vector array stores the sprite
	std::vector<std::vector<Sprite*>> tileMap;

public:

	// Default constructor
	TileMap();

	// Constructor -- defines the width and length of the tile map
	// @Params: 
	// -params: the settings for a single sprite
	// -tileSetName: the texture set used for the map
	// -constructPattern: the file contains instruction on how to create a map
	TileMap(TileParams params, std::string tileSetName, std::string constructPattern);

	~TileMap();
};
#endif


