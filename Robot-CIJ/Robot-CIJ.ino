#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

int pinMotorDerechaAdelante = 7;
int pinMotorDerechaAtras = 6;
int pinMotorIzquierdaAdelante = 5;
int pinMotorIzquierdaAtras = 4;
 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie  

  pinMode(pinMotorDerechaAdelante,OUTPUT);
  pinMode(pinMotorDerechaAtras,OUTPUT);
  pinMode(pinMotorIzquierdaAdelante,OUTPUT);
  pinMode(pinMotorIzquierdaAtras,OUTPUT);
  
}
 
void loop()
{
  char resultado;
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    resultado = BT.read();
    Serial.println(resultado);
    if(resultado=='1'){
     forwardMotors(); 
    }
    else if(resultado=='2'){
     rigthMotors(); 
    }
    else if(resultado=='3'){
      leftMotors();
    }
    else if(resultado=='4'){
      backwardMotors();
    }
    else{
      stopMotors();
      Serial.print("Envio: ");
      Serial.println(resultado);
    }
  }
 
}

void forwardMotors(){
  digitalWrite(pinMotorDerechaAtras,LOW);
  digitalWrite(pinMotorIzquierdaAtras,LOW);
  digitalWrite(pinMotorDerechaAdelante,HIGH);
  digitalWrite(pinMotorIzquierdaAdelante,HIGH);
}

void rigthMotors(){
  digitalWrite(pinMotorIzquierdaAtras,LOW);  
  digitalWrite(pinMotorDerechaAdelante,LOW);
  digitalWrite(pinMotorDerechaAtras,HIGH);
  digitalWrite(pinMotorIzquierdaAdelante,HIGH);
}

void leftMotors(){
  digitalWrite(pinMotorDerechaAtras,LOW);
  digitalWrite(pinMotorIzquierdaAdelante,LOW);
  digitalWrite(pinMotorDerechaAdelante,HIGH);
  digitalWrite(pinMotorIzquierdaAtras,HIGH);
  
}

void backwardMotors(){
  digitalWrite(pinMotorDerechaAdelante,LOW);
  digitalWrite(pinMotorIzquierdaAdelante,LOW);
  digitalWrite(pinMotorDerechaAtras,HIGH);
  digitalWrite(pinMotorIzquierdaAtras,HIGH);
  
}

void stopMotors(){
  digitalWrite(pinMotorDerechaAdelante,LOW);
  digitalWrite(pinMotorDerechaAtras,LOW);
  digitalWrite(pinMotorIzquierdaAdelante,LOW);
  digitalWrite(pinMotorIzquierdaAtras,LOW);
  
}

void enviarMensajeAt(String *msj){
  BT.write(msj);
}

