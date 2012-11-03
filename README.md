This is a little project to print "LinkedList NYC". Official rules below

RUNNING
=======
* This assumes you have
    1. A Thermal printer like the one available at Adafruit or Sparkfun
    2. An Arduino Uno (may work on other models, but not tested)
* Download and Install Arduino http://arduino.cc/en/Main/Software
* Clone this repo:  
    1. ```> git clone https://github.com/quinkennedy/print_linkedlist_nyc.git```  
    2. ```> git submodule init```  
    3. ```> git submodule update```  
* Copy the thermal printer library in this repo at Libraries/Adafruit_Thermal to your Arduino library. On OSX this will result in the path ~/Documents/Arduino/Libraries/Adafruit_Thermal/Adafruit_Thermal.h
* Connect the Thermal printer to a power supply that provides between 5V and 9V and at least 2A
* Connect the TX wire (Green wire on my model) to pin 5 on the Arduino
* Connect the RX wire (Yellow wire) to pin 6 on the Arduino
* Connect the GND wire (Black) to Gnd on the Arduino
* Connect the Arduino to your USB port
* Open print_memory.ino, compile, and upload the sketch
* Enjoy the printer's output

RULES
======
Write a program that prints the text "LinkedList NYC". For example, you could write the following in Python:

print "LinkedList NYC"

But that wouldn't be much fun. The goal is to do it in the most inventive way. Here's a slightly more interesting version in Bash:

```curl -s http://www.linkedlistnyc.org | sed -n 's/ *&lt;h1>\(.*\)&lt;\/h1>/\1/p'```

Bonus points if your code contains a pun, is self-referential, or is particularly clever or elegant. It can be as long or short as you like.

The winner will get five pints of ice cream delivered to his or her door by the List itself [Seriously! -Ed.]. Note: You must live within the five boroughs or an area served by the PATH train to be eligible for delivery.

Your program must:

* print or evaluate to the string "LinkedList NYC"
* be sent to tips@linkedlistnyc.org by 10am Saturday, Nov. 3
* include instructions for how to run it (if it's not easy and obvious)