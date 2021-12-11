#include "game.hpp"
#include <vector>
#include "Minecraft.hpp"
bool Game::init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        // Create window
        gWindow = SDL_CreateWindow("HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool Game::loadMedia()
{
    // Loading success flag
    bool success = true;

    assets = loadTexture("./sprites/spritesheet_3.png");
    gTexture = loadTexture("./sprites/Background.jpg");
    if (assets == NULL || gTexture == NULL)
    {
        printf("Unable to run due to error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

void Game::close()
{
    // Free loaded images
    SDL_DestroyTexture(assets);
    assets = NULL;
    SDL_DestroyTexture(gTexture);

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Game::run()
{
    bool quit = false;
    SDL_Event e;
    Minecraft Minecraft1(gRenderer, assets);
    Minecraft1.create_init();

    while (!quit)
    {
        if (Minecraft1.game_over())
        {
            // std::cout << "done";
            // Minecraft Minecraft1(gRenderer, assets);
            Minecraft1.reset(gRenderer, assets);
            Minecraft1.create_init();
            Minecraft1.goto_home();
        }
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {

            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                // this is a good location to add pigeon in linked list.
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);
                // while (true)
                // {
                //     if (e.type == SDL_MOUSEBUTTONUP)
                //     {
                //         cout << "XYZ" << endl;
                //         break;
                //     }
                //     cout << "loop\n";
                // }

                Minecraft1.mouse_click(xMouse, yMouse);

                cout << "x: " << xMouse + Minecraft1.get_player()->displacement << "y: " << yMouse + Minecraft1.get_player()->displacement << endl;
                // if (e.type == SDL_MOUSEBUTTONUP)
                // {
                //     cout << "AA";
                // }
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
            {
                // std::cout << "space !";
                int x1 = 0;
                while (x1 < 30)
                {
                    SDL_RenderClear(gRenderer);
                    SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
                    Minecraft1.drawObjects();
                    SDL_RenderPresent(gRenderer);
                    Minecraft1.jump();
                    SDL_Delay(10);
                    x1++;
                }
                Minecraft1.jump_done();
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                if (Minecraft1.at_storage())
                {
                    Minecraft1.goto_game();
                }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
            {

                Minecraft1.move_right();
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
            {

                Minecraft1.move_left();
            }
        }
        if (Minecraft1.exit_click())
        {
            Minecraft1.delete_stuff();
            exit(0);
        }

        SDL_RenderClear(gRenderer);                      // removes everything from renderer
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); // Draws background to renderer
        //***********************draw the objects here********************
        Minecraft1.drawObjects();
        //****************************************************************
        SDL_RenderPresent(gRenderer); // displays the updated renderer

        SDL_Delay(50); // causes sdl engine to delay for specified miliseconds
    }
    Minecraft1.delete_stuff();
}