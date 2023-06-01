#include <iostream>
#include <fstream>
#include <sstream>

#include "resourcemanager.h"

ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager()
{
	std::cout << "Created new ResourceManager" << std::endl;
}

ResourceManager::~ResourceManager()
{
	
}
 
ResourceManager* ResourceManager::Instance()
{
	std::cout << "ResourceManager called" << std::endl;
	if (ResourceManager::_instance == nullptr)
	{
		_instance = new ResourceManager();
	}
	return _instance;
}

Texture2D ResourceManager::GetTexture(std::string path)
{
	std::cout << "GetTexture called" << std::endl;
	if (textures.contains(path))
	{
		std::cout << "Existing texture send" << std::endl;
		return textures[path];
	}
	std::cout << "New texture made" << std::endl; 
	Texture2D texture = LoadTexture(path.c_str());
	textures[path] = texture;
	return texture;
}

