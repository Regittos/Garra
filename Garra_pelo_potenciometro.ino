#include <Servo.h> // Declaramos a biblioteca a sr utilizada, como nesse caso é a servo, o Arduino já sabe que estamos, obviamente, trabalhano com um
Servo s1, s2, s3, s4, s5, s6; // Nesta parte se cria o(s) objeto(s) servo(s)
int p1 = A0, p2 = A1, p3 = A2, p4 = A3, p5 = A4, p6 = A5; // Nesta parte se declara as variaveis analógicas que sarão utilizadas como portas de leitura
int v1, v2, v3, v4, v5, v6; // Variaveis a ser utilizada na escrita dos angulos dos servos
void setup() {
Serial.begin(9600); // Utilizamos a comunicação Serial para analisar os valores e corrigir o alcance dos movimentos para evitar problemas futuros como perda da autonomia
s1.attach(11); // Com o comando attach podemos ancorar um objeto criado na programação a uma porta tanto Analogica ou Digital(nese caso deve-se utilizar as portas pwm(11, 10, 9, 6, 5, 3)
s2.attach(10);// Aqui acontece o mesmo que na linha anterior
s3.attach(9);
s4.attach(6);
s5.attach(5);
s6.attach(3);
}
void loop() {
v1 = analogRead(p1); // Igualamos uma das variáveis do tipo inteira ao valor recebido pela porta Analogica
v1 = map(v1, 0, 1023, 55, 180); // Utilizando o comando map, que funciona como uma regra de três, podemos transformar um valor em outro
s1.write(v1);/*Servo pinça, B*/ // Aqui pedimos ao sistema que a informação seja escrita na porta conectada à algum servo
delay(15); // Utilizamos o delay para que seja efetuado movimentos mais harmonicos, de uma cotidiana de dizer, ele se move com mais fluidez
v2 = analogRead(p2);// O que acontece a partir daqui, até a linha 29, foi explicado nas ultims quatro linhas
v2 = map(v2, 0, 1023, 0, 60);
s2.write(v2); /*servo C*/
delay(15);
v3 = analogRead(p3);
v3 = map(v3, 0, 1023, 180, 0);
s3.write(v3);  /* servo base, D*/
delay(15);
v4 = analogRead(p4);
v4 = map(v4, 0, 1023, 90, 180);
s4.write(v4); /*servo A*/
delay(15);
v5 = analogRead(p5);
v5 = map(v5, 0, 1023, 180, 0);
s5.write(v5);  /* servo base, D*/
delay(15);
v6 = analogRead(p6);
v6 = map(v6, 0, 1023, 0, 180);
s6.write(v6); /*servo A*/
delay(15);
//Serial.print("Valor"); // Aqui enviamos um caractere a ser escrito no monitor Serial
//Serial.println(v1); // Aqui o valor, no momento atual da leitura, da variavel será escrita no monitor Serial
//delay(200);// Como a resposta do arduino é muito rapida, diminuimos a velocidade de reprodução das informções a serem lidas.
}
