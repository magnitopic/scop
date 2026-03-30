/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:20:23 by alaparic          #+#    #+#             */
/*   Updated: 2026/03/26 19:26:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/* glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); */
	/* glfwWindowHint(GLFW_FLOATING, GLFW_TRUE); */
	// TODO -> add os check
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "scop", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

/* int main(int argc, char **argv)
{
	if (argc <= 1 || argc > 3)
	{
		std::cerr << "Usage: " << argv[0] << " <model>.obj" << std::endl;
		return (-1);
	}
	std::cout << "Loading model: " << argv[1] << std::endl;
	std::cout << "Texture: " << (argc == 3 ? argv[2] : "none") << std::endl;

	Scop app(800, 600, "SCOP Application");

	if (!app.init())
	{
		std::cerr << "Failed to initialize application." << std::endl;
		return (-2);
	}

	app.run();

	return (0);
} */