#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "raylib.h"
#include <iostream>
#include <map>

class ResourceManager
{
public:

	static ResourceManager* Instance(); //singleton

	/// @brief Get a texture from the specified path
	Texture2D GetTexture(std::string path);

private:

	static ResourceManager* _instance;
	/// @brief Constructor
	ResourceManager();
	/// @brief Destructor
	virtual ~ResourceManager();

	std::map<std::string, Texture2D> textures;
};

#endif
