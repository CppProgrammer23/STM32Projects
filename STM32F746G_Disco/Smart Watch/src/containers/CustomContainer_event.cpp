#include <gui/containers/CustomContainer_event.hpp>
#include <gui/screen_agenda_screen/Screen_agendaView.hpp>

CustomContainer_event::CustomContainer_event()
{
    
}
//CustomContainer_event::CustomContainer_event(Screen_agendaView& sc):s(sc)
//{
//
//}

void CustomContainer_event::initialize()
{
    CustomContainer_eventBase::initialize();
    flexButton_Shift.setPressed(true);
}

void CustomContainer_event::Return_to_Agenda()
{
    Container::setVisible(false);
    Container::invalidate();
    for (int j = 0; j < pos_cursor; j++)
    {
        textArea2Buffer[j] = '\0';
    }
    textArea2.invalidate();
    pos_cursor = 0;
}
void CustomContainer_event::Add_shift()
{
    if (shif == 1)
    {
        flexButton_Shift.setPressed(false);
        shif = 0;
    }
    else
    {
        flexButton_Shift.setPressed(true);
        shif = 1;
    }
}
//std::string CustomContainer_event::text;
void CustomContainer_event::Save_Note()
{
    std::shared_ptr<Screen_agendaView> scr (new Screen_agendaView);
    for (int i = 0; i <= pos_cursor; i++)
        text +=(textArea2Buffer[i]);
    scr->SendToView(text);
    Return_to_Agenda();
}

//std::string  CustomContainer_event::GetTextFromContainer(void)
//{
//    return (text+=textArea2Buffer[pos_cursor]);
//}
void CustomContainer_event::Add_point()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor]= '.';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_plus()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '+';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Underscore()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '_';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_minus()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '-';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_NewLine()
{
    textArea2Buffer[pos_cursor] = '\n';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Delete()
{
    pos_cursor--;
    textArea2Buffer[pos_cursor] = '\0';
    textArea2.setWildcard(textArea2Buffer);
    textArea2.invalidate();
}
void CustomContainer_event::Add_zero()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '0';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_space()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = ' ';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_A()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'A';
    else
        textArea2Buffer[pos_cursor] = 'a';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Z()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'Z';
    else
        textArea2Buffer[pos_cursor] = 'z';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_E()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'E';
    else
        textArea2Buffer[pos_cursor] = 'e';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_R()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'R';
    else
        textArea2Buffer[pos_cursor] = 'r';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_T()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'T';
    else
        textArea2Buffer[pos_cursor] = 't';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Y()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'Y';
    else
        textArea2Buffer[pos_cursor] = 'y';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_U()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'U';
    else
        textArea2Buffer[pos_cursor] = 'u';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_I()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'I';
    else
        textArea2Buffer[pos_cursor] = 'i';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_O()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'O';
    else
        textArea2Buffer[pos_cursor] = 'o';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_P()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif)
        textArea2Buffer[pos_cursor] = 'P';
    else
        textArea2Buffer[pos_cursor] = 'p';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Q()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'Q';
    else
        textArea2Buffer[pos_cursor] = 'q';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_N()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'N';
    else
        textArea2Buffer[pos_cursor] = 'n';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_V()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'V';
    else
        textArea2Buffer[pos_cursor] = 'v';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_X()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'X';
    else
        textArea2Buffer[pos_cursor] = 'x';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_W()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'W';
    else
        textArea2Buffer[pos_cursor] = 'w';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_S()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'S';
    else
        textArea2Buffer[pos_cursor] = 's';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_B()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'B';
    else
        textArea2Buffer[pos_cursor] = 'b';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_H()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'H';
    else
        textArea2Buffer[pos_cursor] = 'h';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_L()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'L';
    else
        textArea2Buffer[pos_cursor] = 'l';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_M()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'M';
    else
        textArea2Buffer[pos_cursor] = 'm';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_C()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'C';
    else
        textArea2Buffer[pos_cursor] = 'c';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_K()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'K';
    else
        textArea2Buffer[pos_cursor] = 'k';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_F()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'F';
    else
        textArea2Buffer[pos_cursor] = 'f';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_G()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'G';
    else
        textArea2Buffer[pos_cursor] = 'g';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_J()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'J';
    else
        textArea2Buffer[pos_cursor] = 'j';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_D()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if(shif==1)
        textArea2Buffer[pos_cursor] = 'D';
    else
        textArea2Buffer[pos_cursor] = 'd';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_1()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '1';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_2()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '2';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_3()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '3';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_4()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '4';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_5()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '5';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_6()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '6';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_7()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '7';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_8()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    };
    textArea2Buffer[pos_cursor] = '8';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_9()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '9';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Excla()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '!';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Intero()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '?';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_comma()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = ':';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_ComPoint()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = ';';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Percent()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '%';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_at()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '@';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Chap()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '^';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_slash()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '/';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Anpersand()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '&';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_dollar_pound()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    if (shif == 0)
    {
        textArea2Buffer[pos_cursor] = '$';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    else if (shif == 1)
    {
        textArea2Buffer[pos_cursor] = '€';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2.invalidate();
}
void CustomContainer_event::Add_equal()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '=';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_apos()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = '\'';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
void CustomContainer_event::Add_Virg()
{
    if (pos_cursor == 20 || pos_cursor == 40 || pos_cursor == 60)
    {
        textArea2Buffer[pos_cursor] = '\n';
        textArea2.setWildcard(textArea2Buffer);
        pos_cursor++;
    }
    textArea2Buffer[pos_cursor] = ',';
    textArea2.setWildcard(textArea2Buffer);
    pos_cursor++;
    textArea2.invalidate();
}
