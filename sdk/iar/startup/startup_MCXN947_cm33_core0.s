; -------------------------------------------------------------------------
;  @file:    startup_MCXN947_cm33_core0.s
;  @purpose: CMSIS Cortex-M33 Core Device Startup File
;            MCXN947_cm33_core0
;  @version: 1.0
;  @date:    2021-8-3
;  @build:   b220523
; -------------------------------------------------------------------------
;
; Copyright 1997-2016 Freescale Semiconductor, Inc.
; Copyright 2016-2022 NXP
; All rights reserved.
;
; SPDX-License-Identifier: BSD-3-Clause
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table
        PUBLIC  __vector_table_0x1c
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA

__iar_init$$done:              ; The vector table is not needed
                      ; until after copy initialization is done

__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler

        DCD     NMI_Handler                                   ;NMI Handler
        DCD     HardFault_Handler                             ;Hard Fault Handler
        DCD     MemManage_Handler                             ;MPU Fault Handler
        DCD     BusFault_Handler                              ;Bus Fault Handler
        DCD     UsageFault_Handler                            ;Usage Fault Handler
__vector_table_0x1c
        DCD     SecureFault_Handler                           ;Secure Fault Handler
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     SVC_Handler                                   ;SVCall Handler
        DCD     DebugMon_Handler                              ;Debug Monitor Handler
        DCD     0                                             ;Reserved
        DCD     PendSV_Handler                                ;PendSV Handler
        DCD     SysTick_Handler                               ;SysTick Handler

                                                              ;External Interrupts
        DCD     OR_IRQHandler                                 ;OR IRQ
        DCD     DMA3_0_CH0_IRQHandler                         ;DMA3_0_CH0 error or transfer complete
        DCD     DMA3_0_CH1_IRQHandler                         ;DMA3_0_CH1 error or transfer complete
        DCD     DMA3_0_CH2_IRQHandler                         ;DMA3_0_CH2 error or transfer complete
        DCD     DMA3_0_CH3_IRQHandler                         ;DMA3_0_CH3 error or transfer complete
        DCD     DMA3_0_CH4_IRQHandler                         ;DMA3_0_CH4 error or transfer complete
        DCD     DMA3_0_CH5_IRQHandler                         ;DMA3_0_CH5 error or transfer complete
        DCD     DMA3_0_CH6_IRQHandler                         ;DMA3_0_CH6 error or transfer complete
        DCD     DMA3_0_CH7_IRQHandler                         ;DMA3_0_CH7 error or transfer complete
        DCD     DMA3_0_CH8_IRQHandler                         ;DMA3_0_CH8 error or transfer complete
        DCD     DMA3_0_CH9_IRQHandler                         ;DMA3_0_CH9 error or transfer complete
        DCD     DMA3_0_CH10_IRQHandler                        ;DMA3_0_CH10 error or transfer complete
        DCD     DMA3_0_CH11_IRQHandler                        ;DMA3_0_CH11 error or transfer complete
        DCD     DMA3_0_CH12_IRQHandler                        ;DMA3_0_CH12 error or transfer complete
        DCD     DMA3_0_CH13_IRQHandler                        ;DMA3_0_CH13 error or transfer complete
        DCD     DMA3_0_CH14_IRQHandler                        ;DMA3_0_CH14 error or transfer complete
        DCD     DMA3_0_CH15_IRQHandler                        ;DMA3_0_CH15 error or transfer complete
        DCD     GPIO00_IRQHandler                             ;GPIO0 interrupt 0
        DCD     GPIO01_IRQHandler                             ;GPIO0 interrupt 1
        DCD     GPIO10_IRQHandler                             ;GPIO1 interrupt 0
        DCD     GPIO11_IRQHandler                             ;GPIO1 interrupt 1
        DCD     GPIO20_IRQHandler                             ;GPIO2 interrupt 0
        DCD     GPIO21_IRQHandler                             ;GPIO2 interrupt 1
        DCD     GPIO30_IRQHandler                             ;GPIO3 interrupt 0
        DCD     GPIO31_IRQHandler                             ;GPIO3 interrupt 1
        DCD     GPIO40_IRQHandler                             ;GPIO4 interrupt 0
        DCD     GPIO41_IRQHandler                             ;GPIO4 interrupt 1
        DCD     GPIO50_IRQHandler                             ;GPIO5 interrupt 0
        DCD     GPIO51_IRQHandler                             ;GPIO5 interrupt 1
        DCD     UTICK0_IRQHandler                             ;Micro-Tick Timer interrupt
        DCD     MRT0_IRQHandler                               ;Multi-Rate Timer interrupt
        DCD     CTIMER0_IRQHandler                            ;Standard counter/timer 0 interrupt
        DCD     CTIMER1_IRQHandler                            ;Standard counter/timer 1 interrupt
        DCD     SCT0_IRQHandler                               ;SCTimer/PWM interrupt
        DCD     CTIMER2_IRQHandler                            ;Standard counter/timer 2 interrupt
        DCD     LP_FLEXCOMM0_IRQHandler                       ;LP_FLEXCOMM0 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM1_IRQHandler                       ;LP_FLEXCOMM1 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM2_IRQHandler                       ;LP_FLEXCOMM2 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM3_IRQHandler                       ;LP_FLEXCOMM3 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM4_IRQHandler                       ;LP_FLEXCOMM4 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM5_IRQHandler                       ;LP_FLEXCOMM5 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM6_IRQHandler                       ;LP_FLEXCOMM6 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM7_IRQHandler                       ;LP_FLEXCOMM7 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM8_IRQHandler                       ;LP_FLEXCOMM8 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     LP_FLEXCOMM9_IRQHandler                       ;LP_FLEXCOMM9 (LPSPI interrupt or LPI2C interrupt or LPUART Receive/Transmit interrupt)
        DCD     ADC0_IRQHandler                               ;Analog-to-Digital Converter 0 - General Purpose interrupt
        DCD     ADC1_IRQHandler                               ;Analog-to-Digital Converter 1 - General Purpose interrupt
        DCD     PINT_IRQHandler                               ;Pin Interrupt Pattern Match Interrupt
        DCD     MICFIL_IRQHandler                             ;Microphone Interface interrupt
        DCD     Reserved65_IRQHandler                         ;xxx Interrupt 65
        DCD     USB0_FS_IRQHandler                            ;Universal Serial Bus - Full Speed interrupt
        DCD     USB0_DCD_IRQHandler                           ;Universal Serial Bus - Device Charge Detect interrupt
        DCD     RTC_IRQHandler                                ;RTC Subsystem interrupt (RTC interrupt or Wake timer interrupt)
        DCD     SMARTDMA_IRQHandler                           ;SmartDMA_IRQ
        DCD     MAILBOX0_IRQHandler                           ;Inter-CPU Mailbox interrupt0 for CPU0 Inter-CPU Mailbox interrupt1 for CPU1
        DCD     CTIMER3_IRQHandler                            ;Standard counter/timer 3 interrupt
        DCD     CTIMER4_IRQHandler                            ;Standard counter/timer 4 interrupt
        DCD     OSTimer_IRQHandler                            ;OS event timer interrupt
        DCD     FLEXSPI_IRQHandler                            ;Flexible Serial Peripheral Interface interrupt
        DCD     SAI0_IRQHandler                               ;Serial Audio Interface 0 interrupt
        DCD     SAI1_IRQHandler                               ;Serial Audio Interface 1 interrupt
        DCD     USDHC_IRQHandler                              ;Ultra Secured Digital Host Controller interrupt
        DCD     FLEXCAN0_IRQHandler                           ;Controller Area Network 0 interrupt
        DCD     FLEXCAN1_IRQHandler                           ;Controller Area Network 1 interrupt
        DCD     SPI_FILER0_IRQHandler                         ;SPI_Filer interrupt
        DCD     ESPI_IRQHandler                               ;eSPI interrupt
        DCD     USB1_HS_PHY_IRQHandler                        ;USBHS DCD or USBHS Phy interrupt
        DCD     USB1_HS_IRQHandler                            ;USB High Speed OTG Controller interrupt
        DCD     SEC_HYPERVISOR_CALL_IRQHandler                ;AHB Secure Controller hypervisor call interrupt
        DCD     TRO_IRQHandler                                ;Tracking Ring Oscillator interrupt (window expiration interrupt or window expiration maximum or window expiration minimum interrupt)
        DCD     PLU_IRQHandler                                ;Programmable Logic Unit interrupt
        DCD     FME_IRQHandler                                ;Frequency Measurement interrupt
        DCD     SEC_VIO_IRQHandler                            ;Secure violation interrupt (Memory Block Checker interrupt or secure AHB matrix violation interrupt)
        DCD     CSS_IRQHandler                                ;CSS interrupt
        DCD     PKC_IRQHandler                                ;PKC interrupt
        DCD     PUF_IRQHandler                                ;Physical Unclonable Function interrupt
        DCD     PQ_IRQHandler                                 ;Power Quad interrupt
        DCD     DMA3_1_CH0_IRQHandler                         ;DMA3_1_CH0 error or transfer complete
        DCD     DMA3_1_CH1_IRQHandler                         ;DMA3_1_CH1 error or transfer complete
        DCD     DMA3_1_CH2_IRQHandler                         ;DMA3_1_CH2 error or transfer complete
        DCD     DMA3_1_CH3_IRQHandler                         ;DMA3_1_CH3 error or transfer complete
        DCD     DMA3_1_CH4_IRQHandler                         ;DMA3_1_CH4 error or transfer complete
        DCD     DMA3_1_CH5_IRQHandler                         ;DMA3_1_CH5 error or transfer complete
        DCD     DMA3_1_CH6_IRQHandler                         ;DMA3_1_CH6 error or transfer complete
        DCD     DMA3_1_CH7_IRQHandler                         ;DMA3_1_CH7 error or transfer complete
        DCD     DMA3_1_CH8_IRQHandler                         ;DMA3_1_CH8 error or transfer complete
        DCD     DMA3_1_CH9_IRQHandler                         ;DMA3_1_CH9 error or transfer complete
        DCD     DMA3_1_CH10_IRQHandler                        ;DMA3_1_CH10 error or transfer complete
        DCD     DMA3_1_CH11_IRQHandler                        ;DMA3_1_CH11 error or transfer complete
        DCD     DMA3_1_CH12_IRQHandler                        ;DMA3_1_CH12 error or transfer complete
        DCD     DMA3_1_CH13_IRQHandler                        ;DMA3_1_CH13 error or transfer complete
        DCD     DMA3_1_CH14_IRQHandler                        ;DMA3_1_CH14 error or transfer complete
        DCD     DMA3_1_CH15_IRQHandler                        ;DMA3_1_CH15 error or transfer complete
        DCD     CODE_WDG0_IRQHandler                          ;Code Watchdog Timer 0 interrupt
        DCD     CODE_WDG1_IRQHandler                          ;Code Watchdog Timer 1 interrupt
        DCD     I3C0_IRQHandler                               ;Improved Inter Integrated Circuit interrupt 0
        DCD     I3C1_IRQHandler                               ;Improved Inter Integrated Circuit interrupt 1
        DCD     NEUTRON_IRQHandler                            ;NEUTRON Mini interrupt
        DCD     GDET_IRQHandler                               ;Digital Glitch Detect 0 interrupt  or Digital Glitch Detect 1 interrupt
        DCD     VBAT0_IRQHandler                              ;VBAT interrupt( VBAT interrupt or digital tamper interrupt)
        DCD     EWM0_IRQHandler                               ;External Watchdog Monitor interrupt
        DCD     TSI_END_OF_SCAN_IRQHandler                    ;TSI End of Scan interrupt
        DCD     TSI_OUT_OF_SCAN_IRQHandler                    ;TSI Out of Scan interrupt
        DCD     EMVSIM0_IRQHandler                            ;EMVSIM0 interrupt
        DCD     EMVSIM1_IRQHandler                            ;EMVSIM1 interrupt
        DCD     FLEXIO_IRQHandler                             ;Flexible Input/Output interrupt
        DCD     DAC0_IRQHandler                               ;Digital-to-Analog Converter 0 - General Purpose interrupt
        DCD     DAC1_IRQHandler                               ;Digital-to-Analog Converter 1 - General Purpose interrupt
        DCD     HPDAC0_IRQHandler                             ;14-bit Digital-to-Analog Converter interrupt
        DCD     HSCMP0_IRQHandler                             ;High-Speed comparator0 interrupt
        DCD     HSCMP1_IRQHandler                             ;High-Speed comparator1 interrupt
        DCD     HSCMP2_IRQHandler                             ;High-Speed comparator2 interrupt
        DCD     FLEXPWM0_RELOAD_ERROR_IRQHandler              ;FlexPWM0_reload_error interrupt
        DCD     FLEXPWM0_FAULT_IRQHandler                     ;FlexPWM0_fault interrupt
        DCD     FLEXPWM0_SUBMODULE0_IRQHandler                ;FlexPWM0 Submodule 0 capture/compare/reload interrupt
        DCD     FLEXPWM0_SUBMODULE1_IRQHandler                ;FlexPWM0 Submodule 1 capture/compare/reload interrupt
        DCD     FLEXPWM0_SUBMODULE2_IRQHandler                ;FlexPWM0 Submodule 2 capture/compare/reload interrupt
        DCD     FLEXPWM0_SUBMODULE3_IRQHandler                ;FlexPWM0 Submodule 3 capture/compare/reload interrupt
        DCD     FLEXPWM1_RELOAD_ERROR_IRQHandler              ;FlexPWM1_reload_error interrupt
        DCD     FLEXPWM1_FAULT_IRQHandler                     ;FlexPWM1_fault interrupt
        DCD     FLEXPWM1_SUBMODULE0_IRQHandler                ;FlexPWM1 Submodule 0 capture/compare/reload interrupt
        DCD     FLEXPWM1_SUBMODULE1_IRQHandler                ;FlexPWM1 Submodule 1 capture/compare/reload interrupt
        DCD     FLEXPWM1_SUBMODULE2_IRQHandler                ;FlexPWM1 Submodule 2 capture/compare/reload interrupt
        DCD     FLEXPWM1_SUBMODULE3_IRQHandler                ;FlexPWM1 Submodule 3 capture/compare/reload interrupt
        DCD     ENC0_COMPARE_IRQHandler                       ;ENC0_Compare interrupt
        DCD     ENC0_HOME_IRQHandler                          ;ENC0_Home interrupt
        DCD     ENC0_WDG_SAB_IRQHandler                       ;ENC0_WDG_IRQ/SAB interrupt
        DCD     ENC0_IDX_IRQHandler                           ;ENC0_IDX interrupt
        DCD     ENC1_COMPARE_IRQHandler                       ;ENC1_Compare interrupt
        DCD     ENC1_HOME_IRQHandler                          ;ENC1_Home interrupt
        DCD     ENC1_WDG_SAB_IRQHandler                       ;ENC1_WDG_IRQ/SAB interrupt
        DCD     ENC1_IDX_IRQHandler                           ;ENC1_IDX interrupt
        DCD     ITRC0_IRQHandler                              ;Intrusion and Tamper Response Controller interrupt
        DCD     BSP32_IRQHandler                              ;CoolFlux BSP32 interrupt
        DCD     CSS_ERR_IRQHandler                            ;CSS error interrupt
        DCD     PKC_ERR_IRQHandler                            ;PKC error interrupt
        DCD     ERM_SINGLE_BIT_ERROR_IRQHandler               ;ERM Single Bit error interrupt
        DCD     ERM_MULTI_BIT_ERROR_IRQHandler                ;ERM Multi Bit error interrupt
        DCD     FMU0_IRQHandler                               ;Flash Management Unit interrupt
        DCD     ETHERNET_IRQHandler                           ;Ethernet QoS interrupt
        DCD     ETHERNET_PMT_IRQHandler                       ;Ethernet QoS power management interrupt
        DCD     ETHERNET_MACLP_IRQHandler                     ;Ethernet QoS MAC interrupt
        DCD     SINC_FILTER_IRQHandler                        ;SINC Filter interrupt
        DCD     LPTMR0_IRQHandler                             ;Low Power Timer 0 interrupt
        DCD     LPTMR1_IRQHandler                             ;Low Power Timer 1 interrupt
        DCD     SCG_IRQHandler                                ;System Clock Generator interrupt
        DCD     SPC_IRQHandler                                ;System Power Controller interrupt
        DCD     WUU_IRQHandler                                ;Wake Up Unit interrupt
        DCD     PORT_EFT_IRQHandler                           ;PORT0~5 EFT interrupt
        DCD     ETB0_IRQHandler                               ;ETB counter expires interrupt
        DCD     SM3_IRQHandler                                ;Secure Generic Interface (SGI) SAFO interrupt
        DCD     TRNG0_IRQHandler                              ;True Random Number Generator interrupt
        DCD     WWDT0_IRQHandler                              ;Windowed Watchdog Timer 0 interrupt
        DCD     WWDT1_IRQHandler                              ;Windowed Watchdog Timer 1 interrupt
        DCD     CMC0_IRQHandler                               ;Core Mode Controller interrupt
        DCD     CTI0_IRQHandler                               ;Cross Trigger Interface interrupt
