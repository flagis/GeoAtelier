#include <ESP8266WiFi.h>

#include "ADXL345.h"
//#include "BMP085.h"
//#include "BMP180.h"
//#include "buttons.h"
//#include "HMC5883.h"
//#include "HX711.h"
//#include "HCSR04.h"

#include "logging.h"
#include "credentials.h"
#include "settings.h"
#include "wifi.h"

#include <MySQL_Generic.h>

MySQL_Connection conn((Client *)&client);
auto query_mem = MySQL_Query(&conn);

float measurement = 0.0f;

void setup()
{
  setupLogging();
  setupSensor();

  connect2Wifi(ssid, pass);
}

void transmitValue()
{
  Serial.print("Connecting to SQL Server @");
  Serial.print(server);
  Serial.print(", Port =");
  Serial.println(server_port);

  if (conn.connectNonBlocking(server, server_port, user, password) != RESULT_FAIL)
  {
    // Sample query
    auto INSERT_SQL = String("INSERT INTO geo_atelier.sensor")
                      + " (id, measureTime, measurement) VALUES ('" + WiFi.getChipId() + "', " + millis() + ", " + measurement + " )";
    Serial.println(INSERT_SQL);

    if ( !query_mem.execute(INSERT_SQL.c_str()) )
      Serial.println("Insert error");
    else
      Serial.println("Data Inserted.");

    Serial.println("Closing connection.");
    conn.close();
  }
  else
    Serial.println("nConnect failed. Trying again on next iteration.");
}

void loop()
{
  loopSensor();
  transmitValue();
}
