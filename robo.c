#include <AFMotor.h>  

AF_DCMotor motor1(3);  // モーター①をモーター端子3に接続
AF_DCMotor motor2(4);  // モーター②をモーター端子4に接続

void setup(){

 motor1.run(RELEASE);  
 motor2.run(RELEASE);
 delay(2000);

}

void loop(){

 motor1.setSpeed(255);  
 motor2.setSpeed(255); 
 motor1.run(FORWARD);  // モーター1とモーター2を正回転させる
 motor2.run(FORWARD); 
 delay(3000);

 /*motor1.setSpeed(128);  // モータースピードを設定(0~255の範囲)
 motor2.setSpeed(128);
 motor1.run(BACKWARD);  // モーター1とモーター2を逆回転させる
 motor2.run(BACKWARD);
 delay(3000);

 motor1.run(RELEASE);   // モーターを停止させる(ブレーキ)
 motor2.run(RELEASE);
 delay(3000);*/

}
