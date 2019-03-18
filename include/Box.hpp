/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Box
*/

#ifndef BOX_HPP_
	#define BOX_HPP_

#include "SFML/Graphics.hpp"

class Box {
	public:
		Box();
		~Box();

        void set(sf::String t);
        void draw(sf::RenderWindow *world);
	protected:
        sf::Font _font;
        sf::Text _text;
};

#endif /* !BOX_HPP_ */