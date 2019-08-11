
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
     if ( strcmp( argv[1] ,   "rc" ) ==  0 ) 
     {
        printf( "#hostname=generic\n" );
        printf( "#keymap=de\n" );
        printf( "ifconfig_re0=dhcp\n" );
        printf( "ifconfig_urtwn0=dhcp\n" );
        printf( "sshd=YES\n" );
        printf( "dhcpcd=YES\n" );
        printf( "dhcpcd_flags=\"-q -b\"\n" );
        printf( "wpa_supplicant=YES\n" );
        printf( "wpa_supplicant_flags=\"-B -i urtwn0 -c /etc/wpa_supplicant.conf\"\n" );
        return 0;
     }


    ////////////////////////////////////////////////////////
    if ( argc == 2)
    if ( strcmp( argv[1] , "re0" ) ==  0 ) 
    {
       printf(  "\n" );
       printf( "ifconfig_re0=\"dhcp\"\n" );
       printf(  "\n" );
       return 0;
    }
    ////////////////////////////////////////////////////////


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
      if  ( argc == 2 )
      if  ( strcmp( argv[1] , "pkginstall" ) ==  0 ) 
      {
            //printf( " export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/amd64/6.0_BETA_current/All/\" ;   pkg_add -v pkgin " ) ; 
            printf( "\n" ); 
            system( "  uname -a " );
            printf( "\n" ); 

            printf( "1: i386 8.1 (stable)\n" );
            printf( "2: i386 9.x (beta, unstable)\n" );
            printf( "3: amd64 6.0\n" );
            printf( "4: earmv7hf rpi 8.1 (stable, visit 8.1 arm7hf)\n" );
            printf( "5: earmv7hf rpi 9.0 (unstable)\n" );
            printf( "6: evbarm rpi 8.1\n" );
            printf( "7: earmv7hf rpi 7.1 arm7hf\n" );
            choix = getchar();
            printf( "Choix: %d\n", choix );

            if ( choix == -99 )  
               printf( "hello\n" );

            else if ( choix == 48+1 ) 
                system( " echo choix ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/8.1/All/\" ;   pkg_add -v pkgin  ; pkgin update " ) ; 

            else if ( choix == 48+2 )  // i386 
                system( " echo choix ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/9.0/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 

            else if ( choix == 48+3 )  // amd 
                 system( "  echo choix ;   export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/amd64/6.0_BETA_current/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 

            else if ( choix == 48+4 ) // arm 
                system( "  echo choix ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/earmv7hf/8.1/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 

            else if ( choix == 48+5 )  // arm
                system( " echo choix ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/earmv7hf/9.0/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 


            else if ( choix == 48+6 )  // arm
                system( " echo choix evbarm ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/evbarm/8.1/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 

            else if ( choix == 48+7 ) // arm 
                system( "  echo choix ;  export PKG_PATH=\"http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/earmv7hf/7.1/All/\" ;   pkg_add -v pkgin ; pkgin update " ) ; 

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
            system( " uname -a  " );
            npkg( "  subversion-base " ); // on NetBSD to keep light, without java, ruby, apache,... bloat. 
            npkg( "  screen " );
            npkg( "  vim " );
            npkg( "  aumix " );
            return 0;
     }
   ////////////////////////////////////////////////////////






    /////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////
    if ( argc >= 3)
      if ( ( strcmp( argv[1] , "pkgin" )   ==  0 )       // NetBSD
       || ( strcmp( argv[1] ,  "pkg" )     ==  0 )       // FreeBSD
       || ( strcmp( argv[1] ,  "pkg_add" ) ==  0 ) )     // OpenBSD
      if ( strcmp( argv[2] , "" ) !=  0 ) 
      {
           strncpy( cmdi , " pkgin -y install " , PATH_MAX );
           strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
           for( i = 2 ; i < argc ; i++) 
           {
              printf( "==> %d/%d (pkg: %s)\n", i-1 , argc-1 , argv[ i ] );
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

// dd zero wd0 count=9999
// disklabel -I -i wd0 
// c 0 0 or  // d 0 0  is just not necessary
// just a with 4.2BSD 
// press a and 100000M , and newfs wd0 
// (NOPE) installboot -m i386 /dev/wd0a  /usr/mdec/bootxx_ffsv2 
// rather fdisk -i wd0 , botocode /usr/mdec/mbr  y and y to write part table.
// newfs wd0a and mount to /target
// untar 
// make a target/boot
// echo /dev/wd0a / ffs rw 1 1  > /target/etc/fstab
// cp -r /boot /target/boot
// cp  /netbsd /target/netbsd 
// make active partition fdisk -a /dev/wd0 
 
// you may need module, base and ...?


// wd0 , yes all, kernel generic k, kerneel modules, base, configurefiles /etc , comp compiler tools



