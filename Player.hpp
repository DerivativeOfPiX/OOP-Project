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
    bool bw_animate;

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
    int get_ndirts();
    int get_ndirtgs();
    int get_nsand();
    int get_ncoals();
    int get_nglass();
    int get_nice();
    int get_ngrass();
    int get_ngold();
    int get_nred();
    int get_nwood();
    int get_nbright();
    int get_nstone();
    void move_down();
    void jump();
    bool is_alive();
};