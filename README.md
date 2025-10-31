# Flappy Bird Clone

A simple Flappy Bird clone built with C++ and SFML (Simple and Fast Multimedia Library).

![Game Screenshot](assets/sprites/bluebird-downflap.png)

## Features

- Classic Flappy Bird gameplay
- Score tracking
- High score system

## Prerequisites

- C++17 or higher
- CMake 3.10 or higher
- SFML 2.5.1 or higher

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd flappy-bird
   ```

2. Create a build directory and compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

## Running the Game

From the project root directory:

```bash
./FlappyBird
```

## Project Structure

```
SFML/
├── assets/               # Game assets (sprites, sounds)
│   └── sprites/          # Image assets
├── fonts/                # Font files
├── include/              # Header files
│   ├── game/            # Game logic headers
│   └── screens/         # Screen management headers
├── src/                 # Source files
│   ├── game/            # Game logic implementation
│   └── screens/         # Screen implementations
├── CMakeLists.txt       # Build configuration
└── README.md            # This file
```

## Dependencies

- SFML (Graphics, Window, System, Audio modules)
- Standard C++17 Library

## Building on Different Platforms

### Windows
1. Install SFML using vcpkg or download from the SFML website
2. Update the CMake configuration if needed
3. Use Visual Studio or MinGW to build the project

### Linux
```bash
# Install SFML dependencies
sudo apt-get install libsfml-dev

# Build and run
mkdir build && cd build
cmake ..
make
./FlappyBird
```

### macOS
```bash
# Install SFML using Homebrew
brew install sfml

# Build and run
mkdir build && cd build
cmake ..
make
./FlappyBird
```


## Acknowledgments

- SFML Team for the amazing multimedia library
- Original Flappy Bird game
