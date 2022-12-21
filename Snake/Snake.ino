#include <LiquidCrystal.h>
#include "LedControl.h"
#include <EEPROM.h>
int highscoreIndex = 0;
bool highTimeScore = 0;
int contrastValueEp;
int scoreEp;
char atEp;
char afEp;
char athEp;
int scoreEp2;
char atEp2;
char afEp2;
char athEp2;
int scoreEp3;
char atEp3;
char afEp3;
char athEp3;
int scoreEp4;
char atEp4;
char afEp4;
char athEp4;
int scoreEp5;
char atEp5;
char afEp5;
char athEp5;
bool highTime = 0;
bool mutePlay = 0;
int constLCDEp;
const byte dinPin = 12;
const byte clockPin = 13;
const byte loadPin = 10;
bool changedLeaderBoard = 0; 
bool gameOver = 0;
byte pozMod = 0;
int addrL = 0;
bool okF = 0;
bool okT = 0;
bool okTH = 0;
bool okPlay = 0;
byte lengthLeader = 0; 
int addrPlayerOne = 0;
int playIndex = 0;
bool introduce = 0;
bool introduceName = 0;
bool joyYLetterMoved = 0;
bool joyXLetterMoved = 0;
bool okCountDown = 0;
unsigned long debounceOutro = 0;
unsigned long countStartTime = 0;
bool mute = 0;
const int buzzerPin = A4;
LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);
const byte RS = 9;
const byte enable = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
bool aboutEntry = false;
bool howToPlayEntry = false;
int letterPos = 0;
int addrBri = 0;
int addrCon = 4;
int addrDiff = 8;
int addrMat = 12;
int addrBestPlayer = 16;
int addrFirstC = 17;
int addrSecondC = 18;
int addrThirdC = 19;
int addrSecondPlayer = 23;
int addrFirstC2 = 24;
int addrSecondC2 = 25;
int addrThirdC2 = 26;
int addrThirdPlayer = 30;
int addrFirstC3 = 31;
int addrSecondC3 = 32;
int addrThirdC3 = 33;
int addrFourthPlayer = 37;
int addrFirstC4 = 38;
int addrSecondC4 = 39;
int addrThirdC4 = 40;
int addrFifthPlayer = 44;
int addrFirstC5 = 45;
int addrSecondC5 = 46;
int addrThirdC5 = 47;

int af = 97;
int at = 97;
int ath = 97;
int settingIndex = 0; 
int i1;
bool okHighScore = 0;
LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);
const int debounceTotalScroll = 300;
const int debounceTotal = 400;
const int debounceTotal2 = 300;
int contorFour = 0;
unsigned long scrollDebounce = 0;
unsigned long scrollDebounceFour = 0;
const int debounceIntro = 3000;
int menuIndex = 0; 
const int menuSize = 5;
int brightMat = 3;
const String menu[menuSize] = {"Play Game ", "Highscore ", "Settings ", "About ", "How To Play"};
bool ok = 0;
const int pinSW = 2;
const int pinX = A1;
const int pinY = A0;
int brightMatEp;
const String difficulty[2] = {"easy", "medium"};
bool okDiff;
byte diffPos = 0;
byte diffPosEp;
int contrastValue = 54;
bool joyXMoved = false;
bool joyYMoved = false;
const int minThresHold = 200;
const int maxThresHold = 600;
int xValue = 0;
int yValue = 0;
unsigned long lastDebounceTimeMovement = 0;
const int debounceTimeMovement = 1000;
int debounceValue = -1;
int length = 1;
int contor = 0; 
bool reading = 0;
bool lastButtonState = 0;
unsigned long lastDebounceTimePressed = 0; 
bool lastReading = 0;
bool buttonPressedMenu= 0;
unsigned long longPressedTime = 0;
const int longDebounceTimePressLong = 3000;
bool buttonState = 0;
bool buttonPressedState = 0;
unsigned long lasDebounceTimePressed = 0 ;
const int debounceDelayPressed = 20;
const String firstRowAbout = "Enjoy Game! ";
const String secondRowAbout = "Git:Giani2001 ";
unsigned long lastAboutDebounce = 0 ;
const int debounceAbout = 200;
int controlFour = 0; 
const String firstRowHow="How To Play!";
const String secondRowHow="Move the joystick UP and DOWN to not go into an obstacle!";
unsigned long lastDebounceClear = 0;
const int clearTime = 10;
const int matrixBrightnessPin = 11;
const int lcdContrastPin = 3;
int constLCD = 126;
unsigned long lastDebounceTotal = 0;
bool okSetttings = 0;
char playerName[5][3]={
{'u','n','k'},
{'u','n','k'},
{'u','n','k'},
{'u','n','k'},
{'u','n','k'},
};

byte playerScore[5]={0,0,0,0,0};
byte oldplayerScore[5]={0,0,0,0,0};

bool gameBegin = 0;
byte matrixBrightness = 2;
byte xPos =random(0,8);
byte yPos =random(0,8);
const int minThreshold = 350;
const int maxThreshold = 600;
int score = 0;
const byte moveInterval = 100;
unsigned long  lastMoved = 0;
bool lastMovedUp =false;
bool lastMovedDown =false;
bool lastMovedLeft =false;
bool lastMovedRight =false;
const byte matrixSize = 8;
byte matrix[matrixSize][matrixSize] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}  
};

bool okSettings = 0;
const int buttonPin = A5;
bool buttonPressedButt = 0;
int readingButt = 0;
unsigned long lastDebounceTimePressedButt = 0;
const int debounceDelayPressedButt = 100;
int lastReadingButt =0 ;
int lastButtonStateButt =0;
bool buttonStateButt =0 ;
int lengthLead =0;
byte updateInterval = 200;
unsigned long lastUpdate = 0;
class SnakePos {
  public:
    byte x;
    byte y;
}snakePos[64], oldPos[64];
byte xFood = 0; 
byte yFood =  0;
bool moveUp = false;
bool moveDown = true;
bool moveLeft = false;
bool moveRight = false;


