ACMI Backend Platform 

Gateware/Software for ACMI Backend.  Uses zuDFE board as the hardware platform.   Communicates with the control system via gigE using FreeRTOS and PSC.  Communicates with the 2 Front End ACMI Artix boards.  Contains embedded EVR.

Uses the DESY FWK FPGA Firmware Framework https://fpgafw.pages.desy.de/docs-pub/fwk/index.html

Clone with --recurse-submodules to get the FWK repos

git clone --recurse-submodules https://github.com/jamead/acmi-backend

Setup Environment: make env (first time only)

To build firmware make cfg=hw project (Sets up project)

make cfg=hw gui (Open in Vivado)

make cfg=hw build (Builds bit file)

To build Software

make cfg=sw project (Sets up project)

make cfg=sw gui (Opens in Vitis)

make cfg=sw build (Builds executable)

