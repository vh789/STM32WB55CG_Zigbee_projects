# STM32WB55CG_Zigbee_projects
This Repo holds my trials with WeAct STM32WB55CG board. The applications focus on Zigbee - Homassistant - Zigbee2MQTT integration.

## History
As can be seen from [2,3], it was planned to integrate applications with this controller into Tuya Smarthome network. This proved not [6] and was not longer followed as target.
Instead, the controller should now be integrated into a Homeassistant/Zigbee2MQTT network, which was successfull.

## Targets
The project is still in development and far from finished.
The targets are:
-RGB-LED-Strip control (done)
-Sensordata transmit (e.g. temperature, soil/air moisture)

## Harware
The WeAct STM32WB55CG board is used (see [7]).
Around the board, an existing PCB was used as breakout to connect buttins, switches, LEDs etc.
When the application is more fixed, a PCB design will be added.
For prototyping, Schematics will also be added here in the future.

## Supporting Material
[1] https://community.st.com/t5/stm32-mcus-wireless/stm32wb55-color-control-cluster-gives-an-assertion-error/td-p/117097
[2] https://community.st.com/t5/stm32-mcus-wireless/stm32wb55cg-zigbee-connection-tuya-smartlife/td-p/717976
[3] https://community.st.com/t5/stm32-mcus-wireless/stm32wb55cg-zigbee-connection-tuya-smartlife-with-st-example/td-p/720187
[4] https://community.st.com/t5/stm32-mcus-wireless/stm32wb55cg-zigbee-connection-with-custom-project/td-p/724938
[5] https://community.st.com/t5/stm32-mcus-wireless/stm32wb55cg-zigbee-led-controller-color/td-p/727871
[6] https://community.st.com/t5/stm32-mcus-wireless/stm32wb5mm-dk-connecting-to-tuya-gateway-with-zigbee-part-2/m-p/725631#M21348
[7] https://github.com/WeActStudio/WeActStudio.STM32WB55CoreBoard
[8] https://github.com/mesutkilic/DHT11-STM32-Library
