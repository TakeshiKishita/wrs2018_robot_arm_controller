#include <Arduino.h>

//
// ロボットアーム側制御
//
//

// アームの軸数
const int axis_num = 6;

void setup() {
    Serial.begin( 9600 );
}

void loop() {

    // ントローラーの角度を読み取る
    String return_csv;
    for (size_t i = 0; i < axis_num; i++) {
      int analog_in = analogRead(i);

      // 送信するCSVを作成する
      if (return_csv == ""){
        return_csv = analog_in;
      }else{
        return_csv = ","+analog_in;
      }
    }

    // CSV形式のコントローラ角度を各関節に分解する
    Serial.print(return_csv);

    delay(100);
}
