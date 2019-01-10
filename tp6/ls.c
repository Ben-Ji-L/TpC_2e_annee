#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <getopt.h>

int main(int argc, char *argv[]) {

    DIR* ptdir;
    struct dirent* entree;
    ptdir=opendir(".");
    int options;
    while ((options = getopt(argc, argv, "adl\0")) != -1) {
  		switch (options) {
  			case 'a':
          while((entree=readdir(ptdir))!= NULL) {
            if (!ptdir) {
              printf("pb opendir \n");
            }
            printf("%s %lu \n", entree->d_name, entree->d_ino);
          }
  			break;
        default:
          while((entree=readdir(ptdir))!= NULL) {
            if (!ptdir) {
                printf("pb opendir \n");
            }
            if (!(entree->d_name[0] == '.'))
              printf("%s %lu \n", entree->d_name, entree->d_ino);
          }
          break;

          case 'd':
            break;

          case 'l':
            break;
  		}
    }



    closedir(ptdir);
    return 0;
}
