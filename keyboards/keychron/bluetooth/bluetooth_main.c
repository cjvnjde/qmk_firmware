/* Copyright 2022 @ lokher (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "bluetooth.h"
#include "transport.h"
#include "report_buffer.h"

__attribute__((weak)) void bluetooth_pre_task(void) {}
__attribute__((weak)) void bluetooth_post_task(void) {}

/* Called from core QMK (action.c / send_string.c) when KC_BLUETOOTH_ENABLE is defined.
 * Processes pending bluetooth reports during send_string delays. */
void send_string_task(void) {
    if (get_transport() == TRANSPORT_BLUETOOTH) {
#ifndef DISABLE_REPORT_BUFFER
        report_buffer_task();
#endif
    }
}

void bluetooth_tasks(void) {
    bluetooth_pre_task();
    bluetooth_task();
    bluetooth_post_task();

    /* usb_remote_wakeup() should be invoked last so that we have chance
     * to switch to bluetooth after start-up when usb is not connected
     */
    if (get_transport() == TRANSPORT_USB) usb_remote_wakeup();
}

void housekeeping_task_kb(void) {
    bluetooth_tasks();
}
