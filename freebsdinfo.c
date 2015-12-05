/*
 * FreeBSD Info Program -- 
 * By: 8100d1r0n -- April. 2015.
*/
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <sys/sysctl.h>
#include <sys/statvfs.h>
#define Z0 "\x1b[0m"     //Reset
#define Z1  "\x1b[1;34m"   //Blue
#define Z2  "\x1b[1;37m"   //White
#define Z3  "\x1b[30m"   //Black
#define Z4  "\x1b[31m"   //Red
#define Z5 "\x1b[37m"	 //Cyan
#define BK	"\e[1m\e[37;1;41m"
#define BS	"\e[1m\e[37;1;40m"
#define KB	"\e[1m\e[31;1;60m"
#define MB	"\e[1m\e[44;1;37m"

static void disk(void);

void help(void) {
      printf(Z3" FreeBSD Info --- By:  8100d1r0n  April. 2015\n"             
             "-h help msg :)\n"Z0);
      exit(0);
}

static void disk(void) { 
    struct statvfs info;
    if(!statvfs("/", &info)) {
        unsigned long left  = (info.f_bfree * info.f_frsize);
        unsigned long total = (info.f_blocks * info.f_frsize);
        unsigned long used  = total - left;
        float perc  = (float)used / (float)total;
        printf(Z4"\t     Disk "Z0);printf(Z5"     %.2f%% of %.2f GB\n"Z0,
                perc * 100, (float)total / 1e+09);
 }
}
 static void uptime(time_t *nowp) {
        struct timeval boottime;
        time_t uptime;
        int days, hrs, mins, secs;
        int mib[2];
        size_t size;
        char buf[256];
        if(strftime(buf, sizeof(buf), NULL, localtime(nowp)))
             mib[0] = CTL_KERN;
        mib[1] = KERN_BOOTTIME;
        size = sizeof(boottime);
        if(sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 &&
                        boottime.tv_sec) {
                uptime = *nowp - boottime.tv_sec;
                if(uptime > 60)
                        uptime += 30;
                days = (int)uptime / 86400;
                uptime %= 86400;
                hrs = (int)uptime / 3600;
                uptime %= 3600;
                mins = (int)uptime / 60;
                secs = uptime % 60;
                printf(Z4"       Uptime"Z0);
                if(days > 0)
                        printf("%d day%s", days, days > 1? "s " : " ");
                if (hrs > 0 && mins > 0)
                        printf(Z5"    %02d:%02d"Z0, hrs, mins);
                else if(hrs == 0 && mins > 0)
                        printf(Z5"    0:%02d"Z0, mins);
                else
                        printf(Z5"    0:00"Z0);
                putchar('\n');
        }
}
int main(int argc, char **argv) {
	FILE *fpt;
	char packages[50] = " ";
	fpt = popen ("pkg info | wc -l", "r");
	fgets(packages, 50, fpt);
	pclose(fpt);

	struct passwd *p;
	uid_t uid=1001; // 1000 user uid number.

	if ((p = getpwuid(uid)) == NULL) 
		perror("getpwuid() error");
 
    if (argc >= 2) {
        int c;
        while ((c = getopt(argc, argv, "h")) != -1) {
            switch (c) {
                case 'h':
                default:
                    help();
                    break;
            }
        }
    }
{
        char computer[256];
        struct utsname uts;
        time_t timeval;
       
        (void)time(&timeval);
       
        if(gethostname(computer, 255) != 0 || uname(&uts) < 0) {  
                fprintf(stderr, "Could not get host information, so fuck off\n");
                exit(1);
         } 
time_t now;
time(&now);
printf(Z4"             ▄\n"Z0);
printf(Z4"          ▄███▀            ▀█▄\n"Z0);
printf(Z4"         ▓███               ▄█▒\n"Z0);
printf(Z4"        ▒▓██    ▓▄▄░▒▓▓░"Z0);printf(Z4"▄▄▓░▓█▓\n"Z0);
printf(Z4"       ▐▒▓██▌ ▄████████████▓▒▀"Z0); uptime(&now);  
printf(Z4"        ▀▒███▓████████████████"Z0);printf(Z4"\t     OS"Z0);printf(Z5"        %s\n", uts.sysname);
printf(Z4"         ▀▒█████████"Z0);printf(BK"▄▄"Z0);printf(Z4"███"Z0);printf(BK"▄██▄"Z0);printf(Z4"█▄"Z0);printf(Z4"\t     User"Z0);printf(Z5"      %s\n",p->pw_name);// getlogin());
printf(Z4"          ▀▓███████"Z0);printf(Z2"████"Z0);printf(Z4"██"Z0);printf(BK"▐██"Z0);printf(BS"▀"Z0);printf(BK"▌"Z0);printf(Z4"█"Z0);printf(Z4"\t     Hostname"Z0);printf(Z5"  %s\n", computer);
printf(Z4"            ▀▒████"Z0);printf(BK"▐██"Z0);printf(BS"▀▀"Z0);printf(Z4"███"Z0);printf(BK"▐"Z0);printf(BS" ▀█"Z0);printf(Z4"█▌"Z0);printf(Z4"     Version"Z0);printf(Z5"   %s\n", uts.release);
printf(Z4"             ██████"Z0);printf(Z2"█"Z0);printf(Z3"  "Z0);printf(BS"▀▌"Z0);printf(Z4"▀▄▄▄▄▀█▄▄"Z0); printf(Z4"    Hardware"Z0);printf(Z5"  %s\n", uts.machine);
printf(Z4"            ▐▒█████▓"Z0);printf(BK"▀▀"Z0);printf(Z4"█████▓▀▄████"Z0);printf(Z4"   Shell"Z0);printf(Z5"     %s\n", p->pw_shell);
printf(Z4"             ▒▓██▀ ████▄▀▀▄▄█▀██▀"Z0);printf(Z4"    Userdir"Z0);printf(Z5"   %s\n", p->pw_dir);
printf(Z4"              ▀▓█▓▄ ▀▀▀▀▀▀▀▄▄█▀"Z0);printf(Z4"\t     Packages"Z0);printf(Z5"  %s", packages);
printf(Z4"                 ▀▀███████▀"Z0); disk();
printf(Z4"               ▄▄▄███████▄▄▄"Z0);printf(Z4"\t     Date"Z0);printf(Z5"      %s", ctime(&timeval));
printf(Z4"          ▄▄▄███▀▄▓█████▓▄▀███▄▄▄\n"Z0);
printf(Z1" ▒▓██▓▓▓░"Z0);printf(Z4"█████▄"Z0);printf(Z1" ░▒▓████████"Z0);printf(Z4"▄██████"Z0);printf(Z1"░▒███████▓▓▓▒▄   ▄█████▓▒ ███████▓▄\n"Z0);
printf(Z1" ▓███   "Z0);printf(Z4"▓████ ▀██"Z0);printf(Z1"  ░▒▓██▀"Z0);printf(Z4" ██▀ █████ "Z0);printf(Z1"   ██    ▀███ ▒██▀      ██    ▀█▓▒\n"Z0);
printf(Z1" ████    "Z0);printf(Z4"▀▓███"Z0);printf(Z1"               "Z0);printf(Z4"▐██▒▀"Z0);printf(Z1"     ██    ▄██▀ ▒██▄      ██      ██▓\n"Z0);
printf(Z1" ███████ ▓████▄█▓▒▄ ▄██▓▓▒▄   ▄██▓▓▒▄  ████████   ▀▓█████▄  ██      ██▓\n"Z0);
printf(Z1" ████    ▓████  ▀▀▀░██▀  ▀██ ▒██▀  ▀██ ██    ▀██▄       ▀██ ██      ███\n"Z0);
printf(Z1" ████    ▓████     ▒██▀▀▀▀▀▀ ███▀▀▀▀▀▀ ██    ▄███       ▄██ ██    ▄███\n"Z0);
printf(Z1" ████    ▓████     ▀███▄▄██▀  ███▄▄██▀ ████████▀  ▒██████▀  ████████▀\n"Z0);
        
  }
}
