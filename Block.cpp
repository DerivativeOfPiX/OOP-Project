#include "Block.hpp"

Block::Block(SDL_Renderer *rend, SDL_Texture *ast) : gRenderer(rend), assets(ast)
{
}
void Block::draw(SDL_Rect srcRect, SDL_Rect moverRect)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}