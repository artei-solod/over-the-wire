#include <iostream>
#include "common.hpp"

namespace OverTheWire::Example {
  void init(Napi::Env env, Napi::Object exports);

  Napi::Value da(const Napi::CallbackInfo&);
}
