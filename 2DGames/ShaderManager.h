#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H
#include "ShaderProgram.h"
#include "Shader.h"
#include "LogManager.h"
#include <vector>
#include <unordered_map>

class ShaderManager
{
private:
	std::vector<ShaderProgram> mShaders;

	// Not used(yet) hashmap datastructure
	std::unordered_map<std::string, ShaderProgram> mShadersMap;

public:
	ShaderManager();
	~ShaderManager();

	// create a new shader program with single vertex shader
	void createNewShader(const std::string vertexShaderSource, const std::string shaderName);
	// create a new shader program with vertex shader and fragment shader
	void createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string shaderName);
	// create a new shader program with vertex shader, fragment shader and geometry shader
	void createNewShader(const std::string vertexShaderSource, const std::string fragmentShaderSource, const std::string geometryShaderSource, const std::string shaderName);

	// @return: shaderProgram pointer
	// should implemented with hash table
	ShaderProgram* getShader(const std::string shaderName);
};
#endif

