#include <gui/screen_tic_tao_screen/Screen_TIC_TAOView.hpp>
#include <touchgfx/Color.hpp>

Screen_TIC_TAOView::Screen_TIC_TAOView():player(1),win(0),set_player(0)
{
    
}

void Screen_TIC_TAOView::setupScreen()
{
    Screen_TIC_TAOViewBase::setupScreen();
}

void Screen_TIC_TAOView::tearDownScreen()
{
    Screen_TIC_TAOViewBase::tearDownScreen();
}
void Screen_TIC_TAOView::handleTickEvent()
{
    for (int i = 0; i < 7; i+=3)
    {
        if ((tab[i] == tab[i + 1]) && (tab[i + 1]  == tab[i + 2]))
        {
            if (name == "Dra")
            {
                Dra();
            }
            else if (name == "26_I")
            {
                _26I();
            }
            else
            {
                textArea1Buffer1[0] = 'P'; textArea1Buffer1[1] = 'l'; textArea1Buffer1[2] = 'a'; textArea1Buffer1[3] = 'y'; textArea1Buffer1[4] = 'e'; textArea2Buffer1[5] = 'r';
                Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%d", player);
                textArea1.setWildcard2(textArea1Buffer2);
                textArea1.setVisible(true);
                textArea1.invalidate();
            }
            win = true;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if ((tab[j] == tab[j + 3]) && (tab[j + 3] == tab[j + 6]))
        {
            if (name == "Dra")
            {
                Dra();
            }
            else if (name == "26_I")
            {
                _26I();
            }
            else
            {
                textArea1Buffer1[0] = 'P'; textArea1Buffer1[1] = 'l'; textArea1Buffer1[2] = 'a'; textArea1Buffer1[3] = 'y'; textArea1Buffer1[4] = 'e'; textArea2Buffer1[5] = 'r';
                Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%d", player);
                textArea1.setWildcard2(textArea1Buffer2);
                textArea1.setVisible(true);
                textArea1.invalidate();
            }  
            win = true;
        }
    }
    if (((tab[0] == tab[4]) && (tab[4]  == tab[8])) || ((tab[2] == tab[4]) && (tab[4]  == tab[6])))
    {
        if (name == "Dra")
        {
            Dra();
        }
        else if (name == "26_I")
        {
            _26I();
        }
        else
        {
            textArea1Buffer1[0] = 'P'; textArea1Buffer1[1] = 'l'; textArea1Buffer1[2] = 'a'; textArea1Buffer1[3] = 'y'; textArea1Buffer1[4] = 'e'; textArea2Buffer1[5] = 'r';
            Unicode::snprintf(textArea1Buffer2, TEXTAREA1BUFFER2_SIZE, "%d", player);
            textArea1.setWildcard2(textArea1Buffer2);
            textArea1.setVisible(true);
            textArea1.invalidate();
        }
        win = true;
    }
    if (win == true)
    {
        button1.setTouchable(false);
        button2.setTouchable(false);
        button3.setTouchable(false);
        button4.setTouchable(false);
        button5.setTouchable(false);
        button6.setTouchable(false);
        button7.setTouchable(false);
        button8.setTouchable(false);
        button9.setTouchable(false);
        if (set_player == 0)
        {
            if (player == 1)
                player = 2;
            else
                player = 1;
            set_player = 1;
        }
    }
    if (player == 1)
    {
        if (name != "")
        {
            for (unsigned int i = name.length(); i < TEXTAREA2BUFFER1_SIZE; i++)
                textArea2Buffer1[i] = '\0';
            for (unsigned int i = 0; i < name.length(); i++)
                textArea2Buffer1[i] = name[i];
            textArea2.setWildcard1(textArea2Buffer1);
            textArea2.invalidate();
            if (win == false)
            {
                if(color)
                    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(3, 3, 237));
                else
                    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
                textArea2Buffer2[0] = '\0';
                textArea2.setWildcard2(textArea2Buffer2);
                textArea2.invalidate();
            }
            else
            {
                textArea2.setVisible(false);
                textArea2.invalidate();
            }
        }
        else
        {
            if(color)
                textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(3, 3, 237));
            else
                textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
            Unicode::snprintf(textArea2Buffer2, TEXTAREA2BUFFER2_SIZE, "%d", player);
            textArea2.setWildcard2(textArea2Buffer2);
            textArea2.invalidate();
        }
        
    }
    else if(player == 2)
    {
        textArea2Buffer1[0] = 'P'; textArea2Buffer1[1] = 'l'; textArea2Buffer1[2] = 'a'; textArea2Buffer1[3] = 'y'; textArea2Buffer1[4] = 'e'; textArea2Buffer1[5] = 'r';
        textArea2.setWildcard2(textArea2Buffer1);
        textArea2.invalidate();
        if (win == false)
        {
            if(color)
                textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(129, 237, 1));
            else
                textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
            Unicode::snprintf(textArea2Buffer2, TEXTAREA2BUFFER2_SIZE, "%d", player);
            textArea2.setWildcard2(textArea2Buffer2);
            textArea2.invalidate();
        }
        else
        {
            textArea2.setVisible(false);
            textArea2.invalidate();
        }
    }
}
void Screen_TIC_TAOView::B1_Pushed()
{
    button1.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue.setXY(203, 58);
            circle_blue.setVisible(true);
            circle_blue.invalidate();    
        }
        else
        {
            text_O.setXY(219, 70);
            text_O.setVisible(true);
            text_O.invalidate();
        }
        tab[0] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green.setXY(203, 58);
            circle_green.setVisible(true);
            circle_green.invalidate();
        }
        else
        {
            text_X.setXY(219, 70);
            text_X.setVisible(true);
            text_X.invalidate();
        }
        tab[0] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B2_Pushed()
{
    button2.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_1.setXY(273, 58);
            circle_blue_1.setVisible(true);
            circle_blue_1.invalidate();
        }
        else
        {
            text_O_1.setXY(290, 70);
            text_O_1.setVisible(true);
            text_O_1.invalidate();
        }
        tab[1] = player;
        player++;
    }
    else
    {
        if (color == 1)
        {
            circle_green_1.setXY(273, 58);
            circle_green_1.setVisible(true);
            circle_green_1.invalidate();
        }
        else
        {
            text_X_2.setXY(290, 70);
            text_X_2.setVisible(true);
            text_X_2.invalidate();
        }
        tab[1] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B3_Pushed()
{
    button3.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_2.setXY(341, 58);
            circle_blue_2.setVisible(true);
            circle_blue_2.invalidate();
        }
        else
        {
            text_O_2.setXY(355, 70);
            text_O_2.setVisible(true);
            text_O_2.invalidate();
        }
        tab[2] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_2.setXY(341, 58);
            circle_green_2.setVisible(true);
            circle_green_2.invalidate();
        }
        else
        {
            text_X_3.setXY(355, 70);
            text_X_3.setVisible(true);
            text_X_3.invalidate();
        }
        tab[2] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B4_Pushed()
{
    button4.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_3.setXY(203, 115);
            circle_blue_3.setVisible(true);
            circle_blue_3.invalidate();
        }
        else
        {
            text_O_3.setXY(219, 127);
            text_O_3.setVisible(true);
            text_O_3.invalidate();
        }
        tab[3] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_3.setXY(203, 115);
            circle_green_3.setVisible(true);
            circle_green_3.invalidate();
        }
        else
        {
            text_X_4.setXY(219, 127);
            text_X_4.setVisible(true);
            text_X_4.invalidate();
        }
        tab[3] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B5_Pushed()
{
    button5.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_4.setXY(273, 115);
            circle_blue_4.setVisible(true);
            circle_blue_4.invalidate();
        }
        else
        {
            text_O_4.setXY(290, 127);
            text_O_4.setVisible(true);
            text_O_4.invalidate();
        }
        tab[4] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_4.setXY(273, 115);
            circle_green_4.setVisible(true);
            circle_green_4.invalidate();
        }
        else
        {
            text_X_5.setXY(290, 127);
            text_X_5.setVisible(true);
            text_X_5.invalidate();
        }
        tab[4] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B6_Pushed()
{
    button6.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_5.setXY(341, 115);
            circle_blue_5.setVisible(true);
            circle_blue_5.invalidate();
        }
        else
        {
            text_O_5.setXY(357, 127);
            text_O_5.setVisible(true);
            text_O_5.invalidate();
        }
        tab[5] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_5.setXY(341, 115);
            circle_green_5.setVisible(true);
            circle_green_5.invalidate();
        }
        else
        {
            text_X_6.setXY(357, 127);
            text_X_6.setVisible(true);
            text_X_6.invalidate();
        }
        tab[5] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B7_Pushed()
{
    button7.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_6.setXY(203, 168);
            circle_blue_6.setVisible(true);
            circle_blue_6.invalidate();
        }
        else
        {
            text_O_6.setXY(219, 180);
            text_O_6.setVisible(true);
            text_O_6.invalidate();
        }
        tab[6] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_6.setXY(203, 168);
            circle_green_6.setVisible(true);
            circle_green_6.invalidate();
        }
        else
        {
            text_X_7.setXY(219, 180);
            text_X_7.setVisible(true);
            text_X_7.invalidate();
        }
        tab[6] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B8_Pushed()
{
    button8.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_7.setXY(273, 168);
            circle_blue_7.setVisible(true);
            circle_blue_7.invalidate();
        }
        else
        {
            text_O_7.setXY(287, 180);
            text_O_7.setVisible(true);
            text_O_7.invalidate();
        }
        tab[7] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_7.setXY(273, 168);
            circle_green_7.setVisible(true);
            circle_green_7.invalidate();
        }
        else
        {
            text_X_8.setXY(287, 180);
            text_X_8.setVisible(true);
            text_X_8.invalidate();
        }
        tab[7] = player;
        player--;
    }
}
void Screen_TIC_TAOView::B9_Pushed()
{
    button9.setTouchable(false);
    if (player == 1)
    {
        if (color == true)
        {
            circle_blue_8.setXY(341, 168);
            circle_blue_8.setVisible(true);
            circle_blue_8.invalidate();
        }
        else
        {
            text_O_8.setXY(353, 180);
            text_O_8.setVisible(true);
            text_O_8.invalidate();
        }
        tab[8] = player;
        player++;
    }
    else
    {
        if (color == true)
        {
            circle_green_8.setXY(341, 168);
            circle_green_8.setVisible(true);
            circle_green_8.invalidate();
        }
        else
        {
            text_X_9.setXY(353, 180);
            text_X_9.setVisible(true);
            text_X_9.invalidate();
        }
        tab[8] = player;
        player--;
    }
}

