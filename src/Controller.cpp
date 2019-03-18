/*
** EPITECH PROJECT, 2019
** Controller.cpp
** File description:
** Controller.cpp
*/

#include "../include/Controller.hpp"

Controller::Controller(char *ip, int port) : Client(ip, port)
{
}

Controller::~Controller()
{
}

std::vector<std::string> Controller::getAnswer(void)
{
    return this->_answer;
}

void Controller::getServerData(World *world)
{
    std::string line;

    this->_world = world;
    while (1) {
        std::string msg = this->read();
        std::istringstream stream(msg);
        while (std::getline(stream, line)) {
            this->handleServerData(line);
        }
        stream.str("");
    }
}

std::string Controller::getMap(void)
{
    std::string result;

    this->write("mct");
    result = this->read();
    return result;
}

std::string Controller::getMapSize(void)
{
    std::string result;

    this->write("msz");
    return result;
}

std::string Controller::getTeams(void)
{
    std::string result;

    this->write("tna");
    result = this->read();
    return result;
}

std::string Controller::getPlayerPos(int id)
{
    std::string command = "ppo " + std::to_string(id);
    std::string result;

    this->write(command);
    result = this->read();
    return result;
}

std::string Controller::getPlayerLvl(int id)
{
    std::string command = "plv " + std::to_string(id);
    std::string result;

    this->write(command);
    result = this->read();
    return result;
}

std::vector<std::string> Controller::getPlayerInventory(int id)
{
    std::string command = "pin " + std::to_string(id);

    this->write(command);
    sleep(1);
    return this->_answer;
}

std::string Controller::getTimeUnit(void)
{
    std::string command = "sgt";
    std::string result;

    this->write(command);
    result = this->read();
    return result;
}

std::string Controller::setTimeUnit(float unit)
{
    std::string command = "sst " + std::to_string(unit);
    std::string result;
    
    this->write(command);
    result = this->read();
    return result;
}