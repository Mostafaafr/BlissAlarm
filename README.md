[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2yGso8Cl)
# A14-Final Submission
    * Team Number: 13
    * Team Name: BlissAlarm
    * Team Members: Mostafa Afr and Abir Hossain

# Section 1: Video Presentation
Find the video here: https://www.youtube.com/watch?v=Qn7JugjathM&ab_channel=MostafaAfr
[![Video](https://img.youtube.com/vi/Qn7JugjathM/0.jpg)](https://www.youtube.com/watch?v=Qn7JugjathM&ab_channel=MostafaAfr)


# Section 2: Project Photos & Screenshots

## Final Project Look
![hard1](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/hardware1.JPG)
![hard2](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/hardware2.JPG)
![hard3](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/hardware3.JPG)
![hard4](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/hardware4.jpg)

## PCBA Pictures

### Top 
![topPCB](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/PCBA_TOP.JPG)
### Bottom 
![bottomPCB](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/PCBA_BOTTOM.JPG)

## Thermal Images
![thermal pic](https://github.com/ese5160/a12-board-bringup-group-blissalarm/blob/main/images/IMG_8845.JPG)

## Altium Designs

### 2D View
![2dview](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/2d_cad.png)
### 3D View
* Top: ![3dfront](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/FRONT_3d_cad.png)
* Bottom: ![3dback](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/BACK_3d_cad.png)

## Node RED Dashboard

### Node RED Frontend
![nodeRed](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/NODE_RED_FRONTEND.png)
### Node RED Backend
* Checking if prayed: ![prayed](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_hasprayed.png)
* Location: ![location](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_location.png)
* Motor: ![motor](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_motor.png)
* Prayer: ![prayer](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_prayer.png)
* Temperature: ![temp](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_temp.png)
* Time: ![time](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/node_red_back_time.png)

## Block Diagaram
![blockDiag](https://github.com/ese5160/a14-final-submission-group-blissalarm/blob/main/images/block_diagram.png)

# Section 3: Project Summary
## Device Description
Our project solves the issue of Muslims missing prayer times either due to sleep or even during the day. Prayer times change every single day since they are based on the sun’s movement (sunrise, midday, sunset, etc.), and it can be difficult to set an alarm every day for prayer or to always remember to pray on time. Our device connects to the internet and automatically pulls the date, time, and prayer times for that date. It then senses whether you’ve prayed or not using an accelerometer to track if you’ve done the movements for prayer. If you haven’t prayed and the prayer time is coming to an end soon, it will send vibrations with a haptic motor to remind you to pray.

## Inspiration
We were inspired to do this project by Mostafa's 200+ (not joking) alarms on his phone. He can’t wake up to normal alarms well but needs to pray before sunrise every morning, and a strong vibration if you haven’t prayed would be really helpful! This is the case for man Muslims and especially students who have terrible sleep schedules.

## Device Functionality
So the device design is fairly simple. It’s a microcontroller that connects to an OLED via I2C to display things like time, prayer time, etc. It connects to an accelerometer via I2C as well and checks the values at a set interval to try and detect the motions of prayer. It then connects to a haptic motor via a GPIO pin that vibrates if you haven’t prayed. The MCU is WiFi capable, so it connects to MQTT broker on our Azure server which then connects to Node RED to send and receive the data it needs to display. The casing for the watch is 3D printed to fit all the components inside (besides the PCBA which is too large due to the extra testing/debugging components we added). There are also laser cut pieces of acrylic for the bottom of the watch as it made it easier to take apart the watch for debugging. The parts are screwed together or held with adhesive and an ESD strap is used for the watchstrap.

## Project Links
### Node RED Instance
* Backend: http://20.102.106.224:1880/
* Frontend: http://20.102.106.224:1880/ui

### PCBA Link
Altium: https://upenn-eselabs.365.altium.com/designs/55E08EC9-9D23-40D7-89CE-D9C51BA8A47B

## Challenges
We had many, many challenges throughout this project. Our IMU was a major challenge. The IMU we had on our board turned out to have incredibly complex drivers that were difficult to port as it was made for arduino/raspberrypi, and it had its own protocol that wasn’t quite I2C but used I2C in it. We had to switch to a different accelerometer, but thankfully we had an extra JST connector. That extra JST connector unfortunately had the SCL and 3V3 pins swapped, and the trace for the 3V3 pin was really short. That took a couple hours to debug between figuring out the problem, carefully using the knife, and then soldering and resoldering the leads on tight points. We also had many struggles with FreeRtos causing issues. When we pulled pins high they went to .5V instead of 3.3V which is just really weird. We messed with our RTOS scheduling and it fixed it. We had a lot of trouble finding our IMU using I2C even after we switched, which is really odd too. RTOS again caused some issues. We got weird stack overflow errors that sometimes fixed when we unplugged our accelerometer or board. We also had issue with scheduling and getting all of our peripherals to simultaneously work, as sometimes one worked but blocked another. We had problems with MQTT in general as that also had some just weird errors like the Detkin wifi also causing a stack overflow error. We had issues with the screws being too long on our casing and also the casing damaging the OLED we were using (I think that’s what happened at least). Our debug buttons also didn’t work which may have been our own fault in our altium design. A number of things just went wrong and it would take forever to list them all here. We overcame them by asking others in lab for help, reading online, or just trying different things. Each problem came with a set of debugging steps to find a unique solution. Sometimes it was altium, sometimes it was hardware, a lot of times it was RTOS, and sometimes it was unknown Heisenbugs. 

## Prototype Learnings
We learned how to do Altium which we both came in knowing nothing about. That came with a general knowledge of PCBs that we plan to continue into my other products We learned a lot about embedded systems and I2C as well, RTOS, bootloaders, Github, we’ve come out of this class knowing a lot of very necessary skills for prototyping our own projects. We also learned about Node RED and setting up a server, both very useful skills. Node RED in particular is really cool and a nice approach to IoT compared to what we’d done in say ESE 111 with Blynk. We learned about prototyping with different MCUs, particularly a less common one than we did in ESE 350. We even used laser cutting and 3D printing in our final design. We learned a lot of prototyping techniques with regard to coding drivers and picking peripherals and making BOMs (although really boring) that will definitely be useful in our future! If we had to build the device again (which we are actually considering!) we would remove a lot of debugging components since we’ve tested them already. We would fix our mistake of swapping the SCL and 3V3 pins and fix our buttons. We’d definitely use a smaller MCU to make the PCB fit in the watch and choose a bigger screen since those are popular for watches. We’d also change the IMU we are using. Size is really important for our design so we would do a lot of trimming of things to save space.

## Next Steps
We think the steps needed to improve the project are a lot of what we mentioned in question 5. But aside from that, we think we could add a gyroscope. It proved too difficult this time around, but we could do it with more time perhaps. We would also improve the casing to look more professional. We would also work on reliability of the product, as a prototype has its bugs. We would likely add more to the UI on the screen, we think it is fine now, but making it a bit more aesthetic could help it stand out better as a watch. Adding an app could be really helpful too. We also think we should be mainly focusing on size and squeezing the PCB to a much smaller size by shrinking the MCU. 

## Takeaways from ESE 5160 
We learned altium exceptionally well, and learned a lot about I2C. We gained a general understanding of what embedded systems looks like in industry, with power planning, peripheral selection, PCB design, driver coding, etc. We improved in our general knowledge of RTOS based systems, MCUs, etc., and came out just better embedded engineers. We still have a lot to learn, but this was a great introduction to intermediate embedded systems, and we come away with the confidence and ability to build more complex projects!

# Section 4: Codebase
## Attributions for Driver Code

### OLED Driver:
For the OLED Driver, we ported a driver we found on GitHub by elektro155, which can be found at https://github.com/elektro155/OLED-display-SSD1306-library-converted-for-ARM-C-language/tree/master. We attempted to make our own driver, but for this specific OLED it proved to be difficult. The author fo the driver did not post any rules about any specific requirements for attributions. 

### IMU Driver:
For the IMU, we used the IMU that was already used in a previous assignment, so we copied over the driver for that into our final demo. 

### Motor Driver:
We wrote this driver ourselves, and it was on the easier end to do as it was just manipulating the state of a GPIO pin for certain lengths of time. 
