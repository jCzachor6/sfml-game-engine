#pragma once
#include <SFML\Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "teError.h"

class AssetManager
{
public:
	AssetManager();

	sf::Texture &GetTexture(std::string name);
	sf::Font &GetFont(std::string name);

	void LoadAssetsFromFile(std::string filePath);
	void SetTextureScale(float scale);
	void RemoveAll();
private:
	void LoadTexture(std::string name, std::string fileName);
	void LoadFont(std::string name, std::string fileName);
	std::string getAssetNameFromLine(std::string line);
	std::string getFileTypeFromLine(std::string assetName);
	void LoadAsset(std::string ext, std::string name, std::string filePath);
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	float scale;
};

