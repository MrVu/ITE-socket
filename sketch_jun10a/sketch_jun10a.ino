#include <ESP8266WiFi.h>
#include <SocketIoClient.h>
#include <string.h>



//khai bao bien
const char* ssid = "ahihi";
const char* password = "phongbui1997";
#define buttonPin 5
#define LED 4
const char *socketServer = "192.168.1.17";
const int socketPort = 4200;
SocketIoClient socket;


void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print("Connecting..");
  }
  Serial.print("Connected");
  socket.begin(socketServer, socketPort);
  socket.on("moveLeft", moveLeft);
  socket.on("moveRight", moveRight);
  socket.on("moveUp", moveUp);
  socket.on("moveDown", moveDown);
  socket.on("turnLeft", turnLeft);
  socket.on("turnRight", turnRight);
  socket.on("faceUp", faceUp);

}

void moveLeft (const char * payload, size_t length){
  for (int n=0; n<1; n++) {
    shortVibrate();
    delay(300);
    }
  }

void moveRight (const char * payload, size_t length){
  for (int n=0; n<2; n++) {
    shortVibrate();
    delay(300);
    }
  }

void moveUp (const char * payload, size_t length){
  for (int n=0; n<3; n++) {
    shortVibrate();
    delay(300);
    }
  }
  
void moveDown (const char * payload, size_t length){
  for (int n=0; n<4; n++) {
    shortVibrate();
    delay(300);
    }
  }
void turnLeft (const char * payload, size_t length){
  for (int n=0; n<1; n++) {
    longVibrate();
    delay(300);
    }
  
  for (int n=0; n<1; n++) {
    shortVibrate();
    delay(300);
    }
  }

  void turnRight (const char * payload, size_t length){
  for (int n=0; n<1; n++) {
    longVibrate();
    delay(300);
    }
  
  for (int n=0; n<2; n++) {
    shortVibrate();
    delay(300);
    }
  }
void faceUp (const char * payload, size_t length){
  for (int n=0; n<2; n++) {
    longVibrate();
    delay(300);
    }
  }
void shortVibrate(){
  digitalWrite(LED, HIGH);
  delay(200);
  analogWrite(LED, 0);
  }
  
void longVibrate () {
  digitalWrite(LED, HIGH);
  delay(700);
  analogWrite(LED, 0);
  }



void loop() {
 socket.loop();
}
