#include"Semaphore.h";


void Semaphore::draw(SDL_Renderer* renderer)
{


    if (state == 0)
    {
        SDL_SetRenderDrawColor(renderer, 4, 244, 4, SDL_ALPHA_OPAQUE);
    }

    if (state == 1)
    {

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    }
    SDL_RenderDrawLine(renderer, x+length, y-length, x+length, y+length);

    SDL_RenderPresent(renderer);

}