/******************************************************************************
* Copyright (c) 2017 Fahad Siddiqui
* All rights reserved.
*
* This source code is licensed under the BSD-4-Clause license found in the
* LICENSE file in the root directory of this source tree. 
/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "xparameters.h"
#include "xtime_l.h"
#include "video_functions.h"

void print(char *str);

//const x=640;
//const y=480;
int i,j;
unsigned short temp;
//const NPixels = 640*480;
const NPixels = 10;
const BINS = 10;


unsigned short output;
unsigned short frame1[307200]={};
unsigned short frame2[307200]={};
unsigned short outputFrame[307200]={};

unsigned short GaussFrame[307200]={};
unsigned short HighFrame[307200]={};
unsigned short LowFrame[307200]={};
unsigned short outputLL[307200]={};
unsigned short outputLH[307200]={};
unsigned short outputHL[307200]={};
unsigned short outputHH[307200]={};


unsigned short hist[65535]={};


unsigned short sample[]={
		1,2,3,
		4,5,1,
		1,1,1,5
};


/*
 * Generate video frame of 640x480 pixels using random generation
 */
void generate_image(void)
{
	printf("\n\r Generating Video Frame of 640x480.. \n\r");

	for (i=0; i<NPixels ; i++)
	{
		frame1[i] = rand();
		frame2[i] = rand();
		//printf("%d %d ", frame1[i],frame2[i]);
	}
}

/*
 * Main function
 */
