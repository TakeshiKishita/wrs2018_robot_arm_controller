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
    String return_msg;
    for (size_t i = 0; i < axis_num; i++) {
      char temp_analog_in[3] = "";
      sprintf(temp_analog_in, "%03d", analogRead(i));
      String analog_in = String(temp_analog_in);

      // 送信するCSVを作成する
      return_msg += analog_in;
    }

    // CSV形式のコントローラ角度を各関節に分解する
    Serial.println(return_msg);

    delay(100);
}
