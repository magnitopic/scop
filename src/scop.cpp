#include "scop.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

Scop::Scop(int width, int height, const char *title)
	: _width(width), _height(height), _title(title), _window(NULL), _running(true)
{
}

Scop::~Scop()
{
	close();
}

bool Scop::init()
{
	// Initialize GLFW
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

	// Your rendering code here
	// For now, just a clear screen

	// Swap buffers
	glfwSwapBuffers(_window);
}

void Scop::render()
{
	if (_window)
		drawScene();
}

void Scop::update()
{
	// Update game state, animations, etc.
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