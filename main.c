#include "main.h"

int main(int argc, char *argv[]) {
	
	//start SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	//start SDL ttf
	TTF_Init();

	TTF_Font * Sans = TTF_OpenFont("/usr/share/fonts/liberation/LiberationMono-Regular.ttf",1024);

	//launch menu
	Couple RES;
	RES = Play_menu();
	int RESX = RES.RESX;
	int RESY = RES.RESY;

	#define CASE RESY/6 
	
	//define Renderer an Window:
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Lights Out",0,0,RESX,RESY,0);
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer,30,30,30,255);
    SDL_RenderFillRect(renderer,NULL);

	Print_Text(renderer,"--- Welcome ---",0,RESY/2-RESY/8,RESX,RESY/4,Sans);
	SDL_Delay(500);
	SDL_RenderClear(renderer);

	Case ListCase[5][5];
	
	for (int k=0; k<5;k++){
		for(int l=0; l<5; l++){
			ListCase[k][l].on = rand()%2;
			ListCase[k][l].centrx = RESX/2-2*CASE+l*CASE;
			ListCase[k][l].centry = RESY/2-2*CASE+k*CASE;
			ListCase[k][l].box1x = ListCase[k][l].centrx-CASE/2;
			ListCase[k][l].box2x = ListCase[k][l].centrx+CASE/2;
			ListCase[k][l].box1y = ListCase[k][l].centry-CASE/2;
			ListCase[k][l].box2y = ListCase[k][l].centry+CASE/2;
			ListCase[k][l].b = 0;
			if (ListCase[k][l].on == 0) {
 				CreateRectangle(renderer,ListCase[k][l].centrx,ListCase[k][l].centry,CASE,CASE,255,0,0,255,1);
 			}
 			else if (ListCase[k][l].on == 1) {
 				CreateRectangle(renderer,ListCase[k][l].centrx,ListCase[k][l].centry,CASE,CASE,0,255,0,255,1);
 			}
			CreateRectangle(renderer,ListCase[k][l].centrx,ListCase[k][l].centry,CASE,CASE,0,0,0,255,0);
			SDL_Delay(25);
			SDL_RenderPresent(renderer);

		}
	}
	SDL_RenderPresent(renderer);

	int x;
	int y;
	int win;

	SDL_Event event;
	while (1){
		
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym == SDLK_ESCAPE) goto LABEL;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN){
			if (event.button.button == SDL_BUTTON_LEFT) {
				x = event.button.x;
				y = event.button.y;
				win = 0;
				for (int i =0; i<5; i++){
                    for (int j =0; j<5; j++){

						if (x>ListCase[i][j].box1x && x<ListCase[i][j].box2x && y>ListCase[i][j].box1y && y<ListCase[i][j].box2y) {
					
	                        if (ListCase[i][j].on == 0) {
	                            ListCase[i][j].on =1;
	                               	CreateRectangle(renderer,ListCase[i][j].centrx,
	                               		ListCase[i][j].centry,CASE,CASE,0,255,0,255,1);
	                        }
	                        else {
	                           	ListCase[i][j].on = 0;
	                        	    CreateRectangle(renderer,ListCase[i][j].centrx,
	                            		ListCase[i][j].centry,CASE,CASE,255,0,0,255,1);
	                        }
	                                                                
							if (i-1>=0) {
								if (ListCase[i-1][j].on == 0) {				
	                            	ListCase[i-1][j].on =1;
									CreateRectangle(renderer,ListCase[i-1][j].centrx,
	                        	   		ListCase[i-1][j].centry,CASE,CASE,0,255,0,255,1);
								}
								else {
	                            	ListCase[i-1][j].on = 0;
	                            	CreateRectangle(renderer,ListCase[i-1][j].centrx,
	                                	ListCase[i-1][j].centry,CASE,CASE,255,0,0,255,1);
								}
							}
							if (i+1<5) {
								if (ListCase[i+1][j].on == 0) {               
	                                ListCase[i+1][j].on =1;                                 
	                                CreateRectangle(renderer,ListCase[i+1][j].centrx,
	                                    ListCase[i+1][j].centry,CASE,CASE,0,255,0,255,1);
	                        	}                                           
	                            else {                                          
	                                ListCase[i+1][j].on = 0;                 
	                                CreateRectangle(renderer,ListCase[i+1][j].centrx,
	                                ListCase[i+1][j].centry,CASE,CASE,255,0,0,255,1);
	                            }                        
							}
							if (j-1>=0) {
								if (ListCase[i][j-1].on == 0) {               
	                                ListCase[i][j-1].on =1;                                 
	                                CreateRectangle(renderer,ListCase[i][j-1].centrx,
	                                ListCase[i][j-1].centry,CASE,CASE,0,255,0,255,1);
	                            }                                           
	                        	else {                                          
	                        	    ListCase[i][j-1].on = 0;                 
	                                CreateRectangle(renderer,ListCase[i][j-1].centrx,
	                            	    ListCase[i][j-1].centry,CASE,CASE,255,0,0,255,1);
	                        	}                        
							}
							if (j+1<5) {
								if (ListCase[i][j+1].on == 0) {               
	                                ListCase[i][j+1].on =1;                                 
	                                CreateRectangle(renderer,ListCase[i][j+1].centrx,
	                                ListCase[i][j+1].centry,CASE,CASE,0,255,0,255,1);
	                            }                                           
	                            else {                                          
	                                ListCase[i][j+1].on = 0;                 
	                                CreateRectangle(renderer,ListCase[i][j+1].centrx,
	                                ListCase[i][j+1].centry,CASE,CASE,255,0,0,255,1);
	                            }                        
							}
								
							for(int m=0; m<5; m++) {
								for(int n=0; n<5; n++) {
									CreateRectangle(renderer,ListCase[m][n].centrx,
	                            		ListCase[m][n].centry,CASE,CASE,0,0,0,255,0);	
								}
							}	
                        	SDL_RenderPresent(renderer);
                        }
					}
               	}
			}
			win = 0;
			for (int i = 0; i<5; i++) {
				for (int j = 0; j<5; j++) {

					win += ListCase[i][j].on;
					if (win == 25) {
						goto LABEL;
					}		
				}		
			} 
		}			
	}
	LABEL:
	for(int m=0; m<5; m++) {
		for(int n=0; n<5; n++) {
			CreateRectangle(renderer,ListCase[m][n].centrx,
	    		ListCase[m][n].centry,CASE,CASE,30,30,30,255,1);
	    	SDL_Delay(25);
	    	SDL_RenderPresent(renderer);	
		}
	}
	Print_Text(renderer,"--- Good Bye ---",0,RESY/2-RESY/8,RESX,RESY/4,Sans);	
	SDL_Delay(500);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();	
}
