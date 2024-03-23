// my code if PIR detect any motion buzzer will on 
// by ultrasonic if distance is less than 100 red led will on else green led on


#define BUTTON_PIN 13
#define RED_LED_PIN 9
#define GREEN_LED_PIN 10
#define BUZZER_PIN 8
#define ULTRASONIC_TRIGGER_PIN 2
#define ULTRASONIC_ECHO_PIN 4
#define PIR_PIN 7

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ULTRASONIC_TRIGGER_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    digitalWrite(RED_LED_PIN, LOW); // Turn off the red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off the green LED
    noTone(BUZZER_PIN); // Turn off the sound
  }

  // Read distance from ultrasonic sensor
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
  long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;

  // Check if distance is less than 100cm
  if (distance < 100) 
  {
    digitalWrite(RED_LED_PIN, HIGH); // Turn on the red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off the green LED
    tone(BUZZER_PIN, 1000); // Turn on the sound
  } 
  else 
  {
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on the green LED
    digitalWrite(RED_LED_PIN, LOW); // Turn off the red LED
    noTone(BUZZER_PIN); // Turn off the sound
  }

  // Check PIR sensor
  if (digitalRead(PIR_PIN) == HIGH) 
  {
    tone(BUZZER_PIN, 1000);// Turn on the sound
  } 
  else 
  {
    noTone(BUZZER_PIN); // Turn off the sound
  }

  delay(1000); // Adjust delay as necessary
}
