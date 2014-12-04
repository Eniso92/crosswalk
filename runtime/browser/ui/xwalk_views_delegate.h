// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_RUNTIME_BROWSER_UI_XWALK_VIEWS_DELEGATE_H_
#define XWALK_RUNTIME_BROWSER_UI_XWALK_VIEWS_DELEGATE_H_

#if defined(USE_AURA)

#include <string>
#include "ui/views/views_delegate.h"

namespace xwalk {

// Views delegate implementation for Crosswalk. Controls application-wide
// aspects of Views toolkit system.
class XWalkViewsDelegate : public views::ViewsDelegate {
 public:
  XWalkViewsDelegate();
  virtual ~XWalkViewsDelegate();

  // views::ViewsDelegate implementation.
  void SaveWindowPlacement(const views::Widget* widget,
                           const std::string& window_name,
                           const gfx::Rect& bounds,
                           ui::WindowShowState show_state) override {}
  bool GetSavedWindowPlacement(
      const views::Widget* widget,
      const std::string& window_name,
      gfx::Rect* bounds,
      ui::WindowShowState* show_state) const override;
  void NotifyAccessibilityEvent(
      views::View* view,
      ui::AXEvent event_type) override {}
  void NotifyMenuItemFocused(const base::string16& menu_name,
                             const base::string16& menu_item_name,
                             int item_index,
                             int item_count,
                             bool has_submenu) override {}
  views::NonClientFrameView* CreateDefaultNonClientFrameView(
      views::Widget* widget) override;
  void AddRef() override {}
  void ReleaseRef() override {}
  content::WebContents* CreateWebContents(
      content::BrowserContext* browser_context,
      content::SiteInstance* site_instance) override;
  void OnBeforeWidgetInit(
      views::Widget::InitParams* params,
      views::internal::NativeWidgetDelegate* delegate) override;
  base::TimeDelta GetDefaultTextfieldObscuredRevealDuration() override;
#if defined(OS_WIN)
  // Retrieves the default window icon to use for windows if none is specified.
  HICON GetDefaultWindowIcon() const override;
  bool IsWindowInMetro(gfx::NativeWindow window) const override {
    return false;
  }
#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
  gfx::ImageSkia* GetDefaultWindowIcon() const override;
#endif

 private:
  DISALLOW_COPY_AND_ASSIGN(XWalkViewsDelegate);
};

}  // namespace xwalk

#endif  // defined(USE_AURA)

#endif  // XWALK_RUNTIME_BROWSER_UI_XWALK_VIEWS_DELEGATE_H_