void setup() {
pinMode(buttonPin , INPUT_PULLUP);
pinMode(pinX, INPUT);
pinMode(pinY, INPUT);
pinMode(pinSW, INPUT_PULLUP);
pinMode(matrixBrightnessPin, OUTPUT);
pinMode(lcdContrastPin, OUTPUT);
constLCD = EEPROM.read(addrCon);
//contrastValue =EEPROM.read(addrBri);
analogWrite(lcdContrastPin, contrastValue);
analogWrite(matrixBrightnessPin, constLCD);
lcd.begin(16, 2);
//EEPROM.get(addrMat, brightMatEp);
lc.shutdown(0, false);

lc.setIntensity(0, EEPROM.read(addrMat));

lc.clearDisplay(0);
diffPosEp = EEPROM.read(addrDiff);
Serial.begin(9600);
}
void loop() {
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  if(millis() < debounceIntro){
    lcd.setCursor(0, 0);
    lcd.print("Welcome to the");
    lcd.setCursor(5,1);
    lcd.print("best game !");
  }
  else{
    buttonCheck(buttonPressedMenu);
    navigateIntoMenu();
    moveToMenu();
  }
  Serial.println(EEPROM.read(addrMat));
  Serial.println(EEPROM.read(addrCon));
  Serial.println(EEPROM.read(addrBri));
  Serial.println(EEPROM.read(addrDiff));
}
void writeMatrix(){
  byte matrixPlay[matrixSize][matrixSize] = {
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0}  
};
byte matrixHigh[matrixSize][matrixSize] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {1, 1, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 0, 1, 1, 1},
  {1, 0, 1, 0, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1}  
};

byte matrixSettings[matrixSize][matrixSize] = {
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}  
};

byte matrixAbout[matrixSize][matrixSize] = {
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}  
};
byte gameOverMatrix[matrixSize][matrixSize]={
{0,1,0,0,0,0,1,0},
{1,1,0,0,0,0,1,1},
{0,1,0,0,0,0,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,1,1,1,1,1,1,0},
};
byte matrixHow[matrixSize][matrixSize] = {
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}  
};

if(menuIndex == 0 && gameOver ==0){
    for (int row = 0; row < matrixSize; row++) {
      for (int col = 0; col < matrixSize; col++) {
        if(matrixPlay[row][col]==1)
          lc.setLed(0, row, col, true);
        else
          lc.setLed(0, row, col, false);
      }
   }
}
else
  if(menuIndex == 1){
      for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
          if(matrixHigh[row][col]==1)
            lc.setLed(0, row, col, true);
        else
            lc.setLed(0, row, col, false);
        }
      }
  }
  else
    if(menuIndex == 2){
      for (int row = 0; row < matrixSize; row++) {
        for (int col = 0; col < matrixSize; col++) {
          if(matrixSettings[row][col]==1)
            lc.setLed(0, row, col, true);
          else
            lc.setLed(0, row, col, false);
        }
      }
    }
    else
      if(menuIndex == 3){
        for (int row = 0; row < matrixSize; row++) {
          for (int col = 0; col < matrixSize; col++) {
            if(matrixAbout[row][col]==1)
              lc.setLed(0, row, col, true);
            else
              lc.setLed(0, row, col, false);
          }
        }     
      }
      else
      if(menuIndex == 4){
        for (int row = 0; row < matrixSize; row++) {
          for (int col = 0; col < matrixSize; col++) {
            if(matrixHow[row][col]==1)
              lc.setLed(0, row, col, true);
            else
              lc.setLed(0, row, col, false);
          }
        }
      }
if(gameOver == 1 ){
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      if(gameOverMatrix[row][col]==1)
          lc.setLed(0, row, col, true);
      else
          lc.setLed(0, row, col, false);
      }
    }
  }
}
void buttonCheck(bool & buttonPressed) { 
  reading = digitalRead(pinSW);
  if (reading != lastButtonState) {
    lastDebounceTimePressed = millis();
  }
  if(buttonState == 0){
    if(reading!=lastReading){
      longPressedTime = millis();  
    }
    lastReading = reading;
   
  }
  if (millis() - lastDebounceTimePressed > debounceDelayPressed) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW ) {
        if (!buttonPressed) { // to not reset the timer if the button is pressed multiple times
          buttonPressed = 1;
          
        }
        else{
          buttonPressed = 0;    
        }
      }  
    }
  }
  lastButtonState = reading;      
}
void gameGenerate(){
  if(difficulty[diffPosEp] == "medium"){
  xPos =random(1,7);
  yPos =random(1,7);
  }
  else{
    xPos =random(0,8);
  yPos =random(0,8);
  }
  length = 1;
  xFood = random(0,8);
  yFood = random(0,8);
  matrix[xFood][yFood] = 1;
  matrix[xPos][yPos] = 1;
  lc.setLed(0, xFood, yFood, matrix[xFood][yFood]);
  snakePos[0].x = xPos;
  snakePos[0].y = yPos;

}
void moveToMenu(){
  if (yValue < minThresHold && !joyYMoved) { // if the joystick moved to the left
      if(menuIndex > 0){
        --menuIndex;
        ok = 0;
      }
      else{
        ok = 0;
        menuIndex =4;
      }
      mute = 1;
      soundEffect();
      joyYMoved = true; // boolean to increment the value for each movement (not continuosly)
  } 
  if(yValue > maxThresHold && !joyYMoved) { // analog but to the right
      if( menuIndex <menuSize){
        ok = 0;
        menuIndex=(menuIndex +1)%5;
      }
      mute = 1;
      soundEffect();
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold) { // reset joystick X movement
      joyYMoved = false;
      mute = 0;
      soundEffect();
      ok = 1;
  }
}

void setLetterPosition(){
  if (xValue < minThresHold && !joyXLetterMoved && gameOver == 1  ) { 
      if(letterPos > 0){
        letterPos -- ;
      }
      else{
        letterPos = 2;
      }    

      mute = 1;
      soundEffect();
      joyXLetterMoved = true; // boolean to increment the value for each movement (not continuosly)
  } 
  if (xValue > maxThresHold && !joyXLetterMoved   && gameOver == 1) { // analog but to the right
      letterPos = (letterPos +1 )%3;
      joyXLetterMoved = true;
      mute = 1;
      soundEffect();
  }
  if (xValue > minThresHold && xValue < maxThresHold   && gameOver == 1){ // reset joystick X movement
     joyXLetterMoved = false;
     mute = 0;
      soundEffect();
  }
}

