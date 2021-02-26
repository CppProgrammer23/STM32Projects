#ifndef SCREEN_PICVIEW_HPP
#define SCREEN_PICVIEW_HPP

#include <gui_generated/screen_pic_screen/Screen_picViewBase.hpp>
#include <gui/screen_pic_screen/Screen_picPresenter.hpp>

class Screen_picView : public Screen_picViewBase
{
public:
    Screen_picView();
    virtual ~Screen_picView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_PICVIEW_HPP
