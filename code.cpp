// ROBÔ 6 BATERIA  9 //25900

// Portas driver motor
//Motor A
#define INA 3
#define IN1 2
#define IN2 4
//Motor B
#define INB 6
#define IN3 5
#define IN4 7

//Sensores
#define s1 A5
#define s2 A4
#define s3 A3
#define s4 A2
#define s5 A1
#define s6 A0

// Portas led rgb
#define PINLEDR 10
#define PINLEDG 9
#define PINLEDB 11

#define SPEED0 255         // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 1 1 0 0) 
#define SPEED1 210        // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 1 1 1 0) 

#define SPEED2 172          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 0 0) 
#define SPEED3 100         // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 1 0)  
#define SPEED4 80          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 1 1) 

#define SPEED5 0           // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 1 0) 
#define SPEED6 0           // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 1 1) 
#define SPEED7 120          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 0 1) 

#define SPEED8 160          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 1 1) 

//Valor referencia para faixa branca
#define cor 700

//Valor Tempo
#define RUNTIME 27500

void setup() {
  //Motor A - DIREITO
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(INA, OUTPUT);
  //Motor B - ESQUERDO
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(INB, OUTPUT);
}

void motorOption(int option, int SpeedLeft, int SpeedRigh) {
  switch (option) {

    //FRENTE
    case 8:
      //Motor A // ESQUERDO
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(INA , SpeedLeft);
      //Motor B // DIREITO
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(INB, SpeedRigh);
      break;

    //DIREITA
    case 6:

      //Motor A  // ESQUERDO
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(INA, SpeedLeft);
      //Motor B  // DIREITO
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(INB, SpeedRigh);
      break;

    //ESQUERDA
    case 4:

      //Motor A  // ESQUERDO
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(INA, SpeedLeft);
      //Motor B  // DIREITO
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(INB, SpeedRigh);
      break;
  }
}

void loop() {
  int s[5];
  bool flag = true;
  long currentTime = millis();

  while (flag) {
    flag = motorStop(RUNTIME, currentTime);

    s[0] = analogRead(s1);
    s[1] = analogRead(s2);
    s[2] = analogRead(s3);
    s[3] = analogRead(s4);
    s[4] = analogRead(s5);
    s[5] = analogRead(s6);

    //MÁQUINA DE ESTADO FINITA (EM PROCESSO)
    //(1 1 1 1 1 1)
    if ( (s[0] < cor) && (s[1] < cor) && (s[2] < cor) && (s[3] < cor) && (s[4] < cor) && (s[5] < cor) ) {
      motorOption(8, SPEED0, SPEED0); //Frente
    }
    //( 0 1 1 1 1 0 )
    else if ( (s[0] > cor) && (s[1] < cor) && (s[2] < cor) && (s[3] < cor) && (s[4] < cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED0); //Frente
    }
    //( 0 0 1 1 0 0 )
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] < cor) && (s[3] < cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED0); //Frente
    }
    //(0 1 1 1 0 0)
    else if ( (s[0] > cor) && (s[1] < cor) && (s[2] < cor) && (s[3] < cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED1, SPEED0);//Esquerda
    }
    //(0 0 1 1 1 0)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] < cor) && (s[3] < cor) && (s[4] < cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED1);//Direita
    }
    //(0 0 1 0 0 0)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] < cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED1, SPEED0);//Esquerda
    }
    //(0 0 0 1 0 0)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] < cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED1);//Direita
    }
    //(0 1 1 0 0 0)
    else if ( (s[0] > cor) && (s[1] < cor) && (s[2] < cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED1, SPEED0);//Esquerda
    }
    //(0 0 0 1 1 0)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] < cor) && (s[4] < cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED1);//Direita
    }
    //(1 1 1 0 0 0)
    else if ( (s[0] < cor) && (s[1] < cor) && (s[2] < cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED8, SPEED0);//Esquerda
    }
    //(0 0 0 1 1 1)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] < cor) && (s[4] < cor) && (s[5] < cor) ) {
      motorOption(8, SPEED0, SPEED8);//Direita
    }
    //(0 1 0 0 0 0)
    else if ( (s[0] > cor) && (s[1] < cor) && (s[2] > cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED5, SPEED0);//Esquerda
    }
    //(0 0 0 0 1 0)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] > cor) && (s[4] < cor) && (s[5] > cor) ) {
      motorOption(8, SPEED0, SPEED5);//Direita
    }
    //(1 1 0 0 0 0)
    else if ( (s[0] < cor) && (s[1] < cor) && (s[2] > cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(8, SPEED6, SPEED1);//Esquerda
    }
    //(0 0 0 0 1 1)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] > cor) && (s[4] < cor) && (s[5] < cor) ) {
      motorOption(8, SPEED1, SPEED6);//Direita
    }
    //(1 0 0 0 0 0)
    else if ( (s[0] < cor) && (s[1] > cor) && (s[2] > cor) && (s[3] > cor) && (s[4] > cor) && (s[5] > cor) ) {
      motorOption(4, SPEED1, SPEED3);//Esquerda
    }
    //(0 0 0 0 0 1)
    else if ( (s[0] > cor) && (s[1] > cor) && (s[2] > cor) && (s[3] > cor) && (s[4] > cor) && (s[5] < cor) ) {
      motorOption(6, SPEED3, SPEED1);//Direita
    }
  }
}

bool motorStop(long runtime, long currentTime) {
  // Função de parada do robô
  if (millis() >= (runtime + currentTime)) {
    motorOption(8, 0, 0);
    while (true) {
      rgbControl(255, 0, 0, 500);
      rgbControl(0, 0, 0, 500);
    }
    return false;
  }
  rgbControl(0, 0, 255, 0);
  return true;
}


void rgbControl(int red, int green, int blue, long rumtime) {
  // Função para controle do led rgb
  pinMode(PINLEDR, OUTPUT);
  pinMode(PINLEDG, OUTPUT);
  pinMode(PINLEDB, OUTPUT);

  digitalWrite(PINLEDR, HIGH);
  digitalWrite(PINLEDG, HIGH);
  digitalWrite(PINLEDB, HIGH);

  analogWrite(PINLEDR, 255 - red);
  analogWrite(PINLEDG, 255 - green);
  analogWrite(PINLEDB, 255 - blue);
  delay(r
