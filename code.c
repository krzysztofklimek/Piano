#include "msp430g2533.h"

//STATES
#define INIT_STATE              0
#define BUTTON_THREE_STATE      1
#define BUTTON_FOUR_STATE       2
#define BUTTON_FIVE_STATE       3
#define BUTTON_SIX_STATE        4
#define SIMPLE_LOW_STATE        5
#define SIMPLE_HIGH_STATE       6
#define CONTINUE_LOW_STATE      7
#define CONTINUE_HIGH_STATE     8


//EVENTS
#define EV_PULS_THREE_DOWN	BIT0
#define EV_PULS_FOUR_DOWN	BIT1
#define EV_PULS_FIVE_DOWN	BIT2
#define EV_PULS_SIX_DOWN	BIT3
#define EV_RESET                BIT4
#define EV_PULS_TWO_DOWN        BIT5


//MACROS
#define SET(ev)		(events |= (ev))
#define RESET(ev)	(events &= ~(ev))
#define TEST(ev)	(events & (ev))

void Config_uC(void);
void Config_Perifericos();


unsigned char states, events;
unsigned char cuenta;
unsigned char cuentaSTATES;
unsigned char cuentaSTATES_control;


void main(void){
 
  Config_uC();
  Config_Perifericos();
  
  
  cuentaSTATES = 4;
  cuentaSTATES_control = 1;
  cuenta = 2;
  events = 0;
  states = INIT_STATE;
  
  while (1){
    __low_power_mode_0();
    
    while(events){
      
      switch(states){
        
        //CASE INIT STATE ---------------------------------------CASE INIT STATE
        case(INIT_STATE):{
          
          if(TEST(EV_PULS_TWO_DOWN)){

            RESET(EV_PULS_TWO_DOWN);
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_HIGH_STATE;
            }
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_HIGH_STATE;
            }
        
     
          }//if(TEST(EV_PULS_TWO_DOWN)
          
          
          if(TEST(EV_PULS_THREE_DOWN)){
            
            RESET(EV_PULS_THREE_DOWN);
            states = BUTTON_THREE_STATE;
            
            P2OUT |= BIT4;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1432;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;

          }//if(TEST(EV_PULS_THREE_DOWN)
          
          
          if(TEST(EV_PULS_FOUR_DOWN)){
            
            RESET(EV_PULS_FOUR_DOWN);
            states = BUTTON_FOUR_STATE;
            
            P2OUT |= BIT5;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1517;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
       
          }//if(TEST(EV_PULS_FOUR_DOWN)
          
          
          if(TEST(EV_PULS_FIVE_DOWN)){
            
            RESET(EV_PULS_FIVE_DOWN);
            states = BUTTON_FIVE_STATE;
            
            P2OUT |= BIT6;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1703;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
            
          }//if(TEST(EV_PULS_FIVE_DOWN)
          
          
          if(TEST(EV_PULS_SIX_DOWN)){
            
            RESET(EV_PULS_SIX_DOWN);
            states = BUTTON_SIX_STATE;
            
            P2OUT |= BIT7;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1911;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
           
          }//if(TEST(EV_PULS_SIX_DOWN)
          
          break;
        }//case(INIT_STATE)
        

        
        //CASE SIMPLE LOW STATE ---------------------------CASE SIMPLE LOW STATE
        case(SIMPLE_LOW_STATE):{
          
          
           if(TEST(EV_PULS_TWO_DOWN)){
              
            RESET(EV_PULS_TWO_DOWN);
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_HIGH_STATE;
            }
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_HIGH_STATE;
            }         
           
          }//if(TEST(EV_PULS_TWO_DOWN)
          
          if(TEST(EV_PULS_THREE_DOWN)){
            
            RESET(EV_PULS_THREE_DOWN);
            states = BUTTON_THREE_STATE;
            
            P2OUT |= BIT4;
            P1IE &= ~(BIT4);
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1432;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
            
           
          }//if(TEST(EV_PULS_THREE_DOWN)
          
          
          if(TEST(EV_PULS_FOUR_DOWN)){
            
            RESET(EV_PULS_FOUR_DOWN);
            states = BUTTON_FOUR_STATE;
            
            P2OUT |= BIT5;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1517;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
   
          }//if(TEST(EV_PULS_FOUR_DOWN)
          
          
          if(TEST(EV_PULS_FIVE_DOWN)){
            
            RESET(EV_PULS_FIVE_DOWN);
            states = BUTTON_FIVE_STATE;
            
            P2OUT |= BIT6;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1703;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
           
          }//if(TEST(EV_PULS_FIVE_DOWN)
          
          
          if(TEST(EV_PULS_SIX_DOWN)){
            
            RESET(EV_PULS_SIX_DOWN);
            states = BUTTON_SIX_STATE;
            
            P2OUT |= BIT7;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1911;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
           
          }//if(TEST(EV_PULS_SIX_DOWN)
          
          break;
        }//case(SIMPLE_ LOW_STATE)
        
                
        //CASE SIMPLE HIGH STATE -------------------------CASE SIMPLE HIGH STATE 
        case(SIMPLE_HIGH_STATE):{
          
          
           if(TEST(EV_PULS_TWO_DOWN)){
              
            RESET(EV_PULS_TWO_DOWN);
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_HIGH_STATE;
            }
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_HIGH_STATE;
            }           
           
          }//if(TEST(EV_PULS_TWO_DOWN)
          
          if(TEST(EV_PULS_THREE_DOWN)){
            
            RESET(EV_PULS_THREE_DOWN);
            states = BUTTON_THREE_STATE;
            
            P2OUT |= BIT4;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0= 956;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
         
          }//if(TEST(EV_PULS_THREE_DOWN)
          
          
          if(TEST(EV_PULS_FOUR_DOWN)){
            
            RESET(EV_PULS_FOUR_DOWN);
            states = BUTTON_FOUR_STATE;
            
            P2OUT |= BIT5;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1012;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
            
          }//if(TEST(EV_PULS_FOUR_DOWN)
          
          
          if(TEST(EV_PULS_FIVE_DOWN)){
            
            RESET(EV_PULS_FIVE_DOWN);
            states = BUTTON_FIVE_STATE;
            
            P2OUT |= BIT6;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1136;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
            
          }//if(TEST(EV_PULS_FIVE_DOWN)
          
          
          if(TEST(EV_PULS_SIX_DOWN)){
            
            RESET(EV_PULS_SIX_DOWN);
            states = BUTTON_SIX_STATE;
            
            P2OUT |= BIT7;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1276;
            
            TA0CTL |= (TACLR);
            TA0CTL &= ~TAIFG;
            TA0CCTL0 &= ~(CCIFG);
            TA0CCTL0 |= CCIE;
            TA0CCR0 = 62499;
           
          }//if(TEST(EV_PULS_SIX_DOWN)
          
          break;
        }//case(SIMPLE_HIGH_STATE)
        
        //**********************************************************
        
        //CASE CONTINUE LOW STATE -----------------------CASE CONTINUE LOW STATE
        case(CONTINUE_LOW_STATE):{
          
          
           if(TEST(EV_PULS_TWO_DOWN)){
              
            RESET(EV_PULS_TWO_DOWN);
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_HIGH_STATE;
            }
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_HIGH_STATE;
            } 
           
          }//if(TEST(EV_PULS_TWO_DOWN)
          
          if(TEST(EV_PULS_THREE_DOWN)){
            
            P2OUT |= BIT4;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1432;
            
            
            RESET(EV_PULS_THREE_DOWN);
            states = BUTTON_THREE_STATE;
           
          }//if(TEST(EV_PULS_THREE_DOWN)
          
          
          if(TEST(EV_PULS_FOUR_DOWN)){
            
            P2OUT |= BIT5;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1517;
            
            
            RESET(EV_PULS_FOUR_DOWN);
            states = BUTTON_FOUR_STATE;
           
          }//if(TEST(EV_PULS_FOUR_DOWN)
          
          
          if(TEST(EV_PULS_FIVE_DOWN)){
            
            P2OUT |= BIT6;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1703;
            
            
            RESET(EV_PULS_FIVE_DOWN);
            states = BUTTON_FIVE_STATE;
           
          }//if(TEST(EV_PULS_FIVE_DOWN)
          
          
          if(TEST(EV_PULS_SIX_DOWN)){
            
            P2OUT |= BIT7;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1911;
            
            
            RESET(EV_PULS_SIX_DOWN);
            states = BUTTON_SIX_STATE;
           
          }//if(TEST(EV_PULS_SIX_DOWN)
          
          break;
        }//case(CONTINUE_LOW_STATE)
        
        
        
        //CASE CONTINUE HIGH STATE -----------------_---CASE CONTINUE HIGH STATE
        case(CONTINUE_HIGH_STATE):{
          
          
           if(TEST(EV_PULS_TWO_DOWN)){
              
            RESET(EV_PULS_TWO_DOWN);
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) == 0)){
              states = SIMPLE_HIGH_STATE;
            }
            
            if((P1OUT & BIT6) == 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_LOW_STATE;
            }
            
            if((P1OUT & BIT6) != 0 && ((P1OUT & BIT0) != 0)){
              states = CONTINUE_HIGH_STATE;
            } 
           
          }//if(TEST(EV_PULS_TWO_DOWN)
          
          if(TEST(EV_PULS_THREE_DOWN)){
            
            P2OUT |= BIT4;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0= 956;
            
            
            RESET(EV_PULS_THREE_DOWN);
            states = BUTTON_THREE_STATE;
           
          }//if(TEST(EV_PULS_THREE_DOWN)
          
          
          if(TEST(EV_PULS_FOUR_DOWN)){
            
            P2OUT |= BIT5;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1012;
            
            
            RESET(EV_PULS_FOUR_DOWN);
            states = BUTTON_FOUR_STATE;
           
          }//if(TEST(EV_PULS_FOUR_DOWN)
          
          
          if(TEST(EV_PULS_FIVE_DOWN)){
            
            P2OUT |= BIT6;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1136;
            
            
            RESET(EV_PULS_FIVE_DOWN);
            states = BUTTON_FIVE_STATE;
           
          }//if(TEST(EV_PULS_FIVE_DOWN)
          
          
          if(TEST(EV_PULS_SIX_DOWN)){
            
            P2OUT |= BIT7;
            
            TA1CCTL0=OUTMOD_4;
            TA1CCR0=1276;
            
            
            RESET(EV_PULS_SIX_DOWN);
            states = BUTTON_SIX_STATE;
           
          }//if(TEST(EV_PULS_SIX_DOWN)
          
          break;
        }//case(CONTINUE_HIGH_STATE)
        
        //**********************************************************
        
        
        
        //CASE BUTTOM THREE STATE ----------------------------------------
        case(BUTTON_THREE_STATE): {
          
          if(TEST(EV_RESET)){
            
            RESET(EV_RESET);
            
            if((P1OUT & BIT6) == 0){
              states = SIMPLE_LOW_STATE;
            }
            else{
              states = SIMPLE_HIGH_STATE;
            }
            
            
            P2OUT &= ~BIT4;
            
            TA1CCTL0=OUTMOD_5;
            TA1CCR0=0;
            
            TA0CCTL0 &= ~CCIE;
            TA0CTL &= ~TAIFG;
            TA0CCR0 = 0;
            
          }//if(TEST(EV_RESET))          
          break;
        }//case(BUTTOM_THREE_STATE)
        
        
        //CASE BUTTOM FOUR STATE ----------------------------------------
        case(BUTTON_FOUR_STATE): {
          
          if(TEST(EV_RESET)){
            
            RESET(EV_RESET);
            
            if((P1OUT & BIT6) == 0){
              states = SIMPLE_LOW_STATE;
            }
            else{
              states = SIMPLE_HIGH_STATE;
            }
            
            P2OUT &= ~BIT5;
            
            TA1CCTL0=OUTMOD_5;
            TA1CCR0=0;
            
            TA0CCTL0 &= ~CCIE;
            TA0CTL &= ~TAIFG;
            TA0CCR0 = 0;
     
          }//if(TEST(EV_RESET))          
          break;
        }//case(BUTTOM_FOUR_STATE)
        
        
        //CASE HIGH FIVE STATE ----------------------------------------
        case(BUTTON_FIVE_STATE): {
          
          if(TEST(EV_RESET)){
            
            RESET(EV_RESET);
            
            if((P1OUT & BIT6) == 0){
              states = SIMPLE_LOW_STATE;
            }
            else{
              states = SIMPLE_HIGH_STATE;
            }
            
            P2OUT &= ~BIT6;
            
            TA1CCTL0=OUTMOD_5;
            TA1CCR0=0;
            
            TA0CCTL0 &= ~CCIE;
            TA0CTL &= ~TAIFG;
            TA0CCR0 = 0;
   
          }//if(TEST(EV_RESET))          
          break;
        }//case(BUTTOM_FIVE_STATE)
        
        
        //CASE BUTTOM SIX STATE ----------------------------------------
        case(BUTTON_SIX_STATE): {
          
          if(TEST(EV_RESET)){
            
            RESET(EV_RESET);
            
            
            if((P1OUT & BIT6) == 0){
              states = SIMPLE_LOW_STATE;
            }
            else{
              states = SIMPLE_HIGH_STATE;
            }
            
            P2OUT &= ~BIT7;
            
            TA1CCTL0=OUTMOD_5;
            TA1CCR0=0;
            
            TA0CCTL0 &= ~CCIE;
            TA0CTL &= ~TAIFG;
            TA0CCR0 = 0;
              
          }//if(TEST(EV_RESET))          
          break;
        }//case(BUTTOM_SIX_STATE)
      
      }// switch (states)
      
    }// while (events)
    
  }// while (1)
  
}// void main(void)

