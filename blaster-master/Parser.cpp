#include "Parser.h"

std::vector<std::string> split(std::string line, std::string delimeter)
{
	std::vector<std::string> tokens;
	size_t last = 0; size_t next = 0;
	while ((next = line.find(delimeter, last)) != std::string::npos)
	{
		tokens.push_back(line.substr(last, next - last));
		last = next + 1;
	}
	tokens.push_back(line.substr(last));

	return tokens;
}

std::wstring ToWString(std::string string)
{
	const char* str = string.c_str();

	size_t newsize = strlen(str) + 1;
	wchar_t* wcstring = new wchar_t[newsize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize, str, _TRUNCATE);

	std::wstring wstr(wcstring);

	// delete wcstd::string   // << can I ? 
	return wstr;
}

void ParseTextures(std::string line)
{
	std::vector<std::string> tokens = split(line);

	// skip invalid line
	if (tokens.size() < 5)
	{
		return;
	}

	int textureID = atoi(tokens[0].c_str());
	std::wstring filePath = ToWString(tokens[1]);
	int R = atoi(tokens[2].c_str());
	int G = atoi(tokens[3].c_str());
	int B = atoi(tokens[4].c_str());

	Textures::GetInstance()->Add(textureID, filePath.c_str(), D3DCOLOR_XRGB(R, G, B));
}

void ParseSprites(std::string line)
{
	std::vector<std::string> tokens = split(line);

	// skip invalid line
	if (tokens.size() < 6)
	{
		return;
	}

	int id = atoi(tokens[0].c_str());
	int left = atoi(tokens[1].c_str());
	int top = atoi(tokens[2].c_str());
	int right = atoi(tokens[3].c_str());
	int bottom = atoi(tokens[4].c_str());
	int textureID = atoi(tokens[5].c_str());

	LPDIRECT3DTEXTURE9 texture = Textures::GetInstance()->Get(textureID);
	if (texture == NULL)
	{
		DebugOut(L"[ERROR] Texture ID %d not found!\n", textureID);
		return;
	}

	Sprites::GetInstance()->Add(id, left, top, right, bottom, texture);
}

void ParseAnimations(std::string line)
{
	std::vector<std::string> tokens = split(line);

	// skip invalid lines - an animation must at least has 1 frame and 1 frame time //
	if (tokens.size() < 2)
	{
		return;
	}

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	LPANIMATION ani = new Animation(ANIMATION_DEFAULT_TIME);

	int ani_id = atoi(tokens[0].c_str());
	for (int i = 1; i < tokens.size(); i++)
	{
		int sprite_id = atoi(tokens[i].c_str());
		ani->Add(sprite_id);
	}

	Animations::GetInstance()->Add(ani_id, ani);
}