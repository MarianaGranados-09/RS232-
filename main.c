#include <18f4550.h>
#include <string.h>
#include <stdlib.h>
#fuses INTRC,NOPROTECT,NOWDT,NOLVP,PLL1,CPUDIV1
#use delay(crystal=8M)
#use rs232(rcv=pin_C7,xmit=pin_C6,baud=9600,bits=8,parity=n, stream = GSM)
#include <lcd.c>
char ch;
int flag=0;

#int_rda
void isr_rda()
{
   ch=fgetc(GSM);
   //delay_ms(500);
   output_high(pin_a0);
   flag=1;
}

void main()
{
   delay_ms(500);
   lcd_init();
   enable_interrupts(global);
   enable_interrupts(int_rda);
   while(True)
   {
     
      if(flag==1)
      {
         delay_ms(500);
         printf(lcd_putc,"\f Value:  %c",ch );
         //fprintf(GSM,"%c", ch);
         delay_ms(500);
         //Printf(lcd_putc,"\f");
         output_low(pin_a0);
         delay_ms(1000);

      }
      
   }

}
