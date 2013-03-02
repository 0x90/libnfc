/*-
 * Public platform independent Near Field Communication (NFC) library
 *
 * Copyright (C) 2013, Romuald Conty
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

/**
 * @file usbbus.h
 * @brief libusb 0.1 driver header
 */

#ifndef __NFC_BUS_USB_H__
#  define __NFC_BUS_USB_H__

#ifndef _WIN32
// Under POSIX system, we use libusb (>= 0.1.12)
#include <usb.h>
#define USB_TIMEDOUT ETIMEDOUT
#define _usb_strerror( X ) strerror(-X)
#else
// Under Windows we use libusb-win32 (>= 1.2.5)
#include <lusb0_usb.h>
#define USB_TIMEDOUT 116
#define _usb_strerror( X ) usb_strerror()
#endif

#include <stdbool.h>
#include <string.h>

// Global flag to know if usb_init() has already been called or not
extern bool usb_initialized;

int usb_prepare(void);

#endif // __NFC_BUS_USB_H__
