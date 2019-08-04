#include "Sound.hpp"

sf::SoundBuffer & SoundManager::loadSoundBuffer(std::string path)
{

    SoundBufferList.push_back(sf::SoundBuffer());
    auto &soundBuffer = SoundBufferList.back();

    if(!soundBuffer.loadFromFile(path))
    {
        printf("Can't load texture");
    }

    return soundBuffer;
}

sf::Sound SoundManager::createSound(std::string path)
{
    sf::Sound sound;
    auto &soundBuffer = loadSoundBuffer(path);
    sound.setBuffer(soundBuffer);
    return sound;
}

SoundManager::SoundManager()
{
    SoundBufferList.reserve(8);
}




