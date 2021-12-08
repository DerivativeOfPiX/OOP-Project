#pragma once
#include <SDL.h>
class Block
{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

public:
    Block(SDL_Renderer *, SDL_Texture *);
    void draw(SDL_Rect srcRect, SDL_Rect moverRect);
};