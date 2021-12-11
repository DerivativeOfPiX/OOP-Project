#include "Gold.hpp"

Gold::Gold(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2478, 84, 80, 80};
    init_x = x;
    init_y = y;
}

void Gold::draw()
{
    Block::draw(src, mover);
}

int Gold::get_x()
{
    return init_x;
}
int Gold::get_y()
{
    // displacement += 5;
    return init_y;
}
int Gold::get_w()
{
    return mover.w;
}

int Gold::get_h()
{
    return mover.h;
}

bool Gold::operator==(const Gold &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}