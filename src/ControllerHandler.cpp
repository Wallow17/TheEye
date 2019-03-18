/*
** EPITECH PROJECT, 2019
** ControllerHandle.cpp
** File description:
** ControllerHandle class file
*/

#include "../include/Controller.hpp"

void Controller::msz(std::vector<std::string> parameters)
{
    this->_world->setHeight(stoi(parameters[1]));
    this->_world->setWidth(stoi(parameters[2]));
}

void Controller::bct(std::vector<std::string> parameters)
{
    if (parameters.size() == 10)
        this->_world->updateTile(parameters);
}

void Controller::pnw(std::vector<std::string> parameters)
{
    int x = stoi(parameters[2]);
    int y = stoi(parameters[3]);

    Player *player = new Player(atoi(parameters[1].c_str()), x, y,  atoi(parameters[4].c_str()), parameters[5], parameters[6]);
    this->_world->addPlayer(player);
}

void Controller::pin(std::vector<std::string> parameters)
{
    this->_answer = parameters;
}

void Controller::pex(std::vector<std::string> parameters)
{
    this->_world->rmPlayer(atoi(parameters[1].c_str()));
}

void Controller::pbc(std::vector<std::string> parameters)
{
    this->_world->_box->set("Player " + parameters[1] + ": " + parameters[2]);
}

void Controller::pic(std::vector<std::string> parameters)
{
    // this->_world->addIncantation(parameters);
    this->_world->_box->set("Player " + parameters[1] + " started an incantation");
}

void Controller::pie(std::vector<std::string> parameters)
{
    // this->_world->rmIncantation(parameters);
    this->_world->_box->set("Player " + parameters[1] + " ended an incantation");
}

void Controller::pfk(std::vector<std::string> parameters)
{
    // this->_world->addPlayerEgg(parameters);
    this->_world->_box->set("Player " + parameters[1] + " laid an egg");
}

void Controller::pdr(std::vector<std::string> parameters)
{
    // this->_world->updateMap(parameters);
}
void Controller::pgt(std::vector<std::string> parameters)
{
}

void Controller::pdi(std::vector<std::string> parameters)
{
    this->_world->rmPlayer(atoi(parameters[1].c_str()));
}

void Controller::enw(std::vector<std::string> parameters)
{
    // this->_world->addPlayerEgg(parameters);
}

void Controller::eht(std::vector<std::string> parameters)
{
    // this->_world->hatchEgg(parameters);
}

void Controller::ebo(std::vector<std::string> parameters)
{
    // a discuter je ne sais pas ce que fais cette commande... Un addPlayer à l'emplacement de l'egg ?
}

void Controller::edi(std::vector<std::string> parameters)
{
    // this->_world->rmPlayer(parameters);
}

void Controller::seg(std::vector<std::string> parameters)
{
    // End of the game kill window ?
}

void Controller::smg(std::vector<std::string> parameters)
{
    std::cout << "Server " << ": " << parameters[1] << std::endl;
}

void Controller::suc(std::vector<std::string> parameters)
{
    std::cout << "Warning: Server recieved an unknown command." << std::endl;
}

void Controller::sbp(std::vector<std::string> parameters)
{
    std::cout << "Warning: Server recieved an invalid parameter." << std::endl;
}

void Controller::ppo(std::vector<std::string> parameters)
{
    int x = stoi(parameters[2]);
    int y = stoi(parameters[3]);

    Player *tmp = this->_world->getPlayerById(stoi(parameters[1]));
    this->_world->rmPlayer(tmp->getId());
    Player *player = new Player(*tmp, x, y, stoi(parameters[4]));
    this->_world->addPlayer(player);
}

void Controller::handleServerData(const std::string &msg)
{
    std::cout << "From thread: " << msg << std::endl;
    std::vector<std::string>commands =  { "msz", "bct", "pnw", "pin", "pex", "pbc", "pic", "pie", "pfk", "pdr", "pgt", "pdi",
                                        "enw", "eht", "ebo", "edi", "seg", "smg", "suc", "sbp", "ppo" };
    void (Controller::*tab[21])(std::vector<std::string> parameters) = { 
        &Controller::msz, &Controller::bct, &Controller::pnw, &Controller::pin, &Controller::pex, &Controller::pbc, &Controller::pic, &Controller::pie, &Controller::pfk,
        &Controller::pdr, &Controller::pgt, &Controller::pdi, &Controller::enw, &Controller::eht, &Controller::ebo,
        &Controller::edi, &Controller::seg, &Controller::smg, &Controller::suc, &Controller::sbp, &Controller::ppo };
    std::vector<std::string> parameters;
    size_t pos;
    size_t prev;
    int i = 0;

    while (i < commands.size()) {
        if (strncmp(commands[i].c_str(), msg.c_str(), 3) == 0) {
            pos = 0;
            prev = 0;
            while (pos < msg.length() && prev < msg.length()) {
                pos = msg.find(" ", prev);
                if (pos == std::string::npos)
                    pos = msg.length();
                parameters.push_back(msg.substr(prev, pos - prev));
                prev = pos + 1;
            }
            (this->*tab[i])(parameters);
            return;
        }
        i++;
    }
}