int main() {
    XTime tStart, tEnd;

    short	grad;
    short 	gaus;
    short   	gx[10] = {};
    short   	gy[10] = {};
    short 	g[10] = {};

    init_platform();


    generate_image();

	for(i=0; i<65535 ; i++)
	{
		hist[i] = 0 ;
	}

    XTime_GetTime(&tStart);
    
    /******************************************************************************************
    * Uncomment one of the following functions at a time to measure the performance benchmarks
    ******************************************************************************************/

    // Image Contrast
    /*
    printf("\n\rImage Contrast....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = contrast(frame1[i],5);
    }
    */


    // Image Threshold
    /*
    printf("\n\rImage Threshold....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = threshold(frame1[i],5);
    }
    */

    // Image Gradient
    /*
    printf("\n\rImage Gradient....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = gradient(frame1[i],frame2[i]);
    }
    */

    // Gaussian Filter
    /*
    printf("\n\rImage Gaussian 3x3....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = gaussian(	frame1[i],frame1[i+1], frame1[i+2],
    						frame1[i+3],frame1[i+4], frame1[i+5],
							frame1[i+6],frame1[i+7], frame1[i+8]
    					 );
    }
    */


    // SobelX Filter
    /*
    printf("\n\rImage SobelX 3x3....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = sobelX(	frame1[i],frame1[i+1], frame1[i+2],
    								frame1[i+3],frame1[i+4], frame1[i+5],
									frame1[i+6],frame1[i+7], frame1[i+8]
    					 );
    }
    */


    // SobelY Filter
    /*
    printf("\n\rImage SobelY 3x3....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = sobelY(	frame1[i],frame1[i+1], frame1[i+2],
    								frame1[i+3],frame1[i+4], frame1[i+5],
									frame1[i+6],frame1[i+7], frame1[i+8]
    					 );
    }
    */


    // Morphology Dilation Filter
    /*
    printf("\n\rImage Dilation 3x3....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = morphology_dilation(	frame1[i],frame1[i+1], frame1[i+2],
    								frame1[i+3],frame1[i+4], frame1[i+5],
									frame1[i+6],frame1[i+7], frame1[i+8]
    					 );
    }
    */


    // Morphology Erosion Filter
    /*
    printf("\n\rImage Erosion 3x3....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	outputFrame[i] = morphology_erosion(	frame1[i],frame1[i+1], frame1[i+2],
    								frame1[i+3],frame1[i+4], frame1[i+5],
									frame1[i+6],frame1[i+7], frame1[i+8]
    					 );
    }
    */

    // Histogram Calculation
    /*
    printf("\n\r Histogram Calculation....\n\r");

	for (i=0; i<NPixels ; i++)
    {
		// Get the pixel value
		output = frame1[i];

		// Get the pixel histogram
		temp = hist[output];
		temp = temp + 1 ;

		hist[output] = temp;
    }
    /*
	for(i=0; i<BINS ; i++)
	{
		printf("%d BIN: %d \n\r",i,hist[i]);
	}
    */


    // Wavelet Transform
       printf("\n\r Wavelet Transform....\n\r");

       //printf("\n\rImage Gaussian 3x3....\n\r");
       for (i=0; i<NPixels ; i++)
       {
        	GaussFrame[i] = gaussian(	frame1[i],frame1[i+1], frame1[i+2],
        						frame1[i+3],frame1[i+4], frame1[i+5],
    							frame1[i+6],frame1[i+7], frame1[i+8]
        					 );
       }

       //printf("\n\r 1st order Low-pass (L)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	LowFrame[i] = sobelX(	GaussFrame[i],GaussFrame[i+1], GaussFrame[i+2],
       			GaussFrame[i+3],frame1[i+4], GaussFrame[i+5],
				GaussFrame[i+6],frame1[i+7], GaussFrame[i+8]
       					 );
       }

       //printf("\n\r 1st order High-pass (H)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	HighFrame[i] = sobelY(	GaussFrame[i],GaussFrame[i+1], GaussFrame[i+2],
       			GaussFrame[i+3],GaussFrame[i+4], GaussFrame[i+5],
				GaussFrame[i+6],GaussFrame[i+7], GaussFrame[i+8]
       					 );
       }

       //printf("\n\r 2nd order Low-pass (LL)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	outputLL[i] = sobelX(	LowFrame[i],LowFrame[i+1], LowFrame[i+2],
       			LowFrame[i+3],LowFrame[i+4], LowFrame[i+5],
				LowFrame[i+6],LowFrame[i+7], LowFrame[i+8]
       					 );
       }

       //printf("\n\r 2nd order High-pass (LH)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	outputLH[i] = sobelY(	LowFrame[i],LowFrame[i+1], LowFrame[i+2],
       			LowFrame[i+3],LowFrame[i+4], LowFrame[i+5],
				LowFrame[i+6],LowFrame[i+7], LowFrame[i+8]
       					 );
       }

       //printf("\n\r 2nd order Low-pass (HL)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	outputHL[i] = sobelX(	HighFrame[i],HighFrame[i+1], HighFrame[i+2],
       			HighFrame[i+3],HighFrame[i+4], HighFrame[i+5],
				HighFrame[i+6],HighFrame[i+7], HighFrame[i+8]
       					 );
       }

       //printf("\n\r 2nd order High-pass (HH)....\n\r");
       for (i=0; i<NPixels ; i++)
       {
       	outputHH[i] = sobelY(	HighFrame[i],HighFrame[i+1], HighFrame[i+2],
       			HighFrame[i+3],HighFrame[i+4], HighFrame[i+5],
				HighFrame[i+6],HighFrame[i+7], HighFrame[i+8]
       					 );
       }



    /*
     * Sobel Edge Task
     */
	/*
    printf("\n\r Sobel Edge Detection....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	g[i] = gaussian(frame1[i],frame1[i+1],frame1[i+2],frame1[i+3],frame1[i+4],frame1[i+5],frame1[i+6],frame1[i+7],frame1[i+8]);
    }

    for (i=0; i<NPixels ; i++)
    {
      	gx[i] = sobelX(g[i],g[i+1],g[i+2],g[i+3],g[i+4],g[i+5],g[i+6],g[i+7],g[i+8]);
    }

    for (i=0; i<NPixels ; i++)
    {
    	gy[i] = sobelY(g[i],g[i+1],g[i+2],g[i+3],g[i+4],g[i+5],g[i+6],g[i+7],g[i+8]);
    }

    for (i=0; i<NPixels ; i++)
    {
    	grad = gradient(gx[i],gy[i]);
    	//printf("Gx: %d Gy: %d ; Out: %u\n\r",gx[i],gy[i],grad);
    }
    */
    /////////////////////////////////////////////////////////////////

    XTime_GetTime(&tEnd);

    printf("Output took %llu clock cycles.\n", 2*(tEnd - tStart));
    printf("Output took %.2f us.\n",
           1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000));

    cleanup_platform();
    return 0;
}
