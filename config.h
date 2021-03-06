/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/** buttons **/
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False mean panel is on bottom */
#define PANEL_HEIGHT    18        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    BSTACK      /* TILE MONOCLE BSTACK GRID */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_MOUSE    False     /* Focus the window the mouse just entered */
#define FOLLOW_WINDOW   False     /* Follow the window when moved to a different desktop */
#define CLICK_TO_FOCUS  False     /* Focus an unfocused window when clicked */
#define BORDER_WIDTH    0         /* window border width */
#define FOCUS           "#121212" /* focused window border color   */
#define UNFOCUS         "#222222" /* unfocused window border color */
#define DESKTOPS        6         /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define DEFAULT_DESKTOP 0         /* the desktop to focus on exec */
#define MINWSZ          50        /* minimum window size in pixels */

/* open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    { "MPlayer",     3,    True,   False },
    { "Gimp",        0,    False,  True  },
};

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/** commands **/
static const char *termcmd[] = { "uxterm",     NULL };
static const char *menucmd[] = { "dmenu_run", NULL };
static const char *shutdowncmd[] = { "sudo", "shutdown", "-h", "now", NULL };
static const char *rebootcmd[] = { "sudo", "reboot", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };
static const char *thunarcmd[] = { "thunar", NULL };
static const char *scrotcmd[] = { "scrot", NULL };
#define DESKTOPCHANGE(K,N) \
    {  MOD1,             K,              change_desktop, {.i = N}}, \
    {  MOD1|ShiftMask,   K,              client_to_desktop, {.i = N}},

/** Shortcuts **/
static key keys[] = {
    /* modifier          key            function           argument */
    {  MOD1,             XK_b,          togglepanel,       {NULL}},
    {  MOD1,             XK_BackSpace,  focusurgent,       {NULL}},
    {  MOD1|SHIFT,       XK_c,          killclient,        {NULL}},
    {  MOD1,             XK_j,          next_win,          {NULL}},
    {  MOD1,             XK_k,          prev_win,          {NULL}},
    {  MOD1,             XK_h,          resize_master,     {.i = -10}}, /* decrease size in px */
    {  MOD1,             XK_l,          resize_master,     {.i = +10}}, /* increase size in px */
    {  MOD1,             XK_o,          resize_stack,      {.i = -10}}, /* shrink   size in px */
    {  MOD1,             XK_p,          resize_stack,      {.i = +10}}, /* grow     size in px */
    {  MOD1|CONTROL,     XK_h,          rotate,            {.i = -1}},
    {  MOD1|CONTROL,     XK_l,          rotate,            {.i = +1}},
    {  MOD1|SHIFT,       XK_h,          rotate_filled,     {.i = -1}},
    {  MOD1|SHIFT,       XK_l,          rotate_filled,     {.i = +1}},
    {  MOD1,             XK_Tab,        last_desktop,      {NULL}},
    {  MOD1,             XK_Return,     swap_master,       {NULL}},
    {  MOD1|SHIFT,       XK_j,          move_down,         {NULL}},
    {  MOD1|SHIFT,       XK_k,          move_up,           {NULL}},
    {  MOD1|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  MOD1|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  MOD1|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}},
    {  MOD1|SHIFT,       XK_g,          switch_mode,       {.i = GRID}},
    {  MOD1|CONTROL,     XK_r,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  MOD1|CONTROL,     XK_q,          quit,              {.i = 1}}, /* quit with exit value 1 */
    {  MOD1|SHIFT,       XK_Return,     spawn,             {.com = termcmd}},
    {  MOD1,             XK_d,          spawn,             {.com = menucmd}},
    {  MOD1,  	 XK_s,	        spawn,	           {.com = shutdowncmd} },
    {  MOD1,             XK_r,          spawn,             {.com = rebootcmd} },
    {  MOD1,             XK_h,          spawn,             {.com = thunarcmd} },
    {  MOD1,             XK_f,          spawn,             {.com = firefoxcmd} },
    {  MOD1,             XK_z,          spawn,             {.com = scrotcmd} },
       DESKTOPCHANGE(    XK_F1,                             0)
       DESKTOPCHANGE(    XK_F2,                             1)
       DESKTOPCHANGE(    XK_F3,                             2)
       DESKTOPCHANGE(    XK_F4,                             3)
};

static Button buttons[] = {
    {  MOD1,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD1,    Button3,     mousemotion,   {.i = RESIZE}},
    {  MOD4,    Button3,     spawn,         {.com = menucmd}},
};
#endif
