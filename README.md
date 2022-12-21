# 🐍 Snake-Arduino 🐍

## Components 📚
* Joystick
* 74hc595 shift register
* 8x8 LED matrix
* LCD display
* Buzzer
* Ceramic capacitor
* Electrolytic capacitor
* Wires
* Resistors
* Breadboard
* Button

## Game description/ How To Play 🏋️‍♀️
Snake is one og the simplest game in the world, and of the oldest game created on Earth. For me, it's very important to recreate this game phone because, it is my first game played on a mobile phone, exactly a Nokia 3310. The game logic is simple: move the joystick UP, DOWN, LEFT and RIGHT to have a better score. 
Goal is to eat the food and get a new high score. The game ends when the snake eats himself or collides with the obstacles/walls. If the selected the "easy" difficulty then if you eat your "food", you increase your score and the length of the snake. If you selected the "medium" difficulty then, when you'll eat the food, the snake speed will increase, you cannot go through walls at this difficulty, and the score will grow with 2 points instead of 1.
If the player finished in top 5 then it will appeared on Highscore Menu screen at top 5.

## How to use the menu ⚙️
When the board is powered up, a greeting message appears on the LCD for 3 seconds, then the user can navigate into menu using the joystick and toggling Y-axis to scroll up and down into menu.
The menu contains the followings:
* Play Game - where the user start the game 
* Highscore - where it's printing the top 5 scores with first 3 letters of their name (stored with EEPROM)
* Settings:
    * Matrix Brightness - toggle X-axis to change the matrix brightness (stored with EEPROM)
    * LCD brightness: the user can set the brightness of the LCD (stored with EEPROM)
    * LCD Constrast: the user can set the contrast of the LCD (stored with EEPROM)
    * Difficulty: the user can choose between easy and medium (stored with EEPROM)
* About - when you pressed about you'll see information about user
* How To Play ! - if you pressed it you'll see how to play the game

## Demo video presenting gameplay and menu 🎬

[Link to the video!](https://youtu.be/TT73e3caSRI)

[Link to the Code](https://github.com/Giani2001/Snake-Arduino/blob/main/Snake/Snake.ino)

## Setup
![alt text](https://github.com/Giani2001/Snake-Arduino/blob/main/setup.jpeg?raw=true)
