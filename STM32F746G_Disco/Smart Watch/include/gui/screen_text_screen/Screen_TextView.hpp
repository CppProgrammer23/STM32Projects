#ifndef SCREEN_TEXTVIEW_HPP
#define SCREEN_TEXTVIEW_HPP

#include <gui_generated/screen_text_screen/Screen_TextViewBase.hpp>
#include <gui/screen_text_screen/Screen_TextPresenter.hpp>

class Screen_TextView : public Screen_TextViewBase
{
public:
    Screen_TextView();
    virtual ~Screen_TextView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_TEXTVIEW_HPP