void setLetter(){
  if(yValue < minThresHold && !joyYLetterMoved  && gameOver == 1){ 
      if(letterPos ==0){
      if(af > 97){
        af= af -1;
      }
      else{
        af = 122;
      }
  }
  else
    if(letterPos == 1){
      if(at > 97){
        at = at -1;
      }
      else{
        at = 122;
      }
    }
    else
      if(letterPos == 2){
        if(ath > 97){
        ath= ath -1;
      }
      else{
        ath = 122;
      }
      } 
    mute = 1;
      soundEffect();
    joyYLetterMoved = true; // boolean to increment the value for each movement (not continuosly)
  } 
  if(yValue > maxThresHold && !joyYLetterMoved  && gameOver == 1) { 
    if(letterPos == 0){
      if(af <121){
        af = af + 1;
      }
      else{
        af = 97;
      }
    }
    else
      if(letterPos == 1){
        if(at < 121){
        at = at +1;
      }
      else{
        at = 97;
      }
      }
      else
      if(letterPos == 2){
        if(ath < 121){
        ath= ath +1 ;
      }
      else{
        ath = 97;
      }
  }
      mute = 1;
      soundEffect();
    joyYLetterMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold  && gameOver == 1 ) { 
    mute = 0;
      soundEffect();
      joyYLetterMoved = false;
  }
}

void setMatrixContrast(){
  brightMat = EEPROM.read(addrMat);
  if (xValue < minThresHold && !joyXMoved && settingIndex == 0 && menuIndex == 2) { 
      if(brightMat > 0){
        brightMat = ( brightMat - 3 );

      }
      else{
        brightMat = 12;
      }
      EEPROM.put(addrMat, brightMat);
      mute = 1;
      soundEffect();
      joyXMoved = true; 
    } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex == 0 && menuIndex == 2) { 
      if( brightMat <15){
          brightMat =( brightMat + 3 ) % 15;
      }
      EEPROM.put(addrMat, brightMat);
      
      mute = 1;
      soundEffect();
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex == 0 && menuIndex == 2) { // reset joystick X movement
      joyXMoved = false;
      mute = 0;
      EEPROM.put(addrMat, brightMat);
      soundEffect();
  }
}

void setLCDContrast(){
  constLCD = EEPROM.read(addrCon);
  if (xValue < minThresHold && !joyXMoved && settingIndex ==1 && menuIndex == 2) { 
      if(constLCD > 0){
        constLCD  =( constLCD  - 3 )%255;
      }
      mute = 1;
      soundEffect();  
      joyXMoved = true; 
        EEPROM.put(addrCon,constLCD); 
  } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex == 1 && menuIndex == 2) { 
      if( constLCD <255){
           constLCD  =( constLCD  + 10 )%255;
           if(constLCD <115){
             constLCD = 115;
           }
      
      }
      EEPROM.put(addrCon,constLCD);      
      mute = 1;
      soundEffect();
      joyXMoved = true;
  }
  if(xValue > minThresHold && xValue < maxThresHold && settingIndex == 1 && menuIndex == 2) { 
      joyXMoved = false;
      mute = 0;
      soundEffect();
      EEPROM.put(addrCon,constLCD); 
  }
}

void setLCDBrightness(){
  contrastValue = EEPROM.read(addrBri);
  if(xValue < minThresHold && !joyXMoved && settingIndex == 2 && menuIndex == 2) { 
      if(contrastValue > 30){
        contrastValue  = (contrastValue  - 5) ; 
      } 
      else
      {
        contrastValue = 30;
      }
      EEPROM.put(addrBri,contrastValue);
      mute = 1;
      soundEffect(); 
      joyXMoved = true; 
  } 
  if (xValue > maxThresHold && !joyXMoved && settingIndex == 2 && menuIndex == 2) { 
      if( contrastValue <60){
        contrastValue  = (contrastValue  + 5) % 60 ;
      }
      EEPROM.put(addrBri,contrastValue);
      mute = 1;
      soundEffect();
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex == 2 && menuIndex == 2) { 
      joyXMoved = false;
      EEPROM.put(addrBri,contrastValue);
      mute = 0;
      soundEffect();
    }
}

void setDifficulty(){
  diffPos = EEPROM.read(addrDiff);
  if(xValue < minThresHold && !joyXMoved && settingIndex == 3 && menuIndex == 2) { 
      if(diffPos > 0){
       --diffPos;
      }
      else{
       diffPos = 1; 
      }
      EEPROM.put(addrDiff,diffPos);
      mute = 1;
      soundEffect();
      joyXMoved = true; 
  } 
  if(xValue > maxThresHold && !joyXMoved && settingIndex == 3 && menuIndex == 2) { 
      diffPos = (diffPos+1 ) % 2;
      mute = 1;
      soundEffect();
      EEPROM.put(addrDiff,diffPos);
      joyXMoved = true;
  }
  if (xValue > minThresHold && xValue < maxThresHold && settingIndex == 3 && menuIndex == 2 ) { 
      joyXMoved = false;
      mute = 0;
      EEPROM.put(addrDiff,diffPos);
      soundEffect();
    }
}

void firstMenu(){
    if(ok == 0 ){
      lcd.clear();
      ok = 1;
    }
    writeMatrix();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[0]);
    lcd.setCursor(1,1);
    lcd.print(menu[1]);
}

void secondMenu(){
    if(ok == 0 ){
      lcd.clear();
      ok = 1;
    }
     
    writeMatrix();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[1]);
    lcd.setCursor(1,1);
    lcd.print(menu[2]);
    lcd.setCursor(11,0);
    lcd.print(" ");
     lcd.setCursor(10,1);
    lcd.print(" ");
}

void thirdMenu(){
    if(ok == 0  ){
      lcd.clear();
      ok = 1;   
    }
    writeMatrix();
    if( okSettings == 1){
        lcd.clear();
        okSettings = 0;
    }
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[2]);
    lcd.setCursor(1,1);
    lcd.print(menu[3]);
    
}

