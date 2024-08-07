/*
 * lis2dw12.h
 *
 *  Created on: 3 Aug 2024
 *      Author: GraemeGets
 */

#ifndef USER_LIS2DW12_H_
#define USER_LIS2DW12_H_


#define LIS2_ADDR       0x18 //001100xb
#define LIS2_SCL_PIN    GPIO_Pin_2
#define LIS2_SDA_PIN    GPIO_Pin_1
#define LIS2_SCL_PORT   GPIOC
#define LIS2_SDA_PORT   GPIOC


/* REGISTER DEFINES */

// Temp Sensor Out
#define LIS2_REG_OUT_T_L                 0x0d    /r      /Temp Sensor Out
#define LIS2_REG_OUT_T_H                 0x0e    /r
#define LIS2_REG_OUT_T                   0x26    /r

// Who am I
#define LIS2_REG_WHO_AM_I                0x0f    /r      /Who am I

// Control Registers
#define LIS2_REG_CTRL1                   0x20    /rw
#define LIS2_REG_CTRL2                   0x21    /rw
#define LIS2_REG_CTRL3                   0x22    /rw
#define LIS2_REG_CTRL4_INT1_PAD_CTRL     0x23    /rw
#define LIS2_REG_CTRL5_INT2_PAD_CTRL     0x24    /rw
#define LIS2_REG_CTRL6                   0x25    /rw
#define LIS2_REG_CTRL7                   0x3f    /rw

// Status
#define LIS2_REG_STATUS                  0x27    /r

// Axis Out
#define LIS2_REG_OUT_X_L                 0x28    /r
#define LIS2_REG_OUT_X_H                 0x29    /r
#define LIS2_REG_OUT_Y_L                 0x2a    /r
#define LIS2_REG_OUT_Y_H                 0x2b    /r
#define LIS2_REG_OUT_Z_L                 0x2c    /r
#define LIS2_REG_OUT_Z_H                 0x2d    /r

// FIFO Control
#define LIS2_REG_FIFO_CTRL               0x2e    /rw
#define LIS2_REG_FIFO_SAMPLES            0x2f    /r

// TAP Thresholds
#define LIS2_REG_TAP_THS_X               0x30    /rw
#define LIS2_REG_TAP_THS_Y               0x31    /rw
#define LIS2_REG_TAP_THS_Z               0x32    /rw
#define LIS2_REG_TAP_SRC                 0x39    /r

// Interrupt
#define LIS2_REG_INT_DUR                 0x33    /rw
#define LIS2_REG_INT_ALL_SRC             0x3b    /r


// Wake Up
#define LIS2_REG_WAKE_UP_THS             0x34    /rw
#define LIS2_REG_WAKE_UP_DUR             0x35    /rw
#define LIS2_REG_WAKE_UP_SRC             0x38    /r

// Free Fall Config
#define LIS2_REG_FREE_FALL               0x36    /rw

#define LIS2_REG_STATUS_DUP              0x37    /r

// 6D Source
#define LIS2_REG_SIXD_SRC                0x3a    /r

// User Offsets?
#define LIS2_REG_X_OFS_USR               0x3c    /rw
#define LIS2_REG_Y_OFS_USR               0x3d    /rw
#define LIS2_REG_Z_OFS_USR               0x3e    /rw


/* CONTROL (20h) REGISTER 1
 *
 *--------------------------------------------------------------------
 *| ODR3 | ODR2 | ODR1 | ODR 0 | MODE1 | MODE0 | LP_MODE1 | LP_MODE0 |
 *--------------------------------------------------------------------
 * ODR      : output datarate and mode selection
 * MODE     : Mode Selection
 * LP_Mode  : Low Poer Mode
 */
#define LIS2_CTRL1_ODR_POS                 0x4
#define LIS2_CTRL1_MODE_POS                0x2
#define LIS2_CTRL1_LP_MODE_POS             0x0

#define LIS2_CTRL1_ODR_DOWN                0x0
#define LIS2_CTRL1_ODR_12_1p6              0x1
#define LIS2_CTRL1_ODR_12_5                0x2
#define LIS2_CTRL1_ODR_25_HZ               0x3
#define LIS2_CTRL1_ODR_50_HZ               0x4
#define LIS2_CTRL1_ODR_100_HZ              0x5
#define LIS2_CTRL1_ODR_200_HZ              0x6
#define LIS2_CTRL1_ODR_400_HZ              0x7
#define LIS2_CTRL1_ODR_800_200_HZ          0x8
#define LIS2_CTRL1_ODR_1600_200_HZ         0x9

