#define b1 11
#define b2 10
#define b3 9
#define b4 8

#define reset 12

#define p1 7
#define p2 6
#define p3 5
#define p4 4

#define ready 3

int primed = 1;
int buttons[] = { b1, b2, b3, b4 };
int leds[] = { p1, p2, p3, p4 };

void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);

  pinMode(reset, INPUT);

  pinMode(p1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p1, OUTPUT);

  pinMode(ready, OUTPUT);

  digitalWrite(ready, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (primed) {
    int i;
    for (i = 0; i < 4; i++) {
      if (digitalRead(buttons[i]) == HIGH) {
        primed = 0;
        digitalWrite(leds[i], HIGH);
        digitalWrite(ready, LOW);
        break;
      }
    }
  } else {
    if (digitalRead(reset) == HIGH) {
      int i;
      primed = 1;
      digitalWrite(ready, HIGH);
      for (i = 0; i < 4; i++)
        digitalWrite(leds[i], LOW);
    }
  }
}