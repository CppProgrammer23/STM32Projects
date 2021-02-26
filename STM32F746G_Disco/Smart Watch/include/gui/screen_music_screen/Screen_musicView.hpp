#ifndef SCREEN_MUSICVIEW_HPP
#define SCREEN_MUSICVIEW_HPP

#include <gui_generated/screen_music_screen/Screen_musicViewBase.hpp>
#include <gui/screen_music_screen/Screen_musicPresenter.hpp>

class Screen_musicView : public Screen_musicViewBase
{
public:
    Screen_musicView();
    virtual ~Screen_musicView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Play_Pause_Music()override;
    void Open_COntainer_Music()override;
    void SetButton1(bool);
    void handleTickEvent()override;
    void Button_Pause_Clicked()override;
protected:
    bool play = false;
};

#endif // SCREEN_MUSICVIEW_HPP
