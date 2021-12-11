#include "Ice.hpp"

Ice::Ice(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2724, 84, 80, 80};
    init_x = x;
    init_y = y;
}

void Ice::draw()
{
    Block::draw(src, mover);
}

int Ice::get_x()
{
    return init_x;
}
int Ice::get_y()
{
    // displacement += 5;
    return init_y;
}
int Ice::get_w()
{
    return mover.w;
}

int Ice::get_h()
{
    return mover.h;
}

bool Ice::operator==(const Ice &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}