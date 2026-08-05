/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:06:18 by alaparic          #+#    #+#             */
/*   Updated: 2026/08/05 13:11:49 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_


#include <vector>
#include <fstream>
#include <iostream>

class Object
{

private:
	std::vector<float> vertices;

	std::ifstream openFile(std::string const &filename);

public:
	Object();
	Object(const Object &copy);
	Object &operator=(const Object &assign);
	~Object();

	void parser(std::string const &filename);
};

#endif
