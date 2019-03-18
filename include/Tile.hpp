/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Tile
*/

#ifndef TILE_HPP_
	#define TILE_HPP_

#include "Player.hpp"
#include "Object/Object.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Tile {
	public:
		Tile(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6);
		~Tile();

        int getX() const;
        int getY() const;
        void setRessources(std::vector<std::string> parameters);

		sf::Sprite _sTile;
		sf::Sprite _sFood;
		sf::Sprite _sLinemate;
		sf::Sprite _sDeraumere;
		sf::Sprite _sSibur;
		sf::Sprite _sMendiane;
		sf::Sprite _sPhiras;
		sf::Sprite _sThystame;
		int _q0;
		int _q1;
		int _q2;
		int _q3;
		int _q4;
		int _q5;
		int _q6;
	protected:
		int _x;
		int _y;
		sf::Texture _tTile;
		sf::Texture _tFood;
		sf::Texture _tLinemate;
		sf::Texture _tDeraumere;
		sf::Texture _tSibur;
		sf::Texture _tMendiane;
		sf::Texture _tPhiras;
		sf::Texture _tThystame;
		std::vector<Player*> _player;
		sf::Font _font;
};

#endif /* !TILE_HPP_ */
