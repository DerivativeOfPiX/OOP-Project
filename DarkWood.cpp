#include "DarkWood.hpp"

DarkWood::DarkWood(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2478, 2, 80, 80};
    init_x = x;
    init_y = y;
}

void DarkWood::draw()
{
    Block::draw(src, mover);
}

int DarkWood::get_x()
{
    return init_x;
}
int DarkWood::get_y()
{
    // displacement += 5;
    return init_y;
}
int DarkWood::get_w()
{
    return mover.w;
}

int DarkWood::get_h()
{
    return mover.h;
}

bool DarkWood::operator==(const DarkWood &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}