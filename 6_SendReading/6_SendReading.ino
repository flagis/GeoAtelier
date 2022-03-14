#include <ESP8266WiFi.h>

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
  startLogging();

  connect2Wifi(ssid, pass);

  Serial.print("Connecting to SQL Server @");
  Serial.print(server);
  Serial.print(", Port =");
  Serial.println(server_port);
}

bool measure {
  measurement = 3.14159f; // your measurement
  
  return true;
}

void runInsert()
{
  if (conn.connected())
  {
    // Sample query
    auto INSERT_SQL = String("INSERT INTO geo_atelier.sensor")
                      + " (id, measureTime, measurement) VALUES ('" + WiFi.getChipId() + "', " + millis() + ", " + measurement + " )";
    Serial.println(INSERT_SQL);

    if ( !query_mem.execute(INSERT_SQL.c_str()) )
      Serial.println("Insert error");
    else
      Serial.println("Data Inserted.");
  }
  else
    Serial.println("Disconnected from Server. Can't insert.");
}

void loop()
{
  Serial.println("Connecting...");

  //if (conn.connect(server, server_port, user, password))
  if (conn.connectNonBlocking(server, server_port, user, password) != RESULT_FAIL)
  {
    if (measure())
      runInsert();
    conn.close();                     // close the connection
  }
  else
    Serial.println("\nConnect failed. Trying again on next iteration.");

  delay(60000); // wait a minute
}
