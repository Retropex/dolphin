// Copyright 2017 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>
#include <string>

#include "InputCommon/ControlReference/ControlReference.h"

namespace ControllerEmu
{
enum Translatability
{
  DoNotTranslate,
  Translate
};

class Control
{
public:
  virtual ~Control();

  template <typename T = ControlState>
  T GetState() const
  {
    return control_ref->GetState<T>();
  }

  std::unique_ptr<ControlReference> const control_ref;
  const Translatability translate;
  const std::string name;
  std::string ui_name;

  // Used to display original name alongside the ui name
  bool display_alt = false;

protected:
  Control(std::unique_ptr<ControlReference> ref, Translatability translate, std::string name,
          std::string ui_name);
  Control(std::unique_ptr<ControlReference> ref, Translatability translate, std::string name);
};

}  // namespace ControllerEmu
