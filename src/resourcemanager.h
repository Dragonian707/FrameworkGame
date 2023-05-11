#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "raylib.h"
#include <iostream>
#include <map>

class ResourceManager
{
public:

	static ResourceManager* Instance();

private:

	static ResourceManager* _instance;
	/// @brief Constructor
	ResourceManager();
	/// @brief Destructor
	virtual ~ResourceManager();

	std::map<std::string, Texture2D> textures;
};

#endif
