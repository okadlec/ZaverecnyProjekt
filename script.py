import paho.mqtt.client as mqtt #import the client1
import time
import json
import pymysql
from datetime import datetime

############                              
def on_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    presentime = datetime.now()
    data = {"topic": message.topic,"message": str(message.payload.decode("utf-8")),"time":presentime.strftime('%Y-%m-%d-%H-%M-%S')}
    zprava = str(message.payload.decode("utf-8"))
    cas = presentime.strftime('%Y-%m-%d-%H-%M-%S')
   # json_file = open('personal.json', 'a+')
   # json_file.write(str(data)+ '\n')
    print(data)
  #  json_file.close()
    global x
    connection = pymysql.connect(host='localhost',
                      user='root',
                      password='',
                      db='fingerprint')
    cursor = connection.cursor()
    query = "INSERT INTO data(name,date) VALUES('"+zprava+"','" + cas+"');"
    print(query)
    cursor.execute(query)
    connection.commit()
########################################
broker_address="broker.mqtt-dashboard.com"
#broker_address="iot.eclipse.org"
print("creating new instance")
client = mqtt.Client("P1") #create new instance
client.on_message=on_message #attach function to callback
print("connecting to broker")
client.connect(broker_address) #connect to broker
client.loop_start() #start the loop
print("Subscribing to topic","andrej")
client.subscribe("andrej")
print("Publishing message to topic","andrej")
client.publish("andrej","Python")
time.sleep(1500) # wait
