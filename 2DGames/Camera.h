#ifndef CAMERA_H
#define CAMERA_H

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ResourceManager.h"

class Camera
{
private:
	std::string name;

protected:
	// camera projection matrix
	glm::mat4 projectionMatrix;

	glm::vec3 mCamPos;			// camera position
	glm::vec3 mCamTarget;		// target position
	glm::vec3 mCamUp;			// the up vector of camera(local up)
	glm::vec3 mCamRight;		// the right vector of camera(local right)
	glm::vec3 mFromTargetVec;	// the direction unit vector from target to camera
	glm::vec3 mCamFront;		// the front vector of the camera(local front)
	

public:
	// perspective projection
	Camera(std::string _name, float fov, float width, float height, float nearz, float farz);
	// orthographic projection
	Camera(std::string _name, float left, float right, float bot, float top, float nearz, float farz);
	~Camera();

	std::string getName() { return name; }
	void setName(std::string _name) { this->name = name; }

	// get the position of the camera
	// @return a vector 3 type
	inline glm::vec3 getCamPos() { return mCamPos; }

	// get the view matrix from this camera
	glm::mat4 getViewMatrix();

	// get the projection matrix of this camera
	glm::mat4 getProjectionMatrix();

	// virtual update function
	virtual void Update(float deltaSeconds) = 0;

	// virtual input controller function
	virtual void InputController() = 0;
};
#endif

