// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_H_
#define NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_H_

#include <vector>

#include "nativeui/win/scroll_bar/scroll_bar_button.h"
#include "nativeui/win/scroll_bar/scroll_bar_thumb.h"
#include "nativeui/win/scroll_win.h"

namespace nu {

// Draws the native scroll bar.
class ScrollBar : public ContainerImpl,
                  public ContainerImpl::Delegate {
 public:
  ScrollBar(bool vertical, ScrollImpl* scroll);
  ~ScrollBar() override;

  void LineUp();
  void LineDown();
  void PageUp();
  void PageDown();

  int GetValue() const;
  void SetValue(int value);

  // ContainerImpl::Delegate:
  void Layout() override;
  void ForEach(const std::function<bool(ViewImpl*)>& callback) override;
  bool HasChild(ViewImpl* child) override;

  // ViewImpl:
  void OnMouseEnter() override;
  void OnMouseLeave() override;
  bool OnMouseClick(UINT message, UINT flags, const Point& point) override;
  void Draw(PainterWin* painter, const Rect& dirty) override;

 private:
  void UpdateThumbPosition();
  void OnClick();

  int GetTrackSize() const;
  int GetBoxSize() const;
  int GetScrollAmout() const;
  int GetLineHeight() const;
  int GetPageHeight() const;

  NativeTheme::ScrollbarTrackExtraParams params_ = {0};

  int contents_size_ = 1;
  int viewport_size_ = 1;

  ScrollBarButton near_button_;
  ScrollBarButton far_button_;
  ScrollBarThumb thumb_;

  RepeatController repeater_;

  bool vertical_;
  ScrollImpl* scroll_;  // weak ref
};

}  // namespace nu

#endif  // NATIVEUI_WIN_SCROLL_BAR_SCROLL_BAR_H_
