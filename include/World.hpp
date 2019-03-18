/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** World
*/

#ifndef WORLD_HPP_
	#define WORLD_HPP_

#include "Tile.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include <vector>
#include <sstream>
#include "IWindow.hpp"
#include "Box.hpp"

class Controller;

class World {
	public:
		World(Controller *Controller);
		~World();

        void initWorld();
		std::vector<Tile*> &getMap();
		void display(sf::RenderWindow *w);
		void displayMap(sf::RenderWindow *w);
		void displayPlayer(sf::RenderWindow *w);
        std::vector<Player *> &getPlayers();
        Player *getPlayerById(int id);
        void addPlayer(Player *player);
        void rmPlayer(int id);
		std::vector<Tile *> create();
		void refreshPlayer();
        void checkClickPlayer(Inventory &inv, sf::RenderWindow *window);
        void updateTile(std::vector<std::string> parameters);

        void setHeight(int height);
        void setWidth(int width);

        int getHeight(void);
        int getWidth(void);

        Box *_box;
        int team1 = 0;
        int team2 = 0;
	protected:
        int _width;
        int _height;
        std::vector<Player *> _players;
        std::vector<Tile*> _map;
        Controller *_controller;
};

#endif /* !WORLD_HPP_ */