__Vectors_End

__Vectors       EQU   __vector_table
__Vectors_Size  EQU   __Vectors_End - __Vectors


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        CPSID   I               ; Mask interrupts
        LDR     R0, =0xE000ED08
        LDR     R1, =__vector_table
        STR     R1, [R0]
        LDR     R2, [R1]
        MSR     MSP, R2
        LDR     R0, =sfb(CSTACK)
        MSR     MSPLIM, R0
        CPSIE   I               ; Unmask interrupts
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B .

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B .

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B .

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B .

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B .

        PUBWEAK SecureFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SecureFault_Handler
        B .

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B .

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B .

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B .

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B .

        PUBWEAK OR_IRQHandler
        PUBWEAK OR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
OR_IRQHandler
        LDR     R0, =OR_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH0_IRQHandler
        PUBWEAK DMA3_0_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH0_IRQHandler
        LDR     R0, =DMA3_0_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH1_IRQHandler
        PUBWEAK DMA3_0_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH1_IRQHandler
        LDR     R0, =DMA3_0_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH2_IRQHandler
        PUBWEAK DMA3_0_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH2_IRQHandler
        LDR     R0, =DMA3_0_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH3_IRQHandler
        PUBWEAK DMA3_0_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH3_IRQHandler
        LDR     R0, =DMA3_0_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH4_IRQHandler
        PUBWEAK DMA3_0_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH4_IRQHandler
        LDR     R0, =DMA3_0_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH5_IRQHandler
        PUBWEAK DMA3_0_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH5_IRQHandler
        LDR     R0, =DMA3_0_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH6_IRQHandler
        PUBWEAK DMA3_0_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH6_IRQHandler
        LDR     R0, =DMA3_0_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH7_IRQHandler
        PUBWEAK DMA3_0_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH7_IRQHandler
        LDR     R0, =DMA3_0_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH8_IRQHandler
        PUBWEAK DMA3_0_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH8_IRQHandler
        LDR     R0, =DMA3_0_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH9_IRQHandler
        PUBWEAK DMA3_0_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH9_IRQHandler
        LDR     R0, =DMA3_0_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH10_IRQHandler
        PUBWEAK DMA3_0_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH10_IRQHandler
        LDR     R0, =DMA3_0_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH11_IRQHandler
        PUBWEAK DMA3_0_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH11_IRQHandler
        LDR     R0, =DMA3_0_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH12_IRQHandler
        PUBWEAK DMA3_0_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH12_IRQHandler
        LDR     R0, =DMA3_0_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH13_IRQHandler
        PUBWEAK DMA3_0_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH13_IRQHandler
        LDR     R0, =DMA3_0_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH14_IRQHandler
        PUBWEAK DMA3_0_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH14_IRQHandler
        LDR     R0, =DMA3_0_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_0_CH15_IRQHandler
        PUBWEAK DMA3_0_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_0_CH15_IRQHandler
        LDR     R0, =DMA3_0_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO00_IRQHandler
        PUBWEAK GPIO00_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO00_IRQHandler
        LDR     R0, =GPIO00_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO01_IRQHandler
        PUBWEAK GPIO01_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO01_IRQHandler
        LDR     R0, =GPIO01_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO10_IRQHandler
        PUBWEAK GPIO10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO10_IRQHandler
        LDR     R0, =GPIO10_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO11_IRQHandler
        PUBWEAK GPIO11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO11_IRQHandler
        LDR     R0, =GPIO11_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO20_IRQHandler
        PUBWEAK GPIO20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO20_IRQHandler
        LDR     R0, =GPIO20_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO21_IRQHandler
        PUBWEAK GPIO21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO21_IRQHandler
        LDR     R0, =GPIO21_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO30_IRQHandler
        PUBWEAK GPIO30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO30_IRQHandler
        LDR     R0, =GPIO30_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO31_IRQHandler
        PUBWEAK GPIO31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO31_IRQHandler
        LDR     R0, =GPIO31_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO40_IRQHandler
        PUBWEAK GPIO40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO40_IRQHandler
        LDR     R0, =GPIO40_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO41_IRQHandler
        PUBWEAK GPIO41_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO41_IRQHandler
        LDR     R0, =GPIO41_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO50_IRQHandler
        PUBWEAK GPIO50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO50_IRQHandler
        LDR     R0, =GPIO50_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO51_IRQHandler
        PUBWEAK GPIO51_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GPIO51_IRQHandler
        LDR     R0, =GPIO51_DriverIRQHandler
        BX      R0

        PUBWEAK UTICK0_IRQHandler
        PUBWEAK UTICK0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
