#pragma once
#include <SDL.h>
#include "Living_Things.hpp"

class Player : public Living_Things
{
public:
    SDL_Rect src, mover;
    int frame_no;
    bool right_most;
    bool left_most;
    int displacement;

    // public:
    Player(SDL_Renderer *, SDL_Texture *, SDL_Rect);
    void draw();
    void move_right();
    void move_left();
    int get_x();
    int get_y();
    int get_w();
    int get_h();
    int get_displacement();
};