#pragma once

#include <time.h>
#include <chrono>

bool getLocalTime(struct tm * info, uint32_t ms = 5000)
{
  uint32_t start = millis();
  time_t now;
  while ((millis() - start) <= ms) {
    time(&now);
    localtime_r(&now, info);
    if (info->tm_year > (2016 - 1900)) {
      return true;
    }
    delay(10);
  }
  return false;
}

String getISO8601localDateTime()
{ 
  struct tm timeinfo;
  getLocalTime(&timeinfo);
  
  char buffer [80];
  sprintf(buffer, "%04d-%02d-%02dT%02d:%02d:%02d.%03d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, millis());
  return String(buffer);
}