#define LIS2_CTRL1_MODE_LOW_PWR            0x00
#define LIS2_CTRL1_MODE_HIGH_PER           0x01
#define LIS2_CTRL1_MODE_ON_DEMAND          0x03

#define LIS2_CTRL1_LP_MODE_1               0x00
#define LIS2_CTRL1_LP_MODE_2               0x01
#define LIS2_CTRL1_LP_MODE_3               0x02
#define LIS2_CTRL1_LP_MODE_4               0x03

/* --------------------
 * CONTROL REGISTER 2
 * --------------------
 * Register Layout
 * ---------------------------------------------------------------
 * | Boot | Soft Reset | 0 | CS_PU_DISC | BDU | IF_ADD_INC | SIM |
 * ---------------------------------------------------------------
 *
 * BOOT         : Boot enables retrieving the correct trimming parameters from nonvolatile memory into registers where trimming parameters are stored.
 * SOFT-RESET   : Soft reset acts as reset for all control registers, then goes to 0.
 * CS_PU_DISC   : Disconnect CS pull-up.
 * BDU          : Block data update.
 * IF_ADD_INC   : Register address automatically incremented during multiple byte access with a serial interface (I²C or SPI).
 * I2C_DISABLE  : Disable I²C communication protocol
 * SIM          : SPI serial interface mode selection
 * */

#define LIS2_CTRL_2_BOOT             1<<7
#define LIS2_CTRL_2_SOFT_RESET       1<<6
#define LIS2_CTRL_2_CS_PU_DISC       1<<4
#define LIS2_CRTL_2_BDU              1<<3
#define LIS2_CTRL_2_IF_ADD_INC       1<<2
#define LIS2_CTRL_2_I2C_DISABLE      1<<1
#define LIS2_CTRL_2_SIM              1<<0


/* --------------------
 * CONTROL REGISTER 3
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------
 * | ST2 | ST1 | PP_OD | LIR | H_LACTIVE | 0 | SLP_MODE_SEL | SPL_MODE_1 |
 * -----------------------------------------------------------------------
 * ST           : Self test
 * PP_OD        : Push-pull/open-drain selection on interrupt pad. Default value: 0
 * LIR          : Latched Interrupt. Switches between latched ('1'-logic) and pulsed ('0'-logic) mode for function source signals and interrupts routed to pins (wakeup, single/double-tap). Default value: 0
 * H_LACTIVE    : Interrupt active high (1) Low (0)
 * SLP_MODE_SEL : Single data conversion on demand mode selection:
 * SLP_MODE_1   :  Single data conversion on demand mode enable.
 */


#define LIS2_CTRL_3_ST_POS           0x6

#define LIS2_CTRL_3_PP_OD            1<<5
#define LIS2_CTRL_3_LIR              1<<4
#define LIS2_CTRL_3_H_ACTIVE         1<<3
#define LIS2_CTRL_3_SLP_MODE_SEL     1<<1
#define LIS2_CTRL_3_SLP_MODE_1       1<<0

#define LIS2_CTRL_3_ST_MORMAL_MODE   0
#define LIS2_CTRL_3_ST_POSITIVE      1
#define LIS2_CTRL_3_ST_NEGATIVE      2


/* --------------------
 * CONTROL REGISTER 4
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | INT1_6D | INT1_SINGLE_TAP | INT1_WU | INT1_FF | INT1_TAP | INT1_DIFF5 | INT1_FTH | INT1_DRDY |
 * -----------------------------------------------------------------------------------------------
 * INT1_6d          : 6D recognition is routed to INT1 pad. Default: 0
 * INT1_SINGLE_TAP  : Single-tap recognition is routed to INT1 pad. Default value: 0
 * INT1_WU          : Wakeup recognition is routed to INT1 pad. Default value: 0
 * INT1_FF          : Free-fall recognition is routed to INT1 pad. Default value: 0
 * INT1_TAP         : Double-tap recognition is routed to INT1 pad. Default value: 0
 * INT1_DIFF5       : FIFO full recognition is routed to INT1 pad. Default value: 0
 * INT1_DRDY        : Data-Ready is routed to INT1 pad. Default value: 0
 */

