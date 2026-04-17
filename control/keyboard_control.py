import serial
import keyboard  # pip install keyboard for windows

ser = serial.Serial('COM8', 9600)  # change to your port (Linux: /dev/ttyUSB0) or open arduino IDE and check under Tools > Port

print("WASD to drive, X to stop, Q to quit")

while True:
    if keyboard.is_pressed('q'):
        break
    elif keyboard.is_pressed('w'):
        ser.write(b'w')
    elif keyboard.is_pressed('s'):
        ser.write(b's')
    elif keyboard.is_pressed('a'):
        ser.write(b'a')
    elif keyboard.is_pressed('d'):
        ser.write(b'd')
    else:
        ser.write(b'x')  # stop when no key held

ser.close()