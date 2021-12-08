#include "Minecraft.hpp"

Minecraft::Minecraft(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst)
{
    SDL_Rect mov = {480, 400, 40, 40};
    p = new Player(renderer, asst, mov);
    make_full = 0;
    make_new = false;
    screen_scrolled = 0;
    reset_dim = 0;
}
void Minecraft::create_init()
{
    int x = 0;
    int y = 560;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            SDL_Rect mov = {x, y, 40, 40};
            Dirt d1(gRenderer, assets, mov, x, y);
            dirts.push_back(d1);
            x += 40;
        }
        x = 0;
        y -= 40;
    }
    y = 440;
    for (int i = 0; i < 25; i++)
    {
        SDL_Rect mov = {x, y, 40, 40};
        DirtG d1(gRenderer, assets, mov, x, y);
        dirtgs.push_back(d1);
        x += 40;
    }
    // SDL_Rect mov = {480, 400, 40, 40};
    // Player a(gRenderer, assets, mov);
    // p = a;
}
void Minecraft::drawObjects()
{

    if (p->right_most)
    {
        shift_screen(1, p->mover.x);
    }
    else if (p->left_most)
    {
        shift_screen(0, p->mover.x);
    }

    for (Dirt &a : dirts)
    {
        a.draw();
    }
    for (DirtG &b : dirtgs)
    {
        b.draw();
    }

    p->draw();
}

void Minecraft::move_right()
{
    p->move_right();
    if (p->right_most)
    {
        screen_scrolled += 5;
        if (reset_dim == 40)
        {
            reset_dim = 0;
        }
        reset_dim += 5;
        if (make_full == 0 && !(make_new))
        {
            make_new = true;
            SDL_Rect mov = {1000, 440, 40, 40};
            DirtG d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
            dirtgs.push_back(d1);
            make_full += 5;
            int y = 480;
            for (int i = 0; i < 3; i++)
            {
                SDL_Rect mov = {1000, y, 40, 40};
                Dirt d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                dirts.push_back(d1);
                y += 40;
            }
        }
        if (make_full < 40 && make_new)
        {
            make_full += 5;
        }
        else if (make_full >= 40 && make_new)
        {
            make_full = 0;
            make_new = false;
        }
    }
}

void Minecraft::move_left()
{

    p->move_left();
    if (p->left_most)
    {
        screen_scrolled -= 5;
        if (reset_dim == -40)
        {
            reset_dim = 0;
        }
        reset_dim -= 5;
        if (make_full == 0 && !(make_new))
        {
            make_new = true;
            SDL_Rect mov = {-40, 440, 40, 40};
            DirtG d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
            dirtgs.push_back(d1);
            make_full += 5;
            int y = 480;
            for (int i = 0; i < 3; i++)
            {
                SDL_Rect mov = {-40, y, 40, 40};
                Dirt d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                dirts.push_back(d1);
                y += 40;
            }
        }
        if (make_full < 40 && make_new)
        {
            make_full += 5;
        }
        else if (make_full >= 40 && make_new)
        {
            make_full = 0;
            make_new = false;
        }
    }
}

void Minecraft::shift_screen(int side, int units)
{
    if (side == 1)
    {
        units = units - 750;
        for (Dirt &a : dirts)
        {
            a.mover.x -= units;
        }
        for (DirtG &b : dirtgs)
        {
            b.mover.x -= units;
        }

        p->mover.x -= units;
    }
    else if (side == 0)
    {
        units = 210 - units;
        for (Dirt &a : dirts)
        {
            a.mover.x += units;
        }
        for (DirtG &b : dirtgs)
        {
            b.mover.x += units;
        }

        p->mover.x += units;
    }
}

Player *Minecraft::get_player()
{
    return p;
}
void Minecraft::mouse_click(int x, int y)
{
    bool block_present = false;
    for (DirtG &b : dirtgs)
    {
        if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
        {
            dirtgs.remove(b);
            block_present = true;
        }
    }
    for (Dirt &b : dirts)
    {
        if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
        {
            dirts.remove(b);
            block_present = true;
        }
    }
    if (!block_present)
    {
        int new_x = (x) / (40 - reset_dim);
        new_x = (new_x * (40 - reset_dim));
        int new_y = y / (40);
        new_y = (new_y * 40);
        SDL_Rect mov = {new_x, new_y, 40, 40};
        Dirt d1(gRenderer, assets, mov, new_x, new_y);
        dirts.push_back(d1);
    }
}