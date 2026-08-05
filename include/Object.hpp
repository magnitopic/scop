/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:06:18 by alaparic          #+#    #+#             */
/*   Updated: 2026/08/05 14:29:27 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <vector>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

class Object
{

private:
	std::vector<float> vertices;
	std::vector<float> faces;
	std::regex vertexPattern = std::regex(R"(^v\s+(-?\d+(?:\.\d+)?)\s+(-?\d+(?:\.\d+)?)\s+(-?\d+(?:\.\d+)?)\s*$)");
	std::regex tokenPattern = std::regex(R"(^(\d+)(?:\/(\d*)(?:\/(\d+))?)?$)");

	std::ifstream openFile(std::string const &filename);
	std::vector<float> parseFaceLine(const std::string &line);

public:
	Object();
	Object(const Object &copy);
	Object &operator=(const Object &assign);
	~Object();

	void parser(std::string const &filename);
};

#endif
