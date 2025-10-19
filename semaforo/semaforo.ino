#define LUZ_VERMELHA 2
#define LUZ_AMARELA 3
#define LUZ_VERDE 4

#define LUZ_VERMELHA_PEDESTRE 5
#define LUZ_VERDE_PEDESTRE 6

#define DEZ_SEGUNDOS 10000
#define OITO_SEGUNDOS 8000
#define QUATRO_SEGUNDOS 4000
void setup() {

  Serial.begin(9600);
  
  iniciaPortas();

}

void loop() {

  tocaSemaforo();
  Serial.println(LUZ_VERMELHA);
}

void iniciaPortas(){

  pinMode(LUZ_VERMELHA, OUTPUT);
  pinMode(LUZ_AMARELA, OUTPUT);
  pinMode(LUZ_VERDE, OUTPUT);
  pinMode(LUZ_VERMELHA_PEDESTRE, OUTPUT);
  pinMode(LUZ_VERDE_PEDESTRE, OUTPUT);
}

void tocaSemaforo() {

 
  digitalWrite(LUZ_VERMELHA, HIGH);

 
  digitalWrite(LUZ_VERDE_PEDESTRE, HIGH);
  digitalWrite(LUZ_VERMELHA_PEDESTRE, LOW);

  delay(OITO_SEGUNDOS);

  piscaPedestre();

  digitalWrite(LUZ_VERDE_PEDESTRE, LOW);
  digitalWrite(LUZ_VERMELHA_PEDESTRE, HIGH);

  digitalWrite(LUZ_VERMELHA, LOW);


  digitalWrite(LUZ_VERDE, HIGH);

  digitalWrite(LUZ_VERDE_PEDESTRE, LOW);
  digitalWrite(LUZ_VERMELHA_PEDESTRE, HIGH);

  delay(DEZ_SEGUNDOS);

  digitalWrite(LUZ_VERDE, LOW);
  digitalWrite(LUZ_AMARELA, HIGH);
  delay(QUATRO_SEGUNDOS);
  digitalWrite(LUZ_AMARELA, LOW);
}

void piscaPedestre(){

    digitalWrite(LUZ_VERDE_PEDESTRE, LOW);
    delay(250);

    for (int i = 0; i < 4; i++) {
    digitalWrite(LUZ_VERMELHA_PEDESTRE, HIGH);
    delay(250);
    digitalWrite(LUZ_VERMELHA_PEDESTRE, LOW);
    delay(250);
  }

}
