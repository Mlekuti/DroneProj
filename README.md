#  Fall 23 Project <br>
Malik Lekuti - maliklekuti@gmail.com


# Project Overview 
The Drone Simulation System is a program that emulates the behavior of package delivery drones in
a 3D model environment. This program is written in C++, Javascript, with the use of Json objects as well

# Simulation Features 
Features of this program include: <br>
- Movement of drones between two points with different algorithms to design the movement
- Visualization of rotating weather patterns to alter the speed of the drone
- Notifications to notify the user when a package has been picked up, delivered, and when the weather pattern changes

# New Feature: Singleton and Observer for weather patterns and notifications
We have implemented weather models and and the singleton design pattern to track when the "weather states" representing these weather states with 3D glb models. With that different weather states, the drones travel
at different speeds depending on which weather pattern it switches to. We have the weatherSingleton class that tracks the current weather state and relays that 
to the entities (drone, helicopter, human) which will change the speed at which they move. If it is sunny outside the entities move normally. If it is snowing outside the entities move at 1/4 speed. If it is raining the entities move at 1/2 speed. If there is a tornado the entities stop moving in the place they are at to not go into the vortex. The other feature we have implemented is a notification system using the observer design pattern. This feature notifies the operator of the simulation what the weather pattern is currently going to be and at what time. In order to interact with the signleton pattern, we implented buttons on the 
front-end to switch between sunny, heavy rain, heavy snow, and a tornado. we also implemented an auto button to switch between these 4 patterns automatically.

# How to run simulation:
- You are going to want to compile the system using a C++ compiler. If on a Linux environment or on a CSELabs machine, type "make" or "make -j" on the command line 
- after that, to run the code use "./build/bin/transit_service 'port number' apps/transit_service/web
- NOTE: The port number can be a four digit number from 8080-8089 that is forwaded to your terminal. So if I want to run this program on 8081, then I would type this 
into the command line: "./build/bin/transit_service 8081 apps/transit_service/web"
- Once you have successfully compiled and ran the code, go to your web browser and type http://127.0.0.1:8081 (the '8081' part depends on what port you use). there
it should take you to the simulation browser and you should see a visualization along with the front-end buttons we have implemented.

# Sprint Retrospective

The team has made significant progress in implented the rotating weather models and addressing the movement changes using the singleton pattern along with the other 
patterns used for notifications. We found that these patterns were the most useful and effective way to implement what we wanted to do for our project extension. We 
all worked collaboratively and communicated our roles and significant changes to the overall project.

# UML 
<img width="205" alt="HW4 UML" src="https://media.github.umn.edu/user/26678/files/a9982fa0-627f-46ff-a13d-59e9d8ede5ff">
# Youtube Demo
https://youtu.be/4MGesfz19b8


# link to Dockerhub: 
https://hub.docker.com/repository/docker/mlekuti/drone_sim_hw4/general
