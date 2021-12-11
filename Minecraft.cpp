#include "Minecraft.hpp"

Minecraft::Minecraft(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst)
{
    SDL_Rect mov = {480, 360, 40, 80};
    p = new Player(renderer, asst, mov);
    current_block = 2;
    jumping = false;
    make_full = 0;
    make_new = false;
    screen_scrolled = 0;
    reset_dim = 0;
    home_screen = true;
    storage_screen = false;
    exit_clicked = false;
    ndirtgs = 5;
    ndirts = 5;
    nsand = 5;
    nice = 5;
    nstone = 5;
    nwood = 5;
    nbright = 5;
    nred = 5;
    ncoals = 5;
    ngold = 5;
    nglass = 5;
    ngrass = 5;
}
void Minecraft::goto_game()
{
    storage_screen = false;
    home_screen = false;
}

bool Minecraft::at_storage()
{
    return storage_screen;
}

SDL_Rect Minecraft::no_of_blk(int n)
{
    SDL_Rect a;
    switch (n)
    {

    case 0:
        a = {1, 1, 51, 53};
        break;
    case 1:
        a = {54, 1, 51, 55};
        break;
    case 2:
        a = {107, 1, 50, 54};
        break;
    case 3:
        a = {159, 1, 46, 53};
        break;
    case 4:
        a = {207, 1, 46, 52};
        break;
    case 5:
        a = {255, 1, 46, 52};
        break;
    case 6:
        a = {303, 1, 48, 53};
        break;
    case 7:
        a = {353, 1, 47, 51};
        break;
    case 8:
        a = {402, 1, 46, 53};
        break;
    case 9:
        a = {450, 1, 47, 52};
        break;

    default:
        a = {450, 1, 47, 52};
        break;
    }
    return a;
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
    if (!jumping)
    {
        check_fall();
    }
    if (home_screen)
    {
        SDL_Rect src_1 = {15, 1349, 3802, 636};
        SDL_Rect mover_1 = {240, 150, 500, 100};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = {1285, 2751, 580, 137};
        mover_1 = {250, 300, 500, 100};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
    }
    else if (storage_screen)
    {
        SDL_Rect src_1 = {2, 2751, 1281, 723};
        SDL_Rect mover_1 = {0, 0, 1000, 600};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // dirtg
        src_1 = {2560, 84, 80, 80};
        mover_1 = {95, 110, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(ndirtgs);
        mover_1 = {220, 220, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // dirt
        src_1 = {2560, 2, 80, 80};
        mover_1 = {345, 110, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(ndirts);
        mover_1 = {480, 220, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // stone
        src_1 = {2642, 166, 80, 80};
        mover_1 = {595, 110, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nstone);
        mover_1 = {735, 220, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // wood
        src_1 = {2724, 166, 80, 80};
        mover_1 = {845, 110, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nwood);
        mover_1 = {975, 220, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);

        // sand
        src_1 = {2560, 166, 80, 80};
        mover_1 = {95, 320, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nsand);
        mover_1 = {220, 410, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // ice
        src_1 = {2724, 84, 80, 80};
        mover_1 = {345, 320, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nice);
        mover_1 = {480, 410, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // glass
        src_1 = {2642, 2, 80, 80};
        mover_1 = {595, 320, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nglass);
        mover_1 = {735, 410, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // bright
        src_1 = {2478, 248, 80, 80};
        mover_1 = {845, 320, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nbright);
        mover_1 = {975, 410, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // gold
        src_1 = {2478, 84, 80, 80};
        mover_1 = {95, 500, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(ngold);
        mover_1 = {220, 575, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // coal
        src_1 = {2478, 2, 80, 80};
        mover_1 = {345, 500, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(ncoals);
        mover_1 = {480, 575, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // grass
        src_1 = {2642, 84, 80, 80};
        mover_1 = {595, 500, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(ngrass);
        mover_1 = {735, 575, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        // red
        src_1 = {2478, 166, 80, 80};
        mover_1 = {845, 500, 60, 60};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
        src_1 = no_of_blk(nred);
        mover_1 = {975, 575, 20, 20};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
    }
    else
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
        for (Sand &b : sands)
        {
            b.draw();
        }
        for (Stone &b : stones)
        {
            b.draw();
        }
        for (Coal &b : coals)
        {
            b.draw();
        }
        for (Gold &b : golds)
        {
            b.draw();
        }
        for (Red &b : reds)
        {
            b.draw();
        }
        for (Green &b : greens)
        {
            b.draw();
        }
        for (BrightWood &b : brightwoods)
        {
            b.draw();
        }
        for (DarkWood &b : darkwoods)
        {
            b.draw();
        }
        for (Glass &b : glasses)
        {
            b.draw();
        }
        for (Ice &b : ices)
        {
            b.draw();
        }
        p->draw();
        SDL_Rect src_1 = {1867, 2751, 401, 51};
        SDL_Rect mover_1 = {0, 0, 240, 35};
        SDL_RenderCopy(gRenderer, assets, &src_1, &mover_1);
    }
}

void Minecraft::move_right()
{
    if (moveable(1))
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
                int a = random_gen_1();
                if (a == 1)
                {
                    DirtG d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    dirtgs.push_back(d1);
                }
                else if (a == 2)
                {
                    Dirt d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    dirts.push_back(d1);
                }
                else if (a == 3)
                {
                    Stone d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    stones.push_back(d1);
                }
                else if (a == 4)
                {
                    DarkWood d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    darkwoods.push_back(d1);
                }
                else if (a == 5)
                {
                    Sand d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    sands.push_back(d1);
                }
                else if (a == 6)
                {
                    Ice d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    ices.push_back(d1);
                }
                else if (a == 7)
                {
                    Glass d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    glasses.push_back(d1);
                }
                else if (a == 8)
                {
                    BrightWood d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    brightwoods.push_back(d1);
                }
                else if (a == 9)
                {
                    Gold d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    golds.push_back(d1);
                }
                else if (a == 10)
                {
                    Coal d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    coals.push_back(d1);
                }
                else if (a == 11)
                {
                    Green d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    greens.push_back(d1);
                }
                else
                {
                    Red d1(gRenderer, assets, mov, 995 + screen_scrolled, 440);
                    reds.push_back(d1);
                }

                make_full += 5;
                int y = 480;
                for (int i = 0; i < 3; i++)
                {

                    SDL_Rect mov = {1000, y, 40, 40};
                    int a = random_gen_2();
                    if (a == 1)
                    {
                        DirtG d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        dirtgs.push_back(d1);
                    }
                    else if (a == 2)
                    {
                        Dirt d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        dirts.push_back(d1);
                    }
                    else if (a == 3)
                    {
                        Stone d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        stones.push_back(d1);
                    }
                    else if (a == 4)
                    {
                        DarkWood d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        darkwoods.push_back(d1);
                    }
                    else if (a == 5)
                    {
                        Sand d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        sands.push_back(d1);
                    }
                    else if (a == 6)
                    {
                        Ice d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        ices.push_back(d1);
                    }
                    else if (a == 7)
                    {
                        Glass d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        glasses.push_back(d1);
                    }
                    else if (a == 8)
                    {
                        BrightWood d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        brightwoods.push_back(d1);
                    }
                    else if (a == 9)
                    {
                        Gold d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        golds.push_back(d1);
                    }
                    else if (a == 10)
                    {
                        Coal d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        coals.push_back(d1);
                    }
                    else if (a == 11)
                    {
                        Green d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        greens.push_back(d1);
                    }
                    else
                    {
                        Red d1(gRenderer, assets, mov, 995 + screen_scrolled, y);
                        reds.push_back(d1);
                    }
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
}

void Minecraft::move_left()
{
    if (moveable(0))
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
                int a = random_gen_1();
                if (a == 1)
                {
                    DirtG d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    dirtgs.push_back(d1);
                }
                else if (a == 2)
                {
                    Dirt d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    dirts.push_back(d1);
                }
                else if (a == 3)
                {
                    Stone d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    stones.push_back(d1);
                }
                else if (a == 4)
                {
                    DarkWood d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    darkwoods.push_back(d1);
                }
                else if (a == 5)
                {
                    Sand d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    sands.push_back(d1);
                }
                else if (a == 6)
                {
                    Ice d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    ices.push_back(d1);
                }
                else if (a == 7)
                {
                    Glass d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    glasses.push_back(d1);
                }
                else if (a == 8)
                {
                    BrightWood d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    brightwoods.push_back(d1);
                }
                else if (a == 9)
                {
                    Gold d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    golds.push_back(d1);
                }
                else if (a == 10)
                {
                    Coal d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    coals.push_back(d1);
                }
                else if (a == 11)
                {
                    Green d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    greens.push_back(d1);
                }
                else
                {
                    Red d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                    reds.push_back(d1);
                }
                // MAKE BLOCKS AT RANDOM

                // DirtG d1(gRenderer, assets, mov, -35 + screen_scrolled, 440);
                // dirtgs.push_back(d1);
                make_full += 5;
                int y = 480;
                for (int i = 0; i < 3; i++)
                {
                    SDL_Rect mov = {-40, y, 40, 40};
                    int a = random_gen_2();
                    if (a == 1)
                    {
                        DirtG d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        dirtgs.push_back(d1);
                    }
                    else if (a == 2)
                    {
                        Dirt d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        dirts.push_back(d1);
                    }
                    else if (a == 3)
                    {
                        Stone d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        stones.push_back(d1);
                    }
                    else if (a == 4)
                    {
                        DarkWood d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        darkwoods.push_back(d1);
                    }
                    else if (a == 5)
                    {
                        Sand d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        sands.push_back(d1);
                    }
                    else if (a == 6)
                    {
                        Ice d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        ices.push_back(d1);
                    }
                    else if (a == 7)
                    {
                        Glass d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        glasses.push_back(d1);
                    }
                    else if (a == 8)
                    {
                        BrightWood d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        brightwoods.push_back(d1);
                    }
                    else if (a == 9)
                    {
                        Gold d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        golds.push_back(d1);
                    }
                    else if (a == 10)
                    {
                        Coal d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        coals.push_back(d1);
                    }
                    else if (a == 11)
                    {
                        Green d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        greens.push_back(d1);
                    }
                    else
                    {
                        Red d1(gRenderer, assets, mov, -35 + screen_scrolled, y);
                        reds.push_back(d1);
                    }

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
        for (Sand &b : sands)
        {
            b.mover.x -= units;
        }
        for (Stone &b : stones)
        {
            b.mover.x -= units;
        }
        for (Coal &b : coals)
        {
            b.mover.x -= units;
        }
        for (Gold &b : golds)
        {
            b.mover.x -= units;
        }
        for (Red &b : reds)
        {
            b.mover.x -= units;
        }
        for (Green &b : greens)
        {
            b.mover.x -= units;
        }
        for (BrightWood &b : brightwoods)
        {
            b.mover.x -= units;
        }
        for (DarkWood &b : darkwoods)
        {
            b.mover.x -= units;
        }
        for (Glass &b : glasses)
        {
            b.mover.x -= units;
        }
        for (Ice &b : ices)
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
        for (Sand &b : sands)
        {
            b.mover.x += units;
        }
        for (Stone &b : stones)
        {
            b.mover.x += units;
        }
        for (Coal &b : coals)
        {
            b.mover.x += units;
        }
        for (Gold &b : golds)
        {
            b.mover.x += units;
        }
        for (Red &b : reds)
        {
            b.mover.x += units;
        }
        for (Green &b : greens)
        {
            b.mover.x += units;
        }
        for (BrightWood &b : brightwoods)
        {
            b.mover.x += units;
        }
        for (DarkWood &b : darkwoods)
        {
            b.mover.x += units;
        }
        for (Glass &b : glasses)
        {
            b.mover.x += units;
        }
        for (Ice &b : ices)
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

bool Minecraft::exit_click()
{
    if (exit_clicked)
    {
        return true;
    }
    return false;
}
void Minecraft::mouse_click(int x, int y)
{
    if (home_screen && (x >= 250 && x <= 750) && (y >= 300 && y <= 350))
    {
        home_screen = false;
        storage_screen = false;
    }
    else if (home_screen && (x >= 250 && x <= 750) && (y > 350 && y <= 400))
    {
        home_screen = false;
        storage_screen = false;
        exit_clicked = true;
    }
    else if (!home_screen && !storage_screen && (x >= 0 && x <= 120) && (y >= 0 and y <= 35))
    {
        home_screen = true;
    }
    else if (!home_screen && !storage_screen && (x > 120 && x <= 240) && (y >= 0 and y <= 35))
    {
        storage_screen = true;
    }
    else if (storage_screen)
    {
        if (95 <= x && x <= 155 && 110 <= y && y <= 170)
        {
            current_block = 1;
        }
        else if (345 <= x && x <= 405 && 110 <= y && y <= 170)
        {
            current_block = 2;
        }
        else if (595 <= x && x <= 655 && 110 <= y && y <= 170)
        {
            current_block = 3;
        }
        else if (845 <= x && x <= 905 && 110 <= y && y <= 170)
        {
            current_block = 4;
        }
        else if (95 <= x && x <= 155 && 320 <= y && y <= 380)
        {
            current_block = 5;
        }
        else if (345 <= x && x <= 405 && 320 <= y && y <= 380)
        {
            current_block = 6;
        }
        else if (595 <= x && x <= 655 && 320 <= y && y <= 380)
        {
            current_block = 7;
        }
        else if (845 <= x && x <= 905 && 320 <= y && y <= 380)
        {
            current_block = 8;
        }
        else if (95 <= x && x <= 155 && 500 <= y && y <= 560)
        {
            current_block = 9;
        }
        else if (345 <= x && x <= 405 && 500 <= y && y <= 560)
        {
            current_block = 10;
        }
        else if (595 <= x && x <= 655 && 500 <= y && y <= 560)
        {
            current_block = 11;
        }
        else if (845 <= x && x <= 905 && 500 <= y && y <= 560)
        {
            current_block = 12;
        }
    }

    else
    {
        bool block_present = false;
        if (p->get_x() - p->get_w() <= x && x <= p->get_x() + p->get_w() + p->get_w() && p->get_y() - 40 <= y && y <= p->get_y() + 120)
        {

            for (DirtG &b : dirtgs)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    dirtgs.remove(b);
                    ndirtgs += 1;
                    block_present = true;
                }
            }
            for (Dirt &b : dirts)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    dirts.remove(b);
                    ndirts += 1;
                    block_present = true;
                }
            }
            for (Sand &b : sands)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    sands.remove(b);
                    nsand += 1;
                    block_present = true;
                }
            }
            for (Stone &b : stones)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    stones.remove(b);
                    nstone += 1;
                    block_present = true;
                }
            }
            for (Coal &b : coals)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    coals.remove(b);
                    ncoals += 1;
                    block_present = true;
                }
            }
            for (Gold &b : golds)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    golds.remove(b);
                    ngold += 1;
                    block_present = true;
                }
            }
            for (Red &b : reds)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    reds.remove(b);
                    nred += 1;
                    block_present = true;
                }
            }
            for (Green &b : greens)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    greens.remove(b);
                    ngrass += 1;
                    block_present = true;
                }
            }
            for (BrightWood &b : brightwoods)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    brightwoods.remove(b);
                    nbright += 1;
                    block_present = true;
                }
            }
            for (DarkWood &b : darkwoods)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    darkwoods.remove(b);
                    nwood += 1;
                    block_present = true;
                }
            }
            for (Glass &b : glasses)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    glasses.remove(b);
                    nglass += 1;
                    block_present = true;
                }
            }
            for (Ice &b : ices)
            {
                if (b.get_x() - screen_scrolled <= x && x <= b.get_x() - screen_scrolled + b.get_w() && b.get_y() <= y && y <= b.get_y() + b.get_h())
                {
                    ices.remove(b);
                    nice += 1;
                    block_present = true;
                }
            }
        }
        if (!block_present)
        {

            if (p->get_x() - p->get_w() <= x && x <= p->get_x() + p->get_w() + p->get_w() && p->get_y() - 40 <= y && y <= p->get_y() + 120)
            {

                int new_x = (x) / (40 - reset_dim);
                new_x = (new_x * (40 - reset_dim));
                int new_y = y / (40);
                new_y = (new_y * 40);
                SDL_Rect mov = {new_x, new_y, 40, 40};

                if (current_block == 1 && ndirtgs > 0)
                {
                    DirtG d1(gRenderer, assets, mov, new_x, new_y);
                    dirtgs.push_back(d1);
                    ndirtgs -= 1;
                }
                else if (current_block == 2 && ndirts > 0)
                {
                    Dirt d1(gRenderer, assets, mov, new_x, new_y);
                    dirts.push_back(d1);
                    ndirts -= 1;
                }
                else if (current_block == 3 && nstone > 0)
                {
                    Stone d1(gRenderer, assets, mov, new_x, new_y);
                    stones.push_back(d1);
                    nstone -= 1;
                }
                else if (current_block == 4 && nwood > 0)
                {
                    DarkWood d1(gRenderer, assets, mov, new_x, new_y);
                    darkwoods.push_back(d1);
                    nwood -= 1;
                }
                else if (current_block == 5 && nsand > 0)
                {
                    Sand d1(gRenderer, assets, mov, new_x, new_y);
                    sands.push_back(d1);
                    nsand -= 1;
                }
                else if (current_block == 6 && nsand > 0)
                {
                    Ice d1(gRenderer, assets, mov, new_x, new_y);
                    ices.push_back(d1);
                    nsand -= 1;
                }
                else if (current_block == 7 && nglass > 0)
                {
                    Glass d1(gRenderer, assets, mov, new_x, new_y);
                    glasses.push_back(d1);
                    nglass -= 1;
                }
                else if (current_block == 8 && nbright > 0)
                {
                    BrightWood d1(gRenderer, assets, mov, new_x, new_y);
                    brightwoods.push_back(d1);
                    nbright -= 1;
                }
                else if (current_block == 9 && ngold > 0)
                {
                    Gold d1(gRenderer, assets, mov, new_x, new_y);
                    golds.push_back(d1);
                    ngold -= 1;
                }
                else if (current_block == 10 && ncoals > 0)
                {
                    Coal d1(gRenderer, assets, mov, new_x, new_y);
                    coals.push_back(d1);
                    ncoals -= 1;
                }
                else if (current_block == 11 && ngrass > 0)
                {
                    Green d1(gRenderer, assets, mov, new_x, new_y);
                    greens.push_back(d1);
                    ngrass -= 1;
                }
                else if (current_block == 12 && nred > 0)
                {
                    Red d1(gRenderer, assets, mov, new_x, new_y);
                    reds.push_back(d1);
                    nred -= 1;
                }
            }
        }
    }
}
int Minecraft::random_gen_1()
{
    int a = rand() % 240 + 1;
    if (0 <= a && a <= 150)
        return 1;
    else if (150 <= a && a <= 160)
        return 2;

    else if (160 <= a && a <= 170)
        return 3;

    else if (170 <= a && a <= 180)
        return 4;

    else if (180 <= a && a <= 190)
        return 5;

    else if (190 <= a && a <= 200)
        return 6;

    else if (200 <= a && a <= 210)
        return 7;

    else if (210 <= a && a <= 220)
        return 8;

    else if (220 < a && a <= 221)
        return 9;

    else if (221 < a && a <= 226)
        return 10;

    else if (226 < a && a <= 236)
        return 11;

    else if (236 < a && a <= 40)
        return 12;
}

