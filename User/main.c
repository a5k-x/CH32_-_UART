#include <ch32v00x.h>
#include <stdbool.h>

#include "system.h"

int main(void) {
    // USARTx_CFG();
    system_initSystick();
    Delay_Init();
    leds_init();

    leds_led1_on();
    leds_led2_off();
    leds_led3_off();

    __enable_irq();
    while (true)
    {
        if (system_isSysTick())
        {
            // Delay_Us(1000);
            //  UartBufferSend("Hello from Pallav Aggarwal\r\n", 28);
            leds_led1_toggle();
            leds_led2_toggle();
            leds_led3_toggle();
        }
    }
}

void USARTx_CFG(void) {
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };
    USART_InitTypeDef USART_InitStructure = { 0 };
    NVIC_InitTypeDef NVIC_InitStructure = { 0 };

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1,
            ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl =
            USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    ;

    USART_Cmd(USART1, ENABLE);
}

void UartBufferSend(uint8_t* buffer, uint16_t length) {
    uint16_t tmp = 0;
    for (tmp = 0; tmp < length; tmp++) {
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) /* waiting for sending finish */
        {
        }
        USART_SendData(USART1, buffer[tmp]);
    }

}
