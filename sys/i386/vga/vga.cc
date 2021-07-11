/*
 * vga.cc
 *
 * Basic VGA driver
 *
 * This file is a part of <OS>
 * 
 * <OS> is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * <OS> is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "vga.h"

using namespace Kernel
{
    // Draw to screen
    VGA::Draw()
    {

    }

    // Clear framebuffer
    VGA::ClearSrc()
    {

    }

    // Pull cursor position from vmem
    VGA::GetPosition()
    {
        uint8_t position;
        return position;
    }
}