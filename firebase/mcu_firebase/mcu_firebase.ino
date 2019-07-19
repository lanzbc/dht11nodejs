#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "lanzbcdht11.firebaseio.com" //Thay bằng địa chỉ firebase của bạn
#define FIREBASE_AUTH "ZrSgKWRvZ6Qn9GBgC9EdkvDnIy6JZ1pOvpt8mzJ9"   //Không dùng xác thực nên không đổi
#define WIFI_SSID "Diamond Electric VietNam 2.4GHz"   //Thay wifi và mật khẩu
#define WIFI_PASSWORD "devietnam@2019#"

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  Firebase.setFloat("led", 0);

  int i = 0;
  for (i = 0; i < 10; i++) {
    Firebase.setFloat("led", i);
    // handle error
    if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());
      return;
    }
    Serial.println(i);
    delay(200);
  }
}
