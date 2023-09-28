//Variáveis
int SensorE = A0; // Sensor de linha da Esquerda
int SensorD = A1; // Sensor de linha da Direita
int MET = 9; // Motor da Esquerda para Trás
int MEF = 10; // Motor da Esquerda para Frente
int MDF = 6; // Motor da Direita para Frente
int MDT = 5; // Motor da Direita para Trás
int POT = 100; // Potencia dos motores geral
int RE = 250; // Potencia dos motores para ré
int LeituraD = 80; // Valor de leitura analogica (sensor Direito)
int LeituraE = 80; // Valor de leitura analogica (sensor Esquerdo)
int LED = 2;

  //Configurando o setup (entradas e saidas)
void setup(){

  // Declarando modo de pino do arduino (Motores)
  pinMode(MEF, OUTPUT);
  pinMode(MET, OUTPUT); 
  pinMode(MDF, OUTPUT);
  pinMode(MDT, OUTPUT);
  //>>>>>>>> LED
  pinMode(LED, OUTPUT);

  // OUTPUT = Apenas saida de dados (Liga / Desliga)  

  // Declarando modo de pinos do arduino (Sensores)
  pinMode(SensorD, INPUT);
  pinMode(SensorE, INPUT);
  // INPUT = Apenas entrada de dados (Valores lidos pelos sensores)
  digitalWrite(LED, HIGH);
}

void loop(){ // Configurando o modo de repetição e condicionais
  
  
  // ** Aqui serão comparados os valores de leitura dos sensores em tempo real, com o valor estipulado em Leitura(D/E).

  // Entra nessa condição caso os valores de leitura dos sensores forem maior que os estipulados em Leitura(D/E).


  if(analogRead(SensorE) >= LeituraE && analogRead(SensorD) >= LeituraD){
    // Ao entrar aqui o codigo faz o robô parar.
    analogWrite(MDF, 0);
    analogWrite(MEF, 0);
    analogWrite(MDT, 0);
    analogWrite(MET, 0);
    
    // Nesse comando os valores de potencia dos motores sao definidos como zero (desligados)
  }
  

  // Entra nessa condição caso os valores de leitura dos sensores forem diferentes (Os valores variam conforme o robô anda)
  else if(analogRead(SensorE) >= LeituraE && analogRead(SensorD) <=LeituraD) {
    // Sensor Esquerdo maior ou igual ao valor de Leitura Esquerda e Sensor Direito menor ou igual ao valor de Leitura Direito
    
    // Ao entrar aqui o codigo faz o robô virar a esquerda.
    analogWrite(MDF, POT); // Motor Direito Frente anda na potencia estipulada por POT 
    analogWrite(MEF, 0);
    analogWrite(MDT, 0);
    analogWrite(MET, RE); // Motor Esquerdo Trás anda na potencia estipulada por RE
  }

  // Entra nessa condição caso os valores de leitura dos sensores forem diferentes (Os valores variam conforme o robô anda)
  else if(analogRead(SensorE) <=LeituraE && analogRead(SensorD) >= LeituraD) {
    // Sensor Esquerdo menor ou igual ao valor de Leitura Esquerda e Sensor Direito maior ou igual ao valor de Leitura Direito
    
    // Ao entrar aqui o codigo faz o robô virar a direita.
    analogWrite(MDF, 0);
    analogWrite(MEF, POT); // Motor Esquerdo Frente anda na potencia estipulada por POT.
    analogWrite(MDT, RE); // Motor Direito Trás anda na potencia estipulada por RE.
    analogWrite(MET, 0);
  }

  // Entra nessa condição caso nenhuma das condiçoes anteriores forem atendidas
  else { // Aqui não tem nenhuma comparação ou seja, os dois sensores estao lendo valores abaixo dos estipulados em Leitura(D/E).
  
  // Ao entrar aqui o codigo faz o robô andar para frente.
    analogWrite(MDF, POT); // Motor Direito Frente anda na potencia estipulada por POT 
    analogWrite(MEF, POT); // Motor Esquerdo Frente anda na potencia estipulada por POT.
    analogWrite(MDT, 0);
    analogWrite(MET, 0);
  }


  // Entra nessa condição antes de voltar ao inicio do Loop* (*repetição).
  delay(20); // delay (espera) de 20 milisegundos nas funçoes do arduino.

  //Aqui faz o robô parar, antes de iniciar o proximo Loop.
  analogWrite(MDF, 0);
  analogWrite(MEF, 0);
  analogWrite(MDT, 0);
  analogWrite(MET, 0);

  delay(10); // Apos o robôs parar, arduino recebe mais um delay de 10 milisegundos ate o proximo Loop.
}
// Fim do Loop, aqui todo o codigo se repete voltando ao topo da função void loop.