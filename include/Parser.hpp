/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:49:15 by alaparic          #+#    #+#             */
/*   Updated: 2026/08/05 13:06:27 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>

class Parser
{
public:
	Parser();
	Parser(const Parser &copy);
	Parser &operator=(const Parser &assign);
	~Parser();
};

#endif
