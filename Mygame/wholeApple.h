#ifndef WHOLE_TASK
#define WHOLE_TASK


#include<iostream>
#include<string>

using namespace std;


# include "iGraphics.h"
#include "Apple.h"


#define screenWidth 1000
#define screenHeight 900

int mposx, mposy;


/*...........Background immage.............*/
char backgroundimmage[10] = "bc\\bf.bmp";
char backgroundimmage1[10] = "bc\\bf.bmp";
int picx = 0, picy = 0;



/*--------Moving Basket------------*/
char basket[2][20] = { "fr\\basket.bmp", "fr\\basket1.bmp" };
int basktSpeed = 13;
int basx = 0, basy = 0;


/*...........SCORE..............*/
int total = 0;
string score;
int tplas, tminas;
char scr[100];


/*..............life...............*/
int life = 3;
string LIFE;

/*............game over............*/

char gmOver[10] = "fr\\o.bmp";


void gameover()
{
	iShowBMP(0, 0, gmOver);
	iShowBMP(700, 0, "fr\\bcb.bmp");
}



void background()
{
	iShowBMP(0, 0, backgroundimmage);
	iShowBMP(700, 0, "fr\\bcb.bmp");
}


void text()
{
	LIFE = to_string(life);
	iText2(750, 950, "Life::-", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(850, 950, LIFE, GLUT_BITMAP_HELVETICA_18);

	iText(750, 900, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(830, 900, score, GLUT_BITMAP_TIMES_ROMAN_24);

	iText2(750, 730, "Description:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText2(880, 730, "Press Right ", GLUT_BITMAP_HELVETICA_18);
	iText2(750, 680, " button to move 'RIGHT'", GLUT_BITMAP_HELVETICA_18);
	iText2(750, 630, "and left button to move 'LEFT'", GLUT_BITMAP_HELVETICA_18);


	iText2(750, 530, "p for pause", GLUT_BITMAP_HELVETICA_18);
	iText2(750, 500, "r for resume", GLUT_BITMAP_HELVETICA_18);
	iText2(750, 470, "s for restart game", GLUT_BITMAP_HELVETICA_18);

}

void iDraw()
{
	iClear();
	//place your drawing codes here
	if (life == 0)
	{
		gameover();

	}
	else if (life>0)
	{
		background();
		iShowBMP2(basx, basy, basket[0], 0);
		iShowBMP2(frx, fry, fr[0], 0);
		iShowBMP2(basx, basy, basket[1], 0);
	}

	text();


}







#endif