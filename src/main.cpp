#include <Arduino.h>

//
// ロボットアーム側制御
//
//

// アームの軸数
const int axis_num = 6;
int first_angle[6] = {};

void setup() {
    Serial.begin( 9600 );
}

void loop() {

    // ントローラーの角度を読み取る
    String return_msg;
    for (size_t i = 0; i < axis_num; i++) {
      int angle = analogRead(i);
      if (first_angle[i] == 0) {
        first_angle[i] = angle;
        continue;
      }

      char temp_analog_in[4];
      // 初期値からの増減を出力
      sprintf(temp_analog_in, "%03d", angle-first_angle[i]);
      String analog_in = String(temp_analog_in);

      // 送信するCSVを作成する
      if (return_msg != "") {
        analog_in = ","+analog_in;
      }
      return_msg += analog_in;
    }

    // CSV形式のコントローラ角度を各関節に分解する
    if (return_msg != "") {
      Serial.println(return_msg);
    }

    delay(100);
}
