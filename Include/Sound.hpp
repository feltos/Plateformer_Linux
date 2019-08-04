#pragma once

#include "SFML/Audio.hpp"

class SoundManager
{
public:

    SoundManager(const std::vector<sf::SoundBuffer> &soundBufferList);

    SoundManager();

    sf::SoundBuffer & loadSoundBuffer(std::string path);
    sf::Sound createSound(std::string path);

private:

    std::vector<sf::SoundBuffer> SoundBufferList;
};