/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:05:48 by alaparic          #+#    #+#             */
/*   Updated: 2026/08/05 13:14:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Object.hpp"

// Orthodox methods
Object::Object()
{
}

Object::Object(const Object &copy)
{
	*this = copy;
}

Object &Object::operator=(const Object &assign)
{
	if (this != &assign)
	{
	}
	return *this;
}

Object::~Object() {}

// Parsing file methods
std::ifstream Object::openFile(std::string const &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file");
	}
	return file;
}

void Object::parser(std::string const &filename)
{
	std::ifstream file = this->openFile(filename);

	std::string line;

	while (std::getline(file, line))
		std::cout << line << std::endl;

	file.close();
}
