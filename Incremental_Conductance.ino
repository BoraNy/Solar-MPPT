void INC(float voltage, float current)
{
  /* --- Get Reading Value --- */
  V = voltage;
  I = current;

  /* --- Calculation --- */
  dV = V - VOld;
  dI = I - IOld;

  /* --- Incremental Conductance --- */
  if (dV == 0)
  {
    if (dI == 0)
    {
      DT = DT;
    } else {
      if (dI > 0)
        DT = DT + dDT;
      else
        DT = DT - dDT;
    }
  } else {
    if ((dI / dV) == -(I / V))
    {
      DT = DT;
    }
    else {
      if ((dI / dV) < -(I / V))
        DT = DT + dDT;
      else
        DT = DT - dDT;
    }
  }

  /* --- Limit Duty Cycle for Boost Converter --- */
  if (DT < DT_MIN_LIMIT)
    DT = DT_MIN_LIMIT;
  if (DT > DT_MAX_LIMIT)
    DT = DT_MAX_LIMIT;

  /* --- Update Variables --- */
  IOld = I;
  VOld = V;
}
