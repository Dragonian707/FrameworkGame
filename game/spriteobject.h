#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "raylib.h"
#include "resourcemanager.h"
#include "object.h"
#include <vector>

class SpriteObject : public Object
{
protected:
	Texture2D texture;

public:
	/// @brief Constructor
	SpriteObject(std::string filePath);
	/// @brief Destructor
	virtual ~SpriteObject();

	Color color;

	void Draw();

	virtual void UpdateObject(float deltatime);

private:
};

#endif
