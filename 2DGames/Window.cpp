#include "Window.h"


Window::Window(int width, int height, const char * title, GLFWmonitor * monitor, GLFWwindow * share)
{
	this->windowHandler = glfwCreateWindow(width, height, title, monitor, share);

	if (this->windowHandler == nullptr) 
	{
		LogManager::addLog(ELogType::E_ERROR, "Window initiation failed.");

		// force exit program
		LogManager::errorExit();
	}
}

Window::~Window()
{
	LogManager::addLog(ELogType::E_EVENT, "Destory window object");
	glfwDestroyWindow(this->windowHandler);
	this->windowHandler = nullptr;
}

void Window::activateContext()
{
	if (glfwGetCurrentContext() != this->windowHandler) 
	{
		glfwMakeContextCurrent(this->windowHandler);
		LogManager::addLog(ELogType::E_EVENT, "Current Window object active");
	}
}

GLFWwindow * Window::getWindow()
{
	if(this->windowHandler)
		return this->windowHandler;
	return nullptr;
}

void Window::createViewport(int x, int y, int _x, int _y)
{
	glViewport(x, y, _x, _y);
	LogManager::addLog(ELogType::E_EVENT, "Created viewport.");
}

void Window::enableDepthTest()
{
	activateContext();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	LogManager::addLog(ELogType::E_EVENT, "Enabling Depth test. Depth Function: Less");
}

void Window::enableMSAA()
{
	activateContext();
	glEnable(GL_MULTISAMPLE);
	LogManager::addLog(ELogType::E_EVENT, "Enabling multi-sample anti aliasing");
}

void Window::enableFaceCulling()
{
	activateContext();
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	LogManager::addLog(ELogType::E_EVENT, "Enabling face culling, Cull Face: Back");
}

void Window::clearColor(float r, float g, float b, float a)
{
	activateContext();
	glClearColor(r, g, b, a);
}

void Window::clearColor(glm::vec3 color, float alpha)
{
	activateContext();
	glClearColor(color.r, color.g, color.b, alpha);
}

void Window::clearColor(glm::vec4 color)
{
	activateContext();
	glClearColor(color.r, color.g, color.b, color.a);
}

void Window::clearBuffers()
{
	activateContext();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::freezeWindowSize(int x, int y)
{
	glfwSetWindowSizeLimits(this->windowHandler, x, y, x, y);
}

void Window::swapBuffer()
{
	glfwSwapBuffers(this->windowHandler);
}
