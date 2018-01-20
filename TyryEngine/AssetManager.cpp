#include "AssetManager.h"


sf::Texture & AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

sf::Font & AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}

void AssetManager::LoadAllFromFile(std::string fileName)
{
	std::fstream assetFile;
	assetFile.open(fileName, std::ios::in);
	if (!assetFile.good()) {
		fatalError("Failed to load " + fileName);
	}
	else {
		while (!assetFile.eof()) {
			std::string line, asset, ext;
			getline(assetFile, line);
			asset = getAssetNameFromLine(line);
			ext = getFileTypeFromLine(asset);
			LoadAsset(ext, asset, line);
		}
		assetFile.close();
	}
}

void AssetManager::RemoveAll()
{
	textures.clear();
	fonts.clear();
}

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		this->textures[name] = tex;
	}
	else fatalError("Failed to load " + fileName);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->fonts[name] = font;
	}
	else fatalError("Failed to load " + fileName);
}

std::string AssetManager::getAssetNameFromLine(std::string line)
{
	std::size_t found = line.find_last_of("/\\");
	return line.substr(found + 1);
}

std::string AssetManager::getFileTypeFromLine(std::string assetName)
{
	std::size_t found = assetName.find_last_of(".");
	return assetName.substr(found + 1);
}

void AssetManager::LoadAsset(std::string ext, std::string name, std::string filePath)
{
	if (ext == "png") {
		LoadTexture(name, filePath);
	}
	else if (ext == "ttf") {
		LoadFont(name, filePath);
	}
}
