/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:20:23 by alaparic          #+#    #+#             */
/*   Updated: 2026/07/22 00:33:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.hpp"
#include "../include/Object.hpp"

/* float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f}; */

int main(int argc, char **argv)
{
	if (argc <= 1 || argc > 3)
	{
		std::cerr << "Usage: " << argv[0] << " <model>.obj" << std::endl;
		return (-1);
	}
	std::cout << "Loading model: " << argv[1] << std::endl;
	std::cout << "Texture: " << (argc == 3 ? argv[2] : "none") << std::endl;

	Object obj;

	try
	{
		obj.parser(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
