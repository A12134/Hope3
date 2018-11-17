#include "Game.h"
#include "ResourceManager.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Init()
{
}

void Game::ProcessInput(GLfloat deltasec)
{
}

void Game::Update(GLfloat deltasec)
{
	ResourceManager::getCurrentScene()->Update(deltasec);
}

void Game::Render()
{
	ResourceManager::getCurrentScene()->Render();
}
