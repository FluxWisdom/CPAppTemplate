#include <appdef.hpp>
#include <cmath>
#include <sdk/calc/calc.hpp>
#include <sdk/os/debug.hpp>
#include <sdk/os/lcd.hpp>

APP_NAME("Test")
APP_DESCRIPTION("A test app")
APP_AUTHOR("Flux")
APP_VERSION("1.0.2")

// Example for Debug_Printf(x,y,invert_color,0,format_string); //(small text)
// Example for Debug_PrintString(string, invert_color); //(big text)
// Debug_SetCursorPosition(2,1);
// Example for triangle(x0,y0,x1,y1,x2,y2,colorFill,colorLine);
// Example for line(x1,y1,x2,y2,color);

class vec3 {
public:
  float x;
  float z;
  float y;
};

// typedef unsigned vec3;

float sqrt(float num) { return num; };

float length(vec3 v) { return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)); };

float sdSphere(vec3 p, float s) { return length(p) - s; };

extern int width;
extern int height;

uint16_t RayMarch(float x, float y) { return color(255, 255, 255); }

extern "C" void main() {
  calcInit(); // backup screen and init some variables

  fillScreen(color(0, 0, 0));

  for (int w = 1; w <= width; w++) {
    for (int h = 1; h <= height; h++) {

      LCD_SetPixel(w, h, RayMarch(w, h));
    };
  };

  LCD_Refresh();

  while (true) {
    uint32_t key1, key2;  // First create variables
    getKey(&key1, &key2); // then read the keys
    if (testKey(
            key1, key2,
            KEY_CLEAR)) { // Use testKey() to test if a specific key is pressed
      break;
    }
  }

  calcEnd();
}