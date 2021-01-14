#include "lib/geometrie_SDL2.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Case {
        int centrx;
        int centry;
	int box1x;
	int box2x;
	int box1y;
	int box2y;
        int r;
        int g;
        int b;
        int a;
        int fill;
	int on;
	
}Case;

int main(int argc, char *argv[]) {
	
	//start SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	//define Renderer an Window:
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Lights Out",0,0,1366,768,0);
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	CreateRectangle(renderer,1366/2,768/2,500,500,255,0,0,255,0);
        CreateRectangle(renderer,1366/2,768/2,498,498,100,0,0,255,0);
        CreateRectangle(renderer,1366/2,768/2,502,502,100,0,0,255,0);

	Case Case1_1;
	Case Case1_2;	
	Case Case1_3;	
	Case Case1_4;	
	Case Case1_5;	
	Case Case2_1;	
	Case Case2_2;	
	Case Case2_3;	
	Case Case2_4;	
	Case Case2_5;	
	Case Case3_1;	
	Case Case3_2;
	Case Case3_3;	
	Case Case3_4;	
	Case Case3_5;	
	Case Case4_1;	
	Case Case4_2;	
	Case Case4_3;	
	Case Case4_4;	
	Case Case4_5;	
	Case Case5_1;	
	Case Case5_2;	
	Case Case5_3;	
	Case Case5_4;	
	Case Case5_5;	
	
	Case ListCase[5][5] = {{Case1_1,Case1_2,Case1_3,Case1_4,Case1_5},
		{Case2_1,Case2_2,Case2_3,Case2_4,Case2_5},
		{Case3_1,Case3_2,Case3_3,Case3_4,Case3_5},
		{Case4_1,Case4_2,Case4_3,Case4_4,Case4_5},
		{Case5_1,Case5_2,Case5_3,Case5_4,Case5_5}};
	
	for (int k=0; k<5;k++){
		for(int l=0; l<5; l++){
			ListCase[k][l].on = -1;
			ListCase[k][l].centrx = 1366/2-200+k*100;
			ListCase[k][l].centry = 768/2-200+l*100;
			ListCase[k][l].box1x = ListCase[k][l].centrx-50;
			ListCase[k][l].box2x = ListCase[k][l].centrx+50;
			ListCase[k][l].box1y = ListCase[k][l].centry-50;
			ListCase[k][l].box2y = ListCase[k][l].centry+50;
			ListCase[k][l].b = 0;
			CreateRectangle(renderer,ListCase[k][l].centrx,ListCase[k][l].centry,100,100,255,0,0,255,1);
			CreateRectangle(renderer,ListCase[k][l].centrx,ListCase[k][l].centry,100,100,0,0,0,255,0);

		}
	}	
	SDL_RenderPresent(renderer);

	int x;
	int y;

	SDL_Event event;
	while (1){
		
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE) break;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN){
			if (event.button.button == SDL_BUTTON_LEFT) {
				x = event.button.x;
				y = event.button.y;
				for (int i =0; i<5; i++){
                     			for (int j =0; j<5; j++){
						if (x>ListCase[i][j].box1x && x<ListCase[i][j].box2x && y>ListCase[i][j].box1y && y<ListCase[i][j].box2y) {
							if (ListCase[i][j].on == -1) {
								ListCase[i][j].on =1;
								
								CreateRectangle(renderer,ListCase[i][j].centrx,
                                                        	        ListCase[i][j].centry,100,100,0,255,0,255,1);
								if (i-1>=0) {
									if (ListCase[i-1][j].on == -1) {				
                                                        	       		ListCase[i-1][j].on =1;
										CreateRectangle(renderer,ListCase[i-1][j].centrx,
                                                        	        		ListCase[i-1][j].centry,100,100,0,255,0,255,1);
									}
									else {
                                                                                ListCase[i-1][j].on =-1;
                                                                                CreateRectangle(renderer,ListCase[i-1][j].centrx,
                                                                                        ListCase[i-1][j].centry,100,100,255,0,0,255,1);
									}
								}
								if (i+1<5) {
									if (ListCase[i+1][j].on == -1) {               
                                                                                ListCase[i+1][j].on =1;                                 
                                                                                CreateRectangle(renderer,ListCase[i+1][j].centrx,
                                                                                        ListCase[i+1][j].centry,100,100,0,255,0,255,1);
                                                                        }                                           
                                                                        else {                                          
                                                                                ListCase[i+1][j].on =-1;                 
                                                                                CreateRectangle(renderer,ListCase[i+1][j].centrx,
                                                                                        ListCase[i+1][j].centry,100,100,255,0,0,255,1);
                                                                        }                        
								}
								if (j-1>=0) {
									if (ListCase[i][j-1].on == -1) {               
                                                                                ListCase[i][j-1].on =1;                                 
                                                                                CreateRectangle(renderer,ListCase[i][j-1].centrx,
                                                                                        ListCase[i][j-1].centry,100,100,0,255,0,255,1);
                                                                        }                                           
                                                                        else {                                          
                                                                                ListCase[i][j-1].on =-1;                 
                                                                                CreateRectangle(renderer,ListCase[i][j-1].centrx,
                                                                                        ListCase[i][j-1].centry,100,100,255,0,0,255,1);
                                                                        }                        
								}
								if (j+1<5) {
									if (ListCase[i][j+1].on == -1) {               
                                                                                ListCase[i][j+1].on =1;                                 
                                                                                CreateRectangle(renderer,ListCase[i][j+1].centrx,
                                                                                        ListCase[i][j+1].centry,100,100,0,255,0,255,1);
                                                                        }                                           
                                                                        else {                                          
                                                                                ListCase[i][j+1].on =-1;                 
                                                                                CreateRectangle(renderer,ListCase[i][j+1].centrx,
                                                                                        ListCase[i][j+1].centry,100,100,255,0,0,255,1);
                                                                        }                        
								}
							}
							for(int m=0; m<5; m++) {
								for(int n=0; n<5; n++) {
									CreateRectangle(renderer,ListCase[m][n].centrx,
                                                        		ListCase[m][n].centry,100,100,0,0,0,255,0);	
								}
							}	
                                			SDL_RenderPresent(renderer);
						}
                			}
        			}
			}
		}			
	}
	SDL_DestroyRenderer(renderer);
	SDL_Quit();	
}
