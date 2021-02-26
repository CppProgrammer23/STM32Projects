#ifndef SCREEN_MULTIMEDIAVIEW_HPP
#define SCREEN_MULTIMEDIAVIEW_HPP

#include <gui_generated/screen_multimedia_screen/Screen_multimediaViewBase.hpp>
#include <gui/screen_multimedia_screen/Screen_multimediaPresenter.hpp>

class Screen_multimediaView : public Screen_multimediaViewBase
{
public:
    Screen_multimediaView();
    virtual ~Screen_multimediaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN_MULTIMEDIAVIEW_HPP
