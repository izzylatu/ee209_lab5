<img src="https://github.com/ee209-2020class/ee209-2020class.github.io/blob/master/ExtraInfo/logo.png">

# Lab 5 Notes

Keep a digital log of your work using the readme file where appropriate.


==***Part 1: What is a Timer Peripheral?***==

**Q 1.1:** No, both OCR registers aren't needed in every configuration. The OCR registers are used for match value cases, and we don't always use those when using timers.

**Q 1.2:** Range of a timer is the maximum time interval that the timer can measure, while resolution is the smallest time interval that the timer can measure, ie. 1 timer clock period.

**Q 1.3:** The purpose of the prescaler is that it divides the system clock to create the timer clock, so that we can work with times that are more efficient than the usual 2MHz system clock.

**Q 1.4:** 
**(a)** The prescaler is set to 256.
**(b)** The resolution of Timer0 is 128 microseconds.
**(c)** The maximum time range of Timer0 is 32,640 microseconds.

**Q 1.5:** 
**(a)** TCCR0A

| COM0A1 | COM0A0 | COM0B1 | COM0B0 | -   | -   | WGM01 | WGM00 |
| ------ | ------ | ------ | ------ | --- | --- | ----- | ----- |
| 0      | 0      | 0      | 0      |     |     | 1     | 0     |

**(b)** TCCR0B

| FOC0A | FOC0B | -   | -   | WGM02 | CS02 | CS01 | CS00 |
| ----- | ----- | --- | --- | ----- | ---- | ---- | ---- |
| 0     | 0     | 0   | 0   | 0     | 1    | 0    | 0    |

**(c)** OCR0A

|     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 1   | 0   | 0   | 1   | 1   | 0   | 1   |