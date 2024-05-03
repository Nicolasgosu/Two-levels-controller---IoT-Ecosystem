import serial
import thingspeak


puerto_serial = serial.Serial('COM6', 9600)  #se inicializa comunicacion serial con el arduino
canal = thingspeak.Channel(id='[replace by id]', api_key='[Replace by key]') #se inicializa la conexion con el canal de ThingSpeak 

try:
    while True:
        
        linea = puerto_serial.readline().decode().strip() #se lee la comunicacion serial
    
        if linea:
            canal.update({1: linea}) #en caso de una lectura exitosa se actualiza el canal de ThingSpeak
        print(linea)

finally:
    
    puerto_serial.close() #se cierra la comunicacion
