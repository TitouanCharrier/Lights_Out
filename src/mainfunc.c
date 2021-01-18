#include "../main.h"


SDL_Texture *Print_Text(SDL_Renderer *renderer, char text[],int x, int y, int w, int h,TTF_Font *font) {
	SDL_Rect Rect;
	SDL_Color Orange = {255,255,255};
    SDL_Color Grey = {30,30,30};
    SDL_Surface *Choix_1 = TTF_RenderText_Shaded(font,text, Orange,Grey);
    SDL_Texture * T_Choix_1 = SDL_CreateTextureFromSurface(renderer,Choix_1);
    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
   	Rect.h = h;
    SDL_RenderCopy(renderer,T_Choix_1,NULL,&Rect);
    SDL_RenderPresent(renderer);
    return T_Choix_1;
}