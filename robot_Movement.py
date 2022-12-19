import keyboard
import serial.tools.list_ports_windows
import serial
import time


ports = serial.tools.list_ports_windows.comports()
serialInst = serial.Serial()

portsList = []

for onePort in ports:
    portsList.append(str(onePort))
    print(str(onePort))

val = input("Select Ports : COM")

for t in range(0, len(portsList)):
    if portsList[t].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portVar)

serialInst.baudrate = 115200
serialInst.port = portVar
serialInst.timeout = 1
serialInst.open()
print(serialInst)
while True:
    if keyboard.is_pressed('w'):
        x='w'
        serialInst.write(x.encode())
        # serialInst.write(bytes(b'%r' % x))
        print(x)
    elif keyboard.is_pressed('a'):
        x='a'
        serialInst.write(x.encode())
        # serialInst.write(bytes(b'%r' % x))
        print(x)
    elif keyboard.is_pressed('d'):
        x='d'
        serialInst.write(x.encode())
        # serialInst.write(bytes(b'%r' % x))
        print(x)
    elif keyboard.is_pressed('s'):
        x='s'
        serialInst.write(x.encode())
        # serialInst.write(bytes(b'%r' % x))
        print(x)
    # time.sleep(0.1)
    # print(serialInst.readline().decode('ascii'))
