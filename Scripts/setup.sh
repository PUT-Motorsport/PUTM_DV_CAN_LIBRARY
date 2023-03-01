
#!/bin/bash

CAN_VENDOR_ID="0483"
CAN_MODEL_ID="5740"
CAN_TTY_PATH=""


for TTY in /dev/ttyACM* ; do
    VENDOR_ID=$(udevadm info $TTY | grep -oP "ID_VENDOR_ID=\K.*")
    if [ "$CAN_VENDOR_ID" = "$VENDOR_ID" ]; then
        MODEL_ID=$(udevadm info $TTY | grep -oP "ID_MODEL_ID=\K.*")
        if [ "$CAN_MODEL_ID" = "$MODEL_ID" ]; then
            CAN_TTY_PATH=$TTY
            break
        fi
    fi
done

if [ -z "$CAN_TTY_PATH" ]; then
    echo "[CANscript] USB-CAN is not connected"
    exit 1
else
    echo "[CANscript] $CAN_TTY_PATH is the USB-CAN dongle"
    modprobe can
    modprobe can-raw
    modprobe slcan
    
    #link serial interface with a virtual CAN device
    slcand -s8 -o $CAN_TTY_PATH slcan0 
    sleep 1
    
    #bring network interface up
    ifconfig slcan0 up && echo "[CANscript] slcan0 is up and running"
    exit 0
fi

