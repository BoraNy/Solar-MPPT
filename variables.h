#define PWM_PIN 9
#define VOLTAGE_SENSOR_PIN A1
#define CURRENT_SENSOR_PIN A2
#define DT_MIN_LIMIT 10
#define DT_MAX_LIMIT 205

#define PARAM_1 .95
#define PARAM_2 .05
#define FIX_VOLTAGE_READ_ERR .99

static float solarVoltage = 0,
             solarVoltageOld = 0,
             solarCurrent = 0,
             solarCurrentOld = 0;

static float P = 0,
             POld = 0,
             dP = 0;

static float V = 0,
             VOld = 0,
             dV = 0;

static float I = 0,
             IOld = 0,
             dI = 0;

static float dDT = .5,
             DT = 0;

unsigned long tick = 0;
