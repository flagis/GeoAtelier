#include <ESP8266WiFi.h>

#include "logging.h"
#include "credentials.h"
#include "dbSettings.h"
#include "wifi.h"
#include "dateTime.h"
#include "gps.h"

#include <MySQL_Generic.h>

void transmitValue(float value);

//#include "sensors/ADXL345.h"
//#include "sensors/BMP085.h"
//#include "sensors/BMP180.h"
//#include "sensors/buttons.h"
//#include "sensors/HMC5883.h"
//#include "sensors/HX711.h"
#include "sensors/HCSR04.h"

MySQL_Connection conn((Client *)&client);
auto query_mem = MySQL_Query(&conn);

void setup()
{
  setupLogging();
  setupGPS();
  setupSensors();

  connect2Wifi(ssid, pass);
}

void transmitValue(float value)
{
  Serial.print("Connecting to SQL Server @");
  Serial.print(server);
  Serial.print(", Port =");
  Serial.println(server_port);

  if (conn.connectNonBlocking(server, server_port, user, password) != RESULT_FAIL)
  {
    char hexString[20];
    itoa(ESP.getChipId(), hexString, 16); // HEX ID of chip (last 3 digits of MAC)

    // Sample query
    auto INSERT_SQL = String("INSERT INTO geo_atelier.sensor")
                      + " (id, measureDateTime, location, measurement) VALUES ('"
                      + hexString + "', '"
                      + getISO8601localDateTime()
                      + "', PointFromText('POINT(" + lng + " " + lat + ")'), "
                      + value + " )";
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
  loopGPS();
  loopSensors();
}
