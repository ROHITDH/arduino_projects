
#include <ESP8266WiFi.h>

const char* ssid     = "asus zenphine max pro m1";
const char* password = "cfa4zm638z";

WiFiServer server(80);


String header; 

int app1 = D1;
int app2 = D2; 
int app3 = D3; 
int app4 = D4; 
int app5 = D5; 
int app6 = D6; 


String app1state = "off";
String app2state = "off";
String app3state = "off";
String app4state = "off";
String app5state = "off";
String app6state = "off";


void setup() {
  Serial.begin(115200);

  pinMode(app1, OUTPUT);
  pinMode(app2, OUTPUT);
  pinMode(app3, OUTPUT);
  pinMode(app4, OUTPUT);
  pinMode(app5, OUTPUT);
  pinMode(app6, OUTPUT);

  digitalWrite(app1, LOW);
  digitalWrite(app2, LOW);
  digitalWrite(app3, LOW);
  digitalWrite(app4, LOW);
  digitalWrite(app5, LOW);
  digitalWrite(app6, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   

  if (client) {                             
    String currentLine = "";                
    while (client.connected()) {           
      if (client.available()) {             
        char c = client.read();          
        Serial.write(c);                
        header += c;
        if (c == '\n') {         
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            if (header.indexOf("GET /app1/on") >= 0) {
              Serial.println("App 1 on");
              app1state = "on";
              digitalWrite(app1, HIGH);
            } else if (header.indexOf("GET /app1/off") >= 0) {
              Serial.println("App 1 off");
              app1state = "off";
              digitalWrite(app1, LOW);
            } else if (header.indexOf("GET /app2/on") >= 0) {
              Serial.println("App 2 on");
              app2state = "on";
              digitalWrite(app2, HIGH);
            } else if (header.indexOf("GET /app2/off") >= 0) {
              Serial.println("App 2 off");
              app2state = "off";
              digitalWrite(app2, LOW);
            }
           else if (header.indexOf("GET /app3/on") >= 0) {
              Serial.println("App 3 on");
              app3state = "on";
              digitalWrite(app3, HIGH);
            } else if (header.indexOf("GET /app3/off") >= 0) {
              Serial.println("App 3 off");
              app3state = "off";
              digitalWrite(app3, LOW);
            } else if (header.indexOf("GET /app4/on") >= 0) {
              Serial.println("App 4 on");
              app4state = "on";
              digitalWrite(app4, HIGH);
            } else if (header.indexOf("GET /app4/off") >= 0) {
              Serial.println("App 4 off");
              app4state = "off";
              digitalWrite(app4, LOW);
            }

           else if (header.indexOf("GET /app5/on") >= 0) {
              Serial.println("App 5 on");
              app5state = "on";
              digitalWrite(app5, HIGH);
            } else if (header.indexOf("GET /app5/off") >= 0) {
              Serial.println("App 5 off");
              app5state = "off";
              digitalWrite(app5, LOW);
            } else if (header.indexOf("GET /app6/on") >= 0) {
              Serial.println("App 6 on");
              app6state = "on";
              digitalWrite(app6, HIGH);
            } else if (header.indexOf("GET /app6/off") >= 0) {
              Serial.println("App 6 off");
              app6state = "off";
              digitalWrite(app6, LOW);
            }
       
       
       
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            client.println("<body><h1>ESP8266 Web Server</h1>");
            
            client.println("<p>app1 - State " + app1state + "</p>");
            if (app1state == "off") {
              client.println("<p><a href=\"/app1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app1/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            client.println("<p>app2 - State " + app2state + "</p>");
            if (app2state == "off") {
              client.println("<p><a href=\"/app2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>app3 - State " + app3state + "</p>");
            if (app3state == "off") {
              client.println("<p><a href=\"/app3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app3/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            client.println("<p>app4 - State " + app4state + "</p>");
            if (app4state == "off") {
              client.println("<p><a href=\"/app4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            client.println("<p>app5 - State " + app5state + "</p>");
            if (app5state == "off") {
              client.println("<p><a href=\"/app5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            client.println("<p>app6 - State " + app6state + "</p>");
            if (app6state == "off") {
              client.println("<p><a href=\"/app6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/app6/off\"><button class=\"button button2\">OFF</button></a></p>");
            }



            
            client.println("</body></html>");
            
            client.println();
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
