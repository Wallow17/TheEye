/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Inventory
*/

#include "../include/Window.hpp"
#include "../include/Player.hpp"
#include "../include/Inventory.hpp"

Inventory::~Inventory()
{
}

Inventory::Inventory()
{
    if (!this->_font.loadFromFile("media/arcade.TTF"))
        raise("Error: Style file not found");
    this->_nfood.setFont(this->_font);
    this->_nlinemate.setFont(this->_font);
    this->_nderaumere.setFont(this->_font);
    this->_nsibur.setFont(this->_font);
    this->_nmendiane.setFont(this->_font);
    this->_nphiras.setFont(this->_font);
    this->_nthystame.setFont(this->_font);

    this->setFood("0");
    this->setLinemate("0");
    this->setDeraumere("0");
    this->setSibur("0");
    this->setMendiane("0");
    this->setPhiras("0");
    this->setThystame("0");

    this->_nfood.setCharacterSize(18);
    this->_nlinemate.setCharacterSize(18);
    this->_nderaumere.setCharacterSize(18);
    this->_nsibur.setCharacterSize(18);
    this->_nmendiane.setCharacterSize(18);
    this->_nphiras.setCharacterSize(18);
    this->_nthystame.setCharacterSize(18);
    
    this->_nfood.setFillColor(sf::Color::White);
    this->_nlinemate.setFillColor(sf::Color::White);
    this->_nderaumere.setFillColor(sf::Color::White);
    this->_nsibur.setFillColor(sf::Color::White);
    this->_nmendiane.setFillColor(sf::Color::White);
    this->_nphiras.setFillColor(sf::Color::White);
    this->_nthystame.setFillColor(sf::Color::White);    

    if (!this->_tfood.loadFromFile("media/food.png"))
        raise("Error: Texture file not found");
    if (!this->_tlinemate.loadFromFile("media/linemate.png"))
        raise("Error: Texture file not found");
    if (!this->_tderaumere.loadFromFile("media/deraumere.png"))
        raise("Error: Texture file not found");
    if (!this->_tsibur.loadFromFile("media/sibur.png"))
        raise("Error: Texture file not found");
    if (!this->_tmendiane.loadFromFile("media/mendiane.png"))
        raise("Error: Texture file not found");
    if (!this->_tphiras.loadFromFile("media/phiras.png"))
        raise("Error: Texture file not found");
    if (!this->_tthystame.loadFromFile("media/thystame.png"))
        raise("Error: Texture file not found");
    if (!this->_tinventory_bar.loadFromFile("media/inventory_bar.png"))
        raise("Error: Texture file not found");

    this->_sfood.setTexture(this->_tfood);
    this->_slinemate.setTexture(this->_tlinemate);
    this->_sderaumere.setTexture(this->_tderaumere);
    this->_ssibur.setTexture(this->_tsibur);
    this->_smendiane.setTexture(this->_tmendiane);
    this->_sphiras.setTexture(this->_tphiras);
    this->_sthystame.setTexture(this->_tthystame);
    this->_sinventory_bar.setTexture(this->_tinventory_bar);
    
    this->_sinventory_bar.setScale(2.0f, 1.0f);
    this->_sinventory_bar.setPosition(0.0f, 660.0f);
    this->_sfood.setPosition(13.0f, 672.0f);
    this->_slinemate.setPosition(79.0f, 670.0f);
    this->_sderaumere.setPosition(142.0f, 670.0f);
    this->_ssibur.setPosition(207.0f, 670.0f);
    this->_smendiane.setPosition(271.0f, 670.0f);
    this->_sphiras.setPosition(334.0f, 670.0f);
    this->_sthystame.setPosition(399.0f, 670.0f);

    this->_nfood.setPosition(18.0f, 672.0f);
    this->_nlinemate.setPosition(79.0f, 670.0f);
    this->_nderaumere.setPosition(142.0f, 670.0f);
    this->_nsibur.setPosition(207.0f, 670.0f);
    this->_nmendiane.setPosition(271.0f, 670.0f);
    this->_nphiras.setPosition(334.0f, 670.0f);
    this->_nthystame.setPosition(399.0f, 670.0f);
    
}

void Inventory::drawInventory(sf::RenderWindow *window)
{
    window->draw(this->_sinventory_bar);        
    window->draw(this->_sfood);
    window->draw(this->_slinemate);
    window->draw(this->_sderaumere);
    window->draw(this->_ssibur);
    window->draw(this->_smendiane);
    window->draw(this->_sphiras);
    window->draw(this->_sthystame);
    
    window->draw(this->_nfood);
    window->draw(this->_nlinemate);
    window->draw(this->_nderaumere);
    window->draw(this->_nsibur);
    window->draw(this->_nmendiane);
    window->draw(this->_nphiras);
    window->draw(this->_nthystame);
}

sf::Sprite Inventory::getFood(void) const { return this->_sfood; }
sf::Sprite Inventory::getLinemate(void) const { return this->_slinemate; }
sf::Sprite Inventory::getDeraumere(void) const { return this->_sderaumere; }
sf::Sprite Inventory::getSibur(void) const { return this->_ssibur; }
sf::Sprite Inventory::getMendiane(void) const { return this->_smendiane; }
sf::Sprite Inventory::getPhiras(void) const { return this->_sphiras; }
sf::Sprite Inventory::getThystame(void) const { return this->_sthystame; }
sf::Sprite Inventory::getInventory_bar(void) const { return this->_sinventory_bar; }

void Inventory::setFood(std::string nbr) { this->_nfood.setString(nbr); }
void Inventory::setLinemate(std::string nbr) { this->_nlinemate.setString(nbr); }
void Inventory::setDeraumere(std::string nbr) { this->_nderaumere.setString(nbr); }
void Inventory::setSibur(std::string nbr) { this->_nsibur.setString(nbr); }
void Inventory::setMendiane(std::string nbr) { this->_nmendiane.setString(nbr); }
void Inventory::setPhiras(std::string nbr) { this->_nphiras.setString(nbr); }
void Inventory::setThystame(std::string nbr) { this->_nthystame.setString(nbr); }

void Inventory::setAllInv(std::vector<std::string> msg)
{
    this->setFood(msg.at(4));
    this->setLinemate(msg.at(5));
    this->setDeraumere(msg.at(6));
    this->setSibur(msg.at(7));
    this->setMendiane(msg.at(8));
    this->setPhiras(msg.at(9));
    this->setThystame(msg.at(10));
}