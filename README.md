# Lab 1: Digital Interfacing

When learning about an embedded system, you begin by learning how to
program it: how to supply inputs and how to produce system outputs. On
the Xilinx Zynq-7000 All Programmable SoC, you might wonder how a
language you know (like C) behaves on the system and what simple I/O is
available.

In this lab, we examine some common C functions and how to use de LEDs,
switches and pushbuttons present on the Zedboard as inputs and outputs
to/from the Zynq-7000.

Overall, the purpose of this lab is for you to get familiar with reading
a datasheet, extracting information from schematics and to be able to
use memory-mapped I/O to interact with the real world. Practicing
bitwise operations on the memory I/O registers that are connected to the
LEDs, switches and buttons will prepare you for embedded programming
using status and control registers.


# Assignment

Follow the [General Lab Instructions](GeneralLabInstructions.md) and the [Git/Submissions Instructions](submission.md). 

## Pre-Lab

To make efficient use of the limited lab time, prepare for this lab by solving the 
Pre-lab assignment (see Canvas) and go through the assigned reading see Reading List.

## Lab

The instructions for ths lab are detailed in the following steps:

 1. (Reserved for feedback branch pull request. You will receive top level feedback there). 
 2. [Getting Started](.github/STARTING_ISSUES/2.%20Getting%20Started.md)
 3. [LED Output](.github/STARTING_ISSUES/3.%20LED%20Output.md)
 4. [Binary Counter](.github/STARTING_ISSUES/4.%20Binary%20Counter.md)
 5. [Push Buttons](.github/STARTING_ISSUES/5.%20Push%20Buttons.md)
 6. [Post-Lab](.github/STARTING_ISSUES/6.%20Post-Lab.md)

After accepting this assignment in github classroom, each step is converted into a [github issue](https://docs.github.com/en/issues). Follow the issues in numerically increasing issue number (the first issue is typically on the bottom of the list). 

Please comment on each issue with the problems faced and your approach to solve them. Close an issue when done. 

# Reading List

The following documents will help you complete the pre-lab assignment.
These will also help you in subsequent lab assignments.

Please complete the reading assignments that are marked as before
attempting the pre-lab assignments.

Avnet, **ZedBoard Hardware User’s Guide**, v2.2  
<http://zedboard.org/sites/default/files/documentations/ZedBoard_HW_UG_v2_2.pdf>  
Guide to the ZedBoard platform

Xilinx, **AXI GPIO v2.0 Product Guide**, October 5, 2016  
<https://www.xilinx.com/support/documentation/ip_documentation/axi_gpio/v2_0/pg144-axi-gpio.pdf>  
Sections: *Register Space* and *Programming Sequence*

Bruno Morais, Gunar Schirner, **Zedboard Hardware Peripheral Mapping**,
Jan 6, 2020  
see link to Library on course website

Linux Programmer’s Manual, **MEM**, man-pages v4.14  
<http://man7.org/linux/man-pages/man4/mem.4.html>  
The `/dev/mem` device

Linux Programmer’s Manual, **MMAP**, man-pages v4.14  
<http://man7.org/linux/man-pages/man2/mmap.2.html>  
The `mmap()` function

Bruce Eckel, **Thinking in C**, online at
<http://www.mindviewinc.com/CDs/ThinkingInC/>  
Loops, function calls, pointers and bit manipulation.

**HINT:** Whenever you see the man-pages mentioned or a comment like
*see man \<name\>*, you can examine the documentation for that by simply
typing `man <name>` in a terminal inside the development environment.

