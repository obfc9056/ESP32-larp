DEVAICE is a small DIY gadget built on ESP32.
It’s made for makers, tinkerers, and anyone who likes pressing buttons and seeing cool stuff happen.

No cloud, no accounts, no nonsense.
Just you, an OLED screen, three buttons, and a bunch of modules.


How to use?
UP / DOWN — scroll through the menu

SELECT — enter an app or go back

In TV Remote: UP = power, DOWN = volume up

In LED Effects: UP = next mode

In Wi-Fi / BLE Scan: just watch the list, SELECT to exit





Install PlatformIO (VSCode extension is easiest).

Clone or download this repo.

Open the folder in VSCode.

Wire everything according to the pinout above.

Connect your ESP32 via USB.

Hit Upload.

Enjoy.

If you want music, drop a file named song.wav into the root of your SD card.



What you’ll need
Must-have
Part	Qty	Note
ESP32 DevKit V1	1	Or any ESP32 board
OLED 128x64 I2C	1	SSD1306
Push buttons	3	For menu navigation
IR LED 940 nm	1	With 100 Ω resistor
Breadboard + wires	—	For prototyping
Nice-to-have
Part	Why
WS2812B LED strip (10 LEDs)	For LED effects
SD card module + card	For music files
MAX98357 I2S amp + speaker	For audio output
18650 battery + charger	Make it portable

Module	ESP32 GPIO
OLED SDA	21
OLED SCL	22
Button UP	15 → GND
Button DOWN	14 → GND
Button SELECT	12 → GND
IR LED	4 (through 100 Ω) → GND
WS2812B data	13
I2S BCK	26
I2S LRC	25
I2S DIN	27
SD CS	5
SD MOSI	23
SD MISO	19
SD SCK	18