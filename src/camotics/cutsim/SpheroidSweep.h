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

#ifndef CAMOTICS_SPHEROID_SWEEP_H
#define CAMOTICS_SPHEROID_SWEEP_H

#include "Sweep.h"

namespace CAMotics {
  class SpheroidSweep : public Sweep {
    real radius;
    real length;

    Vector3R scale;
    real radius2;

  public:
    SpheroidSweep(real radius, real length = -1);

    // From Sweep
    void getBBoxes(const Vector3R &start, const Vector3R &end,
                   std::vector<Rectangle3R> &bboxes, real tolerance) const;
    bool contains(const Vector3R &start, const Vector3R &end,
                  const Vector3R &p) const;
  };
}

#endif // CAMOTICS_SPHEROID_SWEEP_H

