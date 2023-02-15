# Benchamrking Image Processing Operations

<p align="justify">

This repository contains an implementation of basic image processing operations that are widely used in data intensive video classification and video analytics applications. The code is written in C language and implemented on [Xilinx Zynq 7000 SoC](https://www.xilinx.com/products/silicon-devices/soc/zynq-7000.html). This SoC consists of dual Arm Cortex-A9 CPUs tightly coupled with the Xilinx FPGA programmable logic. 

</p>

The following is a list of [point](https://homepages.inf.ed.ac.uk/rbf/HIPR2/pntops.htm) and [area](https://homepages.inf.ed.ac.uk/rbf/HIPR2/morops.htm) image processing operations considered in this work and benchmarked on [Avnet Zedboard Development Kit](https://www.avnet.com/wps/portal/us/products/avnet-boards/avnet-board-families/zedboard/) (Xilinx Zynq 7000 SoC).

## List of Image Processing Operations
<p align="justify">

### Point Operations
1. Contrast
2. Threshold
3. Gradient
### Area Operations
1. Gaussian Filter
2. Sobel Filters
3. Morphology Filters (Erosion, Dilation)
  
## Usage
Run the ../Benchmarks/TimeMeasurement.c

## Important References
<p align="justify">

[1] F. Siddiqui, S. Amiri, U. Minhas, "[FPGA-Based Processor Acceleration for Image Processing Applications](https://www.mdpi.com/394628)" in Journal of Imaging 2019, 5, 16.

[2] F. Siddiqui, M. Russell, B. Bardak, R. Woods and K. Rafferty, "[IPPro: FPGA based image processing processor](https://ieeexplore.ieee.org/abstract/document/6986057)" in IEEE Workshop on Signal Processing Systems (SiPS), Belfast, UK, 2014, pp. 1-6.

[3] M. Amiri, F. Siddiqui, C. Kelly, et al. "[FPGA-Based Soft-Core Processors for Image Processing Applications](https://link.springer.com/article/10.1007/s11265-016-1185-7)" in Journal of Signal Processing Systems, 87, 139–156 (2017).
  
[4] C. Kelly, F. M. Siddiqui, B. Bardak and R. Woods, "[Histogram of oriented gradients front end processing: An FPGA based processor approach](https://ieeexplore.ieee.org/document/6986093)" in IEEE Workshop on Signal Processing Systems (SiPS), Belfast, UK, 2014, pp. 1-6.

[5] F. Siddiqui, "[FPGA-based Programmable Embedded Platform for Image Processing Applications](https://pure.qub.ac.uk/en/studentTheses/fpga-based-programmable-embedded-platform-for-image-processing-ap)", 11 Sep 2018. (PhD Thesis)
</p>