void Config_uC(void){

        WDTCTL = WDTPW + WDTHOLD;		
	DCOCTL = 0;				
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
}


void Config_Perifericos(void) {
  
      //DIODS (LED3, LED4) BBP
      P2DIR |= BIT4|BIT5;
      P2OUT &= ~(BIT4|BIT5);
      
      //DIODS (LED5, LED6) BBP
      P2DIR |= BIT6|BIT7;
      P2SEL &= ~(BIT6|BIT7);
      P2SEL2 &= ~(BIT6|BIT7);
      P2OUT &= ~(BIT6|BIT7);
      
      //DIODS (LED1, LED2) Lunch Pad
      P1DIR = BIT0 | BIT6;
      P1OUT &= ~(BIT0 | BIT6);
      
      //BUTTON INTERRUPTION settings BBP
      P2DIR &= ~(BIT1|BIT2|BIT3);
      P2REN = (BIT1|BIT2|BIT3);
      P2OUT |= BIT1|BIT2|BIT3;
      P2IES |= BIT1|BIT2|BIT3;
      P2IFG &= ~(BIT1|BIT2|BIT3);
      P2IE |= BIT1|BIT2|BIT3;
      
      //BUTTON INTERRUPTION settings BBP and Lunch Pad
      P1DIR &= ~(BIT4|BIT3);   // entry
      P1REN = BIT4 | BIT3;     //resistance active
      P1OUT |= BIT4|BIT3;      //pulup
      P1IES |= BIT4|BIT3;      // opadaj¹ca krawêdŸ powoduje przerwanie
      P1IFG &= ~(BIT4|BIT3);   // status przerwy 0- nie oczekuje na pin ??
      P1IE |= BIT4|BIT3;       //w³¹czenie przerwania
      
      //SPEAKER
      P2DIR |= BIT0;
      P2SEL |= BIT0;
      P2SEL2 &= ~BIT0;
      
      //TIMER 1 (speaker)
      TA1CTL = MC_1|TACLR|TASSEL_2;
      
      //TIMER 0 (interruptions)
      TA0CTL = TASSEL_2 + ID_3 + MC_1;
      TA0CCR0 = 0;
      TA0CCTL0 &= ~ CCIFG;  //clean innterruption flag
      //TA0CCTL0 |= CCIE;     //interruption enable
      
}//Config_Perifericos(void)


