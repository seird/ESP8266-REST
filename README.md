Simple REST template server for esp8266 which allows access to the `D0, D1, ..., D10` pins.


## Wifi (+ basic auth) parameters in `include/auth.h`

```c
#ifndef __AUTH_H__
#define __AUTH_H__


#define WIFI_SSID "WifiSSID"
#define WIFI_PASSWD "WifiPassword"

/* Optionally use basic auth to authenticate to the esp */
#define AUTH_USERNAME "Username"
#define AUTH_PASSWD "Password"


#endif // __AUTH_H__
```


# Examples

## Read the value from pin D0

```bash
curl -X 'GET' 'http://{ESP_IP}/pin/D0'
```

```json
{
  "value": 0
}
```

## Write a value to pin D0

```bash
curl -X 'POST' 'http://{ESP_IP}/pin/D0' -d '{"value": 1, "duration": 1000}'
```

## Read the mode of pin D0

```bash
curl -X 'GET' 'http://{ESP_IP}/pin/D0/mode'
```

```json
{
  "mode": 1
}
```

## Set the mode of pin D0

```bash
curl -X 'POST' 'http://{ESP_IP}/pin/D0/mode' -d '{"mode": 0}'
```
