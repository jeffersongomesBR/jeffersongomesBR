#include <Arduino.h>

/// --- !THIS IS THE BASE SCRIPT FOR ALL ARDUINO PROJECTS! --- ///
//Author: JeffG (as dcoder)

/// ---Pins--- ///
//#define pins to be used with respective names
//Ex:
#define LED 4 //digital pin 4
#define Buzzer A2 //Analog pin 2

/// ---Commands--- ///
//#define keywords to be read from serial monitor
//Ex:
#define foward 'w' //char "w"
#define backward 's' //char "s"

/// ---Settings--- ///
//settings variables, don't change at runtime, are stored at flash memory
//(before or after compile) and read only at startup
//Ex:
const int parameter = 64; //Change only before compile
bool condition = false; //Change before/after compile, but read only at setup (otherwise, its a Var*)

/// ---Vars--- ///
//misselaneus runtime temp data
//Ex:
u32 preUpdate;
u32 preMicroupdate;
u32 preSecond;

/// ---Objects--- ///
//Used objects are declared here

/// ---Properties--- ///
//Variables with special functions (get/set)
//Ex:
struct propertie {

  private: int value;
  //...

  public:
  int get() {

    return value;
  }

  void set(int newValue) {

    value = newValue;
  }
};

/// ---Functions--- ///
//those are called conditionaly and repeatly

//Called at board powerup
void Awake() {

  //...
}

//Called at first second
void Start() {

  //...
}

//Called 10x per second
void Update() {

  //...
}

//Called 1000x per second
void MicroUpdate() {

  //...
}

//Called per second 
void Timer() {

  //...
}

/// ---Methods--- ///
//those are called dynamicaly on demand

/// ---Base--- ///
//those are the hook of the sketch, where functions will be called

void setup() {
  
  Awake();
}

void loop() {
  
  u32 currentTime = millis();

  if(currentTime - preUpdate >= 100) {

    preUpdate = currentTime;
    Update();
  }

  if(currentTime - preMicroupdate >= 1) {

    preMicroupdate = currentTime;
    MicroUpdate();
  }

  if(currentTime - preSecond >= 1000) {

    preSecond = currentTime;
    Timer();
  }
}