UTICK0_IRQHandler
        LDR     R0, =UTICK0_DriverIRQHandler
        BX      R0

        PUBWEAK MRT0_IRQHandler
        PUBWEAK MRT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MRT0_IRQHandler
        LDR     R0, =MRT0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER0_IRQHandler
        PUBWEAK CTIMER0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER0_IRQHandler
        LDR     R0, =CTIMER0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER1_IRQHandler
        PUBWEAK CTIMER1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER1_IRQHandler
        LDR     R0, =CTIMER1_DriverIRQHandler
        BX      R0

        PUBWEAK SCT0_IRQHandler
        PUBWEAK SCT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCT0_IRQHandler
        LDR     R0, =SCT0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER2_IRQHandler
        PUBWEAK CTIMER2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER2_IRQHandler
        LDR     R0, =CTIMER2_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM0_IRQHandler
        PUBWEAK LP_FLEXCOMM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM0_IRQHandler
        LDR     R0, =LP_FLEXCOMM0_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM1_IRQHandler
        PUBWEAK LP_FLEXCOMM1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM1_IRQHandler
        LDR     R0, =LP_FLEXCOMM1_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM2_IRQHandler
        PUBWEAK LP_FLEXCOMM2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM2_IRQHandler
        LDR     R0, =LP_FLEXCOMM2_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM3_IRQHandler
        PUBWEAK LP_FLEXCOMM3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM3_IRQHandler
        LDR     R0, =LP_FLEXCOMM3_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM4_IRQHandler
        PUBWEAK LP_FLEXCOMM4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM4_IRQHandler
        LDR     R0, =LP_FLEXCOMM4_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM5_IRQHandler
        PUBWEAK LP_FLEXCOMM5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM5_IRQHandler
        LDR     R0, =LP_FLEXCOMM5_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM6_IRQHandler
        PUBWEAK LP_FLEXCOMM6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM6_IRQHandler
        LDR     R0, =LP_FLEXCOMM6_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM7_IRQHandler
        PUBWEAK LP_FLEXCOMM7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM7_IRQHandler
        LDR     R0, =LP_FLEXCOMM7_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM8_IRQHandler
        PUBWEAK LP_FLEXCOMM8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM8_IRQHandler
        LDR     R0, =LP_FLEXCOMM8_DriverIRQHandler
        BX      R0

        PUBWEAK LP_FLEXCOMM9_IRQHandler
        PUBWEAK LP_FLEXCOMM9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LP_FLEXCOMM9_IRQHandler
        LDR     R0, =LP_FLEXCOMM9_DriverIRQHandler
        BX      R0

        PUBWEAK ADC0_IRQHandler
        PUBWEAK ADC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC0_IRQHandler
        LDR     R0, =ADC0_DriverIRQHandler
        BX      R0

        PUBWEAK ADC1_IRQHandler
        PUBWEAK ADC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ADC1_IRQHandler
        LDR     R0, =ADC1_DriverIRQHandler
        BX      R0

        PUBWEAK PINT_IRQHandler
        PUBWEAK PINT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PINT_IRQHandler
        LDR     R0, =PINT_DriverIRQHandler
        BX      R0

        PUBWEAK MICFIL_IRQHandler
        PUBWEAK MICFIL_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MICFIL_IRQHandler
        LDR     R0, =MICFIL_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved65_IRQHandler
        PUBWEAK Reserved65_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reserved65_IRQHandler
        LDR     R0, =Reserved65_DriverIRQHandler
        BX      R0

        PUBWEAK USB0_FS_IRQHandler
        PUBWEAK USB0_FS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB0_FS_IRQHandler
        LDR     R0, =USB0_FS_DriverIRQHandler
        BX      R0

        PUBWEAK USB0_DCD_IRQHandler
        PUBWEAK USB0_DCD_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB0_DCD_IRQHandler
        LDR     R0, =USB0_DCD_DriverIRQHandler
        BX      R0

        PUBWEAK RTC_IRQHandler
        PUBWEAK RTC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
