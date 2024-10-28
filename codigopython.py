import serial
def readserial(comport, baudrate):
ser = serial.Serial(comport, baudrate, timeout=0.1)
while True:
  data = ser.readline().decode().strip()
if data:
  print(data)
with open("incendio.txt", "a") as myfile:
  myfile.write(data)
  myfile.close()
if __name__ == '__main__':
  readserial('COMX', 9600)
