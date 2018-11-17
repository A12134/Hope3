#ifndef GAME_H
#define GAME_H

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "Window.h"

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{

public:
	// Game state
	GameState	State;
	

	
public:
	// Constructor/Destructor
	Game();
	~Game();

	// Initialize game state(load all shaders/textures/levels)
	void Init();

	// GameLoop
	void ProcessInput(GLfloat deltasec);
	void Update(GLfloat deltasec);
	void Render();
};

#endif

