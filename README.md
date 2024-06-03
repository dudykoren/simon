Simon Game  
version 1.0  

This is a C++ code for creating a console application for a game of "Simon" with files:  
  
simon.cpp    
bsp.cpp   
bsp.h   
colors.h  


Default compilation sets the game to have 4 buttons    
For example: when cmake command is excuted in the loaction of the code files, commands:  
		cmake .  
		make  
will produce a binary called simon with 4 buttons .  

To produce a binary with a diffrent number of buttons add to the cmake command line:  
			-DBUTTONS_NUMBER=X  
where X is the number of buttons required.  
e.g. commands:  
		cmake . -DBUTTONS_NUMBER=8  
		make  
will produce the binary with 8 buttons  
  
  
There is an option to cross compile the code and produce a binary for a different platform   
For example Raspberry PI ARM based processor  
To do that the option "CROSS_COMPILE_ARM" needs to be set to ON i.e. -DCROSS_COMPILE_ARM=ON  
For example commands:  
		cmake . -DCROSS_COMPILE_ARM=ON  
		make   
will produce a binary for the specific platform called arm_simon    

The current cross compiler toolchain that is used in the cmake CMakeLists.txt file is:  
		arm-linux-gnueabihf  
which is located at path:  
		/usr/bin/  
  
To use a different cross compiler you need to change the following lines in the CMakeLists.txt to the proper compiler name and path:  
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)  
    set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)  
    set(CMAKE_SYSROOT /usr/bin/)  
	
For example to use cross compiler toolchain "arm_compiler" located in /usr/bin/arm  
The lines are changed to:   
		set(CMAKE_C_COMPILER arm_compiler-gcc)  
		set(CMAKE_CXX_COMPILER arm_compiler-g++)  
		set(CMAKE_SYSROOT /usr/bin/arm/)  
(assuming the gcc and g++ compiler commands are called arm_compiler-gcc and arm_compiler-g++ respectively)  
  
Of course you can use both defines.  
For example:  
		cmake . -DBUTTONS_NUMBER=8 -DCROSS_COMPILE_ARM=ON  
		make  

will produce a binary called arm_simon for the plafrom with a game with 8 buttons  
  
  
The code was tested on Kubuntu version 24.04    
and  
Windows 10 wsl Linux (default - Ubuntu)  
  
  
with the following packages installed   
(using command : sudo apt-get install   [package name])  
  
cmake  
make  
gcc  
g++  
gcc-arm-linux-gnueabihf   
g++-arm-linux-gnueabihf  
  
	
