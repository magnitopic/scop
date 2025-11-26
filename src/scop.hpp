#ifndef SCOP_HPP
#define SCOP_HPP

#include <iostream>

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

	void	setupOpenGL();
	void	loadModels();
	void	drawScene();
};

#endif // SCOP_HPP
