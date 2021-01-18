#include <SDL2/SDL.h>
#include <math.h>

int RegulHollowPoly(SDL_Renderer *renderer, int nbrCote, int tailleCote, int centrx, int centry, int facing, int r, int g, int b, int a);

int RegulPoly(SDL_Renderer *renderer, int nbrCote, int tailleCote, int centrx, int centry, int facing, int r, int g, int b, int a, int hollow );

void CreateCircle(SDL_Renderer *renderer, int centrx, int centry, int ray, int r, int g, int b, int a);

int CreateRectangle(SDL_Renderer *renderer, int centrx, int centry, int sizex, int sizey, int r, int g, int b, int a, int fill);

