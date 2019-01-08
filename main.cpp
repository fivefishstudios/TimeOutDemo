#include "mbed.h"

Timeout timeout;
Serial pc(USBTX, USBRX);  

DigitalOut led(PG_13);
int on = 1;

int timedelayseconds = 10;

void attimeout()
{
  on = 0;
}

int main()
{
  pc.baud(115200);
  timeout.attach(&attimeout, timedelayseconds);

  pc.printf("LED starts blinking...\n");
  while (on)
  {
    led = !led;
    wait(0.2);
  }
  pc.printf("LED stopped blinking after %d seconds. \n", timedelayseconds);

}