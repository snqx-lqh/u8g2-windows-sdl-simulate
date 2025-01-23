
#include "csrc/u8g2.h"
#include <stdio.h>
#include <unistd.h>

u8g2_t u8g2;

typedef struct
{
  char* str;
}SETTING_LIST;

SETTING_LIST list[] = 
{
  {"list_a"},
  {"list_b"},
  {"list_c"},
  {"list_1"},
  {"list_2"},
  {"list_3"},
  {"list_4"},
  {"list_5"},
  {"list_6"},
};

short x,x_trg;  
short y = 10,y_trg = 10;

int ui_run(short *a,short *a_trg)
{
    if(*a < *a_trg)
    {
        *a += 1;
    }
    else if( *a > *a_trg)
    {
        *a -= 1;    
    }
    else
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    int key = 0;
   
    u8g2_SetupBuffer_SDL_128x64_4(&u8g2, &u8g2_cb_r0);
    u8x8_InitDisplay(u8g2_GetU8x8(&u8g2));
    u8x8_SetPowerSave(u8g2_GetU8x8(&u8g2), 0);
    u8g2_SetFont(&u8g2, u8g2_font_wqy12_t_chinese1);

    y_trg = 10; 


    for ( ; ; )
    {
        u8g2_FirstPage(&u8g2);
		do {
            int list_len = sizeof(list) / sizeof(SETTING_LIST);
            for(int i = 0 ;i < list_len;i++)
            {
                u8g2_DrawStr(&u8g2, x,y+i*10,list[i].str);   
            }
            ui_run(&y,&y_trg);
		} while (u8g2_NextPage(&u8g2));
        
        key = u8g_sdl_get_key();
        // ↑ ↓ ← → 
        if(key == 273)
        {
            y_trg -= 10;                    
        }else if(key == 274)
        {
            y_trg += 10;;
        }else if(key == 276)
        {
                               
        }else if(key == 275)
        {
             
        }
        usleep(100000);
    }
    return 0;
}
 
/*
int main(void)
{
    int key = 0;
    int x = 0;
    int y = 0;

    u8g2_SetupBuffer_SDL_128x64_4(&u8g2, &u8g2_cb_r0);
    u8x8_InitDisplay(u8g2_GetU8x8(&u8g2));
    u8x8_SetPowerSave(u8g2_GetU8x8(&u8g2), 0);

    for ( ; ; )
    {
        u8g2_FirstPage(&u8g2);
		do {
			u8g2_SetFontMode(&u8g2, 1);
			u8g2_SetFontDirection(&u8g2, 0);
			u8g2_SetFont(&u8g2, u8g2_font_inb24_mf);
			u8g2_DrawStr(&u8g2, x+0, y+20, "U");
			u8g2_SetFontDirection(&u8g2, 1);
			u8g2_SetFont(&u8g2, u8g2_font_inb30_mn);
			u8g2_DrawStr(&u8g2, x+21, y+8, "8");
			u8g2_SetFontDirection(&u8g2, 0);
			u8g2_SetFont(&u8g2, u8g2_font_inb24_mf);
			u8g2_DrawStr(&u8g2, x+51, y+30, "g");
			u8g2_DrawStr(&u8g2, x+67, y+30, "\xb2");
			u8g2_DrawHLine(&u8g2, x+2, y+35, 47);
			u8g2_DrawHLine(&u8g2, x+3, y+36, 47);
			u8g2_DrawVLine(&u8g2, x+45, y+32, 12);
			u8g2_DrawVLine(&u8g2, x+46, y+33, 12);
            u8g2_SetFont(&u8g2, u8g2_font_wqy12_t_gb2312);
            u8g2_DrawUTF8(&u8g2, x+1, y+54, "测试");
		} while (u8g2_NextPage(&u8g2));

        do{
            key = u8g_sdl_get_key();
        }while(key < 0);
        if(key == 273)
        {
            y--;                    
        }else if(key == 274)
        {
            y++;
        }else if(key == 276)
        {
            x--;                    
        }else if(key == 275)
        {
            x++;
        }
    }
    return 0;
}
*/