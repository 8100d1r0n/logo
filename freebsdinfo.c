/*
 * -- FreeBSD Info Program --
 *    April. 2015.
*/
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/time.h>
#include <sys/sysctl.h>
#include <sys/statvfs.h>

#define Z0 "\x1b[0m"
#define Z1 "\x1b[1;34m"
#define Z2 "\x1b[1;37m"
#define Z3 "\x1b[30m"
#define Z4 "\x1b[31m"
#define Z5 "\x1b[37m"
#define BK "\e[1m\e[37;1;41m"
#define BS "\e[1m\e[37;1;40m"
#define KB "\e[1m\e[31;1;60m"
#define MB "\e[1m\e[44;1;37m"

static void disk(void);

static void disk(void) {
    struct statvfs info;
    if(!statvfs("/", &info)) {
        unsigned long left  = (info.f_bfree * info.f_frsize);
        unsigned long total = (info.f_blocks * info.f_frsize);
        unsigned long used  = total - left;
        float perc  = (float)used / (float)total;
        printf(Z5"%25s     %.2f%% of %.2f GB\n",Z4" Disk "Z5,
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
int main() {

	FILE *fpt;
	char packages[50] = " ";
	fpt = popen ("pkg info | wc -l", "r");
	fgets(packages, 50, fpt);
	pclose(fpt);

	struct passwd *p;
	uid_t uid=1001;

	if ((p = getpwuid(uid)) == NULL)
		perror("getpwuid() error");

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
printf(Z4"%s\n","             ▄"Z0);
printf(Z4"%s\n","          ▄███▀            ▀█▄"Z0);
printf(Z4"%s\n","         ▓███               ▄█▒"Z0);
printf(Z4"%s%s\n","        ▒▓██    ▓▄▄░▒▓▓░"Z0,Z4"▄▄▓░▓█▓"Z0);
printf(Z4"%s","       ▐▒▓██▌ ▄████████████▓▒▀"Z0); uptime(&now);
printf(Z4"%s%19s%15s\n","        ▀▒███▓████████████████"Z0,Z4"OS"Z5, uts.sysname);
printf(Z4"%s%s%s%s%s%20s%10s\n","         ▀▒█████████"Z0,BK"▄▄"Z0,Z4"███"Z0,BK"▄██▄"Z0,Z4"█▄"Z0,Z4"User"Z5,p->pw_name);// getlogin());
printf(Z4"%s%s%s%s%s%s%s%24s%18s\n","          ▀▓███████"Z0,Z2"████"Z0,Z4"██"Z0,BK"▐██"Z0,BS"▀"Z0,BK"▌"Z0,Z4"█"Z0,Z4"Hostname"Z5, computer);
printf(Z4"%s%s%s%s%s%s%s%22s%6s\n","            ▀▒████"Z0,BK"▐██"Z0,BS"▀▀"Z0,Z4"███"Z0,BK"▐"Z0,BS" ▀█"Z0,Z4"█▌"Z0,Z4"Version"Z5, uts.release);
printf(Z4"%s%s%s%s%s%22s%7s\n","             ██████"Z0,Z2"█"Z0,Z3"  "Z0,BS"▀▌"Z0,Z4"▀▄▄▄▄▀█▄▄"Z0,Z4"Hardware"Z5, uts.machine);
printf(Z4"%s%s%s%18s%23s\n","            ▐▒█████▓"Z0,BK"▀▀"Z0,Z4"█████▓▀▄████"Z0,Z4"Shell"Z5, p->pw_shell);
printf(Z4"%s%21s%13s\n","             ▒▓██▀ ████▄▀▀▄▄█▀██▀"Z0,Z4"Userdir"Z5, p->pw_dir);
printf(Z4"%s%24s%6s","              ▀▓█▓▄ ▀▀▀▀▀▀▀▄▄█▀"Z0,Z4"Packages"Z5, packages);
printf(Z4"%s","                 ▀▀███████▀"Z0); disk();
printf(Z4"%s%23s%31s","               ▄▄▄███████▄▄▄"Z0,Z4"Date"Z5, ctime(&timeval));
printf(Z4"%s\n","          ▄▄▄███▀▄▓█████▓▄▀███▄▄▄"Z0);
printf(Z1"%s%s%s%s%s\n"," ▒▓██▓▓▓░"Z0,Z4"█████▄"Z0,Z1" ░▒▓████████"Z0,Z4"▄██████"Z0,Z1"░▒███████▓▓▓▒▄   ▄█████▓▒ ███████▓▄"Z0);
printf(Z1"%s%s%s%s%s\n"," ▓███   "Z0,Z4"▓████ ▀██"Z0,Z1"  ░▒▓██▀"Z0,Z4" ██▀ █████ "Z0,Z1"   ██    ▀███ ▒██▀      ██    ▀█▓▒"Z0);
printf(Z1"%s%s%s%s%s\n"," ████    "Z0,Z4"▀▓███"Z0,Z1"               "Z0,Z4"▐██▒▀"Z0,Z1"     ██    ▄██▀ ▒██▄      ██      ██▓"Z0);
printf(Z1"%s\n"," ███████ ▓████▄█▓▒▄ ▄██▓▓▒▄   ▄██▓▓▒▄  ████████   ▀▓█████▄  ██      ██▓"Z0);
printf(Z1"%s\n"," ████    ▓████  ▀▀▀░██▀  ▀██ ▒██▀  ▀██ ██    ▀██▄       ▀██ ██      ███"Z0);
printf(Z1"%s\n"," ████    ▓████     ▒██▀▀▀▀▀▀ ███▀▀▀▀▀▀ ██    ▄███       ▄██ ██    ▄███"Z0);
printf(Z1"%s\n"," ████    ▓████     ▀███▄▄██▀  ███▄▄██▀ ████████▀  ▒██████▀  ████████▀"Z0);
}
