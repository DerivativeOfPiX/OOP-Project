#include "BrightWood.hpp"

BrightWood::BrightWood(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2478, 248, 80, 80};
    init_x = x;
    init_y = y;
}

void BrightWood::draw()
{
    Block::draw(src, mover);
}

int BrightWood::get_x()
{
    return init_x;
}
int BrightWood::get_y()
{
    // displacement += 5;
    return init_y;
}
int BrightWood::get_w()
{
    return mover.w;
}

int BrightWood::get_h()
{
    return mover.h;
}

bool BrightWood::operator==(const BrightWood &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}