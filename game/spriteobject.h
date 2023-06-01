#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "raylib.h"
#include "resourcemanager.h"
#include "object.h"
#include <vector>

class SpriteObject : public Object
{
public:
	/// @brief Constructor
	SpriteObject(std::string filePath);
	/// @brief Destructor
	virtual ~SpriteObject();

	Color color;

	void Draw();

private:
	Texture2D texture;
	void Init(std::string filePath);
};

#endif
