#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>
#include "Mesh.h"
#include "Texture.h"

struct Vertex
{
	glm::vec3 mPosition;
	glm::vec3 mNormal;
	glm::vec2 mTexCoords;
};

struct MouseStatus 
{
	double posX;
	double posY;
	E_MOUSE_BUTTON_STATUS button;
};

enum E_MOUSE_BUTTON_STATUS 
{
	E_RELEASE,
	E_LEFT_BUTTON_PRESSED,
	E_RIGHT_BUTTON_PRESSED,
	E_MIDDLE_BUTTON_PRESSED
};

// Texture wrapping enums
enum WRAP_TAG
{
	REPEAT,
	MIRRORED,
	CLAMP_EDGE,
	CLAMP_BORDER
};

// Texture fliter enums
enum FLITER_TAG 
{
	LINEAR,
	NEAREST
};


class Utils
{

public:
	Utils();
	~Utils();

	// store the mouse information
	static MouseStatus mouseStatus;

	// get the mouse information
	static inline MouseStatus getMouseStatus() { return mouseStatus; }

	// world coordinate up vector
	static glm::vec3 worldUpVector;

	// Set the property of the texture
	// @wt1, ft1: horizontal property
	// @wt2, ft2: vertical property
	static void setTexProperty(WRAP_TAG wt1, WRAP_TAG wt2, FLITER_TAG ft1, FLITER_TAG ft2);
	
	// Set the property of the texture
	// @wt: wrapping for both s and t direction
	// @ft: filter for both s and t direction
	static void setTexProperty(WRAP_TAG wt, FLITER_TAG ft);

	// set up the mesh's VAO, VBO and EBO
	// @_mesh: the pointer of the mesh
	// @vertices: vertices data vector
	// @indices: indices data vector
	static void setupMesh(Mesh* _mesh, std::vector<Vertex> vertices, std::vector<unsigned int> indices);

	// read the data from file
	// @returns a vector of strings separated by line break
	// @name: the name of the file
	static std::vector<std::string> readTxtFile(std::string name);
	
	// calculate the time between each frame
	// @return time
	static float getDeltaSecond();

	// mouse callback function
	static inline void getMousePosition_CallBack(GLFWwindow* window, double _mouseX, double _mouseY);
	

	// mouse button callback function
	static inline void getMouseButton_CallBack(GLFWwindow* window, int button, int action, int mods);

private:
	static float OTSS;
	static float TSS;
};
#endif

