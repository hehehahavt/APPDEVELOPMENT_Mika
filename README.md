Student name : Duong Hiep. ID : e1601114
https://github.com/hehehahavt/APPDEVELOPMENT_Mika


# Acoustic Sensor using RPi3 

This project is aimed to create a acoustic sensor by utilize Raspberry Pi 3. The project is made as a lesson for each student in first year IT in VAMK to get familiar with application development under the assistance of professor Gao Chao. 

## Getting Started 

```
The project require a Raspberry Pi3, with a USB sound card and a microphone.
You can download all source code from Github and store in one directory
CODE : https://github.com/hehehahavt/APPDEVELOPMENT_Mika 

```
### List of project files 
```
README.md	: this file
makefile	: the makefile of this project
wave.c		: the module containing functions about wave processing
wave.h		: the header of wave.c
screen.c	: the module containing functions about screen manupulation
screen.h	: the header of screen.c
comm.c		: the communication module using libcurl
comm.h		: the header file of comm.c
main.c		: contains main() function
raspsound.php	: the server page to receive data for every 1 second and write to soundlog.txt
read_file3.php	: the server page to read 32 last data from soundlog.txt and show as a chart, the page auto reload for every 1 second so that you can see it as a real-time chart 
```

### Prerequisites

The installation require both hardware configuration and software configuration. 

Hardware : 
```
Connecting all the required devices. Ethernet connection is recommended.
If and older version of Rpberry Pi3 is used, certain change might be necessary.
```

Software : 
```

#1 :RPi onboard sound card doesn't have microphone interface. We have to change the default audio device to be USB sound card
    Use "lusb" command to check if your USB sound card is mounted. 

#2 :Run "sudo nano /etc/asound.conf" command and put following content to the file. 
    pcm.!default{
		type plug
		slave{
			pcm "hw:1,0"
		  }
  	}
	  ctl.!default{
	  	type hw
	  	card 1
	  }

#3 :Run "nano .asoundrc" and put the same content to the file

#4 :Run "alsamixer" to see that USB sound card is the default audio device. You can adjust the volume of mic and headphone

#5 : Second you need to downgrade the alsa-utils from 1.0.28 to 1.0.25. To do so,we need to do all steps:
    Use "sudo nano /etc/apt/sources.list" command and add : deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi"
#6 : Run "sudo apt-get update"
    Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-util is availble
    Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade
#7 :Reboot
    Run “arecord -r44100 -c1 -f S16_LE -d5 test.wav” to test that your microphone is working. You should see a “test.wav” file in the       current folder
    Put earphone on. Run “aplay test.wav” to check that your recording is okay
```
### Installing

Use command "make" to compile and link all the source code.
Sometimes the installation encounters a glitch. It will not compile and say that all the file are updated. Type command "make clear" and retry again. 

## Running 

Run "make" to make file
Run "./wave.a" and record your sound if you want
You will see a screen with many vertical bars and information of duration,
bits per sample, and sample rate.
To stop the program: Ctrl+C


## Deployment Note

This is a complete version that can run properly. 


## Authors

* **Duong Hiep ** - *e1601114* [DuongHiep's github project](https://github.com/hehehahavt/APPDEVELOPMENT_Mika)
Gmail : hiepduong180398@gmail.com

## Acknowledgments

* All the code in this project is belong to professor Gao Chao in Vaasa University of Applied Science. 
