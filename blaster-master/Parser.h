#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Textures.h"
#include "debug.h"
#include "Sprites.h"
#include "Animation.h"
#include "Constants.h"
#include "Animations.h"

enum section {
	UNKNOWN,
	TEXTURES,
	SPRITES,
	ANIMATIONS,
	OBJECTS,
};

std::vector<std::string> split(std::string line, std::string delimeter = "\t");
std::wstring ToWString(std::string string);
void ParseTextures(std::string line);
void ParseSprites(std::string line);
void ParseAnimations(std::string line);