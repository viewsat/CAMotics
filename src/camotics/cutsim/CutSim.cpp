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

#include "CutSim.h"

#include "ToolPathTask.h"
#include "SurfaceTask.h"
#include "ReduceTask.h"

#include <cbang/config/Options.h>
#include <cbang/os/SystemInfo.h>

using namespace std;
using namespace cb;
using namespace CAMotics;


CutSim::CutSim(Options &options) :
  threads(SystemInfo::instance().getCPUCount()) {
  options.addTarget("threads", threads, "Number of simulation threads.");
}


CutSim::~CutSim() {}


SmartPointer<ToolPath> CutSim::computeToolPath(const Project &project) {
  task = new ToolPathTask(project);
  task->run();
  return task.cast<ToolPathTask>()->getPath();
}


SmartPointer<Surface> CutSim::computeSurface
(const SmartPointer<Simulation> &sim, const string &filename) {
  task = new SurfaceTask(threads, filename, sim);
  task->run();
  return task.cast<SurfaceTask>()->getSurface();
}



void CutSim::reduceSurface(Surface &surface) {
  task = new ReduceTask(surface);
  task->run();
}


void CutSim::interrupt() {
  if (!task.isNull()) task->interrupt();
}
