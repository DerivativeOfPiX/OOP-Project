#pragma once
#include <SDL.h>
#include "Dirt.hpp"
#include <list>
#include "DirtG.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

class Minecraft
{
    list<Dirt> dirts;
    list<DirtG> dirtgs;
    Player *p;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    int make_full;
    bool make_new;
    int reset_dim;

public:
    int screen_scrolled;
    Minecraft(SDL_Renderer *, SDL_Texture *);
    void drawObjects();
    void createObjects(int, int);
    void create_init();
    void move_right();
    void move_left();
    void shift_screen(int, int);
    Player *get_player();
    void mouse_click(int a, int b);
};
