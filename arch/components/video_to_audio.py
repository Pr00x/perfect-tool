from youtube_dl import YoutubeDL

RED = "\x1b[31m"
GREEN = "\x1b[32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN = "\x1b[36m"
RESET = "\x1b[0m"

BOLD_RED = "\x1b[1m\033[31m"
BOLD_GREEN = "\x1b[1m\033[32m"
BOLD_YELLOW = "\x1b[1m\033[33m"
BOLD_BLUE = "\x1b[1m\033[34m"
BOLD_MAGENTA = "\x1b[1m\033[35m"
BOLD_CYAN = "\x1b[1m\033[36m"
BOLD_WHITE = "\x1b[1m\033[37m"

print(f"{BOLD_WHITE}\n\n ¸„.-•~¹°”ˆ˜¨ >>> {BOLD_RED}You{BOLD_WHITE}Tube{BOLD_BLUE} Video {BOLD_GREEN}to MP3 Downloader {BOLD_WHITE}by{BOLD_RED} ProX {BOLD_WHITE}<<< ¨˜ˆ”°¹~•-.„¸\n\n{RESET}")


link = input(f"{BOLD_GREEN}\n>{BOLD_RED}> {BOLD_WHITE}Enter YouTube video URL which you want to convert to MP3{RESET}: ")

if("youtube.com" not in link):
    if("youtu.be" not in link):
        print(f"{BOLD_GREEN}\n>{BOLD_RED}> {BOLD_WHITE}Please enter a YouTube video link!{RESET}\n")
        exit()

audio_downloader = YoutubeDL({"format":"bestaudio"})
audio_downloader.extract_info(link)

print(f"{BOLD_GREEN}\n>{BOLD_RED}> {BOLD_WHITE}Successfuly Downloaded an audio file!\n{RESET}")
