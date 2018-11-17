#ifndef SCENE_H
#define SCENE_H

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <string>

class Scene
{
private:
	std::string name;

public:

	Scene(std::string sceneName);
	~Scene();

	void Update(GLfloat deltaSec);

	void Render();

	std::string getName() { return name; }
	void setName(std::string Name) { this->name = Name; }
};
#endif

