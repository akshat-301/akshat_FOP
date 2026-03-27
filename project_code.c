#include <SDL.h>
#include <stdlib.h>
#include <math.h>  /* for circle drawing */
#include <time.h>

/* draw a filled circle at (cx,cy) with radius r */
static void drawCircle(SDL_Renderer *renderer, int cx, int cy, int r) {
    for (int w = 0; w < r * 2; w++) {
        for (int h = 0; h < r * 2; h++) {
            int dx = r - w; // horizontal offset
            int dy = r - h; // vertical offset
            if ((dx*dx + dy*dy) <= (r * r)) {
                SDL_RenderDrawPoint(renderer, cx + dx, cy + dy);
            }
        }
    }
}

/* draw a single digit (0-9) using 7-segment style rectangles */
static void drawDigit(SDL_Renderer *renderer, int x, int y, int size, int d) {
    int segW = size/6;
    int segL = size;
    SDL_Rect seg;
    /* segments: 0=top,1=top-left,2=top-right,3=middle,4=bottom-left,5=bottom-right,6=bottom */
    int segOn[10][7] = {
        {1,1,1,0,1,1,1}, /0/
        {0,0,1,0,0,1,0}, /1/
        {1,0,1,1,1,0,1}, /2/
        {1,0,1,1,0,1,1}, /3/
        {0,1,1,1,0,1,0}, /4/
        {1,1,0,1,0,1,1}, /5/
        {1,1,0,1,1,1,1}, /6/
        {1,0,1,0,0,1,0}, /7/
        {1,1,1,1,1,1,1}, /8/
        {1,1,1,1,0,1,1}  /9/
    };

    /* top */
    if (segOn[d][0]) {
        seg.x = x + segW; seg.y = y; seg.w = segL; seg.h = segW;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* top-left */
    if (segOn[d][1]) {
        seg.x = x; seg.y = y + segW; seg.w = segW; seg.h = segL;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* top-right */
    if (segOn[d][2]) {
        seg.x = x + segW + segL; seg.y = y + segW; seg.w = segW; seg.h = segL;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* middle */
    if (segOn[d][3]) {
        seg.x = x + segW; seg.y = y + segW + segL; seg.w = segL; seg.h = segW;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* bottom-left */
    if (segOn[d][4]) {
        seg.x = x; seg.y = y + segW + segL + segW; seg.w = segW; seg.h = segL;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* bottom-right */
    if (segOn[d][5]) {
        seg.x = x + segW + segL; seg.y = y + segW + segL + segW; seg.w = segW; seg.h = segL;
        SDL_RenderFillRect(renderer, &seg);
    }
    /* bottom */
    if (segOn[d][6]) {
        seg.x = x + segW; seg.y = y + segW + segL + segW + segL; seg.w = segL; seg.h = segW;
        SDL_RenderFillRect(renderer, &seg);
    }
}

/* draw number (0-99) centered at x,y */
static void drawNumber(SDL_Renderer *renderer, int centerX, int y, int size, int num) {
    int tens = num / 10;
    int ones = num % 10;
    int digitWidth = size + size/3 + size/6; /* segL + spacing + segW */
    if (num >= 10) {
        drawDigit(renderer, centerX - digitWidth/2 - (digitWidth/2), y, size, tens);
        drawDigit(renderer, centerX + digitWidth/2 - (digitWidth/2), y, size, ones);
    } else {
        drawDigit(renderer, centerX - digitWidth/2, y, size, ones);
    }
}
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define PADDLE_HEIGHT 80
#define PADDLE_WIDTH 10
#define BALL_SIZE 10

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Pong",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          0);
    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL…