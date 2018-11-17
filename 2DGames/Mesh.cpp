#include "Mesh.h"
#include "LogManager.h"

Mesh::Mesh(std::string name)
{
	this->name = name;
}

Mesh::~Mesh()
{
}

ShaderProgram * Mesh::getShaderProgram()
{
	if(this->sp)
		return this->sp;
	else 
	{
		LogManager::addLog(ELogType::E_WARNING, this->name + " mesh missing shaderProgram.");
		// TODO return default shaderProgram pointer
		return nullptr;
	}
}
