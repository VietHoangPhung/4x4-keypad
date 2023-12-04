//by Phung Viet Hoang, Trieu Thanh Tung. Pham Dang Duc - Do an co so nganh - DHCNHN - KTMT k15
//test ok, thay được switch case bằng chiếu mảng 

#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_sv_SE.h>

#include <stdio.h>

#define KEY_A 97
#define KEY_B 98
#define KEY_C 99
#define KEY_D 100
#define KEY_E 101
#define KEY_F 102
#define KEY_G 103
#define KEY_H 104
#define KEY_I 105
#define KEY_J 106
#define KEY_K 107
#define KEY_L 108
#define KEY_M 109
#define KEY_N 110
#define KEY_O 111
#define KEY_P 112
#define KEY_Q 113
#define KEY_R 114
#define KEY_S 115
#define KEY_T 116
#define KEY_U 117
#define KEY_V 118
#define KEY_W 119
#define KEY_X 120
#define KEY_Y 121
#define KEY_Z 122

const byte row = 4;
const byte col = 4; 
/*
7 8 9 + 
4 5 6 - 
1 2 3 * 
0 . e /
*/
byte key[row][col] = {
  {KEY_KP_7, KEY_KP_8, KEY_KP_9, KEY_KP_PLUS},
  {KEY_KP_4, KEY_KP_5, KEY_KP_6, KEY_KP_MINUS},
  {KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_ASTERISK},
  {KEY_KP_0, KEY_KP_DOT, KEY_KP_ENTER, KEY_KP_SLASH}
};
/*byte key[row][col] = {
  {KEY_KP_7, KEY_KP_8, KEY_KP_9, KEY_KP_PLUS},
  {KEY_KP_4, KEY_KP_5, 102, KEY_KP_MINUS},
  {KEY_LEFT_SHIFT, 110, KEY_KP_3, KEY_KP_ASTERISK},
  {KEY_LEFT_CTRL, KEY_KP_DOT, KEY_KP_ENTER, KEY_KP_SLASH}
};*/

#define col1 9
#define col2 8
#define col3 7
#define col4 6

#define row1 15
#define row2 14
#define row3 16
#define row4 10

byte colPin[col] = {9, 8, 7, 6};
byte rowPin[row] = {15, 14, 16, 10};

bool lastKeyState[row][col]={0};

bool rowState[row][col] = {
  {0, 1, 1, 1},
  {1, 0, 1, 1},
  {1, 1, 0, 1},
  {1, 1, 1, 0}
};

void setup() {
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  pinMode(col1, INPUT_PULLUP);
  pinMode(col2, INPUT_PULLUP);
  pinMode(col3, INPUT_PULLUP);
  pinMode(col4, INPUT_PULLUP);
}

void loop() {
  for(int i=0; i<row; i++){
    for(int j=0; j<row; j++)
      digitalWrite(rowPin[j], rowState[i][j]);                              
    for(int k=0; k<col; k++){
      bool keyState = !(digitalRead(colPin[k]));
      if(keyState && !lastKeyState[i][k]){
        lastKeyState[i][k] = keyState;
        Keyboard.press(key[i][k]);
      }
      else if(!keyState && lastKeyState[i][k]){
        lastKeyState[i][k] = keyState;
        Keyboard.release(key[i][k]);
      }
    }
  }
}