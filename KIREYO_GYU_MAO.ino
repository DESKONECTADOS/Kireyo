//MOTORES
const int pwma = 3;
const int ML_A = 5;
const int ML_B = 4;
const int pwmb = 9;
const int MR_A = 8;
const int MR_B = 7;

//SENSORES
const int fder = 10;
const int fizq = 12;
const int fcent = 11;
const int der = A4;
const int izq = A5;
const int lin1 = 13;
const int REMOTE = 0;

//SENSORES LECTURAS
int sder;
int sizq;
int sfder;
int sfizq;
int sensline;
int lineval;
int SensVal;
int ON = 1;



void setup() {
  pinMode(pwma, OUTPUT);
  pinMode(ML_A, OUTPUT);
  pinMode(ML_B, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(MR_A, OUTPUT);
  pinMode(MR_B, OUTPUT);
  pinMode(REMOTE, INPUT);
  pinMode(fcent, INPUT);
  pinMode(fder, INPUT);
  pinMode(fizq, INPUT);
  pinMode(der, INPUT);
  pinMode(izq, INPUT);
  pinMode(lin1, INPUT);

  Serial.begin(9600);
}



void loop() {

  while (digitalRead(REMOTE) == 1) {

    lineval = digitalRead(lin1);
    SensVal = SensValor();
    Serial.println(SensVal);

    switch (lineval) {
      case 0:
        switch (SensVal) {

          case 0:
            adelante(60);
            Serial.println("Adelante");
            delay(50);
            break;

          case 1:
            derecha(250);
            Serial.println("Derecha");
            delay(50);
            break;
          case 2:
            derecha(200);
            //analogWrite(pwma, 190);
            //analogWrite(pwmb, 190);
            Serial.println("FDerecha");
            delay(50);
            break;

          case 3:
            derecha(220);
            Serial.println("der 23");
            delay(50);
            break;

          case 4:
            adelante(250);
            Serial.println("Centro");
            delay(50);
            break;

          case 6:
            derecha(220);
            Serial.println("Cen y der");
            delay(50);
            break;

          case 8:  //si esta a izquierda
            izquierda(200);
            Serial.println("Izquierda");
            delay(50);
            break;

          case 12:
            izquierda(220);
            Serial.println("Cent y Izquierda");
            delay(50);
            break;

            case 18:
            adelante(250);
            Serial.println("Todos adelante");
            delay(50);
            break;

            case 24:
            izquierda(200);
            Serial.println(250);
            Serial.println("Izquierda");
            delay(50);
            break;


        }
        break;

      case 1:
        atras(255);
        Serial.println("Linea 1");
        delay(200);
        derecha(200);
        delay(200);

        break;
    }
  }
  detenido(200);
}


void adelante(int velocity) {
  analogWrite(ML_A, 1);
  digitalWrite(ML_B, 0);
  analogWrite(MR_A, 1);
  digitalWrite(MR_B, 0);

  analogWrite(pwma, velocity);
  analogWrite(pwmb, velocity);
}

void derecha(int velocity) {
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 1);
  digitalWrite(MR_A, 1);
  digitalWrite(MR_B, 0);
  analogWrite(pwma, velocity);
  analogWrite(pwmb, velocity);
}

void izquierda(int velocity) {
  digitalWrite(ML_A, 1);
  digitalWrite(ML_B, 0);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 1);
  analogWrite(pwma, velocity);
  analogWrite(pwmb, velocity);
}

void atras(int velocity) {
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 1);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 1);
  analogWrite(pwma, velocity);
  analogWrite(pwmb, velocity);
}

void detenido(int velocity) {
  digitalWrite(ML_A, 0);
  digitalWrite(ML_B, 0);
  digitalWrite(MR_A, 0);
  digitalWrite(MR_B, 0);
  analogWrite(pwma, velocity);
  analogWrite(pwmb, velocity);
}


byte SensValor() {
  byte sder = !digitalRead(der);
  byte sfder = !digitalRead(fder) * 2;
  byte sfcen = !digitalRead(fcent) * 4;
  byte sfizq = !digitalRead(fizq) * 8;
  byte sizq = !digitalRead(izq) * 16;

  byte SumaTotal = sizq + sfizq + sfder + sder + sfcen;
  return SumaTotal;
}

/*int linevalue(){
  int sensline =! digitalRead(lin1);
  int suma = sensline;
  return suma;
}*/
