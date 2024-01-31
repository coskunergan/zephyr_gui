/*
    TFT Modbus Lib

    Created on: Jan 18, 2024

    Author: Coskun ERGAN
*/

#pragma once
#include <stdio.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include "modbus_slave.h"

#include <zpp.hpp>
#include <zpp/timer.hpp>
#include <chrono>

#include "pan_procces.h"
#include "lvgl.h"

extern tft_registers_t tft_regs;

namespace device_modbus_tft
{
    using namespace zpp;
    using namespace std::chrono;
    using namespace device_modbus_slave;
    ZPP_THREAD_STACK_DEFINE(tft_modbus_stack, 2048);
    const uint16_t tft_slave_id{1};
    const size_t tft_modbus_try_count{5};// ~5sn
    const milliseconds modbus_stream_check_delay{10s};
    bool tft_enb_state = false;

    static int holding_reg_rd(uint16_t addr, uint16_t *reg)
    {
        if(addr >= (sizeof(tft_regs) / 2))
        {
            return -ENOTSUP;
        }

        *reg = ((uint16_t *)&tft_regs)[addr];

        LOG_INF("Holding register read, addr %u", addr);

        return 0;
    }

    static int holding_reg_wr(uint16_t addr, uint16_t reg)
    {
        if(addr >= (sizeof(tft_regs) / 2))
        {
            return -ENOTSUP;
        }

        ((uint16_t *)&tft_regs)[addr] = reg;

        LOG_INF("Holding register write, addr %u", addr);

        return 0;
    }

    static struct modbus_user_callbacks mbs_cbs =
    {
        .coil_rd = nullptr,
        .coil_wr = nullptr,
        .holding_reg_rd = holding_reg_rd,
        .holding_reg_wr = holding_reg_wr,
    };
    const static struct modbus_iface_param client_param =
    {
        .mode = MODBUS_MODE_RTU,
        //.rx_timeout = 500000, // 500mSn
        .server = {
            .user_cb = &mbs_cbs,
            .unit_id = 1,
        },
        .serial = {
            .baud = 9600,
            .parity = UART_CFG_PARITY_NONE,
            .stop_bits_client = UART_CFG_STOP_BITS_1,
        },
    };

    class modbus_tft : public modbus_slave
    {
    public:
        modbus_tft() : modbus_slave("modbus0", client_param)
        {
            static thread_data tcb;
            static thread t;
            const thread_attr attrs(
                thread_prio::preempt(10),
                thread_inherit_perms::no,
                thread_suspend::no
            );
            t = thread(tcb, tft_modbus_stack(), attrs, task_modbus_tft, this);
        }
        ~modbus_tft() = default;
        modbus_tft(modbus_tft &&) = delete;
        modbus_tft &operator=(modbus_tft &&) = delete;
        modbus_tft(const modbus_tft &) = delete;
        modbus_tft &operator=(const modbus_tft &) = delete;
        void clear_fail()
        {
            tft_regs.read_fail_count = 0;
            tft_regs.write_fail_count = 0;
            tft_regs.modbus_status.data_stream_fail = false;
        }
    private:
        static void task_modbus_tft(modbus_tft *mb) noexcept
        {
            static bool logo_off_state = false;
            while(1)
            {
                this_thread::sleep_for(100ms);
                tft_regs.modbus_status.data_stream_fail = false;
                if(tft_regs.write_regs.master_param_bits.logo_off_state && logo_off_state == false)
                {
                    logo_off_state = true;
                    lv_obj_t *act_scr = lv_scr_act();
                    lv_event_send(act_scr, LV_EVENT_VALUE_CHANGED, NULL);
                }
            }
        }
    };

    modbus_tft modbus;
}
