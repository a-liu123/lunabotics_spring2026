import serial
import keyboard

ser = serial.Serial('/dev/tty.***', 9600) 


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
