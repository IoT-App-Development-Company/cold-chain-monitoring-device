#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Pin Definitions
#define DHTPIN 25          // DHT sensor data pin
#define DHTTYPE DHT22      // Change to DHT11 if using that model
#define BUZZER_PIN 15      // Passive buzzer signal pin
#define LED_PIN 14         // LED pin
#define OLED_SDA 21        // OLED SDA
#define OLED_SCL 22        // OLED SCL

// Threshold
#define TEMP_THRESHOLD 8.0  // Max allowed temp for cold chain

// OLED Display setup
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  // Initialize peripherals
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start DHT sensor
  dht.begin();

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, OLED_SDA, OLED_SCL)) {
    Serial.println(F("OLED init failed"));
    while (true); // Stop if OLED fails
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Cold Chain Monitor"));
  display.display();
  delay(2000);
}

void loop() {
  // Read from DHT sensor
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check for read failure
  if (isnan(temp) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Sensor Error");
    display.display();
    delay(2000);
    return;
  }

  bool alert = temp > TEMP_THRESHOLD;

  // Show on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Cold Chain Monitor"));

  display.setCursor(0, 14);
  display.setTextSize(1);
  display.print(F("Temp: "));
  display.print(temp, 1);
  display.println(F(" C"));

  display.print(F("Humidity: "));
  display.print(humidity, 1);
  display.println(F(" %"));

  display.print(F("Status: "));
  display.println(alert ? "ALERT" : "NORMAL");

  display.display();

  // Serial Output
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" % --> ");
  Serial.println(alert ? "ALERT" : "NORMAL");

  // Alert logic
  if (alert) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);  // 1kHz alert sound
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(2000);
}