void fourthMenu(){
    if(ok == 0 ){
      lcd.clear();
      ok = 1;
    }
    if ( aboutEntry == true){   
      lcd.clear();
      aboutEntry = false;
    }
    writeMatrix();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[3]);
    lcd.setCursor(1,1);
    lcd.print(menu[4]);
}

void fifthMenu(){
   if(ok == 0 ){
      lcd.clear();
      ok = 1;
    }
    if ( howToPlayEntry == true){
      lcd.clear();
      howToPlayEntry = false;
    }
    writeMatrix();
    lcd.setCursor(0,0);
    lcd.print(">");
    lcd.setCursor(1,0);
    lcd.print(menu[4]);
    lcd.setCursor(1,1);
    lcd.print(menu[0]);
}
void matrixSet(){
    if(okSetttings == 0 ){
    lcd.clear();
    okSettings = 1;
    }
    setMatrixContrast();
    lcd.setCursor(3,0);
    lcd.print("Led Brightness");
    lcd.setCursor(3,1);
    lcd.print("<");
    brightMatEp = EEPROM.read(addrMat);
    lcd.setCursor(7,1);
    lcd.print(brightMatEp);
    lc.shutdown(0, false);
    
    
    lc.setIntensity(0, brightMatEp);
    lc.clearDisplay(0);
    //lc.setLed(0, 3, 3, true);
    lcd.setCursor(12,1);  
    lcd.print(">");  
    Serial.print("Ceva:");
    Serial.println(brightMatEp);
}

void lcdContrastSet(){
    if(okSetttings == 0 ){
      lcd.clear();
      okSettings = 1;
    }
    lastDebounceClear = millis();
    setLCDContrast();
    lcd.setCursor(3,0);
    lcd.print("LCD Contrast");
    lcd.setCursor(3,1);
    lcd.print("<");
    lcd.setCursor(7,1);
    constLCDEp = EEPROM.read(addrCon);
    lcd.print(constLCDEp);
    analogWrite(matrixBrightnessPin, constLCDEp); 
    lcd.setCursor(12,1);  
    lcd.print(">");  
}

void lcdContrastBright(){
    if(okSetttings == 0 ){
      lcd.clear();
      okSettings = 1;
    }
    setLCDBrightness();
    lcd.setCursor(3,0);
    lcd.print("LCD Brightness");
    lcd.setCursor(3,1);
    lcd.print("<");
    contrastValueEp = EEPROM.read(addrBri);
    lcd.setCursor(7,1);
    lcd.print(contrastValueEp);
    analogWrite(lcdContrastPin, contrastValueEp);
    lcd.setCursor(12,1);  
    lcd.print(">");  
}
void showDifficulty(){
  if(okSetttings == 0 ){
    lcd.clear();
    okSettings = 1;
  }
  setDifficulty();
  lcd.setCursor(3,0);
  lcd.print("Difficulty:");
  lcd.setCursor(3,1);
  lcd.print("<");
  lcd.setCursor(6,1);
  diffPosEp = EEPROM.read(addrDiff);
  lcd.print(difficulty[diffPosEp]);
  lcd.setCursor(12,1);  
  lcd.print(">");  
}
void moveToSetting(){
  if (yValue < minThresHold && !joyYMoved && buttonPressedMenu) { 
      if(settingIndex > 0){
        --settingIndex;
        okSettings = 0;      
      }
      else{
        settingIndex = 3;
        okSettings = 0;
      } 
      mute = 1;
      soundEffect();
      joyYMoved = true; 
  } 
  if (yValue > maxThresHold && !joyYMoved && buttonPressedMenu) { 
      if( settingIndex <3){
         okSettings = 0;
        settingIndex = (settingIndex +1 ) % 4;
      } 
      mute = 1;
      soundEffect();
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold && buttonPressedMenu) { 
      joyYMoved = false;
      okSettings = 1;
      mute = 0;
      soundEffect();
  }
}

void moveHighScore(){
  if (yValue < minThresHold && !joyYMoved && buttonPressedMenu && menuIndex == 1) { 
      if(highscoreIndex > 0){
        --highscoreIndex;
        okHighScore = 0;     
      }
      else{ 
        okHighScore = 0;
        highscoreIndex=4;
      } 
      mute = 1;
      soundEffect();
      joyYMoved = true; 
  } 
  if (yValue > maxThresHold && !joyYMoved && buttonPressedMenu && menuIndex == 1) { 
      if( highscoreIndex <4){
        
        highscoreIndex = (highscoreIndex+1)%5;
      }
        okHighScore = 0;
      mute = 1;
      soundEffect();
      joyYMoved = true;
  }
  if (yValue > minThresHold && yValue < maxThresHold && buttonPressedMenu && menuIndex == 1) { 
      joyYMoved = false;
      okHighScore = 1;
      ok = 0;
      mute = 0;
      soundEffect();
    }
}

