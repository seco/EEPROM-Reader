/********************************************************************************************

                       EEPROM-Reader v1.0

                       Copyright (c) 2017 Helmut Stult (schinfo)

 ********************************************************************************************/

#include <EEPROM.h>
#include <ESP8266WiFi.h>

// sizeBytes being the number of bytes you want to use.
// It's defined with "#define sizeBytes" 
// Size can be anywhere between 4 and 4096 bytes (Default for ESP8266_deauther = 4096)
#define sizeBytes 4096

// change it for more or less listBytes (Default for maximum and/or ESP8266_deauther = 4096)
// normaly it's the same as sizeBytes
#define listBytes 4096

// change it for higher startByte (Default = 0)
#define startByte 0

unsigned long ok = 0;
unsigned long nok = 0;

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(sizeBytes);

  delay(100);

  Serial.println("**********************************************************************************************");
  Serial.println("");
  Serial.print("             EEPROM-sice defined with ");
  Serial.print(sizeBytes);
  Serial.print(" bytes and list from byte: ");
  Serial.print(startByte);
  Serial.print(" - ");
  Serial.println(listBytes - 1);
  Serial.println("");
  Serial.println("**********************************************************************************************");
  Serial.println("");
  Serial.println("             testing EEPROM for written bytes");
  Serial.println("");
  Serial.println("**********************************************************************************************");
  Serial.println("");

  String content;
  String con;
  int x = 0;
  Serial.println("---------------------------------------------------------------------------------------------|");
  Serial.println("                   |  0000000000111111  |                                                    |");
  Serial.println("                   |  0123456789012345  |  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15   |");
  Serial.println("---------------------------------------------------------------------------------------------|");

  for (int i = startByte; i < listBytes; i = i + 16) {
    for (int x = i; x < i + 16; ++x) {
      con = char(EEPROM.read(x));
      //                                 Char
      //----------------------------------------
      if (EEPROM.read(x) ==   0 ||   //  (nul)
          EEPROM.read(x) ==   1 ||   //  (soh)
          EEPROM.read(x) ==   2 ||   //  (stx)
          EEPROM.read(x) ==   3 ||   //  (ext)
          EEPROM.read(x) ==   4 ||   //  (eot)
          EEPROM.read(x) ==   5 ||   //  (enq)
          EEPROM.read(x) ==   6 ||   //  (ack)
          EEPROM.read(x) ==   7 ||   //  (bel)
          EEPROM.read(x) ==   8 ||   //  (bs)
          EEPROM.read(x) ==   9 ||   //  (ht)
          EEPROM.read(x) ==  10 ||   //  (nl)
          EEPROM.read(x) ==  11 ||   //  (vt)
          EEPROM.read(x) ==  12 ||   //  (np)
          EEPROM.read(x) ==  13 ||   //  (cr)
          EEPROM.read(x) ==  14 ||   //  (so)
          EEPROM.read(x) ==  15 ||   //  (si)
          EEPROM.read(x) ==  16 ||   //  (dle)
          EEPROM.read(x) ==  17 ||   //  (dc1)
          EEPROM.read(x) ==  18 ||   //  (dc2)
          EEPROM.read(x) ==  19 ||   //  (dc3)
          EEPROM.read(x) ==  20 ||   //  (dc4)
          EEPROM.read(x) ==  21 ||   //  (nak)
          EEPROM.read(x) ==  22 ||   //  (syn)
          EEPROM.read(x) ==  23 ||   //  (etb)
          EEPROM.read(x) ==  24 ||   //  (can)
          EEPROM.read(x) ==  25 ||   //  (em)
          EEPROM.read(x) ==  26 ||   //  (sub)
          EEPROM.read(x) ==  27 ||   //  (esc)
          EEPROM.read(x) ==  28 ||   //  (fs)
          EEPROM.read(x) ==  29 ||   //  (gs)
          EEPROM.read(x) ==  30 ||   //  (rs)
          EEPROM.read(x) ==  31 ||   //  (us)
          EEPROM.read(x) == 127 ) {  //  (del)
        con = " ";
      }
      content += con;
    }
    Serial.printf("Byte: %4d", i);
    Serial.printf(" - ");
    Serial.printf("%4d", i + 15);
    Serial.print("  |  ");
    Serial.print(content);
    Serial.print("  |  ");
    content = "";

    for (int y = i; y < i + 16; ++y) {
      Serial.printf("%02x ", EEPROM.read(y));
    }
    Serial.println("  |");
  }
  Serial.println("---------------------------------------------------------------------------------------------|");

  Serial.println("");
  Serial.println("**********************************************************************************************");
  Serial.println("");



  for (int i = startByte; i < listBytes; ++i) {
    if (EEPROM.read(i) == 255) {
      ++ok;
    } else {
      ++nok;
    }
  }

  Serial.printf("               empty bytes: %6d\r\n", ok);
  Serial.printf("           not empty bytes: %6d\r\n", nok);
  Serial.println("");
  Serial.println("**********************************************************************************************");

  delay(100);

  Serial.println("");
  if (nok == 0) {
    Serial.println("             EEPROM empty");
  } else
    Serial.println("             EEPROM not empty");

  Serial.println("");
  Serial.println("**********************************************************************************************");
  Serial.println("");
  Serial.println("             Ready - You can remove your ESP8266 / LoLin");
  Serial.println("");
  Serial.println("**********************************************************************************************");
}

void loop()
{
}
