## TouchGFX with CubeIDE

_**STM32F746G-Disco:**_

1.	Create a new project with CubeIDE.
2.	Configure QSPI bank1 with 4 SPI lines (psc=1, Fifo=4, sample shifting=half cycle, size=24, CS=6Cycles, low, ID1,disabled)
3.	LTDC RGB888
4.	DMA2D: ARGB888, mem to mem
5.	Sys core: Cortex m7: axi interface, All enabled
6.	FreeRTOS: tasks & queues: 4096 words
7.	Additional software: BY @ (otherwise RAM will be overflowed) @=0xC0000000 (external SDRAM @)
8.	Create the project
9.	C/C++ :TouchGFX (C++)
10.	in StartDefaultTask function: add "MX_TouchGFX_Process();"
11.	Add code STM32TouchController.cpp (that enable the touch) as following:

    a. add the include files:
    
      #include <TouchGFXHAL.hpp>
      
      #include <stm32f7xx_hal.h>
      
      #include <touchgfx/hal/OSWrappers.hpp>
      
      #include "../../Drivers/BSP/Components/ft5336/ft5336.h"
      
    b. add the following code:
    
        static TS_DrvTypeDef* tsDriver;
      
        extern I2C_HandleTypeDef hi2c3;

        void STM32TouchController::init()
        {
      
            /* Initialize the TS driver structure */
            tsDriver = &ft5336_ts_drv;

            /* Initialize the TS driver */
            tsDriver->Start(TS_I2C_ADDRESS);
        }

        bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
        {
            /* Checking if the screen has been touched */

            if (tsDriver)
            {
                if (tsDriver->DetectTouch(TS_I2C_ADDRESS))
                {
                    /* Get each touch coordinates */
                    tsDriver->GetXY(TS_I2C_ADDRESS, (uint16_t*)&y, (uint16_t*)&x);
                    return true;
                }
            }
            return false;
        }

        static void I2Cx_Error(I2C_HandleTypeDef* i2c_handler, uint8_t Addr)
        {
          /* De-initialize the I2C communication bus */
          HAL_I2C_DeInit(i2c_handler);

          /* Re-Initialize the I2C communication bus */
          //I2Cx_Init(i2c_handler);
        }

        /**
            * @brief  Reads multiple data.
        * @param  i2c_handler : I2C handler
        * @param  Addr: I2C address
        * @param  Reg: Reg address
        * @param  MemAddress: Memory address
        * @param  Buffer: Pointer to data buffer
        * @param  Length: Length of the data
        * @retval Number of read data
        */
        static HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef* i2c_handler,
                                                 uint8_t Addr,
                                                 uint16_t Reg,
                                                 uint16_t MemAddress,
                                                 uint8_t* Buffer,
                                                 uint16_t Length)
        {
          HAL_StatusTypeDef status = HAL_OK;

          status = HAL_I2C_Mem_Read(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

          /* Check the communication status */
          if (status != HAL_OK)
          {
              /* I2C error occurred */
              I2Cx_Error(i2c_handler, Addr);
          }
          return status;
        }

        /**
        * @brief  Writes a value in a register of the device through BUS in using DMA mode.
        * @param  i2c_handler : I2C handler
        * @param  Addr: Device address on BUS Bus.
        * @param  Reg: The target register address to write
        * @param  MemAddress: Memory address
        * @param  Buffer: The target register value to be written
        * @param  Length: buffer size to be written
        * @retval HAL status
        */
        static HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef* i2c_handler,
                                                  uint8_t Addr,
                                                  uint16_t Reg,
                                                  uint16_t MemAddress,
                                                  uint8_t* Buffer,
                                                  uint16_t Length)
        {
          HAL_StatusTypeDef status = HAL_OK;

          status = HAL_I2C_Mem_Write(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

          /* Check the communication status */
          if (status != HAL_OK)
          {
              /* Re-Initiaize the I2C Bus */
              I2Cx_Error(i2c_handler, Addr);
          }
          return status;
        }

12.	Import ft5336, N25Q128A & the discovery files and add paths


_**STM32F769I-Disco:**_

1.	Create a new project with CubeIDE.
2.	Configure QSPI bank1 with 4 SPI lines (psc=1, Fifo=4, sample shifting=half cycle, size=26, CS=6Cycles, low, ID1,disabled)
3.	LTDC RGB888
4.	DMA2D: ARGB888, mem to mem
5.	Sys core: Cortex m7: axi interface, All enabled
6.	FreeRTOS: tasks & queues: 4096 words
7.	Additional software: BY @ (otherwise RAM will be overflowed) @=0xC0000000(Bank1) and 0xD0000000(Bank2) (external SDRAM @)
8.	Create the project
9.	C/C++ :TouchGFX (C++)
10.	in StartDefaultTask function: add "MX_TouchGFX_Process();"
11.	Add code STM32TouchController.cpp (that enable the touch) as following:

    a. add the include files:
    
      #include "../ft6x06/ft6x06.h"
      
      #include <stm32f7xx_hal.h>
      
    b. add the following code:
    
        extern "C"
        {
        /** @brief With FT6206 : maximum 2 touches detected simultaneously
        */
        #define TS_MAX_NB_TOUCH                 ((uint32_t) FT6206_MAX_DETECTABLE_TOUCH)

        #define TS_SWAP_NONE                    ((uint8_t) 0x01)
        #define TS_SWAP_X                       ((uint8_t) 0x02)
        #define TS_SWAP_Y                       ((uint8_t) 0x04)
        #define TS_SWAP_XY                      ((uint8_t) 0x08)

          /**
            * @brief TouchScreen FT6206 Slave I2C address 1
            */
        #define TS_I2C_ADDRESS                   ((uint16_t)0x54)

          /**
            * @brief TouchScreen FT6336G Slave I2C address 2
            */
        #define TS_I2C_ADDRESS_A02               ((uint16_t)0x70)

          /** @defgroup STM32F769I_DISCOVERY_TS_Exported_Types  TS Exported Types
            * @{
            */
          /**
          *  @brief TS_StateTypeDef
          *  Define TS State structure
          */
          typedef struct
          {
              uint8_t  touchDetected;                /*!< Total number of active touches detected at last scan */
              uint16_t touchX[TS_MAX_NB_TOUCH];      /*!< Touch X[0], X[1] coordinates on 12 bits */
              uint16_t touchY[TS_MAX_NB_TOUCH];      /*!< Touch Y[0], Y[1] coordinates on 12 bits */
          } TS_StateTypeDef;

          /**
           *  @brief TS_StatusTypeDef
           *  Define BSP_TS_xxx() functions possible return value,
           *  when status is returned by those functions.
           */
          typedef enum
          {
              TS_OK                = 0x00, /*!< Touch Ok */
              TS_ERROR             = 0x01, /*!< Touch Error */
              TS_TIMEOUT           = 0x02, /*!< Touch Timeout */
              TS_DEVICE_NOT_FOUND  = 0x03  /*!< Touchscreen device not found */
          } TS_StatusTypeDef;

          extern I2C_HandleTypeDef hi2c4;
          extern void MX_I2C4_Init(void);

          static uint8_t  ts_orientation;
          static uint8_t  I2C_Address = 0;

          /* TouchScreen (TS) IO functions */
          void     TS_IO_Init(void);
          void     TS_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
          uint8_t  TS_IO_Read(uint8_t Addr, uint8_t Reg);
          uint16_t TS_IO_ReadMultiple(uint8_t Addr, uint8_t Reg, uint8_t* Buffer, uint16_t Length);
          void     TS_IO_WriteMultiple(uint8_t Addr, uint8_t Reg, uint8_t* Buffer, uint16_t Length);
          void     TS_IO_Delay(uint32_t Delay);

          uint8_t BSP_TS_Init(uint16_t ts_SizeX, uint16_t ts_SizeY);
          uint8_t BSP_TS_GetState(TS_StateTypeDef* TS_State);
        }

        static bool bsp_ts_initialized = false;

        void STM32TouchController::init()
        {
          /**
           * Initialize touch controller and driver
           *
           */
          if (BSP_TS_Init(800, 480) == TS_OK)
          {
              bsp_ts_initialized = true;
          }

          assert(bsp_ts_initialized);
        }

        bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
        {
          /**
           * By default sampleTouch returns false,
           * return true if a touch has been detected, otherwise false.
           *
           * Coordinates are passed to the caller by reference by x and y.
           *
           * This function is called by the TouchGFX framework.
           * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
           *
           */
          if (bsp_ts_initialized)
          {
              TS_StateTypeDef state;
              BSP_TS_GetState(&state);
              if (state.touchDetected)
              {
                  x = state.touchX[0];
                  y = state.touchY[0];
                  return true;
              }
          }
          return false;
        }

        extern "C"
        {
          /******************************** LINK TS (TouchScreen) ***********************/
          /**
            * @brief  Manages error callback by re-initializing I2C.
            * @param  i2c_handler : I2C handler
            * @param  Addr: I2C Address
            * @retval None
            */
          static void I2Cx_Error(I2C_HandleTypeDef* i2c_handler, uint8_t Addr)
          {
              /* De-initialize the I2C communication bus */
              HAL_I2C_DeInit(i2c_handler);

              /* Re-Initialize the I2C communication bus */
              MX_I2C4_Init();
          }

          /**
            * @brief  Reads multiple data.
            * @param  i2c_handler : I2C handler
            * @param  Addr: I2C address
            * @param  Reg: Reg address
            * @param  MemAddress: memory address
            * @param  Buffer: Pointer to data buffer
            * @param  Length: Length of the data
            * @retval HAL status
            */
          static HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef* i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* Buffer, uint16_t Length)
          {
              HAL_StatusTypeDef status = HAL_OK;

              status = HAL_I2C_Mem_Read(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

              /* Check the communication status */
              if (status != HAL_OK)
              {
                  /* I2C error occured */
                  I2Cx_Error(i2c_handler, Addr);
              }
              return status;
          }

          /**
            * @brief  Writes a value in a register of the device through BUS in using DMA mode.
            * @param  i2c_handler : I2C handler
            * @param  Addr: Device address on BUS Bus.
            * @param  Reg: The target register address to write
            * @param  MemAddress: memory address
            * @param  Buffer: The target register value to be written
            * @param  Length: buffer size to be written
            * @retval HAL status
            */
          static HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef* i2c_handler, uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* Buffer, uint16_t Length)
          {
              HAL_StatusTypeDef status = HAL_OK;

              status = HAL_I2C_Mem_Write(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 1000);

              /* Check the communication status */
              if (status != HAL_OK)
              {
                  /* Re-Initiaize the I2C Bus */
                  I2Cx_Error(i2c_handler, Addr);
              }
              return status;
          }
          
12.	Import ft6x06, N25Q512A & the discovery files and add paths

_**STM32H750-Disco:**_