int Minecraft::random_gen_2()
{
    int a = rand() % 330 + 1;
    if (0 <= a && a <= 40)
        return 2;

    else if (40 <= a && a <= 80)
        return 3;

    else if (80 <= a && a <= 120)
        return 4;

    else if (120 <= a && a <= 160)
        return 5;

    else if (160 <= a && a <= 200)
        return 6;

    else if (200 <= a && a <= 240)
        return 7;

    else if (240 <= a && a <= 280)
        return 8;

    else if (280 < a && a <= 281)
        return 9;

    else if (281 < a && a <= 286)
        return 10;

    else if (286 < a && a <= 326)
        return 11;

    else if (326 < a && a <= 330)
        return 12;
}

void Minecraft::check_fall()
{
    bool block_present = false;
    for (DirtG &b : dirtgs)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {
            block_present = true;
            break;
        }
    }
    for (Dirt &b : dirts)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Sand &b : sands)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Stone &b : stones)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Coal &b : coals)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Gold &b : golds)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Red &b : reds)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Green &b : greens)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (BrightWood &b : brightwoods)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (DarkWood &b : darkwoods)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Glass &b : glasses)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    for (Ice &b : ices)
    {
        if (((b.get_x() <= p->get_x() && p->get_x() <= b.get_x() + b.get_w()) || (b.get_x() <= p->get_x() + p->get_w() - 28 && p->get_x() + p->get_w() - 28 <= b.get_x() + b.get_w())) && b.get_y() == p->get_y() + p->get_h())
        {

            block_present = true;
            break;
        }
    }
    if (!block_present)
    {
        p->move_down();
    }
}