std::string Screen_TIC_TAOView::name;
void Screen_TIC_TAOView::SetDraName(std::string t)
{
    name = t;
}
void Screen_TIC_TAOView::Send26IName(std::string t)
{
    name = t;
}
bool Screen_TIC_TAOView::color=true;
void Screen_TIC_TAOView::SetXO_Ver(bool t)
{
    color = t;
}
void Screen_TIC_TAOView::SetColored_Ver(bool t)
{
    color = t;
}


void Screen_TIC_TAOView::Dra()
{
    for (unsigned int i = 0; i < name.length(); i++)
    {
        textArea1Buffer1[i] = name[i];
    }
    for (unsigned int i = name.length(); i < TEXTAREA1BUFFER1_SIZE; i++)
        textArea1Buffer1[i] = '\0';
    textArea1Buffer2[0] = '\0';
    textArea1.setWildcard1(textArea1Buffer1);
    textArea1.setVisible(true);
    textArea1.invalidate();
}
void Screen_TIC_TAOView::_26I()
{
    for (unsigned int i = 0; i < name.length(); i++)
    {
        textArea1Buffer1[i] = name[i];
    }
    for (unsigned int i = name.length(); i < TEXTAREA1BUFFER1_SIZE; i++)
        textArea1Buffer1[i] = '\0';
    textArea1Buffer2[0] = '\0';
    textArea1.setWildcard1(textArea1Buffer1);
    textArea1.setVisible(true);
    textArea1.invalidate();
}