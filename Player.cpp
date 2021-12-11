#include "Player.hpp"
#include <iostream>
Player::Player(SDL_Renderer *rend, SDL_Texture *ast, SDL_Rect mov) : Living_Things(rend, ast), mover(mov)
{
    src = {1733, 322, 132, 263};
    right_most = false;
    left_most = false;
    displacement = 0;
    bw_animate = false;
}

void Player::draw()
{
    Living_Things::draw(src, mover);
}

void Player::move_right()
{
    // if (!bw_animate)
    // {
    if (src.x == 1733 && src.y == 322)
    {
        src.x = 1533;
        src.y = 22;
        src.h = 262;
        src.w = 132;
    }
    else if (src.x == 1533 && src.y == 22)
    {
        src.x = 1708;
        src.y = 12;
        src.h = 270;
        src.w = 153;
    }
    else if (src.x == 1708 && src.y == 12)
    {
        src.x = 1893;
        src.y = 3;
        src.h = 250;
        src.w = 179;
        // bw_animate = true;
    }
    else if (src.x == 1893 && src.y == 3)
    {
        src.x = 2111;
        src.y = 12;
        src.h = 270;
        src.w = 154;
    }
    else if (src.x == 2111 && src.y == 12)
    {
        src.x = 2341;
        src.y = 22;
        src.h = 263;
        src.w = 132;
    }
    else if (src.x == 2341 && src.y == 22)
    {
        src.x = 1913;
        src.y = 312;
        src.h = 269;
        src.w = 148;
    }
    else if (src.x == 1913 && src.y == 312)
    {
        src.x = 2095;
        src.y = 303;
        src.h = 243;
        src.w = 177;
    }
    else if (src.x == 2095 && src.y == 303)
    {
        src.x = 2309;
        src.y = 312;
        src.h = 265;
        src.w = 159;
    }
    else
    {
        src = {1733, 322, 132, 263};
    }
    // }
    // else if (bw_animate)
    // {
    //     if (src.x == 1549 && src.y == 303)
    //     {
    //         src.x = 1565;
    //         src.y = 12;
    //         src.h = 265;
    //         src.w = 159;
    //     }
    //     else if (src.x == 1565 && src.y == 12)
    //     {
    //         src.x = 1367;
    //         src.y = 312;
    //         src.h = 269;
    //         src.w = 148;
    //     }
    //     else if (src.x == 1367 && src.y == 312)
    //     {
    //         src.x = 1187;
    //         src.y = 322;
    //         src.h = 263;
    //         src.w = 132;
    //         bw_animate = false;
    //     }
    //     else
    //     {
    //         bw_animate = false;
    //         src = {611, 322, 132, 263};
    //     }
    // }
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
    // if (!bw_animate)
    // {
    // std::cout << "x" << get_x();
    // std::cout << "y" << get_y();
    if (src.x == 1157 && src.y == 322)
    {
        src.x = 1357;
        src.y = 22;
        src.h = 262;
        src.w = 132;
    }
    else if (src.x == 1357 && src.y == 22)
    {
        src.x = 1161;
        src.y = 12;
        src.h = 270;
        src.w = 153;
    }
    else if (src.x == 1161 && src.y == 12)
    {
        src.x = 950;
        src.y = 3;
        src.h = 250;
        src.w = 179;
        // bw_animate = true;
    }
    else if (src.x == 950 && src.y == 3)
    {
        src.x = 757;
        src.y = 12;
        src.h = 270;
        src.w = 154;
    }
    else if (src.x == 757 && src.y == 12)
    {
        src.x = 549;
        src.y = 22;
        src.h = 263;
        src.w = 132;
    }
    else if (src.x == 549 && src.y == 22)
    {
        src.x = 961;
        src.y = 312;
        src.h = 269;
        src.w = 148;
    }
    else if (src.x == 961 && src.y == 312)
    {
        src.x = 750;
        src.y = 303;
        src.h = 243;
        src.w = 177;
    }
    else if (src.x == 750 && src.y == 303)
    {
        src.x = 554;
        src.y = 312;
        src.h = 265;
        src.w = 159;
    }

    else
    {
        src = {1157, 322, 132, 263};
    }
    // }
    // else if (bw_animate)
    // {
    //     if (src.x == 204 && src.y == 303)
    //     {
    //         src.x = 211;
    //         src.y = 12;
    //         src.h = 265;
    //         src.w = 159;
    //     }
    //     else if (src.x == 211 && src.y == 12)
    //     {
    //         src.x = 415;
    //         src.y = 312;
    //         src.h = 269;
    //         src.w = 148;
    //     }
    //     else if (src.x == 415 && src.y == 312)
    //     {
    //         src.x = 611;
    //         src.y = 322;
    //         src.h = 263;
    //         src.w = 132;
    //         bw_animate = false;
    //     }
    //     else
    //     {
    //         bw_animate = false;
    //         src = {611, 322, 132, 263};
    //     }
    // }
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

void Player::move_down()
{
    mover.y += 2;
}
void Player::jump()
{
    mover.y -= 2;
}

bool Player::is_alive()
{
    if (mover.y <= 600)
    {
        return true;
    }
    return false;
}