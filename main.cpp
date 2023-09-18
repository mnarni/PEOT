#include <iostream>
#include <SDL2/SDL.h>
#include "Particle.h"
#include "VectorClass.h"
#include "Car.h"
#include "Car_Car_Res.h"
// #include <opencv2/opencv.hpp>

const float WIDTH = 800.0, HEIGHT = 600.0;

void drawAction(SDL_Renderer* r, int x_1, int x_2)
{
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_Rect rect;
    rect.w = 60;
    rect.h = 20;
    rect.x = x_1;
    rect.y = 40;
    SDL_RenderDrawRect(r, &rect);

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_Rect rect_car2;
    rect_car2.w = 60;
    rect_car2.h = 20;
    rect_car2.x = x_2;
    rect_car2.y = 40;
    SDL_RenderDrawRect(r, &rect_car2);
}

int main(int argc, char *argv[])
{

    //SDL_Window *window = SDL_CreateWindow("Physics Engine Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    /*
    if (NULL == window)
    {
        std::cout <<"Error in creating window: " <<SDL_GetError() << std::endl;
        return 1;
    }
    */
    SDL_Event windowEvent;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //SDL_RenderClear(renderer);
    
    drawAction(renderer, 20, 120);
    /*
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect;
    rect.w = 60;
    rect.h = 20;
    rect.x = 20;
    rect.y = 40;
    SDL_RenderDrawRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect_car2;
    rect_car2.w = 60;
    rect_car2.h = 20;
    rect_car2.x = 120;
    rect_car2.y = 40;
    SDL_RenderDrawRect(renderer, &rect_car2);
    */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);
    SDL_RenderPresent(renderer);
    //SDL_Delay(10000);


    //quick test for particle here  ()
    VectorClass p = VectorClass(10, 20, 30, 1);
    VectorClass v = VectorClass(10, 20, 30, 1);
    VectorClass a = VectorClass(10, 20, 30, 1);
    Boundary boundary(WIDTH, HEIGHT);
    Particle test_p = Particle(p, v, a, boundary);
//    Particle test_p = Particle(p, v, a);
    test_p.resetCompMass(200);
    test_p.setCurrForce(2, 3, 2);
    float track = 2.0f;

    //temp check on car collision
    //set up car 1
    Car car1 = Car();
    VectorClass c1_initial_accel = VectorClass(5, 5, 5, 1);
    car1.setAccel(c1_initial_accel);
    car1.setForce(car1.getAccel().scaledVector(car1.getAccel(), car1.getMass()));
    VectorClass c1_p1 = VectorClass(80, 40, 20, 1);
    VectorClass c1_p2 = VectorClass(80, 20, 20, 1);
    VectorClass c1_p3 = VectorClass(20, 40, 20, 1);
    VectorClass c1_p4 = VectorClass(20, 20, 20, 1);
    car1.setPosition_FD(c1_p1);
    car1.setPosition_FP(c1_p2);
    car1.setPosition_RD(c1_p3);
    car1.setPosition_RP(c1_p4);
    int x1 = 20;

    //set up car 2
    Car car2 = Car();
    VectorClass c2_initial_accel = VectorClass(0,0,0, 1);   //a i s0 bc car 2 is at rest for this scenario
    car2.setAccel(c2_initial_accel);
    car2.setForce(c2_initial_accel);    //zeroed out since f = ma and a is 0
    VectorClass c2_p1 = VectorClass(120, 40, 20, 1); //a little farther out from car1 for eventual collision
    VectorClass c2_p2 = VectorClass(120, 20, 20, 1);
    VectorClass c2_p3 = VectorClass(180, 40, 20, 1);
    VectorClass c2_p4 = VectorClass(180, 20, 20, 1);
    car2.setPosition_FD(c2_p1);
    car2.setPosition_FP(c2_p2);
    car2.setPosition_RD(c2_p3);
    car2.setPosition_RP(c2_p4);
    int x2 = 120;

    int result = 0;
    int i = 1;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
            //test_p.Update(track);
            //test_p.print();
            //track++;
            if (result == 0)
            {
                car1.MoveForward(10.0f);
                //rect.x += 10;
                //SDL_RenderDrawRect(renderer, &rect);
                drawAction(renderer, x1 + (10 * i), x2);
                result = Car_Car_Res::Collide(car1, car2);
                i++;
            }

            
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}