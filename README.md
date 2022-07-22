# MP4TOYUV
MP4TOYUV is one of the preprocessing processes of the [ Video super resolution](https://github.com) project,  
and it is a program that helps create YUV datasets in various environments, including the CTC environment.

# Preparation & Installation
> 1. After downloading the clone or zip file, save it in the local folder.
> 2. After moving to the directory (cd local_root/), put the compressed .mp4 file  
> according to the H.264/H.265 Planar (if it exists) in the 8bit_420 and 10bit_420 directories inside the directory.
> 3. Compile

# Run & Test
- When executed, the MPEG2YUV.sh file is automatically created in each 8bit_420 and 10bit_420 directory.
- After that, go to the directory and run it to create a yuv file.
`cd ./8bit_420`
`sh MPEG2YUV`