#define LIS2_CTRL_4_INT1_6D           1<<7
#define LIS2_CTRL_4_INT1_SINGLE_TAP   1<<6
#define LIS2_CTRL_4_INT1_WAKE_UP      1<<5
#define LIS2_CTRL_4_INT1_FREE_FALL    1<<4
#define LIS2_CTRL_4_INT1_TAP          1<<3
#define LIS2_CTRL_4_INT1_DIFF5        1<<2
#define LIS2_CTRL_4_INT1_FTH          1<<1
#define LIS2_CTRL_4_INT1_DRDY         1<<0

/* --------------------
 * CONTROL REGISTER 5 INT 2
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | INT2_SLEEP_STATE | INT2_SLEEP_CHG | INT2_BOOT | INT2_DRDY_T | INT2_OVR | INT2_DIFF5 | INT2_FTH | INT2_DRDY
 * -----------------------------------------------------------------------------------------------
 * INT2_SLEEP_STATE : Enable routing of SLEEP_STATE on INT2 pad. Default value: 0
 * INT2_SLEEP_CHG   : Sleep change status routed to INT2 pad. Default value: 0
 * INT2_BOOT       : Boot state routed to INT2 pad. Default value: 0
 * INT2_DRDY_T      : Temperature data-ready is routed to INT2. Default value: 0
 * INT2_OVR        : FIFO overrun interrupt is routed to INT2 pad. Default value: 0
 * INT2_DIFF5       : FIFO full recognition is routed to INT2 pad. Default value: 0
 * INT2_FTH        : FIFO threshold interrupt is routed to INT2 pad. Default value: 0
 * INT2_DRDY       : Data-ready is routed to INT2 pad. Default value: 0
 */

#define LIS2_CTRL_5_INT2_SLEEP_STATE 1<<7
#define LIS2_CTRL_5_INT2_SLEEP_CHG   1<<6
#define LIS2_CTRL_5_INT2_BOOT        1<<5
#define LIS2_CTRL_5_INT2_DRDY_T      1<<4
#define LIS2_CTRL_5_INT2_OVR         1<<3
#define LIS2_CTRL_5_INT2_DIFF5       1<<2
#define LIS2_CTRL_5_INT2_FTH         1<<1
#define LIS2_CTRL_5_INT2_DRDY        1<<0

/* --------------------
 * CONTROL REGISTER 6
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | BW_FILT1 |BW_FILT0| FS1 | FS0 | FDS | LOW_NOISE | 0 | 0 |
 * -----------------------------------------------------------------------------------------------
 * BW_FLT   : Bandwidth selection
 * FS       : Full-scale selection
 * FDS      : Filtered data type selection.
 * LOW_NOISE: Low-noise configuration.
 */

#define LIS2_CTRL_6_BW_FILTER_POS        0x6
#define LIS2_CTRL_6_BW_FULL_SCALE_POS    0x4

#define LIS2_CTRL_6_BW_FLT_ODR2      0x0
#define LIS2_CTRL_6_BW_FLT_ODR4      0x1
#define LIS2_CTRL_6_BW_FLT_ODR10     0x2
#define LIS2_CTRL_6_BW_FLT_ODR20     0x3

#define LIS2_CTRL_6_FS_2G            0x0
#define LIS2_CTRL_6_FS_4G            0x1
#define LIS2_CTRL_6_FS_8G            0x2
#define LIS2_CTRL_6_FS_16G           0x3

#define LIS2_CTRL_6_FDS              1<<3
#define LIS2_CTRL_6_LOW_NOISE        1<<2

/* --------------------
 * STATUS REGISTER 7
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | FIFO_THS | WU_IA | SLEEP_STATE | DOUBLE_TAP | SINGLE_TAP | 6D_IA | FF_IA | DRDY |
 * -----------------------------------------------------------------------------------------------
 * FIFO_THS     : FIFO threshold status flag.
 * WU_IA        : Wakeup event detection status.
 * SLEEP_STATE  : Sleep event status
 * DOUBLE_TAP   : Double-tap event status
 * SINGLE_TAP   : Single-tap event status
 * 6D_IA        : Source of change in position portrait/landscape/face-up/face-down.
 * FF_IA        : Free-fall event detection status.
 * DRDY         : Data-ready status
 */

