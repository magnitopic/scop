/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:31 by alaparic          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:01 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Parser.hpp"

Parser::Parser()
{
}

Parser::Parser(const Parser &copy)
{
	*this = copy;
}

Parser &Parser::operator=(const Parser &assign)
{
	if (this != &assign)
	{
		// Copy member variables here
	}
	return *this;
}

Parser::~Parser() {}
