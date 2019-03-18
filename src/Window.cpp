/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window class file
*/

#include "../include/Window.hpp"
#include "../include/Player.hpp"
#include "../include/Tile.hpp"
#include "../include/Inventory.hpp"
#include "../include/Team.hpp"

Window::Window(World *world)
{
        this->_world = world;
        this->_settings = new sf::ContextSettings();
        // this->_settings->antialiasingLevel = 8;
        this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "The Eye");
}

Window::~Window()
{
}

void Window::display()
{
    Inventory *inventory = new Inventory();
    Team *team = new Team();
    bool drawTeam = false;

    while (this->_window->isOpen())
    {
        sf::Event event;
        while (this->_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->_window->close();
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                this->_world->checkClickPlayer(*inventory, this->_window);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                drawTeam = true;
            else
                drawTeam = false;
        }
        //init item
        this->_window->clear();
        //Draw items :
        inventory->drawInventory(this->_window);
        this->_world->display(this->_window);
        if (drawTeam)
            team->drawTeam(this->_window, this->_world->team1, this->_world->team2);
        this->_window->display();
    }
}