#include "Living_Things.hpp"

Living_Things::Living_Things(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast)
{
}
void Living_Things::draw(SDL_Rect srcRect, SDL_Rect moverRect)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
