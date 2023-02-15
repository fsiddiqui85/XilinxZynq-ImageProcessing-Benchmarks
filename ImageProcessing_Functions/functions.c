/******************************************************************************
* Copyright (c) 2017 Fahad Siddiqui
* All rights reserved.
*
* This source code is licensed under the BSD-4-Clause license found in the
* LICENSE file in the root directory of this source tree. 
/******************************************************************************
/*
 * functions.c
 *
 *  Created on: 18 Jun 2018
 *      Author: Fahad Siddiqui
 */
/******************************************************************************

#include "functions.h"

/*
 * Point Benchmarks
 */

unsigned short 	contrast 	(unsigned short pixel, unsigned short value)
{
	return (pixel*value);
}


unsigned short 	threshold 	(unsigned short pixel, unsigned short value)
{
	if(pixel<value)
		return (0);			// Black
	else
		return(255);		// White
}

unsigned short	gradient	(short Gx, short Gy)
{
	return( abs(Gx) + abs(Gy) );
}


/*
 * Area Benchmarks
 */
short 	gaussian 	(unsigned short a,
		 unsigned short b,
		 unsigned short c,
		 unsigned short d,
		 unsigned short e,
		 unsigned short f,
		 unsigned short g,
		 unsigned short h,
		 unsigned short i
		 )
{
	short filter[9] = {1,2,3,4,5,6,7,8,9};

	short output;

	output = (a*filter[0]) +
		   (b*filter[1]) +
		   (c*filter[2]) +
		   (d*filter[3]) +
		   (e*filter[4]) +
		   (f*filter[5]) +
		   (g*filter[6]) +
		   (h*filter[7]) +
		   (i*filter[8]);

	return (output);
}


short 	sobelX 	(unsigned short a,
		 unsigned short b,
		 unsigned short c,
		 unsigned short d,
		 unsigned short e,
		 unsigned short f,
		 unsigned short g,
		 unsigned short h,
		 unsigned short i
		 )
{
	short filterX[9] = {-1,0,1,-2,0,2,-1,0,1};

	short output;

	output = (a*filterX[0]) +
		   //(b*filterX[1]) +
		   (c*filterX[2]) +
		   (d*filterX[3]) +
		   //(e*filterX[4]) +
		   (f*filterX[5]) +
		   (g*filterX[6]) +
		   //(h*filterX[7]) +
		   (i*filterX[8]);

	return (output);
}

short 	sobelY 	(unsigned short a,
		 unsigned short b,
		 unsigned short c,
		 unsigned short d,
		 unsigned short e,
		 unsigned short f,
		 unsigned short g,
		 unsigned short h,
		 unsigned short i
		 )
{
	short filterY[9] = {1,2,1,0,0,0,-1,-2,-1};

	short output;

	output = (a*filterY[0]) +
		   (b*filterY[1]) +
		   (c*filterY[2]) +
		   //(d*filterY[3]) +
		   //(e*filterY[4]) +
		   //(f*filterY[5]) +
		   (g*filterY[6]) +
		   (h*filterY[7]) +
		   (i*filterY[8]);

	return (output);
}


unsigned short min (unsigned short a, unsigned short b)
{
	if(a<b)
		return (a);
	else
		return (b);
}

unsigned short max (unsigned short a, unsigned short b)
{
	if(a>b)
		return (a);
	else
		return (b);
}


unsigned short	morphology_dilation	(unsigned short a,
							 	 	 unsigned short b,
									 unsigned short c,
									 unsigned short d,
									 unsigned short e,
									 unsigned short f,
									 unsigned short g,
									 unsigned short h,
									 unsigned short i
							 	 	 )
{
	short Dilationfilter[9] = {0,1,0,1,1,1,0,1,0};

	short output;

	output = max( (a*Dilationfilter[0]), (b*Dilationfilter[1]) );
	output = max( output, (c*Dilationfilter[2]) );
	output = max( output, (d*Dilationfilter[3]) );
	output = max( output, (e*Dilationfilter[4]) );
	output = max( output, (f*Dilationfilter[5]) );
	output = max( output, (g*Dilationfilter[6]) );
	output = max( output, (h*Dilationfilter[7]) );
	output = max( output, (i*Dilationfilter[8]) );

	return (output);
}


unsigned short	morphology_erosion	(unsigned short a,
							 	 	 unsigned short b,
									 unsigned short c,
									 unsigned short d,
									 unsigned short e,
									 unsigned short f,
									 unsigned short g,
									 unsigned short h,
									 unsigned short i
							 	 	 )
{
	short Erosionfilter[9] = {0,1,0,1,1,1,0,1,0};

	short output;

	output = max( (a*Erosionfilter[0]), (b*Erosionfilter[1]) );
	output = max( output, (c*Erosionfilter[2]) );
	output = min( output, (d*Erosionfilter[3]) );
	output = min( output, (e*Erosionfilter[4]) );
	output = min( output, (f*Erosionfilter[5]) );
	output = max( output, (g*Erosionfilter[6]) );
	output = min( output, (h*Erosionfilter[7]) );
	output = max( output, (i*Erosionfilter[8]) );

	return (output);
}
