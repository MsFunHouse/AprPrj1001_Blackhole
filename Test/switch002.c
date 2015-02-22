/****************************************************************************
 File:			switch001.c

 Version:		0.02
 Description:	Random number and switch test

 Created on:	2015-02-22
 Created by:	April

 Board:			RichMCU RZ-51V2.0

 Jumpers:		Remove JPSMG - Disable 7-Segment LEDs

				�� JPSMG ����ܿ������߰ε�ʹ�����ֹͣ������
****************************************************************************/
#include <STC89.H>

#define	HIGH	1
#define LOW		0

#define	EOF		0xff

void delay(int n)
{
	int t;

	for (t=0; t<n; t++);
}

char playerList;
char playerStar;

void main(void)
{
	/* Init player selection to invalid */
	playerList = 0xff;
	playerStar = 0xff;

	int	rndL=0;
	
	char randomL, x;

	char rndList[] = {7, 5, 3, 6, 2, 4, 1, 0, 6, 3, 6, 4, 2, 6, 4, 0, 1, 2, 6, 
					  4, 6, 3, 2, 0, 3, 5, 7, 2, 6, 3, 7, 1, 5, 0, 3, 5, 2, 4,
					 EOF};

	/* Turn off all LEDs */
	P0 = HIGH;
	P1 = HIGH;
	P2 = HIGH;

	/* Set Pin ready for Input */
	P14 = HIGH;
	P15 = HIGH;
	P16 = HIGH;
	P17 = HIGH;

    for (;;)
	{
		while (P14 == HIGH);		/* Key Off */

		while (P14 == LOW)
		{
			random = rndList[rnd++];
			if (rndList[rnd] == EOF) rnd = 0;
	
			x = 1 << random;
	
			P0 = ~x;
			
			delay(200);
		}
		playerList = random;
	}




	int	rnd=0;
	
	char randomS, y;

	char rndStar[] = {3, 0, 6, 2, 1, 7, 5, 3, 4, 2, 0, 2, 1, 5, 6, 3, 2, 6, 1,
					  2, 5, 1, 6, 7, 3, 5, 0, 4, 6, 7, 1, 3, 6, 0, 7, 2, 3, 0,
					 EOF};

	/* Turn off all LEDs */
	P0 = HIGH;
	P1 = HIGH;
	P2 = HIGH;

	/* Set Pin ready for Input */
	P14 = HIGH;
	P15 = HIGH;
	P16 = HIGH;
	P17 = HIGH;

    for (;;)
	{
		while (P17 == HIGH);		/* Key Off */

		while (P17 == LOW)
		{
			randomS = rndList[rnd++];
			if (rndList[rnd] == EOF) rnd = 0;
	
			x = 1 << random;
	
			P0 = ~x;
			
			delay(200);
		}
		playerList = random;
	}
}