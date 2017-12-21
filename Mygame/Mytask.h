#ifndef APPLE
#define APPLE

#define screenWidth 1000
#define screenHeight 900

int mposx,  mposy;


/*...........Background immage.............*/
char backgroundimmage[10] = "bc\\bf.bmp";
char backgroundimmage1[10] = "bc\\bf.bmp";
int picx = 0, picy = 0;


/*--------Moving Basket------------*/
char basket[2][20] = {"fr\\basket.bmp", "fr\\basket1.bmp"};
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


void fruitchange()
{

	int z = 0;
	fry -= frspeed + z;


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



#endif
