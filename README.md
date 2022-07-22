# MP4TOYUV
MP4TOYUV is one of the preprocessing processes of the [ Video super resolution](https://github.com/Hyunmin-jasper-Cho/VideoSuperResolution) project,  
and it is a program that helps create YUV datasets in various environments, including the CTC environment.

# Preparation & Installation
> 1. After downloading the clone or zip file, save it in the local folder.
> 2. After moving into Clone Directory, put the .mp4 file, which is compressed by  
> H.264 or H.265 format, into the corresponding directory, either 8bit_420 or 10bit_420.
> 3. Compile

# Run & Test
- When executed, the MPEG2YUV.sh file is automatically created in each 8bit_420 and 10bit_420 directory.
- After that, go to the directory and run it to create a yuv file.
`cd ./8bit_420`
`sh MPEG2YUV`
