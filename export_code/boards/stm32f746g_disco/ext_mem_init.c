/*
 * Coskun ERGAN
 *
 * Memory Map implementation for stm32f7
 */

#include <zephyr/device.h>
#include <zephyr/zephyr.h>
#include <soc.h>

#define QUAD_INOUT_FAST_READ_CMD        0xEB

#define N25Q128A_DUMMY_CYCLES_READ      10

void BSP_QSPI_EnableMemoryMappedMode()
{
    QSPI_CommandTypeDef      cmd = {0};

    QUADSPI_TypeDef *Instance = (QUADSPI_TypeDef *)QSPI_R_BASE;

    /* Configure the command for the read instruction */
    cmd.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
    cmd.Instruction       = QUAD_INOUT_FAST_READ_CMD;
    cmd.AddressMode       = QSPI_ADDRESS_4_LINES;
    cmd.AddressSize       = QSPI_ADDRESS_24_BITS;
    cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    cmd.DataMode          = QSPI_DATA_4_LINES;
    cmd.DummyCycles       = N25Q128A_DUMMY_CYCLES_READ;
    cmd.DdrMode           = QSPI_DDR_MODE_DISABLE;
    cmd.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
    cmd.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

    WRITE_REG(Instance->CCR, (cmd.DdrMode | cmd.DdrHoldHalfCycle | cmd.SIOOMode |
                                     cmd.DataMode | (cmd.DummyCycles << QUADSPI_CCR_DCYC_Pos) |
                                     cmd.AlternateBytesSize | cmd.AlternateByteMode |
                                     cmd.AddressSize | cmd.AddressMode | cmd.InstructionMode |
                                     cmd.Instruction | QUADSPI_CCR_FMODE));

    NVIC_DisableIRQ(QUADSPI_IRQn);
}

static int qspi_ext_mem_init(const struct device *dev)
{
    ARG_UNUSED(dev);

    BSP_QSPI_EnableMemoryMappedMode();

    return 0;
}

SYS_INIT(qspi_ext_mem_init, POST_KERNEL, CONFIG_APPLICATION_INIT_PRIORITY);