void moveToPlay(){
  if (yValue < minThresHold && !joyYMoved && buttonPressedMenu ) { // if the joystick moved to the left
      if(playIndex > -1){
        --playIndex;
        playIndex = playIndex%1;
      }
      mute = 1;
      soundEffect();
      joyYMoved = true; 
    } 
  if (yValue > maxThresHold && !joyYMoved && buttonPressedMenu) { 
      if( playIndex <1){
         ++playIndex;
        playIndex = playIndex%1;
      }
      joyYMoved = true;
      mute = 1;
      soundEffect();
  }
  if (yValue > minThresHold && yValue < maxThresHold && buttonPressedMenu) {
      joyYMoved = false;
      mute = 0;
      soundEffect();
  }
}
void navigateIntoMenu(){

   blinkLeds();
  if(buttonPressedMenu ==0){
    if(menuIndex == 0){
      firstMenu();
      okPlay =0 ;
     
    }
    else
      if(menuIndex == 1){
          highTime = 0;
          secondMenu();
      }
      else
        if(menuIndex == 2){
            thirdMenu();
        }
        else
          if(menuIndex==3){

          fourthMenu();
      }
          else
            if(menuIndex==4){
                fifthMenu();
            }
  }
  else
    if(menuIndex == 3){
      if(millis()-scrollDebounce > debounceTotalScroll){
        if(millis()-lastDebounceClear > clearTime ){
          lcd.clear();
          lastDebounceClear = millis();
        }
        aboutEntry = true;
        lcd.setCursor(0,0);    
        length= firstRowAbout.length();
        lcd.print(firstRowAbout.substring(contor, contor + 16));
        lcd.print(firstRowAbout);
        lcd.setCursor(0,1);
        lcd.print(secondRowAbout);
        contor++;
        if(contor>(firstRowAbout.length()-16)){
        contor = 0;
        }
        scrollDebounce = millis();
      }
    }  
    else
      if(menuIndex == 4){
        if(millis()-scrollDebounceFour > debounceTotalScroll){
          howToPlayEntry = true;
          lcd.clear();
          lcd.setCursor(0,0);    
          lcd.print(firstRowHow);
          lcd.setCursor(0,1);
          lcd.print(secondRowHow.substring(contorFour, contorFour + 16));
          contorFour++;
          if(contorFour>(secondRowHow.length()-16)){
            contorFour = 0;
          }
          scrollDebounceFour = millis();
        }
      }
      else
        if(menuIndex == 2){
           moveToSetting();
           if(settingIndex == 0){
             lc.setLed(0, 3, 3, true);
             if(millis()-lastDebounceTotal>debounceTotal2){
                lastDebounceTotal= millis();
                matrixSet();
             }              
           }
           else
              if(settingIndex ==1){
                 if(millis()-lastDebounceTotal>debounceTotal2){
                    lastDebounceTotal= millis();
                    lcdContrastSet();
                 } 
              }
              else
                 if(settingIndex ==2){
                  if(millis()-lastDebounceTotal>debounceTotal2){
                    lastDebounceTotal= millis();
                    lcdContrastBright();
                  } 
                 }
                 if(settingIndex == 3){
                   if(millis()-lastDebounceTotal>debounceTotal2){
                     lastDebounceTotal = millis();
                     showDifficulty();
                   }
                 }  
        }
        else
          if(menuIndex == 1){
              moveHighScore();
               
              printLeaderBoard();
               
              
          }
          else
            if(menuIndex == 0 ){
              moveToPlay();
              if(playIndex == 0){
                if(gameBegin == 0){
                  gameGenerate();
                  gameBegin = 1;
                }     
                if(gameOver == 0){
                  playGAME();
                  ok = 0 ;
                  debounceOutro = millis();
                }
                else{
                  if(millis()-debounceOutro< debounceIntro*3){
                    if(introduce ==0){
                      lcd.clear();
                      introduce = 1;
                    }
                    
                    
                    lcd.setCursor(5,0);    
                    lcd.print("Game Over!");
                    if(score > EEPROM.read(addrBestPlayer)){
                     lcd.setCursor(0,1);
                      lcd.print("You beat Highscore");
                      pozMod = 0;
                     
                    }
                    else
                      if(score > EEPROM.read(addrSecondPlayer) && score <= EEPROM.read(addrBestPlayer)){
                        lcd.setCursor(0,1);
                        lcd.print("You're 2nd");
                        pozMod = 1;
                      }
                      else
                        if(score > EEPROM.read(addrThirdPlayer) && score <= EEPROM.read(addrSecondPlayer)){
                          lcd.setCursor(0,1);
                          lcd.print("You're 3nd");
                          pozMod = 2;
                        }
                         else
                            if(score > EEPROM.read(addrFourthPlayer) && score <= EEPROM.read(addrThirdPlayer)){
                             lcd.setCursor(0,1);
                             lcd.print("You're 4th");
                              pozMod = 3;
                            }
                            else
                              if(score > EEPROM.read(addrFifthPlayer) && score <=EEPROM.read(addrFourthPlayer)){
                                 lcd.setCursor(0,1);
                                 lcd.print("You're 5th");
                                pozMod = 4;
                              }
                              
                              else{
                                lcd.setCursor(0,1);
                                lcd.print("Much luck next ");
                                pozMod = -1;
                              }
                    writeMatrix();
                  }
                  
                  else{
                    if(introduceName == 0){
                      introduceName =1;
                      lcd.clear();
                    }
                    setLetterPosition();
                    setLetter();
                    lcd.setCursor(0,0);    
                    lcd.print("Introduce Name: ");
                    lcd.setCursor(6,1);
                    lcd.print(char(af));
                    lcd.setCursor(7,1);
                    lcd.print(char(at));
                    lcd.setCursor(8,1);
                    lcd.print(char(ath));
                    lcd.setCursor(10, 1);
                    lcd.print(letterPos);                
                    Serial.print("a1:");
                    Serial.println(at);
                    Serial.print("a2:");
                    Serial.println(at);
                    Serial.print("a3:");
                    Serial.println(ath);
                    buttonCheckButt();
                    Serial.println(buttonPressedButt );
                    if(buttonPressedButt == 1){
                      modifyLeaderBoard();
                      score = 0;
                      buttonPressedMenu = 0;
                      length = 1;
                    lcd.clear();
                    buttonPressedButt = 0;
                    gameOver = 0;
                    introduceName = 0;
                    okPlay = 0;
                    introduce =0;
                    okCountDown = 0;
                    okF = 0;
                    okT = 0;
                    okTH = 0;
                    at = 97;
                    af = 97;
                    ath = 97;
                    updateInterval = 200;
                }
              }
            }
             } 
          }         
  }

int setPotValue(int potValue){
  return map(potValue, 0, 1023, 0, 255);
}

void blinkLeds(){
  if(playIndex == 0 && buttonPressedMenu){
      matrix[xPos][yPos] = 1;
      matrix[xFood][yFood] = 1;
  }
  else{ 
    lc.setLed(0, xPos, yPos, false);
    lc.setLed(0, xFood, yFood, false);
  }
}
void playGAME() {
  showScore();
  updatePositions();
  updateMatrix();
  growSnake();
  gameCollision();
} 

