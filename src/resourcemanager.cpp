#include <iostream>
#include <fstream>
#include <sstream>

#include "resourcemanager.h"



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
		return nullptr;
}

ResourceManager* ResourceManager::_instance = nullptr;