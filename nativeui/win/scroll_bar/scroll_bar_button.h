// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_BUTTON_H_
#define NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_BUTTON_H_

#include "nativeui/win/scroll_bar/repeat_controller.h"
#include "nativeui/win/view_win.h"

namespace nu {

class ScrollBar;

class ScrollBarButton : public ViewImpl {
 public:
  enum Type {
    Up,
    Down,
    Left,
    Right,
  };

  ScrollBarButton(Type type, ScrollBar* scroll_bar);
  ~ScrollBarButton() override;

  // ViewImpl:
  void OnMouseEnter() override;
  void OnMouseLeave() override;
  bool OnMouseClick(UINT message, UINT flags, const Point& point) override;
  void Draw(PainterWin* painter, const Rect& dirty) override;

  NativeTheme::ScrollbarArrowExtraParams* params() { return &params_; }

 private:
  void OnClick();

  NativeTheme::ScrollbarArrowExtraParams params_ = {0};

  // The repeat controller that we use to repeatedly click the button when the
  // mouse button is down.
  RepeatController repeater_;

  Type type_;
  ScrollBar* scroll_bar_;  // weak ref
};

}  // namespace nu

#endif  // NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_BUTTON_H_
