#pragma once
#include <SDL.h>
#include "Dirt.hpp"
#include <list>
#include "DirtG.hpp"
#include "Player.hpp"
#include "Sand.hpp"
#include "Ice.hpp"
#include "Red.hpp"
#include "Green.hpp"
#include "BrightWood.hpp"
#include "DarkWood.hpp"
#include "Stone.hpp"
#include "Glass.hpp"
#include "Coal.hpp"
#include "Gold.hpp"
#include <iostream>
using namespace std;

class Minecraft
{
    list<Dirt> dirts;
    list<DirtG> dirtgs;
    list<Sand> sands;
    list<Gold> golds;
    list<Ice> ices;
    list<Green> greens;
    list<Red> reds;
    list<Coal> coals;
    list<BrightWood> brightwoods;
    list<DarkWood> darkwoods;
    list<Glass> glasses;
    list<Stone> stones;
    Player *p;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    int make_full;
    bool make_new;
    int reset_dim;
    bool home_screen;
    bool storage_screen;
    bool exit_clicked;
    int ndirts, ndirtgs, ncoals, nglass, nice, ngrass, ngold, nred, nsand, nstone, nwood, nbright;
    bool jumping;
    int current_block;

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
    bool at_home();
    bool at_play();
    bool at_storage();
    bool exit_click();
    SDL_Rect no_of_blk(int n);
    void goto_game();
    int random_gen_1();
    int random_gen_2();
    void check_fall();
    bool moveable(int a);
    void jump();
    void jump_done();
    bool game_over();
    void reset(SDL_Renderer *renderer, SDL_Texture *asst);
    void goto_home();
    void delete_stuff();
};