RTC_IRQHandler
        LDR     R0, =RTC_DriverIRQHandler
        BX      R0

        PUBWEAK SMARTDMA_IRQHandler
        PUBWEAK SMARTDMA_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SMARTDMA_IRQHandler
        LDR     R0, =SMARTDMA_DriverIRQHandler
        BX      R0

        PUBWEAK MAILBOX0_IRQHandler
        PUBWEAK MAILBOX0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
MAILBOX0_IRQHandler
        LDR     R0, =MAILBOX0_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER3_IRQHandler
        PUBWEAK CTIMER3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER3_IRQHandler
        LDR     R0, =CTIMER3_DriverIRQHandler
        BX      R0

        PUBWEAK CTIMER4_IRQHandler
        PUBWEAK CTIMER4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTIMER4_IRQHandler
        LDR     R0, =CTIMER4_DriverIRQHandler
        BX      R0

        PUBWEAK OSTimer_IRQHandler
        PUBWEAK OSTimer_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
OSTimer_IRQHandler
        LDR     R0, =OSTimer_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXSPI_IRQHandler
        PUBWEAK FLEXSPI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXSPI_IRQHandler
        LDR     R0, =FLEXSPI_DriverIRQHandler
        BX      R0

        PUBWEAK SAI0_IRQHandler
        PUBWEAK SAI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI0_IRQHandler
        LDR     R0, =SAI0_DriverIRQHandler
        BX      R0

        PUBWEAK SAI1_IRQHandler
        PUBWEAK SAI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI1_IRQHandler
        LDR     R0, =SAI1_DriverIRQHandler
        BX      R0

        PUBWEAK USDHC_IRQHandler
        PUBWEAK USDHC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC_IRQHandler
        LDR     R0, =USDHC_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCAN0_IRQHandler
        PUBWEAK FLEXCAN0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCAN0_IRQHandler
        LDR     R0, =FLEXCAN0_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXCAN1_IRQHandler
        PUBWEAK FLEXCAN1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXCAN1_IRQHandler
        LDR     R0, =FLEXCAN1_DriverIRQHandler
        BX      R0

        PUBWEAK SPI_FILER0_IRQHandler
        PUBWEAK SPI_FILER0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPI_FILER0_IRQHandler
        LDR     R0, =SPI_FILER0_DriverIRQHandler
        BX      R0

        PUBWEAK ESPI_IRQHandler
        PUBWEAK ESPI_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ESPI_IRQHandler
        LDR     R0, =ESPI_DriverIRQHandler
        BX      R0

        PUBWEAK USB1_HS_PHY_IRQHandler
        PUBWEAK USB1_HS_PHY_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB1_HS_PHY_IRQHandler
        LDR     R0, =USB1_HS_PHY_DriverIRQHandler
        BX      R0

        PUBWEAK USB1_HS_IRQHandler
        PUBWEAK USB1_HS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USB1_HS_IRQHandler
        LDR     R0, =USB1_HS_DriverIRQHandler
        BX      R0

        PUBWEAK SEC_HYPERVISOR_CALL_IRQHandler
        PUBWEAK SEC_HYPERVISOR_CALL_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SEC_HYPERVISOR_CALL_IRQHandler
        LDR     R0, =SEC_HYPERVISOR_CALL_DriverIRQHandler
        BX      R0

        PUBWEAK TRO_IRQHandler
        PUBWEAK TRO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TRO_IRQHandler
        LDR     R0, =TRO_DriverIRQHandler
        BX      R0

        PUBWEAK PLU_IRQHandler
        PUBWEAK PLU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PLU_IRQHandler
        LDR     R0, =PLU_DriverIRQHandler
        BX      R0

        PUBWEAK FME_IRQHandler
        PUBWEAK FME_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FME_IRQHandler
        LDR     R0, =FME_DriverIRQHandler
        BX      R0

        PUBWEAK SEC_VIO_IRQHandler
        PUBWEAK SEC_VIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SEC_VIO_IRQHandler
        LDR     R0, =SEC_VIO_DriverIRQHandler
        BX      R0

        PUBWEAK CSS_IRQHandler
        PUBWEAK CSS_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CSS_IRQHandler
        LDR     R0, =CSS_DriverIRQHandler
        BX      R0

        PUBWEAK PKC_IRQHandler
        PUBWEAK PKC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PKC_IRQHandler
        LDR     R0, =PKC_DriverIRQHandler
        BX      R0

        PUBWEAK PUF_IRQHandler
        PUBWEAK PUF_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PUF_IRQHandler
        LDR     R0, =PUF_DriverIRQHandler
        BX      R0

        PUBWEAK PQ_IRQHandler
        PUBWEAK PQ_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PQ_IRQHandler
        LDR     R0, =PQ_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH0_IRQHandler
        PUBWEAK DMA3_1_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH0_IRQHandler
        LDR     R0, =DMA3_1_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH1_IRQHandler
        PUBWEAK DMA3_1_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH1_IRQHandler
        LDR     R0, =DMA3_1_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH2_IRQHandler
        PUBWEAK DMA3_1_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH2_IRQHandler
        LDR     R0, =DMA3_1_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH3_IRQHandler
        PUBWEAK DMA3_1_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH3_IRQHandler
        LDR     R0, =DMA3_1_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH4_IRQHandler
        PUBWEAK DMA3_1_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH4_IRQHandler
        LDR     R0, =DMA3_1_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH5_IRQHandler
        PUBWEAK DMA3_1_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH5_IRQHandler
        LDR     R0, =DMA3_1_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH6_IRQHandler
        PUBWEAK DMA3_1_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH6_IRQHandler
        LDR     R0, =DMA3_1_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH7_IRQHandler
        PUBWEAK DMA3_1_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH7_IRQHandler
        LDR     R0, =DMA3_1_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH8_IRQHandler
        PUBWEAK DMA3_1_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH8_IRQHandler
        LDR     R0, =DMA3_1_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH9_IRQHandler
        PUBWEAK DMA3_1_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH9_IRQHandler
        LDR     R0, =DMA3_1_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH10_IRQHandler
        PUBWEAK DMA3_1_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH10_IRQHandler
        LDR     R0, =DMA3_1_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH11_IRQHandler
        PUBWEAK DMA3_1_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH11_IRQHandler
        LDR     R0, =DMA3_1_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH12_IRQHandler
        PUBWEAK DMA3_1_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH12_IRQHandler
        LDR     R0, =DMA3_1_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH13_IRQHandler
        PUBWEAK DMA3_1_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH13_IRQHandler
        LDR     R0, =DMA3_1_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH14_IRQHandler
        PUBWEAK DMA3_1_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH14_IRQHandler
        LDR     R0, =DMA3_1_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK DMA3_1_CH15_IRQHandler
        PUBWEAK DMA3_1_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DMA3_1_CH15_IRQHandler
        LDR     R0, =DMA3_1_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK CODE_WDG0_IRQHandler
        PUBWEAK CODE_WDG0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CODE_WDG0_IRQHandler
        LDR     R0, =CODE_WDG0_DriverIRQHandler
        BX      R0

        PUBWEAK CODE_WDG1_IRQHandler
        PUBWEAK CODE_WDG1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CODE_WDG1_IRQHandler
        LDR     R0, =CODE_WDG1_DriverIRQHandler
        BX      R0

        PUBWEAK I3C0_IRQHandler
        PUBWEAK I3C0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C0_IRQHandler
        LDR     R0, =I3C0_DriverIRQHandler
        BX      R0

        PUBWEAK I3C1_IRQHandler
        PUBWEAK I3C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C1_IRQHandler
        LDR     R0, =I3C1_DriverIRQHandler
        BX      R0

        PUBWEAK NEUTRON_IRQHandler
        PUBWEAK NEUTRON_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
