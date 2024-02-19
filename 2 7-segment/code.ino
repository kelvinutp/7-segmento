
//digital writes
//begins with a 7 instead of a 0, because when doing the for cycle, whenever a blank space is transformed to a cero
//it will result in turning on LED A at unwanted times (number 1 and 4)
#define a 7
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
//leds related to number 0...9
const int leds[][7]={
  {a,b,c,d,e,f},    //0
  {b,c},            //1
  {a,b,d,e,g},      //2
  {a,b,c,d,g},      //3
  {b,c,f,g},        //4
  {a,c,d,f,g},      //5
  {a,c,d,e,f,g},    //6
  {a,b,c},          //7
  {a,b,c,d,e,f,g},  //8
  {a,b,c,d,f,g}     //9
};
//arduino pins connected to leds
uint8_t dec_leds[]={0,3,4,5,6,7,8,2}; //leds for the tens places 
uint8_t uni_leds[]={0,A0,A1,A2,A3,A4,A5,13}; //leds for the ones places 

void setup() {
  // put your setup code here, to run once:
  for (int z=1; z<14;z++){//decenas
    pinMode(z, OUTPUT);
    digitalWrite(z, LOW);
  }
  for (int i = 0; i < 8; i++) { //unidades
    pinMode(uni_leds[i], OUTPUT);
    digitalWrite(uni_leds[i], LOW);
  }
  //testing LEDs
  for (int z=1;z<14;z++){
    digitalWrite(z, HIGH);
    delay(50);
    digitalWrite(z, LOW);
  }
  for (int z = 0; z < 7; z++) {
    digitalWrite(uni_leds[z], HIGH);
    delay(50);
    digitalWrite(uni_leds[z], LOW);
  }
  Serial.begin(9600);

  Serial.println(a);
  Serial.println(b);
}

void loop() {
  // put your main code here, to run repeatedly:
  //show numbers 0-99
  for (int z=0;z<100;z++){
    Serial.print(z);
    Serial.print("; decenas: ");
    int dec=int(z/10);
    Serial.print(dec);
    decenas(dec);
    Serial.print("; unidades: ");
    int aux=(z-int(z/10)*10);
    Serial.print(aux);
    unidades(aux);
    delay(500);
    Serial.println();
  }
}

void decenas(int y){
  for (auto x:dec_leds){
    digitalWrite(x, LOW);
  }
  for (auto x:leds[y]){
    digitalWrite(dec_leds[x], HIGH);
  }
}

void unidades(int y){
  for (auto x:uni_leds){
    digitalWrite(x, LOW);
  }
  for (auto x:leds[y]){
    digitalWrite(uni_leds[x], HIGH);
  }
}
