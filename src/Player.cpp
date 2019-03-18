/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Player
*/

#include <iostream>
#include <SFML/Audio.hpp>
#include "../include/Player.hpp"

// Ctor/Dtor
Player::Player(int id, int x, int y, int orientation, std::string level, const std::string &team) :
                _id(id), _x(x), _y(y), _orientation(orientation), _level(level), _team(team)
{
    if (!this->_texture.loadFromFile("media/spaceShip.png"))
        raise("Error: Texture file not found");
    if (!this->_fLevel.loadFromFile("media/arcade.TTF"))
        raise("Error: Font file not found");
    sf::SoundBuffer buffer;
    sf::Sound sound;
    if (!buffer.loadFromFile("media/connexion.wav"))
        raise("Error: Sound file not found");
    sound.setBuffer(buffer);
    sound.play();
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setOrigin(100 / 2, 68 / 2);
    this->_sprite.setScale(0.5f, 0.5f);
    this->_sprite.setPosition(this->_x * 50 + 25, this->_y * 50 + 25);
    if (this->_orientation == 4)
        this->_orientation = 2;
    else if (this->_orientation == 2)
        this->_orientation = 4;
    this->_sprite.setRotation(_orientation * 90 + 90);
    this->_tLevel.setFont(this->_fLevel);
    this->_tLevel.setString(this->_level);
    this->_tLevel.setPosition(this->_sprite.getPosition());
}

Player::Player(Player &player, int x, int y, int orientation) :
_id(player.getId()), _x(x), _y(y), _orientation(orientation),  _level(player.getLevel()), _team(player.getTeam())
{
    if (!this->_texture.loadFromFile("media/spaceShip.png"))
        raise("Error: Texture file not found");
    if (!this->_fLevel.loadFromFile("media/arcade.TTF"))
        raise("Error: Font file not found");
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setOrigin(100 / 2, 68 / 2);
    this->_sprite.setScale(0.5f, 0.5f);
    this->_sprite.setPosition(this->_x * 50 + 25, this->_y * 50 + 25);
    if (this->_orientation == 2)
        this->_orientation = 4;
    else if (this->_orientation == 4)
        this->_orientation = 2;
    this->_sprite.setRotation(_orientation * 90 + 90);
    this->_tLevel.setFont(this->_fLevel);
    this->_tLevel.setString(this->_level);
    this->_tLevel.setPosition(this->_sprite.getPosition());
}

Player::~Player() {}

// Get
sf::Sprite Player::getSprite(void) const { return this->_sprite; }
int Player::getId(void) const {return this->_id;}
std::string Player::getLevel(void) const { return this->_level; }
std::string Player::getTeam(void) const { return this->_team; }
std::vector<std::string> Player::getInventory(void) {return this->_inventory;}

void Player::setInventory(std::vector<std::string> inventory)
{
    this->_inventory = inventory;
}
