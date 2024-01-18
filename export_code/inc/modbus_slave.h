/*
    Mosbus Slave Lib

    Created on: Jan 18, 2024

    Author: Coskun ERGAN
*/

#pragma once
#include <stdio.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>
#include <zephyr/modbus/modbus.h>

#include <zpp.hpp>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(mbc_sample, LOG_LEVEL_INF);

namespace device_modbus_slave
{
    using namespace zpp;
    class modbus_slave
    {
    public:
        modbus_slave(const char *dev, const modbus_iface_param param)
        {
            client_iface = modbus_iface_get_by_name(dev);
            if(modbus_init_server(client_iface, param))
            {
                LOG_ERR("Modbus RTU server initialization failed");
            }
        }

        ~modbus_slave() = default;
        modbus_slave(modbus_slave &&) = delete;
        modbus_slave &operator=(modbus_slave &&) = delete;
        modbus_slave(const modbus_slave &) = delete;
        modbus_slave &operator=(const modbus_slave &) = delete;

    private:
        int client_iface;
    };
}



