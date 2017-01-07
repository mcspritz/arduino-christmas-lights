#include <NeoPixelBus.h>

#define PixelCount 50
#define PixelPin0 2
#define PixelPin1 3
#define PixelPin2 4
#define PixelPin3 5
#define PixelPin4 6
#define pixelToChange 8
#define maxCount 1000
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

NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip0(PixelCount, PixelPin0);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip1(PixelCount, PixelPin1);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip2(PixelCount, PixelPin2);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip3(PixelCount, PixelPin3);
NeoPixelBus<NeoRgbFeature, Neo800KbpsMethod> strip4(PixelCount, PixelPin4);

void SetRandomSeed()
{
  uint32_t seed;
  seed = analogRead(0);
  delay(1);
  for (int shifts = 3; shifts < 31; shifts += 3)
  {
    seed ^= analogRead(0) << shifts;
    delay(1);
  }
  randomSeed(seed);
}

RgbColor PickRandomColor(uint8_t mode)
{
  /* 
   * get a random colour based on mode 
   *   mode = 0: all colour set
   *   mode = 1: all colour except black
   *   mode = 2: only red, green, blue, yellow and black
   */
  uint8_t whichColour = random(255);
  if ( mode == 2 )
  {
    if (whichColour < 32){ return red;}
    if (whichColour < 64){ return green;}
    if (whichColour < 96){ return blue;}
    if (whichColour < 128){ return yellow;}
    if (whichColour < 160){ return lightBlue;}
    return black;
  }
  if ( mode == 3 )
  {
    if (whichColour < 128){ return red;}
    return black;
  }
  if ( mode == 4 )
  {
    if (whichColour < 128){ return green;}
    return black;
  }
  if ( mode == 5 )
  {
    if (whichColour < 128){ return blue;}
    return black;
  }
  if ( mode == 6 )
  {
    if (whichColour < 128){ return yellow;}
    return black;
  }
  if ( mode == 7 )
  {
    if (whichColour < 128){ return purple;}
    return black;
  }
  if ( mode == 8 )
  {
    if (whichColour < 128){ return lightBlue;}
    return black;
  }
  if ( mode == 9 )
  {
    if (whichColour < 128){ return white;}
    return black;
  }
  if (whichColour < 16){ return red;}
  if (whichColour < 32){ return green;}
  if (whichColour < 48){ return blue;}
  if (whichColour < 64){ return yellow;}
  if (whichColour < 80){ return lightBlue;}
  if (whichColour < 96){ return purple;}
  if (whichColour < 112){ return orange;}
  if (whichColour < 128){ return fuchsia;}
  if (whichColour < 144 && mode != 1){ return black;}
  return RgbColor(random(127), random(127), random(127));
}

RgbColor colorEffect(uint8_t mode, uint8_t intensity)
{
  if ( mode == 0x1 ){return PickRandomColor(2);}
  if ( mode == 0x2 ){return RgbColor(intensity, 0, 0);}
  if ( mode == 0x3 ){return RgbColor(127 - intensity, 0, 0);}
  if ( mode == 0x4 ){return RgbColor(0, intensity, 0);}
  if ( mode == 0x5 ){return RgbColor(0, 127 - intensity, 0);}
  if ( mode == 0x6 ){return RgbColor(0, 0, intensity);}
  if ( mode == 0x7 ){return RgbColor(0, 0, 127 - intensity);}
  if ( mode == 0x8 ){return RgbColor(intensity, intensity, 0);}
  if ( mode == 0x9 ){return RgbColor(127 - intensity, 127 - intensity, 0);}
  if ( mode == 0xA ){return RgbColor(intensity, 0, intensity);}
  if ( mode == 0xB ){return RgbColor(127 - intensity, 0, 127 - intensity);}
  if ( mode == 0xC ){return RgbColor(0, intensity, intensity);}
  if ( mode == 0xD ){return RgbColor(0, 127 - intensity, 127 - intensity);}
  if ( mode == 0xE ){return RgbColor(intensity, intensity, intensity);}
  if ( mode == 0xF ){return RgbColor(127 - intensity, 127 - intensity, 127 - intensity);}
  return PickRandomColor(0);
}
  
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
  SetRandomSeed();
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
  offEffect();
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
  offEffect();
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
  offEffect();
  /*
   * All pixels in random colour
   */
  pixel = 0;
  while (pixel < PixelCount)
  {
    delay(random(50, 200));
    strip0.SetPixelColor(pixel, PickRandomColor(1));
    strip0.Show();
    strip1.SetPixelColor(pixel, PickRandomColor(1));
    strip1.Show();
    strip2.SetPixelColor(pixel, PickRandomColor(1));
    strip2.Show();
    strip3.SetPixelColor(pixel, PickRandomColor(1));
    strip3.Show();
    strip4.SetPixelColor(pixel, PickRandomColor(1));
    strip4.Show();
    pixel ++;
  }
}

