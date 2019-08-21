#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp;
String temp, press, altit;
double t1;
double t2;
double t3;
float seaLevelhPa = 1035.7;
void setup()
{
Particle.publish("DEBUG", "starting...");
Particle.variable("temperature", &t1, DOUBLE);
Particle.variable("pression", &t2, DOUBLE);
Particle.variable("altitude", &t3, DOUBLE);
if (bmp.begin())
{
Particle.publish("DEBUG", "starting the environment timer...");
}
else
{
Particle.publish("WARN", "Could not find a valid BMP280 sensor, check
wiring!");
}
Particle.publish("DEBUG", "started!");
}
void loop()
{
temp = String(int(bmp.readTemperature()));
press = String(int(bmp.readPressure()/100));
altit = String(int(bmp.readAltitude(seaLevelhPa)));
t1 = atof(temp);
t2 = atof(press);
t3 = atof(altit);
Particle.publish("TEMPERATURE", temp);
Particle.publish("PRESSION", press);
Particle.publish("ALTITUDE", altit);
delay(3000);
}
