# Spring 2026 Luna 


# install dependencies (pyserial and keyboard)
pip install -r requirements.txt

# upload code
open arduino/rover_control.ino in arduino ide and update code

# open tools on the top and find ur serial
looks like this: ls /dev/tty.*

open keyboard_control.py and update port

# run the code
python control/keyboard_control.py

# binds
W - Forward  
S - Backward  
A - Left  
D - Right  
X - Stop