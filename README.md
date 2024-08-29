# pong++
pong++ is a clone of Atari's 1972 two-player game "pong" made with C++, It uses a custom engine/library called "tahmlib".

Currently tested for Windows 10.

<br/>

## How to run
pong++ was made with Visual Studio 2022. It uses the "Desktop Development with C++" module. Install those and run Visual Studio. Afterwards, click on "Clone a Repository". <br/>
![image](https://github.com/user-attachments/assets/6cb6219f-1023-4eef-953f-354b717218d2)


Copy the repository location and choose a desired path on your PC. <br/>
![image](https://github.com/user-attachments/assets/8d2f069d-c400-4b49-8b4f-1e57391fb934)<br/>


Click on "clone" and you're all set, **code away!**<br/>
note: MAKE SURE TO SET THE CONFIGURATION TO x86 IF IT'S NOT ALREADY SET TO THAT, AS TAHMLIB HAS ONLY BEEN SET UP FOR 32 BIT AT THE MOMENT

<br/>

## Required libraries
ALL of the required libraries are included in the source code, no need to download/set them up.
- [tahmlib](https://github.com/tamtaasatiani/tahmlib) : engine/gamedev library. Organizes video, audio, input, and rendering. Implements the game loop.
- [SDL](https://github.com/libsdl-org/SDL) : window management, rendering, input, audio. Used by tahmlib.
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf) : font management. Used by tahmlib.

<br/>
