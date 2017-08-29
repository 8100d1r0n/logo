/*
 * -- FreeBSD Info Program --
 *    April. 2015.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <sys/sysctl.h>
#include <sys/statvfs.h>

#define RST "\x1b[0m"
#define BLU "\x1b[1;34m"
#define WHT "\x1b[1;37m"
#define BLC "\x1b[30m"
#define RED "\x1b[31m"
#define GRY "\x1b[37m"
#define BK "\e[1m\e[37;1;41m"
#define BS "\e[1m\e[37;1;40m"
#define KB "\e[1m\e[31;1;60m"
#define MB "\e[1m\e[44;1;37m"

static void disk(void) {
    struct statvfs info;

    if(!statvfs("/", &info)) {
        unsigned long left  = (info.f_bfree * info.f_frsize);
        unsigned long total = (info.f_blocks * info.f_frsize);
        unsigned long used  = total - left;
        float perc  = (float)used / (float)total;
        printf(GRY"%25s     %.2f%% of %.2f GB\n",RED" Disk "GRY,
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
               	printf(RED"       Uptime"RST);

        if(days > 0)
                printf("%d day%s", days, days > 1? "s " : " ");

        if (hrs > 0 && mins > 0)
                printf(GRY"    %02d:%02d"RST, hrs, mins);

        else if(hrs == 0 && mins > 0)
                printf(GRY"    0:%02d"RST, mins);
 
               else
		    printf(GRY"    0:00"RST);
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
	uid_t uid=1001; /* 1001 User id */

	if ((p = getpwuid(uid)) == NULL)
		perror("getpwuid() error");

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

	printf(RED"%s\n","             ▄"RST);
	printf(RED"%s\n","          ▄███▀            ▀█▄"RST);
	printf(RED"%s\n","         ▓███               ▄█▒"RST);
	printf(RED"%s%s\n","        ▒▓██    ▓▄▄░▒▓▓░"RST,RED"▄▄▓░▓█▓"RST);
	printf(RED"%s","       ▐▒▓██▌ ▄████████████▓▒▀"RST); uptime(&now);
	printf(RED"%s%19s%15s\n","        ▀▒███▓████████████████"RST,RED"OS"GRY, uts.sysname);
	printf(RED"%s%s%s%s%s%20s%10s\n","         ▀▒█████████"RST,BK"▄▄"RST,RED"███"RST,BK"▄██▄"RST,RED"█▄"RST,RED"User"GRY,p->pw_name);// getlogin());
	printf(RED"%s%s%s%s%s%s%s%24s%18s\n","          ▀▓███████"RST,WHT"████"RST,RED"██"RST,BK"▐██"RST,BS"▀"RST,BK"▌"RST,RED"█"RST,RED"Hostname"GRY, computer);
	printf(RED"%s%s%s%s%s%s%s%22s%6s\n","            ▀▒████"RST,BK"▐██"RST,BS"▀▀"RST,RED"███"RST,BK"▐"RST,BS" ▀█"RST,RED"█▌"RST,RED"Version"GRY, uts.release);
	printf(RED"%s%s%s%s%s%22s%7s\n","             ██████"RST,WHT"█"RST,BLC"  "RST,BS"▀▌"RST,RED"▀▄▄▄▄▀█▄▄"RST,RED"Hardware"GRY, uts.machine);
	printf(RED"%s%s%s%18s%23s\n","            ▐▒█████▓"RST,BK"▀▀"RST,RED"█████▓▀▄████"RST,RED"Shell"GRY, p->pw_shell);
	printf(RED"%s%21s%13s\n","             ▒▓██▀ ████▄▀▀▄▄█▀██▀"RST,RED"Userdir"GRY, p->pw_dir);
	printf(RED"%s%24s%6s","              ▀▓█▓▄ ▀▀▀▀▀▀▀▄▄█▀"RST,RED"Packages"GRY, packages);
	printf(RED"%s","                 ▀▀███████▀"RST); disk();
	printf(RED"%s%23s%31s","               ▄▄▄███████▄▄▄"RST,RED"Date"GRY, ctime(&timeval));
	printf(RED"%s\n","          ▄▄▄███▀▄▓█████▓▄▀███▄▄▄"RST);
	printf(BLU"%s%s%s%s%s\n"," ▒▓██▓▓▓░"RST,RED"█████▄"RST,BLU" ░▒▓████████"RST,RED"▄██████"RST,BLU"░▒███████▓▓▓▒▄   ▄█████▓▒ ███████▓▄"RST);
	printf(BLU"%s%s%s%s%s\n"," ▓███   "RST,RED"▓████ ▀██"RST,BLU"  ░▒▓██▀"RST,RED" ██▀ █████ "RST,BLU"   ██    ▀███ ▒██▀      ██    ▀█▓▒"RST);
	printf(BLU"%s%s%s%s%s\n"," ████    "RST,RED"▀▓███"RST,BLU"               "RST,RED"▐██▒▀"RST,BLU"     ██    ▄██▀ ▒██▄      ██      ██▓"RST);
	printf(BLU"%s\n"," ███████ ▓████▄█▓▒▄ ▄██▓▓▒▄   ▄██▓▓▒▄  ████████   ▀▓█████▄  ██      ██▓"RST);
	printf(BLU"%s\n"," ████    ▓████  ▀▀▀░██▀  ▀██ ▒██▀  ▀██ ██    ▀██▄       ▀██ ██      ███"RST);
	printf(BLU"%s\n"," ████    ▓████     ▒██▀▀▀▀▀▀ ███▀▀▀▀▀▀ ██    ▄███       ▄██ ██    ▄███"RST);
	printf(BLU"%s\n"," ████    ▓████     ▀███▄▄██▀  ███▄▄██▀ ████████▀  ▒██████▀  ████████▀"RST);
      }
   return 0;
}
