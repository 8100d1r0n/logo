// By: 8100d1r0n -- April. 2015.
// Compile: clang -I/usr/include truvalinuxinfo.c -L/usr/lib -o truvalinuxinfo

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define Z0 "\x1b[0m"     //Reset
#define Z1  "\x1b[34m"   //Blue
#define Z2  "\x1b[33m"   //Yellow
#define Z3  "\x1b[31m"   //Red

#define CLR_GRY  "\x1b[0;37m"
#define CLR_RST  "\x1b[0m"

static void disk(void) {
    struct statvfs info;

    if(!statvfs("/", &info)) {
        unsigned long left  = (info.f_bfree * info.f_frsize);
        unsigned long total = (info.f_blocks * info.f_frsize);
        unsigned long used  = total - left;
        float perc  = (float)used / (float)total;
        printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" Disk      "Z0);printf(CLR_GRY"║ %.2f%% of %.2f GB\n"CLR_RST,
                perc * 100, (float)total / 1e+09);
    }
}

int main(int argc, char **argv) {

	FILE *fpt;
	char packages[50] = " ";
	fpt = popen ("ls -1 /var/log/packages | wc -l", "r");
	fgets(packages, 50, fpt);
	pclose(fpt);

	struct sysinfo info;
	sysinfo(&info);
	struct passwd *p;
	uid_t uid=0; // 0 root id number.

	if ((p = getpwuid(uid)) == NULL)
		perror("getpwuid() error");

{
        char computer[256];
        struct utsname uts;
        time_t timeval;
        (void)time(&timeval);
        if(gethostname(computer, 255) != 0 || uname(&uts) < 0) {
                fprintf(stderr, "Could not get host information, so fuck off\n");
                exit(1);
         }

printf(Z1"                                               ░███ ███ ███\n"Z0);
printf(Z1"                                           ░▓██████████████▒"Z0);printf(CLR_GRY"\t\t  ╔═══════════╗\n"CLR_RST);
printf(Z1"                                         ░▒█▒█████████████▒░"Z0);printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" Uptime    ");printf(CLR_GRY"║ %02ld:%02ld:%02ld\n"CLR_RST, info.uptime/3600, info.uptime%3600/60,info.uptime%60);
printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"Z0);printf(Z1"░░░░░░░░░░░░░░░░░░░░░████████████████░"Z0);printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"CLR_RST);
printf(Z1"                  ░████████████████████░██████████████████░"Z0);printf(Z3"    ███       ▄████████ ███    █▄   ▄█    █▄     ▄████████\n"Z0);
printf(Z1"                  ░▓███"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"██████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"████▓█████████████████"Z0);printf(CLR_GRY"█"CLR_RST);printf(Z1"░"Z0);printf(Z3"▀█████████▄  ███    ███ ███    ███ ███    ███   ███    ███\n"Z0);
printf(Z1"                  ░████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"██████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"███████████████████████░"Z0);printf(Z3"   ▀███▀▀██  ███    ███ ███    ███ ███    ███   ███    ███\n"Z0);
printf(Z1"                  ░██████████████████████████████████████▓░"Z0);printf(Z3"    ███   ▀ ▄███▄▄▄▄██▀ ███    ███ ███    ███   ███    ███\n"Z0);
printf(Z1"                  ░██████████████████████████████████████░"Z0);printf(Z3"     ███    ▀▀███▀▀▀▀▀   ███    ███ ███    ███ ▀███████████\n"Z0);
printf(Z1"                  ░█████████████████████████████████████░"Z0);printf(Z3"      ███    ▀███████████ ███    ███ ███    ███   ███    ███\n"Z0);
printf(Z1"         ░░░▒▓████████████████████████████████████████░"Z0);printf(Z3"        ███      ███    ███ ███    ███ ███    ███   ███    ███\n"Z0);
printf(Z1"       ░░█████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"██████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"███████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"█████░"Z0);printf(Z3"      ▄████▀    ███    ███ ████████▀   ▀██████▀    ███    █▀ \n"Z0);        
printf(CLR_GRY"▀▀▀▀▀▀"Z0);printf(Z1"░▓██████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"██████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"███████"Z0);printf(CLR_GRY"███"CLR_RST);printf(Z1"██████░"Z0);printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"CLR_RST);printf(Z3"███"Z0);printf(CLR_GRY"▀▀▀▀"CLR_RST);printf(Z3"▀▀▀"Z0);printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"CLR_RST);  
printf(Z1"   ░░████████████████████████████████████████████████████░"Z0);printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" OS        "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.sysname);
printf(Z1"  ░█████████████████████████████████████████████████████░"Z0);printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" User      "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_name); //getlogin());
printf(Z1"  ░████████████████████████████████████████████████████░"Z0);printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" Hostname  "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, computer);
printf(Z1"  ░████████████████████████░           ░██████████████░"Z0);printf(CLR_GRY"\t\t\t  ║"CLR_RST);printf(Z3" Kernel    "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.release);
printf(Z1"  ▓███████████████████████░             ░▒███████████░"Z0);printf(CLR_GRY"\t\t\t  ║"CLR_RST);printf(Z3" Hardware  "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.machine);
printf(Z1" ░███████████████████████░               ░░██████████░"Z0);printf(CLR_GRY"\t\t\t  ║"CLR_RST);printf(Z3" Shell     "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_shell);
printf(Z1" ░████████░█████████████▒░                 ░█████████░"Z0);printf(CLR_GRY"\t\t\t  ║"CLR_RST);printf(Z3" Userdir   "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_dir);
printf(Z1" ░████████░░████████████░░                  ░█████████░"Z0);printf(CLR_GRY"\t\t\t  ║"CLR_RST);printf(Z3" Packages  "Z0);printf(CLR_GRY"║ %s"CLR_RST,packages);
printf(Z1" █████████░ ░████████████░                   ░█████████░"Z0);disk();
printf(Z1"▒█████████░  ░████████████░                   ░█████████░"Z0);printf(CLR_GRY"\t\t  ║"CLR_RST);printf(Z3" Date      "Z0);printf(CLR_GRY"║ %s"CLR_RST, ctime(&timeval));
printf(Z1"░░░░░░░░░     ░████████████░                   ▒█████████░"Z0);printf(CLR_GRY"\t\t  ╚═══════════╝\n"CLR_RST);
printf(Z1"              ░▓████████████░                  ░██████████░\n"Z0);
printf(Z1"              ░░████████████▓░                 ░███████████▒\n"Z0);
printf("\n");
  }
 return 0;
}

