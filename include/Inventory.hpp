/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Inventory
*/

#ifndef INVENTORY_HPP_
	#define INVENTORY_HPP_

    #include <SFML/Graphics.hpp>

class Inventory {
	public:
		Inventory();
		~Inventory();
        sf::Sprite getFood() const;
        sf::Sprite getLinemate() const;
        sf::Sprite getDeraumere() const;
        sf::Sprite getSibur() const;
        sf::Sprite getMendiane() const;
        sf::Sprite getPhiras() const;
        sf::Sprite getThystame() const;
        sf::Sprite getInventory_bar() const;
        void setFood(std::string nbr);
        void setLinemate(std::string nbr);
        void setDeraumere(std::string nbr);
        void setSibur(std::string nbr);
        void setMendiane(std::string nbr);
        void setPhiras(std::string nbr);
        void setThystame(std::string nbr);
        void drawInventory(sf::RenderWindow *window);
        void setAllInv(std::vector<std::string> inv);
	protected:
            sf::Font _font;
            sf::Text _nfood;
            sf::Text _nlinemate;
            sf::Text _nderaumere;
            sf::Text _nsibur;
            sf::Text _nmendiane;
            sf::Text _nphiras;
            sf::Text _nthystame;
            sf::Sprite _sfood;
            sf::Sprite _slinemate;
            sf::Sprite _sderaumere;
            sf::Sprite _ssibur;
            sf::Sprite _smendiane;
            sf::Sprite _sphiras;
            sf::Sprite _sthystame;
            sf::Sprite _sinventory_bar;
            sf::Texture _tfood;
            sf::Texture _tlinemate;
            sf::Texture _tderaumere;
            sf::Texture _tsibur;
            sf::Texture _tmendiane;
            sf::Texture _tphiras;
            sf::Texture _tthystame;
            sf::Texture _tinventory_bar;
	private:
};

#endif /* !INVENTORY_HPP_ */
