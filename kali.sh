#!/bin/sh
  esc=""

  black="${esc}[30m";       magenta="${esc}[31;41m"
  white="${esc}[37m";       red="${esc}[31m"; 
  rred="${esc}[31;41m";     redf="${esc}[31;57m"
  redb="${esc}[41;31m";     blue="${esc}[34m"
  yellow="${esc}[33m";      yylwd="${esc}[40;33m"
  yylw="${esc}[33;43m";     yyellow="${esc}[43;33m"
  ylwf="${esc}[30;43m";     yyellowb="${esc}[30;33m"
  yellowb="${esc}[37;33m";  yellowf="${esc}[37;43m"

  bold="${esc}[1m";        reset="${esc}[0m"

echo "\
                                ${yellow}▄${reset}${bold}${yellow}▄▄▄▄▄${reset}${yellow}▄${reset} 
                           ${yellow}▄${reset}${bold}${yylw}▄${reset}${bold}${yellow}████████████▄▄▄▄▄${reset}${yellow}▄${reset}      
                    ${yellow}▄▄▄█${reset}  ${yellow}▐${reset}${bold}${yellow}░▓▓███▀▓█▓███▓█▓█▓▒▓▒░${reset}${yellow}█▄▄${reset}      
                ${yellow}▄▄${reset}  ${yellow}▀▀▀▀█▄${reset}  ${bold}${yellow}▀▀▀▀▀ ${yellow}░${reset}${bold}${yellow}▓░▓█▓▒▓▒▓▒░▒░${yellow}▓▓▓▓▓▓▄${reset}     
             ${yellow}▄${bold}${yellow}░░░░░${reset}${yellow}▄▄${reset}                  ${yellow}▀${reset}${bold}${yellow}░▒░▒░${reset}${yellow}▓${reset}${bold}${yellow}░${reset}${yellow}▓▓▓${reset}${bold}${yellow}░${reset}${yellow}▓${reset}${bold}${yellow}░${reset}${yellow}▓${reset}${bold}${yellow}░${reset}${yellow}▓▄${reset}     
           ${yellow}▄${reset} ${yellow}█▀▀▀${reset}                        ${yellow}▀▓${reset}${bold}${yellow}░${reset}${yellow}▓▓▓▓▓${reset}${bold}${yellow}░▒░▒░▒░▒${bold}${yylw}▄${reset}${yellowb}▄${reset}     
         ${yellow}▄${bold}${yellow}░░${reset}${yellow}▀${reset}                              ${yellow}▀▀▓▓▓${reset}${bold}${yellow}░▒▓▒▓▒▓▒▓▒▓${reset}${bold}${yylw}▄${reset}${yellowb}▄${reset}     
       ${yellow}███${reset}                        ${yellow}▀██▄▄${reset}       ${yellow}▀${reset} ${yellow}▀▀${reset}${bold}${yellow}▓${reset}▓${reset}${bold}${yellow}▓${reset}▓${reset}${bold}${yellow}▓${reset}▓${reset}${bold}${yellow}▓${reset}▓${reset}${bold}${yellow}▓${reset}▓${reset}${bold}${yylw}▄${yellowb}▄${reset}   
      ${yellow}▄${reset}${yellow}▄${reset}${yellow}▀▀                             ${yellow}▀▀     ▀${reset}${bold}${yellowf}▀${reset}███▓█▓█▓█▓█▓███${bold}${yellowf}▄${reset}   
     ${yellow}▄█▄${reset}                                        ${yellow}▀${reset}${bold}${yellowf}▀${reset}█████████████▓▄${reset}    
    ${yellow}█${reset}${bold}${yellow}░${reset}${yellow}█▀${reset}                            ${bold}${yellow}▄▄▄▄▄${reset}${yellow}▄${reset}           ▀▀▀▀▀██████▓▄${reset}    
   ${bold}${yellow}▓░▓${reset}                ${yellow}▌${reset}            ${yellow}▀${reset}${bold}${yylw}▀${reset}${bold}${yellow}▓▓▓██▄${reset}${yellow}▄▄${reset}     ${bold}${yellow}▄▄▄${reset}       ${yellow}▀${reset}${bold}${yellowf}▀${reset}███▓${reset}${bold}${yellow}▄${reset}   
  ${bold}${yellow}▐█▓▌${reset}                ${yellow}█${reset}               ${bold}${yellow}▀▀▀▓▓▓▓▄▄${reset}             ${yellow}█${reset}██████▌${reset}    
  ${bold}${yellow}▐██${reset}                  ${yellow}▄${reset}       ${yylwd}▄${reset}${bold}${yellow}░▒░▒░▒░${reset}${yylwd}▓▄${reset}  ${bold}${yellow}▀▀▀██▄▄▄${reset}           ██████${bold}${yellow}█${reset}   
 ${bold}${yellow}▐███${reset}                 ${bold}${yylw}▄${reset}${bold}${yellow}█▓${reset}${bold}${yylw}▄${reset}${bold}${yellow}▄▄▓▒▓▒▓▒▓▒▓▒▓▒▓▒${yylwd}▄${reset}   ${bold}${yyellow}▀${reset}${bold}${yyellow}▀${reset}${bold}${yellow}▓▓▓▄▄    ▄${reset}  ▐▐███████${bold}${yellow}▌${reset}    
 ${bold}${yellow}███▓${reset}                 ${bold}${yylw}▀${reset}▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▄    ${yellow}▀▀▀▀${reset}  ${yellow}█ ▀█▄▄${reset}▓█▓█▓█▓█▓${reset}   
 ${bold}${yellow}▓█▓▒${reset}                  ${yellow}▀${reset}█▓█▓█▓█▓█▓█▓█▓█▓█▓████${bold}${yellowf}▄${reset}${bold}${yellow}▄▄▄▄${reset}${yyellowb}▄${reset}  ${bold}${yellow}▄▄▄${reset} ${yyellowb}▐${reset}${bold}${yellow}▒▓${bold}${white}▓${reset}${bold}${yellow}▓${reset}${bold}${white}▓${reset}${bold}${yellow}▓${reset}${bold}${white}▓${reset}${bold}${yellow}▓${reset}${bold}${white}▓${reset}${bold}${yellow}▓${reset}   
 ${bold}${yellow}▒▓▒▌${reset}                   ${yellow}▀${reset}${bold}${yellowf}▀${reset}██████████████████████▓${bold}${yellow}▓█▓█▓█▓█  ░▒▓▒▓▒▓▒▓▒${reset}   
 ${bold}${yellow}░▒░${reset}                       ${yellow}▀${reset}▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀${bold}${yellow}▓▒▓▒▓▒▓▒▓▒  ░▒░▒░▒${reset}${red}▄${reset} ${bold}${yellow}▀${reset}      
 ${red}█${reset}${bold}${yellow}░${reset}   ${red}▄▄${reset}                                           ${red}▀▀${reset}${bold}${yellow}░▒░▒░   ░${reset}${red}█${reset}${bold}${yellow}░${red}█${reset}${bold}${yellow}░${reset}${red}█${reset}  
 ${red}▐█░█░█░${red}▄${reset}                                              ${red}█${reset}${bold}${yellow}░${reset}${red}██    ▀▀▀${reset}     
  ${bold}${red}░▒░▒░▒░${red}▄${reset}                                               ${red}▀██▄ ▀█▄█▀${reset}     
  ${red}▐${reset}${bold}${red}▓▒▓▒▓▒▓${red}▄${reset}                                                ${red}▀██▄▄▄▄▄${reset}  
   ${red}█${reset}${bold}${red}▓█▓█▓██${red}█${reset}                                                 ${red}█████▀${reset}  
    ${bold}${red}░▓████▄${red}▄${reset}                                                  ${red}███▀${reset}    
     ${bold}${red}░▓█████${reset}   ${red}▄▄${reset}                                            ${red}▐██▀${reset}    
      ${bold}${red}░▓${reset}${redf}▀${reset}${bold}${rred}▀${reset}${bold}${red}█▓  ░${reset}${red}█${bold}${red}░${reset}${red}▌  ${red}░${reset}${bold}${red}░${reset}${red}░${reset}${bold}${red}░${reset}${red}░${reset}${bold}${red}░${reset}                                   ${red}██▀${reset}   
       ${red}▀█▄▄  ▄${reset}${bold}${red}▓░▓░  ${red}▓${reset}${bold}${red}▓${reset}${red}▓${reset}${bold}${red}▓${red}▓${reset}${bold}${red}▓${reset}${red}░${reset}
         ${red}▀${reset}${bold}${red}░▓█▓█▓█▓▒▓░▓░▓░▓░${reset}${red}▄${reset}
           ${red}▀${reset}${bold}${redb}▀${reset}${bold}${red}█████▓█▓█▓█▓█▓░${red}▌${reset}                                   
              ${red}▀▀${reset}${bold}${red}▀▀${reset}${bold}${redb}▀${reset}${bold}${red}██████${reset}${bold}${redb}▀${reset}${red}▀▀${reset}   "
