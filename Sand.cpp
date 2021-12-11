#include "Sand.hpp"

Sand::Sand(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2560, 166, 80, 80};
    init_x = x;
    init_y = y;
}

void Sand::draw()
{
    Block::draw(src, mover);
}

int Sand::get_x()
{
    return init_x;
}
int Sand::get_y()
{
    // displacement += 5;
    return init_y;
}
int Sand::get_w()
{
    return mover.w;
}

int Sand::get_h()
{
    return mover.h;
}

bool Sand::operator==(const Sand &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}