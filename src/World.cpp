/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** World
*/

#include "../include/World.hpp"
#include "../include/Box.hpp"

// Ctor/Dtor
World::World(Controller *controller) : _controller(controller) 
{
    this->_box = new Box();
}

World::~World() {}

void World::setHeight(int height) {this->_height = height;}
void World::setWidth(int width) {this->_width = width;}
int World::getWidth() { return this->_width; }
int World::getHeight() { return this->_height; }

void World::initWorld(void)
{
    this->_controller->getMapSize();
    this->_controller->getMap();
    this->_controller->getMap();
}

void World::addPlayer(Player *player)
{
    this->_players.push_back(player);
    if (player->getTeam() == "team1")
        this->team1++;
    else
        this->team2++;
    std::cout << "team1: " << team1 << std::endl << " team2: " << team2 << std::endl;
}

void World::rmPlayer(int id)
{
    int i = 0;

    if (this->getPlayerById(id)->getTeam() == "team1")
        this->team1--;
    else
        this->team2--;
    std::cout << "team1: " << team1 << std::endl << " team2: " << team2 << std::endl;
    while (i < this->_players.size()) {
        if (_players[i]->getId() == id) {
            this->_players.erase(this->_players.begin() + i);
            break;
        }
        i++;
    }
}

std::vector<Tile*> &World::getMap() { return this->_map; }
std::vector<Player *> &World::getPlayers(void) { return this->_players; }

Player *World::getPlayerById(int id)
{
    for (int i = 0; i < this->_players.size(); i++) {
        if (this->_players[i]->getId() == id)
            return this->_players[i];
    }
}

std::vector<Tile *> World::create()
{
    std::istringstream output(_controller->getMap());
    std::vector<Tile *> newMap;
    std::string line;
    while (std::getline(output, line)) {
        std::istringstream iss(line);
        std::string result;
        if (std::getline(iss, result, ' ') && result == "bct") {
            std::string token;          // ET LA MONSIEUR EST CONTENT ?
            int q[9];                   // \.o./
            for (int i = 0; std::getline(iss, token, ' '); i++)
                q[i] = std::stoi(token);
            newMap.push_back(new Tile(q[0], q[1], q[2], q[3], q[4], q[5], q[6], q[7], q[8]));
        }
    }
    return newMap;
}

void World::updateTile(std::vector<std::string> parameters)
{
    for (int i = 0; i < this->_map.size(); i++) {
        if (this->_map[i]->getX() == stoi(parameters[1]) && this->_map[i]->getY() == stoi(parameters[2]))
            this->_map.erase(this->_map.begin() + i);
    }
    this->_map.push_back(new Tile(stoi(parameters[1]), stoi(parameters[2]), stoi(parameters[3]), stoi(parameters[4]), stoi(parameters[5]),
                stoi(parameters[6]), stoi(parameters[7]), stoi(parameters[8]), stoi(parameters[9])));
}

void World::display(sf::RenderWindow *w)
{
    displayMap(w);
    displayPlayer(w);
    _box->draw(w);
}

void World::displayMap(sf::RenderWindow *w) {
    for (auto &tile : _map) {
        w->draw(tile->_sTile);
        if (tile->_q0 > 0)
            w->draw(tile->_sFood);
        if (tile->_q1 > 0)
            w->draw(tile->_sLinemate);
        if (tile->_q2 > 0)
            w->draw(tile->_sDeraumere);
        if (tile->_q3 > 0)
            w->draw(tile->_sDeraumere);
        if (tile->_q4 > 0)
            w->draw(tile->_sSibur);
        if (tile->_q5 > 0)
            w->draw(tile->_sMendiane);
        if (tile->_q6 > 0)
            w->draw(tile->_sPhiras);
    }
}

void World::displayPlayer(sf::RenderWindow *w) {
    for (auto &player : _players) {
        w->draw(player->getSprite());
        w->draw(player->_tLevel);
    }
}

void World::checkClickPlayer(Inventory &inv, sf::RenderWindow *window)
{
    sf::Sprite act;
    sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    sf::FloatRect bounds;

    if (this->_players.empty())
        return ;
    for (int i = 0; i < this->_players.size(); i++) {
        act = this->_players.at(i)->getSprite();
        bounds = act.getGlobalBounds();
        if (bounds.contains(mouse)) {
            inv.setAllInv(this->_controller->getPlayerInventory(this->_players[i]->getId()));
            return ;
        }
    }
}