void gameCollision(){
  for(int i = 1; i < length; ++i){
    if(snakePos[0].x == snakePos[i].x && snakePos[0].y == snakePos[i].y){
      gameOver = 1;
    }
  }
  if(oldPos[1].x == snakePos[0].x && oldPos[1].y == snakePos[0].y && length >= 2)
    gameOver = 1;
  if(oldPos[length-1].x == snakePos[0].x && oldPos[length-1].y == snakePos[0].y && length >= 2)
     gameOver = 1;
}

void generateFood() {
   matrix[xFood][yFood] = 1;
   lc.setLed(0, xFood, yFood, matrix[xFood][yFood]);
   lc.setLed(0, xFood, yFood, 0);
   
}

void growSnake(){
    if(xPos==xFood && yPos==yFood){
      length ++;
      lc.setLed(0, xFood, yFood, 0);
      xFood = random(8);
      yFood = random(8);
      score++;
      if(difficulty[diffPosEp] == "medium"){
          score++;
          updateInterval = updateInterval - 10;
      }
      generateFood() ;
    }
}

void updateMatrix() {
  changePos();
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
           lc.setLed(0, row, col, 0);
    }
  }  
  for( i1=0;i1<length;++i1){
    lc.setLed(0, snakePos[i1].x, snakePos[i1].y, 1);
  }
  lc.setLed(0, xFood, yFood, 1);
}

void changePos(){
  for(int i=0;i<length;++i){
    for (int row = 0; row < matrixSize; row++) {
      for (int col = 0; col < matrixSize; col++) {
        if(row == snakePos[i].x && col == snakePos[i].y || row == xFood && col == yFood )
            matrix[row][col] = 1;
        else
            matrix[row][col] = 0; 
      }  
    }
  }
}

void updatePositions() {
   for(int i2 = 0; i2 <= length; ++i2){
      oldPos[i2].x = snakePos[i2].x;
      oldPos[i2].y = snakePos[i2].y;
  }
  lastMovedUp = moveUp;
  lastMovedDown = moveDown;
  lastMovedLeft = moveLeft;
  lastMovedRight = moveRight;
  if (yValue < minThreshold  && moveUp == false && xValue > minThreshold && xValue < maxThreshold && menuIndex == 0  && playIndex == 0 ) {
      
      moveDown = false;
      moveUp = true;
      moveLeft = false;
      moveRight = false;  
  }
  else
    if (yValue > maxThreshold && moveDown == false  && xValue > minThreshold && xValue < maxThreshold && menuIndex == 0  && playIndex == 0) {
      
      moveDown = true;
      moveLeft = false;
      moveRight = false;
      moveUp = false;
    }
    else
      if (xValue > maxThreshold  && moveLeft == false  && yValue>minThreshold && yValue <maxThreshold && menuIndex == 0  && playIndex == 0) {
        
        moveLeft = true;
        moveDown = false;
        moveRight = false;
        moveUp = false;  
      }
      else
        if (xValue < minThreshold   && moveRight == false && yValue>minThreshold && yValue <maxThreshold && menuIndex == 0  && playIndex == 0) {
        
          moveLeft = false;
          moveDown = false;
          moveRight = true;
          moveUp = false;
        }
        else
          if( xValue>minThreshold && xValue <maxThreshold &&  yValue>minThreshold && yValue <maxThreshold && menuIndex == 0  && playIndex == 0){
             mutePlay = 0;
             mute = 0;
            soundEffectPlay();
            moveUp=lastMovedUp;
            moveDown=lastMovedDown;
            moveLeft=lastMovedLeft;
            moveRight=lastMovedRight;
          }
  if (moveLeft == true && millis() - lastUpdate > updateInterval && menuIndex == 0  && playIndex == 0) {
    lastUpdate = millis();
      if(yPos < matrixSize -1){
          yPos++;
        }
        else{
         if(yPos  == 7 && difficulty[diffPosEp] == "medium")
                gameOver = 1;
        yPos = 0;
        }
    for(int i = 1;i <= length;++i){
      snakePos[i].x = oldPos[i-1].x;
      snakePos[i].y = oldPos[i-1].y;
    }
    snakePos[0].x = xPos;
    snakePos[0].y = yPos;
    changePos();
    mutePlay = 1;
    mute = 0;
    soundEffectPlay();
      
  }  
  else
    if (moveRight == true && millis() - lastUpdate > updateInterval && menuIndex == 0  && playIndex == 0) {
      lastUpdate = millis();
      if(yPos >0){
        --yPos;
      }
      else{
        if(yPos ==0 && difficulty[diffPosEp] == "medium")
            gameOver = 1;
       yPos = 7;
      }
      for(int i = 1;i <=  length; ++i){
        snakePos[i].x = oldPos[i-1].x;
        snakePos[i].y = oldPos[i-1].y;
      }
      snakePos[0].x = xPos;
      snakePos[0].y = yPos;
      changePos();
         mutePlay = 1;
         mute = 0;
    soundEffectPlay();
    }
  
    else  
      if (moveDown == true  &&  millis() - lastUpdate > updateInterval && menuIndex == 0  && playIndex == 0) {
        lastUpdate = millis();
        if(xPos < matrixSize -1){
          xPos++;
        }
        else{
         if(xPos  == 7 && difficulty[diffPosEp] == "medium")
                gameOver = 1;
        xPos = 0;
        }
        for(int i = 1;i <=  length; ++i){
          snakePos[i].x = oldPos[i-1].x;
          snakePos[i].y = oldPos[i-1].y;
        }
        snakePos[0].x = xPos;
        snakePos[0].y = yPos;
        changePos();
           mutePlay = 1;
           mute = 0;
    soundEffectPlay();
      } 
      else
        if (moveUp == true && millis() - lastUpdate > updateInterval && menuIndex == 0  && playIndex == 0) {
          lastUpdate = millis();
          if(xPos > 0){
            --xPos;
          }
          else{
            if(xPos ==0 && difficulty[diffPosEp] == "medium")
                  gameOver = 1;
            xPos = 7;
          }
          for(int i = 1;i <= length; ++i){
            snakePos[i].x = oldPos[i-1].x;
            snakePos[i].y = oldPos[i-1].y;
          }
          snakePos[0].x = xPos;
          snakePos[0].y = yPos;
          changePos();
            mutePlay = 1;
            mute = 0;
    soundEffectPlay();
        }
}
void showScore(){ 
  if(okPlay == 0){
      lcd.clear();
      okPlay = 1;
   }
  lcd.setCursor(0,0);    
  lcd.print("Score:");
  lcd.setCursor (8,0);
  lcd.print(score);
}

