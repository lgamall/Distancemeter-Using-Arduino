//Youtube|Tech at Home
#include <LiquidCrystal_I2C.h>

int trig=7;
int echo=6;

// Define ultrasonic sensor pins
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Set the I2C address (check your module documentation)
#define I2C_ADDR 0x27

// Set the LCD dimensions (usually 16x2)
#define LCD_COLS 16
#define LCD_ROWS 2

long timeInMicro;

long distanceInCm;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

void setup() 
{
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(6,INPUT);
  lcd.begin(LCD_COLS, LCD_ROWS);  // Initialize the LCD with the specified columns and rows
  lcd.backlight();  // Turn on the backlight

  // pinMode(TRIGGER_PIN, OUTPUT);
  // pinMode(ECHO_PIN, INPUT);

  // lcd.setCursor(0, 0);
  // lcd.print("Distance:");
  // lcd.print("Temp & Humid:");

  // Serial.println("Distance measured on LCD.");
}

void loop()  
{
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 timeInMicro= pulseIn(echo,HIGH);

 distanceInCm = ((timeInMicro/29)/2);

 Serial.println(distanceInCm);
 delay(100);
   // Trigger the ultrasonic sensor
  // digitalWrite(TRIGGER_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIGGER_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIGGER_PIN, LOW);

  // Measure the duration of the pulse
  // long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  // int distance = duration * 0.034 / 2;

    // Update the LCD with the distance
  // lcd.setCursor(0, 1);
  // lcd.print("   ");
  // lcd.setCursor(0, 1);
  // lcd.print(distance);
  // lcd.print(" cm");
    // Print the distance to the Serial Monitor
  // Serial.print("Distance: ");
  // Seri/al.print(distance);
  // Serial.println(" cm");
 
}
