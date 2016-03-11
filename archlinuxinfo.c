/*
 * ======================================================================
 *  Filename:  archlinuxinfo.c
 *
 *   Version:  2.6
 *   Created:  04/08/2015 02:07:35 AM
 *  Revision:  02/19/2016 04:49:09 AM
 *  Compiler:  gcc
 *
 *    Author:  8100d1r0n (https://github.com/8100d1r0n)
 *    E-Mail:  echo "ODEwMGQxcjBuKGF0KXJpc2V1cChkb3QpbmV0Cg=="|base64 -d
 * ======================================================================
 */

#include <sys/statvfs.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>

#define PRNT(args...)   printf(args)
#define INFO_UPTIME     info.uptime/3600, info.uptime%3600/60,info.uptime%60
#define STRG	        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"

#define RT   "\x1b[0m"          //Reset
#define BL   "\x1b[34m"         //Blue
#define RD   "\x1b[31m"         //Red
#define GR   "\x1b[0;37m"       //Gray
#define BW   "\e[1m\e[0;34;47m" //BgColor = white  FgColor = Blue"

static void date(void) {
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time(&rawtime);

   info = localtime(&rawtime);

   strftime(buffer,80,"%a %d %b %H:%M", info);
   PRNT(GR" %s\n"RT, buffer);

}

static void disk(void) {
    struct statvfs info;
    if(!statvfs("/", &info)) {
        unsigned long left  = (info.f_bfree * info.f_frsize);
        unsigned long total = (info.f_blocks * info.f_frsize);
        unsigned long used  = total - left;
        float perc  = (float)used / (float)total;
        PRNT(GR" %.2f%% of %.2f GB\n"RT,
                perc * 100, (float)total / 1e+09);
 }
}

int main(void) {

        FILE *fptr;
        char packages[50] = " ";
        fptr = popen ("pacman -Qq | wc -l", "r");
        fgets(packages, 50, fptr);
        pclose(fptr);

        struct sysinfo info;
        sysinfo(&info);
        struct passwd *p;
        uid_t uid=1000; /* 1000 user id. Info command: $ id -u */

        if ((p = getpwuid(uid)) == NULL)
                perror("getpwuid() error");

{
        char computer[256];
        struct utsname uts;
        if(gethostname(computer, 255) != 0 || uname(&uts) < 0) {
                fprintf(stderr, "Could not get host information, so fuck off\n");
                exit(1);
         }

PRNT("%52s%s%12s%21s%13s%s%s%02ld:%02ld:%02ld\n"
                   ,BL"                   ▄                         ",GR"╔═══════════╗ \n"
                    BL"                  ▄█▄        ",RD" ▄█",RD"▄▀▄",GR"║",RD" Uptime    ",GR"║ ",INFO_UPTIME);
PRNT(STRG,GR"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀",BW"▄",BL"███",BW"▄"  ,GR"▀▀▀▀▀▀▀",RD"███",GR"▀▀▀▀▀▀▀▀",RD"▀",GR"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"
                    BL"                ▄█████▄      ",RD"███        ▄█  ▄█████▄    ▄█    █▄ ▀████    ▐████▀\n"
                    BL"               ▄███████▄     ",RD"███       ███  ███▀▀▀██  ███    ███  ███▌   ████▀ \n"
                    BL"               █████████▄    ",RD"███       ███▌ ███   ██▌ ███    ███   ▀███▄███▀   \n"
                    BL"             ▄  █████████▄   ",RD"███       ███▌ ███   ███ ███    ███   ████▀██▄    \n"
                    BL"            ▄██▄ ▀████████▄  ",RD"███▌    ▄ ███  ███   ███ ███    ███ ▄███     ███▄ \n"
                    BL"           ▄█████▄█████████▄ ",RD"█████▄▄██ █▀   ███   ███  ▀██████▀ ████       ███▄\n"
       GR"▀▀▀▀▀▀▀▀▀▀",BW"▄",RT,BL"██████▀▀▀▀▀██████" ,BW"▄",RD"███",GR"▀▀▀▀▀▀▀▀▀▀▀▀",RD"██",GR"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");
PRNT(BL"%s%s%s%s%s\n","         ▄████▀         ▀████▄               ",GR"║",RD" OS        ",GR"║ ",uts.sysname);
PRNT(BL"%s%s%s%s%s\n","        ▄████             ██ ▀▄              ",GR"║",RD" User      ",GR"║ ",p->pw_name);//getlogin());
PRNT(BL"%s%s%s%s%s\n","       ▄████               ██▄               ",GR"║",RD" Hostname  ",GR"║ ",computer);
PRNT(BL"%s%s%s%s%s\n","      ▄█████               ████▄             ",GR"║",RD" Kernel    ",GR"║ ",uts.release);
PRNT(BL"%s%s%s%s%s\n","     ▄█████                 █████▄           ",GR"║",RD" Hardware  ",GR"║ ",uts.machine);
PRNT(BL"%s%s%s%s%s\n","    ▄█████                   █████▄          ",GR"║",RD" Shell     ",GR"║ ",p->pw_shell);
PRNT(BL"%77s%s%s%s%s","   ▄██████▄                 ▄██████▄         ",GR"║",RD" Packages  ",GR"║ ",packages);
PRNT(BL"%81s%s%s%s\b","  ▄██████▀▀                 ▀▀██████▄        ",GR"║",RD" Disk      ",GR"║ ");disk();
PRNT(BL"%67s%s%s%s\b"," ▄██▀▀                          ▀▀▀██▄       ",GR"║",RD" Date      ",GR"║ ");date();
PRNT(BL"%s%s\b\b\b\n","▄▀                                   ▀▄      ",GR"╚═══════════╝\n"RT);
	}
}
