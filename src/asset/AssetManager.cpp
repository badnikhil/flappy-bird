#include "../../include/asset/AssetManager.h"

void AssetManager::LoadTexture(std::string Name , std::string FileName){
    sf::Texture tx;
    if(tx.loadFromFile(FileName))_Textures[Name] = tx;
    
}
sf::Texture& AssetManager::GetTexture(std::string Name){
    return _Textures[Name];
}
void AssetManager::LoadFont(std::string Name , std::string FileName){
    sf::Font ft;
    if(ft.loadFromFile(FileName))_Fonts[Name] = ft;
}
sf::Font& AssetManager::GetFont(std::string Name){
    return _Fonts[Name];
}