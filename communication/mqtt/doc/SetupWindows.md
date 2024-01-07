# Setup MQTT Client (Windows)

After the MQTT server (broker) runs in a Linux VM, we only need to install 
the client software for other computers in the network.

## MQTT CLI Cient  

Download ZIP file from [MQTT CLI](https://hivemq.github.io/mqtt-cli/) and 
unzip it in a new folder.

Either add this new folder to the PATH environment variable or change into 
this directory:
```
> cd C:\local\mqtt-cli
```

_Example:_ MQTT CLI Cient Subscribes to Linux MQTT Server
```
> mqtt-cli.exe sub -h 192.168.0.38 -t sensor/temp -d
```

_Example:_ MQTT CLI Cient Publishes to Linux MQTT Server
```
> mqtt-cli.exe pub -h 192.168.0.38 -t sensor/temp -m "-10.0" -d
```

This allows an MQTT connection to be established between the Windows host 
and the Linux VM over the local network.


## References
* [MQTT CLI](https://hivemq.github.io/mqtt-cli/)
* [> Windows Client for MQTT: MQTTX](https://mqttx.app/downloads)
