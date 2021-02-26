#include <gui/screen_agenda_screen/Screen_agendaView.hpp>


Screen_agendaView::Screen_agendaView()
{

}

void Screen_agendaView::setupScreen()
{
    Screen_agendaViewBase::setupScreen();
}

void Screen_agendaView::tearDownScreen()
{
    Screen_agendaViewBase::tearDownScreen();
}

void Screen_agendaView::Open_Container()
{
    customContainer_event1.setVisible(true);
    customContainer_event1.invalidate(); 
}
void Screen_agendaView::SendToView(std::string t)
{
    Note = t;
    //Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", t.c_str());
    /*textArea1Buffer[0] = t[0];
    textArea1.setWildcard(textArea1Buffer);
    textArea1.invalidate();*/ 
}
std::string Screen_agendaView::Note;
void Screen_agendaView::handleTickEvent()
{
    if (customContainer_event1.isVisible() == 0)
    {
    //Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", Note.c_str());
        for (unsigned int i = 0; i < Note.length(); i++)
        {
            textArea1Buffer[i] = Note[i];
        }
    textArea1.setWildcard(textArea1Buffer);
    textArea1.invalidate();
    }
}

