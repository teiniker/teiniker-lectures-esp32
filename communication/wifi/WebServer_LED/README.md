# ESP32 Web Server 


```
$ curl -i http://192.168.0.220/
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 5
Connection: close

hello
```

```
$ curl -i http://192.168.0.220/led/on
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 14
Connection: close

LED status: ON
```

```
curl -i http://192.168.0.220/led/off
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 15
Connection: close

LED status: OFF
```


## References
* [Create A Simple ESP32 Web Server In Arduino IDE](https://lastminuteengineers.com/creating-esp32-web-server-arduino-ide/)

* [GitHub: Arduino-ESP32 - WebServer.h](arduino-esp32/libraries/WebServer/src/WebServer.h)
