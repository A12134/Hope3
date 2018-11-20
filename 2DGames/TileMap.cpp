#include "TileMap.h"



TileMap::TileMap()
{
}


TileMap::TileMap(TileParams params, std::string tileSetName, std::string constructPattern)
{
	std::vector<std::string> instruction = Utils::readTxtFile(constructPattern);

	// Acquire the texture material
	Material* mat = ResourceManager::getMaterial(tileSetName);

	// calculate divided the texture into different sprite
	int maxTileX = mat->getTexWidth() / params.spriteWidth;
	int maxTileY = mat->getTexHeight() / params.spriteHeight;
	
	// translate to UV coordinates
	float UV_tile_ratio_x = 1 / maxTileX;
	float UV_tile_ratio_y = 1 / maxTileY;

	int nameTracker = 0;
	int countTracker = 0;
	tileMap.push_back(std::vector<Sprite*>());
	for (unsigned int i = 0; i < instruction.size(); i++)
	{
		
		if (instruction.at(i) == "/n") 
		{
			countTracker += 1;
			tileMap.push_back(std::vector<Sprite*>());
			nameTracker = 0;
		}
		else 
		{

			// calcuate the UV for sprite's four corner
			UV uv;

			// TODO: if the image flipped, change the UV coordinates system's origin from bottom left to top left.
			uv.botLeft = glm::vec2(nameTracker*UV_tile_ratio_x, countTracker*UV_tile_ratio_y);
			uv.botRight = glm::vec2((nameTracker + 1)*UV_tile_ratio_x, countTracker*UV_tile_ratio_y);
			uv.topLeft = glm::vec2(nameTracker*UV_tile_ratio_x, (countTracker+1)*UV_tile_ratio_y);
			uv.topRight = glm::vec2((nameTracker+1)*UV_tile_ratio_x, (countTracker + 1)*UV_tile_ratio_y);

			Sprite* tmpSprite = new Sprite(
				"Sprite_" + std::to_string(countTracker) + "_" + std::to_string(nameTracker),
				mat,
				params.spriteWidth,
				params.spriteHeight,
				uv
			);

			tileMap.at(countTracker).push_back(tmpSprite);
		}
	}
}

TileMap::~TileMap()
{
}
