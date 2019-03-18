/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Team
*/

#include "../include/Team.hpp"

// Ctor/Dtor
Team::Team() 
{
    if (!this->_font.loadFromFile("media/arcade.TTF"))
        raise("Error: Style file not found");
    this->_team1.setFont(this->_font);
    this->_team2.setFont(this->_font);
    this->_name1.setFont(this->_font);
    this->_name2.setFont(this->_font);

    this->_team1.setCharacterSize(100);
    this->_team2.setCharacterSize(100);
    this->_team1.setFillColor(sf::Color::White);
    this->_team2.setFillColor(sf::Color::White);
    this->_team1.setPosition(450.0f, 500.0f);
    this->_team2.setPosition(1400.0f, 500.0f);
    
    this->_name1.setCharacterSize(50);
    this->_name2.setCharacterSize(50);
    this->_name1.setFillColor(sf::Color::White);
    this->_name2.setFillColor(sf::Color::White);
    this->_name1.setPosition(450.0f, 300.0f);
    this->_name2.setPosition(1400.0f, 300.0f);
    this->_name1.setString("TEAM 1");
    this->_name2.setString("TEAM 2");

}

Team::~Team() {}

void Team::drawTeam(sf::RenderWindow *window, int team1, int team2)
{
    this->_team1.setString(std::to_string(team1));
    this->_team2.setString(std::to_string(team2));
    window->draw(this->_team1);
    window->draw(this->_team2);
    window->draw(this->_name1);
    window->draw(this->_name2);
}