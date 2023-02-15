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
#include "platform.h"
#include "xil_printf.h"
#include "functions.h"

// Constants
const NPixels 			= 10;
const contrastValue		= 5 ;
const thresholdValue 	= 5 ;



int i;
unsigned short output ;
short	grad;
short 	gaus;
short   gx[10] = {};
short   gy[10] = {};
short 	g[10] = {};

int main()
{
    init_platform();

    print("**************************************************************\n\r");
    print("Video Benchmarks running on ARM Cortex-A9 CPU (Zynq 7000 SoC) \n\r");
    print("**************************************************************\n\r");


    /*
     * Image Contrast
     */
    printf("\n\rImage Contrast....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	output = contrast(i,contrastValue);
    	printf("In: %u  ; Out: %u\n\r",i,output);
    	//sleep(1);
    }

    /*
     * Image Threshold
     */
    printf("\n\rImage Threshold....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	output = threshold(i,thresholdValue);
    	printf("In: %u  ; Out: %u\n\r",i,output);
    	//sleep(1);
    }

    /*
     * Gradient Calculation
     */
    printf("\n\rGradient Calculation....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	grad = gradient(i,(i*-2)+7);
    	printf("Gx: %d Gy: %d ; Out: %u\n\r",i,(i*-2)+7,grad);
    	//sleep(1);
    }

    /*
     *  Gaussian Filter
     */
    printf("\n\r3x3 Gaussian FIlter....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	gaus = gaussian(i,i+1,i+2,i+3,i+4,i+5,i+6,i+7,i+8);
    	printf("Pixel Window: %d %d %d %d %d %d %d %d %d Out: %d\n\r",i,i+1,i+2,i+3,i+4,i+5,i+6,i+7,i+8,gaus);
    	//sleep(1);
    }

    /*
     *  SobelX Filter
     */
    printf("\n\r3x3 SobelX Filter....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	gaus = sobelX(i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8);
    	printf("Pixel Window: %d %d %d %d %d %d %d %d %d ; Out: %d\n\r",i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8,gaus);
    	//sleep(1);
    }

    /*
     *  SobelY Filter
     */
    printf("\n\r3x3 SobelY Filter....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	gaus = sobelY(i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8);
    	printf("Pixel Window: %d %d %d %d %d %d %d %d %d ; Out: %d\n\r",i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8,gaus);
    	//sleep(1);
    }


    /*
     *  Morphology Dilation Filter
     */
    printf("\n\r3x3 Morphology Dilation Filter....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	gaus = morphology_dilation(i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8);
    	printf("Pixel Window: %d %d %d %d %d %d %d %d %d ; Out: %d\n\r",i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8,gaus);
    	//sleep(1);
    }

    /*
     *  Morphology Erosion Filter
     */
    printf("\n\r3x3 Morphology Erosion Filter....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	gaus = morphology_erosion(i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8);
    	printf("Pixel Window: %d %d %d %d %d %d %d %d %d ; Out: %d\n\r",i,i*1,i*2,i*3,i*4,i*5,i*6,i*7,i*8,gaus);
    	//sleep(1);
    }

    /*
     * Sobel Edge Task
     */
    printf("\n\r Sobel Edge Detection....\n\r");
    for (i=0; i<NPixels ; i++)
    {
    	g[i] = gaussian(i,i+1,i+2,i+3,i+4,i+5,i+6,i+7,i+8);
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
    	printf("Gx: %d Gy: %d ; Out: %u\n\r",gx[i],gy[i],grad);
    }


    cleanup_platform();
    return 0;
}