NEUTRON_IRQHandler
        LDR     R0, =NEUTRON_DriverIRQHandler
        BX      R0

        PUBWEAK GDET_IRQHandler
        PUBWEAK GDET_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
GDET_IRQHandler
        LDR     R0, =GDET_DriverIRQHandler
        BX      R0

        PUBWEAK VBAT0_IRQHandler
        PUBWEAK VBAT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
VBAT0_IRQHandler
        LDR     R0, =VBAT0_DriverIRQHandler
        BX      R0

        PUBWEAK EWM0_IRQHandler
        PUBWEAK EWM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EWM0_IRQHandler
        LDR     R0, =EWM0_DriverIRQHandler
        BX      R0

        PUBWEAK TSI_END_OF_SCAN_IRQHandler
        PUBWEAK TSI_END_OF_SCAN_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TSI_END_OF_SCAN_IRQHandler
        LDR     R0, =TSI_END_OF_SCAN_DriverIRQHandler
        BX      R0

        PUBWEAK TSI_OUT_OF_SCAN_IRQHandler
        PUBWEAK TSI_OUT_OF_SCAN_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TSI_OUT_OF_SCAN_IRQHandler
        LDR     R0, =TSI_OUT_OF_SCAN_DriverIRQHandler
        BX      R0

        PUBWEAK EMVSIM0_IRQHandler
        PUBWEAK EMVSIM0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EMVSIM0_IRQHandler
        LDR     R0, =EMVSIM0_DriverIRQHandler
        BX      R0

        PUBWEAK EMVSIM1_IRQHandler
        PUBWEAK EMVSIM1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EMVSIM1_IRQHandler
        LDR     R0, =EMVSIM1_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO_IRQHandler
        PUBWEAK FLEXIO_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO_IRQHandler
        LDR     R0, =FLEXIO_DriverIRQHandler
        BX      R0

        PUBWEAK DAC0_IRQHandler
        PUBWEAK DAC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DAC0_IRQHandler
        LDR     R0, =DAC0_DriverIRQHandler
        BX      R0

        PUBWEAK DAC1_IRQHandler
        PUBWEAK DAC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
