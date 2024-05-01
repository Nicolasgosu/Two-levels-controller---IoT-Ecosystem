import serial
import thingspeak


puerto_serial = serial.Serial('COM6', 9600)  
canal = thingspeak.Channel(id='2528886', api_key='WYQWLYTSN7O8O5RL')

try:
    while True:
        
        linea = puerto_serial.readline().decode().strip()
    
        if linea:
            canal.update({1: linea})
        print(linea)

finally:
    
    puerto_serial.close()
