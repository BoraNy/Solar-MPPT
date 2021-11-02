void readSolarVoltage(int pin)
{
  solarVoltage = analogRead(pin);
  solarVoltage = PARAM_1 * solarVoltageOld + PARAM_2 * solarVoltage; // Filter
  solarVoltageOld = solarVoltage;
  solarVoltage = solarVoltage * 0.00488758;
  solarVoltage = (solarVoltage / 0.06464924) * FIX_VOLTAGE_READ_ERR;
}

void readSolarCurrent(int pin)
{
  solarCurrent = analogRead(pin);
  solarCurrent = (2.5 - solarCurrent * 0.00488758) / 0.069; // 66mV for ACS 712 30A
  solarCurrent = PARAM_1 * solarCurrentOld + PARAM_2 * solarCurrent; // Filter
  solarCurrentOld = solarCurrent;
}
