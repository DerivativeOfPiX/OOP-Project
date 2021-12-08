#include "Player.hpp"
Player::Player(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Living_Things(rend, ast), mover(mov)
{
    src = {83, 83, 80, 80};
    right_most = false;
    left_most = false;
    displacement = 0;
}

void Player::draw()
{
    Living_Things::draw(src, mover);
}

void Player::move_right()
{
    displacement += 5;
    mover.x += 5;
    if (mover.x >= 750)
    {
        right_most = true;
    }
    left_most = false;
}

void Player::move_left()
{
    displacement -= 5;
    mover.x -= 5;
    if (mover.x <= 210)
    {
        left_most = true;
    }
    right_most = false;
}

int Player::get_x()
{

    return mover.x;
}

int Player::get_y()
{
    // displacement += 5;
    return mover.y;
}
int Player::get_w()
{
    return mover.w;
}

int Player::get_h()
{
    return mover.h;
}

int Player::get_displacement()
{
    return displacement;
}