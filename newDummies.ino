//global variable

long alti = 0, 
	temp = 0,
	humi = 0,
	pres = 0,
	windDir = 0,
	windVelo = 0,
	co2 = 0;

 float  latitude = -6.914744, longitude = 107.609810;

float increment = 0.001;

bool start , img;

void setup(){
	Serial.begin(57600);
}

void loop(){

	if (Serial.available() > 0) {
		char command = (char)Serial.read();

		if (command == '1'){
			start = true;
		} else if (command == '0') {
			start = false;
		} else if (command == '2') {
      img = true;
		}
	}
  

	if (start) {
		alti = alti + random(0,10);
		temp = random(-10,50);
		humi = random(0,100);
		pres = random(0,300);
		windDir = random(0,360);
		windVelo = random(0,30);
		latitude = latitude + increment;
		longitude = longitude + increment;
		co2 = random(0,5000);

    Serial.print("OK");
    Serial.print(",");
		Serial.print(alti );
    Serial.print(",");
		Serial.print(temp );
    Serial.print(",");
		Serial.print(humi );
    Serial.print(",");
		Serial.print(pres );
    Serial.print(",");
		Serial.print(windDir );
    Serial.print(",");
		Serial.print(windVelo );
    Serial.print(",");
		Serial.print(latitude,9);
    Serial.print(",");
		Serial.print(longitude,9);
    Serial.print(",");
		Serial.print(co2 );
		Serial.println();
	}

 if (img) {
  Serial.print("FF D8 FF E0 01 14 A4 64 94 60 11 10 00 00 0A FF DB 04 30 86 67 65 87 77 99 8A C1 4D CB BC 19 12 13 F1 41 D1 A1 F1 E1 D1 A1 C1 C2 02 42 E2 72 02 22 C2 31 C1 C2 83 72 92 C3 03 13 43 43 41 F2 73 93 D3 83 23 C2 E3 33 43 2F FD B0 43 19 99 CB C1 8D D1 83 22 11 C2 13 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 23 2F FC 40 1F 00 15 11 11 11 00 00 00 00 12 34 56 78 9A BF FC 40 B5 10 02 13 32 43 55 44 00 17 D1 23 04 11 51 22 13 14 16 13 51 61 72 27 11 43 28 19 1A 18 23 42 B1 C1 15 52 D1 F0 24 33 62 72 82 9A 16 17 18 19 1A 25 26 27 28 29 2A 34 35 36 37 38 39 3A 43 44 45 46 47 48 49 4A 53 54 55 56 57 58 59 5A 63 64 65 66 67 68 69 6A 73 74 75 76 77 78 79 7A 83 84 85 86 87 88 89 8A 92 93 94 95 96 97 98 99 9A A2 A3 A4 A5 A6 A7 A8 A9 AA B2 B3 B4 B5 B6 B7 B8 B9 BA C2 C3 C4 C5 C6 C7 C8 C9 CA D2 D3 D4 D5 D6 D7 D8 D9 DA E1 E2 E3 E4 E5 E6 E7 E8 E9 EA F1 F2 F3 F4 F5 F6 F7 F8 F9 FA FF C4 01 F1 03 11 11 11 11 10 00 00 01 23 45 67 89 AB FF C4 0B 51 10 21 24 43 47 54 40 12 77 01 23 11 45 21 31 61 24 15 17 61 71 13 22 32 81 81 44 29 1A 1B 1C 19 23 33 52 F0 15 62 72 D1 A1 62 43 4E 12 5F 11 71 81 91 A2 62 72 82 92 A3 53 63 73 83 93 A4 34 44 54 64 74 84 94 A5 35 45 55 65 75 85 95 A6 36 46 56 66 76 86 96 A7 37 47 57 67 77 87 97 A8 28 38 48 58 68 78 88 98 A9 29 39 49 59 69 79 89 99 AA 2A 3A 4A 5A 6A 7A 8A 9A AB 2B 3B 4B 5B 6B 7B 8B 9B AC 2C 3C 4C 5C 6C 7C 8C 9C AD 2D 3D 4D 5D 6D 7D 8D 9D AE 2E ");
  img = false;
 }
	delay(100);
}
