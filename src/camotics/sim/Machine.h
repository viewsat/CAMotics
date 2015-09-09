/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#ifndef CAMOTICS_MACHINE_H
#define CAMOTICS_MACHINE_H

#include <tplang/MachinePipeline.h>
#include <tplang/MoveStream.h>

#include <ostream>


namespace tplang {class MachineMatrix;}

namespace CAMotics {
  class Move;

  class Machine : public tplang::MachinePipeline, public tplang::MoveStream {
    double time;
    double distance;
    // TODO Load machine configuration, ramp up/down, rapid feed, etc.

  public:
    Machine(double rapidFeed = 1000);
    virtual ~Machine() {} // Compiler needs this

    double getTime() const {return time;}
    double getDistance() const {return distance;}

    // From MachineInterface
    void reset() {time = distance = 0; tplang::MachinePipeline::reset();}

    // From tplang::MoveStream
    void move(const Move &move);
  };
}

#endif // CAMOTICS_MACHINE_H
