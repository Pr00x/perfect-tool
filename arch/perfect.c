#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<ctype.h>
#include<unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define BOLD_RED "\x1b[1m\033[31m"
#define BOLD_GREEN "\x1b[1m\033[32m"
#define BOLD_YELLOW "\x1b[1m\033[33m"
#define BOLD_BLUE "\x1b[1m\033[34m"
#define BOLD_MAGENTA "\x1b[1m\033[35m"
#define BOLD_CYAN "\x1b[1m\033[36m"
#define BOLD_WHITE "\x1b[1m\033[37m"

void random_password_generator(int n)
{
  int i, random;

  i = 0;
  random = 0;

  srand((unsigned int)(time(NULL)));

  char numbers[] = "0123456789";
  char letters[] = "abcdefghijklmnoqprstuvwyzx";
  char LETTERS[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  char symbols[] = "!@#$^&*?";
  char passwd[n];

  random = rand() % 4;

  printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Password" BOLD_BLUE ":" BOLD_WHITE " ");

  for(i = 0; i < n; i++)
  {
    if(random == 1)
    {
      passwd[i] = numbers[rand() % 10];
      random = rand() % 4;

      printf("%c", passwd[i]);
    }

    else if(random == 2)
    {
      passwd[i] = letters[rand() % 10];
      random = rand() % 4;

      printf("%c", passwd[i]);
    }

    else if(random == 3)
    {
      passwd[i] = LETTERS[rand() % 10];
      random = rand() % 4;

      printf("%c", passwd[i]);
    }

    else
    {
      passwd[i] = symbols[rand() % 10];
      random = rand() % 4;

      printf("%c", passwd[i]);
    }
  }

  printf("\n\n" RESET);
}

void remove_word(char *string, char *sub)
{
  char *match;
  int len = strlen(sub);

  while((match = strstr(string, sub)))
  {
    *match = '\0';

    strcat(string, match + len);
  }
}

void thumbnail()
{
  printf(BOLD_WHITE "\n\n ¸„.-•~¹°”ˆ˜¨ >>> " BOLD_RED "You" BOLD_WHITE "Tube" BOLD_BLUE " Thumbnail " BOLD_GREEN "Downloader " BOLD_WHITE "by" BOLD_RED " ProX " BOLD_WHITE "<<< ¨˜ˆ”°¹~•-.„¸\n\n\n" RESET);

  char download_thumbnail[128];
  char remove_substring[40] = "https://www.youtube.com/watch?v=";
  char youtube_link[128];
  char add_substring[128] = "https://img.youtube.com/vi/";
  char max[32] = "/maxresdefault.jpg";
  char sd[32] = "/sddefault.jpg";
  char hq[32] = "/hqdefault.jpg";
  char mq[32] = "/mqdefault.jpg";
  char wget[128] = "wget ";
  char download_path[32] = " -O ";
  char thumbnail_name[128];
  char thumbnail_path[128];
  char thumbnail_extension[12] = ".jpg";
  char *remove;

  printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Paste YouTube video URL which you want to Download" RESET ": ");

  scanf("%[^\n]%*c", youtube_link);

  remove = strchr(youtube_link, '&');

  if(remove != NULL)
    *remove = '\0';

  remove_word(youtube_link, "https://www.youtube.com/watch?v=");

  printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Which image quality do you want?\n\n" BOLD_RED "[" BOLD_WHITE "Max" BOLD_GREEN "] " BOLD_RED "[" BOLD_WHITE "Default" BOLD_GREEN "] " BOLD_RED "[" BOLD_WHITE "High" BOLD_GREEN "] " BOLD_RED "[" BOLD_WHITE "Medium" BOLD_GREEN "]" RESET ": ");
  
  scanf("%[^\n]%*c", download_thumbnail);

    if(strncasecmp(download_thumbnail, "max", 4) == 0) {
    strcat(youtube_link, max);
    strcat(add_substring, youtube_link);
    strcat(wget, add_substring);
    strcat(wget, download_path);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Enter a file name" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_name);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Where you want to download thumbnail? (file path)" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_path);

    if(strncmp(thumbnail_path, ".", 1) == 0 || strncmp(thumbnail_path, "..", 2) == 0 || strncmp(thumbnail_path, "~", 1) == 0)
    {
      char add[3] = "/";

      strcat(thumbnail_path, add);
    }

    strcat(wget, thumbnail_path);
    strcat(wget, thumbnail_name);
    strcat(wget, thumbnail_extension);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Downloading...\n\n" RESET);

    system(wget);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Download Completed!\n\n" RESET);
  }

  if(strncmp(download_thumbnail, "Default", 4) == 0 || strncmp(download_thumbnail, "default", 4) == 0 || strncmp(download_thumbnail, "DEFAULT", 4) == 0)
  {
    strcat(youtube_link, sd);
    strcat(add_substring, youtube_link);
    strcat(wget, add_substring);
    strcat(wget, download_path);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Enter a file name" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_name);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Where you want to download thumbnail? (file path)" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_path);

    if(strncmp(thumbnail_path, ".", 1) == 0 || strncmp(thumbnail_path, "..", 2) == 0 || strncmp(thumbnail_path, "~", 1) == 0)
    {
      char add[3] = "/";

      strcat(thumbnail_path, add);
    }

    strcat(wget, thumbnail_path);
    strcat(wget, thumbnail_name);
    strcat(wget, thumbnail_extension);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Downloading...\n\n" RESET);

    system(wget);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Download Completed!\n\n" RESET);
  }

  if(strncmp(download_thumbnail, "High", 4) == 0 || strncmp(download_thumbnail, "high", 4) == 0 || strncmp(download_thumbnail, "HIGH", 4) == 0)
  {
    strcat(youtube_link, hq);
    strcat(add_substring, youtube_link);
    strcat(wget, add_substring);
    strcat(wget, download_path);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Enter a file name" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_name);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Where you want to download thumbnail? (file path)" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_path);

    if(strncmp(thumbnail_path, ".", 1) == 0 || strncmp(thumbnail_path, "..", 2) == 0 || strncmp(thumbnail_path, "~", 1) == 0)
    {
      char add[3] = "/";

      strcat(thumbnail_path, add);
    }

    strcat(wget, thumbnail_path);
    strcat(wget, thumbnail_name);
    strcat(wget, thumbnail_extension);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Downloading...\n\n" RESET);

    system(wget);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Download Completed!\n\n" RESET);

  }

  if(strncmp(download_thumbnail, "Medium", 4) == 0 || strncmp(download_thumbnail, "medium", 4) == 0 || strncmp(download_thumbnail, "MEDIUM", 4) == 0)
  {
    strcat(youtube_link, mq);
    strcat(add_substring, youtube_link);
    strcat(wget, add_substring);
    strcat(wget, download_path);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Enter a file name" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_name);

    printf(BOLD_GREEN "\n>" BOLD_RED ">" BOLD_WHITE " Where you want to download a thumbnail? (file path)" RESET ": ");

    scanf("%[^\n]%*c", thumbnail_path);

    if(strncmp(thumbnail_path, ".", 1) == 0 || strncmp(thumbnail_path, "..", 2) == 0 || strncmp(thumbnail_path, "~", 1) == 0)
    {
      char add[3] = "/";

      strcat(thumbnail_path, add);
    }

    strcat(wget, thumbnail_path);
    strcat(wget, thumbnail_name);
    strcat(wget, thumbnail_extension);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Downloading...\n\n" RESET);

    system(wget);

    printf(BOLD_GREEN ">" BOLD_RED "> " BOLD_WHITE "Download Completed!\n\n" RESET);
  }
}

