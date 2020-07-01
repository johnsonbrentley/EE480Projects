#!/bin/bash
#ACT LED
cd /sys/class/leds/led0
sudo sh -c "echo timer > trigger"
sudo sh -c "echo 50 > delay_on"
sudo sh -c "echo 50 > delay_off"
#PWR LED
cd /sys/class/leds/led1
sudo sh -c "echo timer > trigger"
sudo sh -c "echo 50 > delay_on"
sudo sh -c "echo 50 > delay_off"
