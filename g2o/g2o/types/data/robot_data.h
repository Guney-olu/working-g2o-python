// g2o - General Graph Optimization
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef G2O_ROBOT_DATA_H
#define G2O_ROBOT_DATA_H

#include <iosfwd>
#include <string>

#include "g2o/core/hyper_graph.h"
#include "g2o/core/optimizable_graph.h"
#include "g2o_types_data_api.h"

namespace g2o {

/**
 * \brief data recorded by the robot
 */
class G2O_TYPES_DATA_API RobotData : public HyperGraph::Data {
 public:
  [[nodiscard]] double timestamp() const { return timestamp_; }
  void setTimestamp(double ts);

  [[nodiscard]] double loggerTimestamp() const { return loggerTimestamp_; }
  void setLoggerTimestamp(double ts);

  [[nodiscard]] const std::string& tag() const { return tag_; }
  void setTag(const std::string& tag);

  [[nodiscard]] const std::string& hostname() const { return hostname_; }
  void setHostname(const std::string& hostname);

 protected:
  double timestamp_ = -1.;  ///< timestamp when the measurement was generated
  double loggerTimestamp_ =
      -1.;  ///< timestamp when the measurement was recorded
  std::string
      tag_;  ///< string tag (FLASER, ROBOTLASER, ODOM..) of the line in the log
  std::string hostname_;  ///< name of the computer/robot generating the data
};

}  // namespace g2o

#endif