bool Minecraft::moveable(int a)
{
    if (a == 1)
    {
        for (Dirt &b : dirts)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (DirtG &b : dirtgs)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Sand &b : sands)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Stone &b : stones)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Coal &b : coals)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Gold &b : golds)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Red &b : reds)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Green &b : greens)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (BrightWood &b : brightwoods)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (DarkWood &b : darkwoods)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Glass &b : glasses)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        for (Ice &b : ices)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (p->get_x() + p->get_w() + 5 >= b.get_x()) && (p->get_x() + p->get_w() <= b.get_x()))
            {
                return false;
            }
        }
        return true;
    }
    else if (a == 0)
    {
        for (Dirt &b : dirts)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (DirtG &b : dirtgs)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Sand &b : sands)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Stone &b : stones)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Coal &b : coals)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Gold &b : golds)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Red &b : reds)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Green &b : greens)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (BrightWood &b : brightwoods)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (DarkWood &b : darkwoods)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Glass &b : glasses)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        for (Ice &b : ices)
        {
            if ((p->get_y() + 40 == b.get_y() || p->get_y() == b.get_y()) && (b.get_x() + b.get_w() + 5 >= p->get_x()) && (b.get_x() + b.get_w() <= p->get_x()))
            {
                return false;
            }
        }
        return true;
    }
}

