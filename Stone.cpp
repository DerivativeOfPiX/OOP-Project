#include "Stone.hpp"

Stone::Stone(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2642, 166, 80, 80};
    init_x = x;
    init_y = y;
}

void Stone::draw()
{
    Block::draw(src, mover);
}

int Stone::get_x()
{
    return init_x;
}
int Stone::get_y()
{
    // displacement += 5;
    return init_y;
}
int Stone::get_w()
{
    return mover.w;
}

int Stone::get_h()
{
    return mover.h;
}

bool Stone::operator==(const Stone &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}