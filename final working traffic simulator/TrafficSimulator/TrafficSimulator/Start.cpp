#include <SDL.h>
#include "CarTrack.h"
#include "Car.h"
#include "Semaphore.h";
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Framework {
public:
    // Contructor which initialize the parameters.
    Framework(int height_, int width_) : height(height_), width(width_) {
        SDL_Init(SDL_INIT_VIDEO);       // Initializing SDL as Video
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);      // setting draw color
        SDL_RenderClear(renderer);      // Clear the newly created window
        SDL_RenderPresent(renderer);    // Reflects the changes done in the
                                        //  window.
    }

    // Destructor
    ~Framework() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    int getMainWindowHeight()
    {

        return height;

    }

    int getMainWindowWidth()
    {

        return width;

    }

    SDL_Renderer* getRenderer()
    {

        return renderer;

    }



private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer* renderer = NULL;      // Pointer for the renderer
    SDL_Window* window = NULL;      // Pointer for the window
};

int main(int argc, char* argv[]) {

    bool key_pressed = false;
    // Creating the object by passing Height and Width value.
    Framework fw(1080, 1920);
    int trackStartPos = fw.getMainWindowHeight() / 2;
    int trackEndPos = fw.getMainWindowWidth();
    int trackWidth = 60;
    int carXDestination = trackStartPos / 2;
    int carYDestination = 1920;
    int distance_from_semaphore;
    int car_stopping_distance = 200;

    CarTrack carTrack(trackStartPos, trackEndPos, trackWidth);
    Semaphore semaphore;
    Car car;

    car.setCarHeight(30);
    car.setCarWidth(50);
    car.setXPos(500);
    car.setYpos(200);

    semaphore.x = fw.getMainWindowWidth()/2;
    semaphore.y = (fw.getMainWindowHeight()/2);
    semaphore.length = 30;
    semaphore.state = 0;//0= green

    // Starting the animation

    SDL_bool done = SDL_FALSE;

    car.spawn(20, trackStartPos - 10, fw.getRenderer());

    SDL_Event event;

    while (done != true)
    {
             
            while (SDL_PollEvent(&event) !=0 ) { 
                if (event.type == SDL_QUIT) {
                    done = SDL_TRUE;
                }

                if (event.type == SDL_KEYDOWN)
                {

                    key_pressed = true;
                   

                    // test keycode
                    switch (event.key.keysym.sym) {
                    case SDLK_s:

                        cout << "key press detected";
                        // cout << car.getCarXPos() << endl;
                       //clear the screen with color black every frame
                        SDL_SetRenderDrawColor(fw.getRenderer(), 0, 0, 0, 0);
                        SDL_RenderClear(fw.getRenderer());

                        //redraw the car track every frame
                        carTrack.Draw(fw.getRenderer());
                        semaphore.state = 1;
                        semaphore.draw(fw.getRenderer());


                        distance_from_semaphore = semaphore.x - car.getCarXPos();
                        cout << "distance from semaphore is :" << distance_from_semaphore << endl;
                        


                        while (distance_from_semaphore >= car_stopping_distance) //if we are at the stopping distance the car needs to stop

                        {
                            SDL_SetRenderDrawColor(fw.getRenderer(), 0, 0, 0, 0);
                            SDL_RenderClear(fw.getRenderer());

                            //redraw the car track every frame
                            carTrack.Draw(fw.getRenderer());
                          
                            semaphore.draw(fw.getRenderer());
                            car.move(4, fw.getRenderer());
                            SDL_Delay(20);
                            distance_from_semaphore = semaphore.x - car.getCarXPos();//update position after movement
                        }

                        if (distance_from_semaphore > 0)//don't stop if passed beyond the semaphore
                        {
                            car.move(0, fw.getRenderer());
                            SDL_Delay(2000);
                        }

                   
                    }
             
                   
                }


            }

            // cout << car.getCarXPos() << endl;
            //clear the screen with color black every frame
            SDL_SetRenderDrawColor(fw.getRenderer(), 0, 0, 0, 0);
            SDL_RenderClear(fw.getRenderer());

            //redraw the car track every frame
            carTrack.Draw(fw.getRenderer());

            semaphore.state = 0;
            semaphore.draw(fw.getRenderer());
            car.move(4, fw.getRenderer());
            SDL_Delay(20);

    
    }

    return 1;
}