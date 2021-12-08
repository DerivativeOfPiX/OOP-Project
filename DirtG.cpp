#include "DirtG.hpp"

DirtG::DirtG(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {83, 83, 80, 80};
    init_x = x;
    init_y = y;
}

void DirtG::draw()
{
    Block::draw(src, mover);
}

int DirtG::get_x()
{
    return init_x;
}
int DirtG::get_y()
{
    // displacement += 5;
    return init_y;
}
int DirtG::get_w()
{
    return mover.w;
}

int DirtG::get_h()
{
    return mover.h;
}

bool DirtG::operator==(const DirtG &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}