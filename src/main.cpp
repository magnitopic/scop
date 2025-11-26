#include "scop.hpp"
#include "mlx_opengl.h"

int main()
{
    Scop app(800, 600, "SCOP Application");

    if (!app.init())
    {
        std::cerr << "Failed to initialize application." << std::endl;
        return -1;
    }
    while (!app.shouldClose())
    {
        app.update();
        app.render();
    }
    app.close();
    return 0;
}