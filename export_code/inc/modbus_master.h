/*
    Mosbus Master Lib

    Created on: Dec 28, 2023

    Author: Coskun ERGAN
*/

#pragma once
#include <stdio.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/modbus/modbus.h>

#include <zpp.hpp>

namespace device_modbus_master
{
    using namespace zpp;
    static condition_variable modbus_read_cv;
    static condition_variable modbus_write_cv;
    class modbus_master
    {
    public:
        modbus_master(const char *dev, const modbus_iface_param param)
        {
            client_iface_master = modbus_iface_get_by_name(dev);
            if(modbus_init_client(client_iface_master, param))
            {
                LOG_ERR("Modbus Master RTU client initialization failed");
            }
        }

        ~modbus_master() = default;
        modbus_master(modbus_master &&) = delete;
        modbus_master &operator=(modbus_master &&) = delete;
        modbus_master(const modbus_master &) = delete;
        modbus_master &operator=(const modbus_master &) = delete;

        int read_input_reg(uint16_t node, uint16_t adr, uint16_t *buff, uint16_t size)
        {
            int ret = modbus_read_input_regs(client_iface_master, node, adr, buff, size);
            if(ret != 0)
            {
                LOG_ERR("Read failed input with %d", ret);
            }
            else
            {
                (void)modbus_read_cv.notify_all();
            }
            return ret;
        }

        int read_holding_reg(uint16_t node, uint16_t adr, uint16_t *buff, uint16_t size)
        {
            int ret = modbus_read_holding_regs(client_iface_master, node, adr, buff, size);
            if(ret != 0)
            {
                LOG_ERR("Read failed holding with %d", ret);
            }
            else
            {
                (void)modbus_read_cv.notify_all();
            }
            return ret;
        }
        int write_holding_reg(uint16_t node, uint16_t adr, uint16_t *buff, uint16_t size)
        {
            int ret = modbus_write_holding_regs(client_iface_master, node, adr, buff, size);
            // if(ret != 0)
            // {
            //     LOG_ERR("Write failed with %d", ret);
            // }
            // else
            // {
            //     (void)modbus_write_cv.notify_all();
            // }
            return ret;
        }
        condition_variable &mb_read_cv()
        {
            return modbus_read_cv;
        }
        condition_variable &mb_write_cv()
        {
            return modbus_write_cv;
        }
    private:
        int client_iface_master;
    };
}
