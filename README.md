# MP4TOYUV
MP4TOYUV is one of the preprocessing processes of the [ YUV Super Resolution ](https://github.com/Hyunmin-jasper-Cho/YU-VSR) project,  
and it is a program that helps create YUV datasets in various environments, including the CTC environment.

## Environment 
> GNU++17

## Preparation & Installation
> 1. After downloading the clone or zip file, save it in the local folder.
> 2. After moving into Clone Directory, put the .mp4 file, which is compressed by  
> H.264 or H.265 format, into the corresponding directory, either 8bit_420/mp4 or 10bit_420/mp4.
> 3. Compile

## Compile
> 1. Goto MP4toYUV directory, and make directory 'build'  
> `cd MP4toYUV` and `mkdir build`
> 2. move into build directory, then compile using cmake.  
> `cd build` and `cmake ..`
> 3. In build directory, run makefile to create executable file 
> `make`

## Run & Test
- When executed, the MPEG2YUV.sh file is automatically created in each 8bit_420 and 10bit_420 directory.
- After that, go to the directory and run it to create a yuv file.
> 1. After finish compilation, in build directory, execute MP4toYUV executable file with bit information.  
> When 8 bit, run `./MP4toYUV 8` (for MAC OS)  
> Or `./MP4toYUV 10` (for MAC OS)
