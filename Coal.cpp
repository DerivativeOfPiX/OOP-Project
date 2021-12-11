#include "Coal.hpp"

Coal::Coal(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2478, 2, 80, 80};
    init_x = x;
    init_y = y;
}

void Coal::draw()
{
    Block::draw(src, mover);
}

int Coal::get_x()
{
    return init_x;
}
int Coal::get_y()
{
    // displacement += 5;
    return init_y;
}
int Coal::get_w()
{
    return mover.w;
}

int Coal::get_h()
{
    return mover.h;
}

bool Coal::operator==(const Coal &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}