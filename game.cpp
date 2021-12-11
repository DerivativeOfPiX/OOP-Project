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

    //Initialize SDL_mixer
    else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
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

     /**Load music
    gMusic = Mix_LoadMUS( "21_sound_effects_and_music/beat.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    //Load sound effects
    gScratch = Mix_LoadWAV( "21_sound_effects_and_music/scratch.wav" );
    if( gScratch == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    
    gHigh = Mix_LoadWAV( "21_sound_effects_and_music/high.wav" );
    if( gHigh == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gMedium = Mix_LoadWAV( "21_sound_effects_and_music/medium.wav" );
    if( gMedium == NULL )
    {
        printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    gLow = Mix_LoadWAV( "21_sound_effects_and_music/low.wav" );
    if( gLow == NULL )
    {
        printf( "Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }**/

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

    //Free the sound effects
    Mix_FreeChunk( gScratch );
    Mix_FreeChunk( gHigh );
    Mix_FreeChunk( gMedium );
    Mix_FreeChunk( gLow );
    gScratch = NULL;
    gHigh = NULL;
    gMedium = NULL;
    gLow = NULL;
    
    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;

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

            if (e.type == SDL_MOUSEBUTTONDOWN)  // when mouse is clicked
            {
                
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

//                 cout << "x: " << xMouse + Minecraft1.get_player()->displacement << "y: " << yMouse + Minecraft1.get_player()->displacement << endl;
                // if (e.type == SDL_MOUSEBUTTONUP)
                // {
                //     cout << "AA";
                // }
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)  // when space is pressed
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
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)  // when escape is pressed
                if (Minecraft1.at_storage())
                {
                    Minecraft1.goto_game();
                }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)  // when right key is pressed
            {

                Minecraft1.move_right();
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)  // when left key is pressed
            {

                Minecraft1.move_left();
            }
        }
        if (Minecraft1.exit_click()) // exiting the game is exit is pressed
        {
            Minecraft1.delete_stuff();  // deleting the dynamically allocated objects before exiting
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
    Minecraft1.delete_stuff(); // deleting the dynamically allocated objects before exiting
}
