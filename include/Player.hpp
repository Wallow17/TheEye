/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

#include "Object/Object.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Raise.h"

class Player {
	public:
		Player(int id, int x, int y, int orientation, std::string level, const std::string &team);
        Player(Player &player, int x, int y, int orientation);
		~Player();
        Player() {}
        sf::Sprite getSprite(void) const;
        void setInventory(std::vector<std::string> inventory);
        std::vector<std::string> getInventory(void);
        int getId(void) const;
        std::string getLevel(void) const;
        std::string getTeam() const;
        sf::Text _tLevel;
	protected:
        int _id;
        int _x;
        int _y;
        std::string _level;
        int _orientation;
        std::string _team;
        std::vector<std::string> _inventory;
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Font _fLevel;
	private:
};

#endif /* !PLAYER_HPP_ */
