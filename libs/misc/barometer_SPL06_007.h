/**************************************************************************/
/*!
    @file     barometer_SPL06_007.h

*/
/**************************************************************************/

#ifndef BAROMETER_SPL06_007
#define BAROMETER_SPL06_007

#define SPL06_I2CADDR_DEFAULT (0x77) ///< Default breakout addres
/*=========================================================================*/

#define SPL06_PRSB2 0x00       ///< Highest byte of pressure data
#define SPL06_TMPB2 0x03       ///< Highest byte of temperature data
#define SPL06_PRSCFG 0x06      ///< Pressure configuration
#define SPL06_TMPCFG 0x07      ///< Temperature configuration
#define SPL06_MEASCFG 0x08     ///< Sensor configuration & status
#define SPL06_CFGREG 0x09      ///< Interrupt/FIFO configuration
#define SPL06_RESET 0x0C       ///< Soft reset
#define SPL06_PRODREVID 0x0D   ///< Register that contains the part ID
#define SPL06_COEF_START 0x10  ///< Start of calibration coefficients
#define SPL06_COEF_NUM 18	   ///< Number of calibration coefficient registers

/** The measurement rate ranges */
typedef enum {
  SPL06_1HZ,   ///< 1 Hz
  SPL06_2HZ,   ///< 2 Hz
  SPL06_4HZ,   ///< 4 Hz
  SPL06_8HZ,   ///< 8 Hz
  SPL06_16HZ,  ///< 16 Hz
  SPL06_32HZ,  ///< 32 Hz
  SPL06_64HZ,  ///< 64 Hz
  SPL06_128HZ, ///< 128 Hz
} spl06_rate_t;

/** The  oversample rate ranges */
typedef enum {
  SPL06_1SAMPLE,    ///< 1 x oversampling
  SPL06_2SAMPLES,   ///< 2 x oversampling
  SPL06_4SAMPLES,   ///< 4 x oversampling
  SPL06_8SAMPLES,   ///< 8 x oversampling
  SPL06_16SAMPLES,  ///< 16 x oversampling
  SPL06_32SAMPLES,  ///< 32 x oversampling
  SPL06_64SAMPLES,  ///< 64 x oversampling
  SPL06_128SAMPLES, ///< 128 x oversampling
} spl06_oversample_t;

/** The  oversample rate ranges */
typedef enum {
  SPL06_IDLE = 0b000,            ///< Stopped/idle
  SPL06_ONE_PRESSURE = 0b001,    ///< Take single pressure measurement
  SPL06_ONE_TEMPERATURE = 0b010, ///< Take single temperature measurement
  SPL06_CONT_PRESSURE = 0b101,   ///< Continuous pressure measurements
  SPL06_CONT_TEMP = 0b110,       ///< Continuous pressure measurements
  SPL06_CONT_PRESTEMP = 0b111,   ///< Continuous temp+pressure measurements
} spl06_mode_t;

#endif
