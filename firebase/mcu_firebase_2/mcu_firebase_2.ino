//"Diamond Electric VietNam 2.4GHz","evietnam@2019#"
#include <FirebaseArduino.h>

#include <DHT.h>

#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "lanzbc.firebaseio.com"

#define WIFI_SSID "Diamond Electric VietNam 2.4GHz" // Thay đổi tên wifi của bạn

#define WIFI_PASSWORD "devietnam@2019#" // Thay đổi password wifi của bạn

#define DHTPIN D3    // Chân dữ liệu của DHT 11 , với NodeMCU chân D5 GPIO là 14

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);

  delay(1000);

  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Dang ket noi");

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

  }

  dht.begin();

  Serial.println ("");

  Serial.println ("Da ket noi WiFi!");

  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST);

}

void loop() {

  float h = dht.readHumidity();
  Serial.println(h);

float t = dht.readTemperature();  // Đọc nhiệt độ theo độ C

  if (isnan(h) || isnan(t)) {

    Serial.println("Failed to read from DHT sensor!");

    return;

  }

  Serial.print("Nhiet do:");

  Serial.print(t);

  Serial.print("*C  ");

  Serial.print("Do am: ");

  Serial.print(h);

  Serial.println("%  ");

  Firebase.setFloat ("Temp", t);

  Firebase.setFloat ("Hum", h);

  delay(200);

}
