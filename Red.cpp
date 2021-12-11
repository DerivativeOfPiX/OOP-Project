#include "Red.hpp"

Red::Red(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2478, 166, 80, 80};
    init_x = x;
    init_y = y;
}

void Red::draw()
{
    Block::draw(src, mover);
}

int Red::get_x()
{
    return init_x;
}
int Red::get_y()
{
    // displacement += 5;
    return init_y;
}
int Red::get_w()
{
    return mover.w;
}

int Red::get_h()
{
    return mover.h;
}

bool Red::operator==(const Red &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}