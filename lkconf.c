
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define PATH_MAX 2500




////////////
////////////
void npkg( char *mycmd )
{
           char cmdi[PATH_MAX];
           strncpy( cmdi , " pkgin  -y install  " , PATH_MAX );
           strncat( cmdi , " " ,   PATH_MAX - strlen( cmdi ) -1 );
           strncat( cmdi , mycmd , PATH_MAX - strlen( cmdi ) -1 );
           strncat( cmdi , " " ,   PATH_MAX - strlen( cmdi ) -1 );
           printf( "  npkg (action command) %s.\n" , cmdi );
           if ( strcmp( mycmd, "" ) != 0 ) system( cmdi ); 
}











int main( int argc, char *argv[])
{
     int i ; int choix;
     char cmdi[PATH_MAX];



    ////////////////////////////////////////////////////////
    if ( argc == 2)
    if ( ( strcmp( argv[1] , "ad" ) ==  0 ) 
    || ( strcmp( argv[1] ,  "adhoc" ) ==  0 ) )  
    {
       printf(  "\n" );
       printf( "ifconfig_ue0=\"inet 192.168.123.100 255.255.255.0\"\n" );
       printf(  "\n" );
       return 0;
    }
    ////////////////////////////////////////////////////////


     ////////////////////////////////////////////////////////
     if ( argc == 2)
     if ( strcmp( argv[1] ,   "rc" ) ==  0 ) 
     {
        printf( "ifconfig_urtwn0=dhcp\n" );
        printf( "sshd=YES\n" );
        printf( "dhcpcd=YES\n" );
        printf( "dhcpcd_flags=\"-q -b\"\n" );
        printf( "wpa_supplicant=YES\n" );
        printf( "wpa_supplicant_flags=\"-B -i urtwn0 -c /etc/wpa_supplicant.conf\"\n" );
        return 0;
     }




     printf( "Hello NetBSD.\n" );
     printf( "High Performance UNIX Operating System, NetBSD is the master.\n" );
     printf( "\n" );




     ////////////////////////////////////////////////////////
     if ( argc == 2 )
     if ( ( strcmp( argv[1] , "look" ) ==  0 ) 
     || ( strcmp( argv[1] ,   "perm" ) ==  0 ) 
     || ( strcmp( argv[1] ,   "cons" ) ==  0 ) )
     {
        system( "  wsconsctl -k -w map+='keycode 56 = Cmd Alt_L'   " );
        system( " sysctl -w ddb.onpanic=1 " ); //for crash ddb
        return 0;
     }



      ///////////////////////////////////////////////////////
      if  ( argc == 2)
      if  ( strcmp( argv[1] , "dmesg" ) ==  0 ) 
      {
            system( " while : ; do clear ; dmesg | tail ; sleep 2 ; done  " );
            return 0;
      }



      ///////////////////////////////////////////////////////
      if  ( argc == 2)
      if  ( strcmp( argv[1] , "shutdown" ) ==  0 ) 
      {
            system( " /sbin/halt  " );
            return 0;
      }

      ///////////////////////////////////////////////////////
      if  ( argc == 2)
      if  ( strcmp( argv[1] , "reboot" ) ==  0 ) 
      {
            system( " /sbin/reboot  " );
            return 0;
      }




      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////
      if  ( argc >= 3 )
      if  ( strcmp( argv[1] , "install" ) ==  0 ) 
      if (  ( strcmp( argv[2] , "pkg" ) ==  0 ) 
      ||  ( strcmp( argv[2] , "pkgin" ) ==  0 )   ) 
      {
            printf( " export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/amd64/6.0_BETA_current/All/\" ;   pkg_add -v pkgin " ) ; 
            printf( "\n" ); 

            printf( "1: amd64\n" );
            printf( "2: earmv7hf\n" );
            printf( "3: i386\n" );
            choix = getchar();
            printf( "Choix: %d\n" );

            if ( choix == 1 ) system( " export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/amd64/6.0_BETA_current/All/\" ;   pkg_add -v pkgin " ) ; 
            else if ( choix == 2 ) system( " export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/earmv7hf/9.0/All/\" ;   pkg_add -v pkgin " ) ; 

            else if ( choix == 3 ) system( " export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/9.0/All/\" ;   pkg_add -v pkgin " ) ; 
            return 0;
      }





      ///////////////////////////////////////////////////////
      if  ( argc == 2)
      if (  ( strcmp( argv[1] ,  "links" ) ==  0 ) 
          || ( strcmp( argv[1] , "netbsd" ) ==  0 ) 
          || ( strcmp( argv[1] , "bsd" ) ==  0 ) 
          || ( strcmp( argv[1] , "get" ) ==  0 ) 
         )
       {
            system( " links https://cdn.netbsd.org/pub/NetBSD/  "   ); 
            //system( " links http://nycdn.netbsd.org/pub/NetBSD-daily/netbsd-9/latest/images/  " ); 
            //system( " links https://cdn.netbsd.org/pub/NetBSD/NetBSD-8.1/images/"   ); 
            return 0;
       }



   ////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////
     if ( argc == 3)
     if ( strcmp( argv[1] ,   "install" ) ==  0 ) 
     if ( strcmp( argv[2] ,   "base" ) ==  0 ) 
     {
            npkg( "  screen " );
            npkg( "  subversion " ); 
            npkg( "  ncurses " );
            npkg( "  vim " );
            return 0;
     }
   ////////////////////////////////////////////////////////






    /////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////
    if ( argc >= 3)
      if ( ( strcmp( argv[1] , "pkgin" ) ==  0 )  || ( strcmp( argv[1] , "pkg" ) ==  0 ) )  
      if ( strcmp( argv[2] , "" ) !=  0 ) 
      {
           strncpy( cmdi , " pkgin -y install " , PATH_MAX );
           strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
           for( i = 2 ; i < argc ; i++) 
           {
              printf( "=> %d/%d %s \n", i , argc-1 , argv[ i ]-1 );
              strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
              strncat( cmdi , argv[ i ] , PATH_MAX - strlen( cmdi ) -1 );
              strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
           }
           strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
           strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
           printf( "  npkg (action command) %s.\n" , cmdi );
           system( cmdi );
           return 0; 
      }
    /////////////////////////////////////////////////////////////






     ////////////////////////////////////////////////////////
     if ( argc == 2)
     if ( strcmp( argv[1] ,   "snd" ) ==  0 ) 
     {
           system(  " mixerctl -a ; mixerctl -w outputs.master=60 " );
           return 0; 
     }
     /////////////////////////////////////////////////////////////




     ////////////////////////////////////////////////////////
     if ( argc == 3)
     if ( strcmp( argv[1] ,   "install" ) ==  0 ) 
     if ( ( strcmp( argv[2] ,   "docx" ) ==  0 ) 
     || ( strcmp( argv[2] ,   "antiword" ) ==  0   ) 
     || ( strcmp( argv[2] ,   "catx" ) ==  0 ) )
     {
            npkg( "  docx2txt " );
            npkg( "  antiword " );
            npkg( "  antiword " );
            npkg( "  docx2txt  " );
            npkg( "  antiword  " );
            npkg( "  catdoc  " );
            npkg( " antiword docx2txt "  );
            return 0;
     }


    ////////////////////////////////////////////////////////






    ////////////////////////////////////////////////////////
    if ( argc == 2)
    if ( ( strcmp( argv[1] , "bsd" ) ==  0 ) 
    || ( strcmp( argv[1] ,  "bsd" ) ==  0 ) )  
    {
       printf(  "The server BSD is at 192.168.123.100.\n" );
       printf(  "The client BSD or RPI is at 192.168.123.101.\n" );
       system( " ssh -C 192.168.123.100  "  );
       return 0;
    }


   printf("USERNAME: %s\n", getenv( "USER" ));
   printf("HOME: %s\n", getenv( "HOME" ));
   printf("PATH: %s\n", getcwd( cmdi , PATH_MAX ));


   return 0;
}



