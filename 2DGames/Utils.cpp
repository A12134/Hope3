#include "Utils.h"
#include "includes/GLFW/glfw3.h"
#include "includes/glad/glad.h"
#include <fstream>
#include <sstream>

float Utils::OTSS = 0;
float Utils::TSS = 0;

glm::vec3 Utils::worldUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
MouseStatus Utils::mouseStatus;

Utils::Utils()
{
}


Utils::~Utils()
{
}

void Utils::setTexProperty(WRAP_TAG wt1, WRAP_TAG wt2, FLITER_TAG ft1, FLITER_TAG ft2)
{
	GLenum _wt1, _wt2, _ft1, _ft2;
	switch (wt1)
	{
	case REPEAT:
		_wt1 = GL_REPEAT;
		break;
	case MIRRORED:
		_wt1 = GL_MIRRORED_REPEAT;
		break;
	case CLAMP_EDGE:
		_wt1 = GL_CLAMP_TO_EDGE;
		break;
	case CLAMP_BORDER:
		_wt1 = GL_CLAMP_TO_BORDER;
		break;
	default:
		break;
	}

	switch (wt2)
	{
	case REPEAT:
		_wt2 = GL_REPEAT;
		break;
	case MIRRORED:
		_wt2 = GL_MIRRORED_REPEAT;
		break;
	case CLAMP_EDGE:
		_wt2 = GL_CLAMP_TO_EDGE;
		break;
	case CLAMP_BORDER:
		_wt2 = GL_CLAMP_TO_BORDER;
		break;
	default:
		break;
	}

	switch (ft1)
	{
	case LINEAR:
		_ft1 = GL_LINEAR;
		break;
	case NEAREST:
		_ft1 = GL_NEAREST;
		break;
	default:
		break;
	}

	switch (ft2)
	{
	case LINEAR:
		_ft2 = GL_LINEAR;
		break;
	case NEAREST:
		_ft2 = GL_NEAREST;
		break;
	default:
		break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wt1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wt2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _ft1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _ft2);
}

void Utils::setTexProperty(WRAP_TAG wt, FLITER_TAG ft)
{
	GLenum _wt, _ft;
	switch (wt)
	{
	case REPEAT:
		_wt = GL_REPEAT;
		break;
	case MIRRORED:
		_wt = GL_MIRRORED_REPEAT;
		break;
	case CLAMP_EDGE:
		_wt = GL_CLAMP_TO_EDGE;
		break;
	case CLAMP_BORDER:
		_wt = GL_CLAMP_TO_BORDER;
		break;
	default:
		break;
	}

	switch (ft)
	{
	case LINEAR:
		_ft = GL_LINEAR;
		break;
	case NEAREST:
		_ft = GL_NEAREST;
		break;
	default:
		break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _wt);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _wt);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _ft);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _ft);
}

void Utils::setupMesh(Mesh * _mesh, std::vector<Vertex> vertices, std::vector<unsigned int> indices)
{
	glGenVertexArrays(1, _mesh->getVAOHandler());
	glGenBuffers(1, _mesh->getVBOHandler());
	glGenBuffers(1, _mesh->getEBOHandler());

	glBindVertexArray(*(_mesh->getVAOHandler()));
	glBindBuffer(GL_ARRAY_BUFFER, *(_mesh->getVBOHandler()));

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *(_mesh->getEBOHandler()));
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
		&indices[0], GL_STATIC_DRAW);

	// vertex position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	// vertex Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mNormal));

	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mTexCoords));

	glBindVertexArray(0);
}

std::vector<std::string> Utils::readTxtFile(std::string name)
{
	std::ifstream infile(name);
	std::string line;
	std::vector<std::string> retVal;

	while (std::getline(infile, line)) 
	{
		std::stringstream ss(line);
		std::string i;

		while (ss >> i) 
		{
			retVal.push_back(i);

			if (ss.peek() == ',' || ss.peek() == ' ') 
			{
				ss.ignore();
			}
		}

		retVal.push_back("/n");
	}
	return retVal;
}

float Utils::getDeltaSecond()
{
	TSS = (float)glfwGetTime();
	float retVal = TSS - OTSS;
	OTSS = TSS;
	return retVal;		// return delta second between each frame.
}

inline void Utils::getMousePosition_CallBack(GLFWwindow * window, double _mouseX, double _mouseY)
{
	mouseStatus.posX = _mouseX;
	mouseStatus.posY = _mouseY;
}

inline void Utils::getMouseButton_CallBack(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		mouseStatus.button = E_MOUSE_BUTTON_STATUS::E_RIGHT_BUTTON_PRESSED;
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		mouseStatus.button = E_MOUSE_BUTTON_STATUS::E_LEFT_BUTTON_PRESSED;
	else if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
		mouseStatus.button = E_MOUSE_BUTTON_STATUS::E_MIDDLE_BUTTON_PRESSED;
	else
		mouseStatus.button = E_MOUSE_BUTTON_STATUS::E_RELEASE;
}
