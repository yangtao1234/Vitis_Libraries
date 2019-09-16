## Population Markov Chain Mote Carlo (MCMC) Demonstration
This is a demonstration of the Population based MCMC built using the Vitis environment.  It supports software and hardware emulation as well as running the hardware accelerator on the Alveo U200.

The demonstration run the kernel to generate configurable number of Samples. Samples are saved to a csv file for further analysis.

## Prerequisites

- Alveo U200 installed and configured as per https://www.xilinx.com/products/boards-and-kits/alveo/u200.html#gettingStarted
- Xilinx runtime (XRT) installed
- Xilinx Vitis 2019.2 installed and configured

## Building the demonstration
The kernel and host application is built using a command line Makefile flow.

### Step 1 :
Setup the build environment using the Vitis and XRT scripts:

            source <install path>/Vitis/2019.2/settings64.sh
            source /opt/xilinx/xrt/setup.sh

### Step 2 :
Call the Makefile passing in the intended target and platform (.xpfm). For example:

            make all TARGET=sw_emu DEVICE=xilinx_u200_xdma_201830_1

 The Makefile supports software emulation, hardware emulation and hardware targets ('sw_emu', 'hw_emu' and 'hw', respectively). The host application (bsm_test) is written to the root of this demo folder, and the xclbin is delivered into the xclbin folder with a name identifying the card and target.  For example the U200 software emulation build produces:

            mcmc_kernel.sw_emu.u200.xclbin

The xclbin is passed as a parameter to the host code along with the number of Samples to generate and burn_in samples.
The software emulation can be run as follows:

            export XCL_EMULATION_MODE sw_emu
            ./mcmc_test ./xclbin/mcmc_kernel.sw_emu.u200.xclbin 500 50

The hardware emulation can be run in a similar way, but a smaller number of parameters should be used as an RTL simulation is used under-the-hood:

            export XCL_EMULATION_MODE hw_emu
            ./mcmc_test ./xclbin/mcmc_kernel.hw_emu.u200.xclbin 500 50

Assuming an Alveo U200 card with the XRT configured the hardware build is run in the same way.  Here a much large number of parameters should be used to fully exercise the DDR bandwidth:

            unset XCL_EMULATION_MODE
            ./bsm_test ./xclbin/bsm_kernel.hw.u200.xclbin 5000 500

## Example Output
This is an example output from the demonstration using a sw_emu target.

    *************                                                                                                                                               
    MCMC Demo v1.0                                                                                                                                      
    *************                                                                                                                                      
    Connecting to device and loading kernel...
    Found Platform                                                                                                                                               
    Platform Name: Xilinx                                                                                                                                
    INFO: Importing ./xclbin/mcmc_kernel.sw_emu.u200.xclbin                                                                                                   
    Loading: './xclbin/mcmc_kernel.sw_emu.u200.xclbin'                                                              
    Allocating buffers...                                                    
    Launching kernel...
    Duration returned by profile API is 23853 ms ****                                                                                             
    Kernel done!                                                                                                                                   
    Processed 500 samples with 10 chains                                                                                                       
    Samples saved to sdx_samples_out.csv                                                        
    Use Python plot_hist.py to plot histogram  