#include "Dirt.hpp"

Dirt::Dirt(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov, int x, int y) : Block(rend, ast), mover(mov)
{
    src = {2560, 2, 80, 80};
    init_x = x;
    init_y = y;
}

void Dirt::draw()
{
    Block::draw(src, mover);
}
int Dirt::get_x()
{
    return init_x;
}

int Dirt::get_y()
{
    // displacement += 5;
    return init_y;
}
int Dirt::get_w()
{
    return mover.w;
}

int Dirt::get_h()
{
    return mover.h;
}

bool Dirt::operator==(const Dirt &a1)
{
    if (a1.mover.x == mover.x && a1.mover.y == mover.y)
    {
        return true;
    }
    return false;
}