#define LIS2_STATUS_FIFO_THS     1<<7
#define LIS2_STATUS_WU_IA        1<<6
#define LIS2_STATUS_SLEEP_STATE  1<<5
#define LIS2_STATUS_DOUBLE_TAP   1<<4
#define LIS2_STATUS_SINGLE_TAP   1<<3
#define LIS2_STATUS_6D_IA        1<<2
#define LIS2_STATUS_FF_IA        1<<1
#define LIS2_STATUS_DRDY         1<<0

/* --------------------
 * FIFO CONTROL REGISTER
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | FMode2 | FMode1 | FMode0 | FTH4 | FTH3 | FTH2 | FTH1 | FTH0 |
 * -----------------------------------------------------------------------------------------------
 * FMode[2:0]   : FIFO mode selection bits. Default: 000. For further details refer to Table 55. FIFO mode selection
 * FTH[4:0]     : FIFO threshold level setting.
 */
#define LIS2_CTRL_FIFO_MODE_BYPASS_POS               0x5
#define LIS2_CTRL_FIFO_THRESHOLD                     0x0

#define LIS2_CTRL_FIFO_MODE_BYPASS_OFF               0x0
#define LIS2_CTRL_FIFO_MODE_FULL                     0x1
#define LIS2_CTRL_FIFO_MODE_RESERVED
#define LIS2_CTRL_FIFO_MODE_CONTINUOUSE_TO_FIFO      0x3
#define LIS2_CTRL_FIFO_MODE_BYPASS_TO_CONTINOUSE     0x4
#define LIS2_CTRL_FIFO_MODE_CONTINUOUS               0x6


/* --------------------
 * FIFO SAMPLES REGISTER
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | FIFO_FTH | FIFO_OVR | Diff5 | Diff4 | Diff3 | Diff2 | Diff1 | Diff0 |
 * -----------------------------------------------------------------------------------------------
 * FIFO_FTH : FIFO threshold status flag.
 * FIFO_OVR : FIFO overrun status
 * Diff[5:0]: Represents the number of unread samples stored in FIFO.
*/

#define LIS2_FIFO_SAMPLES_FIFO_THS    1<<7
#define LIS2_FIFO_SAMPLES_OVR_MASK    1<<6

/* --------------------
 * TAP THRESHOLD X REGISTER
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------------------------
 * | 4D_EN | 6D_THS1 | 6D_THS0 | TAP_THSX_4 | TAP_THSX_3 | TAP_THSX_2 | TAP_THSX_1 | TAP_THSX_0 |
 * -----------------------------------------------------------------------------------------------
 * 4D_EN        : 4D detection portrait/landscape position enable.
 * 6D_THS[1:0]  : Thresholds for 4D/6D function @ FS = ±2 g
 * TAP_THSX[4:0]: Threshold for TAP recognition @ FS = ±2 g on X direction
 */

#define LIS2_TAP_THS_X_4D_EN        1<<7

#define LIS2_TAP_THS_X_6D_THS_POS    0x5

#define LIS2_TAP_THS_X_6D_6          0x0
#define LIS2_TAP_THS_X_6D_11         0x1
#define LIS2_TAP_THS_X_6D_16         0x2
#define LIS2_TAP_THS_X_6D_21         0x3

/* --------------------
 * TAP THRESHOLD Y REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------------------------------
 * | TAP_PRIOR_2 | TAP_PRIOR_1 | TAP_PRIOR_0 | TAP_THSY_4 | TAP_THSY_3 | TAP_THSY_2 | TAP_THSY_1 | TAP_THSY_0
 * ----------------------------------------------------------------------------------------------------------
 * TAP_PRIOR_[2:0]  : Selection of priority axis for tap detection
 * TAP_THSY_[4:0] Threshold for tap recognition @ FS = ±2 g on Y direction.
 */

#define LIS2_TAP_THS_Y_PRIOR_POS     0x5
#define LIS2_TAP_THS_Y_THSY_POS      0x0

