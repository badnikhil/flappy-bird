#include <fstream>
#include <filesystem>

int loadHighScore() {
    std::filesystem::create_directory("data"); // Create folder if doesn't exist
    std::ifstream file("data/highscore.txt");
    int highScore = 0;
    if(file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void saveHighScore(int highScore) {
    std::filesystem::create_directory("data");
    std::ofstream file("data/highscore.txt");
    if(file.is_open()) {
        file << highScore;
        file.close();
    }
}