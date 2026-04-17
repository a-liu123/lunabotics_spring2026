import serial
import keyboard
import time

ser = serial.Serial('/dev/tty.usbmodem', 9600)  
time.sleep(2)

print("Controls: W A S D to move, X to stop")

while True:
    if keyboard.is_pressed('w'):
        ser.write(b'w')
    elif keyboard.is_pressed('s'):
        ser.write(b's')
    elif keyboard.is_pressed('a'):
        ser.write(b'a')
    elif keyboard.is_pressed('d'):
        ser.write(b'd')
    elif keyboard.is_pressed('x'):
        ser.write(b'x')
