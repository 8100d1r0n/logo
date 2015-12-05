// By: 8100d1r0n -- April. 2015.
// Compile: clang -I/usr/include pisilinuxinfo.c -L/usr/lib -o pisilinuxinfo

#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <sys/statvfs.h>

#define Z0 "\x1b[0m"
#define Z1  "\x1b[35m"
#define Z2  "\x1b[37m"
#define Z3  "\x1b[30m"
#define Z4  "\x1b[2m"
#define Z5  "\x1b[31m"

#define CLR_GRY  "\x1b[0;37m"
#define CLR_RST  "\x1b[0m"
static void disk(void);

void help(void) {
      printf(Z3" Linux Info --- By:  8100d1r0n  April. 2015\n"             
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
        printf(CLR_GRY"\t\t\t\t\t\t\t║"CLR_RST);printf(Z5" Disk      "Z0);printf(CLR_GRY"║ %.2f%% of %.2f GB\n"CLR_RST,
                perc * 100, (float)total / 1e+09);
 }
}

int main(int argc, char **argv) {
	
	FILE *fpt;
	char wmname[50] = " ";
	fpt = popen ("wmctrl -m | grep -i name | awk '{print $2}'", "r");
	fgets(wmname, 50, fpt);
	pclose(fpt);

	struct sysinfo info;
	sysinfo(&info);
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
printf(Z1"   ████████                                         ████████ \n"Z0);        
printf(Z1"  █████████████"Z0);printf(Z4"        ███████"Z0);printf(Z2"█████████"Z0);printf(Z4"█"Z0);printf(Z1"        █████████████\n"Z0);        
printf(Z1"  ████████████████"Z0);printf(Z4"  ████"Z0);printf(Z2"███"Z0);printf(Z4"███"Z0);printf(Z2"████████████"Z0);printf(Z4"█"Z0);printf(Z1"  ████████████████\n"Z0);        
printf(Z1"  ████████████████"Z0);printf(Z4"█"Z0);printf(Z2"█"Z0);printf(Z4"████"Z0);printf(Z2"████"Z0);printf(Z4"██"Z0);printf(Z2"██████████████"Z0);printf(Z4"█"Z0);printf(Z1"████████████████\n"Z0);        
printf(Z1"  ██████████████"Z0);printf(Z4"█"Z0);printf(Z2"████"Z0);printf(Z4"███"Z0);printf(Z2"████"Z0);printf(Z4"██"Z0);printf(Z2"████████████████"Z0);printf(Z4"█"Z0);printf(Z1"██████████████"Z0);printf(CLR_GRY"\t\t\t\t\t\t╔═══════════╗\n"CLR_RST);       
printf(Z1"  ████████████"Z0);printf(Z4"█"Z0);printf(Z2"████████"Z0);printf(Z4"█"Z0);printf(Z2"█████"Z0);printf(Z4"█"Z0);printf(Z2"██████████████████"Z0);printf(Z4"█"Z0);printf(Z1"████████████"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Uptime    ");printf(CLR_GRY"║ %02ld:%02ld:%02ld\n"CLR_RST, info.uptime/3600, info.uptime%3600/60,info.uptime%60);
printf(Z1"  ██████████"Z0);printf(Z4"█"Z0);printf(Z2"█████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z1"██████████"Z0);printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"CLR_RST);        
printf(Z1"  ████████"Z0);printf(Z4"█"Z0);printf(Z2"█████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z1"████████"Z0);printf(Z5"    ▄███████▄  ▄█     ▄████████  ▄█   ▄█        ▄█  ███▄▄▄▄   ███    █▄  ▀████    ▐████▀\n"Z0);         
printf(Z1"  ███████"Z0);printf(Z4"█"Z0);printf(Z2"███████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z1"███████"Z0);printf(Z5"   ███    ███ ███    ███    ███ ███  ███       ███  ███▀▀▀██▄ ███    ███   ███▌   ████▀ \n"Z0);         
printf(Z1"  ██████"Z0);printf(Z2"███████████████████████████████████████████████"Z0);printf(Z1"██████"Z0);printf(Z5"   ███    ███ ███▌   ███    █▀  ███▌ ███       ███▌ ███   ███ ███    ███    ███  ▐███   \n"Z0);         
printf(Z1"   ███"Z0);printf(Z4"█"Z0);printf(Z2"█████████████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z1"███"Z0);printf(Z5"    ███    ███ ███▌   ███        ███▌ ███       ███▌ ███   ███ ███    ███    ▀███▄███▀   \n"Z0);         
printf(Z1"    █"Z0);printf(Z4"█"Z0);printf(Z2"███████████████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z1"█"Z0);printf(Z5"     ███    ███ ███▌   ███        ███▌ ███       ███▌ ███   ███ ███    ███     ██████     \n"Z0);         
printf(Z4"    █"Z0);printf(Z2"█████████████████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z5"   ▀█████████▀  ███▌ ▀███████████ ███▌ ███       ███▌ ███   ███ ███    ███    ████▀██▄    \n"Z0);         
printf(Z4"  ██"Z0);printf(Z2"███████████████████████████████████████████████████████"Z0);printf(Z4"██"Z0);printf(Z5"   ███        ███           ███ ███  ███       ███  ███   ███ ███    ███   ▐███  ▀███   \n"Z0);        
printf(Z4"  █"Z0);printf(Z2"█████████████████████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(Z5"   ███        ███     ▄█    ███ ███  ███▌    ▄ ███  ███   ███ ███    ███  ▄███     ███▄ \n"Z0);        
printf(Z4" █"Z0);printf(Z2"███████████"Z0);printf(Z3"████████"Z0);printf(Z2"█████████████████████"Z0);printf(Z3"████████"Z0);printf(Z2"███████████"Z0);printf(Z4"█"Z0);printf(Z5" ▄████▀      █▀    ▄████████▀  █▀   █████▄▄██ █▀    ▀█   █▀  ████████▀  ████       ███▄\n"Z0);      
printf(Z4"██"Z0);printf(Z2"███████████"Z0);printf(Z3"██"Z0);printf(Z2"███"Z0);printf(Z3"█████"Z0);printf(Z2"█████████████████"Z0);printf(Z3"██████"Z0);printf(Z2"██"Z0);printf(Z3"██"Z0);printf(Z2"███████████"Z0);printf(Z4"██"Z0);printf(CLR_GRY"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n"CLR_RST);      
printf(Z4"█"Z0);printf(Z2"████████████"Z0);printf(Z3"██"Z0);printf(Z2"██"Z0);printf(Z3"███████"Z0);printf(Z2"███████████████"Z0);printf(Z3"███████"Z0);printf(Z2"██"Z0);printf(Z3"██"Z0);printf(Z2"████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" OS        "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.sysname);
printf(Z4"█"Z0);printf(Z2"████████████"Z0);printf(Z3"██"Z0);printf(Z2"███"Z0);printf(Z3"██████"Z0);printf(Z2"███████████████"Z0);printf(Z3"██████"Z0);printf(Z2"███"Z0);printf(Z3"██"Z0);printf(Z2"████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" User      "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_name); //getlogin());
printf(Z4" █"Z0);printf(Z2"████████████"Z0);printf(Z3"███"Z0);printf(Z2"█████"Z0);printf(Z3"██"Z0);printf(Z2"███████████████"Z0);printf(Z3"██"Z0);printf(Z2"█████"Z0);printf(Z3"███"Z0);printf(Z2"████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Hostname  "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, computer);
printf(Z4"  █"Z0);printf(Z2"██████████████"Z0);printf(Z3"███████"Z0);printf(Z2"███████████████"Z0);printf(Z3"███████"Z0);printf(Z2"██████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Kernel    "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.release);
printf(Z4"   █"Z0);printf(Z2"███████████████████████████████████████████████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Hardware  "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, uts.machine);
printf(Z4"    ██"Z0);printf(Z2"████████████████████"Z0);printf(Z3"███████████"Z0);printf(Z2"████████████████████"Z0);printf(Z4"██"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Shell     "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_shell);
printf(Z4"      █"Z0);printf(Z2"█████████████"Z0);printf(Z1"█"Z0);printf(Z2"██████"Z0);printf(Z3"█████████"Z0);printf(Z2"██████"Z0);printf(Z1"█"Z0);printf(Z2"█████████████"Z0);printf(Z4"█"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" Userdir   "Z0);printf(CLR_GRY"║ %s\n"CLR_RST, p->pw_dir);
printf(Z4"       ██"Z0);printf(Z2"████████"Z0);printf(Z1"███"Z0);printf(Z2"█"Z0);printf(Z1"███"Z0);printf(Z2"████"Z0);printf(Z3"███████"Z0);printf(Z2"████"Z0);printf(Z1"███"Z0);printf(Z2"█"Z0);printf(Z1"███"Z0);printf(Z2"████████"Z0);printf(Z4"██"Z0);printf(CLR_GRY"\t\t\t\t\t\t║"CLR_RST);printf(Z5" WM        "Z0);printf(CLR_GRY"║ %s"CLR_RST,wmname);
printf(Z4"          █"Z0);printf(Z2"███"Z0);printf(Z1"███"Z0);printf(Z2"██"Z0);printf(Z1"██"Z0);printf(Z2"█████████"Z0);printf(Z3"███"Z0);printf(Z2"█████████"Z0);printf(Z1"██"Z0);printf(Z2"██"Z0);printf(Z1"███"Z0);printf(Z2"███"Z0);printf(Z4"█"Z0);disk();
printf(Z2"            "Z0);printf(Z1"███"Z0);printf(Z2"█"Z0);printf(Z1"███"Z0);printf(Z2"████████████"Z0);printf(Z3"█"Z0);printf(Z2"████████████"Z0);printf(Z1"███"Z0);printf(Z2"█"Z0);printf(Z1"███"Z0);printf(CLR_GRY"\t\t\t\t\t\t\t║"CLR_RST);printf(Z5" Date      "Z0);printf(CLR_GRY"║ %s"CLR_RST, ctime(&timeval));
printf(Z2"         "Z0);printf(Z1"███ █████"Z0);printf(Z2"███████████████████████████"Z0);printf(Z1"█████ ███"Z0);printf(CLR_GRY"\t\t\t\t\t\t\t╚═══════════╝\n"CLR_RST);
printf(Z2"      "Z0);printf(Z1"████ ███"Z0);printf(Z4"      █"Z0);printf(Z2"█████████████████████"Z0);printf(Z4"█      "Z0);printf(Z1"███ ████\n"Z0);            
printf(Z2"    "Z0);printf(Z1"███ ████"Z0);printf(Z2"                                       "Z0);printf(Z1"███  ███\n"Z0);          
printf(Z2"   "Z0);printf(Z1"██  ██"Z0);printf(Z2"                                             "Z0);printf(Z1"██  ██\n"Z0);       
printf("\n");
  }
}                                                                          