#define LIS2_TAP_THS_Y_PRIOR_0_X_Y_Z   0x0
#define LIS2_TAP_THS_Y_PRIOR_1_Y_X_Z   0x1
#define LIS2_TAP_THS_Y_PRIOR_2_X_Z_Y   0x2
#define LIS2_TAP_THS_Y_PRIOR_3_Z_Y_X   0x3
#define LIS2_TAP_THS_Y_PRIOR_4_X_Y_Z   0x4
#define LIS2_TAP_THS_Y_PRIOR_5_Y_Z_X   0x5
#define LIS2_TAP_THS_Y_PRIOR_6_Z_X_Y   0x6
#define LIS2_TAP_THS_Y_PRIOR_7_Z_Y_X   0x7

/* --------------------
 * TAP THRESHOLD Z REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------------------------------
 * | TAP_X_EN | TAP_Y_EN | TAP_Z_EN | TAP_THSZ_4 | TAP_THSZ_3 | TAP_THSZ_2 | TAP_THSZ_1 | TAP_THSZ_0
 * ----------------------------------------------------------------------------------------------------------
 * TAP_X_EN         : Enables X direction in tap recognition.
 * TAP_Y_EN         : Enables Y direction in tap recognition
 * TAP_Z_EN         : Enables Z direction in tap recognition.
 * TAP_THSZ_[4:0]   : Threshold for tap recognition @ FS = ±2 g on Z direction.
 */


#define  LIS2_TAP_X_EN_POS    0x7
#define  LIS2_TAP_Y_EN_POS    0x6
#define  LIS2_TAP_Z_EN_POS    0x5
#define  LIS2_TAP_THS_Z_POS   0x0

/* --------------------
 * INT DURATION REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------------------------------
 * | LATENCY3 | LATENCY2 | LATENCY1 | LATENCY0 | QUIET1 | QUIET0 | SHOCK1 | SHOCK0
 * ----------------------------------------------------------------------------------------------------------
 * LATENCY[3:0] : Duration of maximum time gap for double-tap recognition.
 * QUIET[1:0]   : Expected quiet time after a tap detection
 * SHOCK[1:0]   : Maximum duration of over-threshold event:
 */

#define  LIS2_INT_DUR_LATENCY_POS 0x4
#define  LIS2_INT_DUR_QUITE_POS   0x2
#define  LIS2_INT_DUR_SHOCK_POS   0x1


/* --------------------
 * WAKE UP THRESHOLD REGISTER
 * --------------------
 * Register Layout
 * ------------------------------------------------------------------------------------------
 * | SINGLE_DOUBLE_TAP | SLEEP_ON | WK_THS5 | WK_THS4 | WK_THS3 | WK_THS2 | WK_THS1 | WK_THS0
 * ------------------------------------------------------------------------------------------
 * SINGLE_DOUBLE_ TAP   : Enable single/double-tap event.
 * SLEEP_ON             : Sleep (inactivity) enable.
 * WK_THS[5:0]          : Wakeup threshold,
 */

#define LIS2_WAKE_UP_THS_TAP_EN      1<<7
#define LIS2_WAKE_UP_THS_SLEEP       1<<6
#define LIS2_WAKE_UP_THS_WAKE_UP_POS 0x0

/* --------------------
 * WAKE UP DURATION REGISTER
 * --------------------
 * Register Layout
 * --------------------------------------------------------------------------------------------------
 * | FF_DUR5 | WAKE_DUR1 | WAKE_DUR0 | STATIONARY | SLEEP_DUR3 | SLEEP_DUR2 | SLEEP_DUR1 | SLEEP_DUR0
 * --------------------------------------------------------------------------------------------------
 *  FF_DUR5         : Free-fall duration.
 *  WAKE_DUR[1:0]   : Wakeup duration.
 *  STATIONARY      : Enable stationary detection / motion detection with no automatic ODR change when detecting stationary state
 *  SLEEP_DUR[3:0]  : Duration to go in sleep mode.
 */

#define LIS2_WAKE_UP_DUR_FF             1<<7
#define LIS2_WAKE_UP_DUR_DURATION_POS   0x5
#define LIS2_WAKE_UP_DUR_STATIONARY     1<<4
#define LIS2_WAKE_UP_DUR_SLEEP_POS       0x0

