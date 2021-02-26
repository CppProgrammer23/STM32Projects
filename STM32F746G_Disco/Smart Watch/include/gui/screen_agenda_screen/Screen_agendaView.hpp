#ifndef SCREEN_AGENDAVIEW_HPP
#define SCREEN_AGENDAVIEW_HPP

#include <gui_generated/screen_agenda_screen/Screen_agendaViewBase.hpp>
#include <gui/screen_agenda_screen/Screen_agendaPresenter.hpp>
#include <string>

class CustomContainer_event;
class Screen_agendaView : public Screen_agendaViewBase
{
public:
    Screen_agendaView();
    virtual ~Screen_agendaView() { }
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Open_Container()override;
    void SendToView(std::string t);
    void handleTickEvent();
protected:
    static std::string Note;
};

#endif // SCREEN_AGENDAVIEW_HPP