DAC1_IRQHandler
        LDR     R0, =DAC1_DriverIRQHandler
        BX      R0

        PUBWEAK HPDAC0_IRQHandler
        PUBWEAK HPDAC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HPDAC0_IRQHandler
        LDR     R0, =HPDAC0_DriverIRQHandler
        BX      R0

        PUBWEAK HSCMP0_IRQHandler
        PUBWEAK HSCMP0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HSCMP0_IRQHandler
        LDR     R0, =HSCMP0_DriverIRQHandler
        BX      R0

        PUBWEAK HSCMP1_IRQHandler
        PUBWEAK HSCMP1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HSCMP1_IRQHandler
        LDR     R0, =HSCMP1_DriverIRQHandler
        BX      R0

        PUBWEAK HSCMP2_IRQHandler
        PUBWEAK HSCMP2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
HSCMP2_IRQHandler
        LDR     R0, =HSCMP2_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_RELOAD_ERROR_IRQHandler
        PUBWEAK FLEXPWM0_RELOAD_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_RELOAD_ERROR_IRQHandler
        LDR     R0, =FLEXPWM0_RELOAD_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_FAULT_IRQHandler
        PUBWEAK FLEXPWM0_FAULT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_FAULT_IRQHandler
        LDR     R0, =FLEXPWM0_FAULT_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_SUBMODULE0_IRQHandler
        PUBWEAK FLEXPWM0_SUBMODULE0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_SUBMODULE0_IRQHandler
        LDR     R0, =FLEXPWM0_SUBMODULE0_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_SUBMODULE1_IRQHandler
        PUBWEAK FLEXPWM0_SUBMODULE1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_SUBMODULE1_IRQHandler
        LDR     R0, =FLEXPWM0_SUBMODULE1_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_SUBMODULE2_IRQHandler
        PUBWEAK FLEXPWM0_SUBMODULE2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_SUBMODULE2_IRQHandler
        LDR     R0, =FLEXPWM0_SUBMODULE2_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM0_SUBMODULE3_IRQHandler
        PUBWEAK FLEXPWM0_SUBMODULE3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM0_SUBMODULE3_IRQHandler
        LDR     R0, =FLEXPWM0_SUBMODULE3_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_RELOAD_ERROR_IRQHandler
        PUBWEAK FLEXPWM1_RELOAD_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_RELOAD_ERROR_IRQHandler
        LDR     R0, =FLEXPWM1_RELOAD_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_FAULT_IRQHandler
        PUBWEAK FLEXPWM1_FAULT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_FAULT_IRQHandler
        LDR     R0, =FLEXPWM1_FAULT_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_SUBMODULE0_IRQHandler
        PUBWEAK FLEXPWM1_SUBMODULE0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_SUBMODULE0_IRQHandler
        LDR     R0, =FLEXPWM1_SUBMODULE0_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_SUBMODULE1_IRQHandler
        PUBWEAK FLEXPWM1_SUBMODULE1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_SUBMODULE1_IRQHandler
        LDR     R0, =FLEXPWM1_SUBMODULE1_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_SUBMODULE2_IRQHandler
        PUBWEAK FLEXPWM1_SUBMODULE2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_SUBMODULE2_IRQHandler
        LDR     R0, =FLEXPWM1_SUBMODULE2_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXPWM1_SUBMODULE3_IRQHandler
        PUBWEAK FLEXPWM1_SUBMODULE3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXPWM1_SUBMODULE3_IRQHandler
        LDR     R0, =FLEXPWM1_SUBMODULE3_DriverIRQHandler
        BX      R0

        PUBWEAK ENC0_COMPARE_IRQHandler
        PUBWEAK ENC0_COMPARE_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC0_COMPARE_IRQHandler
        LDR     R0, =ENC0_COMPARE_DriverIRQHandler
        BX      R0

        PUBWEAK ENC0_HOME_IRQHandler
        PUBWEAK ENC0_HOME_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC0_HOME_IRQHandler
        LDR     R0, =ENC0_HOME_DriverIRQHandler
        BX      R0

        PUBWEAK ENC0_WDG_SAB_IRQHandler
        PUBWEAK ENC0_WDG_SAB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC0_WDG_SAB_IRQHandler
        LDR     R0, =ENC0_WDG_SAB_DriverIRQHandler
        BX      R0

        PUBWEAK ENC0_IDX_IRQHandler
        PUBWEAK ENC0_IDX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC0_IDX_IRQHandler
        LDR     R0, =ENC0_IDX_DriverIRQHandler
        BX      R0

        PUBWEAK ENC1_COMPARE_IRQHandler
        PUBWEAK ENC1_COMPARE_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC1_COMPARE_IRQHandler
        LDR     R0, =ENC1_COMPARE_DriverIRQHandler
        BX      R0

        PUBWEAK ENC1_HOME_IRQHandler
        PUBWEAK ENC1_HOME_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC1_HOME_IRQHandler
        LDR     R0, =ENC1_HOME_DriverIRQHandler
        BX      R0

        PUBWEAK ENC1_WDG_SAB_IRQHandler
        PUBWEAK ENC1_WDG_SAB_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC1_WDG_SAB_IRQHandler
        LDR     R0, =ENC1_WDG_SAB_DriverIRQHandler
        BX      R0

        PUBWEAK ENC1_IDX_IRQHandler
        PUBWEAK ENC1_IDX_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ENC1_IDX_IRQHandler
        LDR     R0, =ENC1_IDX_DriverIRQHandler
        BX      R0

        PUBWEAK ITRC0_IRQHandler
        PUBWEAK ITRC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ITRC0_IRQHandler
        LDR     R0, =ITRC0_DriverIRQHandler
        BX      R0

        PUBWEAK BSP32_IRQHandler
        PUBWEAK BSP32_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