void loop()
{
  uint16_t counter = 0;
  uint8_t strip = random(4);
  RgbColor color = black;
  /* 
   * This mode changes up to "pixelToChange" pixels each cycle 
   */
  uint8_t mode = 0;
  uint8_t mode0 = 0;
  uint8_t mode1 = 0;
  uint8_t mode2 = 0;
  uint8_t mode3 = 0;
  uint8_t mode4 = 0;
  /*
   * Trying to make a fake transition colour with different colours
   */
  while (mode < modesNumber)
  {
    counter = 0;
    while (counter < maxCount)
    {
      delay(typicalDelay);
      color = PickRandomColor(mode);
      strip0.SetPixelColor(0, color);
      strip0.Show();
      color = PickRandomColor(mode);
      strip1.SetPixelColor(0, color);
      strip1.Show();
      color = PickRandomColor(mode);
      strip2.SetPixelColor(0, color);
      strip2.Show();
      color = PickRandomColor(mode);
      strip3.SetPixelColor(0, color);
      strip3.Show();
      color = PickRandomColor(mode);
      strip4.SetPixelColor(0, color);
      strip4.Show();
      strip0.ShiftRight(1);
      strip1.ShiftRight(1);
      strip2.ShiftRight(1);
      strip3.ShiftRight(1);
      strip4.ShiftRight(1);
      counter ++;
    }
    mode ++;
  }
  mode = 0;
  while (mode < 16)
  {
    mode0 = random(2, effectsNumber);
    mode1 = random(2, effectsNumber);
    mode2 = random(2, effectsNumber);
    mode3 = random(2, effectsNumber);
    mode4 = random(2, effectsNumber);
    counter = 0;
    while (counter < maxCount)
    {
      delay(typicalDelay);
      strip = (counter << 3) & 0x007F;
      color = colorEffect(mode0, strip);
      strip0.SetPixelColor(0, color);
      strip0.Show();
      color = colorEffect(mode1, strip);
      strip1.SetPixelColor(0, color);
      strip1.Show();
      color = colorEffect(mode2, strip);
      strip2.SetPixelColor(0, color);
      strip2.Show();
      color = colorEffect(mode3, strip);
      strip3.SetPixelColor(0, color);
      strip3.Show();
      color = colorEffect(mode4, strip);
      strip4.SetPixelColor(0, color);
      strip4.Show();
      strip0.ShiftRight(1);
      strip1.ShiftRight(1);
      strip2.ShiftRight(1);
      strip3.ShiftRight(1);
      strip4.ShiftRight(1);
      counter ++;
    }
    mode ++;
  }
  offEffect();
  /*
   * every strip has now a random colour
   */
  mode = 0;
  while (mode < modesNumber)
  {
    counter = 0;
    while (counter < maxCount)
    {
      delay(random(minDelay,maxDelay));
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode);
        pixel = random(PixelCount);
        strip0.SetPixelColor(pixel, color);
      }
      strip0.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode);
        pixel = random(PixelCount);
        strip1.SetPixelColor(pixel, color);
      }
      strip1.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode);
        pixel = random(PixelCount);
        strip2.SetPixelColor(pixel, color);
      }
      strip2.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode);
        pixel = random(PixelCount);
        strip3.SetPixelColor(pixel, color);
      }
      strip3.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode);
        pixel = random(PixelCount);
        strip4.SetPixelColor(pixel, color);
      }
      strip4.Show();
      counter ++;
    }
    mode ++;
  }
  mode = 0;
  while (mode < 16)
  {
    mode0 = random(modesNumber);
    mode1 = random(modesNumber);
    mode2 = random(modesNumber);
    mode3 = random(modesNumber);
    mode4 = random(modesNumber);
    counter = 0;
    while (counter < maxCount)
    {
      delay(random(minDelay, maxDelay));
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode0);
        pixel = random(PixelCount);
        strip0.SetPixelColor(pixel, color);
      }
      strip0.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode1);
        pixel = random(PixelCount);
        strip1.SetPixelColor(pixel, color);
      }
      strip1.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode2);
        pixel = random(PixelCount);
        strip2.SetPixelColor(pixel, color);
      }
      strip2.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode3);
        pixel = random(PixelCount);
        strip3.SetPixelColor(pixel, color);
      }
      strip3.Show();
      for (strip=0; strip <= pixelToChange; strip++){
        color = PickRandomColor(mode4);
        pixel = random(PixelCount);
        strip4.SetPixelColor(pixel, color);
      }
      strip4.Show();
      counter ++;
    }
    mode ++;
  }
  offEffect();
}

