#define COMS_H 1

#define HOSTNAME "beenet-frame-0"

#ifndef STASSID
//#define STASSID "ankiNet-2.4ghz"
#define STASSID "BeeNet"
#define STAPSK  "smarthive1234"
#endif

//int status = WL_IDLE_STATUS;     // the WiFi radio's status


#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

unsigned int localPort = 4257;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged\r\n";       // a string to send back

WiFiUDP Udp;

void coms_setup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);


}
