/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:20:30 by alaparic          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:30 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
#define SCOP_HPP

#include <iostream>
#include <glad/glad.h>

typedef struct s_vec3
{
	float x;
	float y;
	float z;
} t_vec3;

// Forward declarations
struct GLFWwindow;

class Scop
{
public:
	Scop(int width = 800, int height = 600, const char *title = "SCOP");
	~Scop();

	bool	init();
	void	run();
	void	render();
	void	update();
	bool	shouldClose() const;
	void	close();

private:
	int			_width;
	int			_height;
	const char	*_title;
	GLFWwindow	*_window;
	bool		_running;
	float	_rotation; // For rotating the cube

	void	setupOpenGL();
	void	loadModels();
	void	drawScene();
	void	drawCube();
	
};

#endif // SCOP_HPP
