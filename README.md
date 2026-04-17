# Spring 2026 Luna 


# 1
git clone https://github.com/YOUR_USERNAME/rover-control.git
cd rover-control

# 2
pip install -r requirements.txt

# 3
- Open arduino/rover_control.ino in Arduino IDE
- Upload to Arduino Uno

# 4
ls /dev/tty.*

Update the port in keyboard_control.py

# 5
python control/keyboard_control.py

# binds
W - Forward  
S - Backward  
A - Left  
D - Right  
X - Stop