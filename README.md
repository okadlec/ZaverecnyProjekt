# ZaverecnyProjekt
<br>Září - Obstarání součástek, začít, pořešit zapojení modulu DY50 s esp8266
<br>Říjen - Zapojení obvodu, softwarová stránka věci
<br>Listopad - Začít s dokumentací, Dokončení softwaru
<br>Prosinec - Vylepšování projektu
<br>Leden - Dokončení projektu a dokumentace
<link>https://www.youtube.com/watch?v=qXjjVqQwLyY</link>
<br>https://randomnerdtutorials.com/fingerprint-sensor-module-with-arduino/

<br>Cílem je vytvořit zámek do dveří ovládaný pomocí čtečky otisku prstů. Logy se budou nahrávat na server a ukládat do souboru JSON.

<br>Schéma zapojení čtečky:
https://hackster.imgix.net/uploads/attachments/687481/fingerprint_bb_H4k0IdYAE7.png
- <code>
- #include <ESP8266WiFi.h>        // Include the Wi-Fi library
- #include <PubSubClient.h>
-
- const char* ssid     = "ESPNet";         // The SSID (name) of the Wi-Fi network you want to connect to
- const char* password = "";     // The password of the Wi-Fi network
-
- void setup() {
 - Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  -delay(1000);
 - Serial.println('\n');
  -
-  WiFi.begin(ssid, password);             // Connect to the network
-  Serial.print("Connecting to ");
-  Serial.print(ssid); Serial.println(" ...");
-
 - int i = 0;
 - while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
  -  delay(1000);
  -  Serial.print(++i); Serial.print(' ');
  - }

 - Serial.println('\n');
  -Serial.println("Connection established!");  
 - Serial.print("IP address:\t");
 - Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
- }

- void loop() { }</code>
- 
- platform = espressif8266
- board = esp12e
- framework = arduino
-
- pio device monitor -b 115200
