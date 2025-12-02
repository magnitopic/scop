#include "scop.hpp"

int main(int argc, char **argv)
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
}