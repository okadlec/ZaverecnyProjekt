# ZaverecnyProjekt
<br>Září - Obstarání součástek, začít, pořešit zapojení modulu DY50 s esp8266
<br>Říjen - Zapojení obvodu, softwarová stránka věci
<br>Listopad - Začít s dokumentací, Dokončení softwaru
<br>Prosinec - Vylepšování projektu
<br>Leden - Dokončení projektu a dokumentace
<link>https://www.youtube.com/watch?v=qXjjVqQwLyY</link>
<br>https://randomnerdtutorials.com/fingerprint-sensor-module-with-arduino/

<br>Cílem je vytvořit zámek do dveří ovládaný pomocí čtečky otisku prstů. Logy se budou nahrávat na server a ukládat do souboru JSON.
-[ ]Upravit napětí známku z 5V do 12V
<br>Schéma zapojení čtečky:
https://hackster.imgix.net/uploads/attachments/687481/fingerprint_bb_H4k0IdYAE7.png
- Compiler - ESP8266 Board -> Wemos D1 R2
- SoftwareSerial mySerial(4,5);
- Rx -> 3
- Tx -> 4
- platform = espressif8266
- board = esp12e
- framework = arduino
- LED -> 9
- pio device monitor -b 115200
- https://www.instructables.com/id/NodeMCU-MQTT-Basic-Example/
- https://github.com/adibbazli/fingerprint-attendance
