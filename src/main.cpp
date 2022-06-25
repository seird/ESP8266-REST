#include <stdio.h>
#include <time.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

#include "auth.h"
#include "config.h"
#include "pin.h"
#include "restserver.h"


extern ESP8266WebServer server;


const char ntp_server[] = "pool.ntp.org";
const long gmt_offset_s = 7200;
const int daylight_offset_s = 0;


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

    configTime(gmt_offset_s, daylight_offset_s, ntp_server);
    while (!time(NULL)) {
        delay(1000);
    }

    // // This part is important to use header values.. otherwise the server won't track the header
    // const char * headerkeys[] = {"X-Access-Token"} ;
    // size_t headerkeyssize = sizeof(headerkeys) / sizeof(char *);
    // server.collectHeaders(headerkeys, headerkeyssize);

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
