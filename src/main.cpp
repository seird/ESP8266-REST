#include <stdio.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

#include "auth.h"
#include "config.h"
#include "pin.h"
#include "restserver.h"


extern ESP8266WebServer server;


int
init_wifi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(WIFI_RETRY_DELAY);
    }

    return WiFi.status();
}


void
setup(void)
{
    Serial.begin(9600);

    pins_init();

    init_wifi();

    server_config_routing();
    server.begin();
}


void
loop(void)
{
    if (WiFi.status() != WL_CONNECTED) {
        init_wifi();
    }

    server.handleClient();
}
