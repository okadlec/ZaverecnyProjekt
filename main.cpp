#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
LiquidCrystal_I2C lcd(0x27,16,2); 
const char* ssid = "ESPNet";
const char* password = "";
const char* server = "broker.mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);

  for (int i=0;i<length;i++) {
    lcd.print((char)payload[i]);
  }
}




void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic","hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);

  client.setServer(server, 1883);
  client.setCallback(callback);
  setup_wifi();
  // Allow the hardware to sort itself out
  delay(1500);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

// set the LCD address to 0x27 for a 16 chars and 2 line display
/*
void setup()
{

  lcd.setCursor(0,0);
  lcd.print("Michal Prokes");
}*/
