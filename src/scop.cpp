/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:20:27 by alaparic          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:27 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scop.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

Scop::Scop(int width, int height, const char *title)
	: _width(width), _height(height), _title(title), _window(NULL), _running(true), _rotation(0.0f) {}

Scop::~Scop()
{
	close();
}

bool Scop::init()
{
	if (!glfwInit())
	{
		std::cerr << "Error: Failed to initialize GLFW" << std::endl;
		return false;
	}

	// Set OpenGL context version to 2.1 for compatibility
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Create window
	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (!_window)
	{
		std::cerr << "Error: Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Make the window's context current
	glfwMakeContextCurrent(_window);

	// Enable vsync
	glfwSwapInterval(1);

	// Setup OpenGL
	setupOpenGL();

	// Load 3D models
	loadModels();

	return true;
}

void Scop::setupOpenGL()
{
	// Set viewport
	glViewport(0, 0, _width, _height);

	// Set clear color (dark blue)
	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Setup projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set perspective (fov, aspect ratio, near, far)
	float aspectRatio = (float)_width / (float)_height;
	float fov = 45.0f;
	float nearPlane = 0.1f;
	float farPlane = 100.0f;

	// Manual perspective calculation (since we're using OpenGL 2.1)
	float f = 1.0f / tan(fov * 0.5f * 3.14159265f / 180.0f);
	float perspectiveMatrix[16] = {
		f / aspectRatio, 0, 0, 0,
		0, f, 0, 0,
		0, 0, (farPlane + nearPlane) / (nearPlane - farPlane), -1,
		0, 0, (2 * farPlane * nearPlane) / (nearPlane - farPlane), 0};
	glLoadMatrixf(perspectiveMatrix);

	// Switch back to modelview
	glMatrixMode(GL_MODELVIEW);
}

void Scop::loadModels()
{
	// TODO: Load OBJ models (teapot.obj, 42.obj)
	// This would involve parsing the .obj and .mtl files
}

void Scop::drawScene()
{
	// Clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Position camera (eye position, look at, up vector)
	// Move camera back 5 units on Z axis
	glTranslatef(0.0f, 0.0f, -5.0f);

	// Rotate the cube
	glRotatef(_rotation, 1.0f, 1.0f, 0.0f);

	// Draw the cube
	drawCube();

	// Swap buffers
	glfwSwapBuffers(_window);
}
void Scop::update()
{
	// Update game state, animations, etc.
	// Rotate the cube slowly
	_rotation += 0.5f;
	if (_rotation >= 360.0f)
		_rotation -= 360.0f;
}

void Scop::drawCube()
{
	// Draw a cube using immediate mode (glBegin/glEnd)
	// Each face is defined by 4 vertices

	glBegin(GL_QUADS);

	// Front face (Red)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	// Back face (Green)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Top face (Blue)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// Bottom face (Yellow)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face (Magenta)
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Left face (Cyan)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	glEnd();
}

void Scop::render()
{
	if (_window)
		drawScene();
}

void Scop::run()
{
	while (!shouldClose() && !glfwWindowShouldClose(_window))
	{
		update();
		render();
		glfwPollEvents();
	}
}

bool Scop::shouldClose() const
{
	return !_running;
}

void Scop::close()
{
	_running = false;
	if (_window)
	{
		glfwDestroyWindow(_window);
		_window = NULL;
	}
	glfwTerminate();
}
