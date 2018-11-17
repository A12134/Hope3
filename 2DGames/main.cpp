#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "LogManager.h"
#include "Window.h"
#include "ResourceManager.h"



#define RESOLUTION_X 1920	// window width
#define RESOLUTION_Y 1440	// window height

void main() 
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	Window* mainWindow = ResourceManager::createNewWindow(RESOLUTION_X, RESOLUTION_Y);
	
	mainWindow->activateContext();

	// load glad libs
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		LogManager::addLog(ELogType::E_ERROR, "Failed to initialize GLAD proc.");
		LogManager::errorExit();
	}

	mainWindow->createViewport(0, 0, RESOLUTION_X, RESOLUTION_Y);
	mainWindow->freezeWindowSize(RESOLUTION_X, RESOLUTION_Y);
	mainWindow->enableDepthTest();
	mainWindow->enableMSAA();


}