/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Team
*/

#ifndef TEAM_HPP_
	#define TEAM_HPP_

#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.hpp"

class Team {
	public:
		Team();
		~Team();
		void drawTeam(sf::RenderWindow *window, int team1, int team2);
	protected:
		sf::Font _font;
		sf::Text _team1;
		sf::Text _team2;
		sf::Text _name1;
		sf::Text _name2;
};

#endif /* !TEAM_HPP_ */