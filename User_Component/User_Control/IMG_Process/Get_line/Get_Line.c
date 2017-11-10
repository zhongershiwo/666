/*
 * Get_Line.c
 *
 *  Created on: 2017年10月30日
 *      Author: 惠普
 */

#include "Get_Line.h"

#define PIX_X 128
#define PIX_Y 64
#define LEFT  0
#define MIDDLE 1
#define RIGHT 2
//60->40
#define R_CAR_EDGE 85
#define L_CAR_EDGE 42
extern uint8_t Image[64][128];//小胖给我的数据
uint8_t x_edge[PIX_Y][3]={PIX_X/2,PIX_X/2,PIX_X/2};//car_edge[PIX_Y][3]=0;
uint8_t Line_1[64];
#define IMG_BLACK       1
#define IMG_WHITE       0

void img_deflection(){
	int x,y;
	for(x=1;x<PIX_X;x++){
		if(!Image[PIX_Y-1][x])break;
	}x_edge[0][LEFT]=x;
	for(x=1;x<PIX_X;x++){
			if(!Image[PIX_Y-1][x-1]&&Image[PIX_Y-1][x]) x_edge[0][RIGHT]=x;
		}
	x_edge[0][MIDDLE]= (x_edge[0][RIGHT]+ x_edge[0][LEFT])/2;

	 for(y=1;y<PIX_Y;y++)
	 {

		 x=x_edge[y-1][RIGHT]-1;
	    while(x<PIX_X&&x>0)
	    {
			if(!Image[PIX_Y-1-y][x])x++;else x--;
	    	//x++;
		      if(!Image[PIX_Y-1-y][x-1]&&Image[PIX_Y-1-y][x]) break;
	    };

	    x_edge[y][RIGHT]=x;

	 x=x_edge[y-1][LEFT]+1;
	    while(x<PIX_X&&x>0)
	    {
		  if(!Image[PIX_Y-1-y][x])x--;else x++;
	    	//x--;
	      if(!Image[PIX_Y-1-y][x+1]&&Image[PIX_Y-1-y][x]) break;
	    };
	    x_edge[y][LEFT]=x;

	    x_edge[y][MIDDLE]= (x_edge[y][RIGHT]+ x_edge[y][LEFT])/2;
	   // if(x_edge[y][LEFT]>x_edge[y][RIGHT])x_edge[y][MIDDLE]=x_edge[y-1][MIDDLE];
	    Image[PIX_Y-1-y][x_edge[y][MIDDLE]]=!Image[PIX_Y-1-y][x_edge[y][MIDDLE]];

    }
};


float img_calc(float k){
    float img_trend;
    uint8_t y;
    for(y=1;y<=PIX_Y;y++){
    	     img_trend+=(float)(x_edge[y][MIDDLE]-PIX_X/2)/y;

        if(x_edge[y][LEFT]>(PIX_X/2-(30-y/3))||x_edge[y][RIGHT]<(PIX_X/2+(30-y/3))){
            return (float)img_trend+(float)k*(x_edge[y][MIDDLE]-PIX_X/2)*(4000-y*y)/16;
        }

    }
return img_trend;
};



/*


u8 pix[PIX_Y][PIX_X]=0;
u8 x_edge[PIX_Y][3]=0,car_edge[PIX_Y][3]=0;

void img_deflection(){
	u8 x,y;
	float img_trend;

	x_edge[0][LEFT]=0;     //x_edge[0][LEFT]=PIX_X/2;
	x_edge[0][RIGHT]=PIX_X;//x_edge[0][RIGHT]=PIX_X/2;

  	for(y=1;y<=PIX_Y;y++){
        x=x_edge[y-1][MIDDLE];
	while(x%PIX_X){
        if(Image[PIX_Y-1-y][x])x++;else x--;
		if(Image[PIX_Y-1-y][x]^Image[PIX_Y-1-y][x+1]) break;
	};

	x_edge[y][LEFT]=x;
        x=x_edge[y-1][MIDDLE];
	while(x%PIX_X){
		if(Image[PIX_Y-1-][x])x--;else x++;
		if(Image[PIX_Y-1-y][x]^Image[PIX_Y-1-y][x-1]) break;
	};

	x_edge[y][RIGHT]=x;
	x_edge[y][MIDDLE]=(x_edge[y][RIGHT]+x_edge[y][LEFT])/2;
    }
}



*/






































