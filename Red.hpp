#include "Block.hpp"

class Red : public Block
{

public:
    int init_x;
    int init_y;
    SDL_Rect src, mover;

    // public:
    Red(SDL_Renderer *, SDL_Texture *, SDL_Rect mov, int x, int y);
    void draw();
    int get_x();
    int get_y();
    int get_w();
    int get_h();
    bool operator==(const Red &);
};