int main()
{
  char command[1024];
  char email[1024];
  char update[1024] = "sudo pacman -Syu";
  char ls[1024] = "ls -lah";
  char yt_downloader[128] = "python /opt/components/youtube_downloader.py";
  char mp3_downloader[128] = "python /opt/components/video_to_audio.py";
  char exit[1024];

  printf(BOLD_WHITE "\n\n ¸„.-•~¹°”ˆ˜¨ >>> WELCOME -" BOLD_BLUE " Perfect Tool " BOLD_GREEN "v1.0 " BOLD_WHITE "by" BOLD_RED " ProX " BOLD_WHITE "<<< ¨˜ˆ”°¹~•-.„¸\n\n\n" RESET);
  printf(BOLD_WHITE " Please choose an option:\n\n" RESET);
  printf(BOLD_BLUE "  1)" BOLD_GREEN " Help               --->  Display Help Menu.\n");
  printf(BOLD_BLUE "  2)" BOLD_GREEN " Update             --->  Update & Upgrade Packages.\n");
  printf(BOLD_BLUE "  3)" BOLD_GREEN " Exit               --->  Exit Perfect Tool.\n" RESET);
  printf(BOLD_BLUE "  4)" BOLD_GREEN " Thumbnail          --->  Download a thumbnail from Youtube.\n" RESET);
  printf(BOLD_BLUE "  5)" BOLD_GREEN " YTdownload         --->  Download a video from Youtube.\n" RESET);
  printf(BOLD_BLUE "  6)" BOLD_GREEN " Mp3                --->  Download & convert a mp3 file from Youtube.\n" RESET);
  printf(BOLD_BLUE "  7)" BOLD_GREEN " passwd-gen         --->  Generate a Random Secure Password.\n\n" RESET);

  printf(BOLD_BLUE ">>" BOLD_RED " Perfect Tool" BOLD_GREEN ":" BOLD_WHITE" $ " RESET);

  fgets(command, 1024, stdin);
  
  if(strncasecmp(command, "help", 4) == 0 || strncasecmp(command, "h", 1) == 0 || strncmp(command, "1" , 1) == 0 || strncmp(command, "1)", 2) == 0)
    printf("\n\n>> Usage: Enter the option.\n\n");

  else if(strncasecmp(command, "update", 6) == 0 || strncmp(command, "2)", 2) == 0 || strncmp(command, "2", 1) == 0)
  {
    printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Updating & Upgrading all Packages...\n\n" RESET);

    system(update);
    printf("\n\n");
    system("clear");
    main();
  }

  else if(strncasecmp(command, "exit", 4) == 0 || strncmp(command, "3)", 2) == 0 || strncmp(command, "3", 1) == 0)
  {
    printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Bye!\n\n" RESET);

    return 0;
  }

  else if(strncasecmp(command, "thumbnail", 9) == 0 || strncmp(command, "4)", 2) == 0 || strncmp(command, "4", 1) == 0)
    thumbnail();
  else if(strncasecmp(command, "ytdownload", 10) == 0 || strncmp(command, "5)", 2) == 0 || strncmp(command, "5", 1) == 0)
    system(yt_downloader);

  else if(strncasecmp(command, "mp3", 3) == 0 || strncmp(command, "6)", 2) == 0 || strncmp(command, "6", 1) == 0)
  {
    system(mp3_downloader);

    return 0;
  }

  else if(strncasecmp(command, "passwd-gen", 10) == 0 || strncmp(command, "7)", 2) == 0 || strncmp(command, "7", 1) == 0)
  {
    printf(BOLD_WHITE "\n\n ¸„.-•~¹°”ˆ˜¨ >>> " BOLD_RED "Secure" BOLD_BLUE " Password " BOLD_GREEN "Generator " BOLD_WHITE "by" BOLD_RED " ProX " BOLD_WHITE "<<< ¨˜ˆ”°¹~•-.„¸\n\n\n" RESET);

    int n;

    printf(BOLD_GREEN "\n>" BOLD_RED "> " BOLD_WHITE "Enter a lenght of the password" RESET ": ");
    scanf("%d", &n);

    random_password_generator(n);
  }

  else
  {
    printf(BOLD_GREEN "\n>" BOLD_RED "> " RESET "Command not found.\n\n" RESET);
  }
}
