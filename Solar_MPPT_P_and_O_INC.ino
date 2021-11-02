/*
    Programmed By Virbora Ny
    2 NOV 2021
*/

#include "variables.h"

void setup()
{
  TCCR1B = TCCR1B & (B11111000 | B00000001); // for PWM frequency of 31372.55 Hz

  Serial.begin(9600);
  pinMode(PWM_PIN, OUTPUT);

  // Duty Cycle Soft Start
  DT = 50;
}

void loop()
{
  /* --- Read Voltage and Current --- */
  readSolarVoltage(VOLTAGE_SENSOR_PIN);
  readSolarCurrent(CURRENT_SENSOR_PIN);

  /* --- Perturb and Observe --- */
  // P_and_O(solarVoltage, solarCurrent);

  /* --- Incremental Conductance --- */
  INC(solarVoltage, solarCurrent);

  /* --- Control Duty Cycle --- */
  analogWrite(PWM_PIN, DT);

  /*
    if (millis() - tick >= 100)
    {
      tick = millis();
      Serial.print(solarVoltage);
      Serial.print(',');
      Serial.print(solarCurrent);
      Serial.print(',');
      Serial.println(DT);
    }
  */
}