/* --------------------
 * FREE FALL REGISTER
 * --------------------
 * Register Layout
 * --------------------------------------------------------------------------------------------------
 * | FF_DUR4 |  FF_DUR3 | FF_DUR2 | FF_DUR1 | FF_DUR0 | FF_THS2 | FF_THS1 | FF_THS0
 * --------------------------------------------------------------------------------------------------
 * FF_DUR [4:0] : Free-fall duration. In conjunction with FF_DUR5 bit in
 * FF_THS [2:0] : Free-fall threshold
 */

#define LIS2_FREE_FALL_DURATION_POS      0x4
#define LIS2_FREE_FALL_THRESHOLD_POS     0x0

#define LIS2_FREE_FALL_THRESHOLD_5       0x0
#define LIS2_FREE_FALL_THRESHOLD_7       0x1
#define LIS2_FREE_FALL_THRESHOLD_8       0x2
#define LIS2_FREE_FALL_THRESHOLD_10      0x3
#define LIS2_FREE_FALL_THRESHOLD_11      0x4
#define LIS2_FREE_FALL_THRESHOLD_13      0x5
#define LIS2_FREE_FALL_THRESHOLD_15      0x6
#define LIS2_FREE_FALL_THRESHOLD_16      0x7

/* --------------------
 * STATUS DUP REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------
 * | OVR | DRDY_T | SLEEP_STATE_IA | DOUBLE_TAP | SINGLE_TAP | 6D_IA | FF_IA | DRDY |
 * ----------------------------------------------------------------------------------
 * OVR              : FIFO overrun status flag.
 * DRDY_T           : Temperature status.
 * SLEEP_STATE_IA   : Sleep event status.
 * DOUBLE_TAP       : Double-tap event status:
 * SINGLE_TAP       : Single-tap event status:
 * 6D_IA            : Source of change in position portrait/landscape/face-up/face-down.
 * FF_IA            : Free-fall event detection status.
 * DRDY             : Data-ready status.
 */


#define LIS2_STATUS_DUP_OVR             1<<7
#define LIS2_STATUS_DUP_DRDY_TEMP       1<<6
#define LIS2_STATUS_DUP_SLEEP_STATE     1<<5
#define LIS2_STATUS_DUP_DOUBLE_TAP      1<<4
#define LIS2_STATUS_DUP_SINGLE_TAP      1<<3
#define LIS2_STATUS_DUP_6D              1<<2
#define LIS2_STATUS_DUP_FREE_FALL       1<<1
#define LIS2_STATUS_DUP_DATA_READY      1<<0

/* --------------------
 * WAKE_UP_SRC (38h) REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------
 * | 0 | 0 | FF_IA | SLEEP_STATE_IA | WU_IA | X_WU | Y_WU Z | Z_WU |
 * ----------------------------------------------------------------------------------
 * FF_IA            : Free-fall event detection status.
 * SLEEP_STATE_IA   : Sleep event status.
 * WU_IA            : Wakeup event detection status.
 * X_WU             : Wakeup event detection status on X-axis.
 * Y_WU             : Wakeup event detection status on Y-axis.
 * Z_WU             : Wakeup event detection status on Z-axis.
 */

#define LIS2_WAKE_UP_SOURCE_FF               1<<5
#define LIS2_WAKE_UP_SOURCE_SLEEP_STATE      1<<4
#define LIS2_WAKE_UP_SOURCE_WAKE_UP          1<<3
#define LIS2_WAKE_UP_SOURCE_WAKE_UP_X        1<<2
#define LIS2_WAKE_UP_SOURCE_WAKE_UP_Y        1<<1
#define LIS2_WAKE_UP_SOURCE_WAKE_UP_Z        1<<0

/* --------------------
 * TAP SOURCE (39h) REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------
 * | 0 | TAP_IA | SINGLE_TAP | DOUBLE_TAP | TAP_SIGN X_TAP | Y_TAP | Z_TAP
 * ----------------------------------------------------------------------------------
 * TAP_IA       : Tap event status.
 * SINGLE_TAP   : Single-tap event status.
 * DOUBLE_TAP   : Double-tap event status.
 * TAP_SIGN     : Sign of acceleration detected by tap event.
 * X_TAP        : Tap event detection status on X-axis.
 * Y_TAP        : Tap event detection status on Y-axis.
 * Z_TAP        : Tap event detection status on Z-axis.
 */

