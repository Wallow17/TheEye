/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Window header file
*/

#ifndef WINDOW_HPP_
	#define WINDOW_HPP_

#include "IWindow.hpp"
#include "World.hpp"
#include "Controller.hpp"

class Window : public IWindow {
	public:
		Window(World *world);
		virtual ~Window();
        	void display();
        sf::RenderWindow *_window;
	protected:
        sf::ContextSettings *_settings;
        World *_world;
	private:
};

#endif /* !WINDOW_HPP_ */
