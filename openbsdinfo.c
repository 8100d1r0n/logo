/*
 * -- OpenBSD Info Program --
 *      -- April.2015 --
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
#define Z1 "\x1b[0;32m"
#define Z2 "\x1b[1;33m"
#define Z3 "\x1b[0;36m"
#define Z4 "\x1b[0;31m"
#define Z5 "\x1b[37m"

static void disk(void);

void help(void) {
      printf(Z3" OpenBSD Info --- By:  8100d1r0n  April. 2015\n"
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
        printf(Z5"%37s%s%18s%.2f%% of %.2f GB\n","║",Z4" Disk ",Z5"║ "Z5,
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
                printf(Z5"%37s%s%12s\b","║",Z4" Uptime",Z5"║ ");
                if(days > 0)
                        printf(" %d day%s", days, days > 1? "s " : " ");
                if (hrs > 0 && mins > 0)
                        printf(Z5" %02d:%02d"Z0, hrs, mins);
                else if(hrs == 0 && mins > 0)
                        printf(Z5" 0:%02d"Z0, mins);
                else
                        printf(Z5" 0:00"Z0);
                putchar('\n');
        }
}
int main(int argc, char **argv) {
	FILE *fpt;
	char packages[50] = " ";
	fpt = popen ("pkg_info -q | gwc -l", "r");
	fgets(packages, 50, fpt);
	pclose(fpt);

	struct passwd *p;
	uid_t uid=1000; // 1000 user uid number.

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
time_t now;
time(&now);
{
        char computer[256];
        struct utsname uts;
        time_t timeval;

        (void)time(&timeval);

        if(gethostname(computer, 255) != 0 || uname(&uts) < 0) {
                fprintf(stderr, "Could not get host information, so fuck off\n");
                exit(1);
         }
printf(Z5"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"Z0);
printf(Z2"  ▄████▄  ▀██████████████████████████████████▄   ▄███████ ████████▄  \n"Z0);
printf(Z2" ██    ██                            ██    ▀███ ███▀      ██    ▀███ \n"Z0);
printf(Z2" ██    ██                            ██    ▄██▀ ███▄      ██      ███\n"Z0);
printf(Z2" ██    ██ ██████▄   ▄████▄  ▄█████▄  ████████   ▀██████▄  ██      ███\n"Z0);
printf(Z2" ██    ██ ██    ██ ██▀  ▀██ ██   ▀██ ██    ▀██▄       ▀██ ██      ███\n"Z0);
printf(Z2" ██    ██ ██    ██ ██▀▀▀▀▀▀ ██    ██ ██    ▄███       ▄██ ██    ▄███ \n"Z0);
printf(Z2"  ▀████▀ ▄██████▀  ▀██▄▄██▀ ██    ██ ████████▀  ███████▀  ████████▀  \n"Z0);
printf(Z5"%s%s%s%s%s\n","▀▀▀▀▀▀▀▀▀▀",  Z2"██"Z0,Z5"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"Z0,Z2"█▀"Z0,Z5"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"Z0);
printf(Z2"%20s%30s%s%16s%s\n",      " ██" Z0,Z5"║",Z4" OS",      Z5"║ ", uts.sysname);
printf(Z2"%25s%29s%s%14s%s\n",     " ▀▀▀▀"Z0,Z5"║",Z4" User",    Z5"║ ", getlogin());
printf(Z5"%37s%s%10s%s\n",                     "║",Z4" Hostname",Z5"║ ", computer);
printf(Z5"%37s%s%11s%s\n",                     "║",Z4" Version", Z5"║ ", uts.release);
printf(Z5"%37s%s%10s%s\n",                     "║",Z4" Hardware",Z5"║ ", uts.machine);
printf(Z5"%37s%s%13s%s\n",                     "║",Z4" Shell",   Z5"║ ", p->pw_shell);
printf(Z5"%37s%s%11s%s\n",                     "║",Z4" Userdir", Z5"║ ", p->pw_dir);
printf(Z5"%37s%s%10s%s",                       "║",Z4" Packages",Z5"║ ", packages);disk();
printf(Z5"%37s%s%14s%s",                       "║",Z4" Date",    Z5"║ ", ctime(&timeval));uptime(&now);
printf(Z5"%74s\n",                             "╚══════════╝"Z0);
  }
}