void buttonCheckButt() { 
  readingButt = digitalRead(buttonPin);
  if (readingButt != lastButtonStateButt) {
    lastDebounceTimePressedButt = millis();
  }
  if(buttonStateButt == 0){
    lastReadingButt = readingButt;
  }
  if (millis() - lastDebounceTimePressedButt > debounceDelayPressedButt) {
    if (readingButt != buttonStateButt) {
      buttonStateButt = readingButt;
      if (buttonStateButt == LOW ) {
        if (!buttonPressedButt) { // to not reset the timer if the button is pressed multiple times
          buttonPressedButt = 1;
          
        }
        else{
          buttonPressedButt = 0;    
        }
      }  
    }
  }
  lastButtonStateButt = readingButt;      
}

void soundEffect(){
  if(mute){
    analogWrite(buzzerPin, 255);
    delay(2);
  }
  else
    analogWrite(buzzerPin, 0);
}

void soundEffectPlay(){
  if(mutePlay){
    analogWrite(buzzerPin, 155);
    delay(2);
  }
  else
    analogWrite(buzzerPin, 0);
}

void writeCountdown() {
  countStartTime = millis();
  if (millis() - countStartTime < 1000) {
    if(okF == 0){
      okF =1;
      lcd.clear();
    }
    lcd.setCursor(5,0);
    lcd.print("3");
  }
  else 
    if (millis() - countStartTime < 2000) {
      if(okT == 0){
        okT =1;
        lcd.clear();
      }
      lcd.setCursor(5,0);
      lcd.print("2");
    }
    else 
      if (millis() - countStartTime < 3000) {
        if(okTH == 0){
        okTH =1;
        lcd.clear();
      }
      lcd.setCursor(5,0);
      lcd.print("1");
    }
}
void modifyLeaderBoard(){
  int j;
  int k;
   scoreEp =  EEPROM.read(addrBestPlayer);
  afEp =EEPROM.read(addrFirstC);
  atEp =EEPROM.read(addrSecondC);
  athEp = EEPROM.read(addrThirdC);

  scoreEp2 =  EEPROM.read(addrSecondPlayer);
  afEp2 =EEPROM.read(addrFirstC2);
  atEp2 =EEPROM.read(addrSecondC2);
  athEp2 = EEPROM.read(addrThirdC2);

  scoreEp3 =  EEPROM.read(addrThirdPlayer);
  afEp3 =EEPROM.read(addrFirstC3);
  atEp3 =EEPROM.read(addrSecondC3);
  athEp3 = EEPROM.read(addrThirdC3);


scoreEp4 =  EEPROM.read(addrFourthPlayer);
  afEp4 =EEPROM.read(addrFirstC4);
  atEp4 =EEPROM.read(addrSecondC4);
  athEp4 = EEPROM.read(addrThirdC4);


scoreEp5 =  EEPROM.read(addrFifthPlayer);
  afEp5 =EEPROM.read(addrFirstC5);
  atEp5 =EEPROM.read(addrSecondC5);
  athEp5 = EEPROM.read(addrThirdC5);


  playerName[0][0] = afEp;
  playerName[0][1] = atEp;
  playerName[0][2] = athEp;
  playerScore[0]= scoreEp;

  playerName[1][0] = afEp2;
  playerName[1][1] = atEp2;
  playerName[1][2] = athEp2;
  playerScore[1]= scoreEp2;

   playerName[2][0] = afEp3;
  playerName[2][1] = atEp3;
  playerName[2][2] = athEp3;
  playerScore[2]= scoreEp3;

   playerName[3][0] = afEp4;
  playerName[3][1] = atEp4;
  playerName[3][2] = athEp4;
  playerScore[3]= scoreEp4;

   playerName[4][0] = afEp5;
  playerName[4][1] = atEp5;
  playerName[4][2] = athEp5;
  playerScore[4]= scoreEp5;

  for(j = 0; j< 5; ++j){
    oldplayerScore[j] = playerScore[j];
  }
  if(pozMod == 0){
    
    EEPROM.put(addrSecondPlayer, playerScore[0]);
    EEPROM.put(addrFirstC2, playerName[0][0]);
    EEPROM.put(addrSecondC2,  playerName[0][1]);
    EEPROM.put(addrThirdC2,  playerName[0][2]);

   

    playerScore[4]=playerScore[3];
    playerScore[3]=playerScore[2];
    playerScore[2]=playerScore[1];
     playerScore[1]=playerScore[0];
    playerScore[0]=score;
    for(j=4;j>0;--j){
      for(k=0;k<3;++k){
        playerName[j][k]=playerName[j-1][k];
      }
    }
    
    EEPROM.put(addrBestPlayer, score);
    EEPROM.put(addrFirstC, af);
    EEPROM.put(addrSecondC, at);
    EEPROM.put(addrThirdC, ath);
    
    playerName[0][0] = af;
    playerName[0][1] = at;
    playerName[0][2] = ath;
  }
  else
    if(pozMod ==1){

     EEPROM.put(addrThirdPlayer, playerScore[1]);
    EEPROM.put(addrFirstC3, playerName[1][0]);
    EEPROM.put(addrSecondC3,  playerName[1][1]);
    EEPROM.put(addrThirdC3,  playerName[1][2]);

    EEPROM.put(addrFourthPlayer, playerScore[2]);
    EEPROM.put(addrFirstC4, playerName[2][0]);
    EEPROM.put(addrSecondC4,  playerName[2][1]);
    EEPROM.put(addrThirdC4,  playerName[2][2]);

    EEPROM.put(addrFifthPlayer, playerScore[3]);
    EEPROM.put(addrFirstC5, playerName[3][0]);
    EEPROM.put(addrSecondC5,  playerName[3][1]);
    EEPROM.put(addrThirdC5,  playerName[3][2]);

    playerScore[4]=playerScore[3];
    playerScore[3]=playerScore[2];
    playerScore[2]=playerScore[1];
    playerScore[1]=score;
    EEPROM.put(addrSecondPlayer, score);
    EEPROM.put(addrFirstC2, af);
    EEPROM.put(addrSecondC2, at);
    EEPROM.put(addrThirdC2, ath);
    
    
    for(j=4;j>1;--j){
      for(k=0;k<3;++k){
        playerName[j][k]=playerName[j-1][k];
      }
    }
    playerName[1][0] = af;
    playerName[1][1] = at;
    playerName[1][1] = ath;
  }
  else
    if(pozMod ==2){
      EEPROM.put(addrFourthPlayer, playerScore[2]);
    EEPROM.put(addrFirstC4, playerName[2][0]);
    EEPROM.put(addrSecondC4,  playerName[2][1]);
    EEPROM.put(addrThirdC4,  playerName[2][2]);

    EEPROM.put(addrFifthPlayer, playerScore[3]);
    EEPROM.put(addrFirstC5, playerName[3][0]);
    EEPROM.put(addrSecondC5,  playerName[3][1]);
    EEPROM.put(addrThirdC5,  playerName[3][2]);

      playerScore[4]=playerScore[3];
      playerScore[3]=playerScore[2];
      playerScore[2]=score;
    for(j=4;j>2;--j){
      for(k=0;k<3;++k){
        playerName[j][k]=playerName[j-1][k];
      }
    }
    EEPROM.put(addrThirdPlayer, score);
    EEPROM.put(addrFirstC3, af);
    EEPROM.put(addrSecondC3, at);
    EEPROM.put(addrThirdC3, ath);

    playerName[2][0] = af;
    playerName[2][1] = at;
    playerName[2][1] = ath;
  } 
   else
    if(pozMod ==3){

         EEPROM.put(addrFifthPlayer, playerScore[3]);
    EEPROM.put(addrFirstC5, playerName[3][0]);
    EEPROM.put(addrSecondC5,  playerName[3][1]);
    EEPROM.put(addrThirdC5,  playerName[3][2]);

      playerScore[4]=playerScore[3];
     
      playerScore[3]=score;
    for(j=4;j>3;--j){
      for(k=0;k<3;++k){
        playerName[j][k]=playerName[j-1][k];
      }
    }
    EEPROM.put(addrFourthPlayer, score);
    EEPROM.put(addrFirstC4, af);
    EEPROM.put(addrSecondC4, at);
    EEPROM.put(addrThirdC4, ath);

    playerName[3][0] = af;
    playerName[3][1] = at;
    playerName[3][1] = ath;
  }
  else
    if(pozMod ==4){
    EEPROM.put(addrFifthPlayer, score);
    EEPROM.put(addrFirstC5, af);
    EEPROM.put(addrSecondC5, at);
    EEPROM.put(addrThirdC5, ath);   

    playerScore[4]=score;
    
    playerName[4][0] = af;
    playerName[4][1] = at;
    playerName[4][1] = ath;
  }
    
}

