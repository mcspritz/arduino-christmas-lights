#include <NeoPixelBus.h>

#define PixelCount 50
#define PixelPin0 2
#define PixelPin1 3
#define PixelPin2 4
#define PixelPin3 5
#define PixelPin4 6
#define pixelToChange 8
#define minDelay 10
#define typicalDelay 150
#define maxDelay 150
#define modesNumber 10
#define effectsNumber 0xF

const RgbColor red(127, 0, 0);
const RgbColor green(0, 127, 0);
const RgbColor blue(0, 0, 127);
const RgbColor yellow(127, 127, 0);
const RgbColor lightBlue(0, 127, 127);
const RgbColor purple(127, 0, 127);
const RgbColor orange(127, 63, 0);
const RgbColor fuchsia(127, 0, 63);
const RgbColor white(127);
const RgbColor black(0);

uint8_t pixel = 0;
RgbColor color = black;

NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip0(PixelCount, PixelPin0);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip1(PixelCount, PixelPin1);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip2(PixelCount, PixelPin2);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip3(PixelCount, PixelPin3);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip4(PixelCount, PixelPin4);


void offEffect()
{
  /*
   * This turns off all the pixels from the last to the first
   */
  pixel = 0;
  while (pixel < PixelCount)
  {
    delay(random(minDelay, maxDelay));
    strip0.SetPixelColor(PixelCount - pixel - 1, black);
    strip0.Show();
    strip1.SetPixelColor(PixelCount - pixel - 1, black);
    strip1.Show();
    strip2.SetPixelColor(PixelCount - pixel - 1, black);
    strip2.Show();
    strip3.SetPixelColor(PixelCount - pixel - 1, black);
    strip3.Show();
    strip4.SetPixelColor(PixelCount - pixel - 1, black);
    strip4.Show();
    pixel ++;
  }
}

void setup()
{
  /*
   * Setting all the pixels off
   */
  strip0.Begin();
  strip0.Show();
  strip1.Begin();
  strip1.Show();
  strip2.Begin();
  strip2.Show();
  strip3.Begin();
  strip3.Show();
  strip4.Begin();
  strip4.Show();
  /*
   * Testing red
   */
  Serial.begin(9600);
  pixel = 0;
  while (pixel < PixelCount)
  {
    delay(random(50, 200));
    strip0.SetPixelColor(pixel, red);
    strip0.Show();
    strip1.SetPixelColor(pixel, red);
    strip1.Show();
    strip2.SetPixelColor(pixel, red);
    strip2.Show();
    strip3.SetPixelColor(pixel, red);
    strip3.Show();
    strip4.SetPixelColor(pixel, red);
    strip4.Show();
    pixel ++;
  }
  /*
   * Testing green
   */
  pixel = 0;
  while (pixel < PixelCount)
  {
    delay(random(50, 200));
    strip0.SetPixelColor(pixel, blue);
    strip0.Show();
    strip1.SetPixelColor(pixel, blue);
    strip1.Show();
    strip2.SetPixelColor(pixel, blue);
    strip2.Show();
    strip3.SetPixelColor(pixel, blue);
    strip3.Show();
    strip4.SetPixelColor(pixel, blue);
    strip4.Show();
    pixel ++;
  }
  /*
   * Testing blue
   */
  pixel = 0;
  while (pixel < PixelCount)
  {
    delay(random(50, 200));
    strip0.SetPixelColor(pixel, green);
    strip0.Show();
    strip1.SetPixelColor(pixel, green);
    strip1.Show();
    strip2.SetPixelColor(pixel, green);
    strip2.Show();
    strip3.SetPixelColor(pixel, green);
    strip3.Show();
    strip4.SetPixelColor(pixel, green);
    strip4.Show();
    pixel ++;
  }
}

void loop()
{
  int red_value = 0;
  int green_value = 0;
  int blue_value = 0;
  Serial.println('Enter red value:');
  while (Serial.available() == 0)
  {
    int red_value = Serial.parseInt();
  }
  Serial.print('Enter green value:');
  while (Serial.available() == 0)
  {
    int green_value = Serial.parseInt();
  }
  Serial.print('Enter blue value:');
  while (Serial.available() == 0)
  {
    int blue_value = Serial.parseInt();
  }
  Serial.println('Entered ' + red_value + ', ' + green_value + ', ' + blue_value);
  pixel = 0;
  color = RgbColor(red_value, green_value, blue_value);
  while (pixel < PixelCount)
  {
    delay(typicalDelay);
    strip0.SetPixelColor(pixel, green);
    strip0.Show();
    strip1.SetPixelColor(pixel, green);
    strip1.Show();
    strip2.SetPixelColor(pixel, green);
    strip2.Show();
    strip3.SetPixelColor(pixel, green);
    strip3.Show();
    strip4.SetPixelColor(pixel, green);
    strip4.Show();
    pixel ++;
  }
}