BSP32_IRQHandler
        LDR     R0, =BSP32_DriverIRQHandler
        BX      R0

        PUBWEAK CSS_ERR_IRQHandler
        PUBWEAK CSS_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CSS_ERR_IRQHandler
        LDR     R0, =CSS_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK PKC_ERR_IRQHandler
        PUBWEAK PKC_ERR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PKC_ERR_IRQHandler
        LDR     R0, =PKC_ERR_DriverIRQHandler
        BX      R0

        PUBWEAK ERM_SINGLE_BIT_ERROR_IRQHandler
        PUBWEAK ERM_SINGLE_BIT_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ERM_SINGLE_BIT_ERROR_IRQHandler
        LDR     R0, =ERM_SINGLE_BIT_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK ERM_MULTI_BIT_ERROR_IRQHandler
        PUBWEAK ERM_MULTI_BIT_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ERM_MULTI_BIT_ERROR_IRQHandler
        LDR     R0, =ERM_MULTI_BIT_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK FMU0_IRQHandler
        PUBWEAK FMU0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FMU0_IRQHandler
        LDR     R0, =FMU0_DriverIRQHandler
        BX      R0

        PUBWEAK ETHERNET_IRQHandler
        PUBWEAK ETHERNET_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ETHERNET_IRQHandler
        LDR     R0, =ETHERNET_DriverIRQHandler
        BX      R0

        PUBWEAK ETHERNET_PMT_IRQHandler
        PUBWEAK ETHERNET_PMT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ETHERNET_PMT_IRQHandler
        LDR     R0, =ETHERNET_PMT_DriverIRQHandler
        BX      R0

        PUBWEAK ETHERNET_MACLP_IRQHandler
        PUBWEAK ETHERNET_MACLP_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ETHERNET_MACLP_IRQHandler
        LDR     R0, =ETHERNET_MACLP_DriverIRQHandler
        BX      R0

        PUBWEAK SINC_FILTER_IRQHandler
        PUBWEAK SINC_FILTER_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SINC_FILTER_IRQHandler
        LDR     R0, =SINC_FILTER_DriverIRQHandler
        BX      R0

        PUBWEAK LPTMR0_IRQHandler
        PUBWEAK LPTMR0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPTMR0_IRQHandler
        LDR     R0, =LPTMR0_DriverIRQHandler
        BX      R0

        PUBWEAK LPTMR1_IRQHandler
        PUBWEAK LPTMR1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPTMR1_IRQHandler
        LDR     R0, =LPTMR1_DriverIRQHandler
        BX      R0

        PUBWEAK SCG_IRQHandler
        PUBWEAK SCG_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SCG_IRQHandler
        LDR     R0, =SCG_DriverIRQHandler
        BX      R0

        PUBWEAK SPC_IRQHandler
        PUBWEAK SPC_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SPC_IRQHandler
        LDR     R0, =SPC_DriverIRQHandler
        BX      R0

        PUBWEAK WUU_IRQHandler
        PUBWEAK WUU_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WUU_IRQHandler
        LDR     R0, =WUU_DriverIRQHandler
        BX      R0

        PUBWEAK PORT_EFT_IRQHandler
        PUBWEAK PORT_EFT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PORT_EFT_IRQHandler
        LDR     R0, =PORT_EFT_DriverIRQHandler
        BX      R0

        PUBWEAK ETB0_IRQHandler
        PUBWEAK ETB0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
ETB0_IRQHandler
        LDR     R0, =ETB0_DriverIRQHandler
        BX      R0

        PUBWEAK SM3_IRQHandler
        PUBWEAK SM3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SM3_IRQHandler
        LDR     R0, =SM3_DriverIRQHandler
        BX      R0

        PUBWEAK TRNG0_IRQHandler
        PUBWEAK TRNG0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
TRNG0_IRQHandler
        LDR     R0, =TRNG0_DriverIRQHandler
        BX      R0

        PUBWEAK WWDT0_IRQHandler
        PUBWEAK WWDT0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WWDT0_IRQHandler
        LDR     R0, =WWDT0_DriverIRQHandler
        BX      R0

        PUBWEAK WWDT1_IRQHandler
        PUBWEAK WWDT1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
WWDT1_IRQHandler
        LDR     R0, =WWDT1_DriverIRQHandler
        BX      R0

        PUBWEAK CMC0_IRQHandler
        PUBWEAK CMC0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CMC0_IRQHandler
        LDR     R0, =CMC0_DriverIRQHandler
        BX      R0

        PUBWEAK CTI0_IRQHandler
        PUBWEAK CTI0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CTI0_IRQHandler
        LDR     R0, =CTI0_DriverIRQHandler
        BX      R0

