#include <Adafruit_NeoPixel.h>
//   NEO_KHZ800
//   NEO_GRB + NEO_KHZ800

#define LED_COUNT 64
#define LED_PIN    6

// strip
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// colors
uint32_t red = strip.Color(255,0,0);
uint32_t yellow = strip.Color(255,255,0);
uint32_t green = strip.Color(0,255,0);
uint32_t cyan = strip.Color(0,255,255);
uint32_t blue = strip.Color(0,0,255);
uint32_t magenta = strip.Color(255,0,255);
uint32_t white = strip.Color(255,255,255);


void setup() {
  initialize();
  setBrightness(5);
  show();
}

void loop() {
  colorRangeTest();
}

void colorRangeTest() {
  int t = 2000;

  setRange(red, 1, 64);
  sleep(t);
  clear();
  setRange(yellow, 1, 32);
  sleep(t);
  clear();
  setRange(green, 1, 16);
  sleep(t);
  clear();
  setRange(cyan, 1, 8);
  sleep(t);
  clear();
  setRange(blue, 1, 4);
  sleep(t);
  clear();
  setRange(magenta, 1, 2);
  sleep(t);
  clear();
  setRange(white, 1, 1);
  sleep(t);
  clear();
}

void setRange(uint32_t color, int startLed, int endLed) {
  for (int i=startLed-1; i<endLed; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void initialize() {
  strip.begin();
}

void setBrightness(int brightness) {
  // max 255
  strip.setBrightness(brightness);
}

void show() {
  strip.show();
}

void sleep(int wait) {
  delay(wait);
}

void clear() {
  strip.clear();
}
