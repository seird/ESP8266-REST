#include <stdio.h>
#include <time.h>

#include "restserver.h"


extern ESP8266WebServer server;


void
get_root()
{
    char date[50];
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(date, 50, "%d %B %Y %H:%M:%S ", timeinfo);

    char message[100];
    sprintf(message, "%s -- %ld seconds since boot.", date, millis()/1000);
    server.send(200, "text/html", message);
}
