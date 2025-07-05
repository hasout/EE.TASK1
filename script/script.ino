const int buttonPin = 2;     // pushbutton pin
const int ledPin = 13;       // built-in LED pin

int ledState = LOW;          // LED status
int buttonState;             // current button reading
int lastButtonState = LOW;   // previous button reading

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;   // debounce time in milliseconds

void setup() {
  pinMode(buttonPin, INPUT);   // button as input
  pinMode(ledPin, OUTPUT);     // LED as output
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // reset the debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // toggle the LED only when the button is pressed
      if (buttonState == HIGH) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastButtonState = reading;
}
