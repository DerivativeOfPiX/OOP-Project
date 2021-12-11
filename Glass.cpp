#include "Glass.hpp"

Glass::Glass(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2642, 2, 80, 80};
    init_x = x;
    init_y = y;
}

void Glass::draw()
{
    Block::draw(src, mover);
}

int Glass::get_x()
{
    return init_x;
}
int Glass::get_y()
{
    // displacement += 5;
    return init_y;
}
int Glass::get_w()
{
    return mover.w;
}

int Glass::get_h()
{
    return mover.h;
}

bool Glass::operator==(const Glass &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}