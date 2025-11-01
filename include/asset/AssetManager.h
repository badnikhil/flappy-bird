#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include<SFML/Graphics.hpp>
#include<unordered_map>
class AssetManager{
    public:
        AssetManager( ){ };
        ~AssetManager( ){ };
        void LoadTexture(std::string Name , std::string FileName);
        sf::Texture& GetTexture(std::string Name);

        void LoadFont(std::string Name , std::string FileName);
        sf::Font& GetFont(std::string Name );
    private:
        std::unordered_map<std::string , sf::Texture> _Textures;
        std::unordered_map<std::string , sf::Font> _Fonts;
};

#endif