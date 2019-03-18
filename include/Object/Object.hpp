/*
** EPITECH PROJECT, 2019
** OOP_theeye_2018
** File description:
** Object
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

#include <string>

class Object {
	public:
		Object(const std::string &name);
		~Object();
	protected:
        std::string _name;
};

#endif /* !OBJECT_HPP_ */