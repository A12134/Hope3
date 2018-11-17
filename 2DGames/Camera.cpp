#include "Camera.h"



Camera::Camera(std::string _name, float fov, float width, float height, float nearz, float farz)
{
	this->setName(_name);
	this->projectionMatrix = glm::perspective(glm::radians(fov), width / height, nearz, farz);

	// register mouse callback function
	glfwSetCursorPosCallback(ResourceManager::getCurrentWindow()->getWindow(), Utils::getMousePosition_CallBack);
	glfwSetMouseButtonCallback(ResourceManager::getCurrentWindow()->getWindow(), Utils::getMouseButton_CallBack);
}

Camera::Camera(std::string _name, float left, float right, float bot, float top, float nearz, float farz)
{
	this->setName(_name);
	this->projectionMatrix = glm::ortho(left, right, bot, top, nearz, farz);

	// register mouse callback function
	glfwSetCursorPosCallback(ResourceManager::getCurrentWindow()->getWindow(), Utils::getMousePosition_CallBack);
	glfwSetMouseButtonCallback(ResourceManager::getCurrentWindow()->getWindow(), Utils::getMouseButton_CallBack);
}

Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 view = glm::mat4(1);
	view = glm::lookAt(this->mCamPos, this->mCamPos + this->mCamFront, this->mCamUp);
	return view;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return this->projectionMatrix;
}
