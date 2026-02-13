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
  gridTest();

}

void setPixel(int x, int y, uint32_t color) {
  //  (x=1, y=8)  ...   (x=8, y=8)
  //  ...         ...   ...
  //  (x=1, y=1)  ...   (x=8, y=1)
  int address = (x-1) * 8 + y - 1; // 0-indexed
  strip.setPixelColor(address, color);
}

void rectangle(int x1, int y1, int x2, int y2, uint32_t color) {
  int xa = min(x1, x2);
  int xb = max(x1, x2);
  int ya = min(y1, y2);
  int yb = max(y1, y2);
  for (int x=xa; x<xb+1; x++) {
    for (int y=ya; y<yb+1; y++) {
      setPixel(x, y, color);
    }
  }
}

void gridTest() {
  rectangle(1,1,1,1,red);
  rectangle(2,2,2,3,yellow);
  rectangle(1,6,1,8,blue);
  rectangle(7,7,8,8,green);
  rectangle(6,3,8,1,white);
  rectangle(3,3,4,4,magenta);
  rectangle(5,6,7,7,cyan);
  show();
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
