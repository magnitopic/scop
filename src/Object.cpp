/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:05:48 by alaparic          #+#    #+#             */
/*   Updated: 2026/08/05 14:38:59 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Object.hpp"

// Orthodox methods
Object::Object() {}

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

std::vector<unsigned int> Object::parseFaceLine(const std::string &line)
{
	std::vector<unsigned int> indices;
	std::istringstream iss(line);
	std::string tag, token;

	iss >> tag;

	while (iss >> token)
	{
		std::smatch match;

		if (std::regex_match(token, match, tokenPattern))
		{
			unsigned int index = std::stoul(match[1]);
			indices.push_back(index - 1);
		}
	}

	std::vector<unsigned int> triangles;

	if (indices.size() < 3)
		return triangles;

	// Triangle fan triangulation
	for (size_t i = 1; i + 1 < indices.size(); ++i)
	{
		triangles.push_back(indices[0]);
		triangles.push_back(indices[i]);
		triangles.push_back(indices[i + 1]);
	}

	return triangles;
}


void Object::parser(std::string const &filename)
{
	std::ifstream file = this->openFile(filename);

	std::string line;

	while (std::getline(file, line))
	{
		std::smatch match;

		// Checking for vertex lines
		if (std::regex_match(line, match, vertexPattern))
		{
			float x = std::stof(match[1]);
			float y = std::stof(match[2]);
			float z = std::stof(match[3]);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);
		}
		else
		{
			// Checking for face lines
			if (line.rfind("f ", 0) == 0)
			{
				std::vector<unsigned int> face = parseFaceLine(line);
				for (const auto &fv : face)
					faces.push_back(fv);
			}
		}
	}

	if (vertices.empty())
	{
		throw std::runtime_error("Invalid .obj file: No vertices found");
	}

	std::cout << "Parsed " << vertices.size() << " vertices and " << faces.size() << " faces." << std::endl;

	file.close();
}
