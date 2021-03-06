/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#ifdef LRN_OP

#pragma once

#include <string>
#include "framework/operator.h"
#include "operators/kernel/lrn_kernel.h"
#include "operators/op_param.h"

namespace paddle_mobile {
namespace operators {
using std::string;
template <typename DeviceType, typename T>
class LrnOp : public framework::OperatorWithKernel<
                  DeviceType, LrnParam, operators::LrnKernel<DeviceType, T>> {
 public:
  LrnOp(const string &type, const VariableNameMap &inputs,
        const VariableNameMap &outputs, const framework::AttributeMap &attrs,
        std::shared_ptr<framework::Scope> scope)
      : framework::OperatorWithKernel<DeviceType, LrnParam,
                                      operators::LrnKernel<DeviceType, T>>(
            type, inputs, outputs, attrs, scope) {}

  using framework::OperatorWithKernel<
      DeviceType, LrnParam,
      operators::LrnKernel<DeviceType, T>>::OperatorWithKernel;
  void InferShape() const override;

 protected:
};

}  // namespace operators
}  // namespace paddle_mobile

#ifdef PADDLE_MOBILE_CPU
USE_OP_CPU(lrn);
#endif
#ifdef PADDLE_MOBILE_MALI_GPU
USE_OP_MALI_GPU(lrn);
#endif
#ifdef PADDLE_MOBILE_FPGA
#endif

#endif