void printLeaderBoard(){
  if(okHighScore == 0){
    lcd.clear();
    okHighScore = 1;
  }
  scoreEp =  EEPROM.read(addrBestPlayer);
  afEp =EEPROM.read(addrFirstC);
  atEp =EEPROM.read(addrSecondC);
  athEp = EEPROM.read(addrThirdC);

  scoreEp2 =  EEPROM.read(addrSecondPlayer);
  afEp2 =EEPROM.read(addrFirstC2);
  atEp2 =EEPROM.read(addrSecondC2);
  athEp2 = EEPROM.read(addrThirdC2);

  scoreEp3 =  EEPROM.read(addrThirdPlayer);
  afEp3 =EEPROM.read(addrFirstC3);
  atEp3 =EEPROM.read(addrSecondC3);
  athEp3 = EEPROM.read(addrThirdC3);


scoreEp4 =  EEPROM.read(addrFourthPlayer);
  afEp4 =EEPROM.read(addrFirstC4);
  atEp4 =EEPROM.read(addrSecondC4);
  athEp4 = EEPROM.read(addrThirdC4);


scoreEp5 =  EEPROM.read(addrFifthPlayer);
  afEp5 =EEPROM.read(addrFirstC5);
  atEp5 =EEPROM.read(addrSecondC5);
  athEp5 = EEPROM.read(addrThirdC5);


  playerName[0][0] = afEp;
  playerName[0][1] = atEp;
  playerName[0][2] = athEp;
  playerScore[0]= scoreEp;

  playerName[1][0] = afEp2;
  playerName[1][1] = atEp2;
  playerName[1][2] = athEp2;
  playerScore[1]= scoreEp2;

   playerName[2][0] = afEp3;
  playerName[2][1] = atEp3;
  playerName[2][2] = athEp3;
  playerScore[2]= scoreEp3;

   playerName[3][0] = afEp4;
  playerName[3][1] = atEp4;
  playerName[3][2] = athEp4;
  playerScore[3]= scoreEp4;

   playerName[4][0] = afEp5;
  playerName[4][1] = atEp5;
  playerName[4][2] = athEp5;
  playerScore[4]= scoreEp5;
    
  if(millis()-lastDebounceClear > clearTime && highTime == 0  ){
          lcd.clear();
          lastDebounceClear = millis();
           okHighScore = 1;
           highTime = 1;
        }
    
   lcd.setCursor(0,0);
  lcd.print(highscoreIndex+1);
  lcd.setCursor(2,0);
  lcd.print("Name:");
  lcd.setCursor(9,0);
  lcd.print(playerName[highscoreIndex][0]);
   lcd.setCursor(10,0);
  lcd.print(playerName[highscoreIndex][1]);
   lcd.setCursor(11,0);
  lcd.print(playerName[highscoreIndex][2]);
  lcd.setCursor(2,1);
  lcd.print("Score:");
  lcd.setCursor(9,1);
  lcd.print(playerScore[highscoreIndex]);

}

