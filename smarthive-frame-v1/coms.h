#define COMS_H 1

#define SEND_UDP "10.4.0.90"

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
  WiFi.hostname(HOSTNAME);
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


void printUDP(double s);
void printUDP(float s);
void printUDP(char s);
void printUDP(int s);
void printUDP(String s);

void printUDP(double s)
{
  printUDP(String(s));
}

void printUDP(float s)
{
  printUDP(String(s));
}

void printUDP(char s)
{
  printUDP(String(s));
}

void printUDP(int s)
{
  printUDP(String(s));
}

void printUDP(String s)
{
  char tx[100];
  s.toCharArray(tx, s.length()+1);
  Udp.beginPacket(SEND_UDP, localPort);
  //Udp.beginPacket(Udp.remoteIP(), localPort);
  
  Udp.write(tx);
  Udp.endPacket();
}