void Minecraft::jump()
{
    p->jump();
    jumping = true;
}

void Minecraft::jump_done()
{
    jumping = false;
}

bool Minecraft::game_over()
{
    return (!(p->is_alive()));
}

void Minecraft::reset(SDL_Renderer *renderer, SDL_Texture *asst)
{
    delete p;
    SDL_Rect mov = {480, 360, 40, 80};
    p = new Player(renderer, asst, mov);
    current_block = 2;
    jumping = false;
    make_full = 0;
    make_new = false;
    screen_scrolled = 0;
    reset_dim = 0;
    home_screen = true;
    storage_screen = false;
    exit_clicked = false;
    ndirtgs = 5;
    ndirts = 5;
    nsand = 5;
    nice = 5;
    nstone = 5;
    nwood = 5;
    nbright = 5;
    nred = 5;
    ncoals = 5;
    ngold = 5;
    nglass = 5;
    ngrass = 5;
    dirtgs.clear();
    dirts.clear();
    sands.clear();
    ices.clear();
    stones.clear();
    darkwoods.clear();
    brightwoods.clear();
    reds.clear();
    coals.clear();
    golds.clear();
    greens.clear();
    glasses.clear();
}

void Minecraft::goto_home()
{
    home_screen = true;
    storage_screen = false;
}

void Minecraft::delete_stuff()
{
    delete p;
}