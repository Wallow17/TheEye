/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Box
*/

#include "../include/Box.hpp"
#include "../include/Raise.h"

Box::Box()
{
    if (!this->_font.loadFromFile("media/arial.ttf"))
        raise("Error: Style file not found");
    this->_text.setFont(this->_font);
    this->_text.setString("No messages");
    this->_text.setPosition(0, 600);
    this->_text.setCharacterSize(16);
    this->_text.setColor(sf::Color::White);
}

Box::~Box()
{
}

void Box::set(sf::String t) {
    this->_text.setString(t);
}

void Box::draw(sf::RenderWindow *window) {
    window->draw(this->_text);
}