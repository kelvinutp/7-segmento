int a = 3;
const int d[3] = {B0110000, B1101101, B1111001};
int e;
int f;
void setup() {
  Serial.begin(9600);
  for (a = 3; a < 11; a++)
  {
    pinMode(a, OUTPUT);
  }
}

void loop() {
  delay(500);
  e = analogRead(A0);
  if (e > 100)
  {
    if (f < 3)
    {
      f = f + 1;
      salida(f);
    }
    else
    {
      f = 1;
      salida(f);

    }
  }
  Serial.print(bitRead(d[1], 0));
  //Serial.println(bitRead(d[1], 1));
}
void salida(int g)
{
  digitalWrite(3, bitRead(d[g], 0));
  digitalWrite(4, bitRead(d[g], 1));
  digitalWrite(5, bitRead(d[g], 2));
  digitalWrite(6, bitRead(d[g], 3));
  digitalWrite(7, bitRead(d[g], 4));
  digitalWrite(8, bitRead(d[g], 5));
  digitalWrite(9, bitRead(d[g], 6));
}

