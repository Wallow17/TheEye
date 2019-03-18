/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Tile
*/

#include "../include/Tile.hpp"
#include <iostream>

// Ctor/Dtor
Tile::Tile(int x, int y, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
        : _x(x), _y(y), _q0(q0), _q1(q1), _q2(q2), _q3(q3), _q4(q4), _q5(q5), _q6(q6) {
    if (!_tTile.loadFromFile("media/tile.png")
    || !_tFood.loadFromFile("media/food.png")
    || !_tLinemate.loadFromFile("media/linemate.png")
    || !_tDeraumere.loadFromFile("media/deraumere.png")
    || !_tSibur.loadFromFile("media/sibur.png")
    || !_tMendiane.loadFromFile("media/mendiane.png")
    || !_tPhiras.loadFromFile("media/phiras.png")
    || !_tThystame.loadFromFile("media/thystame.png"))
        raise("Error: Texture file not found");
    if (!_font.loadFromFile("media/arial.ttf"))
        raise("Font not found.");

    _sTile.setTexture(this->_tTile);
    _sTile.scale(0.5f, 0.5f);
    _sTile.setPosition(_x * 50, _y * 50);

    _sFood.setTexture(this->_tFood);
    _sFood.scale(0.5f, 0.5f);
    _sFood.setPosition(_x * 50, _y * 50);

    _sLinemate.setTexture(this->_tLinemate);
    _sLinemate.scale(0.5f, 0.5f);
    _sLinemate.setPosition(_x * 50 + 15, _y * 50);

    _sDeraumere.setTexture(this->_tDeraumere);
    _sDeraumere.scale(0.5f, 0.5f);
    _sDeraumere.setPosition(_x * 50 + 30, _y * 50);

    _sSibur.setTexture(this->_tSibur);
    _sSibur.scale(0.5f, 0.5f);
    _sSibur.setPosition(_x * 50, _y * 50 + 15);

    _sMendiane.setTexture(this->_tMendiane);
    _sMendiane.scale(0.5f, 0.5f);
    _sMendiane.setPosition(_x * 50 + 15, _y * 50 + 15);

    _sPhiras.setTexture(this->_tPhiras);
    _sPhiras.scale(0.5f, 0.5f);
    _sPhiras.setPosition(_x * 50 + 30, _y * 50 + 15);
    
    _sThystame.setTexture(this->_tThystame);
    _sThystame.scale(0.5f, 0.5f);
    _sThystame.setPosition(_x * 50, _y * 50 + 30);
}
Tile::~Tile() {}

int Tile::getX() const { return this->_x;}
int Tile::getY() const { return this->_y;}