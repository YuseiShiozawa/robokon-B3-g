
#include "SR04.h"
#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN A1
#define ECHO_PIN A0
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

Servo myservo1;
AF_DCMotor motor1(3);  // モーター①をモーター端子3に接続
AF_DCMotor motor2(4);  // モーター②をモーター端子4に接続

const int Servo1_PIN = 10;
void setup(){
myservo1.attach(Servo1_PIN);

motor1.run(RELEASE);  // モーターを一旦停止させる
motor2.run(RELEASE);
delay(2000);
Serial.begin(9600);           // シリアル通信の開始
delay(1000);                   // センサーの初期化のための遅延

}

void loop(){
distance = sr04.Distance();
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
//delay(1000);  // 1秒待機
if(distance >= 200){
//while(true){
myservo1.write(0);  
delay(1000);  // 指定角度にサーボを動かす
myservo1.write(90);
delay(1000);

}

if(distance <= 200){
motor1.run(RELEASE);   // モーターを停止させる(ブレーキ)
motor2.run(RELEASE);
}

else {
 motor1.setSpeed(255);  // モータースピードを設定(0~255の範囲)
 motor2.setSpeed(255); 
 motor1.run(FORWARD);   // モーター1とモーター2を正回転させる
 motor2.run(FORWARD); 
 delay(3000);
}

 /*motor1.setSpeed(128);  // モータースピードを設定(0~255の範囲)
 motor2.setSpeed(128);
 motor1.run(BACKWARD);  // モーター1とモーター2を逆回転させる
 motor2.run(BACKWARD);
 delay(3000);

 motor1.run(RELEASE);   // モーターを停止させる(ブレーキ)
 motor2.run(RELEASE);
 delay(3000);*/

}