#pragma vector = WDT_VECTOR
__interrupt void RTI_WD(void) {
  WDTCTL = WDTPW + WDTHOLD;
 
  P1IFG &= ~(BIT4);
  P1IE |= (BIT4);
  
  P1IFG &= ~(BIT3);
  P1IE |= (BIT3);
  
  P2IFG &= ~(BIT1);
  P2IE |= (BIT1);
  
  P2IFG &= ~(BIT2);
  P2IE |= (BIT2);
  
  P2IFG &= ~(BIT3); 
  P2IE |= (BIT3);
}


//--------------------------------------interruption PORT 1 
#pragma vector = PORT1_VECTOR
__interrupt void RTI_P1(void){
  
  
  //Ÿród³o przerwania S2    
  if ((P1IFG & BIT3) != 0) {
        
    P1IFG &= ~(BIT3);
    P1IE &= ~(BIT3);
    
    //wy³¹czenie przycisku na 30ms    
    WDTCTL = WDT_MDLY_32;
    IFG1 &= ~(WDTIFG);
    IE1 |= WDTIE;
    
    if ((P1IES & BIT3) != 0){ //tutaj w³¹czyæ licznik i trzymac i jak nowa quenta dojdzie do 4 to wlaczyc swiartlo a jesli nie to zielone 
      
      TA0CTL |= (TACLR);
      TA0CTL &= ~TAIFG;
      TA0CCTL0 &= ~(CCIFG);
      TA0CCTL0 |= CCIE;
      TA0CCR0 = 62499;
      
   

    }
    else{
      
      TA0CCTL0 &= ~CCIE;
      TA0CTL &= ~TAIFG;
      TA0CCR0 = 0;
      
      if(cuentaSTATES > cuentaSTATES_control){
        P1OUT ^= BIT6;
      }
      
      cuentaSTATES_control = 1;
      
      events = 0;
      SET(EV_PULS_TWO_DOWN);
    }
    
    P1IES ^= BIT3;   
  }
  
  //Ÿród³o przerwania S3
  if ((P1IFG & BIT4) != 0) {
  
    P1IFG &= ~(BIT4);
    P1IE &= ~(BIT4);
    
    //wy³¹czenie przycisku na 30ms
    WDTCTL = WDT_MDLY_32;
    IFG1 &= ~(WDTIFG);
    IE1 |= WDTIE;
    
    if ((P1IES & BIT4) != 0){
      events = 0;
      SET(EV_PULS_THREE_DOWN);
    }
    
    else{
      if((P1OUT & BIT0) != 0){
        events = 0; 
        SET(EV_RESET);
      }
    }

    P1IES ^= BIT4;
  }
  
  if (events) {
	__low_power_mode_off_on_exit();
  } // if (eventos)
}