OR_DriverIRQHandler
DMA3_0_CH0_DriverIRQHandler
DMA3_0_CH1_DriverIRQHandler
DMA3_0_CH2_DriverIRQHandler
DMA3_0_CH3_DriverIRQHandler
DMA3_0_CH4_DriverIRQHandler
DMA3_0_CH5_DriverIRQHandler
DMA3_0_CH6_DriverIRQHandler
DMA3_0_CH7_DriverIRQHandler
DMA3_0_CH8_DriverIRQHandler
DMA3_0_CH9_DriverIRQHandler
DMA3_0_CH10_DriverIRQHandler
DMA3_0_CH11_DriverIRQHandler
DMA3_0_CH12_DriverIRQHandler
DMA3_0_CH13_DriverIRQHandler
DMA3_0_CH14_DriverIRQHandler
DMA3_0_CH15_DriverIRQHandler
GPIO00_DriverIRQHandler
GPIO01_DriverIRQHandler
GPIO10_DriverIRQHandler
GPIO11_DriverIRQHandler
GPIO20_DriverIRQHandler
GPIO21_DriverIRQHandler
GPIO30_DriverIRQHandler
GPIO31_DriverIRQHandler
GPIO40_DriverIRQHandler
GPIO41_DriverIRQHandler
GPIO50_DriverIRQHandler
GPIO51_DriverIRQHandler
UTICK0_DriverIRQHandler
MRT0_DriverIRQHandler
CTIMER0_DriverIRQHandler
CTIMER1_DriverIRQHandler
SCT0_DriverIRQHandler
CTIMER2_DriverIRQHandler
LP_FLEXCOMM0_DriverIRQHandler
LP_FLEXCOMM1_DriverIRQHandler
LP_FLEXCOMM2_DriverIRQHandler
LP_FLEXCOMM3_DriverIRQHandler
LP_FLEXCOMM4_DriverIRQHandler
LP_FLEXCOMM5_DriverIRQHandler
LP_FLEXCOMM6_DriverIRQHandler
LP_FLEXCOMM7_DriverIRQHandler
LP_FLEXCOMM8_DriverIRQHandler
LP_FLEXCOMM9_DriverIRQHandler
ADC0_DriverIRQHandler
ADC1_DriverIRQHandler
PINT_DriverIRQHandler
MICFIL_DriverIRQHandler
Reserved65_DriverIRQHandler
USB0_FS_DriverIRQHandler
USB0_DCD_DriverIRQHandler
RTC_DriverIRQHandler
SMARTDMA_DriverIRQHandler
MAILBOX0_DriverIRQHandler
CTIMER3_DriverIRQHandler
CTIMER4_DriverIRQHandler
OSTimer_DriverIRQHandler
FLEXSPI_DriverIRQHandler
SAI0_DriverIRQHandler
SAI1_DriverIRQHandler
USDHC_DriverIRQHandler
FLEXCAN0_DriverIRQHandler
FLEXCAN1_DriverIRQHandler
SPI_FILER0_DriverIRQHandler
ESPI_DriverIRQHandler
USB1_HS_PHY_DriverIRQHandler
USB1_HS_DriverIRQHandler
SEC_HYPERVISOR_CALL_DriverIRQHandler
TRO_DriverIRQHandler
PLU_DriverIRQHandler
FME_DriverIRQHandler
SEC_VIO_DriverIRQHandler
CSS_DriverIRQHandler
PKC_DriverIRQHandler
PUF_DriverIRQHandler
PQ_DriverIRQHandler
DMA3_1_CH0_DriverIRQHandler
DMA3_1_CH1_DriverIRQHandler
DMA3_1_CH2_DriverIRQHandler
DMA3_1_CH3_DriverIRQHandler
DMA3_1_CH4_DriverIRQHandler
DMA3_1_CH5_DriverIRQHandler
DMA3_1_CH6_DriverIRQHandler
DMA3_1_CH7_DriverIRQHandler
DMA3_1_CH8_DriverIRQHandler
DMA3_1_CH9_DriverIRQHandler
DMA3_1_CH10_DriverIRQHandler
DMA3_1_CH11_DriverIRQHandler
DMA3_1_CH12_DriverIRQHandler
DMA3_1_CH13_DriverIRQHandler
DMA3_1_CH14_DriverIRQHandler
DMA3_1_CH15_DriverIRQHandler
CODE_WDG0_DriverIRQHandler
CODE_WDG1_DriverIRQHandler
I3C0_DriverIRQHandler
I3C1_DriverIRQHandler
NEUTRON_DriverIRQHandler
GDET_DriverIRQHandler
VBAT0_DriverIRQHandler
EWM0_DriverIRQHandler
TSI_END_OF_SCAN_DriverIRQHandler
TSI_OUT_OF_SCAN_DriverIRQHandler
EMVSIM0_DriverIRQHandler
EMVSIM1_DriverIRQHandler
FLEXIO_DriverIRQHandler
DAC0_DriverIRQHandler
DAC1_DriverIRQHandler
HPDAC0_DriverIRQHandler
HSCMP0_DriverIRQHandler
HSCMP1_DriverIRQHandler
HSCMP2_DriverIRQHandler
FLEXPWM0_RELOAD_ERROR_DriverIRQHandler
FLEXPWM0_FAULT_DriverIRQHandler
FLEXPWM0_SUBMODULE0_DriverIRQHandler
FLEXPWM0_SUBMODULE1_DriverIRQHandler
FLEXPWM0_SUBMODULE2_DriverIRQHandler
FLEXPWM0_SUBMODULE3_DriverIRQHandler
FLEXPWM1_RELOAD_ERROR_DriverIRQHandler
FLEXPWM1_FAULT_DriverIRQHandler
FLEXPWM1_SUBMODULE0_DriverIRQHandler
FLEXPWM1_SUBMODULE1_DriverIRQHandler
FLEXPWM1_SUBMODULE2_DriverIRQHandler
FLEXPWM1_SUBMODULE3_DriverIRQHandler
ENC0_COMPARE_DriverIRQHandler
ENC0_HOME_DriverIRQHandler
ENC0_WDG_SAB_DriverIRQHandler
ENC0_IDX_DriverIRQHandler
ENC1_COMPARE_DriverIRQHandler
ENC1_HOME_DriverIRQHandler
ENC1_WDG_SAB_DriverIRQHandler
ENC1_IDX_DriverIRQHandler
ITRC0_DriverIRQHandler
BSP32_DriverIRQHandler
CSS_ERR_DriverIRQHandler
PKC_ERR_DriverIRQHandler
ERM_SINGLE_BIT_ERROR_DriverIRQHandler
ERM_MULTI_BIT_ERROR_DriverIRQHandler
FMU0_DriverIRQHandler
ETHERNET_DriverIRQHandler
ETHERNET_PMT_DriverIRQHandler
ETHERNET_MACLP_DriverIRQHandler
SINC_FILTER_DriverIRQHandler
LPTMR0_DriverIRQHandler
LPTMR1_DriverIRQHandler
SCG_DriverIRQHandler
SPC_DriverIRQHandler
WUU_DriverIRQHandler
PORT_EFT_DriverIRQHandler
ETB0_DriverIRQHandler
SM3_DriverIRQHandler
TRNG0_DriverIRQHandler
WWDT0_DriverIRQHandler
WWDT1_DriverIRQHandler
CMC0_DriverIRQHandler
CTI0_DriverIRQHandler
DefaultISR
        B .

        END