#define LIS2_TAP_SOURCE_EVENT       0x6
#define LIS2_TAP_SOURCE_SINGLE_TAP  0x5
#define LIS2_TAP_SOURCE_DOUBLE_TAP  0x4
#define LIS2_TAP_SOURCE_SIGN        0x3
#define LIS2_TAP_SOURCE_X           0x2
#define LIS2_TAP_SOURCE_Y           0x1
#define LIS2_TAP_SOURCE_Z           0x0

/* --------------------
 * SIXD_SRC (3Ah) REGISTER
 * --------------------
 * Register Layout
 * ----------------------------------------------------------------------------------
 * | 0 | 6D_IA | ZH | ZL | YH | YL | XH | XL
 * ----------------------------------------------------------------------------------
 * 6D_IA    : Source of change in position portrait/landscape/face-up/face-down.
 * ZH       : ZH over threshold.
 * ZL       : ZL over threshold.
 * YH       : YH over threshold.
 * YL       : YL over threshold.
 * XH       : XH over threshold.
 * XL       : XL over threshold.
 */

#define LIS2_SIXD_SOURCE_6D      1<<6
#define LIS2_SIXD_SOURCE_ZH      1<<5
#define LIS2_SIXD_SOURCE_ZL      1<<4
#define LIS2_SIXD_SOURCE_YH      1<<3
#define LIS2_SIXD_SOURCE_YL      1<<2
#define LIS2_SIXD_SOURCE_XH      1<<1
#define LIS2_SIXD_SOURCE_XL      1<<0

/* --------------------
 * ALL_INT_SRC (3Bh) REGISTER
 * --------------------
 * Register Layout
 * -----------------------------------------------------------------------------
 * | 0 | 0 | SLEEP_CHANGE_IA | 6D_IA | DOUBLE_TAP | SINGLE_TAP | WU_IA | FF_IA |
 * -----------------------------------------------------------------------------
 *  * NOTE : Reading this register, all related interrupt function flags routed to the INT pads are reset simultaneously.
 *
 * SLEEP_CHANGE_IA  :
 * 6D_IA            :
 * DOUBLE_TAP       :
 * SINGLE_TAP       :
 * WU_IA            :
 * FF_IA            :
 */

#define LIS2_ALL_INT_SOURCE_SLEEP_CHANGE        1<<5
#define LIS2_ALL_INT_SOURCE_6D                  1<<4
#define LIS2_ALL_INT_SOURCE_DOUBLE_TAP          1<<3
#define LIS2_ALL_INT_SOURCE_SINGLE_TAP          1<<2
#define LIS2_ALL_INT_SOURCE_WAKE_UP             1<<1
#define LIS2_ALL_INT_SOURCE_FREE_FALL           1<<0

/* --------------------
 * CTRL7 (3Fh) REGISTER
 * --------------------
 * Register Layout
 * -------------------------------------------------------------------------------------------------------------------------
 * | DRDY_PULSED | INT2_ON_INT1 | INTERRUPTS_ENABLE | USR_OFF_ON_OUT | USR_OFF_ON_WU | USR_OFF _W | HP_REF_MODE | LPASS_ON6D
 * --------------------------------------------------------------------------------------------------------------------------
 * DRDY_PULSED          : Switches between latched and pulsed mode for data ready interrupt.
 * INT2_ON_INT1         : Signal routing.
 * INTERRUPTS_ENABLE    : Enable interrupts.
 * USR_OFF_ON_OUT       : Enable application of user offset value on XL output data registers.
 * USR_OFF_ON_WU        : Enable application of user offset value on XL data for wakeup function only.
 * USR_OFF _W           : Selects the weight of the user offset words specified by X_OFS_USR_[7:0], Y_OFS_USR_[7:0] and Z_OFS_USR_[7:0] bits.
 * HP_REF_MODE          : High-pass filter reference mode enable.
 * LPASS_ON6D           : Low-pass filter
 */



/* -------------------------------------------------
 * PUBLIC PROTOTYPES
 * -------------------------------------------------
 */
void init_lis2dw12();


uint8_t lis2_read(uint8_t readAddr);
void lis2d_write(uint8_t addr, uint8_t data);

#endif /* USER_LIS2DW12_H_ */
