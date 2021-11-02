void P_and_O(float voltage, float current)
{
  /* --- Get Reading Value */
  P = voltage * current;
  V = voltage;

  /* --- Calculate Changing Solar Power and Voltage --- */
  dP = P - POld;
  dV = V - VOld;

  if (dP > 0)
  {
    if (dV > 0)
      DT = DT - dDT;
    else
      DT = DT + dDT;
  } else {
    if (dV > 0)
      DT = DT + dDT;
    else
      DT = DT - dDT;
  }

  /* --- Limit Duty Cycle for Boost Converter --- */
  if (DT < DT_MIN_LIMIT)
    DT = DT_MIN_LIMIT;
  if (DT > DT_MAX_LIMIT)
    DT = DT_MAX_LIMIT;

  /* --- Update P&O Values ---*/
  POld = P;
  VOld = V;
}
