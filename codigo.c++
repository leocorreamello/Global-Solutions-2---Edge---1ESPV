#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_topic = "node-red/greenflow/energy";
const char* mqtt_topic_amps = "node-red/greenflow/currentAmps";

WiFiClient espClient;
PubSubClient client(espClient);

#define LED_PIN 26
#define BUZZER_PIN 25
#define POTENTIOMETER_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);

int potValue = 0;
float potPercentage = 0;
float currentAmps = 0;
String energyLevel;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  setup_wifi();
  delay(2000);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client-805")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  potValue = analogRead(POTENTIOMETER_PIN);
  potPercentage = (potValue / 4095.0) * 100;
  currentAmps = potPercentage * 0.1; // Exemplo: valor de corrente proporcional ao percentual

  if (potPercentage < 33.3) {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    lcd.clear();
    lcd.print("Energia: Normal");
    lcd.setCursor(0, 1);
    lcd.print("Amps: ");
    lcd.print(currentAmps);
    energyLevel = "Normal";
    Serial.println("Gasto de Energia: Normal");
    Serial.print("Amps: ");
    Serial.println(currentAmps);
  } else if (potPercentage < 66.6) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    lcd.clear();
    lcd.print("Energia: Moderado");
    lcd.setCursor(0, 1);
    lcd.print("Amps: ");
    lcd.print(currentAmps);
    energyLevel = "Moderado";
    Serial.println("Gasto de Energia: Moderado");
    Serial.print("Amps: ");
    Serial.println(currentAmps);
  } else {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    lcd.clear();
    lcd.print("Energia: Alto");
    lcd.setCursor(0, 1);
    lcd.print("Amps: ");
    lcd.print(currentAmps);
    energyLevel = "Alto";
    Serial.println("Gasto de Energia: Alto");
    Serial.print("Amps: ");
    Serial.println(currentAmps);
  }

  if (client.connected()) {
    client.publish(mqtt_topic, energyLevel.c_str());
    client.publish(mqtt_topic_amps, String(currentAmps).c_str());
  }

  delay(3000);
  noTone(BUZZER_PIN);
}
