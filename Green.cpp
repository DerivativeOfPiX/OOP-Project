#include "Green.hpp"

Green::Green(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2642, 84, 80, 80};
    init_x = x;
    init_y = y;
}

void Green::draw()
{
    Block::draw(src, mover);
}

int Green::get_x()
{
    return init_x;
}
int Green::get_y()
{
    // displacement += 5;
    return init_y;
}
int Green::get_w()
{
    return mover.w;
}

int Green::get_h()
{
    return mover.h;
}

bool Green::operator==(const Green &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}