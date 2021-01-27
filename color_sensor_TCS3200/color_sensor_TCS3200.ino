int out = 2;

int s0 = 3;

int s1 = 4;

int s2 = 5;

int s3 = 6;

int RedColor = 0;

int GreenColor = 0;

int BlueColor = 0;

void setup() {

Serial.begin(9600);

pinMode(s0, OUTPUT);

pinMode(s1, OUTPUT);

pinMode(s2, OUTPUT);

pinMode(s3, OUTPUT);

pinMode(out, INPUT);

digitalWrite(s0, HIGH);

digitalWrite(s1, HIGH);

}

void loop() {

ScanColor();

Serial.print(” Red: “);

Serial.print(RedColor);

Serial.print(” Green: “);

Serial.print(GreenColor);

Serial.print(” Blue : “);

Serial.print(BlueColor);

if (RedColor < BlueColor && RedColor < GreenColor) {

Serial.println(” – (Red Color)”);

}

else if (BlueColor < RedColor && BlueColor < GreenColor) {

Serial.println(” – (Blue Color)”);

}

else if (GreenColor < RedColor && GreenColor < BlueColor) {

Serial.println(” – (Green Color)”);

}

}

void ScanColor() {

digitalWrite(s2, LOW);

digitalWrite(s3, LOW);

RedColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

digitalWrite(s3, HIGH);

BlueColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

digitalWrite(s2, HIGH);

GreenColor = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}