//--------------------------------------interruption PORT 2
#pragma vector = PORT2_VECTOR
__interrupt void RTI_P2(void){

    //Ÿród³o przerwania S4
  if ((P2IFG & BIT1) != 0) {
    
    P2IFG &= ~(BIT1);
    P2IE &= ~(BIT1);
    
    //wy³¹czenie przycisku na 30ms    
    WDTCTL = WDT_MDLY_32;
    IFG1 &= ~(WDTIFG);
    IE1 |= WDTIE;
    
    if ((P2IES & BIT1) != 0){
      events = 0;
      SET(EV_PULS_FOUR_DOWN);
    }

    else{
      if((P1OUT & BIT0) != 0){
        events = 0; 
        SET(EV_RESET);
      }
    }
    
    P2IES ^= BIT1;
  }

  //Ÿród³o przerwania S5
  if ((P2IFG & BIT2) != 0) {
    
        
    P2IFG &= ~(BIT2);
    P2IE &= ~(BIT2);
    
    //wy³¹czenie przycisku na 30ms    
    WDTCTL = WDT_MDLY_32;
    IFG1 &= ~(WDTIFG);
    IE1 |= WDTIE;
    
    
    if ((P2IES & BIT2) != 0){
      events = 0;
      SET(EV_PULS_FIVE_DOWN);
    }
    
    else{
      if((P1OUT & BIT0) != 0){
        events = 0; 
        SET(EV_RESET);
      }
    }
    
    P2IES ^= BIT2;
  }
  
  //Ÿród³o przerwania S6
  if ((P2IFG & BIT3) != 0) {
    
    P2IFG &= ~(BIT3);
    P2IE &= ~(BIT3);
    
    //wy³¹czenie przycisku na 30ms 
    WDTCTL = WDT_MDLY_32;
    IFG1 &= ~(WDTIFG);
    IE1 |= WDTIE;

    if ((P2IES & BIT3) != 0){
      events = 0;
      SET(EV_PULS_SIX_DOWN);
    }

    else{
      if((P1OUT & BIT0) != 0){
        events = 0; 
        SET(EV_RESET);
      }
    }
    
    P2IES ^= BIT3;
  }
  if (events) {
    __low_power_mode_off_on_exit();
  } // if (eventos)
}

//--------------------------------------interruption TIMER
#pragma vector = TIMER0_A0_VECTOR
__interrupt void RTI_T0_A0(void) {

  cuentaSTATES_control++;
  
  static unsigned char cont=1;    
  if ((cont==cuenta) && (P1IN & BIT3) != 0 && (P1OUT & BIT0) == 0){ //i s2 nie wciœniety trzeba dodac 
        events = 0; 
	SET(EV_RESET);
        cont=1;
        cuentaSTATES_control = 1;
  }
  else cont++; 
  
    if ((cuentaSTATES == cuentaSTATES_control)&& (P1IN & BIT3) == 0){ 
        P1OUT ^= BIT0;
        cont=1;
    }
	
    
    if (events) {
		__low_power_mode_off_on_exit();
    } // if (eventos)

} // __interrupt void RTI_T0_A0(void)