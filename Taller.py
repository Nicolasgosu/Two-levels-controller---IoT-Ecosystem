import serial
import thingspeak


puerto_serial = serial.Serial('COM6', 9600)  
canal = thingspeak.Channel(id='[replace by id]', api_key='[Replace by key]')

try:
    while True:
        
        linea = puerto_serial.readline().decode().strip()
    
        if linea:
            canal.update({1: linea})
        print(linea)

finally:
    
    puerto_serial.close()
