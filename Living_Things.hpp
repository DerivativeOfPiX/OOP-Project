#pragma once
#include <SDL.h>
class Living_Things
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    Living_Things(SDL_Renderer *, SDL_Texture *);
    void draw(SDL_Rect srcRect, SDL_Rect moverRect);
};
