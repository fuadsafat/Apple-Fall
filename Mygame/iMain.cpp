/*    
    Author: Fuad Hasan
    last modified: 
*/
#include<iostream>
#include<string>

using namespace std;


# include "iGraphics.h"
#include "Apple.h"



#define screenWidth 1000
#define screenHeight 900

int mposx, mposy;
int p;

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
		iShowBMP2(frx+ p, fry, fr[0], 0);
		iShowBMP2(basx, basy, basket[1], 0);
	}

	text();


}





/*	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.*/
void iMouseMove(int mx, int my)
{/*
	basx = mx;
	basy = my;*/
}




/*	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.*/

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		/*basx += 10;
		if (basx > 585) basx = 585;
		basy = my;*/
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}



/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	/*
 mposx = mx;
 mposy = my;*/
 if(mx== 2){}        /*Something to do with mx*/
// else if(my== 2){}   /*Something to do with my*/
 
}



/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	if (key == 's')
	{
		total = 0;
		life = 3;
		iResumeTimer(0);
	}
	
}



/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
		basx += 10;
		if (basx > 585) basx = 585;
	}

	if (key == GLUT_KEY_LEFT)
	{
		basx -= 10;
		if (basx < 0) basx = 0;
	}


	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}



void fruitchange()
{
	
	int z = 0;
	fry -= frspeed+z;


	if (fry == 0)
	{
		total -= 2;
		frx = rand() % 585;

		fry = 900;
		//minas -= 2;
		
		life--;
		if (life == 0)iPauseTimer(0);

	}

	else if (frx >= basx && frx <= basx + 70)
	{
		if (fry == basy + 90)
			{

				frx = rand() % 585;
				fry = 900;
				total += 5;
			}


	
		score = to_string(total);
		

		int flag = total / 10;
		if ((double)total / 10.0 == flag)z += 12;
	}
	

}
		
	 


 void fruitchange();


int main()
{
	//place your own initialization codes here.

	iSetTimer(20, fruitchange);
	frspeed = 10;

	iInitialize(screenWidth, screenHeight + 200, "Safat");
	return 0;
}
