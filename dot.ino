#include "LedControl.h"
 
// 오렌지보드의 12, 11, 10핀을 사용하고, 1개의 8x8 도트매트릭스를 제어하는 도트매트릭스 객체를 생성합니다.
LedControl lc = LedControl(12, 11, 10, 1);
 
// 8X8로 X자를 표시할 수 있는 배열을 생성합니다.(1은 켜짐, 0은 꺼짐)
byte A[8] = { B00011000, B00100100, B00100100, B01000010, B01111110, B01000010, B01000010, B01000010};
byte B[8] = { B00111100, B01000010, B01000010, B01111100, B01000010, B01000010, B01000010, B00111100};
byte C[8] = { B00111100, B01000000, B01000000, B01000000, B01000000, B01000000, B01000000, B00111100};
byte D[8] = { B01111000, B01000100, B01000010, B01000010, B01000010, B01000010, B01000100, B01111000};
byte E[8] = { 0x7e, 0x40, 0x40, 0x7c, 0x40, 0x40, 0x7e, 0x00 };
byte F[8] = { 0x7e, 0x40, 0x40, 0x7c, 0x40, 0x40, B01000000, 0x00 };


// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup()
{
  // 도트매트릭스의 절전모드를 꺼줍니다.
  lc.shutdown(0, false);
 
  // 도트매트릭스의 LED 밝기를 8로 지정해 줍니다.(0~15)
  lc.setIntensity(0, 2);
 
  // 도트매트릭스의 LED를 초기화 해줍니다.
  lc.clearDisplay(0);
}
 
 
// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop()
{
  // 도트매트릭스의 LED를 첫 행부터 차례대로 켭니다.
  for (int row = 0; row < 8; row++)
  {
    lc.setRow(0, row, F[row]);  // 도트매트릭스의 LED를 행단위로 위부터 켭니다.
    delay(25);
  }
}
