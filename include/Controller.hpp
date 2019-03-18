/*
** EPITECH PROJECT, 2019
** Controller.hpp
** File description:
** Controller header file
*/

#ifndef CONTROLLER_HPP_
	#define CONTROLLER_HPP_

#include "Client.hpp"
#include "Player.hpp"
#include <thread>
#include <iostream>
#include <vector>
#include "IWindow.hpp"

class World;

class Controller : public Client {
	public:
        typedef void (Controller::*functions)();

		Controller(char *ip, int port);
		~Controller();

        void getServerData(World *world);
        void handleServerData(const std::string &msg);

        std::vector<std::string> getAnswer(void);
        std::string getMap(void);
        std::string getMapSize(void);
        std::string getTeams(void);
        std::string getPlayerPos(int id);
        std::string getPlayerLvl(int id);
        std::vector<std::string> getPlayerInventory(int id);
        std::string getTimeUnit(void);
        std::string setTimeUnit(float unit);

        void msz(std::vector<std::string> parameters);
        void bct(std::vector<std::string> parameters);
        void pnw(std::vector<std::string> parameters);
        void pin(std::vector<std::string> parameters);
        void pex(std::vector<std::string> parameters);
        void pbc(std::vector<std::string> parameters);
        void pic(std::vector<std::string> parameters);
        void pie(std::vector<std::string> parameters);
        void pfk(std::vector<std::string> parameters);
        void pdr(std::vector<std::string> parameters);
        void pgt(std::vector<std::string> parameters);
        void pdi(std::vector<std::string> parameters);
        void enw(std::vector<std::string> parameters);
        void eht(std::vector<std::string> parameters);
        void ebo(std::vector<std::string> parameters);
        void edi(std::vector<std::string> parameters);
        void seg(std::vector<std::string> parameters);
        void smg(std::vector<std::string> parameters);
        void suc(std::vector<std::string> parameters);
        void sbp(std::vector<std::string> parameters);
        void ppo(std::vector<std::string> parameters);

	protected:
        World *_world;
        std::vector<std::string> _answer;

	private:
};

#endif /* !CONTROLLER_HPP_ */
