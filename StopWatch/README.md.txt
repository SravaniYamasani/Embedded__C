By connecting two 7-segment displays to an MSP430 Launchpad board and using the on-board push-button switch (or off-board) to make this system replicate a stopwatch.

0. On bootup, the LEDs should show 0.0
1. On first switch press, the timer should start up-counting and display 0.1, 0.2, 0.3, etc. seconds. When 9.9 is reached, the next number displayed should be 0.0 and continue up-counting from there.
2. On the next (second) button press, the timer should stop and the LED display stay at the current number.
3. On the next (third) button press, the LED displays should be set to display 0.0. (basically, be at step 0 above)